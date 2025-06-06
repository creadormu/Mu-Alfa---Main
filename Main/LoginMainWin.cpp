#include "StdAfx.h"
#include "Util.h"
#include "SEASON3B.h"
#include "UIControl.h"
#include "RegisterForm.h"
#include "LoginMainWin.h"
#include "Object.h"
#include "AutoLoginWin.h"

CLoginMainWin g_pLoginMainWin;

BYTE m_Register[224];
CRegisterForm * FormReg;

CLoginMainWin::CLoginMainWin(void)
{
}

CLoginMainWin::~CLoginMainWin(void)
{
}

void CLoginMainWin::ReciveCreateAccount(BYTE value)
{
	FormReg->RequestAccount(value);
}

void CLoginMainWin::Create(BYTE* thisa, int nWidth, int nHeight, int nTexID, bool bTile)
{
	WinCreate(thisa, nWidth, nHeight, nTexID, bTile);

	CButtonCreate(m_Register, 54, 30, 71620, 3, 2, 1, -1, -1, -1, -1, -1);
	RegisterButton(thisa, m_Register);

	FormReg = new CRegisterForm;
	FormReg->Create(thisa);
}

void CLoginMainWin::SetPosition(BYTE* thisa, int x, int y)
{
	int cx = x + - 61; int cy = 0;

	SpiriteSetPosition(thisa, cx, y, 3);
	SpiriteSetPosition(m_Register, x, y, 3);

	cx = (int)(WindowWidth1  / g_fScreenRate_x) / 2 - 95;
	cy = (int)(WindowHeight1 / g_fScreenRate_y) / 2 - 125;
	FormReg->SetPosicion(cx, cy);
}

void CLoginMainWin::Show(BYTE* thisa, bool bShow)
{
	CWin_Show(thisa, bShow);
	CButton_Show(m_Register, bShow);
}

bool CLoginMainWin::OpenFormRegister(BYTE* thisa)
{
	if (AutoLogin.GetShowListAccount()) {
		return false;
	}
	if(CButtonIsPress(m_Register))
	{
		FormReg->GiveFocus(1, TRUE);
		FormReg->Show(true);
		CUIMngHideWin(CharMakeWin(), FormReg->CWin);
		return false;
	}
	return CButtonIsPress(thisa);
}

void CLoginMainWin::RenderButtonControls(BYTE* thisa)
{
	CSysMenuWin_Render(thisa);
	CButtonRender(m_Register);
}

void CLoginMainWin::CancelLogin(void* thisa)
{
	if (AutoLogin.GetShowListAccount()) {
		return;
	}
	FormReg->Show(false);
	((void(__thiscall*)(void*)) 0x0040BBC0)(thisa);
}

void CLoginMainWin::ManageOKClick(void* thisa)
{
	((void(__thiscall*)(void*)) 0x0040D020)(thisa);
	int v10 = (int)thisa; // [sp+Ch] [bp-8h]@1

	int m_nMsgCode = *(DWORD *)(v10 + 980);

	switch(m_nMsgCode)
	{
	case MESSAGE_FREE_MSG_NOT_BTN:
		{
			switch(FormReg->CodeAction)
			{
				case CREATE_ACCOUNT_FAIL_USERID:
						FormReg->GiveFocus(1, TRUE);
					break;
				case CREATE_ACCOUNT_FAIL_PASSWORD:
						FormReg->GiveFocus(2, TRUE);
					break;
				case CREATE_ACCOUNT_FAIL_PERSOCODE:
						FormReg->GiveFocus(3, TRUE);
					break;
				case CREATE_ACCOUNT_FAIL_CAPTCHA:
						FormReg->GiveFocus(4, TRUE);
					break;
				case CREATE_ACCOUNT_FAIL_ID:
					{
						if(CurrentProtocolState == RECEIVE_JOIN_SERVER_SUCCESS)
						{
							FormReg->Show(true);
							FormReg->GiveFocus(1, TRUE);
						}
						else
						{
							((void(__thiscall*)(void*)) 0x0040BBC0)(FormReg->CWin);
						}
						FormReg->CodeAction = -1;
					}
					break;
				default:
					{
						((void(__thiscall*)(void*)) 0x0040BBC0)(FormReg->CWin);
						FormReg->CodeAction = -1;
					}
					break;
			}
		}
		break;
	}
}

void CLoginMainWin::RenderButtonControls2(BYTE* thisa)
{
	CSpriteRender(thisa);
	if(FormReg != NULL)
	{
		FormReg->RenderForm();
	}
}

void CLoginMainWin::LoadImages()
{
	((void(__cdecl*)())0x006310C0)();
	LoadBitmapA("Custom\\Desig\\register_back.tga", 73618, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\newui_btn_empty_very_small.tga", 71619, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\newui_button_register.tga", 71620, GL_LINEAR, GL_CLAMP, 1, 0);
}

void CLoginMainWin::Init()
{
	SetDword(0x0040C989 + 3, 2); //-- activar msgbox btnOk
	SetCompleteHook(0xE8, 0x004D7602, &CLoginMainWin::LoadImages);
	//--
	SetCompleteHook(0xE8, 0x0040B331, CLoginMainWin::Show);
	SetCompleteHook(0xE8, 0x0040ADA2, CLoginMainWin::Create);
	SetCompleteHook(0xE8, 0x0040B2E2, CLoginMainWin::SetPosition);
	//--
	SetCompleteHook(0xE8, 0x0040C3AF, CLoginMainWin::ManageOKClick);
	SetCompleteHook(0xE8, 0x0040C40B, CLoginMainWin::ManageOKClick);
	SetCompleteHook(0xE8, 0x0040C45F, CLoginMainWin::ManageOKClick);
	//--
	SetCompleteHook(0xE8, 0x0040B422, CLoginMainWin::CancelLogin);
	SetCompleteHook(0xE8, 0x0040B47C, CLoginMainWin::CancelLogin);
	SetCompleteHook(0xE8, 0x0040B3F1, &CLoginMainWin::OpenFormRegister);
	SetCompleteHook(0xE8, 0x0040B515, &CLoginMainWin::RenderButtonControls);
	SetCompleteHook(0xE8, 0x0040AB50, &CLoginMainWin::RenderButtonControls2);
}