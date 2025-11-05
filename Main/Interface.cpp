#include "stdafx.h"
#include "Common.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomRanking.h"
#include "Interface.h"
#include "Import.h"
#include "Reconnect.h"
#include "TMemory.h"
#include "Defines.h"
#include "OffTrade.h"
#include "Protect.h"
#include "Protocol.h"
#include "PrintPlayer.h"
#include "User.h"
#include "Util.h"
#include "array.h"
#include "Offset.h"
#include "StatsAdvance.h"
#include "CustomCloak.h"
#include "ChatExpanded.h"
#include "Camera.h"
#include "TrayModeNew.h"
#include "Controller.h"
#include "postInterface.h"
#include "Ruud.h"
#include "Inter3.h"
#include "InterEx.h"
#include "Central.h"
#include "JewelryBank.h"
#include "NPCRuud.h"
#include "ChangeClass.h"
#include "PartySearch.h"
#include "PartySearchSettings.h"
#include "CustomRankUser.h"
#include "MultiWare.h"
#include "ChangeClass.h"
#include "LuckyWheels.h"
#include "ChangeReset.h"
#include "CSmithItem.h"
#include "SmithItem.h"
#include "JewelBank.h"
#include "MultiCharacter.h"
#include "WindowsStruct.h"
#include "MiniMap.h"
#include "Achievements.h"
#include "MuaVip.h"
#include "DanhHieu.h"
#include "TuChanInterface.h"
#include "ExQuestWinSystem.h"
#include "EmojiSystem.h"


Interface gInterface;

Interface::Interface()
{
	this->Moving = false;
	this->ultimoX = 205;
    this->ultimoY = 30;
	this->ultimoPTsearchY = 50;
	this->ultimoWareY = 100;
	
}

Interface::~Interface()
{
}

