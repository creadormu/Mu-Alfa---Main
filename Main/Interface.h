#pragma once

#include "stdafx.h"
#include "import.h"
#include "Protect.h"

#define MAX_OBJECT 	1024//512
#define MAX_WIN_WIDTH 640
#define MAX_WIN_HEIGHT 480
#define MAX_WINDOW_EX 100

#define pDrawInterfaceNumBer   ((double(__stdcall*)(float X, float Y, int num, float size)) 0x854FE0)
#define sub_4DB0C0					((double(__cdecl*)(float a1))0x4DB0C0)
#define resizeGuiRate				1.875
#define resizeGuiScaleRateX			(float)*(DWORD*)MAIN_RESOLUTION_X / 800.0f
#define resizeGuiScaleRateY			(float)*(DWORD*)MAIN_RESOLUTION_Y / 600.0f
#define resizeGuiRateX				resizeGuiRate * resizeGuiScaleRateX
#define resizeGuiRateY				resizeGuiRate * resizeGuiScaleRateY


#define GMT (24 + (gProtect.m_MainInfo.TIME_GMT))

enum ObjectID
{
	eFlag01=1,
	eFlag02,
	eFlag03,
	eFlag04,
	eFlag05,
	eFlag06,
	eFlag07,
	eFlag08,
	eFlag09,
	eFlag10,
	eFlag11,
	eFlag12,
	eFlag13,
	eFlag14,
	eFlag15,
	eFlag16,
	eFlag17,
	eFlag18,
	eFlag19,
	eFlag20,
	eFlag21,
	eFlag22,
	//eTIME,
	eRankPANEL_MAIN,
	eRanking,
	eSAMPLEBUTTON,
	eSAMPLEBUTTON2,
	eVip_MAIN,
	eVip_TITLE,
	eVip_FRAME,
	eVip_FOOTER,
	eVip_DIV,
	eVip_CLOSE,
	eVip_BRONZE,
	eVip_SILVER,
	eVip_GOLD,
	eVip_PLATINUM,
	eVip_STATUS,
	eRanking_MAIN,
	eRanking_CLOSE,
	eRanking_TITLE,
	eRanking_FRAME,
	eRanking_FOOTER,
	eLogo,
	eEventTimePANEL_MAIN,
	eEventTime_MAIN,
	eEventTime_TITLE,
	eEventTime_CLOSE,
	eEventTime_FRAME,
	eEventTime_FOOTER,
	eMenu,
	eMenuBG,
	
	eMenu_MAIN,
	eMenu_MAINTWO,
	eMenu_TITLE,
	eMenu_FRAME,
	eMenu_FOOTER,
	eMenu_DIV,
	eMenu_CLOSE,
	eMenu_OPT1,
	eMenu_OPT2,
	eMenu_OPT3,
	eMenu_OPT4,
	eMenu_OPT20,
	eMenu_VAULT,
	eMenu_USERPANEL,
	eMenu_CHANGECLASS,
	eMenu_NEXT,
	eMenu_PREVIUS,
	eMenu_RESETCHANGE,
	eMenu_LUCKYWELL,
	eMenu_SMITH_ITEM,
	eMenu_JEWEL_BANK,
	eMenu_CUSTOM_VIP,
	eMenu_RANK_TITLE,
	eMenu_TU_CHAN,
	eMenu_QUEST_SYSTEM,

