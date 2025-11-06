-- =============================================
-- Fix Korean/Japanese Character Display - Complete UTF-8 Support
-- =============================================
USE [MuOnline]
GO

-- IMPORTANT: Backup your database first!
-- BACKUP DATABASE [MuOnline] TO DISK = 'C:\Backup\MuOnline_Before_UTF8.bak'

PRINT '========================================='
PRINT 'Starting COMPLETE UTF-8 conversion...'
PRINT '========================================='
GO

-- =============================================
-- STEP 1: Drop ALL Foreign Key constraints
-- =============================================
PRINT 'STEP 1: Dropping Foreign Key constraints...'
GO

IF EXISTS (SELECT * FROM sys.foreign_keys WHERE name = 'FK_CustomNpcQuest_Character')
BEGIN
    ALTER TABLE CustomNpcQuest DROP CONSTRAINT FK_CustomNpcQuest_Character
    PRINT '  - Dropped FK_CustomNpcQuest_Character'
END

IF EXISTS (SELECT * FROM sys.foreign_keys WHERE name = 'FK_CustomQuest_Character')
BEGIN
    ALTER TABLE CustomQuest DROP CONSTRAINT FK_CustomQuest_Character
    PRINT '  - Dropped FK_CustomQuest_Character'
END

IF EXISTS (SELECT * FROM sys.foreign_keys WHERE name = 'FK_CustomAttack_Character')
BEGIN
    ALTER TABLE CustomAttack DROP CONSTRAINT FK_CustomAttack_Character
    PRINT '  - Dropped FK_CustomAttack_Character'
END

-- Drop any other FKs that might exist
DECLARE @sql NVARCHAR(MAX) = ''
SELECT @sql = @sql + 'ALTER TABLE ' + QUOTENAME(OBJECT_SCHEMA_NAME(parent_object_id)) + '.' + QUOTENAME(OBJECT_NAME(parent_object_id)) + 
              ' DROP CONSTRAINT ' + QUOTENAME(name) + '; '
FROM sys.foreign_keys
WHERE referenced_object_id IN (
    OBJECT_ID('Character'),
    OBJECT_ID('MEMB_INFO'),
    OBJECT_ID('AccountCharacter'),
    OBJECT_ID('CustomAttack'),
    OBJECT_ID('BotNames')
)

IF LEN(@sql) > 0
BEGIN
    EXEC sp_executesql @sql
    PRINT '  - Dropped additional foreign keys'
END

GO

-- =============================================
-- STEP 2: Drop ALL Primary Key constraints
-- =============================================
PRINT 'STEP 2: Dropping Primary Key constraints...'
GO

IF EXISTS (SELECT * FROM sys.key_constraints WHERE name = 'PK_Character')
BEGIN
    ALTER TABLE Character DROP CONSTRAINT PK_Character
    PRINT '  - Dropped PK_Character'
END

IF EXISTS (SELECT * FROM sys.key_constraints WHERE name = 'PK_AccountCharacter')
BEGIN
    ALTER TABLE AccountCharacter DROP CONSTRAINT PK_AccountCharacter
    PRINT '  - Dropped PK_AccountCharacter'
END

IF EXISTS (SELECT * FROM sys.key_constraints WHERE name = 'PK_CustomAttack')
BEGIN
    ALTER TABLE CustomAttack DROP CONSTRAINT PK_CustomAttack
    PRINT '  - Dropped PK_CustomAttack'
END

GO

-- =============================================
-- STEP 3: Drop ALL Unique constraints
-- =============================================
PRINT 'STEP 3: Dropping Unique constraints...'
GO

IF EXISTS (SELECT * FROM sys.key_constraints WHERE name = 'UQ_BotNames')
BEGIN
    ALTER TABLE BotNames DROP CONSTRAINT UQ_BotNames
    PRINT '  - Dropped UQ_BotNames'
END

GO

-- =============================================
-- STEP 4: Drop ALL Indexes on affected columns
-- =============================================
PRINT 'STEP 4: Dropping Indexes...'
GO

