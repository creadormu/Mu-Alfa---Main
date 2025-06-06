#include "stdafx.h"
#include "Ruud.h"
#include "Util.h"
#include "Offset.h"
#include "Import.h"
#include "User.h"
#include "Interface.h"
#include "Defines.h"

CRuudShop gCRuudShop;

void pDrawButtonInfo(Button * Btn, DWORD ModelImg, float x, float y, float w, float h)
{
	Btn->id = 61529;
	Btn->x = x;
	Btn->y = y;
	Btn->w = w;
	Btn->h = h;
}

void CRuudShop::LoadWindows()
{
	this->RuudRender.Open = false;
	this->RuudRender.DrawImg = 61530;
	this->RuudRender.x = 0;
	this->RuudRender.y = 0;
	this->RuudRender.w = 190;
	this->RuudRender.h = 422;
	this->RuudRender.SteepPage = 0;
	Index = 1;
	pDrawButtonInfo(&this->RuudRender.BtnClose, 61529, this->RuudRender.x + 160, this->RuudRender.y + 27, 11, 12);


	/*pDrawButtonInfo(&gCRuudShop.RuudRender.BtnClose, 61529,gCRuudShop.RuudRender.x + 160, gCRuudShop.RuudRender.y + 27,11,12);
	pDrawButtonInfo(&gCRuudShop.RuudRender.BtnClose, 61529,gCRuudShop.RuudRender.x + 160, gCRuudShop.RuudRender.y + 27,11,12);*/
	
}

void CRuudShop::MoveWindows(RuudWindows * windows, float x, float y)
{
	if(windows->Open)
	{
		if (windows->Move == 1 &&
			((double)*(DWORD*)0x879340C >= windows->x && (double)*(DWORD*)0x879340C <= windows->x + windows->w)
			&& ((double)*(DWORD*)0x8793410 >= windows->y + 10 && (double)*(DWORD*)0x8793410 <= windows->y + 60) )
		{
			if( x >= 0 && (x + windows->w) <= 640)
			{
				windows->x = x;
			}
			if( y >= 0 && y <= 480 - windows->h )
			{
				windows->y = y;
			}
		}
		else
		{
			windows->Move = 0;
		}
	}
	else
	{
		windows->Move = 0;
	}
}

void CRuudShop::CloseWindows()
{
	PMSG_SHOPRUUD_SEND pMsg;

	pMsg.h.set (0xEE, sizeof(pMsg) );

	DataSend((BYTE*)&pMsg, pMsg.h.size);

	this->RuudRender.Open = false;

	pCloseWindow(pWindowThis(), 13);
}

