#pragma once
// ---------------------------------------------------------------------------------------------
#define LoadBitmapA			((int(__cdecl*)(char * Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6)) 0x00772330)
#define MUHELPER_STRUC		0x00E8CB7C
#define EnableAlphaTest				((void(__cdecl*)(char a1)) 0x00635FD0)
#define World								*(int*)0x00E61E18
#define PlayBuffer			((signed int(__cdecl*)(int a1, int a2, int a3)) 0x006D6C20)
#define RenderImage			((void(__cdecl*)(DWORD, float, float, float, float)) 0x00790B50)
#define RenderImage2		((int(__cdecl*)(int a1, float a2, float a3)) 0x00790C20)

//--------
#define pNIDrawGUI				((void(__cdecl*)(DWORD ModelID, float PosX, float PosY, float Width, float Height, float SourceX, float SourceY, float ScaleX, float ScaleY, bool Scale, bool Arg11, float Arg12)) 0x637C60)
#define pMapName				((char*(__cdecl*)(signed int mapNumber)) 0x5D2C10)
#define pMUHelperStat			*(bool*)((*(DWORD*)0x00E8CB7C) + 0x8)
#define DelaySwitchServer		5000
#define scale_ratio				1.710526315789474
#define scale_width				scale_ratio / pWinWidthReal
#define scale_height			scale_ratio / pWinHeightReal
#define resizeGuiRate			1.875
#define resizeGuiScaleRateX		(float)*(DWORD*)MAIN_RESOLUTION_X / 800.0f
#define resizeGuiScaleRateY		(float)*(DWORD*)MAIN_RESOLUTION_Y / 600.0f
#define resizeGuiRateX			resizeGuiRate * resizeGuiScaleRateX
#define resizeGuiRateY			resizeGuiRate * resizeGuiScaleRateY

struct textSize
{
	float	width;
	float	height;
	float	resize_width;
	float	resize_height;
};

struct GUIresource
{
	DWORD	ID;
	float	CellWidth;
	float	CellHeight;
	float	SourceX;
	float	SourceY;
	float	SourceWidth;
	float	SourceHeight;
	float	ScaleX;
	float	ScaleY;
	DWORD	TextColor;
	DWORD	TextBGColor;

	GUIresource(DWORD a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8 = 0, float a9 = 0, DWORD a10 = 0x999999FF, DWORD a11 = 0x0)
	{
		ID = a1;
		CellWidth = a2;
		CellHeight = a3;
		SourceX = a4;
		SourceY = a5;
		SourceWidth = a6;
		SourceHeight = a7;
		ScaleX = a8;
		ScaleY = a9;
		TextColor = a10;
		TextBGColor = a11;
	}
};

struct GUIButton
{
	float X;
	float Y;
	float Width;
	float Height;
	float Max_X;
	float Max_Y;
	bool  clickDown;
	BYTE  state;
	int	  delay;
	DWORD lastActionTime;

	GUIButton()
	{
		clickDown = false;
		state = 0;
		lastActionTime = GetTickCount();
	}

	GUIButton(float a1, float a2, float a3, float a4, int a5)
	{
		clickDown = false;
		state = 0;
		lastActionTime = GetTickCount();
		X = a1;
		Y = a2;
		Width = a3;
		Height = a4;
		Max_X = X + Width;
		Max_Y = Y + Height;
		delay = a5;
		lastActionTime = GetTickCount();
	}
};

struct GUIbutton
{
	GUIButton	*data;
	GUIresource *normalFrame;
	GUIresource *hoverFrame;
	GUIresource *clickedFrame;
	GUIresource *disabledFrame;
};

struct GUIObj
{
	float X;
	float Y;
	float Default_X;
	float Default_Y;
	float curX;
	float curY;
	float Width;
	float Height;
	float Max_X;
	float Max_Y;
	bool  isFocus;
	bool onShow;
	bool dragging;
	bool allowDrag;
	bool scaleUp;
	BYTE state;
	DWORD lastActionTime;

	GUIObj() {
		onShow = false;
		dragging = false;
		lastActionTime = GetTickCount();
		state = 0;
		isFocus = false;
		allowDrag = false;
		scaleUp = true;
	}

	GUIObj(float a1, float a2, float a3, float a4, bool a5 = false, bool a6 = true) {
		onShow = false;
		dragging = false;
		lastActionTime = GetTickCount();
		state = 0;
		isFocus = false;
		allowDrag = false;
		scaleUp = true;

		X = a1;
		Y = a2;
		Default_X = a1;
		Default_Y = a2;
		Width = a3;
		Height = a4;
		Max_X = X + Width;
		Max_Y = Y + Height;
		allowDrag = a5;
		scaleUp = a6;
	}

};

// ---------------------------------------------------------------------------------------------

class CMacroUIEx
{
public:
	CMacroUIEx();
	~CMacroUIEx();
	void Load();
	//static void		LoadImages();
	static void		RenderFrame(int *This);
	static void		RenderHelperFrame(int *This);
	void			Button(DWORD Event);
	//--------
	void		ButtonNew(DWORD Event);
	bool		isLockCursor();
	float		resizeX(float);
	float		resizeY(float);
	void		DrawGui(short ObjID, float X, float Y, float W, float H, float SourceX = 0, float SourceY = 0, float SourceW = 1024, float SourceH = 512, float ScaleW = 1.5f, float ScaleH = 1.5f, bool ScaleUp = 0);
	void		DrawToolTipBG(float, float, float, float);
	bool		IsWorkZone(float, float, float, float);
	void		DrawFrame(DWORD ModelID, float X, float Y, float W, float H, float SourceX = 0, float SourceY = 0, float SourceW = 1024, float SourceH = 512, float ScaleW = 1.5f, float ScaleH = 1.5f, bool ScaleUp = 0);
	bool		Drawbutton(GUIbutton*, float, float, LPCSTR, ...);
	bool		Drawbutton(GUIbutton*, LPCSTR, ...);

	void		DrawWindowBG(float, float);


	bool		isSwitchServer;
	DWORD		lastSwitch;
	bool		macroSwitchServerHoving;

	GUIbutton	*macroSwitchServer;
	GUIbutton	*macroSwitchServerHover;
	GUIbutton	*macroSwitchServerSliderUp;
	GUIbutton	*macroSwitchServerSliderDown;

	GUIbutton		*macroLog;
	GUIbutton		*macroConfig;
	GUIbutton		*macroAuto;
	GUIbutton		*macroPauseAuto;

	//custom list
	GUIObj		*CustomList;
/*	GUIbutton	*CustomButton[8];
	GUIbutton	*CustomClose;*/

	/*Windows X803*/
	GUIbutton   *CloseWindowsUP;

	textSize	getTextSize(char*);
	//--------
private:
	
};
extern CMacroUIEx gCMacroUIEx;
// ---------------------------------------------------------------------------------------------