void Interface::RenderObjectSystem()
{
	if(gProtect.m_MainInfo.MonitorMS == 1)
	{
		gInterface.lastReport = GetTickCount();
		gInterface.frameCount = 0;
	}
	if(gProtect.m_MainInfo.MonitorFPS == 1)
	{
		gInterface.iniciador = 1;
	}

	//51522
	//--
		//Menu
	this->BindObject(eMenu_MAIN, 0x7A5A, 222, 240, -1, -1);
	this->BindObject(eMenu_MAINTWO, 0x7A5A, 222, 240, -1, -1);
	this->BindObject(eMenu_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eMenu_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eMenu_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eMenu_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eMenu_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eMenu_OPT1, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_OPT2, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_OPT3, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_OPT4, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_OPT20, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_VAULT, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_USERPANEL, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_CHANGECLASS, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_RESETCHANGE, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_LUCKYWELL, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_SMITH_ITEM, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_JEWEL_BANK, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_CUSTOM_VIP, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_RANK_TITLE, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_TU_CHAN, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eMenu_QUEST_SYSTEM, 0x7A5E, 108, 29, -1, -1);
	
	this->BindObject(eMenu_NEXT, 0x7918, 23, 23, -1, -1);
	this->BindObject(eMenu_PREVIUS, 0x7913, 23, 23, -1, -1);

	this->BindObject(EXBEXO_MUA_VIP_MAIN, 0x0899, 560, 279, -1, -1);
	this->BindObject(EXBEXO_MUA_VIP_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(EXBEXO_MUA_VIP_NANG_CAP, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(EXBEXO_DANH_HIEU_MAIN, 0x0899, 560, 279, -1, -1);
	this->BindObject(EXBEXO_DANH_HIEU_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(EXBEXO_DANH_HIEU_NANG_CAP, 0x7A5E, 108, 29, -1, -1);

	this->BindObject(eCONFIRM_MUUNBTN_OK, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eCONFIRM_MUUNBTN_CANCEL, 0x7A5C, 54, 30, -1, -1);
	//--
	//this->BindObject(eTIME, 30847, 106, 22, -10, 359);
	this->BindObject(eFlag01, 0x7880, 78, 78, -1, -1);
	this->BindObject(eFlag02, 0x7881, 78, 78, -1, -1);
	this->BindObject(eFlag03, 0x7882, 78, 78, -1, -1);
	this->BindObject(eFlag04, 0x7883, 78, 78, -1, -1);
	this->BindObject(eFlag05, 0x7884, 78, 78, -1, -1);
	this->BindObject(eFlag06, 0x7885, 78, 78, -1, -1);
	this->BindObject(eFlag07, 0x7886, 78, 78, -1, -1);
	this->BindObject(eFlag08, 0x7887, 78, 78, -1, -1);
	this->BindObject(eFlag09, 0x7888, 78, 78, -1, -1);
	this->BindObject(eFlag10, 0x7889, 78, 78, -1, -1);
	this->BindObject(eFlag11, 0x7890, 78, 78, -1, -1);
	this->BindObject(eFlag12, 0x7891, 78, 78, -1, -1);
	this->BindObject(eFlag13, 0x7892, 78, 78, -1, -1);
	this->BindObject(eFlag14, 0x7893, 78, 78, -1, -1);
	this->BindObject(eFlag15, 0x7894, 78, 78, -1, -1);
	this->BindObject(eFlag16, 0x7895, 78, 78, -1, -1);
	this->BindObject(eFlag17, 0x7896, 78, 78, -1, -1);
	this->BindObject(eFlag18, 0x7897, 78, 78, -1, -1);
	this->BindObject(eFlag19, 0x7898, 78, 78, -1, -1);
	this->BindObject(eFlag20, 0x7899, 78, 78, -1, -1);
	this->BindObject(eFlag21, 0x7900, 78, 78, -1, -1);
	this->BindObject(eFlag22, 0x7901, 78, 78, -1, -1);
	//--
	this->BindObject(eRanking, 0x7902, 179, 27, -1, -1);
	this->BindObject(eSAMPLEBUTTON, 0x7903, 25, 40, -1, -1);
	this->BindObject(eSAMPLEBUTTON2, 0x7904, 25, 40, -1, -1);
	//--
	this->BindObject(eVip_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eVip_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eVip_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eVip_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eVip_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eVip_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eVip_BRONZE, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_SILVER, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_GOLD, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_PLATINUM, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_STATUS, 0x7A5E, 108, 29, -1, -1);
	
	//--
	this->BindObject(eCommand_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eCommand_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCommand_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCommand_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCommand_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCommand_CLOSE, 0x7EC5, 36, 29, -1, -1);
	//--
	this->BindObject(eRanking_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eRanking_CLOSE, 0x7EC5, 36, 29, -1, -1);
	//--
	this->BindObject(eEventTime_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eEventTime_CLOSE, 0x7EC5, 36, 29, -1, -1);
	//--
	this->BindObject(eCONFIRM_MAIN, 0x7A5A, 222, 120, 205, -1);
	this->BindObject(eCONFIRM_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCONFIRM_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCONFIRM_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCONFIRM_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCONFIRM_BTN_OK, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eCONFIRM_BTN_CANCEL, 0x7A5C, 54, 30, -1, -1);
	this->BindObject(eLogo, 0x7905, 150, 114, -1, -1);

	// Change Class
	this->BindObject(eCHANGINGCLASS_MAIN, 0x7A5A, 222, 303, -1, -1);
	this->BindObject(eCHANGINGCLASS_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCHANGINGCLASS_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCHANGINGCLASS_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCHANGINGCLASS_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCHANGINGCLASS_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_INFOBG, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eCHANGINGCLASS_MONEYBG, 0x7A89, 170, 26, -1, -1);
	this->BindObject(eCHANGINGCLASS_DW, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_DK, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_ELF, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_MG, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_DL, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_SUM, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_RF, 0x7A5E, 106, 29, -1, -1);

	//Party Search
	this->BindObject(ePARTYSETTINGS_MAIN, 0x7A5A, 222, 345, -1, -1);
	this->BindObject(ePARTYSETTINGS_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(ePARTYSETTINGS_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(ePARTYSETTINGS_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(ePARTYSETTINGS_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(ePARTYSETTINGS_SYSTEM_ACTIVE, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_ONLY_GUILD, 0x7BAE, 15, 15, -1, -1); 
	this->BindObject(ePARTYSETTINGS_ONE_CLASS, 0x7BAE, 15, 15, -1, -1); 
	this->BindObject(ePARTYSETTINGS_DARK_WIZARD, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_DARK_KNIGHT, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_ELF, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_MAGIC_GLADIATOR, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_DARK_LORD, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_SUMMONER, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_RAGE_FIGHTER, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_LEVEL_MINUS, 0x7C0D, 16, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_LEVEL_PLUS, 0x7AA4, 16, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_OK, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(ePARTYSEARCH_MAIN, 0x7A5A, 230, 313, -1, -1);
	this->BindObject(ePARTYSEARCH_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(ePARTYSEARCH_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(ePARTYSEARCH_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(ePARTYSEARCH_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(ePARTYSEARCH_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(ePARTYSEARCH_LEFT, 0x7E56, 20, 23, -1, -1);
	this->BindObject(ePARTYSEARCH_RIGHT, 0x7E57, 20, 23, -1, -1);
	this->BindObject(ePARTYSETTINGS_INF, 0x7915, 54, 30, -1, -1);
	this->BindObject(ePARTYSETTINGS_INF2, 0x7916, 54, 30, -1, -1);

	//Warehouse
	this->BindObject(eVAULT_MAIN, 0x7A5A, 222, 220, -1, -1);
	this->BindObject(eVAULT_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eVAULT_FRAME, 0x7A58, 230, 12, -1, -1);
	this->BindObject(eVAULT_FOOTER, 0x7A59, 230, 0, -1, -1);
	this->BindObject(eVAULT_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eVAULT_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eVAULT_INFOBG, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eVAULT_MONEYBG, 0x7A89, 170, 26, -1, -1);
	this->BindObject(eVAULT_FINISH, 0x7A5E, 128, 29, -1, -1);
	this->BindObject(eWARE1_FINISH, 0x7A5E, 128, 29, -1, -1);
	this->BindObject(eWARE2_FINISH, 0x7A5E, 128, 29, -1, -1);
	this->BindObject(eWARE3_FINISH, 0x7A5E, 128, 29, -1, -1);
	this->BindObject(eWARE4_FINISH, 0x7A5E, 128, 29, -1, -1);
	this->BindObject(eWARE5_FINISH, 0x7A5E, 128, 29, -1, -1);
	this->BindObject(eWARE6_FINISH, 0x7A5E, 128, 29, -1, -1);
	this->BindObject(eWARE7_FINISH, 0x7A5E, 128, 29, -1, -1);
	this->BindObject(eWARE8_FINISH, 0x7A5E, 128, 29, -1, -1);
	this->BindObject(eWARE9_FINISH, 0x7A5E, 128, 29, -1, -1);

	//LuckyWheell
	this->BindObject(eLuckyWheelStart, 0x9327, 86, 33, -1, -1);
	this->BindObject(eLuckyWheelPanel, 0x9328, 312, 292, -1, -1);
	gInterface.BindObject(eCloseLuckyWheel, 0X7EC5, 36, 29, -1, -1);
	this->LuckyWheelNumber = -1;

		// ChangeCReset
	this->BindObject(eCHANGE_RESET_MAIN, 0x7A5A, 222, 303, -1, -1);
	this->BindObject(eCHANGE_RESET_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCHANGE_RESET_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCHANGE_RESET_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCHANGE_RESET_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCHANGE_RESET_LINE, 0x7B67, 154, 2, -1, -1);
	this->BindObject(eCHANGE_RESET_CLOSE, 0x7A5E, 128, 29, -1, -1);
	this->BindObject(eCHANGE_RESET_INFOBG, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eCHANGE_RESET_MONEYBG, 0x7A89, 170, 26, -1, -1);
	this->BindObject(eCHANGE_RESET_5, 0x7908, 106, 29, -1, -1); 
	this->BindObject(eCHANGE_RESET_10, 0x7908, 106, 29, -1, -1); 
	this->BindObject(eCHANGE_RESET_15, 0x7908, 106, 29, -1, -1); 
	this->BindObject(eCHANGE_RESET_20, 0x7908, 106, 29, -1, -1);
	this->BindObject(eCHANGE_RESET_25, 0x7908, 106, 29, -1, -1); 

	//smith
	this->BindObject(eUNCHECK_2, iOptionCheck, 15, 15, 175, 60);
	this->BindObject(eUNCHECK_3, iOptionCheck, 15, 15, 175, 90);
	this->BindObject(eUNCHECK_6, iOptionCheck, 15, 15, 195, 90);
	this->BindObject(eUNCHECK_4, iOptionCheck, 15, 15, 175, 120);
	this->BindObject(eUNCHECK_5, iOptionCheck, 15, 15, 175, 150);
	this->BindObject(eCHECKED_2, iOptionCheck, 15, 15, 175, 60);
	this->BindObject(eCHECKED_3, iOptionCheck, 15, 15, 175, 90);
	this->BindObject(eCHECKED_6, iOptionCheck, 15, 15, 195, 90);
	this->BindObject(eCHECKED_4, iOptionCheck, 15, 15, 175, 120);
	this->BindObject(eCHECKED_5, iOptionCheck, 15, 15, 175, 150);
	this->BindObject(eSMITH_MAIN, 0x7A5A, 222, 383, -1, -1);
	this->BindObject(eSMITH_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eSMITH_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eSMITH_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eSMITH_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eSMITH_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eSMITH_BUY, 0x7A5E, 128, 29, -1, -1);
	this->BindObject(eSMITH_ITEMTYPE, 0x7C0D, 16, 15, 215, 70);
	this->BindObject(eSMITH_ITEMTYPE_1, 0xAA4, 16, 15, 273, 70);
	this->BindObject(eSMITH_ITEMINDEX, 0x7C0D, 17, 18, 208, 103);
	this->BindObject(eSMITH_ITEMINDEX_1, 0xAA4, 17, 18, 400, 103);
	this->BindObject(eSMITH_DAYS, 0x7C0D, 16, 15, 340, 70);
	this->BindObject(eSMITH_DAYS_1, 0xAA4, 16, 15, 393, 70);
	this->BindObject(eSMITH_LEVEL, 0x7C0D, 16, 15, 340, 153);
	this->BindObject(eSMITH_LEVEL_1, 0xAA4, 16, 15, 380, 153);
	this->BindObject(eSMITH_OPT, 0x7C0D, 16, 15, 340, 213);
	this->BindObject(eSMITH_OPT_1, 0xAA4, 16, 15, 380, 213);
	this->BindObject(eSMITH_SKILL, 0x7B69, 15, 15, 380, 175);
	this->BindObject(eSMITH_SKILL_1, 0x7B69, 15, 15, 380, 175);
	this->BindObject(eSMITH_LUCK, 0x7B69, 15, 15, 380, 195);
	this->BindObject(eSMITH_LUCK_1, 0x7B69, 15, 15, 380, 195);
	this->BindObject(eSMITH_EXC, 0x7B69, 15, 15, 380, 235);
	this->BindObject(eSMITH_EXC_1, 0x7B69, 15, 15, 380, 235);
	this->BindObject(eSMITH_EXC1, 0x7B69, 15, 15, 380, 255);
	this->BindObject(eSMITH_EXC1_1, 0x7B69, 15, 15, 380, 255);
	this->BindObject(eSMITH_EXC2, 0x7B69, 15, 15, 380, 275);
	this->BindObject(eSMITH_EXC2_1, 0x7B69, 15, 15, 380, 275);
	this->BindObject(eSMITH_EXC3, 0x7B69, 15, 15, 380, 295);
	this->BindObject(eSMITH_EXC3_1, 0x7B69, 15, 15, 380, 295);
	this->BindObject(eSMITH_EXC4, 0x7B69, 15, 15, 380, 315);
	this->BindObject(eSMITH_EXC4_1, 0x7B69, 15, 15, 380, 315);
	this->BindObject(eSMITH_EXC5, 0x7B69, 15, 15, 380, 335);
	this->BindObject(eSMITH_EXC5_1, 0x7B69, 15, 15, 380, 335);

#if (SELECTCHARACTER==1)
	this->BindObject(eSELECTCHAR_LEFT, 0x7912, 25, 40, -1, -1);
	this->BindObject(eSELECTCHAR_RIGHT, 0x7911, 25, 40, -1, -1);
#endif

	if(gProtect.m_MainInfo.DisableEmojiSystem == 0)
	{
		gEmojis.AddTextures();
	}

	gAchievements.BindImages();
	g_ExWinQuestSystem.BindImages();

	//Custom Store
	if( gProtect.m_MainInfo.CustomInterfaceType == 3 )
	{
		this->BindObject(eOFFTRADE_JoB, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_JoS, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_JoC, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCC, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCP, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCG, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_OPEN, 51522, 108, 30, -1, -1);
	}
	else
	{
		this->BindObject(eOFFTRADE_JoB, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_JoS, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_JoC, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCC, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCP, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCG, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_OPEN, 0x7BFD, 108, 30, -1, -1);
	}
	//-- custom
	this->BindObject(eSTORE_CLOSE, 0x7BFD, 108, 30, -1, -1);
	//Minimap
	this->BindObject(ePLAYER_POINT, 31460, 3, 3, -1, -1);
	this->BindObject(eNULL_MAP, 31461, 128, 128, -1, -1);
	this->BindObject(eLORENCIA_MAP, 31462, 128, 128, -1, -1);
	this->BindObject(eDUNGEON_MAP, 31463, 128, 128, -1, -1);
	this->BindObject(eDEVIAS_MAP, 31464, 128, 128, -1, -1);
	this->BindObject(eNORIA_MAP, 31465, 128, 128, -1, -1);
	this->BindObject(eLOSTTOWER_MAP, 31466, 128, 128, -1, -1);
	this->BindObject(eSTADIUM_MAP, 61465, 128, 128, -1, -1);
	this->BindObject(eATLANS_MAP, 31467, 128, 128, -1, -1);
	this->BindObject(eTarkan_MAP, 31468, 128, 128, -1, -1);
	this->BindObject(eElbeland_MAP, 31469, 128, 128, -1, -1);
	this->BindObject(eICARUS_MAP, 31470, 128, 128, -1, -1);
	this->BindObject(eLANDOFTRIALS_MAP, 31461, 128, 128, -1, -1);
	this->BindObject(eAIDA_MAP, 31472, 128, 128, -1, -1);
	this->BindObject(eCRYWOLF_MAP, 31473, 128, 128, -1, -1);
	this->BindObject(eKANTRU_MAP, 31474, 128, 128, -1, -1);
	this->BindObject(eKANTRU3_MAP, 31475, 128, 128, -1, -1);
	this->BindObject(eBARRACKS_MAP, 31476, 128, 128, -1, -1);
	this->BindObject(eCALMNESS_MAP, 31477, 128, 128, -1, -1);
	this->BindObject(eRAKLION_MAP, 31478, 128, 128, -1, -1);
	this->BindObject(eVULCANUS_MAP, 31479, 128, 128, -1, -1);
	this->BindObject(eKALRUTAN_MAP, 31480, 128, 128, -1, -1);
	this->BindObject(eKALRUTAN2_MAP, 31481, 128, 128, -1, -1);
	this->BindObject(eNextCommand, 31659, 17, 18, -1, -1);
	this->BindObject(ePrevCommand, 31658, 17, 18, -1, -1);
	this->BindObject(eNextEvent, 31659, 17, 18, -1, -1);
	this->BindObject(ePrevEvent, 31658, 17, 18, -1, -1);
	this->BindObject(eCamera3DInit, 31659, 17, 18, -1, -1);
	this->BindObject(eCamera3DSwitch, 31659, 17, 18, -1, -1);
	//this->Data[eTIME].OnShow = true;
	if(gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		this->BindObject(ButtonSettings, 51522, 19, 19, -1, -1);
		this->BindObject(ButtonStart, 51522, 19, 19, -1, -1);
		this->BindObject(ButtonStop, 51522, 19, 19, -1, -1);
	}
	else
	{
		this->BindObject(ButtonSettings, 31761, 18, 13.3, -1, -1);
		this->BindObject(ButtonStart, 31762, 18, 13.3, -1, -1);
		this->BindObject(ButtonStop, 31763, 18, 13.3, -1, -1);
	}
	this->BindObject(ButtonStartAttack, 31593, 15, 15, -15, -15);
	//--
	this->BindObject(eJewelOfBank, 51522, 230.0, 270.0, -1, -1);
	this->BindObject(eJewelOfBankPush, 71521, 59, 28, -1, -1);
	this->BindObject(eJewelOfBankRemove, 71521, 59, 28, -1, -1);
	this->BindObject(eJewelOfBankClose, 71521, 59, 28, -1, -1);

	switch(gProtect.m_MainInfo.CustomInterfaceType)
	{
	case 1:
	case 2:
		//--
		if (gProtect.m_MainInfo.CustomMenuType == 1)
		{
			this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
		}
		else
		{
			this->BindObject(eMenu, 0x7906, 16, 12, -1, -1);
			this->BindObject(eMenuBG, 0x7907, 36, 18, 174, 0);
		}
		//--
		//this->BindObject(MINIMAP_FRAME, 31608, 154, 162, -10, 359);
		this->BindObject(MINIMAP_TIME_FRAME, 31609, 134.0, 37.0, -10, 359);
		this->BindObject(MINIMAP_BUTTOM, 31617, 38.0f, 24.0f, -10, 569);
		//---
		this->BindObject(eDragonLeft, 2337, 108.0, 45.0, 0.0, 385);
		this->BindObject(eDragonRight, 2336, 108.0, 45.0, 532.0, 385);
		this->BindObject(eParty, iNewParty, 25, 25, 348, 449);
		this->BindObject(eCharacter, iNewCharacter, 25, 25, 379, 449);
		this->BindObject(eInventory, iNewInventory, 25, 25, 409, 449);
		this->BindObject(eFriend, iNewWinpush, 52, 18, 581, 432);

		if(gProtect.m_MainInfo.CustomInterfaceType == 2)
		{
			this->BindObject(eFastMenu, iNewFastMenu, 53, 19, 5, 432);
		}
		this->BindObject(eGuild, iNewGuild, 52, 18, 581, 454);
		break;
	case 3:
	case 4:
		this->BindObject(eButton1, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton2, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton3, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton4, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton5, 61525, 43.0f, 17.0f, -43.0f, -17.0f);

		if (gProtect.m_MainInfo.CustomMenuType == 1)
		{
			this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
		}
		else
		{
			this->BindObject(eMenu, 51522, 19, 19, -1, -1);
			this->BindObject(eMenuBG, 51522, 36, 18, 174, 0);
		}
		//Ex700
		this->BindObject(chatbackground, 51545, 300.0f, 128.0f, -10, 569);
		this->BindObject(eShop, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eCharacter, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eInventory, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eQuest, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eCommunity, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eSystem, 51522, 19.5f, 19.5f, -1, -1);
		break;
	default:
		if (gProtect.m_MainInfo.CustomMenuType == 1)
		{
			this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
		}
		else
		{
			this->BindObject(eMenu, 0x7906, 16, 12, -1, -1);
			this->BindObject(eMenuBG, 0x7907, 36, 18, 174, 0);
		}
		break;
	}
	if(gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		this->BindObject(eMoney1, 0x7909, 75, 13, -1, -1);
		this->BindObject(eMoney2, 0x7910, 75, 13, -1, -1);
	}
	if(gProtect.m_MainInfo.DisableAdvance == 0)
	{
		gInterface.BindObject(eADVANCE_STAT_INFO, ex_INFO_2, 35, 30, -1, -1);
	}

#if (SELECTCHARACTER==1)
	SetCompleteHook(0xFF, 0x004D5EE6, &gSelectChar.SelectChar);
	gSelectChar.m_CharacterPage = 1;
#endif


	SetRange((LPVOID)0x00842086, 5, ASM::NOP);
	SetRange((LPVOID)0x0084234F, 5, ASM::NOP);
	SetRange((LPVOID)0x008423C3, 5, ASM::NOP);
	SetOp((LPVOID)oLoadSomeForm_Call, this->LoadImages, ASM::CALL);
	SetOp((LPVOID)oDrawInterface_Call, this->Work, ASM::CALL);



	if(gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		SetRange((LPVOID)0x00835116, 5, ASM::NOP);
		SetOp((LPVOID)0x00835116, this->DrawZenAndRud, ASM::CALL);
	}

	gJewelsBank.JewelsBankLoad();

	gTuChanInterface.loadBind();

	this->ClickTime = 0;
}

void Interface::DrawZenAndRud(int a1, int a2, int a3, int a4)
{
	int v10;
	int v11;
	DWORD v23;
	v10 = *(DWORD*)(a1 + 40);
	v11 = *(DWORD*)(a1 + 36);
	v23 = *(DWORD*)(*(DWORD*)0x8128AC4 + 5956);
	*(float*)(0x00D24E88); //Width

	char MoneyBuff1[50], MoneyBuff2[50], MoneyBuff3[50], MoneyBuff4[50], test[50];
	ZeroMemory(MoneyBuff1, sizeof(MoneyBuff1));
	ZeroMemory(MoneyBuff2, sizeof(MoneyBuff2));
	ZeroMemory(MoneyBuff3, sizeof(MoneyBuff3));
	ZeroMemory(MoneyBuff4, sizeof(MoneyBuff4));

	pGetMoneyFormat(v23, MoneyBuff1, 0);
	pGetMoneyFormat(Coin3, MoneyBuff2, 0);
	pGetMoneyFormat(Coin1, MoneyBuff3, 0);
	pGetMoneyFormat(Coin2, MoneyBuff4, 0);

	gInterface.DrawFormat(eWhite, v11, v10 + 12, 190, 3, pGetTextLine(pTextLineThis, 223));
	//--
	gInterface.DrawGUI(eMoney1, v11 + 18, v10 + 365);
	gInterface.DrawFormat(eBlack, v11 + 18, v10 + 367, 20, 1, "Zen");
	gInterface.DrawFormat(eRed, v11 + 40, v10 + 367, 50, 3, "%s", MoneyBuff1);
	//--
	gInterface.DrawGUI(eMoney2, v11 + 102, v10 + 365);
	gInterface.DrawFormat(eBlack, v11 + 102, v10 + 367, 20, 1, "GP");
	gInterface.DrawFormat(eWhite, v11 + 128, v10 + 367, 45, 4, "%s", MoneyBuff2);
	//--
	gInterface.DrawGUI(eMoney2, v11 + 18, v10 + 378);
	gInterface.DrawFormat(eBlack, v11 + 17, v10 + 380, 20, 1, "WC");
	gInterface.DrawFormat(eGold, v11 + 38, v10 + 381, 50, 4, "%s", MoneyBuff3);
	//--
	gInterface.DrawGUI(eMoney2, v11 + 102, v10 + 378);
	gInterface.DrawFormat(eBlack, v11 + 98, v10 + 380, 20, 1, "WCP");
	gInterface.DrawFormat(eBlue, v11 + 128, v10 + 381, 45, 4, "%s", MoneyBuff4);
}


void Interface::LoadModels()
{
	pLoadModel(406, "Data\\Custom\\Bmd\\VIP1\\", "musign", -1);
	pLoadTexture(406, "Custom\\Bmd\\VIP1\\", 0x2901, 0x2600, 1);
	pLoadModel(407, "Data\\Custom\\Bmd\\VIP2\\", "musign", -1);
	pLoadTexture(407, "Custom\\Bmd\\VIP2\\", 0x2901, 0x2600, 1);
	pLoadModel(408, "Data\\Custom\\Bmd\\VIP3\\", "musign", -1);
	pLoadTexture(408, "Custom\\Bmd\\VIP3\\", 0x2901, 0x2600, 1);
	// ----
	pInitModelData2();
}


void Interface::LoadImages()
{
	if(gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		pLoadImage("Custom\\Interface\\Money\\item_money.tga", 0x7909, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\Money\\item_money2.tga", 0x7910, 0x2601, 0x2901, 1, 0);
	}
	
	//
	pLoadImage("Custom\\Interface\\Rank01.tga", 0x7880, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank02.tga", 0x7881, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank03.tga", 0x7882, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank04.tga", 0x7883, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank05.tga", 0x7884, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank06.tga", 0x7885, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank07.tga", 0x7886, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank08.tga", 0x7887, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank09.tga", 0x7888, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank10.tga", 0x7889, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank11.tga", 0x7890, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank12.tga", 0x7891, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank13.tga", 0x7892, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank14.tga", 0x7893, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank15.tga", 0x7894, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank16.tga", 0x7895, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank17.tga", 0x7896, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank18.tga", 0x7897, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank19.tga", 0x7898, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank20.tga", 0x7899, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank21.tga", 0x7900, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank22.tga", 0x7901, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Ranking.tga", 0x7902, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Next.tga", 0x7903, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Previous.tga", 0x7904, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\MU-logo.tga", 0x7905, 0x2601, 0x2901, 1, 0);

	if (gProtect.m_MainInfo.CustomMenuType == 1)
	{
		pLoadImage("Custom\\Interface\\Menu1.tga", 0x7906, 0x2601, 0x2901, 1, 0);
	}
	else
	{
		pLoadImage("Custom\\Interface\\Menu2.tga", 0x7906, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\Menu_BG.tga", 0x7907, 0x2601, 0x2901, 1, 0);
	}
	pLoadImage("Custom\\Interface\\Button.tga", 0x7908, 0x2601, 0x2900,1,0);

	pLoadImage("Custom\\Interface\\NextMenu.tga", 0x7918, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\PreviousMenu.tga", 0x7913, GL_LINEAR, GL_CLAMP, 1, 0);

	pLoadImage("Custom\\Interface\\LuckyWheel\\itembackpanel.tga", 0x9326, 0x2601, 0x2900, 1, 0);
//	pLoadImage("Custom\\Interface\\LuckyWheel\\topmenutabbt1.tga", 0x9327, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\LuckyWheel\\ui_dialog_e.tga", 0x9328, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\LuckyWheel\\Nut_XoaHomDo.tga", 0x9327, 0x2601, 0x2900, 1, 0);

	
#if (SELECTCHARACTER==1)
	pLoadImage("Custom\\Interface\\Next.tga", 0x7911, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Previous.tga", 0x7912, 0x2601, 0x2901, 1, 0);
#endif

	pLoadImage("Custom\\RankUser\\Vip\\vip1.tga", 32891, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankUser\\Vip\\vip2.tga", 32892, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankUser\\Vip\\vip3.tga", 32893, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankUser\\Vip\\vip4.tga", 32894, 0x2601, 0x2901, 1, 0);


	pLoadImage("Custom\\RankUser\\Rangos\\Main.tga", 0x0899, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\Successful.tga", 0x0898, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\Progress.tga", 0x0897, 0x2601, 0x2901, 1, 0);
	//==============================================
	//==============================================
	pLoadImage("Custom\\RankUser\\Rangos\\1Guardian\\1.tga", 10100, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\2Pionero\\1.tga", 10200, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\3Audaz\\1.tga", 10300, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\4Castigador\\1.tga", 10400, 0x2601, 0x2900, 1, 0);
	
	//==============================================
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(1).tga", 10500, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(2).tga", 10501, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(3).tga", 10502, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(4).tga", 10503, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(5).tga", 10504, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(6).tga", 10505, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(7).tga", 10506, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(8).tga", 10507, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(9).tga", 10508, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(10).tga", 10509, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(11).tga", 10510, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(12).tga", 10511, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(13).tga", 10512, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(14).tga", 10513, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(15).tga", 10514, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(16).tga", 10515, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(17).tga", 10516, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(18).tga", 10517, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(19).tga", 10518, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(20).tga", 10519, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(21).tga", 10520, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(22).tga", 10521, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(23).tga", 10522, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(24).tga", 10523, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(25).tga", 10524, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(26).tga", 10525, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(27).tga", 10526, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(28).tga", 10527, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(29).tga", 10528, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(30).tga", 10529, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(31).tga", 10530, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(32).tga", 10531, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(33).tga", 10532, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(34).tga", 10533, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(35).tga", 10534, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(36).tga", 10535, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(37).tga", 10536, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(38).tga", 10537, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(39).tga", 10538, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\5Capturador\\(40).tga", 10539, 0x2601, 0x2900, 1, 0);

	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(1).tga", 10600, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(2).tga", 10601, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(3).tga", 10602, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(4).tga", 10603, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(5).tga", 10604, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(6).tga", 10605, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(7).tga", 10606, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(8).tga", 10607, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(9).tga", 10608, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(10).tga", 10609, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(11).tga", 10610, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(12).tga", 10611, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(13).tga", 10612, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(14).tga", 10613, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(15).tga", 10614, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(16).tga", 10615, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(17).tga", 10616, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(18).tga", 10617, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(19).tga", 10618, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(20).tga", 10619, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(21).tga", 10620, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(22).tga", 10621, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(23).tga", 10622, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(24).tga", 10623, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(25).tga", 10624, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(26).tga", 10625, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(27).tga", 10626, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(28).tga", 10627, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(29).tga", 10628, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(30).tga", 10629, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(31).tga", 10630, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(32).tga", 10631, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(33).tga", 10632, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(34).tga", 10633, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(35).tga", 10634, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(36).tga", 10635, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(37).tga", 10636, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(38).tga", 10637, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(39).tga", 10638, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\6Altisimo\\(40).tga", 10639, 0x2601, 0x2900, 1, 0);
	//==============================================
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(1).tga", 10700, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(2).tga", 10701, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(3).tga", 10702, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(4).tga", 10703, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(5).tga", 10704, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(6).tga", 10705, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(7).tga", 10706, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(8).tga", 10707, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(9).tga", 10708, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(10).tga", 10709, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(11).tga", 10710, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(12).tga", 10711, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(13).tga", 10712, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(14).tga", 10713, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(15).tga", 10714, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(16).tga", 10715, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(17).tga", 10716, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(18).tga", 10717, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(19).tga", 10718, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(20).tga", 10719, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(21).tga", 10720, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(22).tga", 10721, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(23).tga", 10722, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(24).tga", 10723, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(25).tga", 10724, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(26).tga", 10725, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(27).tga", 10726, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(28).tga", 10727, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(29).tga", 10728, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(30).tga", 10729, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(31).tga", 10730, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(32).tga", 10731, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(33).tga", 10732, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(34).tga", 10733, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(35).tga", 10734, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(36).tga", 10735, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(37).tga", 10736, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(38).tga", 10737, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(39).tga", 10738, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\7Silver\\(40).tga", 10739, 0x2601, 0x2900, 1, 0);
	
pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(1).tga", 10800, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(2).tga", 10801, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(3).tga", 10802, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(4).tga", 10803, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(5).tga", 10804, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(6).tga", 10805, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(7).tga", 10806, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(8).tga", 10807, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(9).tga", 10808, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(10).tga", 10809, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(11).tga", 10810, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(12).tga", 10811, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(13).tga", 10812, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(14).tga", 10813, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(15).tga", 10814, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(16).tga", 10815, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(17).tga", 10816, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(18).tga", 10817, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(19).tga", 10818, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(20).tga", 10819, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(21).tga", 10820, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(22).tga", 10821, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(23).tga", 10822, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(24).tga", 10823, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(25).tga", 10824, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(26).tga", 10825, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(27).tga", 10826, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(28).tga", 10827, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(29).tga", 10828, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(30).tga", 10829, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(31).tga", 10830, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(32).tga", 10831, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(33).tga", 10832, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(34).tga", 10833, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(35).tga", 10834, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(36).tga", 10835, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(37).tga", 10836, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(38).tga", 10837, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(39).tga", 10838, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\8Bronce\\(40).tga", 10839, 0x2601, 0x2900, 1, 0);
	
pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(1).tga", 10900, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(2).tga", 10901, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(3).tga", 10902, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(4).tga", 10903, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(5).tga", 10904, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(6).tga", 10905, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(7).tga", 10906, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(8).tga", 10907, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(9).tga", 10908, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(10).tga", 10909, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(11).tga", 10910, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(12).tga", 10911, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(13).tga", 10912, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(14).tga", 10913, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(15).tga", 10914, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(16).tga", 10915, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(17).tga", 10916, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(18).tga", 10917, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(19).tga", 10918, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(20).tga", 10919, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(21).tga", 10920, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(22).tga", 10921, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(23).tga", 10922, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(24).tga", 10923, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(25).tga", 10924, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(26).tga", 10925, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(27).tga", 10926, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(28).tga", 10927, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(29).tga", 10928, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(30).tga", 10929, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(31).tga", 10930, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(32).tga", 10931, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(33).tga", 10932, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(34).tga", 10933, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(35).tga", 10934, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(36).tga", 10935, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(37).tga", 10936, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(38).tga", 10937, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(39).tga", 10938, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\9Destructor\\(40).tga", 10939, 0x2601, 0x2900, 1, 0);
	
pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(1).tga", 11000, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(2).tga", 11001, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(3).tga", 11002, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(4).tga", 11003, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(5).tga", 11004, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(6).tga", 11005, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(7).tga", 11006, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(8).tga", 11007, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(9).tga", 11008, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(10).tga", 11009, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(11).tga", 11010, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(12).tga", 11011, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(13).tga", 11012, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(14).tga", 11013, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(15).tga", 11014, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(16).tga", 11015, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(17).tga", 11016, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(18).tga", 11017, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(19).tga", 11018, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(20).tga", 11019, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(21).tga", 11020, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(22).tga", 11021, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(23).tga", 11022, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(24).tga", 11023, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(25).tga", 11024, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(26).tga", 11025, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(27).tga", 11026, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(28).tga", 11027, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(29).tga", 11028, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(30).tga", 11029, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(31).tga", 11030, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(32).tga", 11031, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(33).tga", 11032, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(34).tga", 11033, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(35).tga", 11034, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(36).tga", 11035, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(37).tga", 11036, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(38).tga", 11037, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(39).tga", 11038, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\10Conquistador\\(40).tga", 11039, 0x2601, 0x2900, 1, 0);
	
pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(1).tga", 11100, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(2).tga", 11101, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(3).tga", 11102, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(4).tga", 11103, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(5).tga", 11104, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(6).tga", 11105, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(7).tga", 11106, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(8).tga", 11107, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(9).tga", 11108, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(10).tga", 11109, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(11).tga", 11110, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(12).tga", 11111, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(13).tga", 11112, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(14).tga", 11113, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(15).tga", 11114, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(16).tga", 11115, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(17).tga", 11116, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(18).tga", 11117, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(19).tga", 11118, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(20).tga", 11119, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(21).tga", 11120, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(22).tga", 11121, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(23).tga", 11122, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(24).tga", 11123, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(25).tga", 11124, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(26).tga", 11125, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(27).tga", 11126, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(28).tga", 11127, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(29).tga", 11128, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(30).tga", 11129, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(31).tga", 11130, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(32).tga", 11131, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(33).tga", 11132, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(34).tga", 11133, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(35).tga", 11134, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(36).tga", 11135, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(37).tga", 11136, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(38).tga", 11137, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(39).tga", 11138, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\11Dominador\\(40).tga", 11139, 0x2601, 0x2900, 1, 0);
	
pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(1).tga", 11200, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(2).tga", 11201, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(3).tga", 11202, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(4).tga", 11203, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(5).tga", 11204, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(6).tga", 11205, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(7).tga", 11206, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(8).tga", 11207, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(9).tga", 11208, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(10).tga", 11209, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(11).tga", 11210, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(12).tga", 11211, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(13).tga", 11212, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(14).tga", 11213, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(15).tga", 11214, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(16).tga", 11215, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(17).tga", 11216, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(18).tga", 11217, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(19).tga", 11218, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(20).tga", 11219, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(21).tga", 11220, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(22).tga", 11221, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(23).tga", 11222, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(24).tga", 11223, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(25).tga", 11224, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(26).tga", 11225, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(27).tga", 11226, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(28).tga", 11227, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(29).tga", 11228, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(30).tga", 11229, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(31).tga", 11230, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(32).tga", 11231, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(33).tga", 11232, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(34).tga", 11233, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(35).tga", 11234, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(36).tga", 11235, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(37).tga", 11236, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(38).tga", 11237, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(39).tga", 11238, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\12Salvador\\(40).tga", 11239, 0x2601, 0x2900, 1, 0);
	
pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(1).tga", 11300, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(2).tga", 11301, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(3).tga", 11302, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(4).tga", 11303, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(5).tga", 11304, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(6).tga", 11305, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(7).tga", 11306, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(8).tga", 11307, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(9).tga", 11308, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(10).tga", 11309, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(11).tga", 11310, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(12).tga", 11311, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(13).tga", 11312, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(14).tga", 11313, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(15).tga", 11314, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(16).tga", 11315, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(17).tga", 11316, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(18).tga", 11317, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(19).tga", 11318, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(20).tga", 11319, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(21).tga", 11320, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(22).tga", 11321, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(23).tga", 11322, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(24).tga", 11323, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(25).tga", 11324, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(26).tga", 11325, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(27).tga", 11326, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(28).tga", 11327, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(29).tga", 11328, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(30).tga", 11329, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(31).tga", 11330, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(32).tga", 11331, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(33).tga", 11332, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(34).tga", 11333, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(35).tga", 11334, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(36).tga", 11335, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(37).tga", 11336, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(38).tga", 11337, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(39).tga", 11338, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\13Laguna\\(40).tga", 11339, 0x2601, 0x2900, 1, 0);
	
pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(1).tga", 11400, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(2).tga", 11401, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(3).tga", 11402, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(4).tga", 11403, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(5).tga", 11404, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(6).tga", 11405, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(7).tga", 11406, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(8).tga", 11407, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(9).tga", 11408, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(10).tga", 11409, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(11).tga", 11410, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(12).tga", 11411, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(13).tga", 11412, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(14).tga", 11413, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(15).tga", 11414, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(16).tga", 11415, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(17).tga", 11416, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(18).tga", 11417, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(19).tga", 11418, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(20).tga", 11419, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(21).tga", 11420, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(22).tga", 11421, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(23).tga", 11422, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(24).tga", 11423, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(25).tga", 11424, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(26).tga", 11425, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(27).tga", 11426, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(28).tga", 11427, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(29).tga", 11428, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(30).tga", 11429, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(31).tga", 11430, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(32).tga", 11431, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(33).tga", 11432, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(34).tga", 11433, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(35).tga", 11434, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(36).tga", 11435, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(37).tga", 11436, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(38).tga", 11437, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(39).tga", 11438, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\14Exterminador\\(40).tga", 11439, 0x2601, 0x2900, 1, 0);
	//==============================================
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(1).tga", 11500, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(2).tga", 11501, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(3).tga", 11502, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(4).tga", 11503, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(5).tga", 11504, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(6).tga", 11505, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(7).tga", 11506, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(8).tga", 11507, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(9).tga", 11508, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(10).tga", 11509, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(11).tga", 11510, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(12).tga", 11511, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(13).tga", 11512, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(14).tga", 11513, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(15).tga", 11514, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(16).tga", 11515, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(17).tga", 11516, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(18).tga", 11517, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(19).tga", 11518, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(20).tga", 11519, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(21).tga", 11520, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(22).tga", 11521, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(23).tga", 11522, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(24).tga", 11523, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(25).tga", 11524, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(26).tga", 11525, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(27).tga", 11526, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(28).tga", 11527, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(29).tga", 11528, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(30).tga", 11529, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(31).tga", 11530, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(32).tga", 11531, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(33).tga", 11532, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(34).tga", 11533, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(35).tga", 11534, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(36).tga", 11535, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(37).tga", 11536, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(38).tga", 11537, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(39).tga", 11538, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\15Hanshinkan\\(40).tga", 11539, 0x2601, 0x2900, 1, 0);
	
pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(1).tga", 11600, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(2).tga", 11601, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(3).tga", 11602, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(4).tga", 11603, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(5).tga", 11604, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(6).tga", 11605, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(7).tga", 11606, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(8).tga", 11607, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(9).tga", 11608, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(10).tga", 11609, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(11).tga", 11610, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(12).tga", 11611, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(13).tga", 11612, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(14).tga", 11613, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(15).tga", 11614, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(16).tga", 11615, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(17).tga", 11616, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(18).tga", 11617, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(19).tga", 11618, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(20).tga", 11619, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(21).tga", 11620, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(22).tga", 11621, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(23).tga", 11622, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(24).tga", 11623, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(25).tga", 11624, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(26).tga", 11625, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(27).tga", 11626, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(28).tga", 11627, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(29).tga", 11628, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(30).tga", 11629, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(31).tga", 11630, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(32).tga", 11631, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(33).tga", 11632, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(34).tga", 11633, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(35).tga", 11634, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(36).tga", 11635, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(37).tga", 11636, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(38).tga", 11637, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(39).tga", 11638, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankUser\\Rangos\\16Creador\\(40).tga", 11639, 0x2601, 0x2900, 1, 0);


		pLoadImage("Custom\\RankUser\\Titulos\\1.tga", 50000, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\2.tga", 50001, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\3.tga", 50002, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\4.tga", 50003, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\5.tga", 50004, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\6.tga", 50005, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\7.tga", 50006, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\8.tga", 50007, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\9.tga", 50008, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\10.tga", 50009, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\11.tga", 50010, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\12.tga", 50011, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\13.tga", 50012, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\14.tga", 50013, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\15.tga", 50014, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\16.tga", 50015, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\17.tga", 50016, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\18.tga", 50017, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\19.tga", 50018, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\20.tga", 50019, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\21.tga", 50020, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\22.tga", 50021, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\23.tga", 50022, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\24.tga", 50023, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\25.tga", 50024, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\26.tga", 50025, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\27.tga", 50026, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\28.tga", 50027, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\29.tga", 50028, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\30.tga", 50029, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\31.tga", 50030, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\32.tga", 50031, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\33.tga", 50032, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\34.tga", 50033, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\35.tga", 50034, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\36.tga", 50035, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\37.tga", 50036, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\38.tga", 50037, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\39.tga", 50038, 0x2601, 0x2900, 1, 0);
						
		pLoadImage("Custom\\RankUser\\Titulos\\40.tga",  50041, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_1.tga",50042, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_2.tga",50043, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_3.tga",50044, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_4.tga",50045, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_5.tga",50046, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_6.tga",50047, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_7.tga",50048, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_8.tga",50049, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_9.tga",50050, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_10.tga",50051, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_11.tga",50052, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_12.tga",50053, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_13.tga",50054, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_14.tga",50055, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_15.tga",50056, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_16.tga",50057, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_17.tga",50058, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_18.tga",50059, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_19.tga",50060, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_20.tga",50061, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_21.tga",50062, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_22.tga",50063, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_23.tga",50064, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_24.tga",50065, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_25.tga",50066, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_26.tga",50067, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankUser\\Titulos\\40_27.tga",50068, 0x2601, 0x2900, 1, 0);

		// AutoLogin / Register
	LoadBitmapA("Custom\\Desig\\login_auto.tga", 531141, GL_NEAREST, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\login_auto.tga", 531141, GL_NEAREST, GL_CLAMP, 1, 0);
    LoadBitmapA("Custom\\Desig\\Login.tga", 71621, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\1.tga", 71622, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\2.tga", 71623, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\3.tga", 71624, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\4.tga", 71625, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\5.tga", 71626, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\6.tga", 71627, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\8.tga", 71629, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\9.tga", 71630, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\10.tga", 71630, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\login_back.tga", 71631, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\reloadcap.jpg", 71632, GL_LINEAR, GL_CLAMP, 1, 0);


	pLoadImage("Custom\\Interface\\Info.tga", 0x7915, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\Info2.tga", 0x7916, 0x2601, 0x2900, 1, 0);


	//MiniMap
		pLoadImage("Custom\\Maps\\PlayerPoint.jpg", 31460, 0x2600, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\none.tga", 31461, 0x2601, 0x2900, 1, 0);
	//--
	//--Interface MiniMap 97/99/S2/S6
	if(MiniMapType == 0)
	{
	pLoadImage("Custom\\Maps\\edBtUcx_old.tga", 31463, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\timeold.tga", 31458, 0x2601, 0x2900, 1, 0); //-- Dungeon
	}
	//--Interface MiniMap ex700/Legends
	if(MiniMapType == 1)
	{
	pLoadImage("Custom\\Maps\\edBtUcx.tga", 31463, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\time700.tga", 31458, 0x2601, 0x2900, 1, 0); //-- Dungeon
	}
	//--
	pLoadImage("Custom\\Maps\\edBtUcx_2.tga", 31464, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\edBtUcx_1.tga", 31459, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\YYB6BUk.tga", 31465, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_blacksmith.tga", 31466, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_Potion.tga", 31467, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_baul.tga", 31468, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_Que.tga", 31469, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_monsterred.tga", 31471, 0x2601, 0x2900, 1, 0); //-- Dungeon Red
	pLoadImage("Custom\\Maps\\mini_map_ui_monsterblue.tga", 31472, 0x2601, 0x2900, 1, 0); //-- Dungeon Blue
	pLoadImage("Custom\\Maps\\mini_map_ui_monstergold.tga", 31473, 0x2601, 0x2900, 1, 0); //-- Dungeon Gold


	pLoadImage("Interface\\mini_map_ui_party.tga", 61520, 0x2601, 0x2901, 1, 0); //esquina abajo derecha

	gAchievements.LoadImages();

	if(gProtect.m_MakeViewTRSData.TooltipS15 == 1)
	{
		//-- itemtooltip
		pLoadImage("Interface\\GFx\\tooltip_bg01.tga", 61511, 0x2601, 0x2901, 1, 0); //esquina arriba izquierda
		pLoadImage("Interface\\GFx\\tooltip_bg02.tga", 61512, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg03.tga", 61513, 0x2601, 0x2901, 1, 0); //esquina arriba derecha
		pLoadImage("Interface\\GFx\\tooltip_bg04.tga", 61514, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg06.tga", 61515, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg07.tga", 61516, 0x2601, 0x2901, 1, 0); //esquina abajo izquierda
		pLoadImage("Interface\\GFx\\tooltip_bg08.tga", 61517, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg09.tga", 61518, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	}
	//-- itemtooltip
	pLoadImage("Interface\\GFx\\popupbg01.tga", 71511, 0x2601, 0x2901, 1, 0); //esquina arriba izquierda
	pLoadImage("Interface\\GFx\\popupbg02.tga", 71512, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg03.tga", 71513, 0x2601, 0x2901, 1, 0); //esquina arriba derecha
	pLoadImage("Interface\\GFx\\popupbg04.tga", 71514, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg06.tga", 71515, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg07.tga", 71516, 0x2601, 0x2901, 1, 0); //esquina abajo izquierda
	pLoadImage("Interface\\GFx\\popupbg08.tga", 71517, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg09.tga", 71518, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	pLoadImage("Interface\\GFx\\popup_line_m.tga", 71519, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\popup_line_s.tga", 71520, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	pLoadImage("Interface\\GFx\\Render_buttom_1.tga", 71521, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\Render_buttom_2.tga", 71522, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\Render_buttom_3.tga", 71524, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	pLoadImage("Interface\\GFx\\RenderBits_Sound.tga", 71523, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\newui_option_volume01.tga", 31596, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\newui_option_volume02.tga", 31597, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	pLoadImage("Custom\\Party\\newui_Party_Back.tga", 81520, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\newui_Party_flag.tga", 81521, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\newui_Party_HpBar.jpg", 81522, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\newui_Party_ManaBar.jpg", 81523, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\newui_Party_X.tga", 81524, 0x2601, 0x2901, 1, 0);
	
	//-
	LoadBitmapA("Interface\\newui_number1.tga", 31337, 9729, 10496, 1, 0);

	LoadBitmapA("Interface\\newui_SW_Minimap_Frame.tga", 31608, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\newui_SW_Time_Frame.tga", 31609, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\newui_SW_MiniMap_Bt_clearness.jpg", 31617, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\InventoryFrame_RuudShop.tga", 61560, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Menu_RuudShopFrame.tga", 61561, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Menu_Button03.tga", 61562, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);


	//
	switch(gProtect.m_MainInfo.CustomInterfaceType) 
	{
	case 1:
	case 2:
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Item_Back01.tga", 61522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Frame_I3.tga", 51522, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\DragonRight.tga", 2336, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\DragonLeft.tga", 2337, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		if(gProtect.m_MainInfo.CustomInterfaceType == 1)
		{
			LoadBitmapA("Custom\\InterfaceS2\\Menu_left97.jpg", 31292, GL_LINEAR, GL_CLAMP, 1, 0); //replace
			LoadBitmapA("Custom\\Interface\\none.tga", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		}else
		{
			LoadBitmapA("Custom\\InterfaceS2\\Menu_left.jpg", 31292, GL_LINEAR, GL_CLAMP, 1, 0); //replace
			LoadBitmapA("Custom\\InterfaceS2\\Menu_SD.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		}
		
		LoadBitmapA("Custom\\InterfaceS2\\Menu_right.jpg", 31294, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_middle.jpg", 31293, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Red.jpg", 0x7A42, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Green.jpg", 0x7A41, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Blue.jpg", 0x7A40, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_AG.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_fastmenu.jpg", iNewFastMenu, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Inventory.jpg", iNewInventory, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Character.jpg", iNewCharacter, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Party.jpg", iNewParty, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_friend.jpg", iNewWinpush, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_guild.jpg", iNewGuild, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\skillboxR.jpg", 0x700003, 0x2601, 0x2901, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill.jpg", 31308, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill2.jpg", 31309, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill3.jpg", 31311, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_command.jpg", 31310, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill.jpg", 31314, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill2.jpg", 31315, GL_LINEAR, GL_CLAMP, 1, 0); 
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill3.jpg", 31317, GL_LINEAR, GL_CLAMP, 1, 0); 
		//--
		LoadBitmapA("Custom\\InterfaceS2\\newui_skillbox.jpg", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skillbox2.jpg", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		//Interface Character
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Stats.jpg", 31352, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\StatsDL.jpg", 51291, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Stats2.jpg", 51292, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Level_box.jpg", 35353, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Level_button.jpg", 51290, GL_LINEAR, GL_CLAMP, 1, 0);
		//-- chat
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_vframe.jpg", 51551, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe.tga", 51552, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_up.jpg", 51553, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_m.jpg", 51554, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_down.jpg", 51555, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_hframe.jpg", 31275, 9729, 10496, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue1.tga", 51530, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue2.tga", 51531, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue2_1.jpg", 51532, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);
		goto LOAD_GFX;
	case 3:
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I1.tga", 61522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I2.tga", 61523, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I3.tga", 61524, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Frame_I3.tga", 61526, GL_LINEAR, GL_CLAMP, 1, 0); //-- All Window
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I4.tga", 61527, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Draw_money.tga", 61528, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\button_close.tga", 61529, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\CharacterInfoFrame_I1.tga", 61532, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_chainfo_btn_level.tga", 61533, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ButtonCharacterInfo.tga", 61535, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\CharacterInfoFrame_I2.tga", 61538, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\BaulFrame_I1.tga", 61539, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\BaulFrame_I2.tga", 61540, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ShopFrame_I1.tga", 61541, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newSytemButton.tga", 61542, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ShopFrame_I2.tga", 61543, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\StoreFrame_I1.tga", 61544, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\Main_IE.tga", 31293, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_IE_Exp.tga", 59000, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I1.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I4.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I5.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_skillbox2.tga", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_skillbox.tga", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_Skillbox.tga", 51500, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("Interface\\GFx\\ex700\\guege_mp.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_mp_1.tga", 51501, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp_green.tga", 31297, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp_1.tga", 51502, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);
		goto LOAD_GFX;
	case 4:
		LoadBitmapA("Interface\\GFx\\Legends\\Main_IE.tga", 31293, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_I3.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_mp.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_mp_1.tga", 51501, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp_green.tga", 31297, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp_1.tga", 51502, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("Interface\\GFx\\Legends\\Main_I5.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_I4.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\Legends\\newui_skillbox2.tga", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\newui_skillbox.tga", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_Skillbox.tga", 51500, GL_LINEAR, GL_CLAMP, 1, 0);
LOAD_GFX:
		LoadBitmapA("Interface\\GFx\\Buttom_empty_small.tga", 61525, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\newui_number1.tga", 6829, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg01.tga", 61550, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg02.tga", 61551, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg03.tga", 61534, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Chat_I5.tga", 61548, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\newui_chat_back.tga", 61549, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Main_IE_Buttons.tga", 0x901, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\skill_render.tga", 61546, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\item_pbtnbg.tga", 61547, GL_LINEAR, GL_CLAMP, 1, 0);
		//-- Folder MacroUI
		//LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Main.tga", 51550, GL_LINEAR, GL_CLAMP, 1, 0);//vieja
		pLoadImage("Interface\\GFx\\MacroUI\\MacroUI_I1.tga", 0xF3001, 0x2601, 0x2900, 1, 0);//nueva

		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_BSetup.tga", 51546, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_BStart.tga", 51547, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Stop.tga", 51548, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Bar.jpg", 51549, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Menu.tga", 51553, GL_LINEAR, GL_CLAMP, 1, 0);
		//-- Botones del Main
		LoadBitmapA("Custom\\Interface\\none.tga", 31303, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31304, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31305, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31306, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31307, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\Frame_I3.tga", 51522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31294, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31292, GL_LINEAR, GL_CLAMP, 1, 0);
		
		LoadBitmapA("Interface\\GFx\\ex700\\newSytemButton.tga", 61542, GL_LINEAR, GL_CLAMP, 1, 0);
		break;
	}
	LoadBitmapA("Custom\\Interface\\TimeBar.tga", 0x787F, 0x2601, 0x2901, 1, 0);

	if( gProtect.m_MainInfo.DisableEffectRemake == 0 )
	{
		pLoadImage("Effect\\flare01.jpg", 52002, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flareRed.jpg", 52230, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\JointLaser01.jpg", 52224, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\hikorora.jpg", 52379, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flareBlue.jpg", 52229, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\bostar3_R.jpg", 32614, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\line_of_big_R.jpg", 32772, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flare01.jpg", 42134, GL_LINEAR, GL_REPEAT, 1, 0);
	}
	//--

	g_ExWinQuestSystem.ImageLoad();

	if(gProtect.m_MainInfo.DisableCustomCloack == 0)
	{
		gCloak.LoadTexture();
	}

	if(gProtect.m_MainInfo.DisableEmojiSystem == 0)
	{
		gEmojis.LoadImages();
	}
	//--
	pLoadSomeForm();
}

void Interface::BindObject(short MonsterID, DWORD ModelID, float Width, float Height, float X, float Y)
{
	this->Data[MonsterID].EventTick	= 0;
	this->Data[MonsterID].OnClick	= false;
	this->Data[MonsterID].OnShow	= false;
	this->Data[MonsterID].ModelID	= ModelID;
	this->Data[MonsterID].Width		= Width;
	this->Data[MonsterID].Height	= Height;
	this->Data[MonsterID].X			= X;
	this->Data[MonsterID].Y			= Y;
	this->Data[MonsterID].MaxX		= X + Width;
	this->Data[MonsterID].MaxY		= Y + Height;
	this->Data[MonsterID].Attribute	= 0;
}

void Interface::DrawGUI(short ObjectID, float PosX, float PosY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= PosX;
		this->Data[ObjectID].Y		= PosY;
		this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;
	}

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawGUI2(short ObjectID, float PosX, float PosY)
{
	this->Data[ObjectID].X		= PosX;
	this->Data[ObjectID].Y		= PosY;
	this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawGUI3(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	this->Data[ObjectID].X		= PosX;
	this->Data[ObjectID].Y		= PosY;
	this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;

	RenderBitmap(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height,0,0,ScaleX,ScaleY,1,1,0);
}

void Interface::DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= PosX;
		this->Data[ObjectID].Y		= PosY;
		this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;
	}

	RenderBitmap(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height,0,0,ScaleX,ScaleY,1,1,0);
}

void Interface::ResetDrawIMG(short ObjectID)
{
	if( this->Data[ObjectID].X != -1 || this->Data[ObjectID].Y != -1 )
	{
		this->Data[ObjectID].X		= -1;
		this->Data[ObjectID].Y		= -1;
		this->Data[ObjectID].MaxX	= -1;
		this->Data[ObjectID].MaxY	= -1;
	}
}

void Interface::ResetDrawIMG2(short ObjectID)
{
		this->Data[ObjectID].X		= -1;
		this->Data[ObjectID].Y		= -1;
		this->Data[ObjectID].MaxX	= -1;
		this->Data[ObjectID].MaxY	= -1;
}

void Interface::Work()
{
	gObjUser.Refresh();

	gInterface.WindowsProTecno();

	jCRenderRuud.CheckOpen();
	
	if(gObjUser.lpViewPlayer->WeaponFirstSlot >= ITEM2(4,0) && gObjUser.lpViewPlayer->WeaponFirstSlot <= ITEM2(4,255)
		||gObjUser.lpViewPlayer->WeaponSecondSlot >= ITEM2(4,0) && gObjUser.lpViewPlayer->WeaponSecondSlot <= ITEM2(4,255))
	{
		gInterface.PetY = 38.0f;
		
	}
	else
	{
		gInterface.PetY = 26.0f;
	}

	if(gObjUser.lpViewPlayer->PetSlot!= -1)
	{
		gInterface.PetX = 61.0f;
	}else
	{
		gInterface.PetX = 0;
	}

	if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{	gInterface.DrawInterfaceDragonLS3();
		gInterface.DrawInterfaceDragonRS3();
	}

	gInterface.DrawMiniMap();

	gInterface.DrawTimeUI();

	gAchievements.Draw();

	gInterface.DrawPartySearchWindow();
	gInterface.DrawPartySettingsWindow();
	gInterface.DrawVaultWindow();
	gInterface.DrawChangingClassWindow();
	gInterface.DrawLuckyWheel();
	gInterface.DrawChangeResetWindow();
	gInterface.DrawSmithItem();
	gJewelsBank.Draw();

	gCustomRanking.DrawRankPanelWindow();

	gCustomEventTime.DrawEventTimePanelWindow();
	
	ReconnectMainProc();

	gInterface.DrawVipWindow();

	gInterface.DrawMenu();

	gInterface.DrawMenuOpen();

	gInterface.DrawMenuOpenTwo();

	gCustomCommandInfo.DrawCommandWindow();

	gInterface.DrawConfirmOpen();

	G_BEXO_DANH_HIEU.DRAW_DANH_HIEU();

	G_BEXO_MUA_VIP.DRAW_MUA_VIP();

	g_ExWinQuestSystem.DrawMiniInfo();

	g_ExWinQuestSystem.Draw();

	gTuChanInterface.DrawTuChanWindow();

	if(gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		gInterface.DrawInterfaceCustom();
	}

	pDrawInterface();


	if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		
		if(gProtect.m_MainInfo.CustomInterfaceType == 1)
		{
			gInterface.DrawInterface97Menu();
		}
		if(gProtect.m_MainInfo.CustomInterfaceType == 2)
		{
			gInterface.DrawInterfaceS2Menu();
		}
	}

	if( GetForegroundWindow() == pGameWindow )
	{
		if (GetKeyState(VK_SNAPSHOT) < 0) 
		{
			gInterface.DrawLogo(1); 
		}
		if (GetKeyState(VK_END) & 0x4000) 
		{
			if((GetTickCount()-gInterface.Data[eVip_MAIN].EventTick) > 300)
			{
				if (gInterface.CheckVipWindow())
				{
					gInterface.Data[eVip_MAIN].EventTick = GetTickCount();
					gInterface.CloseVipWindow();
				}
				else
				{
					gInterface.Data[eVip_MAIN].EventTick = GetTickCount();
					gInterface.CloseCustomWindow();
					gInterface.OpenVipWindow();
				}
			}
		}

		//if (GetKeyState('K') & 0x4000) 
		//{
		//	gAchievements.CGWindowOpen();
		//}

		if (GetKeyState('H') & 0x4000) 
		{
			gCustomEventTime.OpenWindow();
		}
		if (GetKeyState('O') & 0x4000) 
		{
			gInterface.OpenConfig(0);
		}
		if (GetKeyState(VK_UP) & 0x4000) 
		{
			gInterface.OpenConfig(1);
		}
		else if (GetKeyState(VK_DOWN) & 0x4000) 
		{
			gInterface.OpenConfig(1);
		}
		//if (GetKeyState('J') & 0x4000) 
		//{
		//}
		if (GetKeyState(VK_F6) & 0x4000) 
		{
			gInterface.SwitchChatExpand();
		}
		if (GetKeyState(VK_F8) & 0x4000) 
		{
			gCustomRanking.OpenWindow();
		}
		if (GetKeyState(VK_F10) & 0x4000) 
		{
			gInterface.SwitchCamera();
		}
		if (GetKeyState(VK_F11) & 0x4000) 
		{
			gInterface.CameraInit();
		}
		if (GetKeyState(VK_F12) & 0x4000) 
		{
			if( gTrayMode.TempWindowProc == NULL )
			{
				gTrayMode.TempWindowProc = SetWindowLong(pGameWindow, GWL_WNDPROC, (long)gController.Window);
			}
			// ----
			gTrayMode.SwitchState();
		}
		if (GetKeyState(VK_ESCAPE) < 0) 
		{
			if (gInterface.Data[eCommand_MAIN].OnShow == true)
			{
				gInterface.Data[eCommand_MAIN].OnShow = false;
				
				if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}

			if (gInterface.Data[eRankPANEL_MAIN].OnShow == true)
			{
				gInterface.Data[eRankPANEL_MAIN].OnShow = false;
				
				if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}

			if (gInterface.Data[eEventTimePANEL_MAIN].OnShow == true)
			{
				gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
				
				if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}

			if (gInterface.CheckVipWindow())
			{
				gInterface.CloseVipWindow();
			}

			if (gInterface.CheckMenuWindow())
			{
				gInterface.CloseMenuWindow();
			}

			if (gInterface.CheckMenuWindowTwo())
			{
				gInterface.CloseMenuWindowTwo();
			}

			if (gInterface.CheckVaultWindow())
			{
				gInterface.CloseVaultWindow();
			}

			if (gTuChanInterface.CheckTuChanWindow())
			{
				gTuChanInterface.CloseTuChanWindow();
			}

			if (gInterface.Data[eSMITH_MAIN].OnShow == true)
			{
				gInterface.Data[eSMITH_MAIN].OnShow = false;
				pSetCursorFocus = false;
		    }

			if (gInterface.Data[eJEWELBANK_MAIN].OnShow == true)
			{
				gInterface.Data[eJEWELBANK_MAIN].OnShow = false;
				pSetCursorFocus = false;
		    }

			if (gInterface.Data[eCHANGINGCLASS_MAIN].OnShow == true)
			{
				gInterface.Data[eCHANGINGCLASS_MAIN].OnShow = false;
				pSetCursorFocus = false;
		    }

			if (gInterface.Data[eJEWELBANK_MAIN].OnShow == true)
			{
				gInterface.Data[eJEWELBANK_MAIN].OnShow = false;
				pSetCursorFocus = false;
		    }

			if (gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow == true)
			{
				gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow = false;
				pSetCursorFocus = false;
		    }

			if (gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow == true)
			{
				gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow = false;
				pSetCursorFocus = false;
		    }

			if (gInterface.Data[eTUCHAN_MAIN].OnShow == true)
			{
				gInterface.Data[eTUCHAN_MAIN].OnShow = false;
				pSetCursorFocus = false;
		    }

			if (gInterface.Data[OBJECT_WIN_QUEST_MAIN].OnShow == true)
			{
				gInterface.Data[OBJECT_WIN_QUEST_MAIN].OnShow = false;
				pSetCursorFocus = false;
		    }

			gInterface.Data[ePARTYSETTINGS_MAIN].Close();
			gInterface.Data[ePARTYSEARCH_MAIN].Close();
			gInterface.Data[eCHANGINGCLASS_MAIN].Close();
			gInterface.Data[eLuckyWheelMain].Close();
			gInterface.LuckyWheelStateclose();
			gInterface.Data[eCHANGINGCLASS_MAIN].Close();
			gInterface.Data[eCHANGE_RESET_MAIN].Close();
			gJewelsBank.Active = false;

		}


	}

gCRuudShop.RuudShop();

	gInterface.DrawLogo(0);
}

void Interface::SwitchMiniMap()
{
	if((GetTickCount() - gInterface.Data[eNULL_MAP].EventTick) < 1000 ||this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[eNULL_MAP].EventTick = GetTickCount();

	if (MiniMap != 0)
	{
		gInterface.DrawMessage(1, "MiniMap Window [OFF]");
		MiniMap = 0;
		WritePrivateProfileStringA("Graphics","MiniMap","0","./Settings.ini");
	}
	else 
	{
		gInterface.DrawMessage(1, "MiniMap Window [ON]");
		MiniMap = 1;
		WritePrivateProfileStringA("Graphics","MiniMap","1","./Settings.ini");
	}
}

void Interface::DrawTimeUI()
{
/*  if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 3)
	{
		return;
	} */


	if(TimerBar == 0 || (this->CheckWindow(ObjWindow::CashShop)|| this->CheckWindow(ObjWindow::FullMap) || this->CheckWindow(ObjWindow::ChatWindow) || this->CheckWindow(ObjWindow::SkillTree)
	|| this->CheckWindow(ObjWindow::MoveList) || pMapNumber == 34 || pMapNumber == 30 ))
	{
		return;
	}
	//--
	time_t TimeServer, TimeLocal;
	struct tm * ServerT, * LocalT;
	time(&TimeServer);
	time(&TimeLocal);
	// ----
	ServerT = gmtime(&TimeServer);
	// ----
	char ServerTimeName[25] = "Estados Unidos:";
	char ServerTime[30];

	sprintf(ServerTime, "%2d:%02d:%02d", (ServerT->tm_hour + GMT)%24, ServerT->tm_min, ServerT->tm_sec);
	// -----
	LocalT = localtime(&TimeLocal); 
	// -----
	char LocalTimeName[25] = "Perú, Lima:";
	char LocalTime[30];
	sprintf(LocalTime, "%2d:%02d:%02d", LocalT->tm_hour, LocalT->tm_min, LocalT->tm_sec);

	//this->DrawGUI(eTIME, this->Data[eTIME].X, this->Data[eTIME].Y - 20);

	//RenderBitmap(this->Data[eTIME].ModelID, 0, 384, 106, 22.5, 0.0, 0.3986999691, 0.369599998, 0.3498000205, 1, 1, 0);

	//RenderBitmap(this->Data[eTIME].ModelID, 0, 384 + 22.3, 106, 22.5, 0.0, 0.3986999691, 0.369599998, 0.3498000205, 1, 1, 0);

	//this->DrawFormat(eGold, 5, 391, 50, 1, ServerTimeName);
	//this->DrawFormat(eWhite, 55, 391, 100, 1, ServerTime);
	// ----
	//this->DrawFormat(eGold, 5, 413, 50, 1, LocalTimeName);
	//this->DrawFormat(eWhite, 55, 413, 100, 1, LocalTime);
}

int Interface::DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	
	int LineCount = 0;
	
	char * Line = strtok(Buff, "\n");
	
	while( Line != NULL )
	{
		pDrawColorText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}
	
	return PosY;
}

bool Interface::CheckWindow(int WindowID)
{
	return pCheckWindow(pWindowThis(), WindowID);
}
int Interface::CloseWindow(int WindowID)
{
	return pCloseWindow(pWindowThis(), WindowID);
}
int Interface::OpenWindow(int WindowID)
{
	return pOpenWindow(pWindowThis(), WindowID);
}

bool Interface::IsWorkZone(short ObjectID)
{
	//estaba hay
/*	if( (pCursorX < this->Data[ObjectID].X || pCursorX > this->Data[ObjectID].MaxX) || (pCursorY < this->Data[ObjectID].Y || pCursorY > this->Data[ObjectID].MaxY) )
		return false;
	return true;*/
		if( (gObjUser.m_CursorX < this->Data[ObjectID].X || gObjUser.m_CursorX > this->Data[ObjectID].MaxX) || (gObjUser.m_CursorY < this->Data[ObjectID].Y || gObjUser.m_CursorY > this->Data[ObjectID].MaxY) )
		return false;

	return true;
}
bool Interface::IsWorkZone(float X, float Y, float MaxX, float MaxY, bool a5)
{
	if (a5) 
	{
		if ((pCursorX < X || pCursorX > X + MaxX) || (pCursorY < Y || pCursorY > Y + MaxY))
		return false;
		return true;
	}
	if ((pCursorX < X || pCursorX > MaxX) || (pCursorY < Y || pCursorY > MaxY))
	return false;
	return true;
}

bool Interface::IsWorkZone(float X, float Y, float MaxX, float MaxY)
{
	if( (gObjUser.m_CursorX < X || gObjUser.m_CursorX > MaxX) 
		|| (gObjUser.m_CursorY < Y || gObjUser.m_CursorY > MaxY) )
	{
		return false;
	}
	// ----
	return true;
}

bool Interface::IsWorkZone4(float X, float Y, float MaxX, float MaxY)
{
	if ((gObjUser.m_CursorX < X || gObjUser.m_CursorX > MaxX)
		|| (gObjUser.m_CursorY < Y || gObjUser.m_CursorY > MaxY))
	{
		return false;
	}
	// ----
	return true;
}

bool Interface::IsWorkZone2(float X, float Y, float MaxX, float MaxY)
{
	if ((gObjUser.m_CursorX < X + gJewelsBank.ultimoX|| gObjUser.m_CursorX > MaxX)|| (gObjUser.m_CursorY < Y || gObjUser.m_CursorY > MaxY))
	{
		return false;
	}
	// ----
	return true;
}

bool Interface::IsWorkZone3(float X, float Y, float MaxX, float MaxY, bool a5){
	if (a5) {
		if ((pCursorX < X || pCursorX > X + MaxX) || (pCursorY < Y || pCursorY > Y + MaxY))
			return false;
		return true;
	}
	if ((pCursorX < X || pCursorX > MaxX) || (pCursorY < Y || pCursorY > MaxY))
		return false;
	return true;
}

void Interface::DrawButton2(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawColoredGUI2(short ObjectID, float X, float Y, DWORD Color)
{
	this->Data[ObjectID].X		= X;
	this->Data[ObjectID].Y		= Y;
	this->Data[ObjectID].MaxX	= X + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY	= Y + this->Data[ObjectID].Height;
	pDrawColorButton(this->Data[ObjectID].ModelID, X,Y, this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, Color);
}

float Interface::GetResizeX(short ObjectID)
{
	if( pWinWidth == 800 )
	{
		return this->Data[ObjectID].X + 16.0;
	}
	else if( pWinWidth != 1024 )
	{
		return this->Data[ObjectID].X - 16.0;
	}
	
	return this->Data[ObjectID].X;
}

int Interface::DrawToolTip(int X, int Y, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	
	return pDrawToolTip(X, Y, Buff);
}

int Interface::DrawMessage(int Mode, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----
	return pDrawMessage(Buff, Mode);
}

void Interface::DrawVipWindow()
{

	if( !this->Data[eVip_MAIN].OnShow )
	{
		return;
	}

	if( gProtect.m_MainInfo.EnableVipShop != 1 )
	{
		this->CloseVipWindow();
		return;
	}

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Store)) 
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(Warehouse) 
		&& this->CheckWindow(ExpandWarehouse)) )
	{
		CloseVipWindow();
		return;
	}

	// ----
	float MainWidth			= 230.0;
	float MainHeight		= 320.0;
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
//----------------------------------------------------------------------------
	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);
	// ----
	this->DrawFormat(eGold, (int)StartX + 10, (int)StartY + 10, 210, 3, gCustomMessage.GetMessage(5));
	int LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)StartY + 35, 210, 1, gCustomMessage.GetMessage(6), gObjUser.lpPlayer->Name);
	LineY = this->DrawFormat(eGold, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(14));
	LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(7));
	LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(8));
	//--
	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartY + 85, 200, 1); //-- Divisor
	//--
	this->DrawFormat(eGold, (int)StartX + 30, (int)StartY + 95 - 2, 210, 1, "Plan");
	this->DrawFormat(eGold, (int)StartX + 80, (int)StartY + 95 - 2 , 210, 1, "Exp");
	this->DrawFormat(eGold, (int)StartX + 130, (int)StartY + 95 - 2, 210, 1, "Drop");
	this->DrawFormat(eGold, (int)StartX + 170, (int)StartY + 95 - 2, 210, 1, "Time");
	// ----

	if (gProtect.m_MainInfo.VipTypes < 1 || gProtect.m_MainInfo.VipTypes > 3)
	{
		gProtect.m_MainInfo.VipTypes = 3;
	}

	for( int i = 0; i < (int)gProtect.m_MainInfo.VipTypes; i++ )
	{
		this->DrawFormat(eWhite, (int)StartX + 30, (int)StartY + 110 + (12 * i) - 5, 210, 1, gCustomBuyVip.m_CustomBuyVipInfo[i].VipName);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 80, (int)StartY + 110 + (12 * i) - 5, 210, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Exp);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 130, (int)StartY + 110 + (12 * i) - 5, 210, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Drop);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 170, (int)StartY + 110 + (12 * i) - 5, 210, 1, "%d day(s)", gCustomBuyVip.m_CustomBuyVipInfo[i].Days);

		pDrawGUI(0x7B5E, StartX + 30, StartY + 110 + (12 * i) + 9 - 5, 82.0, 2.0);
		pDrawGUI(0x7B5E, StartX + 30 + 82, StartY + 110 + (12 * i) + 9 - 5, 82.0, 2.0);
	}

	if (gProtect.m_MainInfo.VipTypes > 0)
	{
	// ---- bronze start 
	if (IsWorkZone(eVip_BRONZE))
	{
		if (this->Data[eVip_BRONZE].OnClick)
			this->DrawButton2(eVip_BRONZE, StartX + 64, StartY + 190, 0, 58);
		else
			this->DrawButton2(eVip_BRONZE, StartX + 64, StartY + 190, 0, 29);
		// ----
		this->DrawFormat(eGold, (int)StartX + 30, (int)StartY + 142, 210, 1, gCustomMessage.GetMessage(10));
		this->DrawFormat(eGold, (int)StartX + 70, (int)StartY + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin1);
		this->DrawFormat(eGold, (int)StartX + 120, (int)StartY + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin2);
		this->DrawFormat(eGold, (int)StartX + 160, (int)StartY + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin3);
	}
	else
		this->DrawButton2(eVip_BRONZE, StartX + 64, StartY + 190, 0, 0);
	// ----
	this->DrawFormat(eWhite, (int)StartX + 90, StartY + 199, 160, 1, gCustomMessage.GetMessage(9),gCustomBuyVip.m_CustomBuyVipInfo[0].VipName);
	// ---- bronze end ------------------------------------
	}

	if (gProtect.m_MainInfo.VipTypes > 1)
	{
	// ---- Silver start ------------------------------------
	if (IsWorkZone(eVip_SILVER))
	{
		if (this->Data[eVip_SILVER].OnClick)
			this->DrawButton2(eVip_SILVER, StartX + 64, StartY + 220, 0, 58);
		else
			this->DrawButton2(eVip_SILVER, StartX + 64, StartY + 220, 0, 29);
		// ----
		this->DrawFormat(eGold, (int)StartX + 30, (int)StartY + 142, 210, 1, gCustomMessage.GetMessage(10));
		this->DrawFormat(eGold, (int)StartX + 70, (int)StartY + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin1);
		this->DrawFormat(eGold, (int)StartX + 120, (int)StartY + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin2);
		this->DrawFormat(eGold, (int)StartX + 160, (int)StartY + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin3);
	}
	else
		this->DrawButton2(eVip_SILVER, StartX + 64, StartY + 220, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 90, StartY + 229, 160, 1, gCustomMessage.GetMessage(9),gCustomBuyVip.m_CustomBuyVipInfo[1].VipName);
	// ---- silver end ------------------------------------
	}

	if (gProtect.m_MainInfo.VipTypes > 2)
	{
	// ---- gold start ------------------------------------
	if (IsWorkZone(eVip_GOLD))
	{
		if (this->Data[eVip_GOLD].OnClick)
			this->DrawButton2(eVip_GOLD, StartX + 64, StartY + 250, 0, 58);
		else
			this->DrawButton2(eVip_GOLD, StartX + 64,  StartY + 250, 0, 29);
		// ----
		this->DrawFormat(eGold, (int)StartX + 30, (int)StartY + 142, 210, 1, gCustomMessage.GetMessage(10));
		this->DrawFormat(eGold, (int)StartX + 70, (int)StartY + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin1);
		this->DrawFormat(eGold, (int)StartX + 120, (int)StartY + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin2);
		this->DrawFormat(eGold, (int)StartX + 160, (int)StartY + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin3);
	}
	else
		this->DrawButton2(eVip_GOLD, StartX + 64,  StartY + 250, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 90, StartY + 259, 160, 1, gCustomMessage.GetMessage(9),gCustomBuyVip.m_CustomBuyVipInfo[2].VipName);
	// ---- gold end ------------------------------------
	}

	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), 280 + 55, 200, 1); //-- Divisor
}

bool Interface::EventVipWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_CLOSE].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_CLOSE].OnClick = false;
	// ----
	if (Delay < 1000)
	{
		return false;
	}
	// ----
	this->Data[eVip_CLOSE].EventTick = GetTickCount();
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Bronze(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_BRONZE].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_BRONZE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_BRONZE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_BRONZE].OnClick = false;;
	// ----
	if (Delay < 1000)
	{
		return false;
	}
	// ----
	this->Data[eVip_BRONZE].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(1);
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Silver(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_SILVER].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_SILVER))
	{
		return false;
	}
	if (gProtect.m_MainInfo.VipTypes < 2)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_SILVER].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_SILVER].OnClick = false;;
	// ----
	if (Delay < 1000)
	{
		return false;
	}
	// ----
	this->Data[eVip_SILVER].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(2);
	this->CloseVipWindow();
	// ----
	return false;
}

// ----------------------------------------------------------------------------------------------
bool Interface::EventVipWindow_Gold(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_GOLD].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_GOLD))
	{
		return false;
	}
	if (gProtect.m_MainInfo.VipTypes < 3)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_GOLD].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_GOLD].OnClick = false;;
	// ----
	if (Delay < 1000)
	{
		return false;
	}
	// ----
	this->Data[eVip_GOLD].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(3);
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Main(DWORD Event)
{
	this->EventVipWindow_Close(Event);
	this->EventVipWindow_Bronze(Event);
	this->EventVipWindow_Silver(Event);
	this->EventVipWindow_Gold(Event);
	// ----
	return true;
}

float Interface::DrawRepeatGUI(short MonsterID, float X, float Y, int Count)
{
	float StartY = Y;
	// ----
	for( int i = 0; i < Count; i++ )
	{
		pDrawGUI(this->Data[MonsterID].ModelID, X, StartY,
			this->Data[MonsterID].Width, this->Data[MonsterID].Height);
		// ----
		StartY += this->Data[MonsterID].Height;
	}
	// ----
	return StartY;
}

float Interface::DrawRepeatGUIScale(short MonsterID, float X, float Y,float ScaleX, float ScaleY, int Count)
{
	float StartY = Y;
	// ----
	for( int i = 0; i < Count; i++ )
	{
		this->DrawIMG(this->Data[MonsterID].ModelID, X, StartY,ScaleX,ScaleY);
		// ----
		StartY += this->Data[MonsterID].Height;
	}
	// ----
	return StartY;
}

void Interface::DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawButtonRender(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= X;
		this->Data[ObjectID].Y		= Y;
		this->Data[ObjectID].MaxX	= X + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= Y + this->Data[ObjectID].Height;
	}
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, X, Y, 
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, Color);
}

void Interface::DrawLogo(bool active)
{
	if (gProtect.m_MainInfo.PrintLogo != 0)
	{

		if (active == 1)
		{
			this->Data[eLogo].EventTick = GetTickCount()+1500;
		}

		if (gInterface.Data[eLogo].EventTick > GetTickCount())
		{
			if (gProtect.m_MainInfo.PrintLogo == 1)
			{
				this->DrawGUI(eLogo, 10, 10);
			}

			if (gProtect.m_MainInfo.PrintLogo == 2)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, 10);

			}

			if (gProtect.m_MainInfo.PrintLogo == 3)
			{
				this->DrawGUI(eLogo, 10, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 4)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 5)
			{
				this->DrawGUI(eLogo, (MAX_WIN_WIDTH/2)-(150/2), (MAX_WIN_HEIGHT/2)-(114/2));
			}
		}
	}
}

