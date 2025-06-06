#include "stdafx.h"
#include "MultiWare.h"
#include "Interface.h"
#include "User.h"
#include "PrintPlayer.h"

cWarehousePanel gWarehousePanel;

cWarehousePanel::cWarehousePanel()
{

}

cWarehousePanel::~cWarehousePanel()
{
	
}

void cWarehousePanel::CGSendWarehouseOpen(int Number)
{
	PMSG_WAREHOUSEINTERFACE_SEND pMsg;
	pMsg.header.set(0xF2,0x0B,sizeof(pMsg));
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg,pMsg.header.size);
}
