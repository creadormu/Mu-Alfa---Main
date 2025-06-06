#pragma once

#define MAX_SMOKE_ITEMS 500

struct CUSTOM_SMOKEEFFECT
{
	int Index;
	int ItemIndex;
	float Red;
	float Green;
	float Blue;
};

class cSmokeEffect
{
public:
	cSmokeEffect();
	virtual ~cSmokeEffect();
	void Load(CUSTOM_SMOKEEFFECT* info);
	int getSmokeTRSData(int ItemIndex); // OK
	float getRedColor(int ItemIndex);
	float getGreenColor(int ItemIndex);
	float getBlueColor(int ItemIndex);
public:
	std::map<int, CUSTOM_SMOKEEFFECT> m_CustomSmokeEffect;

}; extern cSmokeEffect gSmokeEffect;