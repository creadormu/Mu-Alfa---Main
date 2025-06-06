#pragma once
typedef char * String;
typedef char textlist[100];
#define MAX_MUUN_DATA						0x12C
#define OPEN_MUUN_SCRIPT					0x3BB2
#define MAX_OPT_MUUN						5

#define g_hWnd											*(HWND*)0xE8C578
#define BuxConvert										((int(__cdecl*)(BYTE * Buffer, int Size)) 0x004071A0)
#define PetProcessData									((void(__thiscall*)(int thisa)) 0x00924D80)
#define tooltitextScriptLoader							((void(__thiscall*)(BYTE * thisa, int pchFileName)) 0x007E39B0)
#define ForSocketItem									((int (__thiscall*)(LPVOID thisa, ITEM* ip, int num)) 0x00968880)
#define EndRenderColor									((void(__cdecl*)())0x00637A30)
#define RenderColor										((void(__cdecl*)(float x,float y,float Width,float Height, float Alpha, int Flag)) 0x006378A0)


typedef struct
{
	WORD Type;
	BYTE MuunType;
	BYTE Rank;
	BYTE OptionIndex;
} MUUN_ATTRIBUTE;

typedef struct
{
	WORD Type;
	BYTE Optio[MAX_OPT_MUUN];
	WORD Val[MAX_OPT_MUUN];
	BYTE SpecialOpt;
	BYTE Specialval;
	BYTE Map;
	BYTE DayOfWeek;
	BYTE MinHor;
	BYTE MaxHor;
	WORD MinLvl;
	WORD MaxLvl;
} MUUN_OPTION;

typedef struct
{
	WORD Type;
	BYTE Optio;
	textlist text;
} MUUN_TOOLTIP_TEXT;

class MuunOption
{
public:
	enum FontType
	{
		Font_Normal = 0,
		Font_Bold = 1,
	};
	enum MuunType
	{
		TypeNormal = 0,
		TypeUtil = 1,
		TypeMount = 2,
	};
	enum MuunOptionC
	{
		ADD_HP = 1,
		ADD_MP,
		DMG_RATE,
		ATTK_SPEED,
		DOUBLE_DMG_RATE,
		TRIPLE_DMG_RATE,
		INC_EXP_RATE,
		RES_DOUBLE_DMG,
		RES_IGNORE_DEF,
		RES_IGNORE_SD,
		RES_CRITICAL_DMG,
		RES_EXE_DMG,
		BLOCKSTUCK,
		REFLECT_RATE,
	};
	enum ColorLine
	{
		TEXT_COLOR_WHITE = 0,
		TEXT_COLOR_BLUE,
		TEXT_COLOR_RED,
		TEXT_COLOR_YELLOW,
		TEXT_COLOR_GREEN,
		TEXT_COLOR_DARKRED,
		TEXT_COLOR_PURPLE,
		TEXT_COLOR_DARKBLUE,
		TEXT_COLOR_DARKYELLOW,
		TEXT_COLOR_GREEN_BLUE,
		TEXT_COLOR_GRAY,
		TEXT_COLOR_REDPURPLE,
		TEXT_COLOR_VIOLET,
		TEXT_COLOR_ORANGE = 13,
	};
	MuunOption();
	virtual ~MuunOption();
	void Init();
	//--
	int AttachToolTipForMuun(ITEM* Temp, int TextNum);
	static void CRenderItem3D(float x, float y, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
	static void RenderTipTextList(int sx, int sy, int TextNum, int Tab, int iSort, int iRenderPoint, BOOL bUseBG);
	//-- change text
    static	char * __thiscall GetFontname(LPVOID thisa, int LineNumber);
    static	void __thiscall itemtooltiptextScriptLoader(BYTE * thisa, int pchFileName);
	//--
	static void OpenPetProcess(int thisa);
	static void OpenMuunScript(char *FileName);
	static void OpenMuunOptScript(char *FileName);
	static void OpenMuunTextScript(char *FileName);
	//--
	String GetGlobalMuunText(int Line);
	static MUUN_OPTION * GetMuunInfo(WORD Index);
	//--
	static MUUN_ATTRIBUTE * GetAttribute(WORD Index);
    static	int __thiscall AttachToolTipForSocketItem(LPVOID thisa, ITEM* Temp, int TextNum);
public:
	int ITEM_SELECT;
	//--
	MUUN_ATTRIBUTE MuunAttribute[MAX_MUUN_DATA];
	MUUN_OPTION MuunOPT[MAX_MUUN_DATA];
	MUUN_TOOLTIP_TEXT MuunText[MAX_MUUN_DATA];
};

extern MuunOption g_Option;
