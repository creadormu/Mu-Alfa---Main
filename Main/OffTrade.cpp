#include "stdafx.h"
#include "Defines.h"
#include "Import.h"
#include "Interface.h"
#include "OffTrade.h"
#include "Offset.h"
#include "Protect.h"
#include "Util.h"
#include "CustomMessage.h"
#include "WindowsStruct.h"


cOffTrade gOffTrade;

cOffTrade::cOffTrade()
{
	this->ShopActive	= 0;
	this->TypeShop		= 0;
	this->Init();
}

cOffTrade::~cOffTrade()
{
	
}

#define sub_841E10	((int(__thiscall*)(int a1)) 0x00841E10)

void InterfaceOfftrade(DWORD id, float x, float y, float w, float h)
{
	pDrawGUI(id, x, y, w, h);

	gOffTrade.DrawOffTradeWindow(x, y);
}

void cOffTrade::Init()
{
	if( gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 4 )
	{
		SetCompleteHook(0xE8, 0x00841E49, &InterfaceOfftrade);
	}

	SetCompleteHook(0xFF, 0x007E4641, &this->ShowPrice);

	SetCompleteHook(0xFF, 0x007E4753, &this->ShowTwoString);

	SetCompleteHook(0xE9, 0x007E46A0, &ChangePSValueColor);
}

