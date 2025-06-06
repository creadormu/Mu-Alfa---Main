#include "StdAfx.h"
#include "CustomCommandInfo.h"
#include "Defines.h"
#include "Interface.h"
#include "Central.h"
#include "User.h"
// -------------------------------------------------------------------------------

CCustomCommandInfo gCustomCommandInfo;
// -------------------------------------------------------------------------------

CCustomCommandInfo::CCustomCommandInfo()
{
	this->Init();
	this->Moving = false;
	this->ultimoX = 205;
    this->ultimoY = 95;
}
// -------------------------------------------------------------------------------

CCustomCommandInfo::~CCustomCommandInfo()
{
	// ----
}
// -------------------------------------------------------------------------------

void CCustomCommandInfo::Init() // OK
{
	for(int n=0;n < MAX_CUSTOM_COMMAND;n++)
	{
		this->m_CustomCommandInfo[n].Index = -1;
	}
	this->Count = 0;
	this->Page = 0;
}

void CCustomCommandInfo::Load(CUSTOM_COMMAND_INFO* info) // OK
{
	for(int n=0;n < MAX_CUSTOM_COMMAND;n++)
	{
		this->SetInfo(info[n]);
	}
}

void CCustomCommandInfo::SetInfo(CUSTOM_COMMAND_INFO info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_CUSTOM_COMMAND)
	{
		return;
	}
	this->Count = info.Index+1;
	this->m_CustomCommandInfo[info.Index] = info;
}

CUSTOM_COMMAND_INFO* CCustomCommandInfo::GetInfo(int index) // OK
{
	if(index < 0 || index >= MAX_CUSTOM_COMMAND)
	{
		return 0;
	}

	if(this->m_CustomCommandInfo[index].Index != index)
	{
		return 0;
	}

	return &this->m_CustomCommandInfo[index];
}

int next = 0;
int prev = 0;

void CCustomCommandInfo::DrawCommandWindow()
{
	if( !gInterface.Data[eCommand_MAIN].OnShow )
	{
		return;
	}

	// ----
	float MainWidth			= 230.0;
	float MainHeight		= 320.0;
	float StartX = this->ultimoX;
	float StartY = this->ultimoY;
	float curX = pCursorX >= MAX_WIN_WIDTH ? 0 : pCursorX;
	float curY = pCursorY >= MAX_WIN_HEIGHT ? 0 : pCursorY;

	if (gInterface.IsWorkZone3(StartX, StartY, 329 / (resizeGuiRate * resizeGuiScaleRateX), 72 / (resizeGuiRate * resizeGuiScaleRateY), true)) 
	{	
		if (!this->Moving && GetKeyState(VK_LBUTTON) & 0x8000) {
			this->Moving = true;
			this->mX = curX;
			this->mY = curY;
		}	
	}

	if (this->Moving) {
		StartX = this->ultimoX + (curX - this->mX);
		StartY = this->ultimoY + (curY - this->mY);
		StartX = StartX < -5 ? -5 : StartX;
		StartX = StartX > 465 ? 465 : StartX;
		StartY = StartY < 20 ? 20 : StartY;
		StartY = StartY > 95 ? 95 : StartY;
	}

	if (this->Moving && !(GetKeyState(VK_LBUTTON) & 0x8000)) {
		this->Moving = false;
		this->ultimoX = StartX;
		this->ultimoY = StartY;
	}


	// ----
	DWORD Color = eGray100;

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);
	// ----
	gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartY + 10, 210, 3, "Commands");

	//
	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartY + 35, 200, 1); //-- Divisor


	if ((this->Page == 0 && this->Count > 25) || (this->Page == 1 && this->Count > 50) || (this->Page == 2 && this->Count > 75))
	{
		gInterface.DrawGUI2(eNextCommand, StartX + MainWidth - 8, StartY + 80);
	}
	else 
	{
		gInterface.ResetDrawIMG2(eNextCommand);
	}

	if (this->Page == 1 || this->Page == 2 || this->Page == 3)
	{
		gInterface.DrawGUI2(ePrevCommand, StartX - 20, StartY + 80);
	}
	else
	{
		gInterface.ResetDrawIMG2(ePrevCommand);
	}

	for( int i = (25*Page)+0; i < (25*Page)+25; i++ )
	{
		if (this->m_CustomCommandInfo[i].Index == -1)
		{
			continue;
		}

		if (this->m_CustomCommandInfo[i].Color == 1)
		{
			Color = eGold;
		}
		else if (this->m_CustomCommandInfo[i].Color == 2)
		{
			Color = eWhite;
		}
		else if (this->m_CustomCommandInfo[i].Color == 3)
		{
			Color = eOrange;
		}
		else if (this->m_CustomCommandInfo[i].Color == 4)
		{
			Color = eRed2;
		}
		else if (this->m_CustomCommandInfo[i].Color == 5)
		{
			Color = eExcellent;
		}
		else if (this->m_CustomCommandInfo[i].Color == 6)
		{
			Color = eYellow;
		}
		else if (this->m_CustomCommandInfo[i].Color == 7)
		{
			Color = eSocket;
		}
		else
		{
			Color = eGold;
		}

		int x = i;

		if (this->Page > 0)
		{
			x = x-(25*Page);
		}

		gInterface.DrawFormat(Color, (int)StartX + 18, (int)StartY + 50 + (x*10), 100, 1, this->m_CustomCommandInfo[i].Command);

		pDrawColorText(this->m_CustomCommandInfo[i].Description,  (int)StartX + 112, (int)StartY + 50 + (x*10), 100, 0, Color, 0, 1);

	}

	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartY + 285, 200, 1); //-- Divisor

}

