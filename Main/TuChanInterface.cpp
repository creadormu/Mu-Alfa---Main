#include "stdafx.h"
#include "User.h"
#include "TuChanInterface.h"
#include "Central.h"
#include "Interface.h"
#include "DanhHieuTuChan.h"
#include "Defines.h"
#include "JewelBank.h"
#include "Item.h"
#include "CustomFont.h"
#include "CustomRankUser.h"
#include "JCButton.h"
#include "Config.h"


cTuChanInterface gTuChanInterface;

cTuChanInterface::cTuChanInterface()
{
}


cTuChanInterface::~cTuChanInterface()
{
}

void cTuChanInterface::loadBind(){
	gInterface.BindObject(eTUCHAN_MAIN, 0x7A5A, 222, 345, -1, -1);
	gInterface.BindObject(eTUCHAN_TITLE, 0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(eTUCHAN_FRAME, 0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(eTUCHAN_FOOTER, 0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(eTUCHAN_DIV, 0x7A62, 223, 21, -1, -1);
	gInterface.BindObject(eTUCHAN_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(eTUCHAN_SYSTEM_ACTIVE, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(eNextEventTC, 31659, 17, 18, -1, -1);
	gInterface.BindObject(eNextEventTC, 31658, 17, 18, -1, -1);
	gInterface.BindObject(eTuChanSend, 71522, 108, 30.5f, -1, -1);
	gInterface.BindObject(eShowTuChan, 31593, 15, 15, -1, -1);

}

void cTuChanInterface::GCReqTuChan() // OK
{
	this->Count = 40;

	for(int n=0;n < this->Count;n++)
	{

		if (n >= 0 && n <=39) this->Arena = 1;
	}

	
}

void cTuChanInterface::SwitchTuChan(){
	gInterface.Data[eTUCHAN_MAIN].OnShow == true ? gInterface.Data[eTUCHAN_MAIN].Close() : gInterface.Data[eTUCHAN_MAIN].Open();
}

int TuChanInterface = 50041;

void cTuChanInterface::DrawTuChanWindow(){
	if (!gInterface.Data[eTUCHAN_MAIN].OnShow){
		return;
	}

	if ( gInterface.CheckWindow(Inventory)
		|| gInterface.CheckWindow(Character) //-- 13 & 16
		|| gInterface.CheckWindow(Warehouse) //-- 8
		|| gInterface.CheckWindow(Shop) //-- 12
		|| gInterface.CheckWindow(ChaosBox) //-- 9
		|| gInterface.CheckWindow(Trade) //-- 7
		|| gInterface.CheckWindow(Store) //-- 14
		|| gInterface.CheckWindow(OtherStore) //-- 15
		|| gInterface.CheckWindow(LuckyCoin1) //-- 60
		|| gInterface.CheckWindow(NPC_ChaosMix) ) //-- 76
	{
		gInterface.Data[eTUCHAN_MAIN].OnShow = false;
	}


	float MainWidth			= 230.0;
	float MainHeight		= 180.0;
	float StartBody			= ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartY			= ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX			= (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	if (gInterface.IsWorkZone4(StartX, StartY, StartX + MainWidth, StartY + MainHeight))
	{
		pSetCursorFocus = true;
	}
	else {pSetCursorFocus = true;
	}
	//gInterface.DrawWindow(eTUCHAN_MAIN, eTUCHAN_TITLE, eTUCHAN_FRAME, eTUCHAN_FOOTER, 14, StartX, StartY, "");

	

	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	
	//pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartBody + 20, 200, 1); //-- Divisor

	//gInterface.DrawButtonRender(eTuChanSend, StartX + 20, 362, 0.0, 0.0);

	

	//JCOptionBox.ActionListener(1);


	//JCOptionBox.LoadAction(1,JCDINAMIC_EFFECT);

	if (gInterface.IsWorkZone(eTUCHAN_CLOSE))
	{
		if (gInterface.Data[eTUCHAN_CLOSE].OnClick)
		{
			PlayBuffer(25, 0, 0);
			gInterface.DrawButtonRender(eTUCHAN_CLOSE, (int)StartX + 205, (int)StartY - 10, 0 , 28);
		}
		else
		{
			gInterface.DrawButtonRender(eTUCHAN_CLOSE, (int)StartX + 205, (int)StartY - 10, 0 , 0);
		}
	}
	else
	{
		gInterface.DrawButtonRender(eTUCHAN_CLOSE, (int)StartX + 205, (int)StartY - 10, 0 , 0);
	}


	if(gDanhHieu.m_Slot2 != 40)
	{
		
		if (gInterface.IsWorkZone(eTuChanSend))
		{
			

			if (gInterface.Data[eTuChanSend].OnClick)
			{

				PlayBuffer(25, 0, 0);
				gInterface.DrawButtonRender(eTuChanSend, StartX + (MainWidth / 2) - (108 / 2), StartBody + MainHeight - 40, 0 , 28);
			}
			else
			{
				gInterface.DrawButtonRender(eTuChanSend, StartX + (MainWidth / 2) - (108 / 2), StartBody + MainHeight - 40, 0 , 0);
			}
		}
		else
		{
			gInterface.DrawButtonRender(eTuChanSend, StartX + (MainWidth / 2) - (108 / 2), StartBody + MainHeight - 40, 0 , 0);
		}
		gInterface.DrawFormat(eGold180 , StartX + (MainWidth / 2) - (38 / 2), StartBody + MainHeight - 32, 300, 1,  Config.MenuTuChan_TextNVT[9]);

	}
	//== nút tích

	//pDrawButton(31593, x + 140, y + 57, 15, 15, 0.0, (LogoTuChan != 0) ? 0.0 : 15.0); //-- Time Bar

	//gInterface.SwitchTuChan();

	
	
	if(gInterface.Data[eTUCHAN_MAIN].OnShow)
	{
		int ShowTuChan =  GetPrivateProfileInt ( "TUCHAN", "OnOff", 1, ".\\Settings.ini" );

		if (gInterface.IsWorkZone(eShowTuChan))
		{
			if (ShowTuChan == 1)
			{
			
				PlayBuffer(25, 0, 0);
				gInterface.DrawButtonRender(eShowTuChan, StartX + (MainWidth / 2) - (108 / 2), StartBody + MainHeight - 57, 0 , 0);
			}
			else
			{
				gInterface.DrawButtonRender(eShowTuChan, StartX + (MainWidth / 2) - (108 / 2), StartBody + MainHeight - 57, 0 , 15);
			}
		}
		else if (ShowTuChan == 1)
		{
			gInterface.DrawButtonRender(eShowTuChan, StartX + (MainWidth / 2) - (108 / 2), StartBody + MainHeight - 57, 0 , 0);
			
		}
		else
		{
			gInterface.DrawButtonRender(eShowTuChan, StartX + (MainWidth / 2) - (108 / 2), StartBody + MainHeight - 57, 0 , 15);
		}


		if (ShowTuChan == 1)
		{
			gInterface.DrawFormat(eExcellent, (StartX + 50), StartBody + MainHeight - 55, 150, 3, Config.MenuTuChan_TextNVT[6]);	
		}
		else
		{
			gInterface.DrawFormat(eExcellent, (StartX + 50), StartBody + MainHeight - 55, 150, 3, Config.MenuTuChan_TextNVT[7]);	
		}
	}




	//if(gInterface.Data[eTUCHAN_MAIN].OnShow)
	//{
	//		if((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000 || gInterface.CheckWindow(ChatWindow))
	//		{
	//			return;
	//		}
	//		if( gProtect.m_MainInfo.EnableRankTuChan != 0 )
	//			{

	//			gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

	//			int ShowTuChan =  GetPrivateProfileInt ( "TUCHAN", "OnOff", 1, ".\\Settings.ini" );
	//			if (gInterface.IsWorkZone(eShowTuChan))
	//			{
	//				if (gInterface.Data[eShowTuChan].OnClick)
	//				{
	//					if (ShowTuChan != 0)
	//					{
	//						//gInterface.DrawMessage(1, TuChanOff);
	//						ShowTuChan = 0;
	//						WritePrivateProfileStringA("TUCHAN","OnOff"," 0","./Settings.ini");
	//						PlayBuffer(25, 0, 0);
	//						gInterface.DrawButtonRender(eShowTuChan, StartX + (MainWidth / 2) - (108 / 2), StartBody + MainHeight - 50, 0 , 15);
	//					}
	//					else 
	//					{
	//						//gInterface.DrawMessage(1,  TuChanOn);
	//						ShowTuChan = 1;
	//						WritePrivateProfileStringA("TUCHAN","OnOff"," 1","./Settings.ini");
	//						gInterface.DrawButtonRender(eShowTuChan, StartX + (MainWidth / 2) - (108 / 2), StartBody + MainHeight - 50, 0 , 0);
	//					}
	//				}
	//			}
	//		}
	//}
	//== nút tích


	//pDrawImage(50069,StartX+52, 10, 75, 15, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
	//pDrawImage(50070,StartX+52, 70, 75, 15, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
	//pDrawImage(50071,			 StartX + (MainWidth / 2) - (130 / 2), StartBody+15, 150, 60, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);

	//gInterface.DrawFormat(eGold, StartX - 10, StartBody + 120, 150, 3, "123123 %d", gCustomRankUser.m_Data[m_rcrit]);	
	//gInterface.DrawFormat(eGold, StartX	+ 15, StartBody + 120, 170, 3, "323123 %d", gCustomRankUser.m_Data[m_rexc]);	
	//gInterface.DrawFormat(eGold, StartX + 40, StartBody + 120, 190, 3, "321312 %d", gCustomRankUser.m_Data[m_rdmg]);	
	//gInterface.DrawFormat(eGold, StartX + 65, StartBody + 120, 210, 3, "321312 %d", gCustomRankUser.m_Data[m_rdouble]);	
	


	switch (gDanhHieu.m_Slot2)
	{
		case 0:  
			
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[0], Config.TuChan[1], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[8]);
			pDrawImage(50000,StartX+52, StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			break;
		case 1:  
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[0], Config.TuChan[1], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[8]);
			pDrawImage(50000,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);  
			pDrawImage(50001,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");
			break;
		case 2:  
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[0], Config.TuChan[1], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[8]);
			pDrawImage(50001,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);  
			pDrawImage(50002,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");
			break;
		case 3:  
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[0], Config.TuChan[1], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[8]);
			pDrawImage(50002,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);  
			pDrawImage(50003,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");
			break;
		case 4: 
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[0], Config.TuChan[1], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[8]);
			pDrawImage(50003,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);  
			pDrawImage(50004,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 5:  
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[0], Config.TuChan[1], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[8]);
			pDrawImage(50004,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);  
			pDrawImage(50005,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 6:  
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[0], Config.TuChan[1], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[8]);
			pDrawImage(50005,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);  
			pDrawImage(50006,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 7:  
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[0], Config.TuChan[1], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[8]);
			pDrawImage(50006,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);  
			pDrawImage(50007,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 8: 
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[0], Config.TuChan[1], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[8]);
			pDrawImage(50007,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);  
			pDrawImage(50008,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 9:
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[0], Config.TuChan[1], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[8]);
			pDrawImage(50008,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50009,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 10:
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[2], Config.TuChan[3], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[9]);
			pDrawImage(50009,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50010,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 11:
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[2], Config.TuChan[3], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[9]);
			pDrawImage(50010,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50011,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 12: 
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[2], Config.TuChan[3], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[9]);
			pDrawImage(50011,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50012,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 13: 
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[2], Config.TuChan[3], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[9]);
			pDrawImage(50012,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50013,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 14: 
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[2], Config.TuChan[3], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[9]);
			pDrawImage(50013,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50014,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 15: 
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[2], Config.TuChan[3], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[9]);
			pDrawImage(50014,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50015,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 16: 
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[2], Config.TuChan[3], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[9]);
			pDrawImage(50015,StartX+52, StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50016,StartX+52, StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 17:
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[2], Config.TuChan[3], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[9]);
			pDrawImage(50016,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			pDrawImage(50017,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 18: 
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[2], Config.TuChan[3], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[9]);
			pDrawImage(50017,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50018,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 19:
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[2], Config.TuChan[3], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[9]);
			pDrawImage(50018,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50019,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 20: 
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[4], Config.TuChan[5], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[10]);
			pDrawImage(50019,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50020,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 21:
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[4], Config.TuChan[5], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[10]);
			pDrawImage(50020,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50021,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 22: 
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[4], Config.TuChan[5], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[10]);
			pDrawImage(50021,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50022,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 23:
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[4], Config.TuChan[5], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[10]);
			pDrawImage(50022,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50023,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 24:
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[4], Config.TuChan[5], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[10]);
			pDrawImage(50023,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50024,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;

		case 25:
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[4], Config.TuChan[5], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[10]);
			pDrawImage(50024,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50025,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 26:
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[4], Config.TuChan[5], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[10]);
			pDrawImage(50025,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50026,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 27:
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[4], Config.TuChan[5], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[10]);
			pDrawImage(50026,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50027,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 28:
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[4], Config.TuChan[5], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[10]);
			pDrawImage(50027,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50028,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 29:
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[4], Config.TuChan[5], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[10]);
			pDrawImage(50028,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50029,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 30:
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[6], Config.TuChan[7], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[11]);
			pDrawImage(50029,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50030,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 31:
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[6], Config.TuChan[7], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[11]);
			pDrawImage(50030,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50031,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 32:
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[6], Config.TuChan[7], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[11]);
			pDrawImage(50031,StartX+52,StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50032,StartX+52,StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 33: 
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[6], Config.TuChan[7], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[11]);
			pDrawImage(50032,StartX+52, StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50033,StartX+52, StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 34: 
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[6], Config.TuChan[7], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[11]);
			pDrawImage(50033,StartX+52, StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			pDrawImage(50034,StartX+52, StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 35:
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[6], Config.TuChan[7], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[11]);
			pDrawImage(50034,StartX+52, StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50035,StartX+52, StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 36: 
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[6], Config.TuChan[7], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[11]);
			pDrawImage(50035,StartX+52, StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50036,StartX+52, StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 37: 
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[6], Config.TuChan[7], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[11]);
			pDrawImage(50036,StartX+52, StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			pDrawImage(50037,StartX+52, StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 38: 
			gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
			this->DrawLineJewel(Config.TuChan[6], Config.TuChan[7], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[11]);
			pDrawImage(50037,StartX+52, StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); 
			pDrawImage(50038,StartX+52, StartY + 55, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		
			gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");break;
		case 39: 
				pDrawImage(50038,StartX+52, StartY + 10, 150, 67, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);  
				if(TuChanInterface >= 50041){
						pDrawImage(TuChanInterface,StartX+52, 75, 150, 67,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
						TuChanInterface++;
						if(TuChanInterface == 50068){TuChanInterface = 50041;}
				}
				gInterface.DrawToolTip( StartX + MainWidth + 15, 255 - 50, Config.MenuTuChan_TextNVT[8]);
				this->DrawLineJewel(Config.TuChan[6], Config.TuChan[7], 1,StartX + MainWidth + 100,255 - 60, "", Config.TuChan[11]);
				gInterface.DrawFormat(eGold, StartX + (MainWidth / 2) - (210 / 2), StartBody+12, 210, 3, "");
		break;
		case 40: 
			if(TuChanInterface >= 50041){
				pDrawImage(TuChanInterface,StartX+52, StartY + 30, 150, 67,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				TuChanInterface++;
				if(TuChanInterface == 50068){TuChanInterface = 50041;}
			} 
		break;
	}


}

bool cTuChanInterface::EventTuChanWindow_Main(DWORD Event){

	if ( gInterface.CheckWindow(Inventory)
		|| gInterface.CheckWindow(Character) //-- 13 & 16
		|| gInterface.CheckWindow(Warehouse) //-- 8
		|| gInterface.CheckWindow(Shop) //-- 12
		|| gInterface.CheckWindow(ChaosBox) //-- 9
		|| gInterface.CheckWindow(Trade) //-- 7
		|| gInterface.CheckWindow(Store) //-- 14
		|| gInterface.CheckWindow(OtherStore) //-- 15
		|| gInterface.CheckWindow(LuckyCoin1) //-- 60
		|| gInterface.CheckWindow(NPC_ChaosMix) ) //-- 76
	{
		return false;
	}

	this->EventTuChanWindow_Close(Event);
	this->EventTuChanWindow_Send(Event);
	this->EventShowTuChanDraw(Event);
	return true;
}

bool cTuChanInterface::EventTuChanWindow_Close(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eTUCHAN_CLOSE].EventTick);
	if (!gInterface.Data[eTUCHAN_MAIN].OnShow || !gInterface.IsWorkZone(eTUCHAN_CLOSE)){
		return false;
	}
	if (Event == WM_LBUTTONDOWN){
		gInterface.Data[eTUCHAN_CLOSE].OnClick = true;
		return true;
	}
	gInterface.Data[eTUCHAN_CLOSE].OnClick = false;
	if (Delay < 500){
		return false;
	}
	gInterface.Data[eTUCHAN_CLOSE].EventTick = GetTickCount();
	gInterface.Data[eTUCHAN_MAIN].Close();
	return false;
}

bool cTuChanInterface::EventTuChanWindow_Send(DWORD Event)
{
	if(gDanhHieu.m_Slot2 == 40)
	{
		return false;
	}
	
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eTuChanSend].EventTick);
	if (!gInterface.Data[eTUCHAN_MAIN].OnShow || !gInterface.IsWorkZone(eTuChanSend)){
		return false;
	}
	if (Event == WM_LBUTTONDOWN){
		gInterface.Data[eTuChanSend].OnClick = true;
		return true;
	}
	gInterface.Data[eTuChanSend].OnClick = false;
	if (Delay < 1000){
		return false;
	}
	gInterface.Data[eTuChanSend].EventTick = GetTickCount();
	gTuChanInterface.EventTuChan_Send(0);
	//gInterface.Data[eTUCHAN_MAIN].Close();

	return false;
}

bool cTuChanInterface::EventShowTuChanDraw(DWORD Event)
{
	//if(gDanhHieu.m_Slot2 == 40)
	//{
	//	return false;
	//}
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eShowTuChan].EventTick);
	if (!gInterface.Data[eTUCHAN_MAIN].OnShow || !gInterface.IsWorkZone(eShowTuChan)){
		return false;
	}
	if (Event == WM_LBUTTONDOWN){
		gInterface.Data[eShowTuChan].OnClick = true;
		return true;
	}
	gInterface.Data[eShowTuChan].OnClick = false;
	if (Delay < 500){
		return false;
	}
	gInterface.Data[eShowTuChan].EventTick = GetTickCount();
	
	gInterface.SwitchTuChan();

	return false;
}

void cTuChanInterface::DrawLineJewel(int ItemType, int ItemIndex, int ItemLevel, float ItemDrawX, float ItemDrawY, char * ItemName, int Count)
{
	ItemBmdStruct* ItemInfo = pGetItemBmdStruct(ITEM(ItemType, ItemIndex));
	const int WidthValue = 24;
	const int HeightValue = 26;
	float barWidth = WidthValue * ItemInfo->ItemWidth;
	float barHeight = HeightValue * ItemInfo->ItemHeight;
	float flX = ItemDrawX + 10;
	float flY = ItemDrawY;
	int iLevel = 100;
	
	
	//gInterface.DrawItem2(214, 223, barWidth, barHeight, GET_ITEM(ItemType, ItemIndex), SET_ITEMOPT_LEVEL(iLevel), 1, 0, 0);
	gInterface.DrawItem2(flX, flY, barWidth, barHeight, GET_ITEM(ItemType, ItemIndex), SET_ITEMOPT_LEVEL(iLevel), 1, 0, 0);
	
	flX += 30; //35
	flY += 10;
	//CustomFont.DrawMultipleColor(CustomFont.FontBold, flX, flY + 2, 0x0, 0, 0, 3, "%sx%d", ItemName, Count);
	CustomFont.DrawMultipleColor(CustomFont.FontBold, flX, flY + 2, 0x0, 0, 0, 3, "x%d", Count);
}



void cTuChanInterface::EventTuChan_Send(int TU_CHAN)
{
	EVENTTUCHAN_REQ pRequest;
	pRequest.h.set(0xF3,0x32, sizeof(pRequest));
	pRequest.TU_CHAN = TU_CHAN;
	DataSend((LPBYTE)&pRequest, pRequest.h.size);
}