void cOffTrade::DrawOffTradeWindowEx700(float x, float y)
{
	int ObjectIDs[6] = { eOFFTRADE_JoB, eOFFTRADE_JoS, eOFFTRADE_JoC, eOFFTRADE_WCC, eOFFTRADE_WCP, eOFFTRADE_WCG };

	if (gOffTrade.ShopActive != 0)
	{
		gInterface.Data[eSTORE_CLOSE].OnShow = false;
		gInterface.Data[eOFFTRADE_OPEN].OnShow = false;
		gInterface.Data[eOFFTRADE_JoB].OnShow = false;
		gInterface.Data[eOFFTRADE_JoS].OnShow = false;
		gInterface.Data[eOFFTRADE_JoC].OnShow = false;
		gInterface.Data[eOFFTRADE_WCC].OnShow = false;
		gInterface.Data[eOFFTRADE_WCP].OnShow = false;
		gInterface.Data[eOFFTRADE_WCG].OnShow = false;

		if (gProtect.m_MainInfo.CustomOffStoreEnable)
		{
			gInterface.Data[eSTORE_CLOSE].OnShow = true;
			gInterface.Data[eSTORE_CLOSE].Width = Return2X(TransForX(108));
			gInterface.DrawButtonRender(eSTORE_CLOSE, Return2X(x + TransForX(40)), y + 310, 0, 0);

			if (pCheckMouseOver(Return2X(x + TransForX(40)), y + 310, Return2X(TransForX(108)), 30))
			{
				if (*(BYTE*)0x8793386)
				{
					//-- Push 0.4680666625
					RenderBitmap(0x7BFD, Return2X(x + TransForX(40)), y + 310, Return2X(TransForX(108)), 30, 0.0, 0.4680666625, 0.8499999642, 0.2270333171, 1, 1, 0.0);
				}
				else
				{
					//-- Over 0.7010999322
					RenderBitmap(0x7BFD, Return2X(x + TransForX(40)), y + 310, Return2X(TransForX(108)), 30, 0.0, 0.7010999322, 0.8499999642, 0.2270333171, 1, 1, 0.0);
				}
			}
			else
			{
				RenderBitmap(0x7BFD, Return2X(x + TransForX(40)), y + 310, Return2X(TransForX(108)), 30, 0.0, 0.0, 0.8499999642, 0.2270333171, 1, 1, 0.0);
			}

			//--
			gInterface.Data[eOFFTRADE_OPEN].OnShow = true;
			gInterface.Data[eOFFTRADE_OPEN].Width = Return2X(TransForX(108));
			gInterface.DrawButtonRender(eOFFTRADE_OPEN, Return2X(x + TransForX(40)), y + 270, 0, 0);

			if (pCheckMouseOver(Return2X(x + TransForX(40)), y + 270, Return2X(TransForX(108)), 30))
			{
				if (*(BYTE*)0x8793386)
				{
					//-- Push 0.4680666625
					RenderBitmap(0x7BFD, Return2X(x + TransForX(40)), y + 270, Return2X(TransForX(108)), 30, 0.0, 0.4680666625, 0.8499999642, 0.2270333171, 1, 1, 0.0);
				}
				else
				{
					//-- Over 0.7010999322
					RenderBitmap(0x7BFD, Return2X(x + TransForX(40)), y + 270, Return2X(TransForX(108)), 30, 0.0, 0.7010999322, 0.8499999642, 0.2270333171, 1, 1, 0.0);
				}
			}
			else
			{
				RenderBitmap(0x7BFD, Return2X(x + TransForX(40)), y + 270, Return2X(TransForX(108)), 30, 0.0, 0.0, 0.8499999642, 0.2270333171, 1, 1, 0.0);
			}
			//--
			gInterface.DrawFormat(eYellow, Return2X(x + TransForX(40)), y + 320, Return2X(TransForX(108)), 3, "Closed Store");
			gInterface.DrawFormat(eYellow, Return2X(x + TransForX(40)), y + 280, Return2X(TransForX(108)), 3, "OFF STORE");
		}
		else
		{
			gInterface.Data[eSTORE_CLOSE].OnShow = true;
			gInterface.Data[eSTORE_CLOSE].Width = Return2X(TransForX(108));
			gInterface.DrawButtonRender(eSTORE_CLOSE, Return2X(x + TransForX(40)), y + 310, 0, 0);

			if (pCheckMouseOver(Return2X(x + TransForX(40)), y + 310, Return2X(TransForX(108)), 30))
			{
				if (*(BYTE*)0x8793386)
				{
					//-- Push 0.4680666625
					RenderBitmap(0x7BFD, Return2X(x + TransForX(40)), y + 310, Return2X(TransForX(108)), 30, 0.0, 0.4680666625, 0.8499999642, 0.2270333171, 1, 1, 0.0);
				}
				else
				{
					//-- Over 0.7010999322
					RenderBitmap(0x7BFD, Return2X(x + TransForX(40)), y + 310, Return2X(TransForX(108)), 30, 0.0, 0.7010999322, 0.8499999642, 0.2270333171, 1, 1, 0.0);
				}
			}
			else
			{
				RenderBitmap(0x7BFD, Return2X(x + TransForX(40)), y + 310, Return2X(TransForX(108)), 30, 0.0, 0.0, 0.8499999642, 0.2270333171, 1, 1, 0.0);
			}
			gInterface.DrawFormat(eYellow, Return2X(x + TransForX(40)), y + 320, Return2X(TransForX(108)), 3, "Closed Store");
		}
		return;
	}

	char * ButtonText[6] = { "Bless", "Soul", "Chaos", gCustomMessage.GetMessage(58), gCustomMessage.GetMessage(59), gCustomMessage.GetMessage(60) };

	int ButtonEnabled[6] = { gProtect.m_MainInfo.CustomStoreEnableJoB, gProtect.m_MainInfo.CustomStoreEnableJoS,
		gProtect.m_MainInfo.CustomStoreEnableJoC, gProtect.m_MainInfo.CustomStoreEnableCoin1,
		gProtect.m_MainInfo.CustomStoreEnableCoin2, gProtect.m_MainInfo.CustomStoreEnableCoin3 };


	float XButton;
	float YButton = 341;

	for (int k = 0; k < 2; k++)
	{
		XButton = x + TransForX(20);

		for (int j = 0; j < 3; j++)
		{
			DWORD Color = eWhite;

			gInterface.Data[ObjectIDs[j + 3 * k]].OnShow = true;
			gInterface.Data[ObjectIDs[j + 3 * k]].Width = Return2X(TransForX(40));

			if (!ButtonEnabled[j + 3 * k])
			{
				gInterface.Data[ObjectIDs[j + 3 * k]].OnShow = false;
				continue;
			}

			gInterface.DrawButtonRender(ObjectIDs[j + 3 * k], Return2X(XButton), YButton, 0.0, 0.0);

			if (pCheckMouseOver(Return2X(XButton), YButton, Return2X(TransForX(40)), 17))
			{
				Color = pMakeColor(220, 220, 220, 220);
			}
			RenderBitMapColored(0x7908, Return2X(XButton), YButton, Return2X(TransForX(40)), 17, 0.0, 0.0, 0.6235385537, 0.6235385537, Color);
			//	RenderBitmap(0x7908, Return2X(XButton), YButton, Return2X(TransForX( 40 )), 17, 0.0, 0.0, 0.6235385537, 0.6235385537, 1, 1, 0);

			pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
			pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
			pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);

			pDrawText(pTextThis(), Return2X(XButton), YButton + 3, ButtonText[j + 3 * k], Return2X(TransForX(40)), 0, (LPINT)3, 0);

			XButton += TransForX(56);
		}

		YButton += 21;
	}
}

