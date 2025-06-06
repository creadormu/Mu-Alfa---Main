#include "stdafx.h"
#include "ChangeClass.h"
//#include "Interface.h"

cChangeClass gChangeClass;

cChangeClass::cChangeClass()
{
	this->m_Price = 0;
}

cChangeClass::~cChangeClass()
{
	
}

void cChangeClass::RecvData(PMSG_CHANGECLASS_DATA* Data)
{
	this->m_PriceType = Data->PriceType;
	this->m_Price = Data->Price;
}


void cChangeClass::SendChangeClass(int Type)
{
	CG_CHANGECLASS_SEND pRequest;
	pRequest.Head.set(0xF2,0x05,sizeof(pRequest));	
	pRequest.Type = Type;
	DataSend((BYTE*)&pRequest,pRequest.Head.size);
}
