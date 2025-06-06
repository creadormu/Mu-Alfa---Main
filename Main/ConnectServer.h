#pragma once

#include "Protocol.h"

#define DelayGetServerList		10000
#define DelaySelfGetServerList  30000


//**********************************************//
//********** Client -> ConnectServer ***********//
//**********************************************//

struct PMSG_SERVER_INFO_RECV
{
	PSBMSG_HEAD header; // C1:F4:03
	BYTE ServerCode;
};

struct PMSG_SERVER_LIST_RECV
{
	PSBMSG_HEAD header; // C1:F4:06
};

//**********************************************//
//********** ConnectServer -> Client ***********//
//**********************************************//

struct PMSG_SERVER_INIT_SEND
{
	PBMSG_HEAD header; // C1:00
	BYTE result;
};

struct PMSG_SERVER_INFO_SEND
{
	PSBMSG_HEAD header; // C1:F4:03
	char ServerAddress[16];
	WORD ServerPort;
};

struct PMSG_SERVER_LIST_SEND
{
	PSWMSG_HEAD header; // C1:F4:06
	BYTE count[2];
};

struct PMSG_SERVER_LIST
{
	WORD ServerCode;
	BYTE UserTotal;
	BYTE type;
};



struct ServerListStat
{
	WORD ServerCode;
	BYTE UserTotal;
	BYTE type;
};

class cConnectServer
{
public:
	cConnectServer();
	~cConnectServer();
	void Load();

	void ServerInfoRecv(BYTE* a1, bool a2 = false);
	void ServerListRecv(BYTE* a1, bool a2 = false);
	void ReqServerInfo(WORD subcode);
	void ReqServerList(bool a1 = false);
	BYTE getServerType(WORD subcode);
	int server_list_count;
	WORD	currently_subcode;
	bool	ServerOnline;
	ServerListStat	SrvStat[50];
	DWORD lastGetSrvList;
private:

};extern cConnectServer ConnectServer;