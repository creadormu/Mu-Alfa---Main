#include "stdafx.h"
#include "ItemSmoke.h"
#include "Item.h"


cSmokeEffect gSmokeEffect;

cSmokeEffect::cSmokeEffect()
{
	this->m_CustomSmokeEffect.clear();
}

cSmokeEffect::~cSmokeEffect()
{
	
}

void cSmokeEffect::Load(CUSTOM_SMOKEEFFECT* info)
{
	for (int n = 0 ; n < MAX_SMOKE_ITEMS; n++)
	{
		if(info[n].Index < 0 || info[n].Index >= MAX_SMOKE_ITEMS)
		{
			return;
		}

		this->m_CustomSmokeEffect.insert(std::pair<int, CUSTOM_SMOKEEFFECT>(GET_ITEM_MODEL(11, info[n].ItemIndex),info[n]));
	}
}

int cSmokeEffect::getSmokeTRSData(int ItemIndex) // OK
{
	std::map<int, CUSTOM_SMOKEEFFECT>::iterator it = this->m_CustomSmokeEffect.find(ItemIndex);

	if(it != this->m_CustomSmokeEffect.end())
	{
		return it->second.ItemIndex;
	}

	return -1;
}

float cSmokeEffect::getRedColor(int ItemIndex)
{
	std::map<int, CUSTOM_SMOKEEFFECT>::iterator it = this->m_CustomSmokeEffect.find(ItemIndex);

	if(it != this->m_CustomSmokeEffect.end())
	{
		return it->second.Red;
	}

	return -1;
}

float cSmokeEffect::getGreenColor(int ItemIndex)
{
	std::map<int, CUSTOM_SMOKEEFFECT>::iterator it = this->m_CustomSmokeEffect.find(ItemIndex);

	if(it != this->m_CustomSmokeEffect.end())
	{
		return it->second.Green;
	}

	return -1;
}

float cSmokeEffect::getBlueColor(int ItemIndex)
{
	std::map<int, CUSTOM_SMOKEEFFECT>::iterator it = this->m_CustomSmokeEffect.find(ItemIndex);

	if(it != this->m_CustomSmokeEffect.end())
	{
		return it->second.Blue;
	}

	return -1;
}