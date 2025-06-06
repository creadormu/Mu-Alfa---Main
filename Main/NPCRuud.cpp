#include "stdafx.h"
#include "NPCRuud.h"
#include "Import.h"
#include "Object.h"
#include "Offset.h"
#include "Util.h"
#include "WindowsStruct.h"
#include "postInterface.h"
#include "Protocol.h"
#include "ItemInfoEx.h"
#include "mu_object_item_data.h"
#include "Central.h"
#include "Defines.h"

cRenderRuud jCRenderRuud;

cRenderRuud::cRenderRuud()
{
	this->OpeningRuud = false;
	this->OpenWindowConfirm = false;
	this->JCSlot = -1;
	this->JCPage = -1;
	this->Page = 1;
	this->ClearRuudInfo();
}

cRenderRuud::~cRenderRuud()
{
}

bool cRenderRuud::EventPressButton(int x, int y, int h, int w)
{
	if( pCheckMouseOver(x, y, w, h) )
	{
		if( CursorPress )
		{
			if (GetTickCount() >= this->TimerEvent + 200) 
			{
				this->TimerEvent = GetTickCount();
				return true;
			}
		}
	}
	return false;
}

void cRenderRuud::ClosedRuud()
{
	PMSG_NPC_TALK_SEND pMsg;
	pMsg.header.set(0x31,sizeof(pMsg));
	DataSend((BYTE*)&pMsg,sizeof(pMsg));
	this->JCSlot = -1;
	this->JCPage = -1;
	this->OpenWindowConfirm = false;
	if(pCheckWindow(pWindowThis(), 13))
	{
		pCloseWindow(pWindowThis(), 13);
	}
}

void cRenderRuud::InsertRuudInfo(_tagRuudTokenSell * lpInfo)
{
	this->m_RuudInfo[Enter].byItemType = lpInfo->byItemType;
	this->m_RuudInfo[Enter].wItemIndex = lpInfo->wItemIndex;
	this->m_RuudInfo[Enter].shPageShop = lpInfo->shPageShop;
	this->m_RuudInfo[Enter].wSlotIndex = lpInfo->wSlotIndex;
	this->m_RuudInfo[Enter].dwRuudCount = lpInfo->dwRuudCount;
	this->Enter++;
}

void cRenderRuud::ClearRuudInfo()
{
	for (int i = 0; i < MAX_RUUDTOKENSELL_INFO; i++)
	{
		this->m_RuudInfo[i].byItemType = -1;
		this->m_RuudInfo[i].wItemIndex = -1;
		this->m_RuudInfo[i].shPageShop = -1;
		this->m_RuudInfo[i].wSlotIndex = -1;
		this->m_RuudInfo[i].dwRuudCount = -1;
	}
	this->Page = 1;
	this->Enter = 0;
}

void cRenderRuud::LoadRuudShop_Recv(PMSG_ITEMRUUD_LIST_RECV * lpMsg)
{
	this->ClearRuudInfo();

	for (int n = 0; n < lpMsg->count; n++)
	{
		_tagRuudTokenSell* lpInfo = (_tagRuudTokenSell*)(((BYTE*)lpMsg) + sizeof(PMSG_ITEMRUUD_LIST_RECV) + (sizeof(_tagRuudTokenSell)*n));
		
		this->InsertRuudInfo(lpInfo);
	}
}