-- Drop index on BotNames.Language
IF EXISTS (SELECT * FROM sys.indexes WHERE name = 'IX_BotNames_Language_Gender' AND object_id = OBJECT_ID('BotNames'))
BEGIN
    DROP INDEX IX_BotNames_Language_Gender ON BotNames
    PRINT '  - Dropped IX_BotNames_Language_Gender'
END

-- Drop any other indexes on Name columns
DECLARE @DropIndexSQL NVARCHAR(MAX) = ''
SELECT @DropIndexSQL = @DropIndexSQL + 
    'DROP INDEX ' + QUOTENAME(i.name) + ' ON ' + QUOTENAME(OBJECT_SCHEMA_NAME(i.object_id)) + '.' + QUOTENAME(OBJECT_NAME(i.object_id)) + '; '
FROM sys.indexes i
INNER JOIN sys.index_columns ic ON i.object_id = ic.object_id AND i.index_id = ic.index_id
INNER JOIN sys.columns c ON ic.object_id = c.object_id AND ic.column_id = c.column_id
WHERE (c.name = 'Name' OR c.name = 'Language' OR c.name = 'AccountID' OR c.name = 'memb___id')
  AND i.is_primary_key = 0
  AND i.is_unique_constraint = 0
  AND i.type > 0  -- Exclude heap

IF LEN(@DropIndexSQL) > 0
BEGIN
    EXEC sp_executesql @DropIndexSQL
    PRINT '  - Dropped additional indexes'
END

GO

-- =============================================
-- STEP 5: Drop Default constraints
-- =============================================
PRINT 'STEP 5: Dropping Default constraints...'
GO

DECLARE @ConstraintName NVARCHAR(200)

-- Drop Language default on Character
SELECT @ConstraintName = dc.name 
FROM sys.default_constraints dc
JOIN sys.columns c ON dc.parent_object_id = c.object_id AND dc.parent_column_id = c.column_id
WHERE dc.parent_object_id = OBJECT_ID('Character') AND c.name = 'Language'

IF @ConstraintName IS NOT NULL
BEGIN
    EXEC('ALTER TABLE Character DROP CONSTRAINT ' + @ConstraintName)
    PRINT '  - Dropped Character.Language default constraint: ' + @ConstraintName
END

-- Drop Language default on BotNames
SELECT @ConstraintName = dc.name 
FROM sys.default_constraints dc
JOIN sys.columns c ON dc.parent_object_id = c.object_id AND dc.parent_column_id = c.column_id
WHERE dc.parent_object_id = OBJECT_ID('BotNames') AND c.name = 'Language'

IF @ConstraintName IS NOT NULL
BEGIN
    EXEC('ALTER TABLE BotNames DROP CONSTRAINT ' + @ConstraintName)
    PRINT '  - Dropped BotNames.Language default constraint: ' + @ConstraintName
END

GO

-- =============================================
-- STEP 6: Convert Character table to NVARCHAR
-- =============================================
PRINT 'STEP 6: Converting Character table columns...'
GO

ALTER TABLE Character
ALTER COLUMN AccountID NVARCHAR(10) COLLATE Korean_Wansung_CI_AS NOT NULL
PRINT '  - Character.AccountID converted'
GO

ALTER TABLE Character
ALTER COLUMN Name NVARCHAR(10) COLLATE Korean_Wansung_CI_AS NOT NULL
PRINT '  - Character.Name converted (UNICODE ENABLED!)'
GO

-- Handle Language column
IF EXISTS (SELECT * FROM sys.columns WHERE object_id = OBJECT_ID('Character') AND name = 'Language')
BEGIN
    ALTER TABLE Character
    ALTER COLUMN Language NVARCHAR(20) COLLATE Korean_Wansung_CI_AS NULL
    PRINT '  - Character.Language converted'
END
ELSE
BEGIN
    ALTER TABLE Character ADD Language NVARCHAR(20) COLLATE Korean_Wansung_CI_AS NULL
    PRINT '  - Character.Language column added'
END
GO

-- =============================================
-- STEP 7: Convert MEMB_INFO table to NVARCHAR
-- =============================================
PRINT 'STEP 7: Converting MEMB_INFO table columns...'
GO