void Interface::DrawMenu()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if (this->Data[eMenu].OnShow)
	{
		this->Data[eMenu].OnShow = false;
	}

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Store))
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Character))
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(Warehouse) 
		&& this->CheckWindow(ExpandWarehouse)) )
	{
		CloseMenuWindow();
		return;
	}
	
	this->Data[eMenu].OnShow = true;
}

bool Interface::EventDrawMenu_Open(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu].EventTick);
	// ----
	if (!this->Data[eMenu].OnShow || !IsWorkZone(eMenu))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
		this->Data[eMenu].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu].OnClick = false;
	// ----
	if (Delay < 1000)
	{
		return false;
	}
	
	// ----
	this->Data[eMenu].EventTick = GetTickCount();
	
	if (CheckMenuWindow() /*Nuevo max*/|| gInterface.CheckMenuWindowTwo())
	{
		CloseMenuWindow();
		CloseMenuWindowTwo();
	}
	else
	{
		//CloseCustomWindow();// desactivado de maxvoll
		//OpenMenuWindow();
		OpenWindowMenu();// nuevo de maxvoll
	}
	// ----
	return false;
}

void Interface::OpenWindowMenu()
{

	if (gInterface.Data[eMenu_MAIN].OnShow == true)
	{
		gInterface.Data[eMenu_MAIN].OnShow = false;
		pSetCursorFocus = false;
		return;
	}

	DWORD CurrentTick = GetTickCount();

	gInterface.Data[eMenu_MAIN].EventTick = GetTickCount();
	gInterface.Data[eMenu_MAIN].OnShow = true;

}

void Interface::OpenWindowMenuTwo()
{

	if (gInterface.Data[eMenu_MAINTWO].OnShow == true)
	{
		gInterface.Data[eMenu_MAINTWO].OnShow = false;
		pSetCursorFocus = false;
		return;
	}

	DWORD CurrentTick = GetTickCount();

	gInterface.Data[eMenu_MAINTWO].EventTick = GetTickCount();
	gInterface.Data[eMenu_MAINTWO].OnShow = true;

}

void Interface::DrawMenuOpen()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if( !this->Data[eMenu_MAIN].OnShow )
	{
		return;
	}

	float MainWidth			= 230.0;
	float MainHeight		= 250.0;
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

	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartY + 35, 200, 1);

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	this->DrawGUI2(eMenu_CLOSE, StartX + MainWidth - 32, StartY);
	// ----
	if (this->IsWorkZone(eMenu_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eMenu_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI2(eMenu_CLOSE,StartX + MainWidth - 32, StartY, Color);
		this->DrawToolTip(StartX + MainWidth - 29, (int)StartY - 5, "Close ");
	}

	if (gInterface.IsWorkZone(eMenu_NEXT))
	{
		DWORD Color = eGray100;
		// ----
		if (gInterface.Data[eMenu_NEXT].OnClick)
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI2(eMenu_NEXT, StartX + 150, StartY + 210, Color);
		this->DrawToolTip((int)StartX + 150, (int)StartY + 238, "Next");
	}

	if (gInterface.IsWorkZone(eMenu_PREVIUS))
	{
		DWORD Color = eGray100;
		// ----
		if (gInterface.Data[eMenu_PREVIUS].OnClick)
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI2(eMenu_PREVIUS, StartX + 55, StartY + 210, Color);
		this->DrawToolTip((int)StartX + 55, (int)StartY + 238, "Previus");
	}

	gInterface.DrawGUI2(eMenu_PREVIUS, StartX + 55, StartY + 210);
	gInterface.DrawGUI2(eMenu_NEXT, StartX + 150, StartY + 210);
	

	this->DrawFormat(eGold, (int)StartX + 10, (int)StartY + 10, 210, 3, "Menu");

	if(gProtect.m_MainInfo.EnableCoinStatus == 1)
	{
		this->DrawFormat(eGold, (int)StartX + 10, (int)StartY + 35, 210, 3, gCustomMessage.GetMessage(50));

		this->DrawFormat(eWhite, (int)StartX + 25, (int)StartY + 50, 40, 1, gCustomMessage.GetMessage(51));
		this->DrawFormat(eGold, (int)StartX + 50, (int)StartY + 50, 40, 1, "%d",Coin1);

		this->DrawFormat(eWhite, (int)StartX + 90, (int)StartY + 50, 40, 1, gCustomMessage.GetMessage(52));
		this->DrawFormat(eGold, (int)StartX + 115, (int)StartY + 50, 40, 1, "%d",Coin2);

		this->DrawFormat(eWhite, (int)StartX + 153, (int)StartY + 50, 40, 1, gCustomMessage.GetMessage(53));
		this->DrawFormat(eGold, (int)StartX + 176, (int)StartY + 50, 40, 1, "%d",Coin3);
	}
	else
	{
		this->DrawFormat(eGold, (int)StartX + 10, (int)StartY + 45, 210, 3, gCustomMessage.GetMessage(54));
	}

	this->DrawGUI2(eVip_DIV, StartX, StartY + 60);

	int BtCount		= 0;
	int BtCount2    = 0;
	int BtStart		= StartY + 78;
	int BtStart2    = StartY + 78;
	int BtDistance	= 33;

	if (gProtect.m_MainInfo.MenuButtons[0] == 1)//gProtect.m_MainInfo.EnableEventTimeButton
	{
		BtCount++;
	}
	else
	{	
		BtStart	-= 33;
	}
	if (gProtect.m_MainInfo.MenuButtons[1] == 1)//EnableVipShopButton
	{
		BtCount++;
	}
	if (gProtect.m_MainInfo.MenuButtons[2] == 1)//EnableRankingButton
	{
		BtCount++;
	}
	if (gProtect.m_MainInfo.MenuButtons[3] == 1)//EnableCommandButton
	{
		BtCount++;
	}
	// Melo920 Falta el ultimo 4 -> EnableOptionButton



//	if (gProtect.m_MainInfo.EnableEventTimeButton == 1 && gProtect.m_MainInfo.EnableVipShopButton == 1 && gProtect.m_MainInfo.EnableRankingButton == 1 && gProtect.m_MainInfo.EnableCommandButton == 1)
//	{
		if (BtCount2 == 3)
		{
			BtStart2 += 30;
		}
//	}
//	if (gProtect.m_MainInfo.EnableEventTimeButton == 0 && gProtect.m_MainInfo.EnableVipShopButton == 1 && gProtect.m_MainInfo.EnableRankingButton == 1 && gProtect.m_MainInfo.EnableCommandButton == 1)
//	{
		if (BtCount2 == 2)
		{
			BtStart2 += 45;
		}
//	}
//	if (gProtect.m_MainInfo.EnableEventTimeButton == 1 && gProtect.m_MainInfo.EnableVipShopButton == 0 && gProtect.m_MainInfo.EnableRankingButton == 1 && gProtect.m_MainInfo.EnableCommandButton == 1)
//	{
		if (BtCount2 == 2)
		{
			BtStart2 += 45;
		}
//	}
//	if (gProtect.m_MainInfo.EnableEventTimeButton == 1 && gProtect.m_MainInfo.EnableVipShopButton == 1 && gProtect.m_MainInfo.EnableRankingButton == 0 && gProtect.m_MainInfo.EnableCommandButton == 1)
//	{
		if (BtCount2 == 2)
		{
			BtStart2 += 45;
		}
//	}
//	if (gProtect.m_MainInfo.EnableEventTimeButton == 1 && gProtect.m_MainInfo.EnableVipShopButton == 1 && gProtect.m_MainInfo.EnableRankingButton == 1 && gProtect.m_MainInfo.EnableCommandButton == 0)
//	{
		if (BtCount2 == 2)
		{
			BtStart2 += 45;
		}
//	}
//	if (gProtect.m_MainInfo.EnableEventTimeButton == 0 && gProtect.m_MainInfo.EnableVipShopButton == 0 && gProtect.m_MainInfo.EnableRankingButton == 1 && gProtect.m_MainInfo.EnableCommandButton == 1)
//	{
		if (BtCount2 == 1)
		{
			BtStart2 += 60;
		}
//	}
//	if (gProtect.m_MainInfo.EnableEventTimeButton == 0 && gProtect.m_MainInfo.EnableVipShopButton == 1 && gProtect.m_MainInfo.EnableRankingButton == 0 && gProtect.m_MainInfo.EnableCommandButton == 1)
//	{
		if (BtCount2 == 1)
		{
			BtStart2 += 60;
		}
//	}
//	if (gProtect.m_MainInfo.EnableEventTimeButton == 0 && gProtect.m_MainInfo.EnableVipShopButton == 1 && gProtect.m_MainInfo.EnableRankingButton == 1 && gProtect.m_MainInfo.EnableCommandButton == 0)
//	{
		if (BtCount2 == 1)
		{
			BtStart2 += 60;
		}
//	}


//	//Horario eventos
	if (gProtect.m_MainInfo.MenuButtons[0] == 1)//EnableEventTimeButton
	{
	
	if (IsWorkZone(eMenu_OPT1))
	{
		if (this->Data[eMenu_OPT1].OnClick)
			this->DrawButton2(eMenu_OPT1, StartX + 4, BtStart, 0, 58);
		else
			this->DrawButton2(eMenu_OPT1, StartX + 4, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton2(eMenu_OPT1, StartX + 4, BtStart, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 4, BtStart + 9, 108, 3, gCustomMessage.GetMessage(25));
	}

//	//Comprar vip
	if (gProtect.m_MainInfo.MenuButtons[1] == 1)//EnableVipShopButton
	{
	
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_OPT2))
	{
		if (this->Data[eMenu_OPT2].OnClick)
			this->DrawButton2(eMenu_OPT2, StartX + 4, BtStart, 0, 58);
		else
			this->DrawButton2(eMenu_OPT2, StartX + 4, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton2(eMenu_OPT2, StartX + 4, BtStart, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 4, BtStart + 9, 108, 3, gCustomMessage.GetMessage(26));
	}

	//Ranking
	if (gProtect.m_MainInfo.MenuButtons[2] == 1)//EnableRankingButton
	{
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_OPT3))
	{
		if (this->Data[eMenu_OPT3].OnClick)
			this->DrawButton2(eMenu_OPT3, StartX + 4, BtStart, 0, 58);
		else
			this->DrawButton2(eMenu_OPT3, StartX + 4, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton2(eMenu_OPT3, StartX + 4, BtStart, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 4, BtStart + 9, 108, 3, gCustomMessage.GetMessage(27));
	}

	if (gProtect.m_MainInfo.MenuButtons[3] == 1)//EnableCommandButton
	{
	//Commandos
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_OPT4))
	{
		if (this->Data[eMenu_OPT4].OnClick)
			this->DrawButton2(eMenu_OPT4, StartX + 4, BtStart, 0, 58);
		else
			this->DrawButton2(eMenu_OPT4, StartX + 4, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton2(eMenu_OPT4, StartX + 4, BtStart, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 4, BtStart + 9, 108, 3, gCustomMessage.GetMessage(28));
	}
	// melo920 recuerda falta la 4 de EnableOptionButton

// ======================================== SEGUNDA COLUMNA ==============================================

	
	if (gProtect.m_MainInfo.MenuButtons[5] == 1)//EnableMultiWareButton
	{
		BtCount2++;
	}
	else
	{
		BtStart2 -= 33;
	}
//	if (gProtect.m_MainInfo.EnableUserPanelButton == 1)
//	{
		BtCount2++;
//	}
//	if (gProtect.m_MainInfo.EnableOptionButton == 1)
//	{
		BtCount2++;
//	}
//	if (gProtect.m_MainInfo.EnableChangeClassButton == 1)
//	{
		BtCount2++;
//	}

//	if (gProtect.m_MainInfo.EnableChangeClassButton == 1 && gProtect.m_MainInfo.EnableOptionButton == 1 && gProtect.m_MainInfo.EnableUserPanelButton == 1 && gProtect.m_MainInfo.EnableMultiWareButton == 1)
//	{
		if (BtCount2 == 3)
		{
			BtStart2 += 30;
		}
//	}
//	if (gProtect.m_MainInfo.EnableChangeClassButton == 0 && gProtect.m_MainInfo.EnableOptionButton == 1 && gProtect.m_MainInfo.EnableUserPanelButton == 1 && gProtect.m_MainInfo.EnableMultiWareButton == 1)
//	{
		if (BtCount2 == 2)
		{
			BtStart2 += 45;
		}
//	}
//	if (gProtect.m_MainInfo.EnableChangeClassButton == 1 && gProtect.m_MainInfo.EnableOptionButton == 0 && gProtect.m_MainInfo.EnableUserPanelButton == 1 && gProtect.m_MainInfo.EnableMultiWareButton == 1)
//	{
		if (BtCount2 == 2)
		{
			BtStart2 += 45;
		}
//	}
//	if (gProtect.m_MainInfo.EnableChangeClassButton == 1 && gProtect.m_MainInfo.EnableOptionButton == 1 && gProtect.m_MainInfo.EnableUserPanelButton == 0 && gProtect.m_MainInfo.EnableMultiWareButton == 1)
//	{
		if (BtCount2 == 2)
		{
			BtStart2 += 45;
		}
//	}
//	if (gProtect.m_MainInfo.EnableChangeClassButton == 1 && gProtect.m_MainInfo.EnableOptionButton == 1 && gProtect.m_MainInfo.EnableUserPanelButton == 1 && gProtect.m_MainInfo.EnableMultiWareButton == 0)
//	{
		if (BtCount2 == 2)
		{
			BtStart2 += 45;
		}
//	}
//	if (gProtect.m_MainInfo.EnableChangeClassButton == 0 && gProtect.m_MainInfo.EnableOptionButton == 0 && gProtect.m_MainInfo.EnableUserPanelButton == 1 && gProtect.m_MainInfo.EnableMultiWareButton == 1)
//	{
		if (BtCount2 == 1)
		{
			BtStart2 += 60;
		}
//	}
//	if (gProtect.m_MainInfo.EnableChangeClassButton == 0 && gProtect.m_MainInfo.EnableOptionButton == 1 && gProtect.m_MainInfo.EnableUserPanelButton == 0 && gProtect.m_MainInfo.EnableMultiWareButton == 1)
//	{
		if (BtCount2 == 1)
		{
			BtStart2 += 60;
		}
//	}
//	if (gProtect.m_MainInfo.EnableChangeClassButton == 0 && gProtect.m_MainInfo.EnableOptionButton == 1 && gProtect.m_MainInfo.EnableUserPanelButton == 1 && gProtect.m_MainInfo.EnableMultiWareButton == 0)
//	{
		if (BtCount2 == 1)
		{
			BtStart2 += 60;
		}
//	}

	//MultiWare
	if (gProtect.m_MainInfo.MenuButtons[5] == 1)//EnableMultiWareButton
	{
		if (IsWorkZone(eMenu_VAULT))
		{
			if (this->Data[eMenu_VAULT].OnClick)
				this->DrawButton2(eMenu_VAULT, StartX + 115, BtStart2, 0, 58);
			else
				this->DrawButton2(eMenu_VAULT, StartX + 115, BtStart2, 0, 29);
			// ----
		}
		else
			this->DrawButton2(eMenu_VAULT, StartX + 115, BtStart2, 0, 0);

		this->DrawFormat(eWhite, (int)StartX + 115, BtStart2 + 9, 108, 3, "MultiWare");//gCustomMessage.GetMessage(43)
	}
	//User Panel
	if (gProtect.m_MainInfo.MenuButtons[4] == 1)//EnableUserPanelButton
	{

		BtStart2 += BtDistance;

		if (IsWorkZone(eMenu_USERPANEL))
		{
			if (this->Data[eMenu_USERPANEL].OnClick)
				this->DrawButton2(eMenu_USERPANEL, StartX + 115, BtStart2, 0, 58);
			else
				this->DrawButton2(eMenu_USERPANEL, StartX + 115, BtStart2, 0, 29);
			// ----
		}
		else
			this->DrawButton2(eMenu_USERPANEL, StartX + 115, BtStart2, 0, 0);

		this->DrawFormat(eWhite, (int)StartX + 115, BtStart2 + 9, 108, 3, "User Panel");//gCustomMessage.GetMessage(42)
	}
	//Party Search
	if (gProtect.m_MainInfo.MenuButtons[7] == 1)//Party Search Mal escrito -> EnableOptionButton
	{

		BtStart2 += BtDistance;

		if (IsWorkZone(eMenu_OPT20))
		{
			if (this->Data[eMenu_OPT20].OnClick)
				this->DrawButton2(eMenu_OPT20, StartX + 115, BtStart2, 0, 58);
			else
				this->DrawButton2(eMenu_OPT20, StartX + 115, BtStart2, 0, 29);
			// ----
		}
		else
			this->DrawButton2(eMenu_OPT20, StartX + 115, BtStart2, 0, 0);

		this->DrawFormat(eWhite, (int)StartX + 115, BtStart2 + 9, 108, 3, "Party Setting");//gCustomMessage.GetMessage(44)
	}
	//Change Class
	if (gProtect.m_MainInfo.MenuButtons[8] == 1)//EnableChangeClassButton
	{

		BtStart2 += BtDistance;

		if (IsWorkZone(eMenu_CHANGECLASS))
		{
			if (this->Data[eMenu_CHANGECLASS].OnClick)
				this->DrawButton2(eMenu_CHANGECLASS, StartX + 115, BtStart2, 0, 58);
			else
				this->DrawButton2(eMenu_CHANGECLASS, StartX + 115, BtStart2, 0, 29);
			// ----
		}
		else
			this->DrawButton2(eMenu_CHANGECLASS, StartX + 115, BtStart2, 0, 0);

		this->DrawFormat(eWhite, (int)StartX + 115, BtStart2 + 9, 108, 3, "Change Class");//gCustomMessage.GetMessage(41)
	}
}

void Interface::DrawMenuOpenTwo()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if (!this->Data[eMenu_MAINTWO].OnShow)
	{
		return;
	}
	// ----

	float MainWidth			= 230.0;
	float MainHeight		= 250.0;
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

	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartY + 35, 200, 1);

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	this->DrawGUI2(eMenu_CLOSE, StartX + MainWidth - 32, StartY);
	// ----
	if (this->IsWorkZone(eMenu_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eMenu_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI2(eMenu_CLOSE,StartX + MainWidth - 32, StartY, Color);
		this->DrawToolTip(StartX + MainWidth - 29, (int)StartY - 5, "Close ");
	}

	if (gInterface.IsWorkZone(eMenu_NEXT))
	{
		DWORD Color = eGray100;
		// ----
		if (gInterface.Data[eMenu_NEXT].OnClick)
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI2(eMenu_NEXT, StartX + 150, StartY + 210, Color);
		this->DrawToolTip((int)StartX + 150, (int)StartY + 238, "Next");
	}

	if (gInterface.IsWorkZone(eMenu_PREVIUS))
	{
		DWORD Color = eGray100;
		// ----
		if (gInterface.Data[eMenu_PREVIUS].OnClick)
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI2(eMenu_PREVIUS, StartX + 55, StartY + 210, Color);
		this->DrawToolTip((int)StartX + 55, (int)StartY + 238, "Previus");
	}

	gInterface.DrawGUI2(eMenu_PREVIUS, StartX + 55, StartY + 210);
	gInterface.DrawGUI2(eMenu_NEXT, StartX + 150, StartY + 210);
	

	this->DrawFormat(eGold, (int)StartX + 10, (int)StartY + 10, 210, 3, "Menu");

	if(gProtect.m_MainInfo.EnableCoinStatus == 1)
	{
		this->DrawFormat(eGold, (int)StartX + 10, (int)StartY + 35, 210, 3, gCustomMessage.GetMessage(50));

		this->DrawFormat(eWhite, (int)StartX + 25, (int)StartY + 50, 40, 1, gCustomMessage.GetMessage(51));
		this->DrawFormat(eGold, (int)StartX + 50, (int)StartY + 50, 40, 1, "%d",Coin1);

		this->DrawFormat(eWhite, (int)StartX + 90, (int)StartY + 50, 40, 1, gCustomMessage.GetMessage(52));
		this->DrawFormat(eGold, (int)StartX + 115, (int)StartY + 50, 40, 1, "%d",Coin2);

		this->DrawFormat(eWhite, (int)StartX + 153, (int)StartY + 50, 40, 1, gCustomMessage.GetMessage(53));
		this->DrawFormat(eGold, (int)StartX + 176, (int)StartY + 50, 40, 1, "%d",Coin3);
	}
	else
	{
		this->DrawFormat(eGold, (int)StartX + 10, (int)StartY + 45, 210, 3, gCustomMessage.GetMessage(54));
	}

	this->DrawGUI2(eVip_DIV, StartX, StartY + 60);

	int BtCount = 0;
	int BtCount2 = 0;
	int BtStart = StartY + 78;
	int BtStart2 = StartY + 78;
	int BtDistance = 33;
	
	if (gProtect.m_MainInfo.MenuButtons[10] == 1)//9
	{
		BtCount++;
	}
	else
	{
		BtStart -= 33;
	}
//------------------------------------------------
	if (gProtect.m_MainInfo.MenuButtons[10] == 1)
	{
		BtCount++;
	}
//------------------------------------------------

	//Change Resets
	if (gProtect.m_MainInfo.MenuButtons[9] == 1)
	{

		if (IsWorkZone(eMenu_RESETCHANGE))
		{
			if (this->Data[eMenu_RESETCHANGE].OnClick)
				this->DrawButton2(eMenu_RESETCHANGE, StartX + 4, BtStart, 0, 58);
			else
				this->DrawButton2(eMenu_RESETCHANGE, StartX + 4, BtStart, 0, 29);
			// ----
		}
		else
			this->DrawButton2(eMenu_RESETCHANGE, StartX + 4, BtStart, 0, 0);

		this->DrawFormat(eWhite, (int)StartX + 4, BtStart + 9, 108, 3, "Change Resets");
	}

	//SmithItem
//	if (gProtect.m_MainInfo.MenuButtons[10] == 1)//EnableSmithItem
//	{

	BtStart += BtDistance;

		if (IsWorkZone(eMenu_SMITH_ITEM))
		{
			if (this->Data[eMenu_SMITH_ITEM].OnClick)
				this->DrawButton2(eMenu_SMITH_ITEM, StartX + 4, BtStart, 0, 58);
			else
				this->DrawButton2(eMenu_SMITH_ITEM, StartX + 4, BtStart, 0, 29);
			// ----
		}
		else
			this->DrawButton2(eMenu_SMITH_ITEM, StartX + 4, BtStart, 0, 0);

		this->DrawFormat(eWhite, (int)StartX + 4, BtStart + 9, 108, 3, "Smith Item");
//	}

	BtStart += BtDistance;

		if (IsWorkZone(eMenu_CUSTOM_VIP))
		{
			if (this->Data[eMenu_CUSTOM_VIP].OnClick)
				this->DrawButton2(eMenu_CUSTOM_VIP, StartX + 4, BtStart, 0, 58);
			else
				this->DrawButton2(eMenu_CUSTOM_VIP, StartX + 4, BtStart, 0, 29);
			// ----
		}
		else
			this->DrawButton2(eMenu_CUSTOM_VIP, StartX + 4, BtStart, 0, 0);

		this->DrawFormat(eWhite, (int)StartX + 4, BtStart + 9, 108, 3, "MuVip");
//---------------------------------------------------------------
	BtStart += BtDistance;

		if (IsWorkZone(eMenu_TU_CHAN))
		{
			if (this->Data[eMenu_TU_CHAN].OnClick)
				this->DrawButton2(eMenu_TU_CHAN, StartX + 4, BtStart, 0, 58);
			else
				this->DrawButton2(eMenu_TU_CHAN, StartX + 4, BtStart, 0, 29);
			// ----
		}
		else
			this->DrawButton2(eMenu_TU_CHAN, StartX + 4, BtStart, 0, 0);

		this->DrawFormat(eWhite, (int)StartX + 4, BtStart + 9, 108, 3, "TuChan");
//---------------------------------------------------------------
	// ======================================== SEGUNDA COLUMNA ==============================================


	if (gProtect.m_MainInfo.MenuButtons[10] == 1)//6
	{
		BtCount2++;
	}
	else
	{
		BtStart2 -= 33;
	}
//------------------------------------------------
	if (gProtect.m_MainInfo.MenuButtons[10] == 1)
	{
		BtCount2++;
	}
//------------------------------------------------
	//OffAttack Panel
	if (gProtect.m_MainInfo.MenuButtons[6] == 1)
	{

		if (IsWorkZone(eMenu_LUCKYWELL))
		{
			if (this->Data[eMenu_LUCKYWELL].OnClick)
				this->DrawButton2(eMenu_LUCKYWELL, StartX + 115, BtStart2, 0, 58);
			else
				this->DrawButton2(eMenu_LUCKYWELL, StartX + 115, BtStart2, 0, 29);
			// ----
		}
		else
			this->DrawButton2(eMenu_LUCKYWELL, StartX + 115, BtStart2, 0, 0);

		this->DrawFormat(eWhite, (int)StartX + 115, BtStart2 + 9, 108, 3, "LuckyWell");
	}

		BtStart2 += BtDistance;

		if (IsWorkZone(eMenu_JEWEL_BANK))
		{
			if (this->Data[eMenu_JEWEL_BANK].OnClick)
				this->DrawButton2(eMenu_JEWEL_BANK, StartX + 115, BtStart2, 0, 58);
			else
				this->DrawButton2(eMenu_JEWEL_BANK, StartX + 115, BtStart2, 0, 29);
			// ----
		}
		else
			this->DrawButton2(eMenu_JEWEL_BANK, StartX + 115, BtStart2, 0, 0);

		this->DrawFormat(eWhite, (int)StartX + 115, BtStart2 + 9, 108, 3, "JewelBank");

		BtStart2 += BtDistance;

		if (IsWorkZone(eMenu_RANK_TITLE))
		{
			if (this->Data[eMenu_RANK_TITLE].OnClick)
				this->DrawButton2(eMenu_RANK_TITLE, StartX + 115, BtStart2, 0, 58);
			else
				this->DrawButton2(eMenu_RANK_TITLE, StartX + 115, BtStart2, 0, 29);
			// ----
		}
		else
			this->DrawButton2(eMenu_RANK_TITLE, StartX + 115, BtStart2, 0, 0);

		this->DrawFormat(eWhite, (int)StartX + 115, BtStart2 + 9, 108, 3, "RankTitle");
//----------------------------------------
		BtStart2 += BtDistance;

		if (IsWorkZone(eMenu_QUEST_SYSTEM))
		{
			if (this->Data[eMenu_QUEST_SYSTEM].OnClick)
				this->DrawButton2(eMenu_QUEST_SYSTEM, StartX + 115, BtStart2, 0, 58);
			else
				this->DrawButton2(eMenu_QUEST_SYSTEM, StartX + 115, BtStart2, 0, 29);
			// ----
		}
		else
			this->DrawButton2(eMenu_QUEST_SYSTEM, StartX + 115, BtStart2, 0, 0);

		this->DrawFormat(eWhite, (int)StartX + 115, BtStart2 + 9, 108, 3, "QuestSystem");
//----------------------------------------
}

void Interface::ButtonsMenu(DWORD Event)
{
	DWORD Delay = (GetTickCount() - this->ClickTime);


	if (gInterface.Data[eMenu_MAIN].OnShow)
	{
		if (gInterface.IsWorkZone(eMenu_CLOSE))
		{
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[eMenu_CLOSE].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
			// ----
			gInterface.Data[eMenu_CLOSE].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 1000)
			{
				return;
			}
			// ----
			gInterface.Data[eMenu_CLOSE].EventTick = GetTickCount();

			this->CloseMenuWindow();
			return;
		}

		if (gInterface.IsWorkZone(eMenu_OPT1))
			{
				if (Event == WM_LBUTTONDOWN)
				{
					gInterface.Data[eMenu_OPT1].OnClick = true;
					pSetCursorFocus = true;
					return;
				}
				// ----
				gInterface.Data[eMenu_OPT1].OnClick = false;
				pSetCursorFocus = false;
				// ----
				if (Delay < 1000)
				{
					return;
				}
				// ----
				gInterface.Data[eMenu_OPT1].EventTick = GetTickCount();

				this->CloseMenuWindow();
				gCustomEventTime.OpenWindow();
				return;
			}

		
		if (gInterface.IsWorkZone(eMenu_OPT2))
			{
				if (Event == WM_LBUTTONDOWN)
				{
					gInterface.Data[eMenu_OPT2].OnClick = true;
					pSetCursorFocus = true;
					return;
				}
				// ----
				gInterface.Data[eMenu_OPT2].OnClick = false;
				pSetCursorFocus = false;
				// ----
				if (Delay < 1000)
				{
					return;
				}
				// ----
				gInterface.Data[eMenu_OPT2].EventTick = GetTickCount();

				this->CloseMenuWindow();
				this->OpenVipWindow();
				return;
			}

		
		if (gInterface.IsWorkZone(eMenu_OPT3))
			{
				if (Event == WM_LBUTTONDOWN)
				{
					gInterface.Data[eMenu_OPT3].OnClick = true;
					pSetCursorFocus = true;
					return;
				}
				// ----
				gInterface.Data[eMenu_OPT3].OnClick = false;
				pSetCursorFocus = false;
				// ----
				if (Delay < 1000)
				{
					return;
				}
				// ----
				gInterface.Data[eMenu_OPT3].EventTick = GetTickCount();

				this->CloseMenuWindow();
				gCustomRanking.OpenWindow();
				return;
			}

		if (gInterface.IsWorkZone(eMenu_USERPANEL))
		{
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[eMenu_USERPANEL].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
			// ----
			gInterface.Data[eMenu_USERPANEL].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 1000)
			{
				return;
			}
			// ----
			gInterface.Data[eMenu_USERPANEL].EventTick = GetTickCount();

			this->CloseMenuWindow();
			this->OpenWindow(ObjWindow::Options);
			return;
		}

		if (gInterface.IsWorkZone(eMenu_CHANGECLASS))
		{
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[eMenu_CHANGECLASS].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
			// ----
			gInterface.Data[eMenu_CHANGECLASS].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 1000)
			{
				return;
			}
			// ----
			gInterface.Data[eMenu_CHANGECLASS].EventTick = GetTickCount();

			gInterface.DrawChangingClassWindow();
			gInterface.Data[eCHANGINGCLASS_MAIN].Open();
			this->CloseMenuWindow();			
			return;
		}

		
		if (gInterface.IsWorkZone(eMenu_OPT4))
			{
				if (Event == WM_LBUTTONDOWN)
				{
					gInterface.Data[eMenu_OPT4].OnClick = true;
					pSetCursorFocus = true;
					return;
				}
				// ----
				gInterface.Data[eMenu_OPT4].OnClick = false;
				pSetCursorFocus = false;
				// ----
				if (Delay < 1000)
				{
					return;
				}
				// ----
				gInterface.Data[eMenu_OPT4].EventTick = GetTickCount();

				this->CloseMenuWindow();
				gCustomCommandInfo.OpenCommandWindow();
				return;
			}

			if (gInterface.IsWorkZone(eMenu_VAULT))
			{
				if (Event == WM_LBUTTONDOWN)
				{
					gInterface.Data[eMenu_VAULT].OnClick = true;
					pSetCursorFocus = true;
					return;
				}
				// ----
				gInterface.Data[eMenu_VAULT].OnClick = false;
				pSetCursorFocus = false;
				// ----
				if (Delay < 1000)
				{
					return;
				}
				// ----
				gInterface.Data[eMenu_VAULT].EventTick = GetTickCount();

				gInterface.DrawVaultWindow();
				gInterface.Data[eVAULT_MAIN].Open();
				this->CloseMenuWindow();
				return;
			}

			if (gInterface.IsWorkZone(eMenu_OPT20))
			{
				if (Event == WM_LBUTTONDOWN)
				{
					gInterface.Data[eMenu_OPT20].OnClick = true;
					pSetCursorFocus = true;
					return;
				}
				// ----
				gInterface.Data[eMenu_OPT20].OnClick = false;
				//pSetCursorFocus = false;
				// ----
				if (Delay < 1000)
				{
					return;
				}
				// ----
				gInterface.Data[eMenu_OPT20].EventTick = GetTickCount();

				this->CloseMenuWindow();
				gInterface.SwitchPartySettingsWindowState();
				pSetCursorFocus = true;
				return;
			}

			if (gInterface.IsWorkZone(eMenu_NEXT))
			{
				if (Event == WM_LBUTTONDOWN)
				{
					gInterface.Data[eMenu_NEXT].OnClick = true;
					pSetCursorFocus = true;
					return;
				}
				// ----
				gInterface.Data[eMenu_NEXT].OnClick = false;
				pSetCursorFocus = false;
				// ----
				if (Delay < 1000)
				{
					return;
				}
				// ----
				gInterface.Data[eMenu_NEXT].EventTick = GetTickCount();

				this->CloseMenuWindow();
				this->OpenWindowMenuTwo();
				return;
			}

	}
