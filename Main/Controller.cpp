#include "stdafx.h"
#include "resource.h"
#include "Controller.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomRanking.h"
#include "Defines.h"
#include "OffTrade.h"
#include "Protocol.h"
#include "Import.h"
#include "Interface.h"
#include "Protect.h"
#include "TMemory.h"
#include "CSCharacterS13.h"
#include "CMacroUIEx.h"
#include "Camera.h"
#include "TrayModeNew.h"
#include "MiniMap.h"
#include "WindowsStruct.h"
#include "Ruud.h"
#include "Central.h"
#include "JewelBank.h"
#include "MultiCharacter.h"
#include "Achievements.h"
#include "MuaVip.h"
#include "DanhHieu.h"
#include "TuChanInterface.h"
#include "ExQuestWinSystem.h"
// ----------------------------------------------------------------------------------------------

Controller	gController;
// ----------------------------------------------------------------------------------------------
void __declspec(naked) iconHook()
{
	static DWORD dwIcon = (DWORD)LoadIcon(gController.Instance, MAKEINTRESOURCE(IDI_ICON1));
	static DWORD dwJmp = 0x004D0E3C;

	_asm
	{
		MOV EAX, dwIcon
		JMP dwJmp
	}
}

bool Controller::Load()
{
	if( !this->MouseHook )
	{
		this->MouseHook = SetWindowsHookEx(WH_MOUSE, this->Mouse, gController.Instance, GetCurrentThreadId());
		// ----
		if( !this->MouseHook )
		{
			return false;
		}
	}
	// ----
	if( !this->KeyboardHook )
	{
	}
	// ----
	SetOp((LPVOID)0x004D0E2F, iconHook, ASM::CALL);
	return true;
}


