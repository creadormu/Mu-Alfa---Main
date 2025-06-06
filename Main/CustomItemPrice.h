// CustomItem.h: interface for the CCustomItem class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#define MAX_ITEM_VALUE 1000

struct ITEM_VALUE_INFO
{
	int	Index;
	int	ItemIndex;
	int	Level;
	int	OpcExc;
	int	Zen;
	int	Coin1;
	int	Coin2;
	int	Coin3;
	int	Sell;
};


class CItemValue
{
public:
	CItemValue();
	virtual ~CItemValue();
	void Init();
	void Load(ITEM_VALUE_INFO* info);
	void SetInfo(ITEM_VALUE_INFO info);
	ITEM_VALUE_INFO* GetInfo(int index);
	ITEM_VALUE_INFO* GetInfoByItem(int ItemIndex);
	bool isItemShopValue(int ItemIndex);
public:
	ITEM_VALUE_INFO m_ItemValueInfo[MAX_ITEM_VALUE];
};

extern CItemValue gItemValue;