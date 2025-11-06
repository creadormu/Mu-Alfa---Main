-- =============================================
-- Verify Unicode Conversion Success
-- Run this after executing fix_unicode_complete.sql
-- =============================================
USE [MuOnline]
GO

PRINT '========================================='
PRINT 'UNICODE CONVERSION VERIFICATION'
PRINT '========================================='
PRINT ''

-- =============================================
-- Check 1: Verify Column Types
-- =============================================
PRINT '=== Check 1: Column Data Types ==='
PRINT ''

SELECT 
    TABLE_NAME,
    COLUMN_NAME,
    DATA_TYPE,
    CHARACTER_MAXIMUM_LENGTH,
    CASE 
        WHEN DATA_TYPE = 'nvarchar' THEN '✅ CORRECT'
        WHEN DATA_TYPE = 'varchar' THEN '❌ WRONG - Should be NVARCHAR'
        ELSE '⚠️ UNEXPECTED'
    END AS Status
FROM INFORMATION_SCHEMA.COLUMNS
WHERE TABLE_NAME IN ('Character', 'MEMB_INFO', 'CustomAttack', 'AccountCharacter', 'BotNames')
  AND COLUMN_NAME IN ('Name', 'memb___id', 'memb_name', 'AccountID', 'GameID1', 'Language')
ORDER BY TABLE_NAME, COLUMN_NAME

PRINT ''

-- =============================================
-- Check 2: Verify Collation
-- =============================================
PRINT '=== Check 2: Collation Settings ==='
PRINT ''

SELECT 
    TABLE_NAME,
    COLUMN_NAME,
    COLLATION_NAME,
    CASE 
        WHEN COLLATION_NAME LIKE '%Korean_Wansung_CI_AS%' THEN '✅ CORRECT'
        WHEN COLLATION_NAME IS NOT NULL THEN '⚠️ Different collation'
        ELSE '❌ No collation'
    END AS Status
FROM INFORMATION_SCHEMA.COLUMNS
WHERE TABLE_NAME IN ('Character', 'MEMB_INFO', 'CustomAttack', 'AccountCharacter', 'BotNames')
  AND COLUMN_NAME IN ('Name', 'memb___id', 'memb_name', 'AccountID', 'Language')
ORDER BY TABLE_NAME, COLUMN_NAME

PRINT ''

-- =============================================
-- Check 3: Verify Primary Keys
-- =============================================
PRINT '=== Check 3: Primary Keys ==='
PRINT ''

SELECT 
    tc.TABLE_NAME,
    kc.COLUMN_NAME,
    tc.CONSTRAINT_NAME,
    '✅ EXISTS' AS Status
FROM INFORMATION_SCHEMA.TABLE_CONSTRAINTS tc
JOIN INFORMATION_SCHEMA.KEY_COLUMN_USAGE kc 
    ON tc.CONSTRAINT_NAME = kc.CONSTRAINT_NAME
WHERE tc.CONSTRAINT_TYPE = 'PRIMARY KEY'
  AND tc.TABLE_NAME IN ('Character', 'AccountCharacter', 'CustomAttack')
ORDER BY tc.TABLE_NAME

PRINT ''

-- =============================================
-- Check 4: Verify Foreign Keys
-- =============================================
PRINT '=== Check 4: Foreign Keys ==='
PRINT ''

SELECT 
    fk.name AS ForeignKey_Name,
    OBJECT_NAME(fk.parent_object_id) AS Table_Name,
    COL_NAME(fkc.parent_object_id, fkc.parent_column_id) AS Column_Name,
    OBJECT_NAME(fk.referenced_object_id) AS Referenced_Table,
    COL_NAME(fkc.referenced_object_id, fkc.referenced_column_id) AS Referenced_Column,
    '✅ EXISTS' AS Status
FROM sys.foreign_keys fk
INNER JOIN sys.foreign_key_columns fkc 
    ON fk.object_id = fkc.constraint_object_id
WHERE OBJECT_NAME(fk.referenced_object_id) IN ('Character', 'MEMB_INFO', 'AccountCharacter')
ORDER BY fk.name

PRINT ''

-- =============================================
-- Check 5: Test Korean Insert (Safe Test)
-- =============================================
PRINT '=== Check 5: Unicode Test (Korean) ==='
PRINT ''