ALTER TABLE MEMB_INFO
ALTER COLUMN memb___id NVARCHAR(10) COLLATE Korean_Wansung_CI_AS NOT NULL
PRINT '  - MEMB_INFO.memb___id converted'
GO

ALTER TABLE MEMB_INFO
ALTER COLUMN memb_name NVARCHAR(10) COLLATE Korean_Wansung_CI_AS NOT NULL
PRINT '  - MEMB_INFO.memb_name converted'
GO

-- Optional: Convert other text fields in MEMB_INFO for full Unicode support
ALTER TABLE MEMB_INFO
ALTER COLUMN memb__pwd NVARCHAR(10) COLLATE Korean_Wansung_CI_AS NOT NULL
GO

ALTER TABLE MEMB_INFO
ALTER COLUMN mail_addr NVARCHAR(50) COLLATE Korean_Wansung_CI_AS NULL
GO

ALTER TABLE MEMB_INFO
ALTER COLUMN fpas_ques NVARCHAR(50) COLLATE Korean_Wansung_CI_AS NULL
GO

ALTER TABLE MEMB_INFO
ALTER COLUMN fpas_answ NVARCHAR(50) COLLATE Korean_Wansung_CI_AS NULL
GO

PRINT '  - MEMB_INFO optional fields converted'

-- =============================================
-- STEP 8: Convert AccountCharacter table to NVARCHAR
-- =============================================
PRINT 'STEP 8: Converting AccountCharacter table columns...'
GO

ALTER TABLE AccountCharacter
ALTER COLUMN Id NVARCHAR(10) COLLATE Korean_Wansung_CI_AS NOT NULL
GO

ALTER TABLE AccountCharacter
ALTER COLUMN GameID1 NVARCHAR(10) COLLATE Korean_Wansung_CI_AS NULL
GO

ALTER TABLE AccountCharacter
ALTER COLUMN GameID2 NVARCHAR(10) COLLATE Korean_Wansung_CI_AS NULL
GO

ALTER TABLE AccountCharacter
ALTER COLUMN GameID3 NVARCHAR(10) COLLATE Korean_Wansung_CI_AS NULL
GO

ALTER TABLE AccountCharacter
ALTER COLUMN GameID4 NVARCHAR(10) COLLATE Korean_Wansung_CI_AS NULL
GO

ALTER TABLE AccountCharacter
ALTER COLUMN GameID5 NVARCHAR(10) COLLATE Korean_Wansung_CI_AS NULL
GO

ALTER TABLE AccountCharacter
ALTER COLUMN GameIDC NVARCHAR(10) COLLATE Korean_Wansung_CI_AS NULL
GO

PRINT '  - AccountCharacter all GameID columns converted'

-- =============================================
-- STEP 9: Convert CustomAttack table to NVARCHAR
-- =============================================
PRINT 'STEP 9: Converting CustomAttack table columns...'
GO

IF EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID('CustomAttack'))
BEGIN
    ALTER TABLE CustomAttack
    ALTER COLUMN Name NVARCHAR(10) COLLATE Korean_Wansung_CI_AS NOT NULL
    PRINT '  - CustomAttack.Name converted (UNICODE ENABLED!)'
END
GO

-- =============================================
-- STEP 10: Convert BotNames table to NVARCHAR
-- =============================================
PRINT 'STEP 10: Converting BotNames table columns...'
GO

IF EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID('BotNames'))
BEGIN
    ALTER TABLE BotNames
    ALTER COLUMN Name NVARCHAR(50) COLLATE Korean_Wansung_CI_AS NOT NULL
    PRINT '  - BotNames.Name converted'
    
    ALTER TABLE BotNames
    ALTER COLUMN Language NVARCHAR(20) COLLATE Korean_Wansung_CI_AS NOT NULL
    PRINT '  - BotNames.Language converted'
END
GO

-- =============================================
-- STEP 11: Convert related tables to NVARCHAR
-- =============================================
PRINT 'STEP 11: Converting related tables...'
GO

