# Unicode Support Implementation Guide for MU Online

## Problem
Korean, Japanese, and Chinese characters display as symbols (�����) instead of actual characters because the database uses `VARCHAR` (single-byte) instead of `NVARCHAR` (Unicode/multi-byte).

## Solution Overview
1. ✅ Convert database columns from `VARCHAR` to `NVARCHAR`
2. ⚠️ Update C++ server code to handle Unicode properly
3. ⚠️ Ensure client sends UTF-8 encoded data

---

## Step 1: Database Conversion ✓

### Run the Fixed SQL Script

I've created a corrected version: `fix_unicode_complete.sql`

**What it fixes from your previous script:**
- ✅ Drops `PK_CustomAttack` constraint before altering `CustomAttack.Name`
- ✅ Drops `IX_BotNames_Language_Gender` index before altering `BotNames.Language`
- ✅ Drops ALL dependent objects in correct order
- ✅ Recreates everything after conversion

### Execute the script:

```sql
-- 1. BACKUP FIRST (CRITICAL!)
BACKUP DATABASE [MuOnline] TO DISK = 'C:\Backup\MuOnline_Before_UTF8.bak'

-- 2. Run the conversion script
-- Execute: fix_unicode_complete.sql in SQL Server Management Studio
```

### Verify the conversion:

```sql
-- Check column types
SELECT 
    TABLE_NAME,
    COLUMN_NAME,
    DATA_TYPE,
    CHARACTER_MAXIMUM_LENGTH,
    COLLATION_NAME
FROM INFORMATION_SCHEMA.COLUMNS
WHERE TABLE_NAME IN ('Character', 'MEMB_INFO', 'CustomAttack', 'AccountCharacter')
  AND COLUMN_NAME IN ('Name', 'memb___id', 'memb_name', 'AccountID', 'GameID1')
ORDER BY TABLE_NAME, COLUMN_NAME
```

Expected results:
- `Character.Name`: **NVARCHAR(10)**
- `Character.AccountID`: **NVARCHAR(10)**
- `MEMB_INFO.memb___id`: **NVARCHAR(10)**
- `CustomAttack.Name`: **NVARCHAR(10)**

---

## Step 2: C++ Server Code Updates ⚠️

The database change alone is NOT enough. Your C++ server code needs to handle Unicode properly.

### Required C++ Code Changes

#### A. Use Wide Character APIs

**Find code like this (WRONG - Single-byte):**
```cpp
char szCharName[11];
strcpy(szCharName, "한국어");  // Will corrupt!
```

**Replace with (CORRECT - Multi-byte/Unicode):**
```cpp
wchar_t wszCharName[11];
wcscpy(wszCharName, L"한국어");  // L prefix for wide strings
```

#### B. Database Connection String

Add charset parameter to your SQL connection:

```cpp
// In your database connection code:
// ODBC connection string example:
"Driver={SQL Server Native Client 11.0};Server=localhost;Database=MuOnline;Trusted_Connection=yes;CHARSET=UTF8;"

// Or for newer drivers:
"Driver={ODBC Driver 17 for SQL Server};Server=localhost;Database=MuOnline;Trusted_Connection=yes;CharacterSet=UTF-8;"
```

#### C. SQL Parameter Binding

When binding character names to SQL queries:

**WRONG:**
```cpp
// Using SQL_C_CHAR (single-byte)
SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 
                 10, 0, szCharName, 0, &cbName);
```

**CORRECT:**
```cpp
// Using SQL_C_WCHAR (wide character)
SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_C_WCHAR, SQL_WVARCHAR, 
                 10, 0, wszCharName, 0, &cbName);
```

#### D. Packet Handling

If your server sends/receives character names in packets:

```cpp
// When receiving from client:
void CGameServer::ReceiveCreateCharacter(BYTE* packet) {
    // Assuming packet contains UTF-8 encoded name
    char szUTF8Name[31];  // UTF-8 can be up to 3x longer
    memcpy(szUTF8Name, packet + 0x04, 30);
    
    // Convert UTF-8 to Wide Char
    wchar_t wszName[11];
    MultiByteToWideChar(CP_UTF8, 0, szUTF8Name, -1, wszName, 11);
    
    // Now use wszName for database operations
}

// When sending to client:
void CGameServer::SendCharacterList(SOCKET sock, wchar_t* wszName) {
    char szUTF8Name[31];
    
    // Convert Wide Char to UTF-8
    WideCharToMultiByte(CP_UTF8, 0, wszName, -1, szUTF8Name, 31, NULL, NULL);
    
    // Send szUTF8Name in packet
}
```

