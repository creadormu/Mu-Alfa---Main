#include "stdafx.h"
#include "GS_SEND_CLIENT.h"
#include "Protocol.h"

RecvGS gRecvGS;

RecvGS::RecvGS()
{
}
// -------------------------------------------------------------------------------

RecvGS::~RecvGS()
{
	// ----
}
//-----------------------------
void RecvGS::GetInfoRankTitle(PMSG_RANKTITLE_UPD * aRecv)
{
	//-----------------------------
	this->m_RankTitle1 = aRecv->RankTitle1;
}

void RecvGS::GetInfoRankTitle1(PMSG_QUAN_HAM_UPD * aRecv)
{
	//-----------------------------
	this->m_RankTitle2 = aRecv->RankTitle2;
}

void RecvGS::GetInfoRankTitle2(PMSG_TU_LUYEN_UPD * aRecv)
{
	//-----------------------------
	this->m_RankTitle3 = aRecv->RankTitle3;

}

void RecvGS::GetInfoRankTitle3(PMSG_MUA_VIP_UPD * aRecv)
{
	//-----------------------------
	this->m_RankTitle4 = aRecv->RankTitle4;
}