void cRenderRuud::WindowConfirm(int Page, int Slot)
{
	if ( this->OpenWindowConfirm && Page != -1 && Slot != -1 )
	{
		gCentral.PrintDropBox(205, 100, 230, 150, 0, 0);

		_tagRuudTokenSell * JCLoadInfo = this->JCGetInfoRuud(Page, Slot);

		int ItemID = ITEM(JCLoadInfo->byItemType, JCLoadInfo->wItemIndex);

		gPostInterface.DrawItemIMG(205 + 90, 90, 50, 50, ItemID, 0, 0, 0, 0);
		pSetFont(pTextThis(), (int) pFontBold);
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		pDrawText(pTextThis(), 205, 175, "Mastery", 230, 0, (LPINT)3, 0);

		pDrawText(pTextThis(), 205, 190, (const char*)pGetItemAtt(ItemID, 0), 230, 0, (LPINT)3, 0);
		//-- 0.4359999299 push
		if(CheckButtonPressed(240, 219, Return2X( TransForX( 43 )), 17))
		{
			this->OpenWindowConfirm = false;
			this->JCSlot = -1;
			this->JCPage = -1;

			PMSG_BUY_ITEMRUUD_SEND pMsg;
			pMsg.header.set(0xEE,sizeof(pMsg));
			pMsg.PAGE = Page;
			pMsg.SLOT = Slot;
			DataSend((BYTE*)&pMsg,sizeof(pMsg));

			RenderBitmap(71521, TransFor2X( 240 ), TransForY( 219 ), TransForX( 43 ), TransForY( 17 ), 0.0013, 0.4359999299, 0.8805001974, 0.3845001459, 0, 0, 0);
		}
		else
		{
			RenderBitmap(71521,  TransFor2X( 240 ), TransForY( 219 ), TransForX( 43 ), TransForY( 17 ), 0.0013, 0.013, 0.8805001974, 0.3845001459, 0, 0, 0);
		}

		if(CheckButtonPressed(356, 219, Return2X( TransForX( 43 )), 17))
		{
			this->OpenWindowConfirm = false;
			this->JCSlot = -1;
			this->JCPage = -1;
			RenderBitmap(71521, TransFor2X( 356 ), TransForY( 219 ), TransForX( 43 ), TransForY( 17 ), 0.0013, 0.4359999299, 0.8805001974, 0.3845001459, 0, 0, 0);
		}
		else
		{
			RenderBitmap(71521, TransFor2X( 356 ), TransForY( 219 ), TransForX( 43 ), TransForY( 17 ), 0.0013, 0.013, 0.8805001974, 0.3845001459, 0, 0, 0);
		}
		//RenderBitmap(71521, 445, 270, TransForX( 43 ), TransForY( 17 ), 0.0013, 0.013, 0.8805001974, 0.3845001459, 0, 0, 0);
		pDrawText(pTextThis(), 240, 222, pGetTextLine(pTextLineThis, 228/*ok*/), Return2X( TransForX( 43 )), 0, (LPINT)3, 0);
		pDrawText(pTextThis(), 356, 222, pGetTextLine(pTextLineThis, 229/*Cancel*/), Return2X( TransForX( 43 )), 0, (LPINT)3, 0);
	}
}

_tagRuudTokenSell * cRenderRuud::JCGetInfoRuud(int Page, int Slot)
{
	for ( int SlectSlot = 0; SlectSlot < MAX_RUUDTOKENSELL_INFO; SlectSlot++ )
	{
		if(this->m_RuudInfo[SlectSlot].shPageShop == Page 
			&& this->m_RuudInfo[SlectSlot].wSlotIndex == Slot )
		{
			return &this->m_RuudInfo[SlectSlot];
		}
	}
	return 0;
}

