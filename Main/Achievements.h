#pragma once

#include "Protocol.h"
#include "Interface.h"

#define ACH_PROTOCOL1	0x23

#define ACHIEVEMENTS_COUNT 50

enum MaiObjID
{
	ImgID_ACHIEVEMENTS_MAIN = 0x9C46,
	ImgID_ACHIEVEMENTS_PROGRESS_BG,
	ImgID_ACHIEVEMENTS_PROGRESS_LINE,
	ImgID_ACHIEVEMENTS_MISSIONS,
	ImgID_ACHIEVEMENTS_PANEL,
	ImgID_ACHIEVEMENTS_DAMAGE,
	ImgID_ACHIEVEMENTS_DEFENSE,
	ImgID_ACHIEVEMENTS_LIFE,
	ImgID_ACHIEVEMENTS_EXCELLENT,
	ImgID_ACHIEVEMENTS_CRITICAL,
};

struct ACH_SETTING_USER_DATA
{
	unsigned int counter;
	char Name[64];
	BYTE RewardType;
	int RewardValue;
};

// ----------------------------------------------------------------------------------------------
// GameServer <-> Client
struct PMSG_GC_ACH_SETTINGS_DATA
{
	PSWMSG_HEAD h;
	//ACHIEVEMENTS_DATA cfg;
	//unsigned int need_to_fill[50];
	ACH_SETTING_USER_DATA Data[ACHIEVEMENTS_COUNT];
};

struct PMSG_GC_ACH_PLAYER_DATA
{
	PSBMSG_HEAD h;
	bool bWinOpen;
	//ACHIEVEMENTS_DATA usr;
	unsigned int counter[ACHIEVEMENTS_COUNT];
};

struct PMSG_CG_ACH_WINOPEN
{
	PSBMSG_HEAD h;
};
// ----------------------------------------------------------------------------------------------

struct PMSG_GC_ACH_POWER
{
	PSBMSG_HEAD h;
	int iDamage;
	int iDamageMax;
	int iDefence;
	int iDefenceMax;
	int iLife;
	int iLifeMax;
	int iExellentDamage;
	int iExellentDamageMax;
	int iCriticalDamage;
	int iCriticalDamageMax;
};
// ----------------------------------------------------------------------------------------------

class CAchievements
{
public:
	CAchievements();
	~CAchievements();

	void Init();
	void Load();
	void LoadImages();
	void BindImages();
	void Draw();
	void DrawMission(int ObjectID, float X, float Y, char* Name, int Start, int Need);
	void Button(DWORD Event);
	void GCConfigData(PMSG_GC_ACH_SETTINGS_DATA* aRecv);
	void GCPlayerData(PMSG_GC_ACH_PLAYER_DATA* aRecv);
	void CGWindowOpen();
	void DrawPanel();
	void DrawPower(int ObjectID, float X, float Y, char* Name, int Start, int Need);
	void GCCalculatorPower(PMSG_GC_ACH_POWER* aRecv);
	void SwitchStatsWindowState() { (gInterface.Data[OBJECT_ACHIEVEMENTS_MAIN].OnShow == true) ? gInterface.Data[OBJECT_ACHIEVEMENTS_MAIN].Close() : gInterface.Data[OBJECT_ACHIEVEMENTS_MAIN].Open(-226, 20); };

private:
	//bool bActive;
	//ACHIEVEMENTS_DATA m_config;
	//ACHIEVEMENTS_DATA m_user;
	ACH_SETTING_USER_DATA m_SettingsData[ACHIEVEMENTS_COUNT];
	unsigned int m_UserCount[ACHIEVEMENTS_COUNT];

	int m_Damage;
	int m_DamageMax;
	int m_Defence;
	int m_DefenceMax;
	int m_Life;
	int m_LifeMax;
	int m_ExellentDamage;
	int m_ExellentDamageMax;
	int m_CriticalDamage;
	int m_CriticalDamageMax;
};
extern CAchievements  gAchievements;
// ----------------------------------------------------------------------------------------------