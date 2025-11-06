# Quick Start Guide: Fix Korean/Japanese Characters in MU Online

## 🎯 Problem
Korean/Japanese characters show as `�����` or `???` because:
1. ❌ Database uses `VARCHAR` (single-byte)
2. ❌ C++ code uses `char` (single-byte)
3. ❌ No Unicode encoding in packets

## ✅ Solution (3 Steps)

---

## Step 1: Fix Database (15 minutes)

### 1.1 Backup Database (CRITICAL!)
```sql
BACKUP DATABASE [MuOnline] TO DISK = 'C:\Backup\MuOnline_Before_UTF8.bak'
```

### 1.2 Run the Fix Script
- Open SQL Server Management Studio
- Open file: **`fix_unicode_complete.sql`**
- Press F5 to execute
- Wait for "UTF-8/Unicode conversion COMPLETE!" message

### 1.3 Verify Success
```sql
-- Check if columns are NVARCHAR
SELECT 
    TABLE_NAME,
    COLUMN_NAME,
    DATA_TYPE
FROM INFORMATION_SCHEMA.COLUMNS
WHERE TABLE_NAME = 'Character' AND COLUMN_NAME = 'Name'
```

✅ Should show: `NVARCHAR`  
❌ If shows: `VARCHAR` - Script failed, check errors

### 1.4 Test Database
```sql
-- Try inserting Korean name (N prefix is CRITICAL!)
INSERT INTO Character (Name, AccountID, cLevel, Class)
VALUES (N'테스트', N'test123', 1, 0)

-- Check it saved correctly
SELECT Name FROM Character WHERE AccountID = N'test123'
```

✅ Should display: `테스트`  
❌ If displays: `???` - N prefix was missing or columns not NVARCHAR

---

## Step 2: Fix C++ Code (1-2 hours)

### 2.1 Change Character Structures

**Find in your code:**
```cpp
char Name[11];        // ❌ WRONG
char getName[11];     // ❌ WRONG
char ReconnectName[11]; // ❌ WRONG
```

**Replace with:**
```cpp
wchar_t Name[11];        // ✅ CORRECT
wchar_t getName[11];     // ✅ CORRECT
wchar_t ReconnectName[11]; // ✅ CORRECT
```

### 2.2 Change String Literals

**Find:**
```cpp
strcpy(name, "한국어");   // ❌ WRONG
```

**Replace:**
```cpp
wcscpy(name, L"한국어");  // ✅ CORRECT (note the L prefix!)
```

### 2.3 Fix Database Queries

**Find:**
```cpp
SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, 
    SQL_C_CHAR, SQL_VARCHAR, ...);  // ❌ WRONG
```

**Replace:**
```cpp
SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, 
    SQL_C_WCHAR, SQL_WVARCHAR, ...);  // ✅ CORRECT
```

### 2.4 Fix Packet Handling

**When receiving packet with name:**
```cpp
// Packet contains UTF-8 bytes
char szUTF8Name[31];
memcpy(szUTF8Name, packet + offset, 30);

// Convert to wide char
wchar_t wszName[11];
MultiByteToWideChar(CP_UTF8, 0, szUTF8Name, -1, wszName, 11);

// Now use wszName for database
```

**When sending packet with name:**
```cpp
// Convert wide char to UTF-8 for packet
wchar_t wszName[11] = L"한국어";
char szUTF8Name[31];
WideCharToMultiByte(CP_UTF8, 0, wszName, -1, szUTF8Name, 31, NULL, NULL);

// Send szUTF8Name in packet
memcpy(packet + offset, szUTF8Name, 30);
```

---

## Step 3: Test (30 minutes)

### 3.1 Test Database Directly
```sql
-- Insert Korean
INSERT INTO Character (Name, AccountID, cLevel, Class)
VALUES (N'한국어', N'test1', 1, 0)

-- Insert Japanese
INSERT INTO Character (Name, AccountID, cLevel, Class)
VALUES (N'テスト', N'test2', 1, 0)

-- Insert Chinese
INSERT INTO Character (Name, AccountID, cLevel, Class)
VALUES (N'测试', N'test3', 1, 0)

-- Verify
SELECT Name, AccountID FROM Character WHERE AccountID IN (N'test1', N'test2', N'test3')
```