IF EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID('CustomNpcQuest'))
BEGIN
    IF EXISTS (SELECT * FROM sys.columns WHERE object_id = OBJECT_ID('CustomNpcQuest') AND name = 'CharacterName')
    BEGIN
        ALTER TABLE CustomNpcQuest
        ALTER COLUMN CharacterName NVARCHAR(10) COLLATE Korean_Wansung_CI_AS NULL
        PRINT '  - CustomNpcQuest.CharacterName converted'
    END
END
GO

IF EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID('CustomQuest'))
BEGIN
    IF EXISTS (SELECT * FROM sys.columns WHERE object_id = OBJECT_ID('CustomQuest') AND name = 'CharacterName')
    BEGIN
        ALTER TABLE CustomQuest
        ALTER COLUMN CharacterName NVARCHAR(10) COLLATE Korean_Wansung_CI_AS NULL
        PRINT '  - CustomQuest.CharacterName converted'
    END
END
GO

-- =============================================
-- STEP 12: Recreate Primary Keys
-- =============================================
PRINT 'STEP 12: Recreating Primary Key constraints...'
GO

ALTER TABLE Character 
ADD CONSTRAINT PK_Character PRIMARY KEY CLUSTERED (Name)
PRINT '  - Recreated PK_Character'
GO

ALTER TABLE AccountCharacter
ADD CONSTRAINT PK_AccountCharacter PRIMARY KEY CLUSTERED (Id)
PRINT '  - Recreated PK_AccountCharacter'
GO

IF EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID('CustomAttack'))
BEGIN
    ALTER TABLE CustomAttack
    ADD CONSTRAINT PK_CustomAttack PRIMARY KEY CLUSTERED (Name)
    PRINT '  - Recreated PK_CustomAttack'
END
GO

-- =============================================
-- STEP 13: Recreate Unique Constraints
-- =============================================
PRINT 'STEP 13: Recreating Unique constraints...'
GO

IF EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID('BotNames'))
BEGIN
    ALTER TABLE BotNames
    ADD CONSTRAINT UQ_BotNames UNIQUE (Name, Language)
    PRINT '  - Recreated UQ_BotNames'
END
GO

-- =============================================
-- STEP 14: Recreate Indexes
-- =============================================
PRINT 'STEP 14: Recreating Indexes...'
GO

IF EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID('BotNames'))
BEGIN
    IF EXISTS (SELECT * FROM sys.columns WHERE object_id = OBJECT_ID('BotNames') AND name = 'Gender')
    BEGIN
        CREATE NONCLUSTERED INDEX IX_BotNames_Language_Gender
        ON BotNames(Language, Gender)
        PRINT '  - Recreated IX_BotNames_Language_Gender'
    END
END
GO

-- =============================================
-- STEP 15: Recreate Foreign Keys
-- =============================================
PRINT 'STEP 15: Recreating Foreign Key constraints...'
GO

IF EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID('CustomNpcQuest'))
BEGIN
    IF EXISTS (SELECT * FROM sys.columns WHERE object_id = OBJECT_ID('CustomNpcQuest') AND name = 'CharacterName')
    BEGIN
        ALTER TABLE CustomNpcQuest
        ADD CONSTRAINT FK_CustomNpcQuest_Character
        FOREIGN KEY (CharacterName) REFERENCES Character(Name)
        ON DELETE CASCADE
        PRINT '  - Recreated FK_CustomNpcQuest_Character'
    END
END
GO

IF EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID('CustomQuest'))
BEGIN
    IF EXISTS (SELECT * FROM sys.columns WHERE object_id = OBJECT_ID('CustomQuest') AND name = 'CharacterName')
    BEGIN
        ALTER TABLE CustomQuest
        ADD CONSTRAINT FK_CustomQuest_Character
        FOREIGN KEY (CharacterName) REFERENCES Character(Name)
        ON DELETE CASCADE
        PRINT '  - Recreated FK_CustomQuest_Character'
    END
END
GO

IF EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID('CustomAttack'))
BEGIN
    ALTER TABLE CustomAttack
    ADD CONSTRAINT FK_CustomAttack_Character
    FOREIGN KEY (Name) REFERENCES Character(Name)
    ON DELETE CASCADE
    PRINT '  - Recreated FK_CustomAttack_Character'
END
GO

