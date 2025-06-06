#include "stdafx.h"
#include "CustomRanking.h"
#include "Defines.h"
#include "HealthBar.h"
#include "Interface.h"
#include "Util.h"
#include "Object.h"
#include "Import.h"
#include "Central.h"

CCustomRanking gCustomRanking;

CCustomRanking::CCustomRanking()
{
	this->Moving = false;
	this->ultimoX = 205;
    this->ultimoY = 94;
}

CCustomRanking::~CCustomRanking()
{	
}

void CCustomRanking::ClearCustomRanking() // OK
{
	for(int n=0;n < MAX_RANK;n++)
	{
		memset(gCustomRanking[n].szName,0,sizeof(gCustomRanking[n].szName));
		gCustomRanking[n].valor = -1;
	}
	this->RankEnable = 0;
}

void CCustomRanking::GCReqRanking(PMSG_CUSTOM_RANKING_RECV* lpMsg) // OK
{
	//this->ClearCustomRanking();

	memcpy(this->rankname,lpMsg->rankname,sizeof(this->rankname)); 
	memcpy(this->col1,lpMsg->col1,sizeof(this->col1)); 
	memcpy(this->col2,lpMsg->col2,sizeof(this->col2));
	this->RankEnable = 1;

	this->count = lpMsg->count;

	for(int n=0;n < lpMsg->count;n++)
	{
		CUSTOM_RANKING_DATA* lpInfo = (CUSTOM_RANKING_DATA*)(((BYTE*)lpMsg)+sizeof(PMSG_CUSTOM_RANKING_RECV)+(sizeof(CUSTOM_RANKING_DATA)*n));

		memcpy(gCustomRanking[n].szName,lpInfo->szName,sizeof(gCustomRanking[n].szName));
		gCustomRanking[n].valor = lpInfo->valor;
	}
}

void CCustomRanking::GCReqRankingCount(PMSG_CUSTOM_RANKING_COUNT_RECV* lpMsg) // OK
{
	this->RankingCount = (lpMsg->count > 0) ? lpMsg->count : 0;
}

int NextRanking = 0;
int PrevRanking = 0;

void CCustomRanking::DrawRankPanelWindow()
{
	if( !gInterface.Data[eRankPANEL_MAIN].OnShow )
	{
		return;
	}
	
	float MainWidth			= 230.0;
	float MainHeight		= 240.0;
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

	DWORD Color = eGray100;

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartY + 10, 210, 3, "Ranking %s",this->rankname );

	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartY + 35, 200, 1); //-- Divisor
	
	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartY + 210, 200, 1); //-- Divisor

	if (this->RankingType > 0 )
	{
		gInterface.DrawGUI2(eSAMPLEBUTTON2, StartX + 10, StartY + 76);
	}
	else 
	{
		gInterface.ResetDrawIMG2(eSAMPLEBUTTON2);
	}

	if (this->RankingType < this->RankingCount-1)
	{
		gInterface.DrawGUI2(eSAMPLEBUTTON, StartX + MainWidth - gInterface.Data[eSAMPLEBUTTON].Width - 15, StartY + 76);
	}
	else
	{
		gInterface.ResetDrawIMG2(eSAMPLEBUTTON);
	}
	
	if (this->RankEnable == 1)
	{

		//gInterface.DrawFormat(eAncient,  MainCenter - (sizeof(this->rankname) / 2)-15, StartY + 40, 52, 3, "(%s)",this->rankname);

		gInterface.DrawFormat(eWhite,  StartX + 65, StartY + 55, 52, 1,"Rank:");

		gInterface.DrawFormat(eWhite,  StartX + 90, StartY + 55, 52, 1,"%s", this->col1);

		gInterface.DrawFormat(eWhite,  StartX + 145, StartY + 55, 52, 1,"%s", this->col2);

		char* name = (char*)(oUserPreviewStruct+0x38);

		for (int i=0; i < this->count; i++)
		{

			Color = eGold;

			if (strcmp(name,this->gCustomRanking[i].szName) == 0)
			{
				Color = eExcellent;
			}

			gInterface.DrawFormat(Color,  StartX + 65, StartY + 70 + (12*i), 52, 1,"%dº", (i+1));

			gInterface.DrawFormat(Color,  StartX + 90, StartY + 70 + (12*i), 52, 1,"%s", this->gCustomRanking[i].szName);

			gInterface.DrawFormat(Color,  StartX + 145, StartY + 70 + (12*i), 52, 1,"%d", this->gCustomRanking[i].valor);

			//gInterface.DrawFormat(eGray100,  StartX + 64, StartBody + 55 + (12*i) + 2, 110, 1,"_________________________________");
		}
	}
	else 
	{
		if (this->RankLoad == 1)
		{
			gInterface.DrawFormat(eGold, StartX + 76 - (sizeof(this->rankname) / 2)+30, StartY + 120, 52, 1,"Loading ..");
			this->RankLoad = 2;
		}
		else if(this->RankLoad == 2)
		{
			gInterface.DrawFormat(eGold, StartX + 76 - (sizeof(this->rankname) / 2)+30, StartY + 120, 52, 1,"Loading ...");
			this->RankLoad = 3;
		}
		else if(this->RankLoad == 3)
		{
			gInterface.DrawFormat(eGold, StartX + 76 - (sizeof(this->rankname) / 2)+30, StartY + 120, 52, 1,"Loading ....");
			this->RankLoad = 4;
		}
		else if(this->RankLoad == 4)
		{
			gInterface.DrawFormat(eGold, StartX + 76 - (sizeof(this->rankname) / 2)+30, StartY + 120, 52, 1,"Loading .....");
			this->RankLoad = 0;
		}
		else
		{
			gInterface.DrawFormat(eGold, StartX + 76 - (sizeof(this->rankname) / 2)+30, StartY + 120, 52, 1,"Loading .");
			this->RankLoad = 1;
		}
	}
}