### Key Files to Check

Search your codebase for these patterns:

```bash
# Find character name handling
grep -r "char.*Name\[" Main/
grep -r "strcpy" Main/
grep -r "sprintf" Main/

# Find SQL queries with character names
grep -r "INSERT INTO Character" Main/
grep -r "SELECT.*FROM Character" Main/
grep -r "SQLBindParameter" Main/
```

Look for files like:
- `CharacterManager.cpp`
- `DBHandler.cpp` / `Database.cpp`
- `Protocol.cpp` / `PacketHandler.cpp`
- `UserManager.cpp`

---

## Step 3: Client Configuration

### Client-side requirements:

1. **Font Support**: Client needs fonts that support Korean/Japanese/Chinese
   - Check if `main.exe` has proper font files
   - May need to add fonts like: `Malgun Gothic`, `Meiryo`, `SimSun`

2. **Encoding**: Client should send character names as UTF-8
   - Check client's locale settings
   - May need to set codepage in client config

---

## Testing Guide

### Test 1: Database Insert (SQL)

```sql
-- Test inserting Korean name directly
INSERT INTO Character (Name, AccountID, cLevel, Class)
VALUES (N'테스트', N'test123', 1, 0)  -- N prefix is CRITICAL!

-- Verify it saved correctly
SELECT Name, AccountID FROM Character WHERE AccountID = N'test123'
-- Should display: 테스트
```

### Test 2: Server Code Test

Create a test character through your game server:

```cpp
// In your test code:
wchar_t wszTestName[] = L"한국어";
CreateCharacter(L"testaccount", wszTestName, 0, 0);

// Check if it appears correctly in database
```

### Test 3: In-Game Test

1. Launch game client
2. Create character with Korean name: `테스트유저`
3. Login and check if name displays correctly
4. Check character list displays correctly

---

## Common Issues & Solutions

### Issue 1: Still seeing ??? or �����

**Cause**: Server code not using wide characters (WCHAR)
**Solution**: Update C++ code to use `wchar_t` and `L"string"` prefix

### Issue 2: Name saves as ? in database

**Cause**: Not using N prefix in SQL or SQL_WVARCHAR binding
**Solution**: 
```cpp
SQLBindParameter(..., SQL_C_WCHAR, SQL_WVARCHAR, ...)
```

### Issue 3: Names appear corrupted after server restart

**Cause**: Reading from database as single-byte char instead of wchar_t
**Solution**: Use `SQLBindCol` with `SQL_C_WCHAR`:
```cpp
wchar_t wszName[11];
SQLBindCol(hStmt, 1, SQL_C_WCHAR, wszName, sizeof(wszName), &cbName);
```

### Issue 4: Client shows boxes □□□

**Cause**: Client font doesn't support the character set
**Solution**: Install appropriate font in client directory

---

## Critical Reminders

1. ✅ **ALWAYS use N prefix** for Unicode strings in SQL:
   ```sql
   VALUES (N'한국어')  -- Correct
   VALUES ('한국어')   -- Wrong! Will corrupt
   ```

2. ✅ **ALWAYS use L prefix** for wide strings in C++:
   ```cpp
   wchar_t* name = L"한국어";  // Correct
   char* name = "한국어";       // Wrong! Will corrupt
   ```

3. ✅ **ALWAYS use WCHAR types** in C++ for names:
   ```cpp
   wchar_t wszName[11];     // Correct
   char szName[11];         // Wrong for Unicode!
   ```

4. ✅ **Check packet protocol**: Ensure client/server agree on UTF-8 encoding

---

## Next Steps

1. ✅ Run `fix_unicode_complete.sql`
2. ⚠️ Update C++ server code (Character creation/loading)
3. ⚠️ Update C++ packet handlers (Send/Receive character names)
4. ⚠️ Test with Korean/Japanese characters
5. ⚠️ Check client font support

---

## Need Help?

If you need help with specific C++ code changes:

1. Share your character creation code
2. Share your database query code
3. Share packet structure definitions

I can provide exact code modifications for your specific implementation.