// ======================PANEL TWO ===============================

	if (gInterface.Data[eMenu_MAINTWO].OnShow)
	{
		if (gInterface.IsWorkZone(eMenu_CLOSE))
		{
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[eMenu_CLOSE].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
			// ----
			gInterface.Data[eMenu_CLOSE].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 1000)
			{
				return;
			}
			// ----
			gInterface.Data[eMenu_CLOSE].EventTick = GetTickCount();

			this->CloseMenuWindowTwo();
			return;
		}

		if (gInterface.IsWorkZone(eMenu_PREVIUS))
		{
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[eMenu_PREVIUS].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
			// ----
			gInterface.Data[eMenu_PREVIUS].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 1000)
			{
				return;
			}
			// ----
			gInterface.Data[eMenu_PREVIUS].EventTick = GetTickCount();

			this->CloseMenuWindowTwo();
			this->OpenWindowMenu();
			return;
		}

		if (gInterface.IsWorkZone(eMenu_RESETCHANGE))
		{
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[eMenu_RESETCHANGE].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
			// ----
			gInterface.Data[eMenu_RESETCHANGE].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 1000)
			{
				return;
			}
			// ----
			gInterface.Data[eMenu_RESETCHANGE].EventTick = GetTickCount();
			
			gInterface.DrawChangeResetWindow();
			gInterface.Data[eCHANGE_RESET_MAIN].Open();
			this->CloseMenuWindowTwo();
			return;
		}

		if (gInterface.IsWorkZone(eMenu_LUCKYWELL))
		{
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[eMenu_LUCKYWELL].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
			// ----
			gInterface.Data[eMenu_LUCKYWELL].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 1000)
			{
				return;
			}
			// ----
			gInterface.Data[eMenu_LUCKYWELL].EventTick = GetTickCount();

			gInterface.LuckyWheelState();

			this->CloseMenuWindowTwo();
			return;
		}
//-----------------------------
		if (gInterface.IsWorkZone(eMenu_SMITH_ITEM))
		{
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[eMenu_SMITH_ITEM].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
			// ----
			gInterface.Data[eMenu_SMITH_ITEM].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 1000)
			{
				return;
			}
			// ----
			gInterface.Data[eMenu_SMITH_ITEM].EventTick = GetTickCount();
			

			gInterface.DrawSmithItem();
			gInterface.Data[eSMITH_MAIN].Open();

			this->CloseMenuWindowTwo();
			return;
		}
		if (gInterface.IsWorkZone(eMenu_JEWEL_BANK))
		{
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[eMenu_JEWEL_BANK].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
			// ----
			gInterface.Data[eMenu_JEWEL_BANK].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 1000)
			{
				return;
			}
			// ----
			gInterface.Data[eMenu_JEWEL_BANK].EventTick = GetTickCount();
			
			if (gJewelsBank.Active != true)
			{
				gJewelsBank.Active = true;
			}
			else
			{
				gJewelsBank.Active = false;
			}
			gInterface.Data[eJEWELBANK_MAIN].Close();

			this->CloseMenuWindowTwo();
			return;
		}
		if (gInterface.IsWorkZone(eMenu_CUSTOM_VIP))
		{
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[eMenu_CUSTOM_VIP].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
			// ----
			gInterface.Data[eMenu_CUSTOM_VIP].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 1000)
			{
				return;
			}
			// ----
			
			G_BEXO_MUA_VIP.OPEN_WINDOW_MUA_VIP();

			this->CloseMenuWindowTwo();
			return;
		}
		if (gInterface.IsWorkZone(eMenu_RANK_TITLE))
		{
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[eMenu_RANK_TITLE].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
			// ----
			gInterface.Data[eMenu_RANK_TITLE].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 1000)
			{
				return;
			}
			// ----
			
			G_BEXO_DANH_HIEU.OPEN_WINDOW_DANH_HIEU();

			this->CloseMenuWindowTwo();
			return;
		}
		if (gInterface.IsWorkZone(eMenu_TU_CHAN))
		{
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[eMenu_TU_CHAN].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
			// ----
			gInterface.Data[eMenu_TU_CHAN].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 1000)
			{
				return;
			}
			// ----
			
			gTuChanInterface.OpenTuChanWindow();

			this->CloseMenuWindowTwo();
			return;
		}
//----------------------------
		if (gInterface.IsWorkZone(eMenu_QUEST_SYSTEM))
		{
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[eMenu_QUEST_SYSTEM].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
			// ----
			gInterface.Data[eMenu_QUEST_SYSTEM].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 1000)
			{
				return;
			}
			// ----

			//gInterface.OpenWindowEx(exWinQuest);
			g_ExWinQuestSystem.SwitchStatsWindowState();			
			//g_ExWinQuestSystem.Draw();

			this->CloseMenuWindowTwo();
			return;
		}
//----------------------------
	}

}

bool Interface::MiniMapCheck()
{
	bool visual = false;

	if ( gInterface.CheckWindow(13) && gInterface.CheckWindow(Character)
    || gInterface.CheckWindow(8)
    || gInterface.CheckWindow(12)
    || gInterface.CheckWindow(9)
    || gInterface.CheckWindow(7)
    || gInterface.CheckWindow(14)
    || gInterface.CheckWindow(15)
    || gInterface.CheckWindow(60)
    || gInterface.CheckWindow(76) )
	{
		visual = true;
	}
	else
	{
		if ( gInterface.CheckWindow(16) && (gInterface.CheckWindow(4)||gInterface.CheckWindow(69)) )
		{
			visual = true;
		}
		else
		{
			if ( gInterface.CheckWindow(16) && gInterface.CheckWindow(11) )
			{
				visual = true;
			}
			else
			{
				if ( gInterface.CheckWindow(27) )
				{
					visual = true;
				}
				else
				{
					if ( gInterface.CheckWindow(13)
					|| gInterface.CheckWindow(16)
					|| gInterface.CheckWindow(3)
					|| gInterface.CheckWindow(21)
					|| gInterface.CheckWindow(6)
					|| gInterface.CheckWindow(22)
					|| gInterface.CheckWindow(23)
					|| gInterface.CheckWindow(24)
					|| gInterface.CheckWindow(4)
					|| gInterface.CheckWindow(18)
					|| gInterface.CheckWindow(10)
					|| gInterface.CheckWindow(5)
					|| gInterface.CheckWindow(25)
					|| gInterface.CheckWindow(26)
					|| gInterface.CheckWindow(19)
					|| gInterface.CheckWindow(20)
					|| gInterface.CheckWindow(58)
					|| gInterface.CheckWindow(59)
					|| gInterface.CheckWindow(62)
					|| gInterface.CheckWindow(73)
					|| gInterface.CheckWindow(68)
					|| gInterface.CheckWindow(69)
					|| gInterface.CheckWindow(70)
					|| gInterface.CheckWindow(66)
					|| gInterface.CheckWindow(75)
					|| gInterface.CheckWindow(74) )
					{
						visual = true;
					}
					else
					{
						if ( gInterface.CheckWindow(79) )
						{
							if ( gInterface.CheckWindow(80) )
							{
								visual = true;
							}
							else
							{
								visual = true;
							}	
						}
					}
				}
			}
		}
	}
  
	if ( gInterface.CheckWindow(77) )
	{
		if ( gInterface.CheckWindow(Warehouse) ||
			gInterface.CheckWindow(ChaosBox) ||
			gInterface.CheckWindow(Store) ||
			gInterface.CheckWindow(OtherStore) ||
			gInterface.CheckWindow(Character))
		{
			visual = true;
		}
		else
		{
			visual = true;
		}
	}
	else if ( gInterface.CheckWindow(78) )
	{
			visual = true;
	}
	return visual;
}

bool Interface::CombinedChecks()
{
	if ((this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Store)) ||
		(this->CheckWindow(Inventory)
		&& this->CheckWindow(Warehouse)
		&& this->CheckWindow(ExpandWarehouse)) ||
		(this->CheckWindow(Inventory)
		&& this->CheckWindow(Character)
		&& this->CheckWindow(Store)))
		return true;
	return false;
}

/*bool Interface::CheckMap()
{
	switch(gObjUser.m_MapNumber)
	{
		case eMapNumber::Lorencia:
			return false;
			break;
		case eMapNumber::Dungeon:
			return false;
			break;
		case eMapNumber::Devias:
			return false;
			break;
		case eMapNumber::Noria:
			return false;
			break;
		case eMapNumber::LostTower:
			return false;
			break;
		case eMapNumber::Stadium:
			return false;
		case eMapNumber::Atlans:
			return false;
			break;
		case eMapNumber::Tarkan:
			return false;
			break;
		case eMapNumber::Elbeland:
			return false;
			break;
		case eMapNumber::Icarus:
			return false;
			break;
		case eMapNumber::Trials:
			return false;
			break;
		case eMapNumber::Aida:
			return false;
			break;
		case eMapNumber::Crywolf:
			return false;
			break;
		case eMapNumber::Kanturu1:
			return false;
			break;
		case eMapNumber::Kanturu3:
			return false;
			break;
		case eMapNumber::Barracks:
			return false;
			break;
		case eMapNumber::Calmness:
			return false;
			break;
		case eMapNumber::Raklion:
			return false;
			break;
		case eMapNumber::Vulcanus:
			return false;
			break;
		case eMapNumber::Karutan1:
			return false;
			break;
		case eMapNumber::Karutan2:
			return false;
			break;
		default:
			return true;
			break;
	}
}*/

void Interface::CloseCustomWindow()
{
	this->CloseMenuWindow();
	this->CloseVipWindow();
	this->CloseVaultWindow();
	this->Data[eRankPANEL_MAIN].OnShow		= false;
	this->Data[eEventTimePANEL_MAIN].OnShow = false;
	this->Data[eCommand_MAIN].OnShow		= false;
	this->Data[ePARTYSETTINGS_MAIN].OnShow  = false;
	this->Data[eVAULT_MAIN].OnShow          = false;
	this->Data[eCHANGINGCLASS_MAIN].OnShow  = false;
	this->Data[eLuckyWheelMain].OnShow  = false;
	this->Data[eJEWELBANK_MAIN].OnShow  = false;
	this->Data[eSMITH_MAIN].OnShow  = false;
	this->Data[eCHANGE_RESET_MAIN].OnShow  = false;
	gJewelsBank.Active = false;
	this->Data[eCHANGE_RESET_MAIN].Close();

	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
}

void Interface::DrawItem(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse)
{

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Store)) 
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(Warehouse) 
		&& this->CheckWindow(ExpandWarehouse)) )
	{
		return;
	}

	pSetBlend(true);
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);

	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;

	if (ItemID == 406)
	{
		sub_6358A0_Addr(0.4, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else if (ItemID == 407)
	{
		sub_6358A0_Addr(0.5, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else
	{
		sub_6358A0_Addr(0.7, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}

	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0); 
	sub_635DE0_Addr();
	sub_635E40_Addr();

	glClear(0x100);

	VAngle v45;

	unsigned __int8 v44 = 1; //0 = parado / 1 = girando

	sub_6359B0_Addr(PosX, PosY, (int)&v45, 0); //posição do bmd
	sub_5CA0D0_Addr(ItemID, Level, Excl, Anc, (int)&v45, v44, 0); //funão que mostra o BMD
	
	sub_636720_Addr();

	glMatrixMode(0x1700);
	glPopMatrix();
	glMatrixMode(0x1701);
	glPopMatrix();

	sub_637770_Addr();

	glColor3f(1,1,1);
	pSetBlend(false);
}

void Interface::DrawConfirmOpen()
{
	if(!this->CheckWindow(Shop) && this->Data[eCONFIRM_MAIN].OnShow == true)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_OK].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_CANCEL].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if( !this->Data[eCONFIRM_MAIN].OnShow )
	{
		return;
	}

	float StartX;
	if( gProtect.m_MainInfo.CustomInterfaceType == 3 )
	{
		StartX = 205.0f;
	}
	else
	{
		StartX = 25.0f;
	}

	float MainWidth			= 230.0;
	float MainHeight		= 130.0;
	float StartBody			= 90.0;
	float StartY			= 90.0;
	
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(66));

	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 40, 210, 3, gCustomMessage.GetMessage(67));

	this->DrawButton(eCONFIRM_BTN_OK, (int)StartX+40, (int)StartBody + 70, 0, 0);

	if( this->IsWorkZone(eCONFIRM_BTN_OK) )
	{
		int ScaleY = 30;
		// ----
		if( this->Data[eCONFIRM_BTN_OK].OnClick )
		{
			ScaleY = 60;
		}
		// ----
		this->DrawButton(eCONFIRM_BTN_OK, (int)StartX+40, (int)StartBody + 70, 0, ScaleY);
	}

	this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX+140, (int)StartBody + 70, 0, 0);

	if( this->IsWorkZone(eCONFIRM_BTN_CANCEL) )
	{
		int ScaleY = 30;
		// ----
		if( this->Data[eCONFIRM_BTN_CANCEL].OnClick )
		{
			ScaleY = 60;
		}
		// ----
		this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX+140, (int)StartBody + 70, 0, ScaleY);
	}

}

bool Interface::EventConfirm_OK(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_OK].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_OK))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_OK].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].OnClick = false;;
	// ----
	if (Delay < 1000)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].EventTick = GetTickCount();

	PMSG_ITEM_BUY_RECV pMsg;

	pMsg.header.set(0xF3, 0xED,sizeof(pMsg));

	pMsg.slot = this->ConfirmSlot;

	DataSend((BYTE*)&pMsg,pMsg.header.size);

	this->Data[eCONFIRM_MAIN].OnShow = false;
	
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

bool Interface::EventConfirm_CANCEL(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_CANCEL].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_CANCEL))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_CANCEL].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].OnClick = false;;
	// ----
	if (Delay < 1000)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].EventTick = GetTickCount();

	this->Data[eCONFIRM_MAIN].OnShow = false;

	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

//-- advance
void Interface::DrawBarForm(float PosX, float PosY, float Width, float Height, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	pSetBlend(true);
	glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
	pDrawBarForm(PosX, PosY, Width, Height, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);
}
// ----------------------------------------------------------------------------------------------
bool Interface::CheckWindowEx(int WindowID)
{
	if (WindowID < 0 || WindowID > MAX_WINDOW_EX)
	{
		return 0;
	}
	return this->WindowEx[WindowID];
}

//---- cosas peladas

void Interface::UPDATE_FPS(){
	gInterface.frameCount++;
	if (GetTickCount() - gInterface.lastReport >= 1000)
	{
		gInterface.frameRate = gInterface.frameCount / ((GetTickCount() - gInterface.lastReport) / 1000);
		sprintf(gInterface.FPS_REAL, "FPS: %d", gInterface.frameRate);
		gInterface.lastReport = GetTickCount();
		gInterface.frameCount = 0;
	}

	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop) )
	{
		return;
	}

	this->DrawFormat(eGold, 600, 5, 80, 1, gInterface.FPS_REAL);
}

void Interface::guiMonitore(){
	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop))
	{
		return;
	}
	pSetBlend(true);
	glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
	pDrawBarForm(460.0, 0.0, 180.0, 20.0, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);
}

void Interface::DrawPing()
{
	gInterface.msPing = GetTickCount() - gInterface.lastSend;
	gInterface.iniciador = 3;
}

struct PMSG_PING
{
	PBMSG_HEAD h;
};

void Interface::SendPingRecv()
{
	if(gInterface.iniciador == 1)
	{
		PMSG_PING pMsgPing;
		pMsgPing.h.set(0xFF,sizeof(pMsgPing));
		gInterface.lastSend = GetTickCount();
		DataSend((BYTE*)&pMsgPing,sizeof(pMsgPing));
		gInterface.iniciador=2;
	}
	else if(gInterface.iniciador == 3)
	{
		if (GetTickCount() >= gInterface.lastSend + 1000){
			PMSG_PING pMsgPing;
			pMsgPing.h.set(0xFF,sizeof(pMsgPing));
			gInterface.lastSend = GetTickCount();
			DataSend((BYTE*)&pMsgPing,sizeof(pMsgPing));
			gInterface.iniciador=2;
		}
	}

	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop))
	{
		return;
	}
	sprintf(gInterface.ServerRTT, "RTT: %d ms", gInterface.msPing);
	sprintf(gInterface.ServerPing, "PING: %d ms", (gInterface.msPing/2));
	// ----
	gInterface.validar=0;

	if(gInterface.msPing > 0){
		//----
		this->DrawFormat(eGold, 470, 5, 120, 1, gInterface.ServerRTT);
		this->DrawFormat(eGold, 530, 5, 120, 1, gInterface.ServerPing);
		//--
		sprintf(gInterface.ultimoRTT, gInterface.ServerRTT);
		sprintf(gInterface.ultimoPing, gInterface.ServerPing);
		//--
		gInterface.ultimo_RTT = gInterface.msPing;
		gInterface.validar=1;
	}

	if(gInterface.validar==0)
	{
		if(gInterface.ultimo_RTT > 0)
		{
			this->DrawFormat(eGold, 470, 5, 80, 1, gInterface.ultimoRTT);
			this->DrawFormat(eGold, 530, 5, 120, 1, gInterface.ultimoPing);
		}
		else
		{
			this->DrawFormat(eGold, 470, 5, 120, 1, gInterface.ServerRTT);
			this->DrawFormat(eGold, 530, 5, 120, 1, gInterface.ServerPing);
		}
	}
}

void Interface::SwitchChatExpand()
{

	if((GetTickCount() - gInterface.Data[chatbackground].EventTick) < 1000 ||this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[chatbackground].EventTick = GetTickCount();

	if (SeparateChat != 0)
	{
		gInterface.DrawMessage(1, "Chat Window Separate [OFF]");
		SeparateChat = 0;
		WritePrivateProfileStringA("Setting","SeparateChat","0","./Settings.ini");
	}
	else 
	{
		gInterface.DrawMessage(1, "Chat Window Separate [ON]");
		SeparateChat = 1;
		WritePrivateProfileStringA("Setting","SeparateChat","1","./Settings.ini");
	}
	gChatExpanded.Switch();
}

void Interface::OpenConfig(int type)
{
	if(type == 0)
	{
		if( (GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 400 
			|| this->CheckWindow(ChatWindow) 
			|| this->CheckWindow(MuHelper) 
			|| this->CheckWindow(Inventory) 
			|| this->CheckWindow(Store) 
			|| this->CheckWindow(Character) 
			|| this->CheckWindow(CreateGuild) )
		{
			return;
		}

		gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

		if (pCheckWindow(pWindowThis(), 35))
		{
			pCloseWindow(pWindowThis(), 35);
		}
		else 
		{
			pOpenWindow(pWindowThis(), 35);
		}
	}
	else if(type == 1 )
	{
		if( (GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 400 || OpenSwicthSkill == 0)
		{
			return;
		}

		gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

		if (SkillPage == 1)
		{
			SkillPage = 2;
		}
		else
		{
			SkillPage = 1;
		}
	}

	PlayBuffer(25, 0, 0);
}
//-- SwitchCamera
void Interface::SwitchCamera()
{
	if( (GetTickCount() - gInterface.Data[eCamera3DSwitch].EventTick) < 1000 )
	{
		return;
	}

	if( pMapNumber == 62 )
	{
		gInterface.DrawMessage(1, "Camera3D not available for this map");
		gCamera.Restore();
	}

	gInterface.Data[eCamera3DSwitch].EventTick = GetTickCount();

	gCamera.Toggle();

	if (gCamera.getEnabled())
	{
		gInterface.DrawMessage(1, "Camera3D [ON]");
	}
	else
	{
		gInterface.DrawMessage(1, "Camera3D [OFF]");
	}
}
//-- CameraInit
void Interface::CameraInit(){

	if((GetTickCount() - gInterface.Data[eCamera3DInit].EventTick) < 1000 )
	{
		return;
	}

	gInterface.Data[eCamera3DInit].EventTick = GetTickCount();

	if (gCamera.getEnabled())
	{
		gInterface.DrawMessage(1, "Camera Restore [DEFAULT]");
		gCamera.Restore();
	}
}

bool Interface::Button(DWORD Event, int WinID, int ButtonID, bool Type)
{
	if (!this->IsWorkZone(ButtonID))
	{
		return false;
	}

	if (Type == true)
	{
		if (!this->Data[ButtonID].Attribute)
		{
			return false;
		}
	}

	// ----
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ButtonID].EventTick);
	// ----

	if (Event == WM_LBUTTONDOWN  && this->Data[ButtonID].OnClick == false)
	{
		this->Data[ButtonID].OnClick = true;
	}

	if (Event == WM_LBUTTONUP && this->Data[ButtonID].OnClick == true)
	{
		this->Data[ButtonID].OnClick = false;
		return true;
	}
	// ----
	if (Delay < 1000)
	{
		return false;
	}
	// ----
	this->Data[ButtonID].OnClick = false;
	// ----
	this->Data[ButtonID].EventTick = GetTickCount();
	// ----
	return false;
}

bool Interface::ButtonEx(DWORD Event, int ButtonID, bool Type)
{
	if (!this->IsWorkZone(ButtonID))
	{
		return false;
	}

	if (Type == true)
	{
		if (!this->Data[ButtonID].Attribute)
		{
			return false;
		}
	}

	// ----
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ButtonID].EventTick);
	// ----

	if (Event == WM_LBUTTONDOWN && this->Data[ButtonID].OnClick == false)
	{
		this->Data[ButtonID].OnClick = true;
		//return false;
	}

	if (Event == WM_LBUTTONUP && this->Data[ButtonID].OnClick == true)
	{
		this->Data[ButtonID].OnClick = false;
		return true;
	}
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[ButtonID].OnClick = false;
	// ----
	this->Data[ButtonID].EventTick = GetTickCount();
	// ----
	return false;
}

