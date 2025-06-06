#pragma once
#define sub_6D9070		((int(__cdecl*) (int a4, vec3_t VecPos, vec3_t WorldPos, vec3_t Color, int a8, int a9, __int16 a10, __int16 a11, __int16 a12, __int16 a13, float a14, __int16 a15)) 0x006D9070)
#define sub_6D6C20_Addr		((signed int(__cdecl*)(int a1, Object* a2, int a3)) 0x6D6C20)
#define sub_6D9070_Addr		((int(__cdecl*)(int Type, vec3_t Position, vec3_t Angle, vec3_t Light, int SubType, Object* Owner, __int16 PKKey, __int16 Skill, __int16 Scale, __int16 SkillSerial, float SkillAngle, __int16 SkillHotKey)) 0x6D9070)


struct CUSTOM_BOW_INFO
{
	int Index;
	int ItemIndex;
	char ModelName[32];
	int ItemType;
	int SkillShot;
	int ColorR;
	int ColorG;
	int ColorB;
};

class CCustomBow
{
public:
	CCustomBow();
	virtual ~CCustomBow();
	void Init();
	void Load(CUSTOM_BOW_INFO* info);
	CUSTOM_BOW_INFO* GetInfoByItem(int ItemIndex);
	bool CheckCustomBow(int ItemIndex);
	bool CheckCustomCross(int ItemIndex);
	int GetCustomSkill(int ItemIndex); // OK
public:
	std::map<int,CUSTOM_BOW_INFO> m_CustomBowInfo;
};

extern CCustomBow gCustomBow;