	eCommand_MAIN,
	eCommand_TITLE,
	eCommand_FRAME,
	eCommand_FOOTER,
	eCommand_DIV,
	eCommand_CLOSE,
	eOFFTRADE_JoB,
	eOFFTRADE_JoS,
	eOFFTRADE_JoC,
	eOFFTRADE_WCC,
	eOFFTRADE_WCP,
	eOFFTRADE_WCG,
	eOFFTRADE_OPEN,
	//Minimap
	ePLAYER_POINT,
	eNULL_MAP,
	eLORENCIA_MAP,
	eDUNGEON_MAP,
	eDEVIAS_MAP,
	eNORIA_MAP,
	eLOSTTOWER_MAP,
	eSTADIUM_MAP,
	eATLANS_MAP,
	eTarkan_MAP,
	eElbeland_MAP,
	eICARUS_MAP,
	eLANDOFTRIALS_MAP,
	eAIDA_MAP,
	eCRYWOLF_MAP,
	eKANTRU_MAP,
	eKANTRU3_MAP,
	eBARRACKS_MAP,
	eCALMNESS_MAP,
	eRAKLION_MAP,
	eVULCANUS_MAP,
	eKALRUTAN_MAP,
	eKALRUTAN2_MAP,
	eCONFIRM_MAIN,
	eCONFIRM_BTN_OK,
	eCONFIRM_BTN_CANCEL,
	eCONFIRM_TITLE,
	eCONFIRM_FRAME,
	eCONFIRM_FOOTER,
	eCONFIRM_DIV,
	eNextCommand,
	ePrevCommand,
	eNextEvent,
	ePrevEvent,
//Ex700
	eMainEx700,
	eQuest,
	eCommunity,
	eSystem,
	//--custom
	eSTORE_CLOSE,
	ex_INFO_2,
	eADVANCE_STAT_INFO,
	//--s2
	eMainS2right,
	eMainS2middle,
	eMainS2left,
	eSkillBox,
	eDragonLeft,
	eDragonRight,
	eCharacter,
	eInventory,
	eParty,
	eFriend,
	eFastMenu,
	eShop,
	eGuild,
	//--custom money
	eMoney1,
	eMoney2,
	CharacterSelect,
	CharacterSelect_Button1,
	CharacterSelect_Button2,
	CharacterSelect_Button3,
	CharacterSelect_Button4,
	CharacterSelect_Button5,
	CharacterCreate_Button1,
	CharacterCreate_Button2,
	CharacterCreate_Button3,
	CharacterCreate_Button4,
	CharacterCreate_Button5,
	CharacterCreate_Button6,
	CharacterCreate_Button7,
	CharacterCreate_SEND,
	CharacterCreate_CANCEL,
	//chat
	chatbackground,
	MINIMAP_FRAME,
	MINIMAP_TIME_FRAME,
	MINIMAP_BUTTOM,
	ButtonSettings,
	ButtonStart,
	ButtonStop,
	ButtonStartAttack,
	eCamera3DInit,
	eCamera3DSwitch,
	strucMoveInv,
	eMainEx700Exp,
	RuudShopListIzq,
	RuudShopListDer,
	RuudShopWindow,
	RuudShopExit,
	eButton1,
	eButton2,
	eButton3,
	eButton4,
	eButton5,
	eJewelOfBank,
	eJewelOfBankPush,
	eJewelOfBankRemove,
	eJewelOfBankClose,
	ePARTYSETTINGS_MAIN,
	ePARTYSETTINGS_TITLE,
	ePARTYSETTINGS_FRAME,
	ePARTYSETTINGS_FOOTER,
	ePARTYSETTINGS_DIV,
	ePARTYSETTINGS_CLOSE,
	ePARTYSETTINGS_SYSTEM_ACTIVE,
	ePARTYSETTINGS_ONLY_GUILD,
	ePARTYSETTINGS_ONE_CLASS,
	ePARTYSETTINGS_DARK_WIZARD,
	ePARTYSETTINGS_DARK_KNIGHT,
	ePARTYSETTINGS_ELF,
	ePARTYSETTINGS_MAGIC_GLADIATOR,
	ePARTYSETTINGS_DARK_LORD,
	ePARTYSETTINGS_SUMMONER,
	ePARTYSETTINGS_RAGE_FIGHTER,
	ePARTYSETTINGS_LEVEL_MINUS,
	ePARTYSETTINGS_LEVEL_PLUS,
	ePARTYSETTINGS_OK,
	ePARTYSEARCH_LEFT,
	ePARTYSEARCH_RIGHT,
	ePARTYSEARCH_MAIN,
	ePARTYSEARCH_TITLE,
	ePARTYSEARCH_FRAME,
	ePARTYSEARCH_FOOTER,
	ePARTYSEARCH_DIV,
	ePARTYSEARCH_CLOSE,
	ePARTYSETTINGS_INF,
	ePARTYSETTINGS_INF2,
	eVAULT_MAIN,
	eVAULT_TITLE,
	eVAULT_FRAME,
	eVAULT_FOOTER,
	eVAULT_DIV,
	eVAULT_INFOBG,
	eVAULT_MONEYBG,
	eVAULT_CLOSE,
	eVAULT_FINISH,
	eWARE1_FINISH,
	eWARE2_FINISH,
	eWARE3_FINISH,
	eWARE4_FINISH,
	eWARE5_FINISH,
	eWARE6_FINISH,
	eWARE7_FINISH,
	eWARE8_FINISH,
	eWARE9_FINISH,
	eCHANGINGCLASS_MAIN,
	eCHANGINGCLASS_TITLE,
	eCHANGINGCLASS_FRAME,
	eCHANGINGCLASS_FOOTER,
	eCHANGINGCLASS_DIV,
	eCHANGINGCLASS_INFOBG,
	eCHANGINGCLASS_MONEYBG,
	eCHANGINGCLASS_CLOSE,
	eCHANGINGCLASS_DW,
	eCHANGINGCLASS_DK,
	eCHANGINGCLASS_ELF,
	eCHANGINGCLASS_MG,
	eCHANGINGCLASS_DL,
	eCHANGINGCLASS_SUM,
	eCHANGINGCLASS_RF,
	eCHANGE_RESET_MAIN,
	eCHANGE_RESET_TITLE,
	eCHANGE_RESET_FRAME,
	eCHANGE_RESET_FOOTER,
	eCHANGE_RESET_DIV,
	eCHANGE_RESET_LINE,
	eCHANGE_RESET_INFOBG,
	eCHANGE_RESET_MONEYBG,
	eCHANGE_RESET_CLOSE,
	eCHANGE_RESET_5,
	eCHANGE_RESET_10,
	eCHANGE_RESET_15,
	eCHANGE_RESET_20,
	eCHANGE_RESET_25,