int cOffTrade::DrawOffTradeWindow(float v6, float v5)
{
	gInterface.Data[eSTORE_CLOSE].OnShow = false;
	gInterface.Data[eOFFTRADE_OPEN].OnShow = false;
	gInterface.Data[eOFFTRADE_JoB].OnShow = false;
	gInterface.Data[eOFFTRADE_JoS].OnShow = false;
	gInterface.Data[eOFFTRADE_JoC].OnShow = false;
	gInterface.Data[eOFFTRADE_WCC].OnShow = false;
	gInterface.Data[eOFFTRADE_WCP].OnShow = false;
	gInterface.Data[eOFFTRADE_WCG].OnShow = false;

	if (gOffTrade.ShopActive != 0)
	{
		if (gProtect.m_MainInfo.CustomOffStoreEnable)
		{
			if (gInterface.IsWorkZone(eSTORE_CLOSE))
			{
				if (gInterface.Data[eSTORE_CLOSE].OnClick)
				{
					gInterface.DrawButtonRender(eSTORE_CLOSE, v6 + 40, 310, 0, 30);
					gInterface.DrawButtonRender(eOFFTRADE_OPEN, v6 + 40, 350, 0, 0);
				}
				else
				{
					gInterface.DrawButtonRender(eSTORE_CLOSE, v6 + 40, 310, 0, 90);
					gInterface.DrawButtonRender(eOFFTRADE_OPEN, v6 + 40, 350, 0, 0);
				}

				gInterface.DrawToolTip(v6 + 60, 300, "Close Custom-Store");
			}
			else if (gInterface.IsWorkZone(eOFFTRADE_OPEN))
			{
				if (gInterface.Data[eOFFTRADE_OPEN].OnClick)
				{
					gInterface.DrawButtonRender(eSTORE_CLOSE, v6 + 40, 310, 0, 0);
					gInterface.DrawButtonRender(eOFFTRADE_OPEN, v6 + 40, 350, 0, 30);
				}
				else
				{
					gInterface.DrawButtonRender(eSTORE_CLOSE, v6 + 40, 310, 0, 0);
					gInterface.DrawButtonRender(eOFFTRADE_OPEN, v6 + 40, 350, 0, 90);
				}

				gInterface.DrawToolTip(v6 + 60, 340, "Open Off-Store");
			}
			else
			{
				gInterface.DrawButtonRender(eSTORE_CLOSE, v6 + 40, 310, 0, 0);
				gInterface.DrawButtonRender(eOFFTRADE_OPEN, v6 + 40, 350, 0, 0);
			}
			gInterface.DrawFormat(eYellow, v6 + 40, 320, 108, 3, "Close STORE");

			gInterface.DrawFormat(eYellow, v6 + 40, 360, 108, 3, "OFF STORE");

			gInterface.Data[eSTORE_CLOSE].OnShow = true;

			gInterface.Data[eOFFTRADE_OPEN].OnShow = true;
		}
		else
		{
			if (gInterface.IsWorkZone(eSTORE_CLOSE))
			{
				if (gInterface.Data[eSTORE_CLOSE].OnClick)
				{
					gInterface.DrawButtonRender(eSTORE_CLOSE, v6 + 40, 330, 0, 30);
				}
				else
				{
					gInterface.DrawButtonRender(eSTORE_CLOSE, v6 + 40, 330, 0, 90);
				}
				gInterface.DrawToolTip(v6 + 60, 320, "Close Custom-Store");
			}
			else
			{
				gInterface.DrawButtonRender(eSTORE_CLOSE, v6 + 40, 330, 0, 0);
			}
			gInterface.DrawFormat(eYellow, v6 + 40, 340, 108, 3, "Close Store");

			gInterface.Data[eSTORE_CLOSE].OnShow = true;
		}
		return 1;
	}


	char* textID[6] =
	{
		"Bless",
		"Soul",
		"Chaos",
		gCustomMessage.GetMessage(58),
		gCustomMessage.GetMessage(59),
		gCustomMessage.GetMessage(60)
	};

	if (gProtect.m_MainInfo.CustomStoreEnableJoB)
	{
		gInterface.DrawButtonRender(eOFFTRADE_JoB, v6 + 20, 341, 0.0, 0.0);
		gInterface.DrawFormat(eWhite, gInterface.Data[eOFFTRADE_JoB].X + 1, gInterface.Data[eOFFTRADE_JoB].Y + 4, gInterface.Data[eOFFTRADE_JoB].Width, 3, textID[0]);
		gInterface.Data[eOFFTRADE_JoB].OnShow = true;
	}

	if (gProtect.m_MainInfo.CustomStoreEnableJoS)
	{
		gInterface.DrawButtonRender(eOFFTRADE_JoS, v6 + 76.5, 341, 0.0, 0.0);
		gInterface.DrawFormat(eWhite, gInterface.Data[eOFFTRADE_JoS].X + 1, gInterface.Data[eOFFTRADE_JoS].Y + 4, gInterface.Data[eOFFTRADE_JoS].Width, 3, textID[1]);
		gInterface.Data[eOFFTRADE_JoS].OnShow = true;
	}

	if (gProtect.m_MainInfo.CustomStoreEnableJoC)
	{
		gInterface.DrawButtonRender(eOFFTRADE_JoC, v6 + 133, 341, 0.0, 0.0);
		gInterface.DrawFormat(eWhite, gInterface.Data[eOFFTRADE_JoC].X + 1, gInterface.Data[eOFFTRADE_JoC].Y + 4, gInterface.Data[eOFFTRADE_JoC].Width, 3, textID[2]);
		gInterface.Data[eOFFTRADE_JoC].OnShow = true;
	}

	if (gProtect.m_MainInfo.CustomStoreEnableCoin1)
	{
		gInterface.DrawButtonRender(eOFFTRADE_WCC, v6 + 20, 362, 0.0, 0.0);
		gInterface.DrawFormat(eWhite, gInterface.Data[eOFFTRADE_WCC].X + 1, gInterface.Data[eOFFTRADE_WCC].Y + 4, gInterface.Data[eOFFTRADE_WCC].Width, 3, textID[3]);
		gInterface.Data[eOFFTRADE_WCC].OnShow = true;
	}

	if (gProtect.m_MainInfo.CustomStoreEnableCoin2)
	{
		gInterface.DrawButtonRender(eOFFTRADE_WCP, v6 + 76.5, 362, 0.0, 0.0);
		gInterface.DrawFormat(eWhite, gInterface.Data[eOFFTRADE_WCP].X + 1, gInterface.Data[eOFFTRADE_WCP].Y + 4, gInterface.Data[eOFFTRADE_WCP].Width, 3, textID[4]);
		gInterface.Data[eOFFTRADE_WCP].OnShow = true;
	}

	if (gProtect.m_MainInfo.CustomStoreEnableCoin3)
	{
		gInterface.DrawButtonRender(eOFFTRADE_WCG, v6 + 133, 362, 0.0, 0.0);
		gInterface.DrawFormat(eWhite, gInterface.Data[eOFFTRADE_WCG].X + 1, gInterface.Data[eOFFTRADE_WCG].Y + 4, gInterface.Data[eOFFTRADE_WCG].Width, 3, textID[5]);
		gInterface.Data[eOFFTRADE_WCG].OnShow = true;
	}

	int ObjectIDs[6] =
	{
		eOFFTRADE_JoB,
		eOFFTRADE_JoS,
		eOFFTRADE_JoC,
		eOFFTRADE_WCC,
		eOFFTRADE_WCP,
		eOFFTRADE_WCG
	};

	for (int i = 0; i<6; i++)
	{
		if (gInterface.IsWorkZone(ObjectIDs[i]) && gInterface.Data[ObjectIDs[i]].OnShow)
		{
			DWORD Color = eGray150;
			// ----
			if (gInterface.Data[ObjectIDs[i]].OnClick)
			{
				Color = eGray150;
			}
			// ----
			gInterface.DrawButtonRender(ObjectIDs[i], gInterface.Data[ObjectIDs[i]].X, gInterface.Data[ObjectIDs[i]].Y, 0.0, 0.0);
			gInterface.DrawColoredGUI(ObjectIDs[i], gInterface.Data[ObjectIDs[i]].X, gInterface.Data[ObjectIDs[i]].Y, Color);
			gInterface.DrawFormat(eWhite, gInterface.Data[ObjectIDs[i]].X + 1, gInterface.Data[ObjectIDs[i]].Y + 4, gInterface.Data[ObjectIDs[i]].Width, 3, textID[i]);
		}
	}
}

