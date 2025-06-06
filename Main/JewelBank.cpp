#include "stdafx.h"
#include "Interface.h"
#include "User.h"
#include "PrintPlayer.h"
#include "JewelBank.h"
#include "Defines.h"
#include "Protocol.h"
#include "Item.h"
#include "Protect.h"
#include "Central.h"

JewelsBank gJewelsBank;

JewelsBank::JewelsBank()
{	
	this->Moving = false;
	this->ultimoX = 205;
    this->ultimoY = 21;
}

JewelsBank::~JewelsBank()
{	
}

void JewelsBank::JewelsBankImageLoad()
{
	//pLoadImage("Custom\\Interface\\JewelsBank\\newui_gens_rankback.tga", 400000, 0x2601, 0x2901, 1, 0);
}

void JewelsBank::JewelsBankLoad()
{
	this->Active = false;

	this->Bind();
}

void JewelsBank::Bind()
{
	gInterface.BindObject(eJEWELBANK_MAIN, 0x7A5A, 222, 320, -1, -1);
	gInterface.BindObject(eJEWELBANK_TITLE, 0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(eJEWELBANK_FRAME, 0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_FOOTER, 0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(eJEWELBANK_POINT, 0x7B68, 10, 10, -1, -1);
	gInterface.BindObject(eJEWELBANK_LINE, 0x7B67, 154, 3, -1, -1);
	gInterface.BindObject(eJEWELBANK_DIV, 0x7A62, 223, 21, -1, -1);
	gInterface.BindObject(eJEWELBANK_CLOSE, 0x7EC5, 36, 29, -1, -1);

	//Sumar
	gInterface.BindObject(eJEWELBANK_PAGEUP1, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP2, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP3, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP4, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP5, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP6, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP7, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP8, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP9, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP10, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP11, 0x7AA4, 15, 15, -1, -1);
	//Restar
	gInterface.BindObject(eJEWELBANK_PAGEDN1, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN2, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN3, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN4, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN5, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN6, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN7, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN8, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN9, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN10, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN11, 0x7C0D, 15, 15, -1, -1);
}

void JewelsBank::DrawWindow(int ObjMain, int ObjTitle, int ObjFrame, int ObjFooter, int Repeat, float X, float Y, char* Text)
{
	float StartY = Y;
	float StartX = X;

	gInterface.DrawGUI(ObjMain, StartX, StartY + 2);
	gInterface.DrawGUI(ObjTitle, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(ObjFrame, StartX, StartY + 67.0, Repeat);
	gInterface.DrawGUI(ObjFooter, StartX, StartY);

	gInterface.DrawFormat(eGold, StartX + 10, Y + 10, 210, 3, Text);
}

bool JewelsBank::ButtonEx(DWORD Event, int ButtonID, bool Type)
{
	if (!gInterface.IsWorkZone(ButtonID))
	{
		return false;
	}

	if (Type == true)
	{
		if (!gInterface.Data[ButtonID].Attribute)
		{
			return false;
		}
	}

	// ----
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[ButtonID].EventTick);
	// ----

	if (Event == WM_LBUTTONDOWN && gInterface.Data[ButtonID].OnClick == false)
	{
		gInterface.Data[ButtonID].OnClick = true;
		//return false;
	}

	if (Event == WM_LBUTTONUP && gInterface.Data[ButtonID].OnClick == true)
	{
		gInterface.Data[ButtonID].OnClick = false;
		return true;
	}
	// ----
	if (Delay < 1000)
	{
		return false;
	}
	// ----
	gInterface.Data[ButtonID].OnClick = false;
	// ----
	gInterface.Data[ButtonID].EventTick = GetTickCount();
	// ----
	return false;
}

void JewelsBank::Draw()
{
	if (this->Active == false) return;

	if(gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::MuHelper)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow))
	{
		gInterface.Data[eJEWELBANK_MAIN].OnShow		= false;
		gInterface.Data[eJEWELBANK_MAIN].Close();		
		return;
	}

	gInterface.Data[eJEWELBANK_MAIN].OnShow = true;

	DWORD Color				= eGray100;
	float MainWidth			= 230.0;
	float MainHeight		= 350.0;
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

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight - 20, 0, 0);
	gInterface.DrawFormat(eGold, StartX + 10, StartY + 10, 210, 3, "Jewel Bank System");	
	
	gInterface.DrawGUI2(eJEWELBANK_CLOSE, StartX + MainWidth - 36 + 5, StartY - 6);
	// ----
	if (gInterface.IsWorkZone(eJEWELBANK_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (gInterface.Data[eJEWELBANK_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI2(eJEWELBANK_CLOSE,StartX + MainWidth - 36 + 5, StartY - 6, Color);
		gInterface.DrawToolTip(StartX + MainWidth - 32 + 5, StartY - 12, "Close ");
	}

	float flDrawX = StartX + 20;
	float flDrawY = StartY + 30;

	this->DrawInfo(flDrawX, flDrawY, "Zen", true, Zen);

	flDrawY += 20;
	pDrawGUI(71520, StartX, flDrawY + 14, 200, 1);

	flDrawY += 20;
	this->DrawLine(12, 15, 1, flDrawX, flDrawY, "Jewel Of Chaos", ChaosBank);

	flDrawY += 20;
	this->DrawLine(14, 13, 2, flDrawX, flDrawY, "Jewel Of Bless", BlessBank);

	flDrawY += 20;
	this->DrawLine(14, 14, 3, flDrawX, flDrawY, "Jewel Of Soul", SoulBank);

	flDrawY += 20;
	this->DrawLine(14, 16, 4, flDrawX, flDrawY, "Jewel Of Life", LifeBank);

	flDrawY += 20;
	this->DrawLine(14, 22, 5, flDrawX, flDrawY, "Jewel Of Creation", CreateonBank);

	flDrawY += 20;
	this->DrawLine(14, 31, 6, flDrawX, flDrawY, "Jewel of Guardian", GuardianBank);

	flDrawY += 20;
	this->DrawLine(14, 42, 7, flDrawX, flDrawY, "Jewel of Harmony", HarmonyBank);

	flDrawY += 20;
	this->DrawLine(14, 43, 8, flDrawX, flDrawY, "Jewel Of LowStone", LowStoneBank);

	flDrawY += 20;
	this->DrawLine(14, 44, 9, flDrawX, flDrawY, "Jewel Of HighStone", HighStoneBank);

	flDrawY += 20;
	this->DrawLine(14, 41, 10, flDrawX, flDrawY, "Jewel Of GemStone", GemStoneBank);
}

void JewelsBank::DrawLine(int ItemType, int ItemIndex, int ItemLevel, float ItemDrawX, float ItemDrawY, char * ItemName, int Count)
{
	ItemBmdStruct* ItemInfo = pGetItemBmdStruct(ITEM(ItemType, ItemIndex));

	const int WidthValue = 24;
	const int HeightValue = 26;
	float barWidth = WidthValue * ItemInfo->ItemWidth;
	float barHeight = HeightValue * ItemInfo->ItemHeight;
	float flX = ItemDrawX + 10;
	float flY = ItemDrawY;
	int iLevel = 0;
	gInterface.DrawItem2(flX, flY, barWidth, barHeight, GET_ITEM(ItemType,ItemIndex), SET_ITEMOPT_LEVEL(iLevel), 1, 0, 0);

	flX += 30;
	flY += 10;
	gInterface.DrawFormat(eYellow, flX, flY + 2, 100, 1, "%s x %d", ItemName, Count);

	flX += 95;
	gInterface.DrawGUI2(eJEWELBANK_PAGEDN1 + ItemLevel, flX, flY);

	if(gInterface.IsWorkZone(eJEWELBANK_PAGEDN1 + ItemLevel))
	{
		if(gInterface.Data[eJEWELBANK_PAGEDN1 + ItemLevel].OnClick)
		{
			gInterface.DrawColoredGUI2(eJEWELBANK_PAGEDN1 + ItemLevel, gInterface.Data[eJEWELBANK_PAGEDN1 + ItemLevel].X, gInterface.Data[eJEWELBANK_PAGEDN1 + ItemLevel].Y, eGray150);
		}	
	}

	flX += 20;
	gInterface.DrawGUI2(eJEWELBANK_PAGEUP1 + ItemLevel, flX, flY);

	if(gInterface.IsWorkZone(eJEWELBANK_PAGEUP1 + ItemLevel))
	{
		if(gInterface.Data[eJEWELBANK_PAGEUP1 + ItemLevel].OnClick)
		{
			gInterface.DrawColoredGUI2(eJEWELBANK_PAGEUP1 + ItemLevel, gInterface.Data[eJEWELBANK_PAGEUP1 + ItemLevel].X, gInterface.Data[eJEWELBANK_PAGEUP1 + ItemLevel].Y, eGray150);
		}
	}
}

void JewelsBank::DrawInfo(float InfoDrawX, float InfoDrawY, char* Text, bool Type, int Count)
{
	float flX = InfoDrawX + 10;
	float flY = InfoDrawY;

	gInterface.DrawGUI(eJEWELBANK_POINT, flX + 8, flY + 10);

	flX += 30;
	flY += 10;
	

	if(Type)
	{
		gInterface.DrawFormat(eYellow, flX, flY + 2, 100, 1, "%s: %d 000 000", Text, Count);

		flX += 95;
		gInterface.DrawGUI2(eJEWELBANK_PAGEDN1, flX, flY);
	
		if(gInterface.IsWorkZone(eJEWELBANK_PAGEDN1))
		{
			if(gInterface.Data[eJEWELBANK_PAGEDN1].OnClick)
			{
				gInterface.DrawColoredGUI2(eJEWELBANK_PAGEDN1, gInterface.Data[eJEWELBANK_PAGEDN1].X, gInterface.Data[eJEWELBANK_PAGEDN1].Y, eGray150);
			}
		}

		flX += 20;
		gInterface.DrawGUI2(eJEWELBANK_PAGEUP1, flX, flY);

		if(gInterface.IsWorkZone(eJEWELBANK_PAGEUP1))
		{
			if(gInterface.Data[eJEWELBANK_PAGEUP1].OnClick)
			{
				gInterface.DrawColoredGUI2(eJEWELBANK_PAGEUP1, gInterface.Data[eJEWELBANK_PAGEUP1].X, gInterface.Data[eJEWELBANK_PAGEUP1].Y, eGray150);
			}
			
		}
	}
	else
	{
		gInterface.DrawFormat(eYellow, flX, flY + 2, 100, 1, "%s: %d", Text, Count);
	}
}

void JewelsBank::Button(DWORD key)
{
	if(this->Active == false)
	{
		return;
	}
	
	for(int i = 0; i < 11; i++)
	{
		if(this->ButtonEx(key, eJEWELBANK_PAGEUP1 + i, false))
		{
			this->Packet(i);
			return;
		}
		else if(this->ButtonEx(key, eJEWELBANK_PAGEDN1 + i, false))
		{
			this->Packet(i+11);
			return;
		}
	}

}

bool JewelsBank::EventJewelBank_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_CLOSE].OnClick = false;
	// ----
	if (Delay < 1000)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_CLOSE].EventTick = GetTickCount();

	gJewelsBank.Active = false;
	gInterface.Data[eJEWELBANK_MAIN].OnShow = false;
	// ----
	
	return false;
}

void JewelsBank::Packet(int number)
{
	PMSG_JEWELBANK pMsg;
	pMsg.h.set(0xF3, 0xDF, sizeof(pMsg));
	pMsg.Result = number;
	DataSend((LPBYTE)&pMsg, pMsg.h.size);
}

void JewelsBank::RecibirJewelsBank(PMSG_JEWELSBANK * aRecv)
{
	if (aRecv == NULL)
	{
		return;
	}
	// ---
	Zen = aRecv->Zen;
	ChaosBank = aRecv->Chaos;
	BlessBank = aRecv->Bless;
	SoulBank = aRecv->Soul;
	LifeBank = aRecv->Life;
	CreateonBank = aRecv->CreateonBank;
	GuardianBank = aRecv->GuardianBank;
	HarmonyBank = aRecv->HarmonyBank;
	LowStoneBank = aRecv->LowStoneBank;
	HighStoneBank = aRecv->HighStoneBank;
	GemStoneBank = aRecv->GemStoneBank;
}