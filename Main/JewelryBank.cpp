#include "stdafx.h"
#include "JewelryBank.h"
#include "Import.h"
#include "Interface.h"
#include "Central.h"
#include "Defines.h"

BankOfJewel JewelOfBack;

void BankOfJewel::RenderJewelOFBank()
{

	if(!gInterface.Data[eJewelOfBank].OnShow || gInterface.Data[eMenu_MAIN].OnShow)
	{
		return;
	}

	float MainWidth = 190.0;
	float MainHeight = 422;
	float StartY = 0;
	float StartX = 0;
	//float MainCenter = StartX + (MainWidth / 3);
	//float ButtonX = MainCenter - (float)(29.0 / 2);

	//gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	gInterface.Data[eJewelOfBank].X = StartX;
	gInterface.Data[eJewelOfBank].Y = StartY;

	//gInterface.DrawFormat(eShinyGreen, (int)StartX, (int)StartY + 10, 230, 3, "Jewel Of Bank");

	pDrawGUI(71526, 0, 0, 190.0, 422); //-- Divisor
//	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartY + 35, 200, 1); //-- Divisor

	/*pDrawGUI(71525, StartX + (MainWidth / 2) - (200 / 2) + 20, StartY + 50, 49, 140);

	gInterface.DrawButtonRender(eJewelOfBankPush, StartX + (MainWidth / 2) - 70, StartY + 200, 0 , 0);
	gInterface.DrawFormat(eWhite, StartX + (MainWidth / 2) - 70, StartY + 210, 59, 3, "Deposit");


	gInterface.DrawButtonRender(eJewelOfBankRemove, StartX + (MainWidth / 2) + 11, StartY + 200, 0 , 0);
	gInterface.DrawFormat(eWhite, StartX + (MainWidth / 2) + 11, StartY + 210, 59, 3, "Obtener");

	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2),  StartY + MainHeight - 40, 200, 1); //-- Divisor

	gInterface.DrawButtonRender(eJewelOfBankClose, StartX + (MainWidth / 2) - (59 / 2), StartY + MainHeight - 32, 0 , 0);
	gInterface.DrawFormat(eWhite, StartX + (MainWidth / 2) - (59 / 2), StartY + MainHeight - 25, 59, 3, "Close");*/

}


void BankOfJewel::OpenBank()
{
	if((GetTickCount() - gInterface.Data[eJewelOfBank].EventTick) < 400 || gInterface.CheckWindow(33) ||  gInterface.Data[eMenu_MAIN].OnShow || gInterface.CheckWindow(35) )
	{
		return;
	}

	gInterface.Data[eJewelOfBank].EventTick = GetTickCount();

	PlayBuffer(25, 0, 0);

	if ( this->CheckBank() )
	{
		gInterface.Data[eJewelOfBank].OnShow = false;
	}
	else 
	{
		gInterface.Data[eJewelOfBank].OnShow = true;
	}
}