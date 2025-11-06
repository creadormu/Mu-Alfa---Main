# C++ Code Fixes for Unicode Support

## Critical Issue Found
Your C++ code uses `char Name[10]` which only supports single-byte characters (ASCII). For Korean/Japanese support, you need **`wchar_t Name[11]`** (wide characters).

---

## Files That Need Updates

Based on your codebase, here are the critical changes:

### 1. Protocol.h - Packet Structures

**BEFORE (Single-byte - WRONG):**
```cpp
struct PMSG_PARTYSEARCH_PARTYLIST
{
    char Name[11];  // ❌ Single-byte only!
    int Map;
    int X;
}
```

**AFTER (Unicode - CORRECT):**
```cpp
struct PMSG_PARTYSEARCH_PARTYLIST
{
    wchar_t Name[11];  // ✅ Supports Korean/Japanese!
    int Map;
    int X;
}
```

### 2. User.h - User Structure

**BEFORE:**
```cpp
char getName[11];  // ❌
```

**AFTER:**
```cpp
wchar_t getName[11];  // ✅
```

### 3. Object.h - Character/Party Structures

**BEFORE:**
```cpp
struct PartyList
{
    char Name[10];  // ❌
    BYTE Unknown10;
    BYTE Unknown11;
}

typedef struct  
{
    char Name[11];  // ❌ Character name
    char Class;
    // ...
}
```

**AFTER:**
```cpp
struct PartyList
{
    wchar_t Name[10];  // ✅
    BYTE Unknown10;
    BYTE Unknown11;
}

typedef struct  
{
    wchar_t Name[11];  // ✅ Character name
    char Class;
    // ...
}
```

### 4. Reconnect.cpp - Reconnect Variables

**BEFORE:**
```cpp
char ReconnectAccount[11];
char ReconnectPassword[11];
char ReconnectName[11];  // ❌
```

**AFTER:**
```cpp
wchar_t ReconnectAccount[11];
wchar_t ReconnectPassword[11];
wchar_t ReconnectName[11];  // ✅
```

---

## Critical Function Changes

### A. Memory Copy Operations

**BEFORE (memcpy - WRONG for Unicode):**
```cpp
memcpy(ReconnectName, (void*)(*(DWORD*)(MAIN_CHARACTER_STRUCT) + 0x00), sizeof(ReconnectName));
```

**AFTER (Use wmemcpy or ensure source is wchar_t):**
```cpp
// If source is already wchar_t:
wmemcpy(ReconnectName, (wchar_t*)(*(DWORD*)(MAIN_CHARACTER_STRUCT) + 0x00), 11);

// OR convert from UTF-8 to wide char:
char* pUTF8Name = (char*)(*(DWORD*)(MAIN_CHARACTER_STRUCT) + 0x00);
MultiByteToWideChar(CP_UTF8, 0, pUTF8Name, -1, ReconnectName, 11);
```

### B. String Copy Operations

**BEFORE (strcpy - WRONG):**
```cpp
strcpy_s(Icon.szTip, sizeof(Icon.szTip), gProtect.m_MainInfo.WindowName);
```

**AFTER (wcscpy - CORRECT):**
```cpp
// If WindowName is wchar_t:
wcscpy_s(Icon.szTip, sizeof(Icon.szTip) / sizeof(wchar_t), gProtect.m_MainInfo.WindowName);

// If WindowName is char (ASCII), convert:
MultiByteToWideChar(CP_ACP, 0, gProtect.m_MainInfo.WindowName, -1, Icon.szTip, sizeof(Icon.szTip) / sizeof(wchar_t));
```

### C. Packet Sending/Receiving

**Protocol.cpp - BEFORE:**
```cpp
char Name[11] = { '\0' };
memcpy_s(&Name[0], 10, &lpMsg->chatid[0], 10);
```

**Protocol.cpp - AFTER:**
```cpp
wchar_t Name[11] = { L'\0' };

// If packet contains UTF-8 bytes:
char szUTF8Name[31];  // UTF-8 can be 3x longer
memcpy_s(&szUTF8Name[0], 30, &lpMsg->chatid[0], 30);
MultiByteToWideChar(CP_UTF8, 0, szUTF8Name, -1, Name, 11);

// If packet contains wide characters directly:
wmemcpy_s(Name, 11, (wchar_t*)&lpMsg->chatid[0], 10);
```

