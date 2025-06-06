#include "stdafx.h"
#include "TrayModeNew.h"
#include "resource.h"
#include "Controller.h"
#include "Offset.h"
#include "User.h"
#include "Defines.h"
#include "PrintPlayer.h"
#include "CustomMessage.h"
#include "Protect.h"
#include "Import.h"
// ----------------------------------------------------------------------------------------------

TrayMode gTrayMode;
// ----------------------------------------------------------------------------------------------

void TrayMode::Load()
{
	this->TempWindowProc	= NULL;
	this->TempIconProc		= NULL;
	this->InTray			= false;
}
// ----------------------------------------------------------------------------------------------

void TrayMode::SwitchState()
{
	if( IsWindowVisible(*(HWND*)(0x00E8C578)) )
	{
		if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
		{
			ShowWindow(*(HWND*)(0x00E8C578), SW_HIDE);
			UpdateWindow(*(HWND*)(0x00E8C578));
			this->ShowNotify(true);
			this->ShowMessage(NIIF_INFO, gProtect.m_MainInfo.WindowName, "Game has been minimized");
		}
	}
	else
	{
		ShowWindow(*(HWND*)(0x00E8C578), SW_SHOW);
		UpdateWindow(*(HWND*)(0x00E8C578));
		this->ShowNotify(false);
	}
}
// ----------------------------------------------------------------------------------------------

void TrayMode::ShowNotify(bool Mode)
{
	this->InTray = Mode;
	NOTIFYICONDATA Icon		= { 0 };
	// ----
	Icon.cbSize				= sizeof(NOTIFYICONDATA);
	Icon.uID				= TRAYMODE_ICON_ID;
	Icon.uFlags				= NIF_ICON|NIF_MESSAGE|NIF_TIP;
	Icon.hIcon				= (HICON)LoadImage(gController.Instance, MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON), LR_DEFAULTCOLOR);
	this->TempIconProc		= Icon.hIcon;
	Icon.hWnd				= *(HWND*)(0x00E8C578);
	Icon.uCallbackMessage	= TRAYMODE_ICON_MESSAGE;
	// ----
	strcpy_s(Icon.szTip, sizeof(Icon.szTip), gProtect.m_MainInfo.WindowName);
	// ----
	if( *(DWORD*)(MAIN_SCREEN_STATE) == GameProcess )
	{
		char Text[120];
		sprintf(Text, "\n=====================\nName: %s\nLevel: %d\nLocation: %s (%d, %d)", 
			gObjUser.getName,gObjUser.getLevel,pGetMapName(*(int*)0x0E61E18), gObjUser.CoordenadaX, gObjUser.CoordenadaY);
		strcat_s(Icon.szTip, Text);
	}
	// ----
	if( Mode )
	{
		Shell_NotifyIcon(NIM_ADD, &Icon);
	}
	else
	{
		Shell_NotifyIcon(NIM_DELETE, &Icon);
	}
	// ----
	DeleteObject(Icon.hIcon);
}
// ----------------------------------------------------------------------------------------------

void TrayMode::ShowMessage(DWORD Type, char * Title, char * Message)
{
	NOTIFYICONDATA Icon		= { 0 };
	// ----
	Icon.cbSize				= sizeof(NOTIFYICONDATA);
	Icon.uID				= TRAYMODE_ICON_ID;
	Icon.hWnd				= *(HWND*)(0x00E8C578);
	Icon.uFlags				= NIF_ICON | NIF_MESSAGE | NIF_INFO;
	Icon.hIcon				= this->TempIconProc;
	Icon.uCallbackMessage	= TRAYMODE_ICON_MESSAGE;
	Icon.dwInfoFlags		= Type;
	Icon.uTimeout			= 5000;
	// ----
	strcpy(Icon.szInfo, Message);
	strcpy(Icon.szInfoTitle, Title);
	// ----
	Shell_NotifyIcon(NIM_MODIFY, &Icon);
}
// ----------------------------------------------------------------------------------------------