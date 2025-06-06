#pragma once
#define InputBox_GetText					((void(__thiscall*)(int thisa, LPSTR lpString, int nMaxCount)) 0x004217D0)
#define InputBox_SetText					((void(__thiscall*)(int thisa, const char* pszText)) 0x00421830)
#define RequestLogin						((int(__thiscall*)(int This)) 0x0040B7B0)
#define Sprite_SetPosition					((void(__thiscall*)(BYTE * CButton, int cx, int cy, int eChangedPram)) 0x00416640)
#define CUIRenderText_SetFont				((int(__thiscall*)(int This, int a2)) 0x00420120)
#define pTextThis							((LPVOID(*)()) 0x0041FE10)
#define _Instance							((int(*)()) 0x00482B70)
#define SEASON3B_CheckMouseIn				((bool(__cdecl*)(int a1, int a2, int a3, int a4)) 0x00790B10)
#define IsPress								((int(__cdecl*)(int VKBUTTON)) 0x00791070)
#define RenderBitmap						((void(__cdecl*)(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, char a10, char a11, float a12)) 0x00637C60)
#define PlayBuffer							((signed int(__cdecl*)(int a1, int a2, int a3)) 0x006D6C20)
#define LoginWinCreate						((void(__thiscall*)(int This)) 0x0040AD70)
#define MAX_ACCOUNT_SAVE					5


typedef void(*PUSHEVENT_CALLBACK_LPVOID)(LPVOID);

struct AUTOLOGIN_ACCOUNT
{
	char ID[11];
	char PW[11];
	int	 index;
};

class cAutoLogin
{
public:
	cAutoLogin();
	~cAutoLogin();
	void Load();
	void ReadConfigs();
	BOOL savePass;
	char iUser[32];
	char iPassword[32];
	DWORD lastClick;
	static void __thiscall DoRequestLogin();
	void Login(char* id, char* pw, bool pressOK = true);
	void Login(int acc, bool pressOK = true);

	static void TongleAccount(LPVOID pClass);
	static void RemoveAccount(LPVOID pClass);
	bool GetShowListAccount(bool checkTick = true);
	void SetShowListAccount(bool show);
	void SetTickCount(DWORD tick);
	int GetSelectedAccount();
	void SetSelectedAccount(int acc) { this->selectedAccount = acc; }
	int	 totalSavedAcc;
	void SaveAccount(char* ID, char* PW, bool Save);
	AUTOLOGIN_ACCOUNT	saved_acc[MAX_ACCOUNT_SAVE];

	
	void DrawButton(int IMGcode, float x, float y, float w, float h, float uw, float uh, float a8, float a9, PUSHEVENT_CALLBACK_LPVOID pCallbackFunc);
	void DrawButton(int IMGcode, float x, float y, float w, float h, float uw, float uh, float a8, float a9, PUSHEVENT_CALLBACK_LPVOID pCallbackFunc, bool a11);
private:
	bool showListAccount;
	DWORD TickCount;
	int  selectedAccount;
};

extern cAutoLogin AutoLogin;