void Interface::DrawInterfaceS2Menu()
{
	if (IsWorkZone(eParty))
	{
		this->DrawToolTip(345, 420, "Party");
	}
	if (this->CheckWindow(Party))
	{
		gInterface.DrawButton(eParty, 348, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter))
	{
		this->DrawToolTip(375, 420, "Character");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter, 378.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory))
	{
		this->DrawToolTip(405, 420, "Inventory");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory, 409, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eShop))
	{
		this->DrawToolTip(430, 420, "CashShop");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop, 439.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eFriend))
	{
		this->DrawToolTip(580, 420, "Friends");
	}
	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eFriend, 581, 433, 0.0, 0.0);
	}
	if (IsWorkZone(eGuild))
	{
		this->DrawToolTip(580, 444, "Guild");
	}
	if (this->CheckWindow(Guild))
	{
		gInterface.DrawButton(eGuild, 581, 457, 0.0, 0.0);
	}
	if (IsWorkZone(eFastMenu))
	{
		this->DrawToolTip(13, 420, "System");
	}
	if (this->CheckWindow(FastMenu))
	{
		gInterface.DrawButton(eFastMenu, 6, 433, 0.0, 0.0);
	}
}
//--------------------------------------
void Interface::DrawInterface97Menu()
{
	if (IsWorkZone(eParty))
	{
		this->DrawToolTip(345, 420, "Party");
	}
	if (this->CheckWindow(Party))
	{
		gInterface.DrawButton(eParty, 348, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter))
	{
		this->DrawToolTip(375, 420, "Character");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter, 378.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory))
	{
		this->DrawToolTip(405, 420, "Inventory");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory, 409, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eShop))
	{
		this->DrawToolTip(430, 420, "CashShop");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop, 439.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eFriend))
	{
		this->DrawToolTip(580, 420, "Friends");
	}
	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eFriend, 581, 433, 0.0, 0.0);
	}
	if (IsWorkZone(eGuild))
	{
		this->DrawToolTip(580, 444, "Guild");
	}
	if (this->CheckWindow(Guild))
	{
		gInterface.DrawButton(eGuild, 581, 457, 0.0, 0.0);
	}
}
//--------------------------------------
void Interface::EventNewInterface_All(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	if (this->CheckWindow(ChaosBox))
	{
		return;
	}
	
	if (IsWorkZone(eFastMenu))
	{
		DWORD Delay = (CurrentTick - this->Data[eFastMenu].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eFastMenu].OnClick = true;
			return;
		}
		this->Data[eFastMenu].OnClick = false;
		if (Delay < 1000) {
			return;
		}
		this->Data[eFastMenu].EventTick = GetTickCount();
		if (this->CheckWindow(FastMenu)) {
				this->CloseWindow(FastMenu);
		}
		else {
			this->OpenWindow(FastMenu);
		}
	}
	else if (IsWorkZone(eParty))
	{
		DWORD Delay = (CurrentTick - this->Data[eParty].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eParty].OnClick = true;
			return;
		}
		this->Data[eParty].OnClick = false;
		if (Delay < 1000) {
			return;
		}
		this->Data[eParty].EventTick = GetTickCount();
		if (this->CheckWindow(Party)) {
			this->CloseWindow(Party);
		}
		else {
			this->OpenWindow(Party);
		}
	}
	
	else if (IsWorkZone(eCharacter))
	{
		DWORD Delay = (CurrentTick - this->Data[eCharacter].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCharacter].OnClick = true;
			return;
		}
		this->Data[eCharacter].OnClick = false;
		if (Delay < 1000) {
			return;
		}
		this->Data[eCharacter].EventTick = GetTickCount();
		if (this->CheckWindow(Character)) {
			this->CloseWindow(Character);
		}
		else {
			this->OpenWindow(Character);
		}
	}
	else if (IsWorkZone(eInventory))
	{
		DWORD Delay = (CurrentTick - this->Data[eInventory].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eInventory].OnClick = true;
			return;
		}
		this->Data[eInventory].OnClick = false;
		if (Delay < 1000) {
			return;
		}
		this->Data[eInventory].EventTick = GetTickCount();
		if (this->CheckWindow(Inventory)) {
			this->CloseWindow(Inventory);
		}
		else {
			this->OpenWindow(Inventory);
		}
	}
	else if (IsWorkZone(eFriend))
	{
		DWORD Delay = (CurrentTick - this->Data[eFriend].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eFriend].OnClick = true;
			return;
		}
		this->Data[eFriend].OnClick = false;
		if (Delay < 1000) {
			return;
		}
		this->Data[eFriend].EventTick = GetTickCount();
		if (this->CheckWindow(FriendList)) {
			this->CloseWindow(FriendList);
		}
		else {
			this->OpenWindow(FriendList);
		}
	}
	else if (IsWorkZone(eGuild))
	{
		DWORD Delay = (CurrentTick - this->Data[eGuild].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eGuild].OnClick = true;
			return;
		}
		this->Data[eGuild].OnClick = false;
		if (Delay < 1000) {
			return;
		}
		this->Data[eGuild].EventTick = GetTickCount();
		if (this->CheckWindow(Guild)) {
			this->CloseWindow(Guild);
		}
		else {
			this->OpenWindow(Guild);
		}
	}
}
void Interface::EventNewInterface97_All(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	if (this->CheckWindow(ChaosBox))
	{
		return;
	}
	
	if (IsWorkZone(eParty))
	{
		DWORD Delay = (CurrentTick - this->Data[eParty].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eParty].OnClick = true;
			return;
		}
		this->Data[eParty].OnClick = false;
		if (Delay < 1000) {
			return;
		}
		this->Data[eParty].EventTick = GetTickCount();
		if (this->CheckWindow(Party)) {
			this->CloseWindow(Party);
		}
		else {
			this->OpenWindow(Party);
		}
	}
	
	else if (IsWorkZone(eCharacter))
	{
		DWORD Delay = (CurrentTick - this->Data[eCharacter].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCharacter].OnClick = true;
			return;
		}
		this->Data[eCharacter].OnClick = false;
		if (Delay < 1000) {
			return;
		}
		this->Data[eCharacter].EventTick = GetTickCount();
		if (this->CheckWindow(Character)) {
			this->CloseWindow(Character);
		}
		else {
			this->OpenWindow(Character);
		}
	}
	else if (IsWorkZone(eInventory))
	{
		DWORD Delay = (CurrentTick - this->Data[eInventory].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eInventory].OnClick = true;
			return;
		}
		this->Data[eInventory].OnClick = false;
		if (Delay < 1000)
		{
			return;
		}
		this->Data[eInventory].EventTick = GetTickCount();
		if (this->CheckWindow(Inventory))
		{
			this->CloseWindow(Inventory);
		}
		else {
			this->OpenWindow(Inventory);
		}
	}
	else if (IsWorkZone(eFriend))
	{
		DWORD Delay = (CurrentTick - this->Data[eFriend].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eFriend].OnClick = true;
			return;
		}
		this->Data[eFriend].OnClick = false;
		if (Delay < 1000)
		{
			return;
		}
		this->Data[eFriend].EventTick = GetTickCount();
		if (this->CheckWindow(FriendList))
		{
			this->CloseWindow(FriendList);
		}
		else {
			this->OpenWindow(FriendList);
		}
	}
	else if (IsWorkZone(eGuild))
	{
		DWORD Delay = (CurrentTick - this->Data[eGuild].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eGuild].OnClick = true;
			return;
		}
		this->Data[eGuild].OnClick = false;
		if (Delay < 1000)
		{
			return;
		}
		this->Data[eGuild].EventTick = GetTickCount();
		if (this->CheckWindow(Guild))
		{
			this->CloseWindow(Guild);
		}
		else {
			this->OpenWindow(Guild);
		}
	}
}

void Interface::DrawInterfaceDragonLS3()
{
	if(this->CheckWindow(ObjWindow::CashShop)
		|| this->CheckWindow(ObjWindow::FullMap)
		|| this->CheckWindow(ObjWindow::SkillTree)
		|| this->CheckWindow(ObjWindow::MoveList)
		)
	{
		return;
	}
	this->DrawGUI(eDragonLeft, this->Data[eDragonLeft].X, this->Data[eDragonLeft].Y);
}

void Interface::DrawInterfaceDragonRS3()
{	
	if (this->MiniMapCheck()||(this->CheckWindow(SkillTree)|| this->CheckWindow(CashShop) || this->CheckWindow(FullMap)
		||this->CheckWindow(FastMenu)||this->CheckWindow(FriendList))
		|| pMapNumber == 39 //Kanturu
		|| pMapNumber == 58 //Selupam
		|| pMapNumber == 64 //Duel Arena
		|| pMapNumber == 65 //Doppelganger
		|| pMapNumber == 66 //Doppelganger
		|| pMapNumber == 67 //Doppelganger
		|| pMapNumber == 68 //Doppelganger
		|| pMapNumber == 69 //Imperial Guardian
		|| pMapNumber == 70 //Imperial Guardian
		|| pMapNumber == 71 //Imperial Guardian
		|| pMapNumber == 72 //Imperial Guardian
		|| pMapNumber == 11	//Blood Castle
		|| pMapNumber == 12	//Blood Castle
		|| pMapNumber == 13	//Blood Castle
		|| pMapNumber == 14	//Blood Castle
		|| pMapNumber == 15	//Blood Castle
		|| pMapNumber == 16	//Blood Castle
		|| pMapNumber == 17	//Blood Castle
		|| pMapNumber == 52	//Blood Castle
		|| pMapNumber == 9	//Devil Square
		|| pMapNumber == 32	//Devil Square
		|| pMapNumber == 18	//Chaos Castle
		|| pMapNumber == 19	//Chaos Castle
		|| pMapNumber == 20	//Chaos Castle
		|| pMapNumber == 21	//Chaos Castle
		|| pMapNumber == 22	//Chaos Castle
		|| pMapNumber == 23	//Chaos Castle
		|| pMapNumber == 53	//Chaos Castle
		|| pMapNumber == 45	//Illusion Temple
		|| pMapNumber == 46	//Illusion Temple
		|| pMapNumber == 47	//Illusion Temple
		|| pMapNumber == 48	//Illusion Temple
		|| pMapNumber == 49	//Illusion Temple
		|| pMapNumber == 50	//Illusion Temple
		|| pMapNumber == 18	//Chaos Castle
		|| pMapNumber == 19	//Chaos Castle
		|| pMapNumber == 20	//Chaos Castle
		|| pMapNumber == 21	//Chaos Castle
		|| pMapNumber == 22	//Chaos Castle
		|| pMapNumber == 23	//Chaos Castle
		|| pMapNumber == 53	//Chaos Castle
		|| pMapNumber == 34 //Crywolf
		|| pMapNumber == 30 //Valley/CastleSiege
		|| pMapNumber == 65 /*DuelArena*/)
	{
		return;
	}
	this->DrawGUI(eDragonRight, this->Data[eDragonRight].X, this->Data[eDragonRight].Y);
}

void Interface::DrawCoord()
{
	gObjUser.Refresh();

	if (*(DWORD*)MAIN_SCREEN_STATE == 5)
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		pDrawInterfaceNumBer(22, 461, gObjUser.lpViewPlayer->MapPosX, 1);
		pDrawInterfaceNumBer(46, 461, gObjUser.lpViewPlayer->MapPosY, 1);

	}
}

//============================================ PARTY SEARCH
int Interface::DrawToolTipEx(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	char Buff2[2048];
	int BuffLen	= sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----

	int LineCount = 0;

	strcpy(Buff2,Buff);

	char * Line = strtok(Buff2, "\n");
	// ----
	while( Line != NULL )
	{
		LineCount++;
		Line = strtok(NULL, "\n");
	}

	pSetBlend(1);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	pDrawBarForm(PosX, PosY, Width, LineCount*10, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();

	glColor3f(1.0, 1.0, 1.0);

	this->DrawFormat(eWhite, PosX, PosY, Width, Align, Buff);
	return 0;
}

void Interface::DrawColoredButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY, DWORD Color)
{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, PosX, PosY,
	this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY, Color);
}

void Interface::SwitchPartySettingsWindowState()
{
	Data[ePARTYSETTINGS_MAIN].OnShow == true? Data[ePARTYSETTINGS_MAIN].Close():Data[ePARTYSETTINGS_MAIN].Open();
}

void Interface::DrawPartySettingsWindow()
{
	if( !this->Data[ePARTYSETTINGS_MAIN].OnShow )
	{
		return;
	}
	// ----
	float MainWidth			= 230.0;
	float MainHeight		= 313.0;

	float StartX = this->ultimoX;
	float StartY = this->ultimoPTsearchY;
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
		StartY = this->ultimoPTsearchY + (curY - this->mY);
		StartX = StartX < -5 ? -5 : StartX;
		StartX = StartX > 465 ? 465 : StartX;
		StartY = StartY < 20 ? 20 : StartY;
		StartY = StartY > 95 ? 95 : StartY;
	}

	if (this->Moving && !(GetKeyState(VK_LBUTTON) & 0x8000)) {
		this->Moving = false;
		this->ultimoX = StartX;
		this->ultimoPTsearchY = StartY;
	}
	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight + 30, 0, 0);
	this->DrawGUI2(ePARTYSETTINGS_CLOSE, StartX + MainWidth - this->Data[ePARTYSETTINGS_CLOSE].Width, StartY);

	// ----
	if( this->IsWorkZone(ePARTYSETTINGS_CLOSE) )
	{
		DWORD Color = eGray100;
		// ----
		if( this->Data[ePARTYSETTINGS_CLOSE].OnClick )
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI2(ePARTYSETTINGS_CLOSE, this->Data[ePARTYSETTINGS_CLOSE].X, this->Data[ePARTYSETTINGS_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[ePARTYSETTINGS_CLOSE].X + 5, this->Data[ePARTYSETTINGS_CLOSE].Y + 25, "Cerrar");
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, StartY + 10, 210, 3, "Party Search Settings");
///////////////////////////////////////////ACTIVE SYSTEM///////////////////////////////////////////
	this->DrawFormat(eWhite, StartX + 40, StartY + 33, 200, 1, "Activar Sistema");

	if (gPartySearchSettings.m_SystemActive == false)
	{
		this->DrawButton2(ePARTYSETTINGS_SYSTEM_ACTIVE, StartX + 60 + 110, StartY + 30, 0, 0);
	}
	else
	{
		this->DrawButton2(ePARTYSETTINGS_SYSTEM_ACTIVE, StartX + 60 + 110, StartY + 30, 0, 15);
	}
	//this->DrawGUI(ePARTYSETTINGS_DIV, StartX , StartY - 60); // Äåëèòåëü áîëüøîé
/////////////////////////////////////////ACTIVE SYSTEM END/////////////////////////////////////////

/////////////////////////////////////////////MAX LEVEL/////////////////////////////////////////////
	this->DrawFormat(eWhite, StartX + 40, StartY + 60, 200, 1, "Max Level");
	this->DrawGUI(ePARTYSETTINGS_DIV, StartX , StartY + 67); // Äåëèòåëü áîëüøîé


	this->DrawToolTip(StartX + 174, StartY + 62, "%d", gPartySearchSettings.m_Level);

	if (gPartySearchSettings.m_SystemActive == 0)
	{
		this->DrawColoredButton(ePARTYSETTINGS_LEVEL_MINUS, StartX + 150, StartY + 57, 0, 0, eGray150); // 
	}
	else
	{
		this->DrawButton2(ePARTYSETTINGS_LEVEL_MINUS, StartX + 150, StartY + 57, 0, 0); // 

		if(this->IsWorkZone(ePARTYSETTINGS_LEVEL_MINUS) )
		{
			if( this->Data[ePARTYSETTINGS_LEVEL_MINUS].OnClick )
			{
				this->DrawButton2(ePARTYSETTINGS_LEVEL_MINUS, StartX + 150, StartY + 57, 0, 16);
			}
		}
	}

	if (gPartySearchSettings.m_SystemActive == 0)
	{
		this->DrawColoredButton(ePARTYSETTINGS_LEVEL_PLUS, StartX + 193, StartY + 57, 0, 0, eGray150); //
	}
	else
	{
		this->DrawButton2(ePARTYSETTINGS_LEVEL_PLUS, StartX + 193, StartY + 57, 0, 0); //

		if(this->IsWorkZone(ePARTYSETTINGS_LEVEL_PLUS) )
		{
			if( this->Data[ePARTYSETTINGS_LEVEL_PLUS].OnClick )
			{
				this->DrawButton2(ePARTYSETTINGS_LEVEL_PLUS, StartX + 193, StartY+ 57, 0, 16);
			}
		}
	}

///////////////////////////////////////////MAX LEVEL END///////////////////////////////////////////

///////////////////////////////////////////////GUILD///////////////////////////////////////////////

	this->DrawFormat(eWhite, StartX + 40, StartY + 87, 200, 1, "Only Guild");

	if (gPartySearchSettings.m_SystemActive)
	{
		if (gPartySearchSettings.m_OnlyGuild == false)
		{
			this->DrawButton2(ePARTYSETTINGS_ONLY_GUILD, StartX + 60 + 110, StartY + 83, 0, 0);
		}
		else
		{
			this->DrawButton2(ePARTYSETTINGS_ONLY_GUILD, StartX + 60 + 110, StartY + 83, 0, 15);
		}
	}
	else
	{
		this->DrawButton2(ePARTYSETTINGS_ONLY_GUILD, StartX + 60 + 110, StartY + 83, 0, 30);
	}

	pDrawGUI(0x7B5E, StartX + 30, StartY + 100, 82.0, 2.0); // Äåëèòåëü ìåëêèé 1
	pDrawGUI(0x7B5E, StartX + 30 + 82, StartY + 100, 82.0, 2.0); // Äåëèòåëü ìåëêèé 2

	this->DrawFormat(eWhite, StartX + 40, StartY + 109, 200, 1, "Only One Class");

	if (gPartySearchSettings.m_SystemActive)
	{
		if (gPartySearchSettings.m_OneClass == false)
		{
			this->DrawButton2(ePARTYSETTINGS_ONE_CLASS, StartX + 60 + 110, StartY + 105, 0, 0);
		}
		else
		{
			this->DrawButton2(ePARTYSETTINGS_ONE_CLASS, StartX + 60 + 110, StartY + 105, 0, 15);
		}
	}
	else
	{
		this->DrawButton2(ePARTYSETTINGS_ONE_CLASS, StartX + 60 + 110, StartY + 105, 0, 30);
	}

	this->DrawGUI(ePARTYSETTINGS_DIV, StartX , StartY + 115);// 94 // Äåëèòåëü áîëüøîé
/////////////////////////////////////////////GUILD END/////////////////////////////////////////////
	char szCharNames[7][32] = 
	{
		"Dark Wizard",
		"Dard Knight",
		"Elf",
		"Magic Gladiator",
		"Dark Lord",
		"Summoner",
		"Rage Fighter"
	};

	int ObjectIDs[7] = 
	{ 
		ePARTYSETTINGS_DARK_WIZARD, 
		ePARTYSETTINGS_DARK_KNIGHT, 
		ePARTYSETTINGS_ELF, 
		ePARTYSETTINGS_MAGIC_GLADIATOR, 
		ePARTYSETTINGS_DARK_LORD, 
		ePARTYSETTINGS_SUMMONER, 
		ePARTYSETTINGS_RAGE_FIGHTER
	};

	for (int i = 0; i<7; i++)
	{
		this->DrawFormat(eWhite, StartX + 40, StartY + 135 + (i * 22), 200, 1, szCharNames[i]);

		bool ClassValue = 0;
		switch (i)
		{
			case 0:
				ClassValue = gPartySearchSettings.m_DarkWizard;
				break;
			case 1:
				ClassValue = gPartySearchSettings.m_DarkKnight;
				break;
			case 2:
				ClassValue = gPartySearchSettings.m_Elf;
				break;
			case 3:
				ClassValue = gPartySearchSettings.m_MagicGladiator;
				break;
			case 4:
				ClassValue = gPartySearchSettings.m_DarkLord;
				break;
			case 5:
				ClassValue = gPartySearchSettings.m_Summoner;
				break;
			case 6:
				ClassValue = gPartySearchSettings.m_RageFighter;
				break;
		}

		if (gPartySearchSettings.m_SystemActive)
		{
			if (ClassValue == false)
			{
				this->DrawButton2(ObjectIDs[i], StartX + 60 + 110, StartY + 131 + (i * 22), 0, 0);
			}
			else
			{
				this->DrawButton2(ObjectIDs[i], StartX + 60 + 110, StartY + 131 + (i * 22), 0, 15);
			}
		}
		else
		{
			this->DrawButton2(ObjectIDs[i], StartX + 60 + 110, StartY + 131 + (i * 22), 0, 30);
		}

		pDrawGUI(0x7B5E, StartX + 30, StartY + 148 + (i * 22), 82.0, 2.0); // Äåëèòåëü ìåëêèé 1
		pDrawGUI(0x7B5E, StartX + 30 + 82, StartY + 148 + (i * 22), 82.0, 2.0); // Äåëèòåëü ìåëêèé 2
	}

	this->DrawGUI(ePARTYSETTINGS_DIV, StartX , StartY + 290); // Äåëèòåëü áîëüøîé

	//if (gPartySearchSettings.m_SystemActive)
	//{
		this->DrawButton2(ePARTYSETTINGS_OK, StartX + this->Data[ePARTYSETTINGS_MAIN].Width/2-this->Data[ePARTYSETTINGS_OK].Width/2, StartY + 310, 0, 0);

		if( this->IsWorkZone(ePARTYSETTINGS_OK) )
		{
			int ScaleY = 30;
			// ----
			if( this->Data[ePARTYSETTINGS_OK].OnClick )
			{
				ScaleY = 60;
			}
			// ----
			this->DrawButton2(ePARTYSETTINGS_OK, StartX + this->Data[ePARTYSETTINGS_MAIN].Width/2-this->Data[ePARTYSETTINGS_OK].Width/2, StartY + 310, 0, ScaleY);
		}
	//}

}

bool Interface::EventPartySettingsWindow_Main(DWORD Event)
{
	this->EventPartySettingsWindow_Close(Event);
	this->EventPartySettingsWindow_All(Event);
	// ----
	// ----
	return true;
}

bool Interface::EventPartySettingsWindow_All(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	//DWORD Delay			= (CurrentTick - this->Data[eDIABLO_CLOSE].EventTick);
	if( !this->Data[ePARTYSETTINGS_MAIN].OnShow )
	{
		return false;
	}

	if (IsWorkZone(ePARTYSETTINGS_SYSTEM_ACTIVE))
	{
		DWORD Delay			= (CurrentTick - this->Data[ePARTYSETTINGS_SYSTEM_ACTIVE].EventTick);

		if( Event == WM_LBUTTONDOWN )
		{
			this->Data[ePARTYSETTINGS_SYSTEM_ACTIVE].OnClick = true;
			return true;
		}
		// ----
		this->Data[ePARTYSETTINGS_SYSTEM_ACTIVE].OnClick = false;
		// ----
		if( Delay < 1000 )
		{
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_SYSTEM_ACTIVE].EventTick = GetTickCount();
		gPartySearchSettings.m_SystemActive ^= 1;

		for (int i=0;i<7;i++)
		{
			gPartySearchSettings.m_SystemActive==true?gPartySearchSettings.SetClassValue(i,true):gPartySearchSettings.SetClassValue(i,false);
		}
	}

	if (IsWorkZone(ePARTYSETTINGS_LEVEL_MINUS))
	{
		if (gPartySearchSettings.m_SystemActive == 0)
		{
			return false;
		}

		DWORD Delay			= (CurrentTick - this->Data[ePARTYSETTINGS_LEVEL_MINUS].EventTick);

		if( Event == WM_LBUTTONDOWN )
		{
			this->Data[ePARTYSETTINGS_LEVEL_MINUS].OnClick = true;
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_LEVEL_MINUS].OnClick = false;
		// ----
		if( Delay < 200 )
		{
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_LEVEL_MINUS].EventTick = GetTickCount();

		gPartySearchSettings.m_Level -= 10;
		if (gPartySearchSettings.m_Level<=0)
		{
			gPartySearchSettings.m_Level = 0;
		}
	}

	if (IsWorkZone(ePARTYSETTINGS_LEVEL_PLUS))
	{
		if (gPartySearchSettings.m_SystemActive == 0)
		{
			return false;
		}

		DWORD Delay			= (CurrentTick - this->Data[ePARTYSETTINGS_LEVEL_PLUS].EventTick);

		if( Event == WM_LBUTTONDOWN )
		{
			this->Data[ePARTYSETTINGS_LEVEL_PLUS].OnClick = true;
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_LEVEL_PLUS].OnClick = false;
		// ----
		if( Delay < 200 )
		{
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_LEVEL_PLUS].EventTick = GetTickCount();

		gPartySearchSettings.m_Level += 10;
		if (gPartySearchSettings.m_Level>=400)
		{
			gPartySearchSettings.m_Level = 400;
		}
	}

	if (IsWorkZone(ePARTYSETTINGS_ONLY_GUILD))
	{
		DWORD Delay			= (CurrentTick - this->Data[ePARTYSETTINGS_ONLY_GUILD].EventTick);

		if( Event == WM_LBUTTONDOWN )
		{
			this->Data[ePARTYSETTINGS_ONLY_GUILD].OnClick = true;
			return true;
		}
		// ----
		this->Data[ePARTYSETTINGS_ONLY_GUILD].OnClick = false;
		// ----
		if( Delay < 1000 )
		{
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_ONLY_GUILD].EventTick = GetTickCount();
		gPartySearchSettings.m_OnlyGuild ^= 1;
	}

	if (IsWorkZone(ePARTYSETTINGS_ONE_CLASS))
	{
		DWORD Delay			= (CurrentTick - this->Data[ePARTYSETTINGS_ONE_CLASS].EventTick);

		if( Event == WM_LBUTTONDOWN )
		{
			this->Data[ePARTYSETTINGS_ONE_CLASS].OnClick = true;
			return true;
		}
		// ----
		this->Data[ePARTYSETTINGS_ONE_CLASS].OnClick = false;
		// ----
		if( Delay < 1000 )
		{
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_ONE_CLASS].EventTick = GetTickCount();
		gPartySearchSettings.m_OneClass ^= 1;

		for (int i=0;i<7;i++)
		{
			gPartySearchSettings.m_OneClass==false?gPartySearchSettings.SetClassValue(i,true):gPartySearchSettings.SetClassValue(i,false);

		}
	}

	if (IsWorkZone(ePARTYSETTINGS_OK))
	{

		DWORD Delay			= (CurrentTick - this->Data[ePARTYSETTINGS_OK].EventTick);

		if( Event == WM_LBUTTONDOWN )
		{
			this->Data[ePARTYSETTINGS_OK].OnClick = true;
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_OK].OnClick = false;
		// ----
		if( Delay < 1000 )
		{
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_OK].EventTick = GetTickCount();
		gPartySearchSettings.CGSendPartySearchAdd();
		this->SwitchPartySettingsWindowState();
	}

	int ObjectIDs[7] = 
	{ 
		ePARTYSETTINGS_DARK_WIZARD, 
		ePARTYSETTINGS_DARK_KNIGHT, 
		ePARTYSETTINGS_ELF, 
		ePARTYSETTINGS_MAGIC_GLADIATOR, 
		ePARTYSETTINGS_DARK_LORD, 
		ePARTYSETTINGS_SUMMONER, 
		ePARTYSETTINGS_RAGE_FIGHTER
	};

	for (int i = 0; i<7; i++)
	{
		if (IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay			= (CurrentTick - this->Data[ObjectIDs[i]].EventTick);

			if( Event == WM_LBUTTONDOWN )
			{
				this->Data[ObjectIDs[i]].OnClick = true;
				return true;
			}
			// ----
			this->Data[ObjectIDs[i]].OnClick = false;
			// ----
			if( Delay < 1000 )
			{
				return false;
			}
			// ----
			this->Data[ObjectIDs[i]].EventTick = GetTickCount();
			gPartySearchSettings.ChangeClassValue(i);

			if (gPartySearchSettings.m_OneClass == true)
			{
				gPartySearchSettings.m_OneClass = false;
			}
		}
	}
	return false;
}

bool Interface::EventPartySettingsWindow_Close(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[ePARTYSETTINGS_CLOSE].EventTick);
	// ----
	if( !this->Data[ePARTYSETTINGS_MAIN].OnShow || !IsWorkZone(ePARTYSETTINGS_CLOSE) )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[ePARTYSETTINGS_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[ePARTYSETTINGS_CLOSE].OnClick = false;
	// ----
	if( Delay < 1000 )
	{
		return false;
	}
	// ----
	this->Data[ePARTYSETTINGS_CLOSE].EventTick = GetTickCount();
	this->Data[ePARTYSETTINGS_MAIN].Close();
	// ----
	return false;
}

void Interface::DrawPartySearchWindow()
{
	if (!this->Data[ePARTYSEARCH_MAIN].OnShow)
	{
		return;
	}
	// ----
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 50.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	// ----
	this->DrawGUI(ePARTYSEARCH_MAIN, StartX, StartY + 2);
	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);
	this->DrawGUI(ePARTYSEARCH_CLOSE, StartX + MainWidth - this->Data[ePARTYSEARCH_CLOSE].Width + 2, 49);
	// ----
	if (this->IsWorkZone(ePARTYSEARCH_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[ePARTYSEARCH_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(ePARTYSEARCH_CLOSE, this->Data[ePARTYSEARCH_CLOSE].X, this->Data[ePARTYSEARCH_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[ePARTYSEARCH_CLOSE].X + 5, this->Data[ePARTYSEARCH_CLOSE].Y + 25, "Close");
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, 60, 210, 3, "Party Search");
	// ----
	int x = GetPrivateProfileIntA("Graphics", "X", 0, "./Settings.ini");
	int y = GetPrivateProfileIntA("Graphics", "Y", 0, "./Settings.ini");
	// ----
	this->DrawFormat(eWhite, StartX + 20, this->Data[ePARTYSEARCH_MAIN].Y + 34, 20, 1, "Status:");

	
	this->DrawFormat(eShinyGreen, StartX + 42, this->Data[ePARTYSEARCH_MAIN].Y + 34, 20, 1, "ON");
	

	// ----
	this->DrawGUI(ePARTYSETTINGS_DIV, StartX, this->Data[ePARTYSEARCH_MAIN].Y + 40); // Äåëèòåëü áîëüøîé
	// ----
	this->DrawFormat(eWhite, StartX + 5, this->Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "Player");
	// ----
	this->DrawFormat(eWhite, StartX + 45, this->Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "Map");
	// ----
	this->DrawFormat(eWhite, StartX + 95, this->Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "X");
	// ----
	this->DrawFormat(eWhite, StartX + 115, this->Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "Y");
	// ----
	this->DrawFormat(eWhite, StartX + 140, this->Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "Count");
	// ----
	this->DrawFormat(eWhite, StartX + 170, this->Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "Join");
	// ----
	this->DrawGUI(ePARTYSETTINGS_DIV, StartX, this->Data[ePARTYSEARCH_MAIN].Y + 60); // Äåëèòåëü áîëüøîé
	// ----
	if (gPartySearch.CountPages>1)
	{
		this->DrawFormat(eGold, StartX + 104, 379, 20, 3, "%d/%d", gPartySearch.Page + 1, gPartySearch.CountPages);
	}

	if (gPartySearch.Page + 1 > 1)
	{
		this->DrawButton(ePARTYSEARCH_LEFT, StartX + 73, 372, 0, 0);
	}

	if (gPartySearch.Page + 1 < gPartySearch.CountPages)
	{
		this->DrawButton(ePARTYSEARCH_RIGHT, StartX + 73 + 60, 372, 0, 0);
	}

	int DrawnItems = 0;

	for (int i = 0; i<gPartySearch.ListsCount; i++)
	{
		if (DrawnItems >= 10)
		{
			break;
		}

		PARTYLIST* info = gPartySearch.GetPartyList(i + (10 * gPartySearch.Page));

		if (info == 0)
		{
			continue;
		}

		pDrawGUI(0x7916, StartX + 10, this->Data[ePARTYSEARCH_MAIN].Y + 80 + (20 * i), 170, 21);

		this->DrawFormat(eYellow, StartX + 15, this->Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 1, info->Name);

		this->DrawFormat(eWhite, StartX + 45, this->Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, pGetMapName(info->Map));

		this->DrawFormat(eWhite, StartX + 95, this->Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, "%d", info->X);

		this->DrawFormat(eWhite, StartX + 115, this->Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, "%d", info->Y);

		this->DrawFormat(eWhite, StartX + 140, this->Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, "%d / 5", info->Count);

		pDrawGUI(0x7915, StartX + 178, this->Data[ePARTYSEARCH_MAIN].Y + 80 + (i * 20), 22, 19);

		if (info->ButtonActive == true)
		{
			pDrawButton(0x7AA4, StartX + 203, this->Data[ePARTYSEARCH_MAIN].Y + 82 + (i * 20), 16, 15, 0, 0);
		}

		int X = StartX + 203;
		int Y = this->Data[ePARTYSEARCH_MAIN].Y + 82 + (i * 20);
		int MaxX = X + 16;
		int MaxY = Y + 15;

		if (info->ButtonActive == true)
		{
			if (IsWorkZone3(X, Y, MaxX, MaxY)) // modificaque aki
			{
				pDrawColorButton(0x7AA4, X, Y, 16, 15, 0, 16, eGray100);
				//pDrawButton(0x7AA4, X, Y,16, 15, 0, 16);
			}
		}

		DrawnItems++;
	}

	DrawnItems = 0;

	for (int i = 0; i<gPartySearch.ListsCount; i++)
	{
		if (DrawnItems >= 10)
		{
			break;
		}

		PARTYLIST* info = gPartySearch.GetPartyList(i + (10 * gPartySearch.Page));

		if (info == 0)
		{
			continue;
		}

		int X = StartX + 178;
		int Y = this->Data[ePARTYSEARCH_MAIN].Y + 80 + (i * 20);
		int MaxX = X + 22;
		int MaxY = Y + 19;

		if (IsWorkZone3(X, Y, MaxX, MaxY))// modifique aki
		{
			char szText[2048];
			sprintf(szText, "Need to Party:\n_____________________\nLevel:%d", info->Level);

			if (info->DarkWizard == true)
			{
				strcat(szText, "\nDark Wizard");
			}
			if (info->DarkKnight == true)
			{
				strcat(szText, "\nDark Knight");
			}
			if (info->Elf == true)
			{
				strcat(szText, "\nElf");
			}
			if (info->MagicGladiator == true)
			{
				strcat(szText, "\nMagic Gladiator");
			}
			if (info->DarkLord == true)
			{
				strcat(szText, "\nDark Lord");
			}
			if (info->Summoner == true)
			{
				strcat(szText, "\nSummoner");
			}
			if (info->RageFighter == true)
			{
				strcat(szText, "\nRage Fighter");
			}
			if (info->OnlyGuild == true)
			{
				strcat(szText, "\nOnly Guild");
			}

			strcat(szText, "\n_____________________");


			glColor4f(0.0, 0.0, 0.0, 0.8);
			pDrawBarForm((float)(StartX + 230), (float)(this->Data[ePARTYSEARCH_MAIN].Y + 62 + (i * 20)), 100.0f, 110.0f, 0.0f, 0);


			gCustomRankUser.DrawFormat(eWhite, StartX + 230, this->Data[ePARTYSEARCH_MAIN].Y + 62 + (i * 20), 100, 3, szText);
		}

		DrawnItems++;
	}

	if (gPartySearch.Page + 1 > 1)
	{
		if (IsWorkZone(ePARTYSEARCH_LEFT))
		{
			if (this->Data[ePARTYSEARCH_LEFT].OnClick)
			{
				this->DrawButton(ePARTYSEARCH_LEFT, StartX + 73, 372, 0, 46);
				return;
			}
			this->DrawButton(ePARTYSEARCH_LEFT, StartX + 73, 372, 0, 23);
		}
	}
	if (gPartySearch.Page + 1 < gPartySearch.CountPages)
	{
		if (IsWorkZone(ePARTYSEARCH_RIGHT))
		{
			if (this->Data[ePARTYSEARCH_RIGHT].OnClick)
			{
				this->DrawButton(ePARTYSEARCH_RIGHT, StartX + 73 + 60, 372, 0, 46);
				return;
			}
			this->DrawButton(ePARTYSEARCH_RIGHT, StartX + 73 + 60, 372, 0, 23);
		}
	}
}


void Interface::EventPartySearchWindow_All(DWORD Event)
{
	float StartX			= (MAX_WIN_WIDTH / 2) - (230.0 / 2);
	DWORD CurrentTick	= GetTickCount();
	//DWORD Delay			= (CurrentTick - this->Data[eDIABLO_CLOSE].EventTick);
	if( !this->Data[ePARTYSEARCH_MAIN].OnShow )
	{
		return;
	}

	if (IsWorkZone(ePARTYSEARCH_CLOSE))
	{
		DWORD Delay			= (CurrentTick - this->Data[ePARTYSEARCH_CLOSE].EventTick);

		if( Event == WM_LBUTTONDOWN )
		{
			this->Data[ePARTYSEARCH_CLOSE].OnClick = true;
			return;
		}
		// ----
		this->Data[ePARTYSEARCH_CLOSE].OnClick = false;
		// ----
		if( Delay < 500 )
		{
			return;
		}
		// ----
		this->Data[ePARTYSEARCH_CLOSE].EventTick = GetTickCount();
		this->SwitchPartySearchWindowState();
	}
	if( IsWorkZone(ePARTYSEARCH_LEFT) && gPartySearch.Page+1 > 1)
	{
		DWORD Delay	= (CurrentTick - this->Data[ePARTYSEARCH_LEFT].EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			this->Data[ePARTYSEARCH_LEFT].OnClick = true;
			return;
		}
		// ----
		this->Data[ePARTYSEARCH_LEFT].OnClick = false;
		// ----
		if( Delay < 100 )
		{
			return;
		}
		// ----
		this->Data[ePARTYSEARCH_LEFT].EventTick = GetTickCount();
		// ----
		gPartySearch.Page--;
		//gPartySearch.DrawnItems = 0;
	}
	if( IsWorkZone(ePARTYSEARCH_RIGHT) && gPartySearch.Page+1 < gPartySearch.CountPages )
	{
		DWORD Delay	= (CurrentTick - this->Data[ePARTYSEARCH_RIGHT].EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			this->Data[ePARTYSEARCH_RIGHT].OnClick = true;
			return;
		}
		// ----
		this->Data[ePARTYSEARCH_RIGHT].OnClick = false;
		// ----
		if( Delay < 100 )
		{
			return;
		}
		// ----
		this->Data[ePARTYSEARCH_RIGHT].EventTick = GetTickCount();
		// ----
		gPartySearch.Page++;
		//gPartySearch.DrawnItems = 0;
	}

	int DrawnItems = 0;

	for (int i=0;i<gPartySearch.ListsCount;i++)
	{
		if (DrawnItems >= 10)
		{
			break;
		}
		//pDrawButton(0x7AA4, StartX + 203, this->Data[ePARTYSEARCH_MAIN].Y + 82+(i*20),16, 15, 0, 0);
		if (IsWorkZone3(StartX + 203,this->Data[ePARTYSEARCH_MAIN].Y + 82+(i*20),StartX + 203 + 16, this->Data[ePARTYSEARCH_MAIN].Y + 82+(i*20)+15)) // modifique aki
		{
			DWORD Delay	= (CurrentTick - this->Data[ePARTYSEARCH_RIGHT].EventTick);
			// ----
			if( Event == WM_LBUTTONDOWN )
			{
				this->Data[ePARTYSEARCH_RIGHT].OnClick = true;
				return;
			}
			// ----
			this->Data[ePARTYSEARCH_RIGHT].OnClick = false;
			// ----
			if( Delay < 100 )
			{
				return;
			}
			// ----
			if (gPartySearch.gPartyList[i+(10*gPartySearch.Page)].ButtonActive == false)
			{
				return;
			}
			// ----
			this->Data[ePARTYSEARCH_RIGHT].EventTick = GetTickCount();
			// ----
			gPartySearch.SendPartyRequest(i+(10*gPartySearch.Page));
			////console.Log("", "Map = %s", pGetMapName(info->Map));
		}
	}
}

// ========================================================== END PARTY SEARCH


//============================================ MULTIWARE
void Interface::DrawVaultWindow()
{
	if (!this->Data[eVAULT_MAIN].OnShow)
	{
		return;
	}
	// ----

	if(gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
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
		gInterface.CloseVaultWindow();
		gInterface.Data[eVAULT_MAIN].Close();
		return;
	}
	
	float MainWidth = 230.0;
	float MainHeight = 280.0;
	float StartX = this->ultimoX;
	float StartY = this->ultimoWareY;
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
		StartY = this->ultimoWareY + (curY - this->mY);
		StartX = StartX < -5 ? -5 : StartX;
		StartX = StartX > 465 ? 465 : StartX;
		StartY = StartY < 20 ? 20 : StartY;
		StartY = StartY > 95 ? 95 : StartY;
	}

	if (this->Moving && !(GetKeyState(VK_LBUTTON) & 0x8000)) {
		this->Moving = false;
		this->ultimoX = StartX;
		this->ultimoWareY = StartY;
	}

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	this->DrawGUI2(eVAULT_CLOSE, StartX + MainWidth - this->Data[eVAULT_CLOSE].Width, StartY);
	// ----
	if (this->IsWorkZone(eVAULT_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eVAULT_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI2(eVAULT_CLOSE, this->Data[eVAULT_CLOSE].X, this->Data[eVAULT_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eVAULT_CLOSE].X + 5, this->Data[eVAULT_CLOSE].Y + 25, "Close");
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, StartY + 10, 210, 3, "Multi Vault System");
	// ----
	this->DrawFormat(eRed, StartX + 10, StartY + 32, 210, 3, "Choose Ware!");
	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartY + 50, 200, 1); //-- Divisor
//------------------------------------------------------------------------------------------------------------
	this->DrawGUI2(eVAULT_FINISH, StartX + 6, StartY + 70);
	this->DrawFormat(eWhite, StartX - 40, StartY + 80, 210, 3, "Vault");
	this->Data[eVAULT_FINISH].Attribute = true;
	// ----
	if (IsWorkZone(eVAULT_FINISH))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eVAULT_FINISH].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI2(eVAULT_FINISH, this->Data[eVAULT_FINISH].X, this->Data[eVAULT_FINISH].Y, Color);
	}
	// ----
