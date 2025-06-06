#pragma once
#include "Protocol.h"

struct BUY_DANH_HIEU_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};


struct BUY_QUAN_HAM_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};


struct BUY_TU_LUYEN_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};

struct BUY_MUA_VIP_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};

class BUY_TINH_NANG
{
public:
	BUY_TINH_NANG();
	~BUY_TINH_NANG();
	//------------------------------------
	void BUY_DANH_HIEU(int Number);
	void BUY_QUAN_HAM(int Number);
	void BUY_TU_LUYEN(int Number);
	void BUY_MUA_VIP(int Number);

	//--------------------------------------
}; extern BUY_TINH_NANG gBUY_TINH_NANG;
