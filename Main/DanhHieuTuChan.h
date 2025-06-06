#pragma once
#include "Protocol.h"

struct ACTIVE_TITLE_REQ
{
	PSBMSG_HEAD h;
	int			Type;
	int			Number;
};

struct BUY_TITLE_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};

struct PMSG_HORNOR_UPD
{
	PSBMSG_HEAD	h;
	int		Title2;
	int		Title3;
	int		Title4;
	int		Title5;
	int		Title6;
	int		VipRank;
};

class DanhHieu
{
public:
	DanhHieu();
	~DanhHieu();
	//void Active(int Type, int Number);
	//void BuyTitle(int Number);
	void GetInfo(PMSG_HORNOR_UPD * aRecv);
	//
	int		m_Slot2;
	int		m_Slot3;
	int		m_Slot4;
	int		m_Slot5;
	int		m_Slot6;
	int		m_VipRank;
	//
}; extern DanhHieu gDanhHieu;
