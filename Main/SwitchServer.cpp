#include "stdafx.h"
#include "Protocol.h"
#include "SwitchServer.h"
//#include "CNewUIWindowsClient.h"
//#include "CNewUIMacro.h"

cSwitchServer SwitchServer;

cSwitchServer::cSwitchServer()
{
}

cSwitchServer::~cSwitchServer()
{
}

void cSwitchServer::switchServer(WORD subcode){
	ECCG_SWITCHSERVER_REQ pMsg;
	pMsg.header.set(0xBF, 0xFF, sizeof(pMsg));
	pMsg.subcode = subcode;
	DataSend((BYTE*)&pMsg, pMsg.header.size);
}