---

## Database Operations Fix

### If using ODBC/SQL directly:

**BEFORE (VARCHAR binding - WRONG):**
```cpp
char szCharName[11];
strcpy(szCharName, "한국어");  // Will corrupt!

// Bind parameter
SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, 
    SQL_C_CHAR,      // ❌ Single-byte
    SQL_VARCHAR,     // ❌ Single-byte
    10, 0, szCharName, 0, &cbName);

SQLBindCol(hStmt, 1, 
    SQL_C_CHAR,      // ❌ Single-byte
    szCharName, sizeof(szCharName), &cbName);
```

**AFTER (NVARCHAR binding - CORRECT):**
```cpp
wchar_t wszCharName[11];
wcscpy(wszCharName, L"한국어");  // ✅ Correct!

// Bind parameter
SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, 
    SQL_C_WCHAR,     // ✅ Wide char
    SQL_WVARCHAR,    // ✅ NVARCHAR in SQL
    10, 0, wszCharName, 0, &cbName);

SQLBindCol(hStmt, 1, 
    SQL_C_WCHAR,     // ✅ Wide char
    wszCharName, sizeof(wszCharName), &cbName);
```

### Example: Character Loading from Database

```cpp
bool LoadCharacter(const wchar_t* wszCharName)
{
    SQLHSTMT hStmt;
    SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);
    
    // Use wide string SQL query
    wchar_t wszQuery[256];
    swprintf(wszQuery, 256, 
        L"SELECT Name, AccountID, cLevel FROM Character WHERE Name = ?");
    
    // Prepare and bind
    SQLPrepareW(hStmt, wszQuery, SQL_NTS);
    
    SQLLEN cbName = SQL_NTS;
    SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT,
        SQL_C_WCHAR, SQL_WVARCHAR,
        10, 0, (SQLPOINTER)wszCharName, 0, &cbName);
    
    // Execute
    SQLExecute(hStmt);
    
    // Get results
    wchar_t wszNameResult[11];
    wchar_t wszAccountID[11];
    int nLevel;
    
    SQLBindCol(hStmt, 1, SQL_C_WCHAR, wszNameResult, sizeof(wszNameResult), &cbName);
    SQLBindCol(hStmt, 2, SQL_C_WCHAR, wszAccountID, sizeof(wszAccountID), NULL);
    SQLBindCol(hStmt, 3, SQL_C_SLONG, &nLevel, 0, NULL);
    
    if (SQLFetch(hStmt) == SQL_SUCCESS)
    {
        // wszNameResult now contains Korean/Japanese characters correctly!
        wprintf(L"Loaded: %s\n", wszNameResult);
    }
    
    SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
    return true;
}
```

---

## Packet Protocol Considerations

### Option 1: Send UTF-8 in Packets (Recommended)

Client and server exchange UTF-8 encoded bytes in packets.

**Server receives packet:**
```cpp
struct PMSG_CHARACTER_CREATE
{
    PBMSG_HEAD header;
    char szNameUTF8[31];  // UTF-8 can be up to 3x longer
    BYTE btClass;
};

void OnCharacterCreate(PMSG_CHARACTER_CREATE* lpMsg)
{
    // Convert UTF-8 to Wide Char
    wchar_t wszName[11];
    MultiByteToWideChar(CP_UTF8, 0, lpMsg->szNameUTF8, -1, wszName, 11);
    
    // Now use wszName for database operations
    CreateCharacterInDB(wszName);
}
```

**Server sends packet:**
```cpp
struct PMSG_CHARACTER_INFO
{
    PBMSG_HEAD header;
    char szNameUTF8[31];
};

void SendCharacterInfo(int aIndex, wchar_t* wszName)
{
    PMSG_CHARACTER_INFO pMsg;
    pMsg.header.set(0xF3, 0x01, sizeof(pMsg));
    
    // Convert Wide Char to UTF-8
    WideCharToMultiByte(CP_UTF8, 0, wszName, -1, 
        pMsg.szNameUTF8, sizeof(pMsg.szNameUTF8), NULL, NULL);
    
    DataSend(aIndex, (BYTE*)&pMsg, sizeof(pMsg));
}
```

