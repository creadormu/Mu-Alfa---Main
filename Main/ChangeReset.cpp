#include "stdafx.h"
#include "ChangeReset.h"

cChangeReset gChangeReset;

cChangeReset::cChangeReset()
{

}

cChangeReset::~cChangeReset()
{
	
}

void cChangeReset::SendChangeReset(int Type)
{
	CG_CHANGE_RESET_SEND pRequest;
	pRequest.Head.set(0xF2,0x06,sizeof(pRequest));
	pRequest.Type = Type;
	DataSend((BYTE*)&pRequest,pRequest.Head.size);
}
