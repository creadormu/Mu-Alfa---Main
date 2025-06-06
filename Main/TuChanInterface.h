#pragma once
#include "Interface.h"

struct EVENTTUCHAN_REQ
{
	PSBMSG_HEAD h;
	int	TU_CHAN;
};





class cTuChanInterface{
public:
	cTuChanInterface();
	~cTuChanInterface();
	void	loadBind();
	void	SwitchTuChan();
	void	GCReqTuChan();	
	void	DrawTuChanWindow();
	bool	CheckTuChanWindow() { return gInterface.Data[eTUCHAN_MAIN].OnShow; };
	bool	EventTuChanWindow_Close(DWORD Event);
	bool	EventTuChanWindow_Send(DWORD Event);
	bool	EventShowTuChanDraw(DWORD Event);
	bool	EventTuChanWindow_Main(DWORD Event);


	void DrawLineJewel(int ItemType, int ItemIndex, int ItemLevel, float DrawX, float DrawY, char * ItemName, int Count);
	void DrawInfo(float InfoDrawX, float InfoDrawY, char* Text, bool Type, int Count);
	void DrawItem(int ItemType, int ItemIndex, int ItemLevel);
	void	OpenTuChanWindow() { gInterface.Data[eTUCHAN_MAIN].OnShow = true; };
	void	CloseTuChanWindow() { gInterface.Data[eTUCHAN_MAIN].OnShow = false;};
	bool	EventNextTC(DWORD Event);
	bool	EventPrevTC(DWORD Event);
	void EventTuChan_Send(int TU_CHAN);

	int		Count;
	int		Page;
	int		Arena;
}; extern cTuChanInterface gTuChanInterface;