✅ All names should display correctly

### 3.2 Test from Game Client
1. Start game server
2. Login with test account
3. Create character with Korean name: `테스트유저`
4. Check if name appears correctly in game
5. Check database:
```sql
SELECT Name FROM Character WHERE Name = N'테스트유저'
```

### 3.3 Check Logs
- No SQL errors about data type mismatches
- No corruption warnings
- Names log correctly in server console

---

## ⚠️ Common Mistakes

### Mistake 1: Forgot N prefix in SQL
```sql
VALUES ('한국어')    -- ❌ WRONG! Will corrupt
VALUES (N'한국어')   -- ✅ CORRECT
```

### Mistake 2: Forgot L prefix in C++
```cpp
wcscpy(name, "한국어");   // ❌ WRONG! Will corrupt
wcscpy(name, L"한국어");  // ✅ CORRECT
```

### Mistake 3: Using char instead of wchar_t
```cpp
char name[11];       // ❌ Can't hold Unicode
wchar_t name[11];    // ✅ Can hold Unicode
```

### Mistake 4: Wrong SQL binding type
```cpp
SQL_C_CHAR          // ❌ For VARCHAR (single-byte)
SQL_C_WCHAR         // ✅ For NVARCHAR (Unicode)
```

---

## 🔍 Troubleshooting

### Problem: Still seeing ??? or �����

**Check 1:** Database columns type
```sql
SELECT DATA_TYPE FROM INFORMATION_SCHEMA.COLUMNS 
WHERE TABLE_NAME = 'Character' AND COLUMN_NAME = 'Name'
```
Should be: `nvarchar`

**Check 2:** Using N prefix in SQL?
```sql
-- Must use N prefix!
INSERT INTO Character (Name) VALUES (N'한국어')
```

**Check 3:** C++ code using wchar_t?
```cpp
wchar_t name[11];  // Not char!
```

**Check 4:** SQL binding using WCHAR?
```cpp
SQL_C_WCHAR, SQL_WVARCHAR  // Not SQL_C_CHAR!
```

### Problem: Server crashes after changes

**Likely cause:** Packet size changed

**Check:** If you changed packet structs from `char` to `wchar_t`, packet size doubled!

**Solution:** Either:
- Keep packets as UTF-8 (char arrays), convert at boundaries
- OR update packet protocol on both client and server

### Problem: Names save correctly but don't display in game

**Cause:** Client doesn't have proper fonts

**Solution:**
1. Check client has Korean/Japanese fonts installed
2. Check client configuration for font settings
3. Verify client is receiving UTF-8 encoded data correctly

---

## 📋 Checklist

Database:
- [ ] Backed up database
- [ ] Ran `fix_unicode_complete.sql`
- [ ] Verified Character.Name is NVARCHAR
- [ ] Tested INSERT with N'한국어'
- [ ] Tested SELECT returns correct characters

C++ Code:
- [ ] Changed `char Name[11]` to `wchar_t Name[11]`
- [ ] Changed strcpy to wcscpy
- [ ] Added L prefix to string literals
- [ ] Updated SQL binding to SQL_C_WCHAR
- [ ] Added UTF-8 conversion in packet handlers

Testing:
- [ ] Test Korean name: 한국어테스트
- [ ] Test Japanese name: テストユーザー  
- [ ] Test Chinese name: 测试用户
- [ ] Verified names in database
- [ ] Verified names in game client
- [ ] No server crashes
- [ ] No SQL errors in logs

---

## 📚 Additional Resources

- **`fix_unicode_complete.sql`** - Complete database fix script
- **`UNICODE_IMPLEMENTATION_GUIDE.md`** - Detailed explanation
- **`CPP_CODE_FIXES.md`** - Specific C++ code examples

---

## 🆘 Still Need Help?

Provide these details:

1. **SQL Server error messages** (if any)
2. **C++ compiler errors** (if any)
3. **Your character creation code** (C++ function)
4. **Your database query code** (C++ function)
5. **Screenshot** of what you see in game

Good luck! 🎮