void cRenderRuud::OpenRuud()
{
	if(this->OpeningRuud == false)
	{
		return;
	}
/*	if(this->OpenWindowConfirm == false)
	{
		return;
	}*/

	
//=====================================
	float x = 1; // ST08_4@1
	float y = 0; // ST04_4@1
	float v16; // ST34_4@1
	unsigned __int8 v17; // ST18_1@1
	unsigned __int8 v22; // ST18_1@1
	float v35; // [sp+338h] [bp-4h]@1
	float RuudY = 109.5;
	float RuudH = 55.0;

	int Width = TransForX( 190 );
	int Heigth = TransForY( 429 );

	RenderBitmap(61560, x, 0, Width, Heigth, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);

	v16 = *(float*)0x5EF5A1C * 0.001000000047497451;
	v35 = Convert(v16) + 1.0;
	v17 = (signed int)((2.0 - v35) * 127.0);

	pSetFont(pTextThis(), (int) pFontBold);
	//-- TitleName 1
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, v17);
	pDrawText(pTextThis(), x, y + 29, "NPC Ruud", Return2X( Width ), 0, (LPINT)3, 0);
	//-- TitleName 2
	v22 = (signed int)(v35 * 127.0);
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, v22);
	pDrawText(pTextThis(), x, y + 29, "Priest James", Return2X( Width ), 0, (LPINT)3, 0);

	pSetFont(pTextThis(), (int) pFontNormal);
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	pDrawText(pTextThis(), x + Return2X(TransForX( 15 )), y + 58, "You can use Ruud to purchase Selaed Mastery", Return2X( TransForX(166) ), 0, (LPINT)1, 0);
	pDrawText(pTextThis(), x + Return2X(TransForX( 15 )), y + 68, "Set Items.", Return2X( TransForX(166) ), 0, (LPINT)1, 0);
	pDrawText(pTextThis(), x + Return2X(TransForX( 15 )), y + 78, "You can unseal Sealed Sets by combining", Return2X( TransForX(166) ), 0, (LPINT)1, 0);
	pDrawText(pTextThis(), x + Return2X(TransForX( 15 )), y + 88, "Ancient Hero's souls via Chaos Goblin.", Return2X( TransForX(166) ), 0, (LPINT)1, 0);
	
	char Precio[50];
	int ItemID;

	for (int i = 0; i < 5 ; i++)
	{
		_tagRuudTokenSell * JCLoadInfo = this->JCGetInfoRuud(this->Page, i + 1);

		if( JCLoadInfo )
		{
			RenderBitmap(61561, x + TransForX( 10 ), TransForY( RuudY + 0.5f + ( RuudH * i )), TransForX( 166 ), TransForY( RuudH ), 0.0, 0.0, 0.5450001955, 0.6800000072, 0, 0, 0);
			pSetFont(pTextThis(), (int) pFontNormal);

			//-- evento comprar
			if( CheckButtonPressed( Return2X(x + TransForX( 135 )), RuudY + 5.0f + ( RuudH * i ), Return2X(TransForX(38)), 17) && !this->OpenWindowConfirm )
			{
				RenderBitmap(61542, Return2X(x + TransForX( 135 )), RuudY + 5.0f + ( RuudH * i ), Return2X(TransForX(38)), 17, 0.0, 0.268338412, 0.7135385275, 0.2283384204, 1, 1, 0);
				this->OpenWindowConfirm = true;
				this->JCSlot = i + 1;
				this->JCPage = this->Page;
			}
			else
			{
				RenderBitmap(61542, Return2X(x + TransForX( 135 )), RuudY + 5.0f + ( RuudH * i ), Return2X(TransForX(38)), 17, 0.0, 0.02, 0.7135385275, 0.2283384204, 1, 1, 0);
			}

			ItemID = ITEM(JCLoadInfo->byItemType, JCLoadInfo->wItemIndex);
			//-- Titulo del Item
			pSetTextColor(pTextThis(), 0xE6u, 0xE6u, 0, 0xFFu);
			pDrawText(pTextThis(), x + Return2X(TransForX( 65 )) , RuudY + 8.0f + ( RuudH * i ), "Mastery", Return2X(TransForX( 70 )), 0, (LPINT)3, 0);
			//-- Nombre del Item
			pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
			pDrawText(pTextThis(), x + Return2X(TransForX( 68 )), RuudY + 28 + ( RuudH * i ), (const char*)pGetItemAtt(ItemID, 0), Return2X( TransForX(105) ), 0, (LPINT)1, 0);
			//-- Precio del Item
			//pGetMoneyFormat(JCLoadInfo->dwRuudCount, Precio, 0);
			wsprintf(Precio, "%d",JCLoadInfo->dwRuudCount);
			pDrawText(pTextThis(), x + Return2X(TransForX( 90 )), RuudY + 43 + ( RuudH * i ), Precio, Return2X(TransForX( 100 )), 0, (LPINT)3, 0);
			//-- Buy
			pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
			pDrawText(pTextThis(), x + Return2X(TransForX( 135 )), RuudY + 8.0f + ( RuudH * i ), pGetTextLine(pTextLineThis, 1124/*Buy*/), Return2X(TransForX(38)), 0, (LPINT)3, 0);
		}
	}
	this->WindowConfirm( this->JCPage, this->JCSlot );

