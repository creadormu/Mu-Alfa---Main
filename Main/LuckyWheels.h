//////////////////////////////////////////////////////////////////////

#pragma once

#define MAX_LUCKYWHEEL_ITEM                12

struct LUCKYWHEEL_INFO
{
	int Index;
	int ItemType;
	int ItemIndex;
	int Level;
	int Luck;
	int Skill;
	int Option;
	int Exc;
};

class CLuckyWheel
{
public:
	CLuckyWheel();
	virtual ~CLuckyWheel();
	void Init();
	void Load(LUCKYWHEEL_INFO* info);
	void SetInfo(LUCKYWHEEL_INFO info);
	void Start(int aIndex);
public:
	LUCKYWHEEL_INFO m_LuckyWheelInfo[MAX_LUCKYWHEEL_ITEM];
};

extern CLuckyWheel gLuckyWheel;
