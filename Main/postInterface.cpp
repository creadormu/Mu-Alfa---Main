#include "stdafx.h"
#include "Common.h"
#include "Import.h"
#include "postInterface.h"
#include "TMemory.h"
#include "Defines.h"
#include "Protect.h"
#include "Protocol.h"
#include "Util.h"
#include "array.h"
#include "PrintPlayer.h"
#include "User.h"
#include "Offset.h"
#include "Interface.h"
#include "StatsAdvance.h"

newInterface gPostInterface;

void newInterface::Load()
{
	//SetCompleteHook
	SetOp((LPVOID)oDrawInterface2_Call, this->Work2, ASM::CALL);
	this->item_post_ = nullptr;
}


void newInterface::Work2()
{
	/*if(gProtect.m_MainInfo.DisableAdvance == 0)
	{
		g_StatsAdvance.DrawInfo();
	}*/

	if(gProtect.m_MainInfo.MonitorMS == 1||gProtect.m_MainInfo.MonitorFPS == 1)
	{
		gInterface.guiMonitore();
	}

	if(gProtect.m_MainInfo.MonitorFPS == 1)
	{
		gInterface.UPDATE_FPS();
	}

	if(gProtect.m_MainInfo.MonitorMS == 1)
	{
		gInterface.SendPingRecv();
	}

	if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		if( gProtect.m_MainInfo.CustomRemoveCoord == 0 )
		{
			gInterface.DrawCoord();
		}
	}

	pDrawInterface2();
}
//----------
void newInterface::DrawItemIMG(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse) // code hien thi item
{
	float x = PosX;
	float y = PosY;

	if(ItemID >= ITEM(0,0) && ItemID < ITEM(1,0))
	{
		x = PosX - 5;
		if(ItemID == ITEM(0,16) || ItemID == ITEM(0,19)) { y = PosY + 30; }
		else if((ItemID >= ITEM(0,32) && ItemID <= ITEM(0,35)) || gCustomBattleGloves.CheckGloves(ItemID) == true) { y = PosY + 15; }
		else if(ItemID >= ITEM(0,15) && ItemID < ITEM(0,32)) { y = PosY + 25; }
		else if(ItemID > ITEM(0,35)) { y = PosY + 20; }
		else if(ItemID == ITEM(0,0)) { y = PosY + 30; }
		else { y = PosY + 20; }
	}
	else if(ItemID >= ITEM(3,0) && ItemID < ITEM(4,0))
	{ y = PosY + 30; }
	else if(ItemID >= ITEM(7,0) && ItemID < ITEM(8,0)) { y = PosY + 25; }
	else if(ItemID >= ITEM(8,0) && ItemID < ITEM(9,0))
	{
		if((ItemID >= ITEM(8,2) && ItemID <= ITEM(8,4)) 
			|| ItemID == ITEM(8,7) || ItemID == ITEM(8,8)
			|| ItemID == ITEM(8,15))
		{
			y = PosY + 20;
		}
		else if(ItemID == ITEM(8,34) || ItemID == ITEM(8,35)) { y = PosY + 25; }
		else if(ItemID <= ITEM(8,73)) { y = PosY + 25; }
		else if(ItemID > ITEM(8,73)) { y = PosY + 35;}
	}
	else if(ItemID >= ITEM(9,0) && ItemID < ITEM(12,0)){ y = PosY + 25; }
	else if(ItemID >= 2048)
	{
		y = PosY + 25;

		if(ItemID ==ITEM(12,40)) { y = PosY + 10; }
	}
	else { y = PosY + 20; }

	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	sub_6363D0_Addr( 0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y );
	float v2 = *(float*) MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;

	sub_6358A0_Addr( 1.0, v2, *(float*)0xE61E38, *(float*)0xE61E3C );
	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();
	sub_635830_Addr((LPVOID) 0x87933A0);
	sub_635DE0_Addr();
	sub_635E40_Addr();
	pDrawItemModel(x, y, Width, Height, ItemID, Level, Excl, Anc, OnMouse); 
	glMatrixMode(0x1700u);
	glPopMatrix();
	glMatrixMode(0x1701u);
	glPopMatrix();
	glColor4f((GLfloat) 1.0, (GLfloat) 1.0, (GLfloat) 1.0,(GLfloat) 1.0);
	pSetBlend(false);
}

void newInterface::DrawChat ( int mode, char* character, char* message ) 
{
	PBMSG_CHATPOSTITEM chat;
	memset ( &chat.character_[0], 0, 10 );
	memset ( &chat.message_[0], 0, 89 );
	memcpy ( &chat.character_[0], &character[0], 10 );
	memcpy ( &chat.message_[0], &message[0], strlen ( message ) );
	pHandlePacketChatData ( &chat );
	if (mode >= 1 && mode <= 9 && ChatBoxMuObjectChatDataPtrArrayLength) 
	{
		int index = ChatBoxMuObjectChatDataPtrArrayLength - 1;
		ChatBoxMuObjectChatDataPtrArray[index]->chat_type_ = mode;
	}
}

void newInterface::DrawItemToolTipText ( void * item, int x, int y )
{
	static DWORD mem = 0;
	_asm 
	{
		PUSH 0
		PUSH 0
		PUSH 0
		PUSH item
		PUSH y
		PUSH x
		MOV mem,0x00861110
		CALL mem
		MOV ECX, EAX
		MOV mem,0x00861AA0
		CALL mem
		MOV ECX, EAX
		MOV mem,0x007E3E30
		CALL mem
	}
}