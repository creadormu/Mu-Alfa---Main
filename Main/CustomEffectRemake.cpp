#include "stdafx.h"
#include "CustomEffectRemake.h"
#include "Defines.h"

cCustomRemake gCustomRemake;

cCustomRemake::cCustomRemake() // OK
{
	this->Init();
}

cCustomRemake::~cCustomRemake() // OK
{

}

void cCustomRemake::Init() // OK
{
	for(int n=0;n < MAX_REMAKE_EFFECT;n++)
	{
		this->m_CustomRemake[n].Index = -1;
	}
}

void cCustomRemake::Load(REMAKE_EFFECT* info) // OK
{
	for(int n=0;n < MAX_REMAKE_EFFECT;n++)
	{
		this->SetInfo(info[n]);
		
	}
	
}

void cCustomRemake::SetInfo(REMAKE_EFFECT info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_REMAKE_EFFECT)
	{
		return;
	}

	this->m_CustomRemake[info.Index] = info;
}

REMAKE_EFFECT* cCustomRemake::GetInfo(int index) // OK
{
	if(index < 0 || index >= MAX_REMAKE_EFFECT)
	{
		return 0;
	}

	if(this->m_CustomRemake[index].Index != index)
	{
		return 0;
	}

	return &this->m_CustomRemake[index];
}

REMAKE_EFFECT* cCustomRemake::GetInfoByItem(int ItemIndex) // OK
{
	for(int n=0;n < MAX_REMAKE_EFFECT;n++)
	{
		REMAKE_EFFECT* lpInfo = this->GetInfo(n);

		if(lpInfo == 0)
		{
			continue;
		}

		if(ItemIndex == ITEM2(lpInfo->ItemType,lpInfo->ItemIndex))
		{
			return lpInfo;
		}
	}

	return 0;
}

bool cCustomRemake::CheckEffectRemake(int ItemIndex){

	for (int i=0;i<20; i++)
	{
		
		if (ItemIndex == ITEM2(m_CustomRemake[i].ItemType,m_CustomRemake[i].ItemIndex))
		{
			return true;
		}
	}
	return false;
}