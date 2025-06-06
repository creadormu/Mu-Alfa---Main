#pragma once
#include "Protocol.h"

struct SDHP_SENDSVSHOP
{
	PSBMSG_HEAD h;	// C1:01
	BYTE MaxLevel;
	BYTE MaxSkill;
	BYTE MaxLuck;
	BYTE MaxOpt;
	BYTE MaxExc;
	int pLevel;
	int pSkill;
	int pLuck;
	int pOpt;
	int pExc;
	int	pExc1;
	int	pExc2;
	int	pExc3;
	int	pExc4;
	int	pExc5;
	int TotalPrice;
};

struct SDHP_BUYSVSHOP
{
	PSBMSG_HEAD h;	// C1:01
	int	ItemType;
	int ItemIndex;
	BYTE mLevel;
	BYTE mSkill;
	BYTE mLuck;
	BYTE mOpt;
	BYTE mExc;
	BYTE ExcOption;
	BYTE ExcOption1;
	BYTE ExcOption2;
	BYTE ExcOption3;
	BYTE ExcOption4;
	BYTE ExcOption5;
	BYTE Days;
};


class cSmithItem
{
public:
	cSmithItem();
	~cSmithItem();
	void GetInfo(SDHP_SENDSVSHOP * lpMsg);
	//
	int	ItemType;
	int ItemIndex;
	BYTE mLevel;
	BYTE mSkill;
	BYTE mLuck;
	BYTE mOpt;
	BYTE mExc;
	BYTE ExcOption;
	BYTE ExcOption1;
	BYTE ExcOption2;
	BYTE ExcOption3;
	BYTE ExcOption4;
	BYTE ExcOption5;
	BYTE Days;
	// GetInfo
	BYTE MaxLevel;
	BYTE MaxSkill;
	BYTE MaxLuck;
	BYTE MaxOpt;
	BYTE MaxExc;
	int pLevel;
	int pSkill;
	int pLuck;
	int pOpt;
	int pExc;
	int	pExc1;
	int	pExc2;
	int	pExc3;
	int	pExc4;
	int	pExc5;
	//
	int	TotalPrice;
}; extern cSmithItem gSmithItem;