__declspec(naked) void ChangePSValueColor()
{
	static DWORD AdressFinal = 0x007E46AB;
	_asm
	{
		MOV DWORD PTR DS : [EAX * 4 + 0x81C0A68], 0x08 //cor
			//MOV DWORD PTR DS:[EAX*4+0x7B52C30],0x02 //borda
			//INC EAX
			JMP[AdressFinal]
	}
}

void cOffTrade::ShowPrice(DWORD a1, const char *a2, char *Price)
{
	if(gOffTrade.ShopActive != 0 || gOffTrade.ShopList != 0)
	{
		if(gOffTrade.TypeShop == 0)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(61),Price);
		}
		else if(gOffTrade.TypeShop == 1)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(62),Price);
		}
		else if(gOffTrade.TypeShop == 2)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(63),Price);
		}
		else if(gOffTrade.TypeShop == 3)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(55),Price);
		}
		else if(gOffTrade.TypeShop == 4)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(56),Price);
		}
		else if(gOffTrade.TypeShop == 5)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(57),Price); 
		}
		else
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(49),Price);
		}
	}
	else
	{
		pSetItemTextLine(a1,gCustomMessage.GetMessage(64),Price);
	}
}

void cOffTrade::ShowTwoString(DWORD a1, const char *a2)
{
	if(gOffTrade.TypeShop == 0)
	{
		pSetItemTextLine(a1,"\n");
	}
	else if(gOffTrade.TypeShop == 1)
	{
		pSetItemTextLine(a1,"\n");
	}
	else if(gOffTrade.TypeShop == 2)
	{
		pSetItemTextLine(a1,"\n");		
	}
	else if(gOffTrade.TypeShop == 3)
	{
		pSetItemTextLine(a1,"\n",gCustomMessage.GetMessage(58));
	}
	else if(gOffTrade.TypeShop == 4)
	{
		pSetItemTextLine(a1,"\n",gCustomMessage.GetMessage(59));
	}
	else if(gOffTrade.TypeShop == 5)
	{
		pSetItemTextLine(a1,"\n",gCustomMessage.GetMessage(60));
	}
	else
	{
		pSetItemTextLine(a1,"You are short of Zen");
	}
}

