#include "stdafx.h"
#include "PartySearchSettings.h"

cPartySearchSettings gPartySearchSettings;

cPartySearchSettings::cPartySearchSettings()
{
	this->m_SystemActive = false;
	this->m_OnlyGuild = false;
	this->m_OneClass = false;
	this->m_DarkWizard = false;
	this->m_DarkKnight = false;
	this->m_Elf = false;
	this->m_MagicGladiator = true;
	this->m_DarkLord = false;
	this->m_Summoner = false;
	this->m_RageFighter = false;
	this->m_Level = 400;
}

cPartySearchSettings::~cPartySearchSettings()
{
	
}

void cPartySearchSettings::ChangeClassValue(int ClassType)
{
	switch (ClassType)
	{
		case 0:
			this->m_DarkWizard ^= 1;
			break;
		case 1:
			this->m_DarkKnight ^= 1;
			break;
		case 2:
			this->m_Elf ^= 1;
			break;
		case 3:
			this->m_MagicGladiator ^= 1;
			break;
		case 4:
			this->m_DarkLord ^= 1;
			break;
		case 5:
			this->m_Summoner ^= 1;
			break;
		case 6:
			this->m_RageFighter ^= 1;
			break;
	}
}

void cPartySearchSettings::SetClassValue(int Class, int Value)
{
	switch (Class)
	{
		case 0:
			this->m_DarkWizard = Value;
			break;
		case 1:
			this->m_DarkKnight = Value;
			break;
		case 2:
			this->m_Elf = Value;
			break;
		case 3:
			this->m_MagicGladiator = Value;
			break;
		case 4:
			this->m_DarkLord = Value;
			break;
		case 5:
			this->m_Summoner = Value;
			break;
		case 6:
			this->m_RageFighter = Value;
			break;
	}
}


void cPartySearchSettings::CGSendPartySearchAdd()
{
	PMSG_SEND_PARTYSEARCH_ADD pMsg;
	pMsg.header.set(0xF3, 0xF1, sizeof(pMsg));

	pMsg.SystemActive = this->m_SystemActive;
	pMsg.OnlyGuild = this->m_OnlyGuild;
	pMsg.OneClass = this->m_OneClass;
	pMsg.DarkWizard = this->m_DarkWizard;
	pMsg.DarkKnight = this->m_DarkKnight;
	pMsg.Elf = this->m_Elf;
	pMsg.MagicGladiator = this->m_MagicGladiator;
	pMsg.DarkLord = this->m_DarkLord;
	pMsg.Summoner = this->m_Summoner;
	pMsg.RageFighter = this->m_RageFighter;
	pMsg.Level = this->m_Level;

	DataSend((BYTE*)&pMsg,pMsg.header.size);
}

void cPartySearchSettings::GCPartySettingsRecv(PMSG_PARTYSETTINGS_RECV* lpMsg)
{
	this->m_SystemActive = lpMsg->SystemActive;

	this->m_OnlyGuild = lpMsg->OnlyGuild;

	this->m_OneClass = lpMsg->OneClass;

	this->m_Level = lpMsg->Level;

	this->m_DarkWizard = lpMsg->DarkWizard;

	this->m_DarkKnight = lpMsg->DarkKnight;

	this->m_Elf = lpMsg->Elf;

	this->m_MagicGladiator = lpMsg->MagicGladiator;

	this->m_DarkLord = lpMsg->DarkLord;

	this->m_Summoner = lpMsg->Summoner;

	this->m_RageFighter = lpMsg->RageFighter;
}
