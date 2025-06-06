#include "stdafx.h"
#include "PartySearch.h"
#include "User.h"
#include "Interface.h"
#include "PartySearchSettings.h"
#include "Defines.h"
#include "Offset.h"

cPartySearch gPartySearch;

cPartySearch::cPartySearch()
{
	this->ClearPartyList();
}

cPartySearch::~cPartySearch()
{
	
}

void cPartySearch::ClearPartyList()
{
	for (int i=0;i<MAX_PARTYLIST;i++)
	{
		this->gPartyList[i].Index = 0xFFFF;
		memset(&this->gPartyList[i].Name, 0, sizeof(this->gPartyList[i].Name));
		this->gPartyList[i].Map = -1;
		this->gPartyList[i].X = -1;
		this->gPartyList[i].Y = -1;
		this->gPartyList[i].Count = -1;
		this->gPartyList[i].ButtonActive = true;
	}

	this->Page = 0;
	this->CountPages = 0;
	this->ListsCount = 0;
}


void cPartySearch::InsertPartyList(PMSG_PARTYSEARCH_PARTYLIST* lpInfo)
{
	////console.Log("", "Map = %s X = %d Y = %d", pGetMapName(lpInfo->Map), lpInfo->X, lpInfo->Y);
	memcpy(this->gPartyList[this->ListsCount].Name, lpInfo->Name, sizeof(this->gPartyList[this->ListsCount].Name));
	this->gPartyList[this->ListsCount].Map = lpInfo->Map;
	this->gPartyList[this->ListsCount].X = lpInfo->X;
	this->gPartyList[this->ListsCount].Y = lpInfo->Y;
	this->gPartyList[this->ListsCount].Level = lpInfo->Level;
	this->gPartyList[this->ListsCount].DarkWizard = lpInfo->DarkWizard;
	this->gPartyList[this->ListsCount].DarkKnight = lpInfo->DarkKnight;
	this->gPartyList[this->ListsCount].Elf = lpInfo->Elf;
	this->gPartyList[this->ListsCount].MagicGladiator = lpInfo->MagicGladiator;
	this->gPartyList[this->ListsCount].DarkLord = lpInfo->DarkLord;
	this->gPartyList[this->ListsCount].Summoner = lpInfo->Summoner;
	this->gPartyList[this->ListsCount].RageFighter = lpInfo->RageFighter;
	this->gPartyList[this->ListsCount].OnlyGuild = lpInfo->OnlyGuild;
	this->gPartyList[this->ListsCount].IsSameGuild = lpInfo->IsSameGuild;
	this->gPartyList[this->ListsCount].Count = lpInfo->Count;
	this->gPartyList[this->ListsCount].Index = this->ListsCount;
	this->ListsCount++;


	//for (int i=0;i<this->ListsCount;i++)
	//{
		////console.Log("", "Name = %s",this->gPartyList[i].Name);
	//}
}

PARTYLIST* cPartySearch::GetPartyList(int index)
{
	if (this->gPartyList[index].Index == 0xFFFF)
	{
		return 0;
	}

	this->CountPages = ((this->ListsCount-1)/10)+1;

	if (this->CountPages <= 0)
	{
		this->CountPages = 1;
	}

	for (int i=0; i<this->ListsCount;i++)
	{
		if(strcmp(this->gPartyList[i].Name,gObjUser.lpPlayer->Name) == 0)
		{
			gPartySearchSettings.m_SystemActive = true;
			break;
		}
	}

	switch (gObjUser.lpPlayer->Class & 7)
	{
		case 0:
			{
				if (this->gPartyList[index].DarkWizard == false)
				{
					this->gPartyList[index].ButtonActive = false;
				}
			}
			break;
		case 1:
			{
				if (this->gPartyList[index].DarkKnight == false)
				{
					this->gPartyList[index].ButtonActive = false;
				}
			}
			break;
		case 2:
			{
				if (this->gPartyList[index].Elf == false)
				{
					this->gPartyList[index].ButtonActive = false;
				}
			}
			break;
		case 3:
			{
				if (this->gPartyList[index].MagicGladiator == false)
				{
					this->gPartyList[index].ButtonActive = false;
				}
			}
			break;
		case 4:
			{
				if (this->gPartyList[index].DarkLord == false)
				{
					this->gPartyList[index].ButtonActive = false;
				}
			}
			break;
		case 5:
			{
				if (this->gPartyList[index].Summoner == false)
				{
					this->gPartyList[index].ButtonActive = false;
				}
			}
			break;
		case 6:
			{
				if (this->gPartyList[index].RageFighter == false)
				{
					this->gPartyList[index].ButtonActive = false;
				}
			}
			break;
	}

	if (gPartyList[index].OnlyGuild == true && gPartyList[index].IsSameGuild == false)
	{
		this->gPartyList[index].ButtonActive = false;
	}

	if (gPartyList[index].Count >= 5)
	{
		gPartyList[index].ButtonActive = false;
	}

	if (*(DWORD*)(MAIN_PARTY_MEMBER_COUNT) > 0)
	{
		gPartyList[index].ButtonActive = false;
	}

	if (gObjUser.lpPlayer->Level > gPartyList[index].Level)
	{
		gPartyList[index].ButtonActive = false;
	}

	if (gPartySearchSettings.m_SystemActive == true)
	{
		gPartyList[index].ButtonActive = false;
	}

	return &this->gPartyList[index];
}

void cPartySearch::SendPartyRequest(int index)
{
	PARTYLIST* info = gPartySearch.GetPartyList(index);

	if (info == 0)
	{
		return;
	}

	PMSG_PARTY_REQ_SEND pMsg;

	pMsg.header.set(0xF3,0xF2,sizeof(pMsg));

	memcpy(pMsg.Name, info->Name, sizeof(pMsg.Name));

	DataSend((BYTE*)&pMsg,pMsg.header.size);
}
