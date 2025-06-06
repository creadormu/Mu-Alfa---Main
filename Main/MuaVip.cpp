#include "stdafx.h"
#include "MuaVip.h"
#include "CustomMessage.h"
#include "Defines.h"
#include "Interface.h"
#include "User.h"
#include "Protocol.h"
#include "PrintPlayer.h"
#include "Config.h"
#include "GS_SEND_CLIENT.h"
#include "CustomTinhNang.h"
#include "Central.h"

//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_MUA_VIP G_BEXO_MUA_VIP;
//-----------------------------------------------------------------------------------------------------------------------------------------------------

#define MAX_TRANG_MUA_VIP    0  // OK

int ImgTagExMuaVip1 = 32891; //Rank Dynamic
int ImgTagExMuaVip2 = 32892; //Rank Dynamic
int ImgTagExMuaVip3 = 32893; //Rank Dynamic
int ImgTagExMuaVip4 = 32894; //Rank Dynamic




//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_MUA_VIP::BEXO_MUA_VIP()
{
	TRANG_MUA_VIP = 1;
	//--------------------------------------------------------------
	HIENTHIMUA_VIP = false;
	MainWidth = 640;
	MainHeight = 429;
	StartY = 0;
	StartX = 0;
	ClickTick = 0;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_MUA_VIP::DRAW_MUA_VIP()
{
	DRAW_WINDOW_MUA_VIP();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_MUA_VIP::BEXO_CLICK_TRANG_MUA_VIP(DWORD ClickMouse)
{
	if (!gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow)
	{
		return;
	}
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - ClickTick);
	if (gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow && gInterface.IsWorkZone(eSAMPLEBUTTON2))
	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			return;
		}
		pSetCursorFocus = false;
		if (Delay < 300)
		{
			return;
		}
		if (1 < TRANG_MUA_VIP && TRANG_MUA_VIP <= MAX_TRANG_MUA_VIP)
		{
			TRANG_MUA_VIP--;
		}
		ClickTick = GetTickCount();
	}
	if (gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow && gInterface.IsWorkZone(eSAMPLEBUTTON))

	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			return;
		}
		pSetCursorFocus = false;
		if (Delay < 300)
		{
			return;
		}
		if (1 <= TRANG_MUA_VIP && TRANG_MUA_VIP < MAX_TRANG_MUA_VIP)
		{
			TRANG_MUA_VIP++;
		}
		ClickTick = GetTickCount();
	}
	if (TRANG_MUA_VIP < 1)
	{
		TRANG_MUA_VIP = 1;
	}
	if (TRANG_MUA_VIP > TRANG_MUA_VIP)
	{
		TRANG_MUA_VIP = TRANG_MUA_VIP;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------

void BEXO_MUA_VIP::DRAW_WINDOW_MUA_VIP()
{

	if (gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::MuHelper)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::CashShop)

		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Character)

		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse))
	{
		return;
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (!gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow)
	{
		return;
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	
	
	//gCentral.PrintDropBox(StartX + 70, StartY + 50, 490, 300, 0, 0); // FONDO NEGRO --------------------------------------------
	pDrawGUFULL(0x0899, StartX + 70, StartY + 50, 900, 550, 0, 0, 1, 1, 1, 1, 0.0); // MENU --------------------------------------
	
	
	//gInterface.DrawGUI(EXBEXO_MUA_VIP_MAIN, StartX, StartY);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gInterface.IsWorkZone4(StartX, StartY, StartX + MainWidth, StartY + MainHeight)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//pDrawMessage("", 0); // Không Cho Hiện Thông Báo Trên Màn Hình
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eWhite, StartX + 115, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 90, 210, 1, Config.TextVN_MuaVip[0]);
	gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 105, 210, 1, Config.TextVN_MuaVip[1]);
	gInterface.DrawFormat(eSocket, StartX + 105, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 120, 210, 1, Config.TextVN_MuaVip[2]);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_MUA_VIP_NANG_CAP, StartX + 435, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 100);

	if (gInterface.IsWorkZone(EXBEXO_MUA_VIP_NANG_CAP))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(EXBEXO_MUA_VIP_NANG_CAP, gInterface.Data[EXBEXO_MUA_VIP_NANG_CAP].X, gInterface.Data[EXBEXO_MUA_VIP_NANG_CAP].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eAncient, StartX + 455, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 110, 210, 1, Config.TextVN_MuaVip[3]);

	gInterface.DrawFormat(eYellow, StartX + 270, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 132, 210, 1, Config.TextVN_MuaVip[4], gRecvGS.m_RankTitle4);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(eSAMPLEBUTTON2, StartX + 70, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 210);

	if (gInterface.IsWorkZone(eSAMPLEBUTTON2))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eSAMPLEBUTTON2, gInterface.Data[eSAMPLEBUTTON2].X, gInterface.Data[eSAMPLEBUTTON2].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(eSAMPLEBUTTON, StartX + 530, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 210);

	if (gInterface.IsWorkZone(eSAMPLEBUTTON))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eSAMPLEBUTTON, gInterface.Data[eSAMPLEBUTTON].X, gInterface.Data[eSAMPLEBUTTON].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_MUA_VIP_CLOSE, StartX + 532, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 52);
	if (gInterface.IsWorkZone(EXBEXO_MUA_VIP_CLOSE))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(EXBEXO_MUA_VIP_CLOSE, gInterface.Data[EXBEXO_MUA_VIP_CLOSE].X, gInterface.Data[EXBEXO_MUA_VIP_CLOSE].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (Coin1 >= 5000)
	{
		RenderBitmap(0x0897, StartX + 197, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 109, 50, 14, 0, 0, 1, 1, 1, 1, 0.0);
	}
	if (Coin1 >= 10000)
	{
		RenderBitmap(0x0897, StartX + 245, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 109, 50, 14, 0, 0, 1, 1, 1, 1, 0.0);
	}
	if (Coin1 >= 20000)
	{
		RenderBitmap(0x0897, StartX + 293, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 109, 50, 14, 0, 0, 1, 1, 1, 1, 0.0);
	}
	if (Coin1 >= 30000)
	{
		RenderBitmap(0x0897, StartX + 341, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 109, 20, 14, 0, 0, 1, 1, 1, 1, 0.0);
	}
	if (Coin1 >= 40000)
	{
		RenderBitmap(0x0897, StartX + 359, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 109, 20, 14, 0, 0, 1, 1, 1, 1, 0.0);
	}
	if (Coin1 >= 50000)
	{
		RenderBitmap(0x0897, StartX + 377, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 109, 23, 14, 0, 0, 1, 1, 1, 1, 0.0);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eRed, StartX + 270, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 108, 210, 1, Config.TextVN_MuaVip[5], Coin1);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	switch (TRANG_MUA_VIP) //====================================================================================================================================
	{
		//=============================================================================================================================================================	
	case 1:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gRecvGS.m_RankTitle4 >= 1)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gRecvGS.m_RankTitle4 >= 2)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gRecvGS.m_RankTitle4 >= 3)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gRecvGS.m_RankTitle4 >= 4)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(ImgTagExMuaVip1, StartX + 100, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 165, 100, 30, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(ImgTagExMuaVip2, StartX + 210, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 165, 100, 30, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(ImgTagExMuaVip3, StartX + 325, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 165, 100, 30, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(ImgTagExMuaVip4, StartX + 435, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 165, 100, 30, 0, 0, 1, 1, 1, 1, 0.0);

		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 210, 210, 1, Config.TextVN_MuaVip[6]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 230, 210, 1, Config.TextVN_MuaVip[7]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 250, 210, 1, Config.TextVN_MuaVip[8]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 270, 210, 1, Config.TextVN_MuaVip[9]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 290, 210, 1, Config.TextVN_MuaVip[10]);

		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 210, 210, 1, Config.TextVN_MuaVip[11]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 230, 210, 1, Config.TextVN_MuaVip[12]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 250, 210, 1, Config.TextVN_MuaVip[13]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 270, 210, 1, Config.TextVN_MuaVip[14]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 290, 210, 1, Config.TextVN_MuaVip[15]);

		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 210, 210, 1, Config.TextVN_MuaVip[16]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 230, 210, 1, Config.TextVN_MuaVip[17]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 250, 210, 1, Config.TextVN_MuaVip[18]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 270, 210, 1, Config.TextVN_MuaVip[19]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 290, 210, 1, Config.TextVN_MuaVip[20]);

		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 210, 210, 1, Config.TextVN_MuaVip[21]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 230, 210, 1, Config.TextVN_MuaVip[22]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 250, 210, 1, Config.TextVN_MuaVip[23]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 270, 210, 1, Config.TextVN_MuaVip[24]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_MUA_VIP_MAIN].Y + 290, 210, 1, Config.TextVN_MuaVip[25]);

		//=============================================================================================================================================================	

		//=============================================================================================================================================================	
		break;
	default:
		break;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_MUA_VIP::MAIN_MUA_VIP(DWORD Event)
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	DWORD CurrentTick = GetTickCount();
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	this->CLOSE_MUA_VIP(Event);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	// TRANG 1
	if (gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow && gInterface.IsWorkZone(EXBEXO_MUA_VIP_NANG_CAP))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_MUA_VIP_NANG_CAP].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[EXBEXO_MUA_VIP_NANG_CAP].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[EXBEXO_MUA_VIP_NANG_CAP].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[EXBEXO_MUA_VIP_NANG_CAP].EventTick = GetTickCount();
		gBUY_TINH_NANG.BUY_MUA_VIP(1);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_MUA_VIP::CLOSE_MUA_VIP(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_MUA_VIP_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow || !gInterface.IsWorkZone(EXBEXO_MUA_VIP_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[EXBEXO_MUA_VIP_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[EXBEXO_MUA_VIP_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[EXBEXO_MUA_VIP_CLOSE].EventTick = GetTickCount();
	G_BEXO_MUA_VIP.CLOSE_WINDOW_MUA_VIP();
	// ----
	return false;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
