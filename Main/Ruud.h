#pragma once
#include "Interface.h"
// ---------------------------------------------------------------------------------------------
#define LoadBitmapA			((int(__cdecl*)(char * Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6)) 0x00772330)
#define PlayBuffer			((signed int(__cdecl*)(int a1, int a2, int a3)) 0x006D6C20)

struct ListItem
{
	/*void * Item;*/
	int ItemIndex;
	int Value;
	char * name;
	char * Descripcion;
};

struct Button
{
	int id;
	int x;
	int y;
	int w;
	int h;
	bool OnClick;
	DWORD EventTick;
};

struct WCursor
{
	float x;
	float y;
};

struct RuudWindows
{
/*+1*/		bool Open;
/*+2*/		DWORD Move;
/*+3*/		WCursor Cursor;
/*+4*/		DWORD DrawImg;
/*+24*/		float x;
/*+36*/		float y;
/*+44*/		float w;
/*+46*/		float h;
/*+146*/	int SteepPage;
/*+226*/	Button BtnClose;
/*+228*/	Button BtnSteep1;
/*+230*/	Button BtnSteep2;
/*+260*/	Button BtnBuy;
};

class CRuudShop
{
public:
	int Index;
	void LoadWindows();
	void OpenWindows();
	void CloseWindows();
	void MoveWindows(RuudWindows * windows, float x, float y);
	void CheckCursor();
	void RuudShop();
	void RuudShopEventButton(DWORD Event);
	void DrawModel(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
	// ----
public:
	RuudWindows RuudRender;
};
extern CRuudShop gCRuudShop;
// ---------------------------------------------------------------------------------------------