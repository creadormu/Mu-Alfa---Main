#pragma once
#include "Protocol.h"
//======================================================
struct PMSG_RANKTITLE_UPD
{
	PSBMSG_HEAD	h;
	int	RankTitle1;

};

struct PMSG_QUAN_HAM_UPD
{
	PSBMSG_HEAD	h;
	int	RankTitle2;

};

struct PMSG_TU_LUYEN_UPD
{
	PSBMSG_HEAD	h;
	int	RankTitle3;

};

struct PMSG_MUA_VIP_UPD
{
	PSBMSG_HEAD	h;
	int	RankTitle4;

};


//======================================================
class RecvGS
{
public:
	RecvGS();
	~RecvGS();

	//-----------------------------
	void GetInfoRankTitle(PMSG_RANKTITLE_UPD * aRecv);
	int		m_RankTitle1;
	//-----------------------------

	void GetInfoRankTitle1(PMSG_QUAN_HAM_UPD * aRecv);
	int		m_RankTitle2;
	//-----------------------------

	void GetInfoRankTitle2(PMSG_TU_LUYEN_UPD * aRecv);
	int		m_RankTitle3;
	//-----------------------------

	void GetInfoRankTitle3(PMSG_MUA_VIP_UPD * aRecv);
	int		m_RankTitle4;
	//-----------------------------


}; extern RecvGS gRecvGS;
