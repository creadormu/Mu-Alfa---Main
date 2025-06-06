#pragma once
#include "Protocol.h"

struct PMSG_SEND_PARTYSEARCH_ADD
{
	PSBMSG_HEAD header;
	bool SystemActive;
	bool OnlyGuild;
	bool OneClass;
	bool DarkWizard;
	bool DarkKnight;
	bool Elf;
	bool MagicGladiator;
	bool DarkLord;
	bool Summoner;
	bool RageFighter;
	int Level;
};

struct PMSG_PARTYSETTINGS_RECV
{
	PSBMSG_HEAD header;
	bool SystemActive;
	bool OnlyGuild;
	bool OneClass;
	bool DarkWizard;
	bool DarkKnight;
	bool Elf;
	bool MagicGladiator;
	bool DarkLord;
	bool Summoner;
	bool RageFighter;
	int Level;
};

class cPartySearchSettings
{
public:
	cPartySearchSettings();
	virtual ~cPartySearchSettings();
	void ChangeClassValue(int Class);
	void SetClassValue(int Class, int Value);
	void CGSendPartySearchAdd();
	void GCPartySettingsRecv(PMSG_PARTYSETTINGS_RECV* lpMsg);
	// ----
	bool m_SystemActive;
	bool m_OnlyGuild;
	bool m_OneClass;
	bool m_DarkWizard;
	bool m_DarkKnight;
	bool m_Elf;
	bool m_MagicGladiator;
	bool m_DarkLord;
	bool m_Summoner;
	bool m_RageFighter;
	int m_Level;
}; extern cPartySearchSettings gPartySearchSettings;