void CCustomCommandInfo::OpenCommandWindow()
{

	if (gInterface.Data[eCommand_MAIN].OnShow == true)
	{
		gInterface.Data[eCommand_MAIN].OnShow = false;
		
		if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
		{
			pSetCursorFocus = false;
		}
		return;
	}

	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - gInterface.Data[eRankPANEL_MAIN].EventTick);

	if(Delay < 1500 )
	{
		gInterface.Data[eCommand_MAIN].OnShow = false;
		return;
	}

	gInterface.CloseCustomWindow();
	gInterface.Data[eCommand_MAIN].EventTick = GetTickCount();
	gInterface.Data[eCommand_MAIN].OnShow = true;
	
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}

}

bool CCustomCommandInfo::EventCommandWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eCommand_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[eCommand_MAIN].OnShow || !gInterface.IsWorkZone(eCommand_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eCommand_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eCommand_CLOSE].OnClick = false;
	// ----
	if (Delay < 1000)
	{
		return false;
	}
	// ----
	gInterface.Data[eCommand_CLOSE].EventTick = GetTickCount();
	gInterface.Data[eCommand_MAIN].OnShow = false;
	
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

bool CCustomCommandInfo::CommandNext(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - gInterface.Data[eNextCommand].EventTick);
	DWORD Delay2		= (CurrentTick - gInterface.Data[ePrevCommand].EventTick);

	if( !gInterface.Data[eCommand_MAIN].OnShow  || next == -1)
	{
		return false;
	}
	
	if( !gInterface.IsWorkZone(eNextCommand))
	{
		return false;
	}

	if( Event == WM_LBUTTONDOWN )
	{
		gInterface.Data[eNextCommand].OnClick = true;
		return true;
	}


	if( Delay < 1000 || Delay2 < 1000 )
	{
		return false;
	}
	
	gInterface.Data[eNextCommand].OnClick = false;
	
	this->Page++;
	
	gInterface.Data[eNextCommand].EventTick = GetTickCount();
	

	return true;
}

bool CCustomCommandInfo::CommandPrev(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - gInterface.Data[ePrevCommand].EventTick);
	DWORD Delay2		= (CurrentTick - gInterface.Data[eNextCommand].EventTick);

	if( !gInterface.Data[eCommand_MAIN].OnShow || prev == -1)
	{
		return false;
	}
	
	if( !gInterface.IsWorkZone(ePrevCommand) )
	{
		return false;
	}

	if( Event == WM_LBUTTONDOWN )
	{
		gInterface.Data[ePrevCommand].OnClick = true;
		return true;
	}

	if( Delay < 1000 || Delay2 < 1000 )
	{
		return false;
	}
	
	gInterface.Data[ePrevCommand].OnClick = false;
	
	gInterface.Data[ePrevCommand].EventTick = GetTickCount();

	this->Page--;
	
	return true;
}