//-- Imprime Item
	/*EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);*/
	for ( int i = 0; i < 5 ; i++)
	{
		_tagRuudTokenSell * JCLoadInfo = this->JCGetInfoRuud(this->Page, i + 1);
		if( JCLoadInfo )
		{
			ItemID = ITEM(JCLoadInfo->byItemType, JCLoadInfo->wItemIndex);
			gPostInterface.DrawItemIMG(x + Return2X(TransForX( 10 )), 84 + 0.5f + ( RuudH * i ), Return2X(TransForX( 50 )), 50, ItemID, 0, 0, 0, 0);
		}
	}
//-- Solo 1 lista 0.4549999833
	if( EventPressButton( x + Return2X(TransForX(65)), y + 400, Return2X(TransForX(10)), 10) && !this->OpenWindowConfirm)
	{
		if( this->Page > 1 ) { this->Page--; }
		RenderBitmap(61562, x + TransForX( 65 ), y + TransForY( 400 ), TransForX( 10 ), TransForY( 10 ), 0.02999999747, ( this->Page == 1 ) ?0.4549999833 : 0.3069999814, 0.2610003054, 0.1405000836, 0, 0, 0);
	}
	else
	{
		RenderBitmap(61562, x + TransForX( 65 ), y + TransForY( 400 ), TransForX( 10 ), TransForY( 10 ), 0.02999999747, ( this->Page == 1 ) ?0.4549999833 : 0.00800000038, 0.2610003054, 0.1405000836, 0, 0, 0);
	}

	if( EventPressButton( x + Return2X(TransForX(115)), y + 400, Return2X(TransForX(10)), 10) && !this->OpenWindowConfirm)
	{
		if( this->Page < 5 ) { this->Page++; }
		RenderBitmap(61562, x + TransForX( 115 ), y + TransForY( 400 ), TransForX( 10 ), TransForY( 10 ), 0.319999963, ( this->Page == 5 ) ? 0.4549999833 : 0.3069999814, 0.2610003054, 0.1405000836, 0, 0, 0);
	}
	else
	{
		RenderBitmap(61562, x + TransForX( 115 ), y + TransForY( 400 ), TransForX( 10 ), TransForY( 10 ), 0.319999963, ( this->Page == 5 ) ? 0.4549999833 : 0.00800000038, 0.2610003054, 0.1405000836, 0, 0, 0);
	}
	char nPage[10];
	ZeroMemory(nPage,sizeof(nPage));
	wsprintf(nPage, pGetTextLine(pTextLineThis, 1181), this->Page, 5);
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	pSetFont(pTextThis(), (int) pFontNormal);
	pDrawText(pTextThis(), x + Return2X(TransForX( 85 )),  y + 400, nPage, Return2X(TransForX(20)), 0, (LPINT)3, 0);

	/*pGLSwitch();
	EnableAlphaTest(0);*/
}

void cRenderRuud::CheckOpen()
{
	if( this->OpeningRuud )
	{
		if( !pCheckWindow(pWindowThis(), 13) )
		{
			this->OpeningRuud = false;
			this->ClosedRuud();
		}

		if( this->OpeningRuud &&
			(this->Coordenada[1] != pGetUserCoorX
			|| this->Coordenada[2] != pGetUserCoorY
			|| this->Coordenada[0] != pMapNumber))
		{
			this->OpeningRuud = false;
			this->ClosedRuud();
		}
	}
	else
	{
		this->Coordenada[0] = pMapNumber;
		this->Coordenada[1] = pGetUserCoorX;
		this->Coordenada[2] = pGetUserCoorY;
	}
}

void cRenderRuud::OpenRuudShop_Recv(PMSG_NPC_TALK_RECV * lpMsg)
{
	if(lpMsg->result == 100)
	{
		this->OpeningRuud = true;

		if(!pCheckWindow(pWindowThis(), 13))
		{
			pOpenWindow(pWindowThis(), 13);
		}
	}
}