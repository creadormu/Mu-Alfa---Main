#pragma once
#include "Import.h"
#include "Interface.h"
#include "Protocol.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
class BEXO_MUA_VIP
{
public:
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	BEXO_MUA_VIP();
	void DRAW_MUA_VIP();
	bool HIENTHIMUA_VIP;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	int TRANG_MUA_VIP;
	void BEXO_CLICK_TRANG_MUA_VIP(DWORD ClickMouse);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainWidth;
	float MainHeight;
	float StartY;
	float StartX;
	DWORD ClickTick;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	void		OPEN_WINDOW_MUA_VIP() { gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CLOSE_WINDOW_MUA_VIP() { gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CHECK_WINDOW_MUA_VIP() { return gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow; };

	void		DRAW_WINDOW_MUA_VIP();

	bool		MAIN_MUA_VIP(DWORD Event);
	bool		CLOSE_MUA_VIP(DWORD Event);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}; extern BEXO_MUA_VIP G_BEXO_MUA_VIP;
//===================================================================================================================================================================