//--------------------------------------------------------------------------------------
	this->DrawGUI2(eWARE1_FINISH, StartX + 6 + 105, StartY + 70);
	this->DrawFormat(eWhite, StartX + 60, StartY + 80, 210, 3, "Ware 1");
	this->Data[eWARE1_FINISH].Attribute = true;
	// ----
	if (IsWorkZone(eWARE1_FINISH))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eWARE1_FINISH].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI2(eWARE1_FINISH, this->Data[eWARE1_FINISH].X, this->Data[eWARE1_FINISH].Y, Color);
	}
//--------------------------------------------------------------------------------------
	this->DrawGUI2(eWARE2_FINISH, StartX + 6, StartY + 105);
	this->DrawFormat(eWhite, StartX -40, StartY + 115, 210, 3, "Ware 2");
	this->Data[eWARE2_FINISH].Attribute = true;
	// ----
	if (IsWorkZone(eWARE2_FINISH))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eWARE2_FINISH].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI2(eWARE2_FINISH, this->Data[eWARE2_FINISH].X, this->Data[eWARE2_FINISH].Y, Color);
	}
//--------------------------------------------------------------------------------------
	this->DrawGUI2(eWARE3_FINISH, StartX + 6 + 105, StartY + 105);
	this->DrawFormat(eWhite, StartX + 60, StartY + 115, 210, 3, "Ware 3");
	this->Data[eWARE3_FINISH].Attribute = true;
	// ----
	if (IsWorkZone(eWARE3_FINISH))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eWARE3_FINISH].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI2(eWARE3_FINISH, this->Data[eWARE3_FINISH].X, this->Data[eWARE3_FINISH].Y, Color);
	}
//--------------------------------------------------------------------------------------
	this->DrawGUI2(eWARE4_FINISH, StartX + 6, StartY + 140);
	this->DrawFormat(eWhite, StartX - 40, StartY + 150, 210, 3, "Ware 4");
	this->Data[eWARE4_FINISH].Attribute = true;
	// ----
	if (IsWorkZone(eWARE4_FINISH))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eWARE4_FINISH].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI2(eWARE4_FINISH, this->Data[eWARE4_FINISH].X, this->Data[eWARE4_FINISH].Y, Color);
	}
//--------------------------------------------------------------------------------------
	this->DrawGUI2(eWARE5_FINISH, StartX + 6 + 105, StartY + 140);
	this->DrawFormat(eWhite, StartX + 60, StartY + 150, 210, 3, "Ware 5");
	this->Data[eWARE5_FINISH].Attribute = true;
	// ----
	if (IsWorkZone(eWARE5_FINISH))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eWARE5_FINISH].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI2(eWARE5_FINISH, this->Data[eWARE5_FINISH].X, this->Data[eWARE5_FINISH].Y, Color);
	}
//--------------------------------------------------------------------------------------
	this->DrawGUI2(eWARE6_FINISH, StartX + 6, StartY + 175);
	this->DrawFormat(eWhite, StartX - 40, StartY + 185, 210, 3, "Ware 6");
	this->Data[eWARE6_FINISH].Attribute = true;
	// ----
	if (IsWorkZone(eWARE6_FINISH))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eWARE6_FINISH].OnClick)
		{
			Color = eGray150;
		}
		// ----
	this->DrawColoredGUI2(eWARE6_FINISH, this->Data[eWARE6_FINISH].X, this->Data[eWARE6_FINISH].Y, Color);
	}
 //--------------------------------------------------------------------------------------
	this->DrawGUI2(eWARE7_FINISH, StartX + 6 + 105, StartY + 175);
	this->DrawFormat(eWhite, StartX + 60, StartY + 185, 210, 3, "Ware 7");
	this->Data[eWARE7_FINISH].Attribute = true;
	// ----
	if (IsWorkZone(eWARE7_FINISH))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eWARE7_FINISH].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI2(eWARE7_FINISH, this->Data[eWARE7_FINISH].X, this->Data[eWARE7_FINISH].Y, Color);
	}
//--------------------------------------------------------------------------------------
	this->DrawGUI2(eWARE8_FINISH, StartX + 6, StartY + 210);
	this->DrawFormat(eWhite, StartX - 40, StartY + 220, 210, 3, "Ware 8");
	this->Data[eWARE8_FINISH].Attribute = true;
	// ----
	if (IsWorkZone(eWARE8_FINISH))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eWARE8_FINISH].OnClick)
		{
			Color = eGray150;
		}
		// ----
	this->DrawColoredGUI2(eWARE8_FINISH, this->Data[eWARE8_FINISH].X, this->Data[eWARE8_FINISH].Y, Color);
	}
//--------------------------------------------------------------------------------------
	this->DrawGUI2(eWARE9_FINISH, StartX + 6 + 105, StartY + 210);
	this->DrawFormat(eWhite, StartX + 6 + 60, StartY + 220, 210, 3, "Ware 9");
	this->Data[eWARE9_FINISH].Attribute = true;
	// ----
	if (IsWorkZone(eWARE9_FINISH))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eWARE9_FINISH].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI2(eWARE9_FINISH, this->Data[eWARE9_FINISH].X, this->Data[eWARE9_FINISH].Y, Color);
	}
 //-------------------------------------------------------------------------------------- }
}
bool Interface::EventVaultWindow_Main(DWORD Event)
{
	this->EventVaultWindow_Close(Event);
	this->EventVaultWindow_Finish(Event);
	this->EventWARE1Window_Finish(Event);
	this->EventWARE2Window_Finish(Event);
	this->EventWARE3Window_Finish(Event);
	this->EventWARE4Window_Finish(Event);
	this->EventWARE5Window_Finish(Event);
	this->EventWARE6Window_Finish(Event);
	this->EventWARE7Window_Finish(Event);
	this->EventWARE8Window_Finish(Event);
	this->EventWARE9Window_Finish(Event);
	return true;
}
bool Interface::EventVaultWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVAULT_CLOSE].EventTick);
	// ----
	if (!this->Data[eVAULT_MAIN].OnShow || !IsWorkZone(eVAULT_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVAULT_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVAULT_CLOSE].OnClick = false;
	// ----
	if (Delay < 1000)
	{
		return false;
	}
	// ----
	this->Data[eVAULT_CLOSE].EventTick = GetTickCount();
	this->CloseVaultWindow();
	// ----
	return false;
}

bool Interface::EventVaultWindow_Finish(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVAULT_FINISH].EventTick);
	// ----
	if (!this->Data[eVAULT_MAIN].OnShow || !IsWorkZone(eVAULT_FINISH)
		|| !this->Data[eVAULT_FINISH].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVAULT_FINISH].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVAULT_FINISH].OnClick = false;;
	// ----
	if (Delay < 2000)
	{
		return false;
	}
	// ----
	this->Data[eVAULT_FINISH].EventTick = GetTickCount();

	gWarehousePanel.CGSendWarehouseOpen(0);

	this->CloseVaultWindow();
	// ----
	return false;
}
bool Interface::EventWARE1Window_Finish(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eWARE1_FINISH].EventTick);
	// ----
	if (!this->Data[eVAULT_MAIN].OnShow || !IsWorkZone(eWARE1_FINISH)
		|| !this->Data[eWARE1_FINISH].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eWARE1_FINISH].OnClick = true;
		return true;
	}
	// ----
	this->Data[eWARE1_FINISH].OnClick = false;;
	// ----
	if (Delay < 2000)
	{
		return false;
	}
	// ----
	this->Data[eWARE1_FINISH].EventTick = GetTickCount();

	gWarehousePanel.CGSendWarehouseOpen(1);

	this->CloseVaultWindow();
	// ----

	return false;
}
bool Interface::EventWARE2Window_Finish(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eWARE2_FINISH].EventTick);
	// ----
	if (!this->Data[eVAULT_MAIN].OnShow || !IsWorkZone(eWARE2_FINISH)
		|| !this->Data[eWARE2_FINISH].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eWARE2_FINISH].OnClick = true;
		return true;
	}
	// ----
	this->Data[eWARE2_FINISH].OnClick = false;;
	// ----
	if (Delay < 2000)
	{
		return false;
	}
	// ----
	this->Data[eWARE2_FINISH].EventTick = GetTickCount();

	gWarehousePanel.CGSendWarehouseOpen(2);

	this->CloseVaultWindow();
	// ----
	return false;
}
bool Interface::EventWARE3Window_Finish(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eWARE3_FINISH].EventTick);
	// ----
	if (!this->Data[eVAULT_MAIN].OnShow || !IsWorkZone(eWARE3_FINISH)
		|| !this->Data[eWARE3_FINISH].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eWARE3_FINISH].OnClick = true;
		return true;
	}
	// ----
	this->Data[eWARE3_FINISH].OnClick = false;;
	// ----
	if (Delay < 2000)
	{
		return false;
	}
	// ----
	this->Data[eWARE3_FINISH].EventTick = GetTickCount();

	gWarehousePanel.CGSendWarehouseOpen(3);

	this->CloseVaultWindow();
	// ----
	return false;
}
bool Interface::EventWARE4Window_Finish(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eWARE4_FINISH].EventTick);
	// ----
	if (!this->Data[eVAULT_MAIN].OnShow || !IsWorkZone(eWARE4_FINISH)
		|| !this->Data[eWARE4_FINISH].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eWARE4_FINISH].OnClick = true;
		return true;
	}
	// ----
	this->Data[eWARE4_FINISH].OnClick = false;;
	// ----
	if (Delay < 2000)
	{
		return false;
	}
	// ----
	this->Data[eWARE4_FINISH].EventTick = GetTickCount();

	gWarehousePanel.CGSendWarehouseOpen(4);

	this->CloseVaultWindow();
	// ----
	return false;
}
bool Interface::EventWARE5Window_Finish(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eWARE5_FINISH].EventTick);
	// ----
	if (!this->Data[eVAULT_MAIN].OnShow || !IsWorkZone(eWARE5_FINISH)
		|| !this->Data[eWARE5_FINISH].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eWARE5_FINISH].OnClick = true;
		return true;
	}
	// ----
	this->Data[eWARE5_FINISH].OnClick = false;;
	// ----
	if (Delay < 2000)
	{
		return false;
	}
	// ----
	this->Data[eWARE5_FINISH].EventTick = GetTickCount();

	gWarehousePanel.CGSendWarehouseOpen(5);

	this->CloseVaultWindow();
	// ----
	return false;
}
bool Interface::EventWARE6Window_Finish(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eWARE6_FINISH].EventTick);
	// ----
	if (!this->Data[eVAULT_MAIN].OnShow || !IsWorkZone(eWARE6_FINISH)
		|| !this->Data[eWARE6_FINISH].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eWARE6_FINISH].OnClick = true;
		return true;
	}
	// ----
	this->Data[eWARE6_FINISH].OnClick = false;;
	// ----
	if (Delay < 2000)
	{
		return false;
	}
	// ----
	this->Data[eWARE6_FINISH].EventTick = GetTickCount();

	gWarehousePanel.CGSendWarehouseOpen(6);

	this->CloseVaultWindow();
	// ----
	return false;
}
bool Interface::EventWARE7Window_Finish(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eWARE7_FINISH].EventTick);
	// ----
	if (!this->Data[eVAULT_MAIN].OnShow || !IsWorkZone(eWARE7_FINISH)
		|| !this->Data[eWARE7_FINISH].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eWARE7_FINISH].OnClick = true;
		return true;
	}
	// ----
	this->Data[eWARE7_FINISH].OnClick = false;;
	// ----
	if (Delay < 2000)
	{
		return false;
	}
	// ----
	this->Data[eWARE7_FINISH].EventTick = GetTickCount();

	gWarehousePanel.CGSendWarehouseOpen(7);

	this->CloseVaultWindow();
	// ----
	return false;
}
bool Interface::EventWARE8Window_Finish(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eWARE8_FINISH].EventTick);
	// ----
	if (!this->Data[eVAULT_MAIN].OnShow || !IsWorkZone(eWARE8_FINISH)
		|| !this->Data[eWARE8_FINISH].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eWARE8_FINISH].OnClick = true;
		return true;
	}
	// ----
	this->Data[eWARE8_FINISH].OnClick = false;;
	// ----
	if (Delay < 1000)
	{
		return false;
	}
	// ----
	this->Data[eWARE8_FINISH].EventTick = GetTickCount();

	gWarehousePanel.CGSendWarehouseOpen(8);

	this->CloseVaultWindow();
	// ----
	return false;
}
bool Interface::EventWARE9Window_Finish(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eWARE9_FINISH].EventTick);
	// ----
	if (!this->Data[eVAULT_MAIN].OnShow || !IsWorkZone(eWARE9_FINISH)
		|| !this->Data[eWARE9_FINISH].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eWARE9_FINISH].OnClick = true;
		return true;
	}
	// ----
	this->Data[eWARE9_FINISH].OnClick = false;;
	// ----
	if (Delay < 2000)
	{
		return false;
	}
	// ----
	this->Data[eWARE9_FINISH].EventTick = GetTickCount();

	gWarehousePanel.CGSendWarehouseOpen(9);

	this->CloseVaultWindow();
	// ----
	return false;
}
// ========================================================== END MULTIWARE


//============================================ MULTIWARE
void Interface::DrawChangingClassWindow()
{
	if( !this->Data[eCHANGINGCLASS_MAIN].OnShow )
	{
		return;
	}

	if(gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
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
		this->Data[eCHANGINGCLASS_MAIN].OnShow		= false;
		gInterface.Data[eCHANGINGCLASS_MAIN].Close();		
		return;
	}
	// ----
	DWORD ItemNameColor		= eWhite;
	float MainWidth			= 230.0;
	float MainHeight		= 313.0;
	float StartX = this->ultimoX;
	float StartY = this->ultimoWareY;
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
		StartY = this->ultimoWareY + (curY - this->mY);
		StartX = StartX < -5 ? -5 : StartX;
		StartX = StartX > 465 ? 465 : StartX;
		StartY = StartY < 20 ? 20 : StartY;
		StartY = StartY > 95 ? 95 : StartY;
	}

	if (this->Moving && !(GetKeyState(VK_LBUTTON) & 0x8000)) {
		this->Moving = false;
		this->ultimoX = StartX;
		this->ultimoWareY = StartY;
	}

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);
	this->DrawGUI2(eCHANGINGCLASS_CLOSE, StartX + 205, StartY);
	// ----
	if( this->IsWorkZone(eCHANGINGCLASS_CLOSE) )
	{
		DWORD Color = eGray100;
		// ----
		if( this->Data[eCHANGINGCLASS_CLOSE].OnClick )
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI2(eCHANGINGCLASS_CLOSE,StartX + 205, StartY, Color);
		this->DrawToolTip(StartX + 205, StartY - 5, "Close ");
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, StartY + 10, 210, 3, "Changing Class System");
	// ----
	if (gChangeClass.m_PriceType == 0)
	{
		this->DrawFormat(eGold, StartX + 30, StartY + 255, 210, 1, "Required Zen:");
	}
	else if (gChangeClass.m_PriceType == 1)
	{
		this->DrawFormat(eGold, StartX + 30, StartY + 255, 210, 1, "Required %s:",gCustomMessage.GetMessage(6));
	}
	else if (gChangeClass.m_PriceType == 2)
	{
		this->DrawFormat(eGold, StartX + 30, StartY + 255, 210, 1, "Required %s:",gCustomMessage.GetMessage(7));
	}
	else if (gChangeClass.m_PriceType == 3)
	{
		this->DrawFormat(eGold, StartX + 30, StartY + 255, 210, 1, "Required %s:",gCustomMessage.GetMessage(13));
	}
	else if (gChangeClass.m_PriceType == 4)
	{
		this->DrawFormat(eGold, StartX + 30, StartY + 255, 210, 1, "Required %s:",gCustomMessage.GetMessage(14));
	}

	this->DrawGUI(eCHANGINGCLASS_MONEYBG, StartX + 30, StartY + 265);
	// ----
	char MoneyBuff[50], MoneyBuff2[50];
	ZeroMemory(MoneyBuff, sizeof(MoneyBuff));
	ZeroMemory(MoneyBuff2, sizeof(MoneyBuff2));
	// ----
	pGetMoneyFormat((double)gChangeClass.m_Price,MoneyBuff, 0);
	this->DrawFormat(eGold, StartX + 70, StartY + 272, 60, 1, "%s", MoneyBuff);
	// ----

		// Display player's current balance based on currency type
	if (gChangeClass.m_PriceType == 0)
	{
		// For Zen, get from character money
		int CurrentZen = *(int*)0x07BC4F0C; // Character money address
		pGetMoneyFormat((double)CurrentZen, MoneyBuff2, 0);
		this->DrawFormat(eWhite, StartX + 30, StartY + 285, 210, 1, "Your Zen: %s", MoneyBuff2);
	}
	else if (gChangeClass.m_PriceType == 1)
	{
		// WCoinC
		this->DrawFormat(eWhite, StartX + 30, StartY + 285, 210, 1, "Your %s: %d", gCustomMessage.GetMessage(6), this->m_LuckyWheelWCoinC);
	}
	else if (gChangeClass.m_PriceType == 2)
	{
		// WCoinP
		this->DrawFormat(eWhite, StartX + 30, StartY + 285, 210, 1, "Your %s: %d", gCustomMessage.GetMessage(7), this->m_LuckyWheelWCoinP);
	}
	else if (gChangeClass.m_PriceType == 3)
	{
		// GoblinPoints
		this->DrawFormat(eWhite, StartX + 30, StartY + 285, 210, 1, "Your %s: %d", gCustomMessage.GetMessage(13), this->m_LuckyWheelGPCoin);
	}
	else if (gChangeClass.m_PriceType == 4)
	{
		// Additional currency type (if any)
		this->DrawFormat(eWhite, StartX + 30, StartY + 285, 210, 1, "Your %s: N/A", gCustomMessage.GetMessage(14));
	}
	// ----


	// ----
	this->DrawGUI2(eCHANGINGCLASS_DW, StartX + 62 - 57, StartY + 30);
	this->DrawFormat(eWhite, StartX - 45, StartY + 40, 210, 3, "%s class",pGetTextLine(pTextLineThis,20));
	// ----
	this->DrawGUI2(eCHANGINGCLASS_DK, StartX + 62 + 52, StartY + 30);
	this->DrawFormat(eWhite, StartX + 62, StartY + 40, 210, 3, "%s class",pGetTextLine(pTextLineThis,21));
	// ----
	this->DrawGUI2(eCHANGINGCLASS_ELF, StartX + 62 - 57, StartY + 60);
	this->DrawFormat(eWhite, StartX - 45, StartY + 70, 210, 3, "%s class",pGetTextLine(pTextLineThis,22));
	// ----
	this->DrawGUI2(eCHANGINGCLASS_MG, StartX + 62 + 52, StartY + 60);
	this->DrawFormat(eWhite, StartX + 62, StartY + 70, 210, 3, "%s class",pGetTextLine(pTextLineThis,23));
	// ----
	if (gProtect.m_MainInfo.RemoveClass != 1)
	{
		this->DrawGUI2(eCHANGINGCLASS_DL, StartX + 62 - 57, StartY + 90);
		this->DrawFormat(eWhite, StartX - 45,StartY + 100, 210, 3, "%s class",pGetTextLine(pTextLineThis,24));
	}
	// ----
	if (gProtect.m_MainInfo.RemoveClass != 1 && gProtect.m_MainInfo.RemoveClass != 2)
	{
		this->DrawGUI2(eCHANGINGCLASS_SUM, StartX + 62 + 52, StartY + 90);
		this->DrawFormat(eWhite, StartX + 62, StartY + 100, 210, 3, "%s class",pGetTextLine(pTextLineThis,1687));
	}
	// ----
	if (gProtect.m_MainInfo.RemoveClass != 1 && gProtect.m_MainInfo.RemoveClass != 2 && gProtect.m_MainInfo.RemoveClass != 3)
	{
		this->DrawGUI2(eCHANGINGCLASS_RF, StartX + 62, StartY + 120);
		this->DrawFormat(eWhite, StartX + 8, StartY + 130, 210, 3, "%s class",pGetTextLine(pTextLineThis,3150));
	}
	// ----
	this->DrawGUI(eCHANGINGCLASS_DIV, StartX, StartY + 212);
	// ----
	this->Data[eCHANGINGCLASS_DW].Attribute = true;
	this->Data[eCHANGINGCLASS_DK].Attribute = true;
	this->Data[eCHANGINGCLASS_ELF].Attribute = true;
	this->Data[eCHANGINGCLASS_MG].Attribute = true;
	this->Data[eCHANGINGCLASS_DL].Attribute = true;
	this->Data[eCHANGINGCLASS_SUM].Attribute = true;
	this->Data[eCHANGINGCLASS_RF].Attribute = true;
	// ----
	if( IsWorkZone(eCHANGINGCLASS_DW) )
	{
		DWORD Color = eGray100;
		// ----
		if( this->Data[eCHANGINGCLASS_DW].OnClick )
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI2(eCHANGINGCLASS_DW, this->Data[eCHANGINGCLASS_DW].X, this->Data[eCHANGINGCLASS_DW].Y, Color);
	}
	if( IsWorkZone(eCHANGINGCLASS_DK) )
	{
		DWORD Color = eGray100;
		// ----
		if( this->Data[eCHANGINGCLASS_DK].OnClick )
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI2(eCHANGINGCLASS_DK, this->Data[eCHANGINGCLASS_DK].X, this->Data[eCHANGINGCLASS_DK].Y, Color);
	}
	if( IsWorkZone(eCHANGINGCLASS_ELF) )
	{
		DWORD Color = eGray100;
		// ----
		if( this->Data[eCHANGINGCLASS_ELF].OnClick )
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI2(eCHANGINGCLASS_ELF, this->Data[eCHANGINGCLASS_ELF].X, this->Data[eCHANGINGCLASS_ELF].Y, Color);
	}
	if( IsWorkZone(eCHANGINGCLASS_MG) )
	{
		DWORD Color = eGray100;
		// ----
		if( this->Data[eCHANGINGCLASS_MG].OnClick )
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI2(eCHANGINGCLASS_MG, this->Data[eCHANGINGCLASS_MG].X, this->Data[eCHANGINGCLASS_MG].Y, Color);
	}
	if( IsWorkZone(eCHANGINGCLASS_DL) )
	{
		if (gProtect.m_MainInfo.RemoveClass != 1)
		{
			DWORD Color = eGray100;
			// ----
			if( this->Data[eCHANGINGCLASS_DL].OnClick )
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI2(eCHANGINGCLASS_DL, this->Data[eCHANGINGCLASS_DL].X, this->Data[eCHANGINGCLASS_DL].Y, Color);
		}
	}
	if( IsWorkZone(eCHANGINGCLASS_SUM) )
	{
		if (gProtect.m_MainInfo.RemoveClass != 1 || gProtect.m_MainInfo.RemoveClass != 2)
		{
			DWORD Color = eGray100;
			// ----
			if( this->Data[eCHANGINGCLASS_SUM].OnClick )
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI2(eCHANGINGCLASS_SUM, this->Data[eCHANGINGCLASS_SUM].X, this->Data[eCHANGINGCLASS_SUM].Y, Color);
		}
	}
	if( IsWorkZone(eCHANGINGCLASS_RF) )
	{
		if (gProtect.m_MainInfo.RemoveClass != 1 || gProtect.m_MainInfo.RemoveClass != 2 || gProtect.m_MainInfo.RemoveClass != 3)
		{
			DWORD Color = eGray100;
			// ----
			if( this->Data[eCHANGINGCLASS_RF].OnClick )
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI2(eCHANGINGCLASS_RF, this->Data[eCHANGINGCLASS_RF].X, this->Data[eCHANGINGCLASS_RF].Y, Color);
		}
	}

}
bool Interface::EventChangingClassWindow_Main(DWORD Event)
{
	this->EventChangingClassWindow_Close(Event);
	this->EventChangingClassWindow_DW(Event);
	this->EventChangingClassWindow_DK(Event);
	this->EventChangingClassWindow_ELF(Event);
	this->EventChangingClassWindow_MG(Event);
	this->EventChangingClassWindow_DL(Event);
	this->EventChangingClassWindow_SUM(Event);
	this->EventChangingClassWindow_RF(Event);
	return true;
}
bool Interface::EventChangingClassWindow_Close(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eCHANGINGCLASS_CLOSE].EventTick);
	// ----
	if( !this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_CLOSE) )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eCHANGINGCLASS_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_CLOSE].OnClick = false;
	// ----
	if( Delay < 1000 )
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_CLOSE].EventTick = GetTickCount();
	this->Data[eCHANGINGCLASS_MAIN].Close();
	// ----
	return false;
}

bool Interface::EventChangingClassWindow_DW(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eCHANGINGCLASS_DW].EventTick);
	// ----
	DWORD DelayUserPanel = (GetTickCount() - this->Data[eMenu_CHANGECLASS].EventTick);
	if (DelayUserPanel < 1000)
	{
		return false;
	}
	// ----
	if( !this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_DW) 
		|| !this->Data[eCHANGINGCLASS_DW].Attribute )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eCHANGINGCLASS_DW].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_DW].OnClick = false;;
	// ----
	if( Delay < 1000 )
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_DW].EventTick = GetTickCount();

	gChangeClass.SendChangeClass(0);

	this->Data[eCHANGINGCLASS_MAIN].Close();
	this->Data[eCHANGINGCLASS_CLOSE].Close();
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_DK(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eCHANGINGCLASS_DK].EventTick);
	// ----
	DWORD DelayUserPanel = (GetTickCount() - this->Data[eMenu_CHANGECLASS].EventTick);
	if (DelayUserPanel < 1000)
	{
		return false;
	}
	// ----
	if( !this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_DK) 
		|| !this->Data[eCHANGINGCLASS_DK].Attribute )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eCHANGINGCLASS_DK].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_DK].OnClick = false;;
	// ----
	if( Delay < 1000 )
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_DK].EventTick = GetTickCount();

	gChangeClass.SendChangeClass(16);

	this->Data[eCHANGINGCLASS_MAIN].Close();
	this->Data[eCHANGINGCLASS_CLOSE].Close();
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_ELF(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eCHANGINGCLASS_ELF].EventTick);
	// ----
	DWORD DelayUserPanel = (GetTickCount() - this->Data[eMenu_CHANGECLASS].EventTick);
	if (DelayUserPanel < 1000)
	{
		return false;
	}
	// ----
	if( !this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_ELF) 
		|| !this->Data[eCHANGINGCLASS_ELF].Attribute )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eCHANGINGCLASS_ELF].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_ELF].OnClick = false;;
	// ----
	if( Delay < 1000 )
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_ELF].EventTick = GetTickCount();

	gChangeClass.SendChangeClass(32);

	this->Data[eCHANGE_RESET_CLOSE].Close();
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_MG(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eCHANGINGCLASS_MG].EventTick);
	// ----
	DWORD DelayUserPanel = (GetTickCount() - this->Data[eMenu_CHANGECLASS].EventTick);
	if (DelayUserPanel < 1000)
	{
		return false;
	}
	// ----
	if( !this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_MG) 
		|| !this->Data[eCHANGINGCLASS_MG].Attribute )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eCHANGINGCLASS_MG].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_MG].OnClick = false;;
	// ----
	if( Delay < 1000 )
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_MG].EventTick = GetTickCount();

	gChangeClass.SendChangeClass(48);

	this->Data[eCHANGINGCLASS_MAIN].Close();
	this->Data[eCHANGINGCLASS_CLOSE].Close();
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_DL(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eCHANGINGCLASS_DL].EventTick);
	// ----
	DWORD DelayUserPanel = (GetTickCount() - this->Data[eMenu_CHANGECLASS].EventTick);
	if (DelayUserPanel < 1000)
	{
		return false;
	}
	// ----
	if( !this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_DL) 
		|| !this->Data[eCHANGINGCLASS_DL].Attribute )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eCHANGINGCLASS_DL].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_DL].OnClick = false;;
	// ----
	if( Delay < 1000 )
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_DL].EventTick = GetTickCount();

	gChangeClass.SendChangeClass(64);

	this->Data[eCHANGINGCLASS_MAIN].Close();
	this->Data[eCHANGINGCLASS_CLOSE].Close();
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_SUM(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eCHANGINGCLASS_SUM].EventTick);
	// ----
	DWORD DelayUserPanel = (GetTickCount() - this->Data[eMenu_CHANGECLASS].EventTick);
	if (DelayUserPanel < 1000)
	{
		return false;
	}
	// ----
	if( !this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_SUM) 
		|| !this->Data[eCHANGINGCLASS_SUM].Attribute )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eCHANGINGCLASS_SUM].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_SUM].OnClick = false;;
	// ----
	if( Delay < 1000 )
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_SUM].EventTick = GetTickCount();

	gChangeClass.SendChangeClass(80);

	this->Data[eCHANGINGCLASS_MAIN].Close();
	this->Data[eCHANGINGCLASS_CLOSE].Close();
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_RF(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eCHANGINGCLASS_RF].EventTick);
	// ----
	DWORD DelayUserPanel = (GetTickCount() - this->Data[eMenu_CHANGECLASS].EventTick);
	if (DelayUserPanel < 1000)
	{
		return false;
	}
	// ----
	if( !this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_RF) 
		|| !this->Data[eCHANGINGCLASS_RF].Attribute )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eCHANGINGCLASS_RF].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_RF].OnClick = false;;
	// ----
	if( Delay < 1000 )
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_RF].EventTick = GetTickCount();

	gChangeClass.SendChangeClass(96);

	this->Data[eCHANGINGCLASS_MAIN].Close();
	this->Data[eCHANGINGCLASS_CLOSE].Close();
	// ----
	return false;
}
// ========================================================== END ChangeClass

