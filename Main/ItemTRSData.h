#pragma once

struct CUSTOM_POSITION_INFO
{
	int		Index;
	int		ItemIndex;
	float	translationX;
	float	translationY;
	float	RotationX;
	float	RotationY;
	float	RotationZ;
	float	Scale;
};

class cCustomPosition
{
public:
	cCustomPosition();
	virtual ~cCustomPosition();
	void Init();
	void Load(CUSTOM_POSITION_INFO* info);
	//--
	bool GetItemTRSData(int ItemIndex);
	float GetItemTRSDataTransLationX(int ItemIndex);
	float GetItemTRSDataTransLationY(int ItemIndex);
	float GetItemTRSDataRotationX(int ItemIndex);
	float GetItemTRSDataRotationY(int ItemIndex);
	float GetItemTRSDataRotationZ(int ItemIndex);
	float GetItemTRSDataScale(int ItemIndex);
	static void CustomPosition(int a1, int a2, int a3, int a4, VAngle* a5, int a6, char a7);
public:
	//CUSTOM_POSITION_INFO m_CustomPositionInfo[MAX_POSITION_ITEM];
	std::map<int, CUSTOM_POSITION_INFO> m_ItemTRSData;
};

extern cCustomPosition ItemTRSData;
