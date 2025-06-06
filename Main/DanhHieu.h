#pragma once
#include "Import.h"
#include "Interface.h"
#include "Protocol.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
class BEXO_DANH_HIEU
{
public:
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	BEXO_DANH_HIEU();
	void DRAW_DANH_HIEU();
	bool HIENTHIDANH_HIEU;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	int TRANG_DANH_HIEU;
	void BEXO_CLICK_TRANG_DANH_HIEU(DWORD ClickMouse);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainWidth;
	float MainHeight;
	float StartY;
	float StartX;
	DWORD ClickTick;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	void		OPEN_WINDOW_DANH_HIEU() { gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CLOSE_WINDOW_DANH_HIEU() { gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CHECK_WINDOW_DANH_HIEU() { return gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow; };

	void		DRAW_WINDOW_DANH_HIEU();

	bool		MAIN_DANH_HIEU(DWORD Event);
	bool		CLOSE_DANH_HIEU(DWORD Event);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}; extern BEXO_DANH_HIEU G_BEXO_DANH_HIEU;
//===================================================================================================================================================================

