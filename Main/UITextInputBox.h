#pragma once

#define newClass									((int(__cdecl*)(int Type)) 0x009D00C5)

#define new_CUITextInputBox							((DWORD* (__thiscall*)(DWORD* thisa)) 0x00420F60)
#define CUITextInputBox_Init						((void (__thiscall*)(DWORD* thisa, HWND hWnd, int iWidth, int iHeight, int iMaxLength, BOOL bIsPassword)) 0x00421B90)
#define CUITextInputBox_SetState					((void (__thiscall*)(DWORD* thisa, int type)) 0x00421D30)
#define CUITextInputBox_GiveFocus					((void (__thiscall*)(DWORD* thisa, BOOL bSel)) 0x00421D80)
#define CUITextInputBox_SetText						((void (__thiscall*)(DWORD* thisa, const char* pszText)) 0x00421830)
#define CUITextInputBox_Render						((void (__thiscall*)(DWORD* thisa)) 0x00422320)
#define CUITextInputBox_SetFont						((void (__thiscall*)(DWORD* thisa, HFONT hFont)) 0x00423060)
#define CUITextInputBox_GetText						((void (__thiscall*)(DWORD* thisa, char * pszText, int iGetLenght)) 0x004217D0)

enum UISTATES
{
	UISTATE_NORMAL = 0,
	UISTATE_RESIZE, 
	UISTATE_SCROLL, 
	UISTATE_HIDE,
	UISTATE_MOVE, 
	UISTATE_READY, 
	UISTATE_DISABLE
};

class CUITextInputBox
{
public:
	CUITextInputBox();
	virtual ~CUITextInputBox();
	void Init();
	//--
	void Render();
	DWORD* GetInput();
	const POINT& GetPos();
	const SIZE& GetSize();
	bool CheckMouseTarget();
	//--
	void ChangeEditBox(int type);
	void SetPosition(int x, int y);
	void SetTextColor(BYTE a, BYTE r, BYTE g, BYTE b);
	void SetBackColor(BYTE a, BYTE r, BYTE g, BYTE b);
	void SetSelectBackColor(BYTE a, BYTE r, BYTE g, BYTE b);
	void GetText(char* pszText, int iGetLenght = 255);

	void SetFont(HFONT hFont);
	void SetState(int iState);
	void GiveFocus(BOOL bSel = FALSE);
	void SetTabTarget(CUITextInputBox * pTabTarget);
	void Init(HWND hWnd, int iWidth, int iHeight, int iMaxLength = 50, BOOL bIsPassword = FALSE);

	DWORD* m_InputBox;
private:
	POINT       m_Pos;
	SIZE        m_Size;
};