#pragma once


#include "stdafx.h"
#include "protocol.h"


struct PMSG_JEWELBANK
{
	PSBMSG_HEAD h;
	int Result;
};

struct PMSG_JEWELSBANK
{
#pragma pack(1)
	PSBMSG_HEAD h;
	int Zen;
	int Chaos;
	int Bless;
	int Soul;
	int Life;
	int CreateonBank;
	int GuardianBank;
	int HarmonyBank;
	int LowStoneBank;
	int HighStoneBank;
	int GemStoneBank;
#pragma pack()
};


class JewelsBank
{
public:
	JewelsBank();
	virtual ~JewelsBank();
	bool Active;
	void JewelsBankImageLoad();
	void JewelsBankLoad();
	void Bind();
	void DrawItem(int ItemType, int ItemIndex, int ItemLevel);
	void DrawWindow(int ObjMain, int ObjTitle, int ObjFrame, int ObjFooter, int Repeat, float X, float Y, char* Text);
	bool ButtonEx(DWORD Event, int ButtonID, bool Type);
	void Draw();
	void DrawLine(int ItemType, int ItemIndex, int ItemLevel, float DrawX, float DrawY, char * ItemName, int Count);
	void DrawInfo(float InfoDrawX, float InfoDrawY, char* Text, bool Type, int Count);
	bool EventJewelBank_Close(DWORD Event);
	void Button(DWORD key);
	void Packet(int number);
	void RecibirJewelsBank(PMSG_JEWELSBANK * aRecv);
	bool  Moving;
	float ultimoX;
	float ultimoY;
	short mX;
	short mY;
};
extern JewelsBank gJewelsBank;