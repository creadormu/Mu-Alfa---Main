#include "stdafx.h"
#include "CustomTinhNang.h"
#include "Protocol.h"

BUY_TINH_NANG gBUY_TINH_NANG;

BUY_TINH_NANG::BUY_TINH_NANG()
{
}
BUY_TINH_NANG::~BUY_TINH_NANG()
{
}
//---------------------------------------------------------
void BUY_TINH_NANG::BUY_DANH_HIEU(int Number)
{
	BUY_DANH_HIEU_REQ pMsg;
	pMsg.h.set(0xFC, 0x03, sizeof(pMsg));
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}
//---------------------------------------------------------


void BUY_TINH_NANG::BUY_QUAN_HAM(int Number)
{
	BUY_QUAN_HAM_REQ pMsg;
	pMsg.h.set(0xFC, 0x04, sizeof(pMsg)); 
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}
//---------------------------------------------------------


void BUY_TINH_NANG::BUY_TU_LUYEN(int Number)
{
	BUY_TU_LUYEN_REQ pMsg;
	pMsg.h.set(0xFC, 0x05, sizeof(pMsg));
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}
//---------------------------------------------------------

void BUY_TINH_NANG::BUY_MUA_VIP(int Number)
{
	BUY_TU_LUYEN_REQ pMsg;
	pMsg.h.set(0xFC, 0x06, sizeof(pMsg));
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}
//---------------------------------------------------------