LRESULT Controller::Mouse(int Code, WPARAM wParam, LPARAM lParam)
{
	if( GetForegroundWindow() != pGameWindow )
	{
		return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
	}
	// ----
	MOUSEHOOKSTRUCTEX * Mouse	= (MOUSEHOOKSTRUCTEX*)lParam;

	switch(wParam)
	{
	case WM_LBUTTONUP:
	case WM_LBUTTONDOWN:
		{
			gCustomRanking.EventRankingNext(wParam);
			gCustomRanking.EventRankingBack(wParam);
			gInterface.EventVipWindow_Main(wParam);
			gCustomRanking.EventVipWindow_Close(wParam);
			gCustomCommandInfo.EventCommandWindow_Close(wParam);
			gCustomCommandInfo.CommandNext(wParam);
			gCustomCommandInfo.CommandPrev(wParam);
			gCustomEventTime.EventEventTimeWindow_Close(wParam);
			gCustomEventTime.EventNext(wParam);
			gCustomEventTime.EventPrev(wParam);
			gInterface.EventDrawMenu_Open(wParam);
			gInterface.ButtonsMenu(wParam);

			gInterface.EventPartySettingsWindow_Main(wParam);
			gInterface.EventPartySearchWindow_All(wParam);
			gInterface.EventPartySettingsWindow_All(wParam);
			gInterface.EventPartySettingsWindow_Close(wParam);
			gInterface.EventVaultWindow_Main(wParam);
			gInterface.EventVaultWindow_Close(wParam);
			gInterface.EventVaultWindow_Finish(wParam);
			gInterface.EventWARE1Window_Finish(wParam);
			gInterface.EventWARE2Window_Finish(wParam);
			gInterface.EventWARE3Window_Finish(wParam);
			gInterface.EventWARE4Window_Finish(wParam);
			gInterface.EventWARE5Window_Finish(wParam);
			gInterface.EventWARE6Window_Finish(wParam);
			gInterface.EventWARE7Window_Finish(wParam);
			gInterface.EventWARE8Window_Finish(wParam);
			gInterface.EventWARE9Window_Finish(wParam);
			gInterface.EventChangingClassWindow_Main(wParam);
			gInterface.EventChangingClassWindow_Close(wParam);
			gInterface.EventChangingClassWindow_DW(wParam);
			gInterface.EventChangingClassWindow_DK(wParam);
			gInterface.EventChangingClassWindow_ELF(wParam);
			gInterface.EventChangingClassWindow_MG(wParam);
			gInterface.EventChangingClassWindow_DL(wParam);
			gInterface.EventChangingClassWindow_SUM(wParam);
			gInterface.EventChangingClassWindow_RF(wParam);
			gInterface.EventChangeResetWindow_Main(wParam);
			gInterface.EventChangeResetWindow_Close(wParam);
			gInterface.EventChangeResetWindow_5(wParam);
			gInterface.EventChangeResetWindow_10(wParam);
			gInterface.EventChangeResetWindow_15(wParam);
			gInterface.EventChangeResetWindow_20(wParam);
			gInterface.EventChangeResetWindow_25(wParam);			
			gInterface.EventLuckyWheel_Main(wParam);
			gInterface.EventDrawClose_LuckyWheel(wParam);
			gInterface.EventSmithItem_Main(wParam);
			gJewelsBank.Button(wParam);
			gJewelsBank.EventJewelBank_Close(wParam);
			gInterface.EventConfirm_CANCEL(wParam);
			gInterface.EventConfirm_OK(wParam);
			gCRuudShop.RuudShopEventButton(wParam);
			gCSCharacterS13.SelectCharButton(wParam);
			EventMuOffhelper(wParam);

#if (SELECTCHARACTER==1)
			gSelectChar.EventSelectChar(wParam);
#endif
			g_ExWinQuestSystem.Button(wParam);

			G_BEXO_MUA_VIP.BEXO_CLICK_TRANG_MUA_VIP(wParam);
			G_BEXO_MUA_VIP.MAIN_MUA_VIP(wParam);

			G_BEXO_DANH_HIEU.BEXO_CLICK_TRANG_DANH_HIEU(wParam);
			G_BEXO_DANH_HIEU.MAIN_DANH_HIEU(wParam);

			gAchievements.Button(wParam);

			gTuChanInterface.EventTuChanWindow_Main(wParam);

			gCMacroUIEx.ButtonNew(wParam);
			gCMacroUIEx.Button(wParam);

			if(gCRuudShop.RuudRender.Open)
			{
				if ( pCheckMouseOver(gCRuudShop.RuudRender.x, gCRuudShop.RuudRender.y + 10, gCRuudShop.RuudRender.w, 40.0f) == 1 )
				{
					gCRuudShop.RuudRender.Cursor.x = (double)*(DWORD*)0x879340C - gCRuudShop.RuudRender.x;
					gCRuudShop.RuudRender.Cursor.y = (double)*(DWORD*)0x8793410 - gCRuudShop.RuudRender.y;
					if(wParam == WM_LBUTTONDOWN)
					{
						gCRuudShop.RuudRender.Move = 1;
					}
					else
					{
						gCRuudShop.RuudRender.Move = 0;
					}
				}
				else
				{
					gCRuudShop.RuudRender.Move = 0;
				}
			}
			else if(gProtect.m_MainInfo.CustomInterfaceType == 1)
			{
				gInterface.EventNewInterface97_All(wParam);
			}
			else if(gProtect.m_MainInfo.CustomInterfaceType == 2)
			{
				gInterface.EventNewInterface_All(wParam);
			}
			gCMacroUIEx.Button(wParam);
			gOffTrade.EventOffTradeWindow_Main(wParam);
			gOffTrade.EventCloseTradeWindow_Main(wParam);

		}
		
		break;
		case WM_MOUSEMOVE:

			gCRuudShop.MoveWindows(&gCRuudShop.RuudRender,
				((double)*(DWORD*)0x879340C) - gCRuudShop.RuudRender.Cursor.x,
				((double)*(DWORD*)0x8793410) - gCRuudShop.RuudRender.Cursor.y);

			if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
			{
				gCamera.Move(Mouse);
			}
			break;
		case WM_MBUTTONDOWN:
			if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
			{
				gCamera.SetIsMove(1);
				gCamera.SetCursorX(Mouse->pt.x);
				gCamera.SetCursorY(Mouse->pt.y);
			}
			break;
		case WM_MBUTTONUP:
			if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
			{
				gCamera.SetIsMove(0);
			}
			break;
		case WM_MOUSEWHEEL:
			if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
			{
				gCamera.Zoom(Mouse);
			}
			break;
	}
	// ----
	return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
}
// ----------------------------------------------------------------------------------------------