// ----------------------------------------------------------------------------------------------
bool cOffTrade::EventCloseTradeWindow_Main(DWORD Event)
{	
	DWORD CurrentTick	= GetTickCount();

	if (gInterface.CheckWindow(ObjWindow::Store) == false)
	{
		return false;
	}

	int ObjectIDs[6] = 
	{ 
		eOFFTRADE_JoB,
		eOFFTRADE_JoS,
		eOFFTRADE_JoC,
		eOFFTRADE_WCC,
		eOFFTRADE_WCP,
		eOFFTRADE_WCG
	};

	for (int i = 0; i<6; i++)
	{
		if (gInterface.IsWorkZone(ObjectIDs[i]) && gInterface.Data[ObjectIDs[i]].OnShow)
		{
			DWORD Delay			= (CurrentTick - gInterface.Data[ObjectIDs[i]].EventTick);

			if( Event == WM_LBUTTONDOWN )
			{
				gInterface.Data[ObjectIDs[i]].OnClick = true;
				return true;
			}
			// ----
			gInterface.Data[ObjectIDs[i]].OnClick = false;
			// ----
			if( Delay < 1000 )
			{
				return false;
			}
			// ----
			gInterface.Data[ObjectIDs[i]].EventTick = GetTickCount();

			CGSendOffTrade(i);
		}
	}

	if (gInterface.IsWorkZone(eSTORE_CLOSE))
	{
		if (!gInterface.Data[eSTORE_CLOSE].OnShow)
		{
			return false;
		}

		DWORD Delay			= (CurrentTick - gInterface.Data[eSTORE_CLOSE].EventTick);

		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[eSTORE_CLOSE].OnClick = true;
			return true;
		}
		// ----
		gInterface.Data[eSTORE_CLOSE].OnClick = false;
		// ----
		if( Delay < 1000 )
		{
			return false;
		}
		// ----
		gInterface.Data[eSTORE_CLOSE].EventTick = GetTickCount();
		CGSendOffTrade(7);
	}
	return false;
}

