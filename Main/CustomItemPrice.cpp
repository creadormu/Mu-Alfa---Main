#include "stdafx.h"
#include "CustomItemPrice.h"

CItemValue gItemValue;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CItemValue::CItemValue() // OK
{
	this->Init();
}

CItemValue::~CItemValue() // OK
{

}

void CItemValue::Init() // OK
{
	for(int n=0;n < MAX_ITEM_VALUE;n++)
	{
		this->m_ItemValueInfo[n].Index = -1;
	}
}

void CItemValue::Load(ITEM_VALUE_INFO* info) // OK
{
	for(int n=0;n < MAX_ITEM_VALUE;n++)
	{
		this->SetInfo(info[n]);
	}
}

void CItemValue::SetInfo(ITEM_VALUE_INFO info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_ITEM_VALUE)
	{
		return;
	}

	this->m_ItemValueInfo[info.Index] = info;
}

ITEM_VALUE_INFO* CItemValue::GetInfo(int index) // OK
{
	if(index < 0 || index >= MAX_ITEM_VALUE)
	{
		return 0;
	}

	if(this->m_ItemValueInfo[index].Index != index)
	{
		return 0;
	}

	return &this->m_ItemValueInfo[index];
}

ITEM_VALUE_INFO* CItemValue::GetInfoByItem(int ItemIndex) // OK
{
	for(int n=0;n < MAX_ITEM_VALUE;n++)
	{
		ITEM_VALUE_INFO* lpInfo = this->GetInfo(n);

		if(lpInfo == 0)
		{
			continue;
		}

		if(lpInfo->ItemIndex == ItemIndex)
		{
			return lpInfo;
		}
	}
	return 0;
}

bool CItemValue::isItemShopValue(int ItemIndex) // OK
{
	for (int i=0;i<MAX_ITEM_VALUE; i++)
	{
		if (ItemIndex == this->m_ItemValueInfo[i].ItemIndex)
		{
			return true;
		}
	}
	return false;
}