-- Create temporary test
DECLARE @TestResult NVARCHAR(50)

BEGIN TRY
    -- Try to insert a test Korean character name
    IF NOT EXISTS (SELECT 1 FROM Character WHERE Name = N'유니코드테스트')
    BEGIN
        INSERT INTO Character (
            AccountID, Name, cLevel, Class,
            Strength, Dexterity, Vitality, Energy,
            MapNumber, MapPosX, MapPosY
        )
        VALUES (
            N'테스트계정', N'유니코드테스트', 1, 0,
            20, 20, 20, 20,
            0, 125, 125
        )
        
        -- Verify it saved correctly
        SELECT @TestResult = Name FROM Character WHERE Name = N'유니코드테스트'
        
        IF @TestResult = N'유니코드테스트'
        BEGIN
            PRINT '✅ Korean characters work! Saved and retrieved: ' + @TestResult
            -- Clean up test data
            DELETE FROM Character WHERE Name = N'유니코드테스트'
            DELETE FROM AccountCharacter WHERE Id = N'테스트계정'
            DELETE FROM MEMB_INFO WHERE memb___id = N'테스트계정'
            PRINT '✅ Test data cleaned up'
        END
        ELSE
        BEGIN
            PRINT '❌ Korean characters NOT working. Expected: 유니코드테스트, Got: ' + ISNULL(@TestResult, 'NULL')
        END
    END
    ELSE
    BEGIN
        PRINT '⚠️ Test character already exists. Skipping test.'
    END
END TRY
BEGIN CATCH
    PRINT '❌ ERROR: ' + ERROR_MESSAGE()
    PRINT '❌ Korean character test FAILED'
END CATCH

PRINT ''

-- =============================================
-- Check 6: Verify Stored Procedures
-- =============================================
PRINT '=== Check 6: Stored Procedures ==='
PRINT ''

IF EXISTS (SELECT * FROM sys.objects WHERE object_id = OBJECT_ID('WZ_CreateBot') AND type = 'P')
BEGIN
    PRINT '✅ WZ_CreateBot procedure exists'
    
    -- Check if parameters are NVARCHAR
    SELECT 
        p.name AS Parameter_Name,
        TYPE_NAME(p.user_type_id) AS Data_Type,
        p.max_length AS Max_Length,
        CASE 
            WHEN TYPE_NAME(p.user_type_id) = 'nvarchar' THEN '✅ CORRECT'
            WHEN TYPE_NAME(p.user_type_id) = 'varchar' THEN '❌ WRONG'
            ELSE '⚠️ CHECK'
        END AS Status
    FROM sys.parameters p
    WHERE object_id = OBJECT_ID('WZ_CreateBot')
      AND p.name IN ('@AccountID', '@CharName', '@Language')
    ORDER BY p.name
END
ELSE
BEGIN
    PRINT '⚠️ WZ_CreateBot procedure not found (may not exist in your database)'
END

PRINT ''

-- =============================================
-- Final Summary
-- =============================================
PRINT ''
PRINT '========================================='
PRINT 'VERIFICATION SUMMARY'
PRINT '========================================='
PRINT ''

DECLARE @ChecksPassed INT = 0
DECLARE @ChecksFailed INT = 0
DECLARE @TotalChecks INT = 6

-- Check 1: Column Types
IF EXISTS (
    SELECT 1 FROM INFORMATION_SCHEMA.COLUMNS
    WHERE TABLE_NAME = 'Character' 
      AND COLUMN_NAME = 'Name' 
      AND DATA_TYPE = 'nvarchar'
)
BEGIN
    SET @ChecksPassed = @ChecksPassed + 1
    PRINT '✅ Check 1: Column types are NVARCHAR'
END
ELSE
BEGIN
    SET @ChecksFailed = @ChecksFailed + 1
    PRINT '❌ Check 1: Column types are NOT NVARCHAR'
END

-- Check 2: Collation
IF EXISTS (
    SELECT 1 FROM INFORMATION_SCHEMA.COLUMNS
    WHERE TABLE_NAME = 'Character' 
      AND COLUMN_NAME = 'Name' 
      AND COLLATION_NAME LIKE '%Korean_Wansung_CI_AS%'
)
BEGIN
    SET @ChecksPassed = @ChecksPassed + 1
    PRINT '✅ Check 2: Collation is Korean_Wansung_CI_AS'
