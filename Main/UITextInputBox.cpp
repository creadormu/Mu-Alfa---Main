#include "StdAfx.h"
#include "Util.h"
#include "UITextInputBox.h"

CUITextInputBox::CUITextInputBox()
{
	this->m_InputBox = NULL;
	this->Init();
}

CUITextInputBox::~CUITextInputBox()
{
}

void CUITextInputBox::Init()
{
	m_InputBox = new_CUITextInputBox((DWORD*)newClass(0xE0u));
}

void CUITextInputBox::SetFont(HFONT hFont)
{
	CUITextInputBox_SetFont(this->m_InputBox, hFont);
}

void CUITextInputBox::SetState(int iState)
{
	CUITextInputBox_SetState(this->m_InputBox, iState);
}

void CUITextInputBox::GiveFocus(BOOL bSel)
{
	CUITextInputBox_GiveFocus(this->m_InputBox, bSel);
}

void CUITextInputBox::Init(HWND hWnd, int iWidth, int iHeight, int iMaxLength, BOOL bIsPassword)
{
	this->m_Size.cx = iWidth;
	this->m_Size.cy = iHeight;
	CUITextInputBox_Init(this->m_InputBox, hWnd, iWidth, iHeight, iMaxLength, bIsPassword);
}

void CUITextInputBox::GetText(char* pszText, int iGetLenght)
{
	CUITextInputBox_GetText(this->m_InputBox, pszText, iGetLenght);
}

void CUITextInputBox::ChangeEditBox(int type)
{
	CUITextInputBox_SetState(m_InputBox, type);
	if ( type == UISTATE_NORMAL ) {CUITextInputBox_GiveFocus(m_InputBox, 0);}
}

void CUITextInputBox::SetTextColor(BYTE a, BYTE r, BYTE g, BYTE b)
{
	(*(void (__thiscall **)(int, BYTE, BYTE, BYTE, BYTE))(*(DWORD *)(int)this->m_InputBox + 64))((int)this->m_InputBox, a, r, g, b);

}
void CUITextInputBox::SetBackColor(BYTE a, BYTE r, BYTE g, BYTE b)
{
	(*(void (__thiscall **)(int, BYTE, BYTE, BYTE, BYTE))(*(DWORD *)(int)this->m_InputBox + 68))((int)this->m_InputBox, a, r, g, b);
}

void CUITextInputBox::SetSelectBackColor(BYTE a, BYTE r, BYTE g, BYTE b)
{
	(*(void (__thiscall **)(int, BYTE, BYTE, BYTE, BYTE))(*(DWORD *)(int)this->m_InputBox + 72))((int)this->m_InputBox, 255, 255, 189, 25);
}

void CUITextInputBox::SetPosition(int x, int y)
{
	this->m_Pos.x = x;
	this->m_Pos.y = y;
	((int(__thiscall*)(int, int, int)) 0x00417EC0)((int)this->m_InputBox, x, y);
}

const POINT& CUITextInputBox::GetPos()
{
	return this->m_Pos;
}

const SIZE& CUITextInputBox::GetSize()
{
	return this->m_Size;
}

bool CUITextInputBox::CheckMouseTarget()
{
	return ((bool(__cdecl*)(int, int, int, int)) 0x00790B10)(
		GetPos().x, GetPos().y, GetSize().cx, GetSize().cy);
}

void CUITextInputBox::Render()
{
	((void (__thiscall*)(DWORD*)) 0x00422320)(this->m_InputBox);
}

DWORD* CUITextInputBox::GetInput()
{
	return this->m_InputBox;
}

void CUITextInputBox::SetTabTarget(CUITextInputBox * pTabTarget)
{
	(*(int (__thiscall **)(int, int))(*(DWORD *)(int)this->m_InputBox + 88))((int)this->m_InputBox, (int)pTabTarget->GetInput());
}
