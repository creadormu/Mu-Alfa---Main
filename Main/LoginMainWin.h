#pragma once
#define CWin_Show						((int(__thiscall*)(BYTE* Instance, bool bShow)) 0x004AC2C0)
#define CWin_GetWidth					((int(__thiscall*)(int Instance)) 0x00405C00)
#define CButton_Show					((void(__thiscall*)(BYTE* thisa, bool bShow)) 0x00401520)
#define Spirite_Show					((void(__thiscall*)(BYTE* thisa, bool bShow)) 0x00401CA0)

#define CInputInstance					((int(__thiscall*)()) 0x00407B20)
#define InputGetScreenWidth				((int(__thiscall*)(int Instance)) 0x004011F0)
#define WinCreate						((void(__thiscall*)(BYTE* thisa, int nWidth, int nHeight, int nTexID, bool bTile)) 0x004ABE90)
#define SpriteCreate					((void(__thiscall*)(BYTE* thisa, int nOrgWidth, int nOrgHeight, int nTexID, int nMaxFrame, int aFrameCoord, int nDatumX, int nDatumY, bool bTile, int nSizingDatums, float fScaleX, float fScaleY)) 0x00416210)


#define CSysMenuWin_Render				((void(__thiscall*)(BYTE* thisa)) 0x004AC520)
#define CButtonIsPress					((bool(__thiscall*)(BYTE* thisa)) 0x00404AD0)

#define SetSysMenuWinShow				((int(__thiscall*)(int thisa, int pWin)) 0x00404B20)

#define ConnectConnectionServer			((void(*)()) 0x0040BBF0)
//--
#define CButtonCreate							((void(__thiscall*)(BYTE * CButton, int iWidth, int iHeigth, int iTexture, int nMaxFrame, int nDownFrame, int nActiveFrame, int nDisableFrame, int nCheckUpFrame, int nCheckDownFrame, int nCheckActiveFrame, int nCheckDisableFrame)) 0x00401370)
#define RegisterButton							((void(__thiscall*)(BYTE * thisa, BYTE * CButton)) 0x004AC500)
#define CButtonRender							((void(__thiscall*)(BYTE * Sprite)) 0x004018E0)
#define CSpriteRender							((void(__thiscall*)(BYTE * Sprite)) 0x00416C40)
#define CRenderButtons							((void(__thiscall*)(BYTE * thisa)) 0x004AC520)
#define SpiriteSetPosition						((void(__thiscall*)(BYTE * CButton, int cx, int cy, int eChangedPram)) 0x00416640)
#define SpiriteGetHeight						((int(__thiscall*)(BYTE* thisa)) 0x00401C80)

#define CWin_SetPosition						((void(__thiscall*)(BYTE* thisa, int x, int y)) 0x004AC070)
#define Spirite_GetXPos							((int(__thiscall*)(BYTE* thisa)) 0x00401C20)
#define Spirite_GetYPos							((int(__thiscall*)(BYTE* thisa)) 0x00401C40)
#define Spirite_GetWidth						((int(__thiscall*)(BYTE* thisa)) 0x00401C60)
#define Spirite_GetHeight						((int(__thiscall*)(BYTE* thisa)) 0x00401C80)


class CLoginMainWin
{
public:
	CLoginMainWin(void);
	virtual ~CLoginMainWin(void);
	void Init();
	static void LoadImages();
	void ReciveCreateAccount(BYTE value);
	static void __thiscall CancelLogin(void* thisa);
	static void __thiscall ManageOKClick(void* thisa);
	static void __thiscall Create(BYTE* thisa, int nWidth, int nHeight, int nTexID, bool bTile);
	static bool __thiscall OpenFormRegister(BYTE* thisa);
	static void __thiscall Show(BYTE* thisa, bool bShow);
	static void __thiscall SetPosition(BYTE* thisa, int x, int y);
	static void __thiscall RenderButtonControls(BYTE *thisa);
	static void __thiscall RenderButtonControls2(BYTE *thisa);
};

extern CLoginMainWin g_pLoginMainWin;