bool cOffTrade::EventOffTradeWindow_Main(DWORD Event)
{	
	DWORD CurrentTick	= GetTickCount();

	if (gInterface.CheckWindow(ObjWindow::Store) == false)
	{
		return false;
	}

	int ObjectIDs[6] = 
	{ 
		eOFFTRADE_JoB,
		eOFFTRADE_JoS,
		eOFFTRADE_JoC,
		eOFFTRADE_WCC,
		eOFFTRADE_WCP,
		eOFFTRADE_WCG
	};

	for (int i = 0; i<6; i++)
	{
		if (gInterface.IsWorkZone(ObjectIDs[i]) && gInterface.Data[ObjectIDs[i]].OnShow)
		{
			DWORD Delay			= (CurrentTick - gInterface.Data[ObjectIDs[i]].EventTick);

			if( Event == WM_LBUTTONDOWN )
			{
				gInterface.Data[ObjectIDs[i]].OnClick = true;
				return true;
			}
			// ----
			gInterface.Data[ObjectIDs[i]].OnClick = false;
			// ----
			if( Delay < 1000 )
			{
				return false;
			}
			// ----
			gInterface.Data[ObjectIDs[i]].EventTick = GetTickCount();

			CGSendOffTrade(i);
		}
	}

	if (gInterface.IsWorkZone(eOFFTRADE_OPEN))
	{
		if (!gInterface.Data[eOFFTRADE_OPEN].OnShow)
		{
			return false;
		}

		DWORD Delay			= (CurrentTick - gInterface.Data[eOFFTRADE_OPEN].EventTick);

		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[eOFFTRADE_OPEN].OnClick = true;
			return true;
		}
		// ----
		gInterface.Data[eOFFTRADE_OPEN].OnClick = false;
		// ----
		if( Delay < 1000 )
		{
			return false;
		}
		// ----
		gInterface.Data[eOFFTRADE_OPEN].EventTick = GetTickCount();
		CGSendOffTrade(6);
	}
	return false;
}
// ----------------------------------------------------------------------------------------------

void cOffTrade::CGSendOffTrade(int Type)
{
	PMSG_OFFTRADE_SEND pMsg;
	pMsg.header.set(0xF3, 0xEB, sizeof(pMsg));
	pMsg.Type = Type;
	DataSend((BYTE*)&pMsg,pMsg.header.size);
}

void cOffTrade::RecvPShop(PMSG_OFFTRADE_RECV *Data)
{
		this->ShopList		= 1;
		this->TypeShop		= Data->Type;
}

void cOffTrade::PShopActiveRecv(PMSG_SHOPACTIVE_RECV *Data)
{
		this->ShopActive	= Data->Active;
		this->TypeShop		= Data->Type;
}