	eLuckyWheelMain,
	eLuckyWheelStart,
	eLuckyWheelPanel,
	eCloseLuckyWheel,

	//Smith
	eSMITH_MAIN,
	eSMITH_MAIN_EX,

	eSMITH_TITLE,
	eSMITH_FRAME,
	eSMITH_FOOTER,
	eSMITH_DIV,
	eSMITH_CLOSE,
	eSMITH_BUY,
	//controll -
	eSMITH_ITEMTYPE,
	eSMITH_ITEMINDEX,
	eSMITH_LEVEL,
	eSMITH_SKILL,
	eSMITH_LUCK,
	eSMITH_OPT,
	eSMITH_EXC,
	eSMITH_EXC1,
	eSMITH_EXC2,
	eSMITH_EXC3,
	eSMITH_EXC4,
	eSMITH_EXC5,
	eSMITH_DAYS,
	//controll +
	eSMITH_ITEMTYPE_1,
	eSMITH_ITEMINDEX_1,
	eSMITH_LEVEL_1,
	eSMITH_SKILL_1,
	eSMITH_LUCK_1,
	eSMITH_OPT_1,
	eSMITH_EXC_1,
	eSMITH_EXC1_1,
	eSMITH_EXC2_1,
	eSMITH_EXC3_1,
	eSMITH_EXC4_1,
	eSMITH_EXC5_1,
	eSMITH_DAYS_1,
	eUNCHECK_1,
	eUNCHECK_2,
	eUNCHECK_3,
	eUNCHECK_4,
	eUNCHECK_5,
	eUNCHECK_6,
	eCHECKED_1,
	eCHECKED_2,
	eCHECKED_3,
	eCHECKED_4,
	eCHECKED_5,
	eCHECKED_6,

	eJEWELBANK_MAIN,
	eJEWELBANK_TITLE,
	eJEWELBANK_FRAME,
	eJEWELBANK_FOOTER,
	eJEWELBANK_POINT,
	eJEWELBANK_LINE,
	eJEWELBANK_DIV,
	eJEWELBANK_CLOSE,
	eJEWELBANK_PAGEUP1,
	eJEWELBANK_PAGEUP2,
	eJEWELBANK_PAGEUP3,
	eJEWELBANK_PAGEUP4,
	eJEWELBANK_PAGEUP5,
	eJEWELBANK_PAGEUP6,
	eJEWELBANK_PAGEUP7,
	eJEWELBANK_PAGEUP8,
	eJEWELBANK_PAGEUP9,
	eJEWELBANK_PAGEUP10,
	eJEWELBANK_PAGEUP11,
	eJEWELBANK_PAGEDN1,
	eJEWELBANK_PAGEDN2,
	eJEWELBANK_PAGEDN3,
	eJEWELBANK_PAGEDN4,
	eJEWELBANK_PAGEDN5,
	eJEWELBANK_PAGEDN6,
	eJEWELBANK_PAGEDN7,
	eJEWELBANK_PAGEDN8,
	eJEWELBANK_PAGEDN9,
	eJEWELBANK_PAGEDN10,
	eJEWELBANK_PAGEDN11,

#if (SELECTCHARACTER==1)
		eSELECTCHAR_LEFT,
		eSELECTCHAR_RIGHT,
#endif