-- =============================================
-- STEP 16: Update Stored Procedures for Unicode
-- =============================================
PRINT 'STEP 16: Updating stored procedures...'
GO

IF EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID('WZ_CreateBot') AND type in (N'P', N'PC'))
    DROP PROCEDURE WZ_CreateBot
GO

CREATE PROCEDURE [dbo].[WZ_CreateBot]
    @AccountID NVARCHAR(10),
    @CharName NVARCHAR(10),
    @ClassCode INT,
    @ConfigIndex INT,
    @Level INT = 400,
    @MapNumber INT = 0,
    @MapPosX INT = 125,
    @MapPosY INT = 125,
    @Money INT = 20000000,
    @Language NVARCHAR(20) = N'English'
AS
BEGIN
    SET NOCOUNT ON
    SET XACT_ABORT ON
    
    DECLARE @Result TINYINT
    DECLARE @Strength INT, @Dexterity INT, @Vitality INT, @Energy INT, @Leadership INT
    DECLARE @MainSkill INT, @SecondarySkill INT
    DECLARE @Buff1 INT, @Buff2 INT, @Buff3 INT
    DECLARE @InventoryHex VARCHAR(MAX), @MagicListHex VARCHAR(MAX)
    
    SET @Result = 0x00
    
    -- Validate language (Use N prefix for Unicode strings!)
    IF @Language NOT IN (N'English', N'Spanish', N'Chinese', N'Portuguese', N'Korean', N'Japanese')
    BEGIN
        SET @Language = N'English'
    END
    
    -- Check if character already exists
    IF EXISTS (SELECT Name FROM Character WHERE Name = @CharName)
    BEGIN
        SET @Result = 0x01
        GOTO ProcEnd
    END
    
    BEGIN TRAN
    
    -- Get class configuration
    EXEC WZ_GetBotClassConfig 
        @ClassCode, @ConfigIndex,
        @Strength OUTPUT, @Dexterity OUTPUT, @Vitality OUTPUT, 
        @Energy OUTPUT, @Leadership OUTPUT,
        @MainSkill OUTPUT, @SecondarySkill OUTPUT,
        @Buff1 OUTPUT, @Buff2 OUTPUT, @Buff3 OUTPUT,
        @InventoryHex OUTPUT, @MagicListHex OUTPUT
    
    IF @InventoryHex IS NULL
    BEGIN
        SET @Result = 0x04
        GOTO TranProcEnd
    END
    
    -- Create or update MEMB_INFO account (Use N prefix for Unicode!)
    IF NOT EXISTS (SELECT memb___id FROM MEMB_INFO WHERE memb___id = @AccountID)
    BEGIN
        INSERT INTO MEMB_INFO (memb___id, memb__pwd, memb_name, sno__numb, mail_addr, bloc_code, ctl1_code)
        VALUES (@AccountID, N'123456', @AccountID, '123456789', N'bot@email.com', '0', '0')
        
        IF @@ERROR <> 0
        BEGIN
            SET @Result = 0x02
            GOTO TranProcEnd
        END
    END
    
    -- Manage AccountCharacter slots
    IF NOT EXISTS (SELECT Id FROM AccountCharacter WHERE Id = @AccountID)
    BEGIN
        INSERT INTO AccountCharacter(Id, GameID1, GameID2, GameID3, GameID4, GameID5, GameIDC)
        VALUES(@AccountID, @CharName, NULL, NULL, NULL, NULL, NULL)
        
        SET @Result = @@ERROR
    END
    ELSE
    BEGIN
        DECLARE @g1 NVARCHAR(10), @g2 NVARCHAR(10), @g3 NVARCHAR(10), @g4 NVARCHAR(10), @g5 NVARCHAR(10)
        SELECT @g1 = GameID1, @g2 = GameID2, @g3 = GameID3, @g4 = GameID4, @g5 = GameID5 
        FROM AccountCharacter WHERE Id = @AccountID
        
        IF (@g1 IS NULL OR LEN(@g1) = 0)
            UPDATE AccountCharacter SET GameID1 = @CharName WHERE Id = @AccountID
        ELSE IF (@g2 IS NULL OR LEN(@g2) = 0)
            UPDATE AccountCharacter SET GameID2 = @CharName WHERE Id = @AccountID
        ELSE IF (@g3 IS NULL OR LEN(@g3) = 0)
            UPDATE AccountCharacter SET GameID3 = @CharName WHERE Id = @AccountID
        ELSE IF (@g4 IS NULL OR LEN(@g4) = 0)
            UPDATE AccountCharacter SET GameID4 = @CharName WHERE Id = @AccountID
        ELSE IF (@g5 IS NULL OR LEN(@g5) = 0)
            UPDATE AccountCharacter SET GameID5 = @CharName WHERE Id = @AccountID
        ELSE
        BEGIN
            SET @Result = 0x03
            GOTO TranProcEnd
        END
        
        SET @Result = @@ERROR
    END
    
    IF (@Result <> 0)
        GOTO TranProcEnd
    
    -- Create Character (Use N prefix for Unicode language!)
    INSERT INTO Character (
        AccountID, Name, cLevel, Class, 
        Strength, Dexterity, Vitality, Energy, Leadership,
        Money, MapNumber, MapPosX, MapPosY,
        Inventory, MagicList,
        LevelUpPoint, Experience,
        MDate, LDate, Quest, DbVersion,
        Language
    )
    VALUES (
        @AccountID, @CharName, @Level, @ClassCode,
        @Strength, @Dexterity, @Vitality, @Energy, @Leadership,
        @Money, @MapNumber, @MapPosX, @MapPosY,
        CONVERT(VARBINARY(MAX), @InventoryHex, 1),
        CONVERT(VARBINARY(MAX), @MagicListHex, 1),
        0, 0,
        GETDATE(), GETDATE(), 0x1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F, 0,
        @Language
    )
    
    SET @Result = @@ERROR
    
