#include "stdafx.h"
#include "DanhHieuTuChan.h"
#include "Protocol.h"

DanhHieu gDanhHieu;

DanhHieu::DanhHieu()
{
}
// -------------------------------------------------------------------------------

DanhHieu::~DanhHieu()
{
	// ----
}


void DanhHieu::GetInfo(PMSG_HORNOR_UPD * aRecv)
{
	this->m_Slot2 = aRecv->Title2;
	this->m_Slot3 = aRecv->Title3;
	this->m_Slot4 = aRecv->Title4;
	this->m_Slot5 = aRecv->Title5;
	this->m_Slot6 = aRecv->Title6;
	this->m_VipRank = aRecv->VipRank;
}