LRESULT Controller::Keyboard(int Code, WPARAM wParam, LPARAM lParam)
{
	if( GetForegroundWindow() != pGameWindow )
	{
		return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
	}

	if (Code < 0) return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
	
	if( (Code == HC_ACTION) && (wParam == WM_KEYDOWN))
	{
		KBDLLHOOKSTRUCT Hook = *((KBDLLHOOKSTRUCT*)lParam);
		switch(Hook.vkCode)
		{
			// --
		case VK_F8:
		{
			gCustomRanking.OpenWindow();
		}
		break;	
		
		case 0x48:
		{
			gCustomEventTime.OpenWindow();
		}
		break;
		case VK_ESCAPE:
		{

			if (gInterface.Data[eCommand_MAIN].OnShow == true  && (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4))
			{
				gInterface.Data[eCommand_MAIN].OnShow = false;

				pSetCursorFocus = false;

				return -1;
			}

			if (gInterface.Data[eRankPANEL_MAIN].OnShow == true  && (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4))
			{
				gInterface.Data[eRankPANEL_MAIN].OnShow = false;

				pSetCursorFocus = false;

				return -1;
			}

			if (gInterface.Data[eEventTimePANEL_MAIN].OnShow == true && (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4))
			{
				gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;

				pSetCursorFocus = false;

				return -1;
			}

			if (gInterface.CheckVipWindow())
			{
				gInterface.CloseVipWindow();
				return -1;
			}

			if (gInterface.CheckMenuWindow())
			{
				gInterface.CloseMenuWindow();
				return -1;
			}

			if (gInterface.CheckMenuWindowTwo())
			{
				gInterface.CloseMenuWindowTwo();
				return -1;
			}

			if (gInterface.CheckVaultWindow())
			{
				gInterface.CloseVaultWindow();
				return -1;
			}

			if (gTuChanInterface.CheckTuChanWindow())
			{
				gTuChanInterface.CloseTuChanWindow();
				return -1;
			}

			if (gInterface.Data[eSMITH_MAIN].OnShow == true)
			{
				gInterface.Data[eSMITH_MAIN].OnShow = false;
				pSetCursorFocus = false;
				return -1;
		    }

			if (gInterface.Data[eCHANGE_RESET_MAIN].OnShow == true)
			{
				gInterface.Data[eCHANGE_RESET_MAIN].OnShow = false;
				pSetCursorFocus = false;
				return -1;
		    }

			if (gInterface.Data[eJEWELBANK_MAIN].OnShow == true)
			{
				gInterface.Data[eJEWELBANK_MAIN].OnShow = false;
				pSetCursorFocus = false;
				return -1;
		    }

			if (gInterface.Data[eSMITH_MAIN].OnShow == true)
			{
				gInterface.Data[eSMITH_MAIN].OnShow = false;
				pSetCursorFocus = false;
				return -1;
		    }

			if (gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow == true)
			{
				gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow = false;
				pSetCursorFocus = false;
				return -1;
		    }

			if (gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow == true)
			{
				gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow = false;
				pSetCursorFocus = false;
				return -1;
		    }

			if (gInterface.Data[eTUCHAN_MAIN].OnShow = true)
			{
				gInterface.Data[eTUCHAN_MAIN].OnShow = false;
				return -1;
			}

			if (gInterface.Data[OBJECT_WIN_QUEST_MAIN].OnShow = true)
			{
				gInterface.Data[OBJECT_WIN_QUEST_MAIN].OnShow = false;
				return -1;
			}

			gInterface.EventChangingClassWindow_Close(wParam);
			gInterface.Data[eCHANGINGCLASS_MAIN].Close();
			gInterface.Data[ePARTYSETTINGS_MAIN].Close();
			gInterface.Data[ePARTYSEARCH_MAIN].Close();
			gInterface.Data[eCHANGE_RESET_CLOSE].Close();
			gInterface.EventChangeResetWindow_Close(wParam);
			gInterface.EventPartySettingsWindow_Close(wParam);
			gInterface.Data[eLuckyWheelMain].Close();
			gInterface.LuckyWheelStateclose();
			gJewelsBank.Active = false;
			gInterface.Data[eJEWELBANK_MAIN].OnShow = false;
			
		}
		break;
		case VK_END:
		{
			if (gInterface.CheckVipWindow())
			{
				gInterface.CloseVipWindow();
			}
			else
			{
				gInterface.CloseCustomWindow();
				gInterface.OpenVipWindow();
			}
		}
		break;
		case VK_SNAPSHOT:
		{
			gInterface.Data[eLogo].EventTick = GetTickCount()+1500;
			return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
		}
		break;

		default:
		break;
		}
	} 
	return (LRESULT) NULL;
	
}
// ----------------------------------------------------------------------------------------------


LRESULT Controller::Window(HWND Window, DWORD Message, WPARAM wParam, LPARAM lParam)
{
	switch(Message)
	{

	case TRAYMODE_ICON_MESSAGE:
		{
			switch(lParam)
			{
			case WM_LBUTTONDBLCLK:
				{
					gTrayMode.SwitchState();
				}
				break;
			}
		}
		break;
	}
	// ----
	return CallWindowProc((WNDPROC)gTrayMode.TempWindowProc, Window, Message, wParam, lParam);
}