	OBJECT_ACHIEVEMENTS_MAIN,
	OBJECT_ACHIEVEMENTS_PROGRESS_BG,
	OBJECT_ACHIEVEMENTS_PANEL,
	OBJECT_ACHIEVEMENTS_CLOSE,
	OBJECT_ACHIEVEMENTS_MISSIONS,
	OBJECT_ACHIEVEMENTS_DAMAGE,
	OBJECT_ACHIEVEMENTS_DEFENSE,
	OBJECT_ACHIEVEMENTS_LIFE,
	OBJECT_ACHIEVEMENTS_EXCELLENT,
	OBJECT_ACHIEVEMENTS_CRITICAL,
	EXBEXO_MUA_VIP_MAIN,
	EXBEXO_MUA_VIP_CLOSE,
	EXBEXO_MUA_VIP_NANG_CAP,
	EXBEXO_DANH_HIEU_MAIN,
	EXBEXO_DANH_HIEU_CLOSE,
	EXBEXO_DANH_HIEU_NANG_CAP,
	eTUCHAN_MAIN,
	eTUCHAN_TITLE,
	eTUCHAN_FRAME,
	eTUCHAN_FOOTER,
	eTUCHAN_DIV,
	eTUCHAN_CLOSE,
	eTUCHAN_SYSTEM_ACTIVE,
	ePrevEventTC,
	eNextEventTC,
	eTuChanSend,
	eShowTuChan,
	OBJECT_WIN_QUEST_MAIN,
	OBJECT_WIN_QUEST_TITLE,
	OBJECT_WIN_QUEST_FRAME,
	OBJECT_WIN_QUEST_FOOTER,
	OBJECT_WIN_QUEST_DIV,
	OBJECT_WIN_QUEST_CLOSE,
	OBJECT_WIN_QUEST_TAB,
	OBJECT_WIN_QUEST_TAB1,
	OBJECT_WIN_QUEST_TAB2,
	OBJECT_WIN_QUEST_TAB3,
	OBJECT_WIN_QUEST_FINISH,
	OBJECT_WIN_QUEST_COUNT1,
	OBJECT_WIN_QUEST_COUNT2,
	OBJECT_WIN_QUEST_COUNT3,
	OBJECT_WIN_QUEST_INFOBG,
	OBJECT_WIN_QUEST_INFOBG2,
	OBJECT_WIN_QUEST_LINE1,
	OBJECT_WIN_QUEST_POINT1,
	OBJECT_WIN_QUEST_INFO,
	OBJECT_WIN_QUEST_INFOBG3,
	eCONFIRM_MUUN,
    eCONFIRM_MUUNBTN_OK,
    eCONFIRM_MUUNBTN_CANCEL,
};

enum InterfaceID
{
	iOptionDot			= 0x7B68,
	iOptionCheck		= 0x7B69,
};


struct InterfaceElement
{
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

	long	OpenedValue;
	BYTE	Speed;
	char	StatValue[20];
	bool	ByClose;
	bool	FirstLoad;

	void Open()
	{
		this->OnShow = true; 
		pSetCursorFocus = true;
		this->ByClose = false;
	};

	void Open(int Value, int Speed)
	{
		this->OnShow = true; pSetCursorFocus = true;
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
		this->FirstLoad = true;
	};

	void Close()
	{
		this->OnShow = false;
		pSetCursorFocus = false;
		this->ByClose = false;
	};

	void Close(int Value, int Speed)
	{
		this->OnShow = false; pSetCursorFocus = false;
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
	}
};

class Interface
{
public:
	int ConfirmSlot;
	float PetY;
	float PetX;
	int lastReport;
	int frameCount;
	int frameRate;
	char FPS_REAL[30];
	void UPDATE_FPS();
	void guiMonitore();
	int iniciador;
	int msPing;
	int lastSend;
	int validar;
	char ServerPing[50];
	char ultimoPing[50];
	int ultimo_Ping;
	char ServerRTT[50];
	char ultimoRTT[50];
	int ultimo_RTT;
	InterfaceElement Data[MAX_OBJECT];
public:
	Interface();
	virtual ~Interface();
	void RenderObjectSystem();
	static void LoadImages();
	static void LoadModels();
	static void Work();
//-- System Windows
	void OpenVipWindow(){ this->Data[eVip_MAIN].OnShow = true; };
	void CloseVipWindow() { this->Data[eVip_MAIN].OnShow = false; }
	bool CheckVipWindow() { return this->Data[eVip_MAIN].OnShow; };
	void DrawVipWindow();
	bool EventVipWindow_Main(DWORD Event);
	bool EventVipWindow_Close(DWORD Event);
	bool EventVipWindow_Bronze(DWORD Event);
	bool EventVipWindow_Silver(DWORD Event);
	bool EventVipWindow_Gold(DWORD Event);
	bool EventVipWindow_Platinum(DWORD Event);
	bool EventVipWindow_StatusVip(DWORD Event);
	//--
	void DrawMenu();
	bool EventDrawMenu_Open(DWORD Event);
	void OpenWindowMenu();

