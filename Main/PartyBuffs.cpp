#include "stdafx.h"
#include "PartyBuffs.h"
#include "Offset.h"
#include "Import.h"
#include "Object.h"
#include "Interface.h"
#include "User.h"
#include <string>

cPartyBuffs gPartyBuffs;

cPartyBuffs::cPartyBuffs()
{
	this->m_PartyBuffsData.clear();
}

cPartyBuffs::~cPartyBuffs()
{
	
}

void cPartyBuffs::RecvPartyBuffs(PMSG_PARTY_EFFECT_LIST_SEND* lpMsg)
{
	PARTY_BUFFS_DATA info;

	memcpy(info.name,lpMsg->name,sizeof(info.name));

	info.count = lpMsg->count;

	for(int n=0;n<lpMsg->count;n++)
	{
		PMSG_PARTY_EFFECT_LIST* lpInfo = (PMSG_PARTY_EFFECT_LIST*)(((BYTE*)lpMsg)+sizeof(PMSG_PARTY_EFFECT_LIST_SEND)+(sizeof(PMSG_PARTY_EFFECT_LIST)*n));

		info.Buffs[n].effect = lpInfo->effect;
		info.Buffs[n].count = lpInfo->count;
	}

	std::string Name(lpMsg->name);

	std::map<std::string,PARTY_BUFFS_DATA>::iterator it = this->m_PartyBuffsData.find(Name);

	if(it == this->m_PartyBuffsData.end())
	{
		this->m_PartyBuffsData.insert(std::pair<std::string,PARTY_BUFFS_DATA>(Name,info));
	}
	else
	{
		it->second = info;
	}
}

PARTY_BUFFS_DATA* cPartyBuffs::GetInfoByName(char* Name)
{
	std::map<std::string, PARTY_BUFFS_DATA>::iterator it = this->m_PartyBuffsData.find(Name);

	if(it != this->m_PartyBuffsData.end())
	{
		return &it->second;
	}

	return 0;
}

void cPartyBuffs::DrawPartyBuffs(float StartX, float StartY, char* MemberName)
{
	std::map<std::string, PARTY_BUFFS_DATA>::iterator it = this->m_PartyBuffsData.find(MemberName);

	if(it != this->m_PartyBuffsData.end())
	{
		float Height = (float)(( 28.0f / 100) * 37.5); // ((double)(unsigned int)*(QWORD*)0x0E61E5C / 480.0); //28
		float Width = (float)(( 20.0f / 100) * 37.5); // ((double)(unsigned int)*(QWORD*)0xE61E58 / 640.0); //20
		float RenderW = (float)(( 256.0f / 100) * 37.5); // ((double)(unsigned int)*(QWORD*)0xE61E58 / 640.0);

		float X = StartX;

		for	( int n = 0 ; n < it->second.count ; n++ )
		{
			if(n > 9)
			{
				X= (double) ( StartX - ( Width * (n - 9)) );
			}
			else
			{
				X= (double) ( StartX + ( Width * n) );
			}

			int EffectValue = (it->second.Buffs[n].effect - 1) % 80;
			float SourceX = (double)(EffectValue % 10) * Width / RenderW;
			float SourceY = (double)(EffectValue / 10) * Height / RenderW;
			float SourceWidth = Width / RenderW;
			float SourceHeight = Height / RenderW;
			RenderBitmap((it->second.Buffs[n].effect - 1) / 80 + 31725, X, StartY, Width, Height, SourceX, SourceY, SourceWidth, SourceHeight, 1, 1, 0);
		}
	}
}