#pragma once

#include "Protocol.h"

enum eChangeReset
{
	CHANGE_RESET_5 = 0,
	CHANGE_RESET_10 = 1,
	CHANGE_RESET_15 = 2,
	CHANGE_RESET_20 = 3,
	CHANGE_RESET_25 = 4,
};

struct CG_CHANGE_RESET_SEND
{
	PSBMSG_HEAD Head;
	int Type;
};

class cChangeReset
{
public:
	cChangeReset();
	virtual ~cChangeReset();
	void SendChangeReset(int Type);
private:
}; extern cChangeReset gChangeReset;