void CRuudShop::OpenWindows()
{
	this->RuudRender.Open = true;
	
	pDrawGUI(this->RuudRender.DrawImg,this->RuudRender.x,this->RuudRender.y,this->RuudRender.w,this->RuudRender.h);
	pDrawButtonInfo(&this->RuudRender.BtnClose, 61529, this->RuudRender.x + 160, this->RuudRender.y + 27, 11, 12);

	pDrawGUI(this->RuudRender.BtnClose.id,this->RuudRender.BtnClose.x,this->RuudRender.BtnClose.y,this->RuudRender.BtnClose.w,this->RuudRender.BtnClose.h);
	
	if(pCheckMouseOver(this->RuudRender.BtnClose.x, this->RuudRender.BtnClose.y,  this->RuudRender.BtnClose.w,  this->RuudRender.BtnClose.h) == 1)
	{
		pDrawToolTip(this->RuudRender.BtnClose.x, this->RuudRender.BtnClose.y - 20, "Cerrar");
	}

	pDrawColorText("Ruud Shop - Priest James", this->RuudRender.x, this->RuudRender.y + 27, 190, 0, eGold, 0, 3 );

	pDrawColorText("You can use Ruud to purchase Sealed", this->RuudRender.x + 17, this->RuudRender.y + 57, 175, 0, eWhite, 0, 1 );
	pDrawColorText("Mastery Set Items.", this->RuudRender.x + 17, this->RuudRender.y + 67, 175, 0, eWhite, 0, 1 );
	pDrawColorText("You cand unseal Sealed Sets", this->RuudRender.x + 17, this->RuudRender.y + 77, 175, 0, eWhite, 0, 1 );
	pDrawColorText("by Combining.", this->RuudRender.x + 17, this->RuudRender.y + 87, 175, 0, eWhite, 0, 1 );

	int RenderX;
	int RenderY;
	char indexado[10];

	for(int i = 0 ; i < 4 ; i++)
	{
		RenderX = this->RuudRender.x + (190 / 2) - (160 / 2);
		RenderY = this->RuudRender.y  + 120 + (i * 60);
		pDrawGUI(61531, RenderX, RenderY, 160, 51);

		pDrawColorText("Bloodangel", RenderX + 55, RenderY + 5, 60, 0, eGold, 0, 3 );

		pDrawColorText("Bloodangel Helm of Sealed Transformation", RenderX + 55, RenderY + 24, 100, 0, eWhite, 0, 1 );

		pDrawColorText("500", RenderX + 105, RenderY + 37, 48, 0, eShinyGreen, 0, 4 );
	}

	/*for(int i = 0 ; i < 4 ; i++)
	{
		RenderX = this->RuudRender.x + (190 / 2) - (160 / 2);
		RenderY = this->RuudRender.y  + 120 + (i * 60);
		this->DrawModel(RenderX + 10, RenderY + 15, 30, 30, ITEM((i+8), 98), 0, 1, 0, 0);
	}
	*/
	RenderX = this->RuudRender.x + (190 / 2);
	wsprintf(indexado,"%d / %d",Index, 4);
	pDrawColorText(indexado, RenderX - 10, this->RuudRender.y + this->RuudRender.h - 33, 20, 0, eGold, 0, 3 );
}

void CRuudShop::RuudShop()
{
	if(!this->RuudRender.Open)
	{
		return;
	}

	if(this->RuudRender.BtnClose.OnClick == true)
	{
		this->CloseWindows();
		return;
	}

	
	this->OpenWindows();

	if(!pCheckWindow(pWindowThis(), 13))
	{
		this->CloseWindows();
		return;
	}
}

void CRuudShop::RuudShopEventButton(DWORD Event)
{	
	DWORD CurrentTick = GetTickCount();
//
	if( pCheckMouseOver(this->RuudRender.BtnClose.x, this->RuudRender.BtnClose.y,  this->RuudRender.BtnClose.w,  this->RuudRender.BtnClose.h) == 1 )
	{
		DWORD Delay	= (CurrentTick - this->RuudRender.BtnClose.EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			this->RuudRender.BtnClose.OnClick = true;
			return;
		}
		// ----
		this->RuudRender.BtnClose.OnClick = false;
		// ----
		if( Delay < 1000 )
		{
			return;
		}
		// ----
		this->RuudRender.BtnClose.EventTick = GetTickCount();
		// ----
	}
}

void CRuudShop::CheckCursor()
{
	if( this->RuudRender.Open && pCheckMouseOver(this->RuudRender.x, this->RuudRender.y,  this->RuudRender.w,  this->RuudRender.h) == 1)
	{
		pSetCursorFocus = true;
	}
	else
	{
		pSetCursorFocus = false;
	}
}

void CRuudShop::DrawModel(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse) // code hien thi item
{
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	sub_6363D0_Addr( 0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y );
	float v2 = *(float*) MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;

	sub_6358A0_Addr( 1.0, v2, *(float*)0xE61E38, *(float*)0xE61E3C );
	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();
	sub_635830_Addr((LPVOID) 0x87933A0);
	sub_635DE0_Addr();
	sub_635E40_Addr();
	pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, Excl, Anc, OnMouse); 
	glMatrixMode(0x1700u);
	glPopMatrix();
	glMatrixMode(0x1701u);
	glPopMatrix();
	glColor4f((GLfloat) 1.0, (GLfloat) 1.0, (GLfloat) 1.0,(GLfloat) 1.0);
	pSetBlend(false);
	//glClearColor((GLfloat) 1.0, (GLfloat) 1.0, (GLfloat) 1.0, (GLfloat) 1.0);
	//glEnable(GL_DEPTH_TEST);
}