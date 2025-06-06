#include "stdafx.h"
#include "Defines.h"
#include "ItemManager.h"
#include "InfoLog.h"

CItemManager gItemManager;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CItemManager::CItemManager() // OK
{
	this->m_ItemInfo.clear();
}

CItemManager::~CItemManager() // OK
{

}

void CItemManager::Load(ITEM_INFO* info) // OK
{
	for(int n=0;n < MAX_ITEM2;n++)
	{
		if(info[n].Index < 0 || info[n].Index >= MAX_ITEM2)
		{
			return;
		}
		this->m_ItemInfo.insert(std::pair<int,ITEM_INFO>(info[n].ItemIndex,info[n]));
	}
}