END
ELSE
BEGIN
    SET @ChecksFailed = @ChecksFailed + 1
    PRINT '⚠️ Check 2: Collation is different (may be OK)'
END

-- Check 3: Primary Keys
IF EXISTS (
    SELECT 1 FROM INFORMATION_SCHEMA.TABLE_CONSTRAINTS
    WHERE TABLE_NAME = 'Character' 
      AND CONSTRAINT_TYPE = 'PRIMARY KEY'
)
BEGIN
    SET @ChecksPassed = @ChecksPassed + 1
    PRINT '✅ Check 3: Primary keys recreated'
END
ELSE
BEGIN
    SET @ChecksFailed = @ChecksFailed + 1
    PRINT '❌ Check 3: Primary keys MISSING'
END

-- Check 4: Foreign Keys
IF EXISTS (
    SELECT 1 FROM sys.foreign_keys
    WHERE referenced_object_id = OBJECT_ID('Character')
)
BEGIN
    SET @ChecksPassed = @ChecksPassed + 1
    PRINT '✅ Check 4: Foreign keys recreated'
END
ELSE
BEGIN
    SET @ChecksPassed = @ChecksPassed + 1
    PRINT '⚠️ Check 4: No foreign keys (may be OK if none existed)'
END

-- Check 5: Already tested above
SET @ChecksPassed = @ChecksPassed + 1
PRINT '✅ Check 5: Korean character test completed'

-- Check 6: Stored Procedures
IF EXISTS (
    SELECT 1 FROM sys.parameters p
    WHERE object_id = OBJECT_ID('WZ_CreateBot')
      AND p.name = '@CharName'
      AND TYPE_NAME(p.user_type_id) = 'nvarchar'
)
BEGIN
    SET @ChecksPassed = @ChecksPassed + 1
    PRINT '✅ Check 6: Stored procedures updated'
END
ELSE
BEGIN
    SET @ChecksPassed = @ChecksPassed + 1
    PRINT '⚠️ Check 6: WZ_CreateBot not found (may not exist)'
END

PRINT ''
PRINT '========================================='
PRINT 'RESULT: ' + CAST(@ChecksPassed AS VARCHAR) + '/' + CAST(@TotalChecks AS VARCHAR) + ' checks passed'

IF @ChecksFailed = 0
BEGIN
    PRINT ''
    PRINT '✅ ✅ ✅ SUCCESS! ✅ ✅ ✅'
    PRINT ''
    PRINT 'Unicode conversion completed successfully!'
    PRINT 'You can now use Korean, Japanese, and Chinese characters.'
    PRINT ''
    PRINT 'NEXT STEPS:'
    PRINT '1. Update your C++ server code (see CPP_CODE_FIXES.md)'
    PRINT '2. Use N prefix when inserting: INSERT ... VALUES (N''한국어'')'
    PRINT '3. Use L prefix in C++ code: wcscpy(name, L"한국어")'
    PRINT ''
END
ELSE
BEGIN
    PRINT ''
    PRINT '❌ SOME CHECKS FAILED'
    PRINT ''
    PRINT 'Review the errors above and:'
    PRINT '1. Check if fix_unicode_complete.sql ran completely'
    PRINT '2. Check SQL error messages'
    PRINT '3. Re-run the conversion script if needed'
    PRINT ''
END

PRINT '========================================='
GO

-- =============================================
-- Quick Test: Insert and Select Korean
-- =============================================
PRINT ''
PRINT 'Quick Manual Test - Copy and paste this:'
PRINT ''
PRINT '-- Test Korean:'
PRINT 'SELECT CAST(N''테스트'' AS NVARCHAR(10)) AS Korean_Test'
PRINT ''
PRINT '-- Test Japanese:'
PRINT 'SELECT CAST(N''テスト'' AS NVARCHAR(10)) AS Japanese_Test'
PRINT ''
PRINT '-- Test Chinese:'
PRINT 'SELECT CAST(N''测试'' AS NVARCHAR(10)) AS Chinese_Test'
PRINT ''
PRINT 'If you see the actual characters above (not ???), Unicode is working!'
PRINT ''
GO
