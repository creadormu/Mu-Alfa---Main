#pragma once

struct REMAKE_EFFECT
{
	int Index;
	int ItemType;
	int ItemIndex;
	int RemakeEffect;
};

class cCustomRemake
{
public:
	cCustomRemake();
	virtual ~cCustomRemake();
	void Init();
	void Load(REMAKE_EFFECT* info);
	void SetInfo(REMAKE_EFFECT info);
	REMAKE_EFFECT* GetInfo(int index);
	REMAKE_EFFECT* GetInfoByItem(int ItemIndex);
	bool CheckEffectRemake(int ItemIndex);
public:
	REMAKE_EFFECT m_CustomRemake[MAX_REMAKE_EFFECT];
}; extern cCustomRemake gCustomRemake;