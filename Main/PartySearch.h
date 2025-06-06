#pragma once

#include "Protocol.h"

#define MAX_PARTYLIST 100

struct PARTYLIST
{
	int Index;
	char Name[11];
	int Map;
	int X;
	int Y;
	int Level;
	bool DarkWizard;
	bool DarkKnight;
	bool Elf;
	bool MagicGladiator;
	bool DarkLord;
	bool Summoner;
	bool RageFighter;
	bool OnlyGuild;
	bool IsSameGuild;
	int Count;
	bool ButtonActive;
};

struct PMSG_PARTY_REQ_SEND
{
	PSBMSG_HEAD header;
	char Name[11];
};

class cPartySearch
{
public:
	cPartySearch();
	~cPartySearch();
	void ClearPartyList();
	void InsertPartyList(PMSG_PARTYSEARCH_PARTYLIST* lpInfo);
	PARTYLIST* GetPartyList(int index);
	void SendPartyRequest(int index);
	// ----
	PARTYLIST gPartyList[MAX_PARTYLIST];
	int ListsCount;
	int Page;
	int CountPages;
	// ----
}; extern cPartySearch gPartySearch;