### Option 2: Send Wide Chars in Packets (Alternative)

**Packet structure:**
```cpp
struct PMSG_CHARACTER_CREATE
{
    PBMSG_HEAD header;
    wchar_t wszName[11];  // Send wide chars directly
    BYTE btClass;
};
```

**Pros:** No conversion needed
**Cons:** Packet size increases (2 bytes per char instead of 1)

---

## Testing Code

Add this test function to verify Unicode support:

```cpp
void TestUnicodeSupport()
{
    // Test 1: Wide string literals
    wchar_t wszKorean[] = L"한국어테스트";
    wchar_t wszJapanese[] = L"テスト";
    wchar_t wszChinese[] = L"测试";
    
    wprintf(L"Korean: %s\n", wszKorean);
    wprintf(L"Japanese: %s\n", wszJapanese);
    wprintf(L"Chinese: %s\n", wszChinese);
    
    // Test 2: UTF-8 to Wide Char conversion
    char szUTF8[] = u8"한국어";
    wchar_t wszConverted[11];
    MultiByteToWideChar(CP_UTF8, 0, szUTF8, -1, wszConverted, 11);
    wprintf(L"Converted: %s\n", wszConverted);
    
    // Test 3: Database roundtrip
    CreateCharacterInDB(L"테스트캐릭터");
    wchar_t wszLoaded[11];
    LoadCharacterFromDB(L"테스트캐릭터", wszLoaded);
    wprintf(L"From DB: %s\n", wszLoaded);
}
```

---

## Compilation Settings

Add to your project properties:

```
1. Character Set: Use Unicode Character Set
   (Not "Use Multi-Byte Character Set")

2. Preprocessor Definitions:
   UNICODE
   _UNICODE

3. C/C++ -> Command Line -> Additional Options:
   /utf-8   (Use UTF-8 for source files)
```

---

## Migration Strategy

### Phase 1: Database (Already done ✅)
- Run `fix_unicode_complete.sql`

### Phase 2: Core Structures
1. Change `char Name[11]` to `wchar_t Name[11]` in:
   - `Object.h` (Character struct)
   - `User.h` (User struct)
   - `Protocol.h` (All packet structs with names)

### Phase 3: String Operations
2. Replace all `strcpy`/`memcpy` with `wcscpy`/`wmemcpy`
3. Replace all `sprintf` with `swprintf` for names
4. Add L prefix to all string literals with names

### Phase 4: Database Code
5. Change SQL parameter binding to `SQL_C_WCHAR`
6. Change SQL column binding to `SQL_C_WCHAR`
7. Use `SQLPrepareW` instead of `SQLPrepare`

### Phase 5: Packet Handling
8. Add UTF-8 ↔ Wide Char conversion at packet boundaries
9. Test with Korean, Japanese, Chinese names

---

## Quick Reference

| Operation | WRONG (ASCII) | CORRECT (Unicode) |
|-----------|---------------|-------------------|
| Declaration | `char name[11]` | `wchar_t name[11]` |
| String Literal | `"한국어"` | `L"한국어"` |
| String Copy | `strcpy(dst, src)` | `wcscpy(dst, src)` |
| Memory Copy | `memcpy(dst, src, 10)` | `wmemcpy(dst, src, 10)` |
| String Format | `sprintf(buf, "%s", name)` | `swprintf(buf, L"%s", name)` |
| SQL Type | `SQL_C_CHAR` | `SQL_C_WCHAR` |
| SQL Prepare | `SQLPrepare` | `SQLPrepareW` |
| String Length | `strlen(str)` | `wcslen(str)` |
| String Compare | `strcmp(a, b)` | `wcscmp(a, b)` |

---

## Need Specific Help?

Share these files for detailed fixes:
1. Your character creation function
2. Your character loading function
3. Your packet handling code for character names
4. Your database query functions

I'll provide exact code replacements for your implementation!