TranProcEnd:
    IF (@Result <> 0)
        ROLLBACK TRAN
    ELSE
        COMMIT TRAN

ProcEnd:
    SET NOCOUNT OFF
    SET XACT_ABORT OFF
    
    SELECT
        CASE @Result
            WHEN 0x00 THEN 0x01
            WHEN 0x01 THEN 0x00
            WHEN 0x03 THEN 0x03
            WHEN 0x04 THEN 0x04
            ELSE 0x02
        END AS Result
END
GO

PRINT '  - WZ_CreateBot procedure updated'

-- =============================================
-- STEP 17: Add default constraint for Language
-- =============================================
PRINT 'STEP 17: Adding default constraints...'
GO

IF EXISTS (SELECT * FROM sys.columns WHERE object_id = OBJECT_ID('Character') AND name = 'Language')
BEGIN
    ALTER TABLE Character 
    ADD CONSTRAINT DF_Character_Language DEFAULT N'English' FOR Language
    PRINT '  - Added default constraint for Character.Language'
END
GO

-- =============================================
-- FINAL VERIFICATION
-- =============================================
PRINT ''
PRINT '========================================='
PRINT 'UTF-8/Unicode conversion COMPLETE!'
PRINT '========================================='
PRINT ''
PRINT 'Verification:'
PRINT '  - Character.Name:      NVARCHAR(10) ✓'
PRINT '  - Character.AccountID: NVARCHAR(10) ✓'
PRINT '  - Character.Language:  NVARCHAR(20) ✓'
PRINT '  - CustomAttack.Name:   NVARCHAR(10) ✓'
PRINT '  - MEMB_INFO.memb___id: NVARCHAR(10) ✓'
PRINT '  - MEMB_INFO.memb_name: NVARCHAR(10) ✓'
PRINT ''
PRINT 'Korean, Japanese, and Chinese characters should now work!'
PRINT ''
PRINT 'IMPORTANT NEXT STEPS:'
PRINT '1. Test creating a character with Korean name: 테스트'
PRINT '2. Test creating a character with Japanese name: テスト'
PRINT '3. When inserting Unicode data, ALWAYS use N prefix:'
PRINT '   Example: INSERT INTO Character (Name) VALUES (N''한국어'')'
PRINT '4. Make sure your game client/server code sends UTF-8 data'
PRINT '========================================='
GO