bool CCustomRanking::EventRankingNext(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - gInterface.Data[eSAMPLEBUTTON].EventTick);
	DWORD Delay2		= (CurrentTick - gInterface.Data[eSAMPLEBUTTON2].EventTick);

	if( !gInterface.Data[eRankPANEL_MAIN].OnShow || NextRanking == -1)
	{
		return false;
	}
	
	if( !gInterface.IsWorkZone(eSAMPLEBUTTON) )
	{
		return false;
	}

	if( Event == WM_LBUTTONDOWN )
	{
		gInterface.Data[eSAMPLEBUTTON].OnClick = true;
		return true;
	}

	if( Delay < 1000 || Delay2 < 1000 )
	{
		return false;
	}
	
	this->ClearCustomRanking();
	
	gInterface.Data[eSAMPLEBUTTON].OnClick = false;
	
	gInterface.Data[eSAMPLEBUTTON].EventTick = GetTickCount();
	
	PMSG_CUSTOM_RANKING_SEND pMsg;

	pMsg.header.set(0xF3, 0xE6,sizeof(pMsg));

	RankingType++;
	pMsg.type = RankingType;

	DataSend((BYTE*)&pMsg,pMsg.header.size);
	return true;
}

bool CCustomRanking::EventRankingBack(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - gInterface.Data[eSAMPLEBUTTON].EventTick);
	DWORD Delay2		= (CurrentTick - gInterface.Data[eSAMPLEBUTTON2].EventTick);

	if( !gInterface.Data[eRankPANEL_MAIN].OnShow || PrevRanking == -1)
	{
		return false;
	}
	
	if( !gInterface.IsWorkZone(eSAMPLEBUTTON2) )
	{
		return false;
	}

	if( Event == WM_LBUTTONDOWN )
	{
		gInterface.Data[eSAMPLEBUTTON2].OnClick = true;
		return true;
	}

	if( Delay < 1000 || Delay2 < 1000 )
	{
		return false;
	}

	this->ClearCustomRanking();
	
	gInterface.Data[eSAMPLEBUTTON2].OnClick = false;
	
		gInterface.Data[eSAMPLEBUTTON2].EventTick = GetTickCount();
	
		PMSG_CUSTOM_RANKING_SEND pMsg;

		pMsg.header.set(0xF3, 0xE6,sizeof(pMsg));

		RankingType--;
		pMsg.type = RankingType;

		DataSend((BYTE*)&pMsg,pMsg.header.size);
		return true;
}

bool CCustomRanking::EventVipWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eRanking_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[eRankPANEL_MAIN].OnShow || !gInterface.IsWorkZone(eRanking_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eRanking_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eRanking_CLOSE].OnClick = false;
	// ----
	if (Delay < 1000)
	{
		return false;
	}
	// ----
	gInterface.Data[eRanking_CLOSE].EventTick = GetTickCount();
	gInterface.Data[eRankPANEL_MAIN].OnShow = false;
	
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

void CCustomRanking::OpenWindow()
{

	if((GetTickCount() - gInterface.Data[eRankPANEL_MAIN].EventTick) < 1500 )
	{
		//gInterface.Data[eRankPANEL_MAIN].OnShow = false;
		return;
	}

	gInterface.Data[eRankPANEL_MAIN].EventTick = GetTickCount();

	if (gInterface.Data[eRankPANEL_MAIN].OnShow == true)
	{
		gInterface.Data[eRankPANEL_MAIN].OnShow = false;
		
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
		return;
	}

	gInterface.CloseCustomWindow();

	this->ClearCustomRanking();

	this->RankingCount = 0;

	PMSG_CUSTOM_RANKING_COUNT_SEND pMsg1;

	pMsg1.header.set(0xF3, 0xE7,sizeof(pMsg1));

	DataSend((BYTE*)&pMsg1,pMsg1.header.size);

	PMSG_CUSTOM_RANKING_SEND pMsg;

	pMsg.header.set(0xF3, 0xE6,sizeof(pMsg));

	this->RankingType = 0;

	pMsg.type = 0;

	DataSend((BYTE*)&pMsg,pMsg.header.size);

	//gInterface.Data[eRankPANEL_MAIN].EventTick = GetTickCount();
	gInterface.Data[eRankPANEL_MAIN].OnShow = true;
	
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}

}