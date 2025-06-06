#pragma once

#include "Protocol.h"

struct PMSG_WAREHOUSEINTERFACE_SEND
{
	PSBMSG_HEAD header;
	int Number;
};

class cWarehousePanel
{
public:
	cWarehousePanel();
	virtual ~cWarehousePanel();
	void CGSendWarehouseOpen(int Number);

}; extern cWarehousePanel gWarehousePanel;





