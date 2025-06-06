#pragma once

#define sub_50D810	((int(__thiscall*)(int a1, int a2, int a3, int a4)) 0x50D810)
#define sub_512D50	((void*(__thiscall*)(void* a1)) 0x512D50)
#define sub_513C60	((char*(__thiscall*)(char *This, void *a2, int a3)) 0x513C60)
#define sub_5135F0	((char*(__thiscall*)(DWORD *This, int a2, int a3)) 0x5135F0)
#define sub_512D60	((void(*)()) 0x512D60)

struct CUSTOM_RF_GLOVES
{
	int Index;
	int ItemIndex;
	char ModelName[32];
	int TextureLeftIndex;
	char TextureLeftName[32];
	int TextureRightIndex;
	char TextureRightName[32];
	int ColorR;
	int ColorG;
	int ColorB;
};

class cCustomGloves
{
public:
	cCustomGloves();
	virtual ~cCustomGloves();
	void Init();
	void Load(CUSTOM_RF_GLOVES* info);
	bool CheckGloves(int ItemID);
	//--
	int GetItemIndex(int ItemIndex);
	//--------
public:
	std::map<int, CUSTOM_RF_GLOVES> m_CustomGlovesInfo;

}; extern cCustomGloves gCustomBattleGloves;