//============================================ LUCKY WHELL
void testfunc()
{
    glMatrixMode(0x1700u);
    glPopMatrix();
    glMatrixMode(0x1701u);
    glPopMatrix();
}
void Interface::DrawItem2(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse) // code hien thi item
{
 
    glMatrixMode(0x1701);
    glPushMatrix();
    glLoadIdentity();
 
    //float X = ull_to_float2(*(QWORD*)0xE61E58);
    //float Y = ull_to_float2(*(QWORD*)0xE61E58+1);
 
    sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);
    //float v2 = (X / (Y / 100.0f)) / 100.0f;//(*(float*)MAIN_RESOLUTION_X / (*(float*)MAIN_RESOLUTION_Y / 100.0f)) / 100.0f;
    float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;
    sub_6358A0_Addr(1.0, v2, *(float*)0xE61E38, *(float*)0xE61E3C);
 
    glMatrixMode(0x1700);
    glPushMatrix();
    glLoadIdentity();
 
    sub_635830_Addr((LPVOID)0x87933A0);
    sub_635DE0_Addr();
    sub_635E40_Addr();
 
    //posX
    //posY
    //Width
    //Height
    //unk
    // 1 - Excellent Effect
    // 1 - Aura +7
    // 1 - original size
    //glClear(0x100u);
    pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, Excl, Anc, OnMouse);
   
    testfunc();
    //sub_637770_Addr();
 
    glColor3f(1,1,1);
    pSetBlend(false);
}
void Interface::DrawLuckyWheel()
{
	if (!gInterface.Data[eLuckyWheelMain].OnShow)
	{
		return;
	}

	if(gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
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
		this->Data[eLuckyWheelMain].OnShow		= false;
		gInterface.Data[eLuckyWheelMain].Close();		
		return;
	}

	float StartX = this->ultimoX;
	float StartY = this->ultimoWareY;
	float curX = pCursorX >= MAX_WIN_WIDTH ? 0 : pCursorX;
	float curY = pCursorY >= MAX_WIN_HEIGHT ? 0 : pCursorY;

	if (gInterface.IsWorkZone3(StartX, StartY - 45, 329 / (resizeGuiRate * resizeGuiScaleRateX), 72 / (resizeGuiRate * resizeGuiScaleRateY), true)) 
	{	
		if (!this->Moving && GetKeyState(VK_LBUTTON) & 0x8000) {
			this->Moving = true;
			this->mX = curX;
			this->mY = curY;
		}	
	}

	if (this->Moving) {
		StartX = this->ultimoX + (curX - this->mX);
		StartY = this->ultimoWareY + (curY - this->mY);
		StartX = StartX < -5 ? -5 : StartX;
		StartX = StartX > 465 ? 465 : StartX;
		StartY = StartY < 20 ? 20 : StartY;
		StartY = StartY > 95 ? 95 : StartY;
	}

	if (this->Moving && !(GetKeyState(VK_LBUTTON) & 0x8000)) {
		this->Moving = false;
		this->ultimoX = StartX;
		this->ultimoWareY = StartY;
	}

	gInterface.DrawGUI2(eLuckyWheelPanel, StartX - 60, StartY - 45);

	pDrawGUI(0x9326, StartX - 45, StartY, 70, 57); 
	pDrawGUI(0x9326, StartX + 25, StartY, 70, 57); 
	pDrawGUI(0x9326, StartX + 95, StartY, 70, 57); 
	pDrawGUI(0x9326, StartX + 165, StartY, 70, 57); 
	pDrawGUI(0x9326, StartX + 165, StartY + 57, 70, 57); 
	pDrawGUI(0x9326, StartX + 165, StartY + 114, 70, 57); 
	pDrawGUI(0x9326, StartX + 165, StartY + 171, 70, 57); 
	pDrawGUI(0x9326, StartX + 95, StartY + 171, 70, 57); 
	pDrawGUI(0x9326, StartX + 25, StartY + 171, 70, 57); 
	pDrawGUI(0x9326, StartX - 45, StartY + 171, 70, 57); 
	pDrawGUI(0x9326, StartX - 45, StartY + 57, 70, 57); 
	pDrawGUI(0x9326, StartX - 45, StartY + 114, 70, 57); 


	if(this->LuckyWheelNumber >= 0)
	{
		pSetBlend(true);
		glColor4f(1.0, 1.0, 0.0, 0.3);
		switch (LuckyWheelNumber)
		{
		case 0:
			pDrawBarForm(StartX - 45, StartY, 70, 57, 0, 0);
		break;
		case 1:
			pDrawBarForm(StartX + 25, StartY, 70, 57, 0, 0);
		break;
		case 2:
			pDrawBarForm(StartX + 95, StartY, 70, 57, 0, 0);
		break;
		case 3:
			pDrawBarForm(StartX + 165, StartY, 70, 57, 0, 0);
		break;
		case 4:
			pDrawBarForm(StartX + 165, StartY + 57, 70, 57, 0, 0);
		break;
		case 5:
			pDrawBarForm(StartX + 165, StartY + 114, 70, 57, 0, 0);
		break;
		case 6:
			pDrawBarForm(StartX + 165, StartY + 171, 70, 57, 0, 0);
		break;
		case 7:
			pDrawBarForm(StartX + 95, StartY + 171, 70, 57, 0, 0);
		break;
		case 8:
			pDrawBarForm(StartX + 25, StartY + 171, 70, 57, 0, 0);
		break;
		case 9:
			pDrawBarForm(StartX - 45, StartY + 171, 70, 57, 0, 0);
		break;
		case 10:
			pDrawBarForm(StartX - 45, StartY + 57, 70, 57, 0, 0);
		break;
		case 11:
			pDrawBarForm(StartX - 45, StartY + 114, 70, 57, 0, 0);
		break;
		}
		pGLSwitchBlend();
		glColor3f(1.0, 1.0, 1.0);
	}

	if(this->StartRoll >= 1)
	{
		pSetBlend(true);
		glColor4f(1.0, 1.0, 0.0, 0.3);
		int roll = rand() % 12;
		switch (roll)
		{
		case 0:
			pDrawBarForm(StartX - 45, StartY, 70, 57, 0, 0);
		break;
		case 1:
			pDrawBarForm(StartX + 25, StartY, 70, 57, 0, 0);
		break;
		case 2:
			pDrawBarForm(StartX + 95, StartY, 70, 57, 0, 0);
		break;
		case 3:
			pDrawBarForm(StartX + 165, StartY, 70, 57, 0, 0);
		break;
		case 4:
			pDrawBarForm(StartX + 165, StartY + 57, 70, 57, 0, 0);
		break;
		case 5:
			pDrawBarForm(StartX + 165, StartY + 114, 70, 57, 0, 0);
		break;
		case 6:
			pDrawBarForm(StartX + 165, StartY + 171, 70, 57, 0, 0);
		break;
		case 7:
			pDrawBarForm(StartX + 95, StartY + 171, 70, 57, 0, 0);
		break;
		case 8:
			pDrawBarForm(StartX + 25, StartY + 171, 70, 57, 0, 0);
		break;
		case 9:
			pDrawBarForm(StartX - 45, StartY + 171, 70, 57, 0, 0);
		break;
		case 10:
			pDrawBarForm(StartX - 45, StartY + 57, 70, 57, 0, 0);
		break;
		case 11:
			pDrawBarForm(StartX - 45, StartY + 114, 70, 57, 0, 0);
		break;
		}
		pGLSwitchBlend();
		glColor3f(1.0, 1.0, 1.0);
	}
	gInterface.DrawItem2(StartX - 42,StartY,70,50,ITEM(gLuckyWheel.m_LuckyWheelInfo[0].ItemType,gLuckyWheel.m_LuckyWheelInfo[0].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[0].Level),gLuckyWheel.m_LuckyWheelInfo[0].Exc,0,0);
	gInterface.DrawItem2(StartX + 32,StartY,65,47,ITEM(gLuckyWheel.m_LuckyWheelInfo[1].ItemType,gLuckyWheel.m_LuckyWheelInfo[1].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[1].Level),gLuckyWheel.m_LuckyWheelInfo[1].Exc,0,0);
	gInterface.DrawItem2(StartX + 102,StartY,65,47,ITEM(gLuckyWheel.m_LuckyWheelInfo[2].ItemType,gLuckyWheel.m_LuckyWheelInfo[2].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[2].Level),gLuckyWheel.m_LuckyWheelInfo[2].Exc,0,0);
	gInterface.DrawItem2(StartX + 172,StartY,65,50,ITEM(gLuckyWheel.m_LuckyWheelInfo[3].ItemType,gLuckyWheel.m_LuckyWheelInfo[3].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[3].Level),gLuckyWheel.m_LuckyWheelInfo[3].Exc,0,0);
	gInterface.DrawItem2(StartX + 172,StartY + 57,65,50,ITEM(gLuckyWheel.m_LuckyWheelInfo[4].ItemType,gLuckyWheel.m_LuckyWheelInfo[4].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[4].Level),gLuckyWheel.m_LuckyWheelInfo[4].Exc,0,0);
	gInterface.DrawItem2(StartX + 172,StartY + 114,63,50,ITEM(gLuckyWheel.m_LuckyWheelInfo[5].ItemType,gLuckyWheel.m_LuckyWheelInfo[5].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[5].Level),gLuckyWheel.m_LuckyWheelInfo[5].Exc,0,0);
	gInterface.DrawItem2(StartX + 172,StartY + 171,70,45,ITEM(gLuckyWheel.m_LuckyWheelInfo[6].ItemType,gLuckyWheel.m_LuckyWheelInfo[6].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[6].Level),gLuckyWheel.m_LuckyWheelInfo[6].Exc,0,0);
	gInterface.DrawItem2(StartX + 102,StartY + 171,70,45,ITEM(gLuckyWheel.m_LuckyWheelInfo[7].ItemType,gLuckyWheel.m_LuckyWheelInfo[7].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[7].Level),gLuckyWheel.m_LuckyWheelInfo[7].Exc,0,0);
	gInterface.DrawItem2(StartX + 32,StartY + 171,70,45,ITEM(gLuckyWheel.m_LuckyWheelInfo[8].ItemType,gLuckyWheel.m_LuckyWheelInfo[8].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[8].Level),gLuckyWheel.m_LuckyWheelInfo[8].Exc,0,0);
	gInterface.DrawItem2(StartX - 38,StartY + 171,70,45,ITEM(gLuckyWheel.m_LuckyWheelInfo[9].ItemType,gLuckyWheel.m_LuckyWheelInfo[9].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[9].Level),gLuckyWheel.m_LuckyWheelInfo[9].Exc,0,0);
	gInterface.DrawItem2(StartX - 38,StartY + 57,70,50,ITEM(gLuckyWheel.m_LuckyWheelInfo[10].ItemType,gLuckyWheel.m_LuckyWheelInfo[10].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[10].Level),gLuckyWheel.m_LuckyWheelInfo[10].Exc,0,0);
	gInterface.DrawItem2(StartX - 38,StartY + 114,70,50,ITEM(gLuckyWheel.m_LuckyWheelInfo[11].ItemType,gLuckyWheel.m_LuckyWheelInfo[11].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[11].Level),gLuckyWheel.m_LuckyWheelInfo[11].Exc,0,0);

	if(this->LuckyWheelNumber >= 0)
	{
	    gInterface.DrawItem2(StartX + 78,StartY + 70,50,50,ITEM(gLuckyWheel.m_LuckyWheelInfo[this->LuckyWheelNumber].ItemType,gLuckyWheel.m_LuckyWheelInfo[this->LuckyWheelNumber].ItemIndex),gLuckyWheel.m_LuckyWheelInfo[this->LuckyWheelNumber].Level,gLuckyWheel.m_LuckyWheelInfo[this->LuckyWheelNumber].Exc,0,0);
	}
	pSetCursorFocus = true;
	gInterface.DrawGUI2(eLuckyWheelStart,StartX + 57,StartY + 90 + 56.5f);
	gInterface.DrawFormat(eGold, StartX + 80, StartY - 25, 25, 5, "Lucky Wheel");
	gInterface.DrawFormat(eWhite, StartX + 85, StartY + 58 + 93, 50.0f, 1.0f, "Start");
    gInterface.DrawGUI2(eCloseLuckyWheel, StartX + 213, StartY - 35);

	this->DrawFormat(eGold, StartX + 35, StartY + 58, 200, 1, "Cooldown use %d Seconds",this->m_LuckyWheelTime);

	int So = StartX;
	if(this->m_LuckyWheelWCoinC > 0)
	{
		this->DrawFormat(eWhite, StartX + 35, So + 20, 200, 1, "WCoinC: %d",this->m_LuckyWheelWCoinC);
		So + 12;
	}
	if(this->m_LuckyWheelWCoinP > 0)
	{
		this->DrawFormat(eWhite, StartX + 35,So + 20, 200, 1, "WCoinP: %d",this->m_LuckyWheelWCoinP);
		So + 12;
	}
	if(this->m_LuckyWheelGPCoin > 0)
	{
		this->DrawFormat(eWhite, StartX + 35, So, 200, 1, "GPCoin: %d",this->m_LuckyWheelGPCoin);
	}



    if (gInterface.IsWorkZone(eCloseLuckyWheel))
	{
    	DWORD Color = eGray100;
    	if (gInterface.Data[eCloseLuckyWheel].OnClick)
		{
    		Color = eGray150;
    	}
    	gInterface.DrawColoredGUI2(eCloseLuckyWheel, StartX + 213, StartY - 35, Color);
    	gInterface.DrawToolTip(StartX + 213, StartY - 35, "Close");
    }

	if(this->LuckyWheelNumber !=13)
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - this->Data[eLuckyWheelStart].EventTick);
		DWORD Delay2 = (CurrentTick - this->Data[eLuckyWheelStart].EventTick);

		if (Delay < (this->m_LuckyWheelTime*1000))
		{
			return;
		}		
	}

    if( gInterface.IsWorkZone(eLuckyWheelStart) )
	{
    	DWORD Color = eGray100;
    	if( gInterface.Data[eLuckyWheelStart].OnClick )
		{
    		Color = eGray150;
    	}
    	gInterface.DrawColoredGUI2(eLuckyWheelStart, gInterface.Data[eLuckyWheelStart].X, gInterface.Data[eLuckyWheelStart].Y, Color);
    }
}
void Interface::EventLuckyWheel_Main(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	if( !gInterface.Data[eLuckyWheelMain].OnShow )
	{
		return;
	}
	if (gInterface.IsWorkZone(eLuckyWheelStart))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[eLuckyWheelStart].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eLuckyWheelStart].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		gInterface.Data[eLuckyWheelStart].OnClick = false;
		pSetCursorFocus = false;
		if(this->LuckyWheelNumber !=13)
		{
			if (Delay < (this->m_LuckyWheelTime*1000))
			{
				return;
			}
		}
		else if (Delay < 5000)
		{
			return;
		}

		gInterface.Data[eLuckyWheelStart].EventTick = GetTickCount();
		UP_TUCHAN_REQ pMsg;
		pMsg.h.set(0xF5, 0x16, sizeof(pMsg));
		DataSend((BYTE*)&pMsg, pMsg.h.size);
		StartRoll = 1;
	}
}
bool Interface::EventDrawClose_LuckyWheel(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eCloseLuckyWheel].EventTick);
	if (!gInterface.Data[eLuckyWheelMain].OnShow || !gInterface.IsWorkZone(eCloseLuckyWheel)){
		return false;
	}
	if (Event == WM_LBUTTONDOWN){
		gInterface.Data[eCloseLuckyWheel].OnClick = true;
		return true;
	}
	gInterface.Data[eCloseLuckyWheel].OnClick = false;
	if (Delay < 5000){
		return false;
	}
	gInterface.Data[eCloseLuckyWheel].EventTick = GetTickCount();
	this->LuckyWheelStateclose();
	return false;
}
// ========================================================== END LUCKYWHELL

//============================================ ChangeReset
void Interface::DrawChangeResetWindow()
{
	if( !this->Data[eCHANGE_RESET_MAIN].OnShow )
	{
		return;
	}

	if(gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::MuHelper)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow))
	{
		this->Data[eCHANGE_RESET_MAIN].OnShow		= false;
		gInterface.Data[eCHANGE_RESET_MAIN].Close();		
		return;
	}

	// ----
	DWORD ItemNameColor		= eWhite;
	float MainWidth			= 230.0;
	float MainHeight		= 313.0;
	float StartX = this->ultimoX;
	float StartY = this->ultimoWareY;
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
		StartY = this->ultimoWareY + (curY - this->mY);
		StartX = StartX < -5 ? -5 : StartX;
		StartX = StartX > 465 ? 465 : StartX;
		StartY = StartY < 20 ? 20 : StartY;
		StartY = StartY > 95 ? 95 : StartY;
	}

	if (this->Moving && !(GetKeyState(VK_LBUTTON) & 0x8000)) {
		this->Moving = false;
		this->ultimoX = StartX;
		this->ultimoWareY = StartY;
	}

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);
	this->DrawGUI2(eCHANGE_RESET_CLOSE, StartX + 60, StartY + 270);
	// ----
	if( this->IsWorkZone(eCHANGE_RESET_CLOSE) )
	{
		DWORD Color = eGray100;
		// ----
		if( this->Data[eCHANGE_RESET_CLOSE].OnClick )
		{
			Color = eGray150;
		}
		// ----

		this->DrawColoredGUI2(eCHANGE_RESET_CLOSE, this->Data[eCHANGE_RESET_CLOSE].X, this->Data[eCHANGE_RESET_CLOSE].Y, Color);
	}
	// ----
	this->DrawFormat(eWhite, StartX + 8, StartY + 278, 210, 3, "Close");
	// ----
	this->DrawFormat(eSocket, StartX + 10, StartY + 10, 210, 3, "Panel Resets Change");
	// ----
	this->DrawGUI2(eCHANGE_RESET_5, StartX + 62 + 106, StartY + 30);
	this->DrawFormat(eYellow, StartX + 83, StartY + 35, 215, 3,"Change");
	this->DrawFormat(eWhite, StartX - 19, StartY + 35, 215, 3,"5 Resets change for 1000 WCoin");
	// ----
	this->DrawGUI2(eCHANGE_RESET_10, StartX + 62  + 106, StartY + 60);
	this->DrawFormat(eYellow, StartX + 83, StartY + 65, 215, 3,"Change");
	this->DrawFormat(eWhite, StartX - 20, StartY + 65, 215, 3,"10 Resets change for 2000 WCoin");
	// ----
	this->DrawGUI2(eCHANGE_RESET_15, StartX + 62  + 106, StartY + 90);
	this->DrawFormat(eYellow, StartX + 83, StartY + 95, 215, 3,"Change");
	this->DrawFormat(eWhite, StartX - 20, StartY + 95, 215, 3,"15 Resets change for 3000 WCoin");
	// ----
	this->DrawGUI2(eCHANGE_RESET_20, StartX + 62  + 106, StartY + 120);
	this->DrawFormat(eYellow, StartX + 83, StartY + 125, 215, 3, "Change");
	this->DrawFormat(eWhite, StartX - 20, StartY + 125, 215, 3,"20 Resets change for 4000 WCoin");
	// ----
	this->DrawGUI2(eCHANGE_RESET_25, StartX + 62  + 106, StartY + 150);
	this->DrawFormat(eYellow, StartX + 83, StartY + 155, 215, 3,"Change");
	this->DrawFormat(eWhite, StartX - 20, StartY + 155, 215, 3,"25 Resets change for 5000 WCoin");
	// ----
	this->DrawGUI(eCHANGE_RESET_LINE, StartX + 30, StartY + 48);
	this->DrawGUI(eCHANGE_RESET_LINE, StartX + 30, StartY + 78);
	this->DrawGUI(eCHANGE_RESET_LINE, StartX + 30, StartY + 108);
	this->DrawGUI(eCHANGE_RESET_LINE, StartX + 30, StartY + 138);
	this->DrawGUI(eCHANGE_RESET_LINE, StartX + 30, StartY + 168);
	// ----
	this->DrawGUI(eCHANGE_RESET_DIV, StartX, StartY + 246);
	// ----
	this->Data[eCHANGE_RESET_25].Attribute = true;
	this->Data[eCHANGE_RESET_5].Attribute = true;
	this->Data[eCHANGE_RESET_10].Attribute = true;
	this->Data[eCHANGE_RESET_15].Attribute = true;
	this->Data[eCHANGE_RESET_20].Attribute = true;
	// ----
	if( IsWorkZone(eCHANGE_RESET_5) )
	{
		DWORD Color = eGray100;
		// ----
		if( this->Data[eCHANGE_RESET_5].OnClick )
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI2(eCHANGE_RESET_5, this->Data[eCHANGE_RESET_5].X, this->Data[eCHANGE_RESET_5].Y, Color);
	}
	if( IsWorkZone(eCHANGE_RESET_10) )
	{
		DWORD Color = eGray100;
		// ----
		if( this->Data[eCHANGE_RESET_10].OnClick )
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI2(eCHANGE_RESET_10, this->Data[eCHANGE_RESET_10].X, this->Data[eCHANGE_RESET_10].Y, Color);
	}
	if( IsWorkZone(eCHANGE_RESET_15) )
	{
			DWORD Color = eGray100;
			// ----
			if( this->Data[eCHANGE_RESET_15].OnClick )
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI2(eCHANGE_RESET_15, this->Data[eCHANGE_RESET_15].X, this->Data[eCHANGE_RESET_15].Y, Color);
	}
	if( IsWorkZone(eCHANGE_RESET_20) )
	{
			DWORD Color = eGray100;
			// ----
			if( this->Data[eCHANGE_RESET_20].OnClick )
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI2(eCHANGE_RESET_20, this->Data[eCHANGE_RESET_20].X, this->Data[eCHANGE_RESET_20].Y, Color);
	}
	if( IsWorkZone(eCHANGE_RESET_25) )
	{
		DWORD Color = eGray100;
		// ----
		if( this->Data[eCHANGE_RESET_25].OnClick )
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI2(eCHANGE_RESET_25, this->Data[eCHANGE_RESET_25].X, this->Data[eCHANGE_RESET_25].Y, Color);
	}
}
bool Interface::EventChangeResetWindow_Main(DWORD Event)
{
	this->EventChangeResetWindow_Close(Event);	
	this->EventChangeResetWindow_5(Event);
	this->EventChangeResetWindow_10(Event);
	this->EventChangeResetWindow_15(Event);
	this->EventChangeResetWindow_20(Event);
	this->EventChangeResetWindow_25(Event);
	return true;
}
bool Interface::EventChangeResetWindow_Close(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eCHANGE_RESET_CLOSE].EventTick);
	// ----
	if( !this->Data[eCHANGE_RESET_MAIN].OnShow || !IsWorkZone(eCHANGE_RESET_CLOSE) )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eCHANGE_RESET_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGE_RESET_CLOSE].OnClick = false;
	// ----
	if( Delay < 1000 )
	{
		return false;
	}
	// ----
	this->Data[eCHANGE_RESET_CLOSE].EventTick = GetTickCount();
	this->Data[eCHANGE_RESET_MAIN].Close();
	// ----
	return false;
}
bool Interface::EventChangeResetWindow_5(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eCHANGE_RESET_5].EventTick);

	DWORD DelayUserPanel = (GetTickCount() - this->Data[eMenu_RESETCHANGE].EventTick);
	if (DelayUserPanel < 500)
	{
		return false;
	}
	// ----
	if( !this->Data[eCHANGE_RESET_MAIN].OnShow || !IsWorkZone(eCHANGE_RESET_5) 
		|| !this->Data[eCHANGE_RESET_5].Attribute )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eCHANGE_RESET_5].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGE_RESET_5].OnClick = false;;
	// ----
	if( Delay < 1000 )
	{
		return false;
	}
	// ----
	this->Data[eCHANGE_RESET_5].EventTick = GetTickCount();

	gChangeReset.SendChangeReset(CHANGE_RESET_5);

	this->Data[eCHANGE_RESET_MAIN].Close();
	// ----
	return false;
}
bool Interface::EventChangeResetWindow_10(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eCHANGE_RESET_10].EventTick);
	// ----
	if( !this->Data[eCHANGE_RESET_MAIN].OnShow || !IsWorkZone(eCHANGE_RESET_10) 
		|| !this->Data[eCHANGE_RESET_10].Attribute )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eCHANGE_RESET_10].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGE_RESET_10].OnClick = false;;
	// ----
	if( Delay < 1000 )
	{
		return false;
	}
	// ----
	this->Data[eCHANGE_RESET_10].EventTick = GetTickCount();

	gChangeReset.SendChangeReset(CHANGE_RESET_10);

	this->Data[eCHANGE_RESET_MAIN].Close();
	// ----
	return false;
}
bool Interface::EventChangeResetWindow_15(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eCHANGE_RESET_15].EventTick);
	// ----
	if( !this->Data[eCHANGE_RESET_MAIN].OnShow || !IsWorkZone(eCHANGE_RESET_15) 
		|| !this->Data[eCHANGE_RESET_15].Attribute )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eCHANGE_RESET_15].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGE_RESET_15].OnClick = false;;
	// ----
	if( Delay < 1000 )
	{
		return false;
	}
	// ----
	this->Data[eCHANGE_RESET_15].EventTick = GetTickCount();

	gChangeReset.SendChangeReset(CHANGE_RESET_15);

	this->Data[eCHANGE_RESET_MAIN].Close();
	// ----
	return false;
}
bool Interface::EventChangeResetWindow_20(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eCHANGE_RESET_20].EventTick);
	// ----
	if( !this->Data[eCHANGE_RESET_MAIN].OnShow || !IsWorkZone(eCHANGE_RESET_20) 
		|| !this->Data[eCHANGE_RESET_20].Attribute )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eCHANGE_RESET_20].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGE_RESET_20].OnClick = false;;
	// ----
	if( Delay < 1000 )
	{
		return false;
	}
	// ----
	this->Data[eCHANGE_RESET_20].EventTick = GetTickCount();

	gChangeReset.SendChangeReset(CHANGE_RESET_20);

	this->Data[eCHANGE_RESET_MAIN].Close();
	// ----
	return false;
}
bool Interface::EventChangeResetWindow_25(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eCHANGE_RESET_25].EventTick);

	DWORD DelayUserPanel = (GetTickCount() - this->Data[eMenu_RESETCHANGE].EventTick);
	if (DelayUserPanel < 500)
	{
		return false;
	}
	// ----
	if( !this->Data[eCHANGE_RESET_MAIN].OnShow || !IsWorkZone(eCHANGE_RESET_25) 
		|| !this->Data[eCHANGE_RESET_25].Attribute )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eCHANGE_RESET_25].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGE_RESET_25].OnClick = false;;
	// ----
	if( Delay < 1000 )
	{
		return false;
	}
	// ----
	this->Data[eCHANGE_RESET_25].EventTick = GetTickCount();

	gChangeReset.SendChangeReset(CHANGE_RESET_25);

	this->Data[eCHANGE_RESET_MAIN].Close();
	// ----
	return false;
}
// ===================================================================================================================== END ChangeReset

