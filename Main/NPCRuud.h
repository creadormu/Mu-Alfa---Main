#pragma once
#include "Protocol.h"

#define MAX_RUUDTOKENSELL_INFO		25
#define CursorPress					*(BYTE*)0x8793386

struct PMSG_ITEMRUUD_LIST_RECV
{
	PBMSG_HEAD header; // C1:42
	BYTE result;
	BYTE count;
};

struct PMSG_BUY_ITEMRUUD_SEND
{
	PBMSG_HEAD header; // EE:30
	BYTE PAGE;
	BYTE SLOT;
};

struct _tagRuudTokenSell
{
	BYTE byItemType;
	WORD wItemIndex;
	BYTE shPageShop;
	BYTE wSlotIndex;
	WORD dwRuudCount;
};

class cRenderRuud
{
public:
	cRenderRuud(); 
	virtual ~cRenderRuud();
	int CheckTimer;
	int Coordenada[3];
	bool OpeningRuud;
	bool OpenWindowConfirm;
	int JCSlot;
	int JCPage;
	void OpenRuud();
	void ClosedRuud();
	void CheckOpen();
	DWORD TimerEvent;
	bool EventPressButton(int x, int y, int w, int h);
public:
	void WindowConfirm(int Page, int Slot);
	void ClearRuudInfo();
	void InsertRuudInfo(_tagRuudTokenSell* lpInfo);
	void LoadRuudShop_Recv(PMSG_ITEMRUUD_LIST_RECV * lpMsg);
	void OpenRuudShop_Recv(PMSG_NPC_TALK_RECV * lpMsg);
	_tagRuudTokenSell * JCGetInfoRuud(int Page, int Slot);
public:
	int Enter;
	int Page;
	//
	int Slot;
	
	_tagRuudTokenSell m_RuudInfo[MAX_RUUDTOKENSELL_INFO];
};

extern cRenderRuud jCRenderRuud;