#ifndef _CUSTOM_RANK_USER_H
#define _CUSTOM_RANK_USER_H
// ---
#include "Protocol.h"
#include "Object.h"
// ---
#define pObjPreviewThis        ((DWORD)0x096A4C0)
#define CS_GET_STRUCT(x, y)	   (1124 * x + *(int*) y)
#define Color4f(r, b, g, o)	   ((o << 24) + (g << 16) + (b << 8) + r)
// ---

// ---
struct PMSG_CUSTOM_RANKUSER
{
	PSBMSG_HEAD h;
	char szName[20];
	int iIndex;
	int iLevel;
	int iReset;
	int iMReset;
	int iKills;
	int iDeads;
	int iFor;
	int iEne;
	int iAgi;
	int iVit;
	int iCom;
	int iClasse;
	int iRank;
	int m_RankTitle1;
	int m_RankTitle4;
	int iLvtuchan;
	int ircrit;
	int irexc;
	int irdmg;
	int irdouble;
	char iVip[20];
};
// ---
struct CUSTOM_RANKUSER_DATA
{
	WORD m_Index;
	WORD m_Resets;
	WORD m_MResets;
	WORD m_Level;
	WORD m_Kills;
	WORD m_Deads;
	WORD m_For;
	WORD m_Vit;
	WORD m_Ene;
	WORD m_Agi;
	WORD m_Com;
	WORD m_Classe;
	WORD m_Rank;
	WORD m_RankTitle1;
	int m_RankTitle4;
	WORD m_Lvtuchan;
	WORD m_rcrit;
	WORD m_rexc;
	WORD m_rdmg;
	WORD m_rdouble;
	char m_Vip[20];
	BOOL m_Enabled;
	DWORD	ModelID;
	float	Width;
	float	Height;
	float	X;
	float	Y;
	float	MaxX;
	float	MaxY;
	DWORD	EventTick;
	bool	OnClick;
	bool	OnShow;
	BYTE	Attribute;
	char szTitleRank[20];
};
// ---
class CCustomRankUser
{
public:
	CCustomRankUser();
	// ---
	void DrawInfo();
	void RenderShowLogRank(DWORD ViewPortAddr, int index, int PosX, int PosY);
	void LoadInfoUser(int index, int PosX, int PosY, char* name);
	int  DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);
	// ---
	void GCReqRankLevelUser(PMSG_CUSTOM_RANKUSER * aRecv);

private:
	/*//-- Max Monster 10000
	CUSTOM_RANKUSER_DATA m_Data[10000];*/
	// -- Max Monster 12000
	CUSTOM_RANKUSER_DATA m_Data[14000];
	/*// -- Max Monster 30500
	CUSTOM_RANKUSER_DATA m_Data[32500];*/
};
extern CCustomRankUser gCustomRankUser;
// ---
class CPreviewManager
{
public:
	bool ObjCheck(int index, int pThis);
	bool ObjSelect(int index, int pThis);
	// ---
	WORD  Index;
	BYTE  Live;
	BYTE  Type;
	BYTE  IsSafeZone;
	// ---
	VAngle Angle;
};
// ---
#endif