	void		OpenMenuWindow() { this->Data[eMenu_MAIN].OnShow = true;};// pSetCursorFocus = true; };

	void CloseMenuWindow() {this->Data[eMenu_MAIN].OnShow = false; };
	bool CheckMenuWindow() { return this->Data[eMenu_MAIN].OnShow; };
	
	void DrawMenuOpen();
	void OpenWindowMenuTwo();
	void DrawMenuOpenTwo();
	void CloseMenuWindowTwo() { this->Data[eMenu_MAINTWO].OnShow = false;};
	bool CheckMenuWindowTwo() { return this->Data[eMenu_MAINTWO].OnShow; };
	void ButtonsMenu(DWORD Event);
	DWORD ClickTime;
	//--
	void DrawConfirmOpen();
	bool EventConfirm_OK(DWORD Event);
	bool EventConfirm_CANCEL(DWORD Event);
//-- Funtions
	void BindObject(short ObjectID, DWORD ModelID, float Width, float Height, float X, float Y);
	void DrawGUI(short ObjectID, float PosX, float PosY);
	void DrawGUI2(short ObjectID, float PosX, float PosY);
	void DrawGUI3(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void DrawTimeUI();
	int DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);
	void DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void ResetDrawIMG(short ObjectID);
	void ResetDrawIMG2(short ObjectID);
	int DrawMessage(int Mode, LPCSTR Text, ...);
	void DrawItem(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
	static void DrawItem2(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
	
	bool CheckWindow(int WindowID);
	int CloseWindow(int WindowID);
	int OpenWindow(int WindowID);	
	bool IsWorkZone(short ObjectID);
	bool IsWorkZone(float X, float Y, float MaxX, float MaxY);
	bool IsWorkZone2(float X, float Y, float MaxX, float MaxY);
	bool IsWorkZone3(float X, float Y, float MaxX, float MaxY, bool a5 = false);
	void DrawButton2(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	bool IsWorkZone4(float X, float Y, float MaxX, float MaxY);
	void DrawColoredGUI2(short ObjectID, float X, float Y, DWORD Color);

	float GetResizeX(short ObjectID);
	int DrawToolTip(int X, int Y, LPCSTR Text, ...);
	float DrawRepeatGUI(short MonsterID, float X, float Y, int Count);
	float DrawRepeatGUIScale(short MonsterID, float X, float Y,float ScaleX, float ScaleY, int Count);
	void DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color);
	void DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void DrawButtonRender(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void DrawLogo(bool active);
	void CloseCustomWindow();
	//Mini Map
	void DrawMiniMap();
	bool MiniMapCheck();
	bool CombinedChecks();
	bool CheckMap();
	void SwitchMiniMap();
	// ex700
	void DrawInterfaceCustom();
	// s2
	void DrawInterfaceS2Menu();
	void DrawInterface97Menu();
	void EventNewInterface_All(DWORD Event);
	void EventNewInterface97_All(DWORD Event);
	void DrawCoord();
	void DrawInterfaceDragonLS3();
	void DrawInterfaceDragonRS3();
	// Advanced Stats
	bool WindowEx[MAX_WINDOW_EX];
	bool CheckWindowEx(int WindowID);
	void DrawBarForm(float PosX,float PosY,float Width,float Height,GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	//--
	void OpenConfig(int type);
	void SwitchCamera();
	void SwitchChatExpand();
	void CameraInit();
	bool Button(DWORD Event, int WinID, int ButtonID, bool Type);
	bool ButtonEx(DWORD Event, int ButtonID, bool Type);
	void DrawPing();
	void SendPingRecv();

	static void DrawZenAndRud(int a1, int a2, int a3, int a4);

	// PARTY SEARCH
	int			DrawToolTipEx(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...);
	void		DrawColoredButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY, DWORD Color);
	void		DrawPartySettingsWindow();
	void		SwitchPartySettingsWindowState();
	bool		EventPartySettingsWindow_Main(DWORD Event);
	bool		EventPartySettingsWindow_Close(DWORD Event);
	bool		EventPartySettingsWindow_All(DWORD Event);
	void		DrawPartySearchWindow();
	void		SwitchPartySearchWindowState() { (Data[ePARTYSEARCH_MAIN].OnShow == true) ? Data[ePARTYSEARCH_MAIN].Close() : Data[ePARTYSEARCH_MAIN].Open(); };
	void		EventPartySearchWindow_All(DWORD Event);
	// END PARTY SEARCH


	void		OpenVaultWindow() { this->Data[eVAULT_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CloseVaultWindow() { this->Data[eVAULT_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CheckVaultWindow() { return this->Data[eVAULT_MAIN].OnShow; };
	void		DrawVaultWindow();
	bool		EventVaultWindow_Main(DWORD Event);
	bool		EventVaultWindow_Close(DWORD Event);
	bool		EventVaultWindow_Finish(DWORD Event);
	bool		EventWARE1Window_Finish(DWORD Event);
	bool		EventWARE2Window_Finish(DWORD Event);
	bool		EventWARE3Window_Finish(DWORD Event);
	bool		EventWARE4Window_Finish(DWORD Event);
	bool		EventWARE5Window_Finish(DWORD Event);
	bool		EventWARE6Window_Finish(DWORD Event);
	bool		EventWARE7Window_Finish(DWORD Event);
	bool		EventWARE8Window_Finish(DWORD Event);
	bool		EventWARE9Window_Finish(DWORD Event);

	void		DrawChangingClassWindow();
	bool		EventChangingClassWindow_Main(DWORD Event);
	bool		EventChangingClassWindow_Close(DWORD Event);	
	bool		EventChangingClassWindow_DW(DWORD Event);
	bool		EventChangingClassWindow_DK(DWORD Event);
	bool		EventChangingClassWindow_ELF(DWORD Event);
	bool		EventChangingClassWindow_MG(DWORD Event);
	bool		EventChangingClassWindow_DL(DWORD Event);
	bool		EventChangingClassWindow_SUM(DWORD Event);
	bool		EventChangingClassWindow_RF(DWORD Event);

	bool		EventDrawClose_LuckyWheel(DWORD Event);
	void		DrawLuckyWheel();
	void		EventLuckyWheel_Main(DWORD Event);
	void		LuckyWheelState(){(Data[eLuckyWheelMain].OnShow == true)? Data[eLuckyWheelMain].Close():Data[eLuckyWheelMain].Open();};
	void		LuckyWheelStateclose() { Data[eLuckyWheelMain].OnShow = false; pSetCursorFocus = false; };
	int			LuckyWheelNumber;
	int m_LuckyWheelEnabled;
	int m_LuckyWheelWCoinC;
	int m_LuckyWheelWCoinP;
	int m_LuckyWheelGPCoin;
	int m_LuckyWheelTime;
	int			StartRoll;
	void        WindowsProTecno();
	
	//-- Minimizar MiniMapa
	void		MiniMapMini();
	//-- Mover MiniMapa
	bool		IsWorkZone(float X, float Y, float MaxX, float MaxY, bool a5 = false);
	void		DrawChangeResetWindow();
	bool		EventChangeResetWindow_Main(DWORD Event);
	bool		EventChangeResetWindow_Close(DWORD Event);		
	bool		EventChangeResetWindow_5(DWORD Event);
	bool		EventChangeResetWindow_10(DWORD Event);
	bool		EventChangeResetWindow_15(DWORD Event);
	bool		EventChangeResetWindow_20(DWORD Event);
	bool		EventChangeResetWindow_25(DWORD Event);
	//smith
	void	DrawSmithItem();
	void	OpenSmithItemWindow() { this->Data[eSMITH_MAIN].OnShow = true; };
	void	CloseSmithItemWindow() { this->Data[eSMITH_MAIN].OnShow = false; };
	bool	CheckSmithItemWindow() { return this->Data[eSMITH_MAIN].OnShow; };
	void	EventSmithItem_Main(DWORD Event);

	void TextDraw(int PosX, int PosY, int Width, int Arg5, int Color, int Arg7, int Align, HGDIOBJ Font, LPCTSTR Format, ...);
	void DrawText(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);

	void SwitchTuChan();
	//
	bool  Moving;
	float ultimoX;
	float ultimoY;
	float ultimoPTsearchY;
	float ultimoWareY;	
	short mX;
	short mY;
	//

private:
	
};
extern Interface gInterface;
