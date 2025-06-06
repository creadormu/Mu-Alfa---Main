// CustomItem.cpp: implementation of the CCustomItem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CustomItem.h"
#include "CustomWing.h"
#include "CustomGloves.h"
#include "CustomBow.h"


CCustomItem gCustomItem;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCustomItem::CCustomItem() // OK
{
	this->m_CustomItemInfo.clear();
	//this->Init();
}

CCustomItem::~CCustomItem() // OK
{

}

void CCustomItem::Load(CUSTOM_ITEM_INFO* info) // OK
{
	for(int n=0;n < MAX_CUSTOM_ITEM;n++)
	{
		if(info[n].Index < 0 || info[n].Index >= MAX_CUSTOM_ITEM)
		{
			return;
		}
		this->m_CustomItemInfo.insert(std::pair<int,CUSTOM_ITEM_INFO>(info[n].ItemIndex,info[n]));
	}
}

int CCustomItem::IsCustomItem(int ItemIndex)
{
	if( ItemIndex >= 3584 && ItemIndex < 4096 )
	{
		std::map<int,CUSTOM_ITEM_INFO>::iterator it = this->m_CustomItemInfo.find(ItemIndex);

		if(it != this->m_CustomItemInfo.end())
		{
			return 1;
		}
	}
	return 0;
}

CUSTOM_ITEM_INFO* CCustomItem::GetInfoByItem(int ItemIndex) // OK
{
	CUSTOM_ITEM_INFO* value;

	std::map<int,CUSTOM_ITEM_INFO>::iterator it = this->m_CustomItemInfo.find(ItemIndex);

	if(it != this->m_CustomItemInfo.end())
	{
		(*value) = it->second;
		return value;
	}
	return 0;
}

BOOL CCustomItem::GetCustomItemColor(int ItemIndex,float* ItemColor) // OK
{
	std::map<int,CUSTOM_ITEM_INFO>::iterator it1 = this->m_CustomItemInfo.find(ItemIndex);
	
	std::map<int,CUSTOM_BOW_INFO>::iterator it2 = gCustomBow.m_CustomBowInfo.find(ItemIndex);

	if(it1 != this->m_CustomItemInfo.end())
	{
		ItemColor[0] = (float)(it1->second.ColorR/255.0f);
		ItemColor[1] = (float)(it1->second.ColorG/255.0f);
		ItemColor[2] = (float)(it1->second.ColorB/255.0f);
		return 1;
	}
	else if(it2 != gCustomBow.m_CustomBowInfo.end())
	{
		ItemColor[0] = (float)(it2->second.ColorR/255.0f);
		ItemColor[1] = (float)(it2->second.ColorG/255.0f);
		ItemColor[2] = (float)(it2->second.ColorB/255.0f);
		return 1;
	}
	else
	{
		for(std::map<int, CUSTOM_RF_GLOVES>::iterator it = gCustomBattleGloves.m_CustomGlovesInfo.begin(); it != gCustomBattleGloves.m_CustomGlovesInfo.end(); it++)
		{
			if(it->second.ItemIndex == ItemIndex)
			{
				ItemColor[0] = (float)(it->second.ColorR/255.0f);
				ItemColor[1] = (float)(it->second.ColorG/255.0f);
				ItemColor[2] = (float)(it->second.ColorB/255.0f);
				return 1;
			}
			else if(it->second.TextureLeftIndex == ItemIndex)
			{
				ItemColor[0] = (float)(it->second.ColorR/255.0f);
				ItemColor[1] = (float)(it->second.ColorG/255.0f);
				ItemColor[2] = (float)(it->second.ColorB/255.0f);
				return 1;
			}
			else if(it->second.TextureRightIndex == ItemIndex)
			{
				ItemColor[0] = (float)(it->second.ColorR/255.0f);
				ItemColor[1] = (float)(it->second.ColorG/255.0f);
				ItemColor[2] = (float)(it->second.ColorB/255.0f);
				return 1;
			}
		}
	}
	return 0;
}