void Interface::WindowsProTecno()
{
	char interbajas[500];
	sprintf_s(interbajas, sizeof(interbajas), "Server: %s || Player: %s || Level: %d || Reset: %d || Files Premium", gProtect.m_MainInfo.WindowName, gObjUser.lpPlayer->Name, gObjUser.lpPlayer->Level, ViewReset);
	SetWindowText(pGameWindow, interbajas);
}
// ===================================================================================================================== END Barra de Informacion
void Interface::DrawSmithItem()
{
	if( !this->Data[eSMITH_MAIN].OnShow )
	{
		return;
	}

	if(gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
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
		this->Data[eSMITH_MAIN].OnShow		= false;
		gInterface.Data[eSMITH_MAIN].Close();		
		return;
	}
	// ----
	float MainWidth			= 230.0f;
	float MainHeight		= 313.0f;
	float StartY			= 100.0f;
	float StartBody			= 100.0;
	float StartX			= (MAX_WIN_WIDTH / 2.0f) - (MainWidth / 2.0f);
	float MainCenter		= StartX + (MainWidth / 3.0f);
	float ButtonX			= MainCenter - (29.0f / 2.0f);
	// ----
/*	this->DrawGUI(eSMITH_MAIN, StartX, StartY - 78);
	this->DrawGUI(eSMITH_TITLE, StartX, StartY - 80);
	StartY = this->DrawRepeatGUI(eSMITH_FRAME, StartX, StartY - 13.0, 13);
	this->DrawGUI(eSMITH_FOOTER, StartX, StartY + 80);
	pDrawGUI(0x7A7B, StartX, 275, 5, 100); //
	pDrawGUI(0x7A7B, StartX + 221, 276, 5, 100); //
	this->DrawGUI(eSMITH_CLOSE, StartX + MainWidth - this->Data[eSMITH_CLOSE].Width, this->Data[eSMITH_TITLE].Height + this->Data[eSMITH_CLOSE].Height - 78);
	this->DrawFormat(eGold, StartX + 95, 30,25, 5, "Smith Shop");
*/
	this->DrawGUI(eSMITH_TITLE, StartX, StartY);
	this->DrawGUI(eSMITH_FOOTER, StartX, StartY /*+ 80*/);
	pDrawGUI(0x7A7B, StartX, 275, 5, 100);
	pDrawGUI(0x7A7B, StartX + 221, 276, 5, 100);
	gCentral.PrintDropBox(StartX, StartY - 78, MainWidth, MainHeight + 75, 0, 0);
	this->DrawGUI(eSMITH_CLOSE, StartX + MainWidth - this->Data[eSMITH_CLOSE].Width, this->Data[eSMITH_TITLE].Height + this->Data[eSMITH_CLOSE].Height - 78);
	this->DrawFormat(eGold, StartX + 95, 30,25, 5, "Smith Shop");
	// ----
	if( this->IsWorkZone(eSMITH_CLOSE) )
	{
		DWORD Color = eGray100;
		// ----
		if( this->Data[eSMITH_CLOSE].OnClick )
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eSMITH_CLOSE, this->Data[eSMITH_CLOSE].X, StartBody, Color);
		this->DrawToolTip(this->Data[eSMITH_CLOSE].X + 5, StartBody + 25, "Close");
	}
	this->DrawFormat(eGold, StartX + 30, 50, 210, 1, "Group Item");
	pDrawGUI(0x7C0D, StartX + 15, 70, 16, 15); //
	pDrawGUI(0x7AA4, StartX + 73, 70, 16, 15); //
	switch (gSmithItem.ItemType)
	{
	case 0:
		this->DrawFormat(eGold, StartX + 40, 73,25, 5, "Sword");
		break;
	case 1:
		this->DrawFormat(eGold, StartX + 40, 73,25, 5, "Axe");
		break;
	case 2:
		this->DrawFormat(eGold, StartX + 40, 73,25, 5, "Scepter");
		break;
	case 3:
		this->DrawFormat(eGold, StartX + 40, 73,25, 5, "Spear");
		break;
	case 4:
		this->DrawFormat(eGold, StartX + 40, 73,25, 5, "Bow");
		break;
	case 5:
		this->DrawFormat(eGold, StartX + 40, 73,25, 5, "Staff");
		break;
	case 6:
		this->DrawFormat(eGold, StartX + 40, 73,25, 5, "Shield");
		break;
	case 7:
		this->DrawFormat(eGold, StartX + 40, 73,25, 5, "Helm");
		break;
	case 8:
		this->DrawFormat(eGold, StartX + 40, 73,25, 5, "Armor");
		break;
	case 9:
		this->DrawFormat(eGold, StartX + 40, 73,25, 5, "Pant");
		break;
	case 10:
		this->DrawFormat(eGold, StartX + 40, 73,25, 5, "Glove");
		break;
	case 11:
		this->DrawFormat(eGold, StartX + 40, 73,25, 5, "Boot");
		break;
	}
	this->DrawFormat(eGold, StartX + 160, 50, 210, 1, "Item Time");
	pDrawGUI(0x7C0D, StartX + 140, 70, 16, 15); //
	pDrawGUI(0x7AA4, StartX + 193, 70, 16, 15); //
	switch (gSmithItem.Days)
	{
	case 0:
		this->DrawFormat(eGold, StartX + 163, 73,25, 5, "1 Days");
		break;
	case 1:
		this->DrawFormat(eGold, StartX + 163, 73,25, 5, "7 Days");
		break;
	case 2:
		this->DrawFormat(eGold, StartX + 163, 73,25, 5, "30 Days");
		break;
	}
	pDrawGUI(0x79A2, StartX + 27, 100, 171, 23);
	pDrawGUI(0x7BAA, StartX + 8, 103, 17, 18);
	pDrawGUI(0x7BAB, StartX + 200, 103, 17, 18);
	switch(gSmithItem.ItemType){
	case 0:
		DrawItem2(StartX + 40,20,100,100,ITEM(gSmithItem.ItemType,gSmithItem.ItemIndex),gSmithItem.mLevel,gSmithItem.mExc,0,0);
		this->DrawFormat(eGold, StartX + 35, 106,25, 5, "%s",gCustomSmith.m_SmithSwordInfo[gSmithItem.ItemIndex].ItemName);
		break;
	case 1:
		DrawItem2(StartX + 40,20,100,100,ITEM(gSmithItem.ItemType,gSmithItem.ItemIndex),gSmithItem.mLevel,gSmithItem.mExc,0,0);
		this->DrawFormat(eGold, StartX + 35, 106,25, 5, "%s",gCustomSmith.m_SmithAxeInfo[gSmithItem.ItemIndex].ItemName);
		break;
	case 2:
		DrawItem2(StartX + 40,20,100,100,ITEM(gSmithItem.ItemType,gSmithItem.ItemIndex),gSmithItem.mLevel,gSmithItem.mExc,0,0);
		this->DrawFormat(eGold, StartX + 35, 106,25, 5, "%s",gCustomSmith.m_SmithMaceInfo[gSmithItem.ItemIndex].ItemName);
		break;
	case 3:
		DrawItem2(StartX + 55,20,100,100,ITEM(gSmithItem.ItemType,gSmithItem.ItemIndex),gSmithItem.mLevel,gSmithItem.mExc,0,0);
		this->DrawFormat(eGold, StartX + 35, 106,25, 5, "%s",gCustomSmith.m_SmithSpearInfo[gSmithItem.ItemIndex].ItemName);
		break;
	case 4:
		DrawItem2(StartX + 65,20,100,100,ITEM(gSmithItem.ItemType,gSmithItem.ItemIndex),gSmithItem.mLevel,gSmithItem.mExc,0,0);
		this->DrawFormat(eGold, StartX + 35, 106,25, 5, "%s",gCustomSmith.m_SmithBowInfo[gSmithItem.ItemIndex].ItemName);
		break;
	case 5:
		DrawItem2(StartX + 55,20,100,100,ITEM(gSmithItem.ItemType,gSmithItem.ItemIndex),gSmithItem.mLevel,gSmithItem.mExc,0,0);
		this->DrawFormat(eGold, StartX + 35, 106,25, 5, "%s",gCustomSmith.m_SmithStaffInfo[gSmithItem.ItemIndex].ItemName);
		break;
	case 6:
		DrawItem2(StartX + 65,20,100,100,ITEM(gSmithItem.ItemType,gSmithItem.ItemIndex),gSmithItem.mLevel,gSmithItem.mExc,0,0);
		this->DrawFormat(eGold, StartX + 35, 106,25, 5, "%s",gCustomSmith.m_SmithShieldInfo[gSmithItem.ItemIndex].ItemName);
		break;
	case 7:
		DrawItem2(StartX + 65,10,100,100,ITEM(gSmithItem.ItemType,gSmithItem.ItemIndex),gSmithItem.mLevel,gSmithItem.mExc,0,0);
		this->DrawFormat(eGold, StartX + 35, 106,25, 5, "%s",gCustomSmith.m_SmithHelmInfo[gSmithItem.ItemIndex].ItemName);
		break;
	case 8:
		DrawItem2(StartX + 65,15,100,100,ITEM(gSmithItem.ItemType,gSmithItem.ItemIndex),gSmithItem.mLevel,gSmithItem.mExc,0,0);
		this->DrawFormat(eGold, StartX + 35, 106,25, 5, "%s",gCustomSmith.m_SmithArmorInfo[gSmithItem.ItemIndex].ItemName);
		break;
	case 9:
		DrawItem2(StartX + 65,5,100,100,ITEM(gSmithItem.ItemType,gSmithItem.ItemIndex),gSmithItem.mLevel,gSmithItem.mExc,0,0);
		this->DrawFormat(eGold, StartX + 35, 106,25, 5, "%s",gCustomSmith.m_SmithPantInfo[gSmithItem.ItemIndex].ItemName);
		break;
	case 10:
		DrawItem2(StartX + 65,5,100,100,ITEM(gSmithItem.ItemType,gSmithItem.ItemIndex),gSmithItem.mLevel,gSmithItem.mExc,0,0);
		this->DrawFormat(eGold, StartX + 35, 106,25, 5, "%s",gCustomSmith.m_SmithGloveInfo[gSmithItem.ItemIndex].ItemName);
		break;
	case 11:
		DrawItem2(StartX + 65,5,100,100,ITEM(gSmithItem.ItemType,gSmithItem.ItemIndex),gSmithItem.mLevel,gSmithItem.mExc,0,0);
		this->DrawFormat(eGold, StartX + 35, 106,25, 5, "%s",gCustomSmith.m_SmithBootInfo[gSmithItem.ItemIndex].ItemName);
		break;
	}
	this->DrawGUI(eSMITH_DIV, StartX, 130);
	for( int i = 0; i < 10; i++ )
	{
		pDrawGUI(iOptionDot,StartX + 15,147 + (20 * i) + 9,10,10);
		pDrawGUI(0x7B5E, StartX + 30, 160 + (20 * i) + 9, 82.0, 2.0);
		pDrawGUI(0x7B5E, StartX + 30 + 82, 160 + (20 * i) + 9, 82.0, 2.0);
	}
	//Level
	this->DrawFormat(eGold, StartX + 40, 155,15, 5, "Item Level");
	pDrawGUI(0x7C0D, StartX + 140, 153, 16, 15); //
	pDrawGUI(0x7AA4, StartX + 180, 153, 16, 15); //
	this->DrawFormat(eGold, StartX + 155, 155,25, 5, "     %d",gSmithItem.mLevel);
	//Skill
	this->DrawFormat(eGold, StartX + 40, 175,15, 5, "Item Skill");
	pDrawButton(iOptionCheck,StartX + 180,175,15,15,0,15);
	if(gSmithItem.mSkill == 1)
	{
		pDrawButton(iOptionCheck,StartX + 180,175,15,15,0,0);
	}
	//Luck
	this->DrawFormat(eGold, StartX + 40, 195,15, 5, "Lucky Option");
	pDrawButton(iOptionCheck,StartX + 180,195,15,15,0,15);
	if(gSmithItem.mLuck == 1)
	{
		pDrawButton(iOptionCheck,StartX + 180,195,15,15,0,0);
	}
	//Option(Life)
	this->DrawFormat(eGold, StartX + 40, 215,15, 5, "Add Option");
	pDrawGUI(0x7C0D, StartX + 140, 213, 16, 15); //
	pDrawGUI(0x7AA4, StartX + 180, 213, 16, 15); //
	this->DrawFormat(eGold, StartX +155, 215,25, 5, "     %d",gSmithItem.mOpt);
	//
	if(gSmithItem.ItemType <= 5)
	{
	this->DrawFormat(eGold, StartX +40, 235,15, 5, "Excellent Damange Rate");
	pDrawButton(iOptionCheck,StartX + 180,235,15,15,0,15);
	if(gSmithItem.ExcOption == 32)
	{
		pDrawButton(iOptionCheck,StartX + 180,235,15,15,0,0);
	}
	//
	this->DrawFormat(eGold, StartX +40, 255,15, 5, "Increase Damage Level");
	pDrawButton(iOptionCheck,StartX + 180,255,15,15,0,15);
	if(gSmithItem.ExcOption1 == 16)
	{
		pDrawButton(iOptionCheck,StartX + 180,255,15,15,0,0);
	}
	//
	this->DrawFormat(eGold, StartX +40, 275,15, 5, "Increase Damage");
	pDrawButton(iOptionCheck,StartX + 180,275,15,15,0,15);

	if(gSmithItem.ExcOption2 == 8)
	{
		pDrawButton(iOptionCheck,StartX + 180,275,15,15,0,0);
	}
	//
	this->DrawFormat(eGold, StartX +40, 295,15, 5, "Increase Attacking(Wizard)Speed");
	pDrawButton(iOptionCheck,StartX + 180,295,15,15,0,15);
	if(gSmithItem.ExcOption3 == 4)
	{
		pDrawButton(iOptionCheck,StartX + 180,295,15,15,0,0);
	}
	//
	this->DrawFormat(eGold, StartX +40, 315,15, 5, "Increase Life Hunting Monster");
	pDrawButton(iOptionCheck,StartX + 180,315,15,15,0,15);
	if(gSmithItem.ExcOption4 == 2)
	{
		pDrawButton(iOptionCheck,StartX + 180,315,15,15,0,0);
	}
	//
	this->DrawFormat(eGold, StartX +40, 335,15, 5, "Increase Mana Hunting Monster");
	pDrawButton(iOptionCheck,StartX + 180,335,15,15,0,15);
	if(gSmithItem.ExcOption5 == 1)
	{
		pDrawButton(iOptionCheck,StartX + 180,335,15,15,0,0);
	}
	}
	if(gSmithItem.ItemType >= 6)
	{
	this->DrawFormat(eGold, StartX +40, 235,15, 5, "Increase Max HP");
	pDrawButton(iOptionCheck,StartX + 180,235,15,15,0,15);
	if(gSmithItem.ExcOption == 32)
	{
		pDrawButton(iOptionCheck,StartX + 180,235,15,15,0,0);
	}
	//
	this->DrawFormat(eGold, StartX +40, 255,15, 5, "Increase Max Mana");
	pDrawButton(iOptionCheck,StartX + 180,255,15,15,0,15);
	if(gSmithItem.ExcOption1 == 16){
		pDrawButton(iOptionCheck,StartX + 180,255,15,15,0,0);
	}
	this->DrawFormat(eGold, StartX +40, 275,15, 5, "Damage Decrease");
	pDrawButton(iOptionCheck,StartX + 180,275,15,15,0,15);
	if(gSmithItem.ExcOption2 == 8){
		pDrawButton(iOptionCheck,StartX + 180,275,15,15,0,0);
	}
	this->DrawFormat(eGold, StartX +40, 295,15, 5, "Reflect Damage");
	pDrawButton(iOptionCheck,StartX + 180,295,15,15,0,15);
	if(gSmithItem.ExcOption3 == 4){
		pDrawButton(iOptionCheck,StartX + 180,295,15,15,0,0);
	}
	this->DrawFormat(eGold, StartX +40, 315,15, 5, "Defense Success Rate");
	pDrawButton(iOptionCheck,StartX + 180,315,15,15,0,15);
	if(gSmithItem.ExcOption4 == 2){
		pDrawButton(iOptionCheck,StartX + 180,315,15,15,0,0);
	}
	this->DrawFormat(eGold, StartX +40, 335,15, 5, "Zen After Hunting Monsters");
	pDrawButton(iOptionCheck,StartX + 180,335,15,15,0,15);
	if(gSmithItem.ExcOption5 == 1){
		pDrawButton(iOptionCheck,StartX + 180,335,15,15,0,0);
	    }
	}
	this->DrawGUI(eSMITH_DIV, StartX, 370);
	this->DrawGUI(eSMITH_BUY, StartX + 50, 375);
	this->DrawFormat(eGold, StartX + 95, 380,15, 5, "Buy Item");
		if( IsWorkZone(eSMITH_BUY) )
		{
			DWORD Color = eGray100;
			if( this->Data[eSMITH_BUY].OnClick ){
				Color = eGray150;
			}
			this->DrawColoredGUI(eSMITH_BUY, this->Data[eSMITH_BUY].X, this->Data[eSMITH_BUY].Y, Color);
		}
	if( gSmithItem.ItemType == 0)
	{
		switch(gSmithItem.Days)
			{
				case 0:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithSwordInfo[gSmithItem.ItemIndex].Price1Days + gSmithItem.TotalPrice);
				break;
				case 1:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithSwordInfo[gSmithItem.ItemIndex].Price7Days + gSmithItem.TotalPrice);
				break;
				case 2:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithSwordInfo[gSmithItem.ItemIndex].Price30Days + gSmithItem.TotalPrice);
				break;
			}
	}
	else if( gSmithItem.ItemType == 1)
	{
		switch(gSmithItem.Days)
			{
				case 0:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithAxeInfo[gSmithItem.ItemIndex].Price1Days + gSmithItem.TotalPrice);
				break;
				case 1:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithAxeInfo[gSmithItem.ItemIndex].Price7Days + gSmithItem.TotalPrice);
				break;
				case 2:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithAxeInfo[gSmithItem.ItemIndex].Price30Days + gSmithItem.TotalPrice);
				break;
			}
	}
	if( gSmithItem.ItemType == 2)
	{
		switch(gSmithItem.Days)
			{
				case 0:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithMaceInfo[gSmithItem.ItemIndex].Price1Days + gSmithItem.TotalPrice);
				break;
				case 1:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithMaceInfo[gSmithItem.ItemIndex].Price7Days + gSmithItem.TotalPrice);
				break;
				case 2:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithMaceInfo[gSmithItem.ItemIndex].Price30Days + gSmithItem.TotalPrice);
				break;
			}
	}
	if( gSmithItem.ItemType == 3)
	{
		switch(gSmithItem.Days)
			{
				case 0:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithSpearInfo[gSmithItem.ItemIndex].Price1Days + gSmithItem.TotalPrice);
				break;
				case 1:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithSpearInfo[gSmithItem.ItemIndex].Price7Days + gSmithItem.TotalPrice);
				break;
				case 2:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithSpearInfo[gSmithItem.ItemIndex].Price30Days + gSmithItem.TotalPrice);
				break;
			}
	}
	if( gSmithItem.ItemType == 4)
	{
		switch(gSmithItem.Days)
			{
				case 0:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithBowInfo[gSmithItem.ItemIndex].Price1Days + gSmithItem.TotalPrice);
				break;
				case 1:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithBowInfo[gSmithItem.ItemIndex].Price7Days + gSmithItem.TotalPrice);
				break;
				case 2:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithBowInfo[gSmithItem.ItemIndex].Price30Days + gSmithItem.TotalPrice);
				break;
			}
	}
	if( gSmithItem.ItemType == 5)
	{
		switch(gSmithItem.Days)
			{
				case 0:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithStaffInfo[gSmithItem.ItemIndex].Price1Days + gSmithItem.TotalPrice);
				break;
				case 1:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithStaffInfo[gSmithItem.ItemIndex].Price7Days + gSmithItem.TotalPrice);
				break;
				case 2:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithStaffInfo[gSmithItem.ItemIndex].Price30Days + gSmithItem.TotalPrice);
				break;
			}
	}
	if( gSmithItem.ItemType == 6)
	{
		switch(gSmithItem.Days)
			{
				case 0:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithShieldInfo[gSmithItem.ItemIndex].Price1Days + gSmithItem.TotalPrice);
				break;
				case 1:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithShieldInfo[gSmithItem.ItemIndex].Price7Days + gSmithItem.TotalPrice);
				break;
				case 2:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithShieldInfo[gSmithItem.ItemIndex].Price30Days + gSmithItem.TotalPrice);
				break;
			}
	}
	if( gSmithItem.ItemType == 7)
	{
		switch(gSmithItem.Days)
			{
				case 0:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithHelmInfo[gSmithItem.ItemIndex].Price1Days + gSmithItem.TotalPrice);
				break;
				case 1:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithHelmInfo[gSmithItem.ItemIndex].Price7Days + gSmithItem.TotalPrice);
				break;
				case 2:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithHelmInfo[gSmithItem.ItemIndex].Price30Days + gSmithItem.TotalPrice);
				break;
			}
	}
	if( gSmithItem.ItemType == 8)
	{
		switch(gSmithItem.Days)
			{
				case 0:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithArmorInfo[gSmithItem.ItemIndex].Price1Days + gSmithItem.TotalPrice);
				break;
				case 1:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithArmorInfo[gSmithItem.ItemIndex].Price7Days + gSmithItem.TotalPrice);
				break;
				case 2:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithArmorInfo[gSmithItem.ItemIndex].Price30Days + gSmithItem.TotalPrice);
				break;
			}
	}
	if( gSmithItem.ItemType == 9)
	{
		switch(gSmithItem.Days)
			{
				case 0:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithPantInfo[gSmithItem.ItemIndex].Price1Days + gSmithItem.TotalPrice);
				break;
				case 1:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithPantInfo[gSmithItem.ItemIndex].Price7Days + gSmithItem.TotalPrice);
				break;
				case 2:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithPantInfo[gSmithItem.ItemIndex].Price30Days + gSmithItem.TotalPrice);
				break;
			}
	}
	if( gSmithItem.ItemType == 10)
	{
		switch(gSmithItem.Days)
			{
				case 0:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithGloveInfo[gSmithItem.ItemIndex].Price1Days + gSmithItem.TotalPrice);
				break;
				case 1:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithGloveInfo[gSmithItem.ItemIndex].Price7Days + gSmithItem.TotalPrice);
				break;
				case 2:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithGloveInfo[gSmithItem.ItemIndex].Price30Days + gSmithItem.TotalPrice);
				break;
			}
	}
	if( gSmithItem.ItemType == 11)
	{
		switch(gSmithItem.Days)
			{
				case 0:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithBootInfo[gSmithItem.ItemIndex].Price1Days + gSmithItem.TotalPrice);
				break;
				case 1:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithBootInfo[gSmithItem.ItemIndex].Price7Days + gSmithItem.TotalPrice);
				break;
				case 2:
					this->DrawFormat(eRed,StartX + 150, 106,15, 5,"Price %d", gCustomSmith.m_SmithBootInfo[gSmithItem.ItemIndex].Price30Days + gSmithItem.TotalPrice);
				break;
			}
	}
}
void Interface::EventSmithItem_Main(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	if( !this->Data[eSMITH_MAIN].OnShow )
	{
		return;
	}
	if (this->IsWorkZone(eSMITH_SKILL))
	{
		DWORD Delay = (CurrentTick - this->Data[eSMITH_SKILL].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSMITH_SKILL].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eSMITH_SKILL].OnClick = false;
		pSetCursorFocus = true;
		// ----
		if (Delay < 1000)
		{
			return;
		}
		// ----
		this->Data[eSMITH_SKILL].EventTick = GetTickCount();
		// ----
		if (!this->Data[eSMITH_SKILL_1].OnShow)
		{
			this->Data[eSMITH_SKILL_1].OnShow = true;
			gSmithItem.mSkill = 1;
			gSmithItem.TotalPrice += gSmithItem.pSkill;
		}
		else {
			this->Data[eSMITH_SKILL_1].OnShow = false;
			gSmithItem.mSkill = 0;
			gSmithItem.TotalPrice -= gSmithItem.pSkill;
		}
	}
	else if (this->IsWorkZone(eSMITH_LUCK))
	{
		DWORD Delay = (CurrentTick - this->Data[eSMITH_LUCK].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSMITH_LUCK].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eSMITH_LUCK].OnClick = false;
		pSetCursorFocus = true;
		// ----
		if (Delay < 1000)
		{
			return;
		}
		// ----
		this->Data[eSMITH_LUCK].EventTick = GetTickCount();
		// ----
		if (!this->Data[eSMITH_LUCK_1].OnShow)
		{
			this->Data[eSMITH_LUCK_1].OnShow = true;
			gSmithItem.mLuck = 1;
			gSmithItem.TotalPrice += gSmithItem.pLuck;
		}
		else {
			this->Data[eSMITH_LUCK_1].OnShow = false;
			gSmithItem.mLuck = 0;
			gSmithItem.TotalPrice -= gSmithItem.pLuck;
		}
	}
	else if (this->IsWorkZone(eSMITH_EXC))
	{
		DWORD Delay = (CurrentTick - this->Data[eSMITH_EXC].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSMITH_EXC].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eSMITH_EXC].OnClick = false;
		pSetCursorFocus = true;
		// ----
		if (Delay < 1000)
		{
			return;
		}
		// ----
		this->Data[eSMITH_EXC].EventTick = GetTickCount();
		// ----
		if (!this->Data[eSMITH_EXC_1].OnShow)
		{
			this->Data[eSMITH_EXC_1].OnShow = true;
			gSmithItem.ExcOption = 32;
			gSmithItem.mExc += 1;
			gSmithItem.TotalPrice += gSmithItem.pExc;
		}
		else {
			this->Data[eSMITH_EXC_1].OnShow = false;
			gSmithItem.ExcOption = 0;
			gSmithItem.mExc -= 1;
			gSmithItem.TotalPrice -= gSmithItem.pExc;
		}
	}
	else if (this->IsWorkZone(eSMITH_EXC1))
	{
		DWORD Delay = (CurrentTick - this->Data[eSMITH_EXC1].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSMITH_EXC1].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eSMITH_EXC1].OnClick = false;
		pSetCursorFocus = true;
		// ----
		if (Delay < 1000)
		{
			return;
		}
		// ----
		this->Data[eSMITH_EXC1].EventTick = GetTickCount();
		// ----
		if (!this->Data[eSMITH_EXC1_1].OnShow)
		{
			this->Data[eSMITH_EXC1_1].OnShow = true;
			gSmithItem.ExcOption1 = 16;
			gSmithItem.mExc += 1;
			gSmithItem.TotalPrice += gSmithItem.pExc1;
		}
		else {
			this->Data[eSMITH_EXC1_1].OnShow = false;
			gSmithItem.ExcOption1 = 0;
			gSmithItem.mExc -= 1;
			gSmithItem.TotalPrice -= gSmithItem.pExc1;
		}
	}
	else if (this->IsWorkZone(eSMITH_EXC2))
	{
		DWORD Delay = (CurrentTick - this->Data[eSMITH_EXC2].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSMITH_EXC2].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eSMITH_EXC2].OnClick = false;
		pSetCursorFocus = true;
		// ----
		if (Delay < 1000)
		{
			return;
		}
		// ----
		this->Data[eSMITH_EXC2].EventTick = GetTickCount();
		// ----
		if (!this->Data[eSMITH_EXC2_1].OnShow)
		{
			this->Data[eSMITH_EXC2_1].OnShow = true;
			gSmithItem.ExcOption2 = 8;
			gSmithItem.mExc += 1;
			gSmithItem.TotalPrice += gSmithItem.pExc2;
		}
		else {
			this->Data[eSMITH_EXC2_1].OnShow = false;
			gSmithItem.ExcOption2 = 0;
			gSmithItem.mExc -= 1;
			gSmithItem.TotalPrice -= gSmithItem.pExc2;
		}
	}
	else if (this->IsWorkZone(eSMITH_EXC3))
	{
		DWORD Delay = (CurrentTick - this->Data[eSMITH_EXC3].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSMITH_EXC3].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eSMITH_EXC3].OnClick = false;
		pSetCursorFocus = true;
		// ----
		if (Delay < 1000)
		{
			return;
		}
		// ----
		this->Data[eSMITH_EXC3].EventTick = GetTickCount();
		// ----
		if (!this->Data[eSMITH_EXC3_1].OnShow)
		{
			this->Data[eSMITH_EXC3_1].OnShow = true;
			gSmithItem.ExcOption3 = 4;
			gSmithItem.mExc += 1;
			gSmithItem.TotalPrice += gSmithItem.pExc3;
		}
		else {
			this->Data[eSMITH_EXC3_1].OnShow = false;
			gSmithItem.ExcOption3 = 0;
			gSmithItem.mExc -= 1;
			gSmithItem.TotalPrice -= gSmithItem.pExc3;
		}
	}
	else if (this->IsWorkZone(eSMITH_EXC4))
	{
		DWORD Delay = (CurrentTick - this->Data[eSMITH_EXC4].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSMITH_EXC4].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eSMITH_EXC4].OnClick = false;
		pSetCursorFocus = true;
		// ----
		if (Delay < 1000)
		{
			return;
		}
		// ----
		this->Data[eSMITH_EXC4].EventTick = GetTickCount();
		// ----
		if (!this->Data[eSMITH_EXC4_1].OnShow)
		{
			this->Data[eSMITH_EXC4_1].OnShow = true;
			gSmithItem.ExcOption4 = 2;
			gSmithItem.mExc += 1;
			gSmithItem.TotalPrice += gSmithItem.pExc4;
		}
		else {
			this->Data[eSMITH_EXC4_1].OnShow = false;
			gSmithItem.ExcOption4 = 0;
			gSmithItem.mExc -= 1;
			gSmithItem.TotalPrice -= gSmithItem.pExc4;
		}
	}
	else if (this->IsWorkZone(eSMITH_EXC5))
	{
		DWORD Delay = (CurrentTick - this->Data[eSMITH_EXC5].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSMITH_EXC5].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eSMITH_EXC5].OnClick = false;
		pSetCursorFocus = true;
		// ----
		if (Delay < 1000)
		{
			return;
		}
		// ----
		this->Data[eSMITH_EXC5].EventTick = GetTickCount();
		// ----
		if (!this->Data[eSMITH_EXC5_1].OnShow)
		{
			this->Data[eSMITH_EXC5_1].OnShow = true;
			gSmithItem.ExcOption5 = 1;
			gSmithItem.mExc += 1;
			gSmithItem.TotalPrice += gSmithItem.pExc5;
		}
		else {
			this->Data[eSMITH_EXC5_1].OnShow = false;
			gSmithItem.ExcOption5 = 0;
			gSmithItem.mExc -= 1;
			gSmithItem.TotalPrice -= gSmithItem.pExc5;
		}
	}
	else if (this->IsWorkZone(eSMITH_LEVEL))
	{
	DWORD Delay = (CurrentTick - this->Data[eSMITH_LEVEL].EventTick);
	// ----
	if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSMITH_LEVEL].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
	// ----
	this->Data[eSMITH_LEVEL].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if (Delay < 100)
		{
			return;
		}
	// ----
	this->Data[eSMITH_LEVEL].EventTick = GetTickCount();
	if(gSmithItem.mLevel <= 0)
	{return;}
	else
	{
		gSmithItem.mLevel	-=	1;
		gSmithItem.TotalPrice -= gSmithItem.pLevel;
	}
	}
	else if (this->IsWorkZone(eSMITH_LEVEL_1))
	{
	DWORD Delay = (CurrentTick - this->Data[eSMITH_LEVEL_1].EventTick);
	// ----
	if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSMITH_LEVEL_1].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
	// ----
	this->Data[eSMITH_LEVEL_1].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if (Delay < 100)
		{
			return;
		}
	// ----
	this->Data[eSMITH_LEVEL_1].EventTick = GetTickCount();
	if(gSmithItem.mLevel >= gSmithItem.MaxLevel)
	{return;}
	else
	{
		gSmithItem.mLevel	+=	1;
		gSmithItem.TotalPrice += gSmithItem.pLevel;
	}
	}
	else if (this->IsWorkZone(eSMITH_OPT))
	{
	DWORD Delay = (CurrentTick - this->Data[eSMITH_OPT].EventTick);
	// ----
	if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSMITH_OPT].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
	// ----
	this->Data[eSMITH_OPT].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if (Delay < 100)
		{
			return;
		}
	// ----
	this->Data[eSMITH_OPT].EventTick = GetTickCount();
	if(gSmithItem.mOpt <= 0)
	{return;}
	else
	{
		gSmithItem.mOpt	-=	1;
		gSmithItem.TotalPrice -= gSmithItem.pOpt;
	}
	}
	else if (this->IsWorkZone(eSMITH_OPT_1))
	{
	DWORD Delay = (CurrentTick - this->Data[eSMITH_OPT_1].EventTick);
	// ----
	if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSMITH_OPT_1].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
	// ----
	this->Data[eSMITH_OPT_1].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if (Delay < 100)
		{
			return;
		}
	// ----
	this->Data[eSMITH_OPT_1].EventTick = GetTickCount();
	if(gSmithItem.mOpt >= gSmithItem.MaxOpt)
	{return;}
	else
	{
		gSmithItem.mOpt	+=	1;
		gSmithItem.TotalPrice += gSmithItem.pOpt;
	}
	}
	else if (this->IsWorkZone(eSMITH_ITEMTYPE))
	{
	DWORD Delay = (CurrentTick - this->Data[eSMITH_ITEMTYPE].EventTick);
	// ----
	if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSMITH_ITEMTYPE].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
	// ----
	this->Data[eSMITH_ITEMTYPE].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if (Delay < 100)
		{
			return;
		}
	// ----
	this->Data[eSMITH_ITEMTYPE].EventTick = GetTickCount();
	if(gSmithItem.ItemType <= 0)
	{return;}
	else
	{
		gSmithItem.ItemType	-=	1;
		gSmithItem.ItemIndex = 0;
	}
	}
	else if (this->IsWorkZone(eSMITH_ITEMTYPE_1))
	{
	DWORD Delay = (CurrentTick - this->Data[eSMITH_ITEMTYPE_1].EventTick);
	// ----
	if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSMITH_ITEMTYPE_1].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
	// ----
	this->Data[eSMITH_ITEMTYPE_1].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if (Delay < 100)
		{
			return;
		}
	// ----
	this->Data[eSMITH_ITEMTYPE_1].EventTick = GetTickCount();
	if(gSmithItem.ItemType >= 11)
	{return;}
	else
	{gSmithItem.ItemType	+=	1;
	gSmithItem.ItemIndex = 0;}
	}
	else if (this->IsWorkZone(eSMITH_DAYS))
	{
	DWORD Delay = (CurrentTick - this->Data[eSMITH_DAYS].EventTick);
	// ----
	if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSMITH_DAYS].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
	// ----
	this->Data[eSMITH_DAYS].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if (Delay < 100)
		{
			return;
		}
	// ----
	this->Data[eSMITH_DAYS].EventTick = GetTickCount();
	if(gSmithItem.Days <= 0)
	{return;}
	else
	{gSmithItem.Days	-=	1;}
	}
	else if (this->IsWorkZone(eSMITH_DAYS_1))
	{
	DWORD Delay = (CurrentTick - this->Data[eSMITH_DAYS_1].EventTick);
	// ----
	if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSMITH_DAYS_1].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
	// ----
	this->Data[eSMITH_DAYS_1].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if (Delay < 100)
		{
			return;
		}
	// ----
	this->Data[eSMITH_DAYS_1].EventTick = GetTickCount();
	if(gSmithItem.Days >= 2)
	{return;}
	else
	{gSmithItem.Days	+=	1;}
	}
	else if (this->IsWorkZone(eSMITH_ITEMINDEX))
	{
	DWORD Delay = (CurrentTick - this->Data[eSMITH_ITEMINDEX].EventTick);
	// ----
	if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSMITH_ITEMINDEX].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
	// ----
	this->Data[eSMITH_ITEMINDEX].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if (Delay < 100)
		{
			return;
		}
	// ----
	this->Data[eSMITH_ITEMINDEX].EventTick = GetTickCount();

	if(gSmithItem.ItemIndex <= 0 )
	{return;}

	if (gSmithItem.ItemType == 0)
	{
		if(gSmithItem.ItemIndex == 31)
		{
			gSmithItem.ItemIndex -=	6;
		}
		else
			gSmithItem.ItemIndex -=	1;
	}
	else if (gSmithItem.ItemType == 2)
	{
		if(gSmithItem.ItemIndex == 18)
		{
			gSmithItem.ItemIndex -=	2;
		}
		else
			gSmithItem.ItemIndex -=	1;
	}
	else if(gSmithItem.ItemType == 4)
		{
			if(gSmithItem.ItemIndex == 8 ||
				gSmithItem.ItemIndex == 16||
				gSmithItem.ItemIndex == 24)
				{
				gSmithItem.ItemIndex -=	2;
				}
			else
				gSmithItem.ItemIndex -=	1;
		}
	else if(gSmithItem.ItemType == 7)
		{
			if(gSmithItem.ItemIndex == 16 ||
				gSmithItem.ItemIndex == 11 ||
				gSmithItem.ItemIndex == 24 ||
				gSmithItem.ItemIndex == 33 ||
				gSmithItem.ItemIndex == 38)	
				{
				gSmithItem.ItemIndex -=	2;
				}
			else
				gSmithItem.ItemIndex -=	1;
		}
	else
	{
		gSmithItem.ItemIndex	-=	1;
	}
	}
	else if (this->IsWorkZone(eSMITH_ITEMINDEX_1))
	{
	DWORD Delay = (CurrentTick - this->Data[eSMITH_ITEMINDEX_1].EventTick);
	// ----
	if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSMITH_ITEMINDEX_1].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
	// ----
	this->Data[eSMITH_ITEMINDEX_1].OnClick = false;
	pSetCursorFocus = true;
	// ----
	if (Delay < 100)
		{
			return;
		}
	// ----
	this->Data[eSMITH_ITEMINDEX_1].EventTick = GetTickCount();
	if (gSmithItem.ItemType == 0)
	{
		if(gSmithItem.ItemIndex >= 35)
			return;

		if(gSmithItem.ItemIndex == 25)
		{
			gSmithItem.ItemIndex +=	6;
		}
		else
			gSmithItem.ItemIndex +=	1;
	}
	else if (gSmithItem.ItemType == 1)
	{
		if(gSmithItem.ItemIndex >= 8)
		{
			return;
		}
		else
		gSmithItem.ItemIndex +=	1;
	}
	else if (gSmithItem.ItemType == 2)
	{
		if(gSmithItem.ItemIndex >= 18)
		{
			return;
		}
		if(gSmithItem.ItemIndex == 16)
		{
			gSmithItem.ItemIndex +=	2;
		}
		else
		gSmithItem.ItemIndex +=	1;
	}
	else if (gSmithItem.ItemType == 3)
	{
		if(gSmithItem.ItemIndex >= 11)
		{
			return;
		}
		else
		gSmithItem.ItemIndex +=	1;
	}
	else if(gSmithItem.ItemType == 4)
		{
			if(gSmithItem.ItemIndex >= 24)
			{
			return;
			}
			else if(gSmithItem.ItemIndex == 6 ||
				gSmithItem.ItemIndex == 14 ||
				gSmithItem.ItemIndex == 22)
				{
				gSmithItem.ItemIndex +=	2;
				}
			else
				gSmithItem.ItemIndex +=	1;
		}
	else if (gSmithItem.ItemType == 5)
	{
		if(gSmithItem.ItemIndex >= 23)
		{
			return;
		}
		else
		gSmithItem.ItemIndex +=	1;
	}
	else if (gSmithItem.ItemType == 6)
	{
		if(gSmithItem.ItemIndex >= 16)
		{
			return;
		}
		else
		gSmithItem.ItemIndex +=	1;
	}
	else if(gSmithItem.ItemType == 7)
		{
			if(gSmithItem.ItemIndex >= 43)
			return;

			else if(gSmithItem.ItemIndex == 14 ||
				gSmithItem.ItemIndex == 19 ||
				gSmithItem.ItemIndex == 22 ||
				gSmithItem.ItemIndex == 31 ||
				gSmithItem.ItemIndex == 36)	
				{
				gSmithItem.ItemIndex +=	2;
				}
			else
				gSmithItem.ItemIndex +=	1;
		}
	else
	{
		if(gSmithItem.ItemIndex >= 43)
		return;
		gSmithItem.ItemIndex	+=	1;
	}
	}
	else if (this->IsWorkZone(eSMITH_CLOSE))
	{
	DWORD Delay = (CurrentTick - this->Data[eSMITH_CLOSE].EventTick);
	// ----
	if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSMITH_CLOSE].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
	// ----
	this->Data[eSMITH_CLOSE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 1000)
		{
			return;
		}
	// ----
	this->Data[eSMITH_CLOSE].EventTick = GetTickCount();
	this->CloseSmithItemWindow();
	}
	else if (this->IsWorkZone(eSMITH_BUY))
	{
	DWORD Delay = (CurrentTick - this->Data[eSMITH_BUY].EventTick);
	// ----
	if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSMITH_BUY].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
	// ----
	this->Data[eSMITH_BUY].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 1000)
		{
			return;
		}
	// ----
	this->Data[eSMITH_BUY].EventTick = GetTickCount();
	if(gSmithItem.ItemType >= 7)
	{
		gSmithItem.mSkill = 0;
	}
	SDHP_BUYSVSHOP pMsg;
	pMsg.h.set(0xF5, 0x08, sizeof(pMsg));//0xFB
	pMsg.ItemType = gSmithItem.ItemType;
	pMsg.ItemIndex = gSmithItem.ItemIndex;
	pMsg.Days	= gSmithItem.Days;
	pMsg.mLevel = gSmithItem.mLevel;
	pMsg.mSkill = gSmithItem.mSkill;
	pMsg.mLuck = gSmithItem.mLuck;
	pMsg.mOpt = gSmithItem.mOpt;
	pMsg.ExcOption = gSmithItem.ExcOption;
	pMsg.ExcOption1 = gSmithItem.ExcOption1;
	pMsg.ExcOption2 = gSmithItem.ExcOption2;
	pMsg.ExcOption3 = gSmithItem.ExcOption3;
	pMsg.ExcOption4 = gSmithItem.ExcOption4;
	pMsg.ExcOption5 = gSmithItem.ExcOption5;
	pMsg.mExc = gSmithItem.mExc;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
	this->CloseSmithItemWindow();
	}
}

void Interface::TextDraw(int PosX, int PosY, int Width, int Arg5, int Color, int Arg7, int Align, HGDIOBJ Font, LPCTSTR Format, ...)
{
	char TextBuff[1024] = { 0 };
	va_list va;
	va_start(va, Format);
	vsprintf_s(TextBuff, Format, va);
	va_end(va);

	int v13; // ST1C_4@1
	int v15; // ST20_4@1
	pSetFont(pTextThis(), (int)Font);
	v13 = sub_41FFE0_Addr(pTextThis());
	v15 = sub_420010_Addr(pTextThis());
	SetTextColorByHDC(pTextThis(), Color);
	sub_4200F0_Addr(pTextThis(), Arg7);
	pSetBkColor(pTextThis(), 255, 255, 255, 0);
	pDrawText(pTextThis(), PosX, PosY, TextBuff, Width, Arg5, (int*)Align, 0);
	SetTextColorByHDC(pTextThis(), v13);
	sub_4200F0_Addr(pTextThis(), v15);
}

void Interface::DrawText(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...) // OK
{
	char Buff[2048];
	const int BuffLen = sizeof(Buff) - 1;
	ZeroMemory(Buff, BuffLen);

	va_list args;
	va_start(args, Text);
	vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	char * Line = strtok(Buff, "\n");

	while (Line != nullptr)
	{
		DrawInterfaceText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}
}

void Interface::SwitchTuChan(){

	if((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000 ||this->CheckWindow(ChatWindow))
	{
		return;
	}
	//melo920 revisar
		gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

		int ShowTuChan =  GetPrivateProfileInt ( "TUCHAN", "OnOff", 1, ".\\Settings.ini" );

		if (ShowTuChan != 0)
		{
			ShowTuChan = 0;
			WritePrivateProfileStringA("TUCHAN","OnOff"," 0","./Settings.ini");
		}
		else 
		{
			ShowTuChan = 1;
			WritePrivateProfileStringA("TUCHAN","OnOff"," 1","./Settings.ini");
		}
}
