#include "stdafx.h"
#include "SmithItem.h"
#include "Protocol.h"

cSmithItem gSmithItem;

cSmithItem::cSmithItem()
{
	this->ItemType = 0;
	this->ItemIndex = 0;
	this->Days	= 0;
	this->mLevel = 0;
	this->mSkill = 0;
	this->mLuck = 0;
	this->mOpt = 0;
	this->ExcOption = 0;
	this->ExcOption1 = 0;
	this->ExcOption2 = 0;
	this->ExcOption3 = 0;
	this->ExcOption4 = 0;
	this->ExcOption5 = 0;
	this->mExc = 0;
	this->TotalPrice = 0;
}
// -------------------------------------------------------------------------------

cSmithItem::~cSmithItem()
{
	// ----
}

void cSmithItem::GetInfo(SDHP_SENDSVSHOP * lpMsg)
{
	this->MaxLevel	=	lpMsg->MaxLevel;
	this->MaxSkill	=	lpMsg->MaxSkill;
	this->MaxLuck	=	lpMsg->MaxLuck;
	this->MaxOpt	=	lpMsg->MaxOpt;
	this->MaxExc	=	lpMsg->MaxExc;
	//Get Price
	this->pLevel	=	lpMsg->pLevel;
	this->pSkill	=	lpMsg->pSkill;
	this->pLuck		=	lpMsg->pLuck;
	this->pOpt		=	lpMsg->pOpt;
	this->pExc	=	lpMsg->pExc;
	this->pExc1	=	lpMsg->pExc1;
	this->pExc2	=	lpMsg->pExc2;
	this->pExc3	=	lpMsg->pExc3;
	this->pExc4	=	lpMsg->pExc4;
	this->pExc5	=	lpMsg->pExc5;
	this->TotalPrice = lpMsg->TotalPrice;
}
