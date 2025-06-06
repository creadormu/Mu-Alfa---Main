#pragma once
//-- Constructor
#define InitializeButton								((void(__thiscall*)(void *thisa)) 0x00779150)
#define DestroyButton									((void(__thiscall*)(void *thisa)) 0x00779250)
#define NewUICreateButton								((void(__stdcall*)(BYTE *thisa,int ObjSize, int ObjCount, void (__thiscall *)(void *) , void (__thiscall *)(void *) )) 0x009CFA13)
//--
#define NewUIChangeButtonInfo							((void(__thiscall*)(BYTE *thisa, int x, int y, int sx, int sy)) 0x00779410)
#define NewUIChangeButtonImgState						((void(__thiscall*)(BYTE *thisa, bool imgregister, int imgindex, bool overflg, bool isimgwidth, bool bClickEffect)) 0x00779350)
#define NewUIUpdateMouseEvent							((bool(__thiscall*)(BYTE *thisa)) 0x00779860)
#define NewUIButtonChangeColor							((int(__thiscall*)(BYTE *thisa, DWORD Color)) 0x007C1C80)
#define NewUIButtonRender								((bool(__thiscall*)(BYTE *thisa, bool RendOption)) 0x007798F0)
#define NewUIButtonChangeImgColor						((void(__thiscall*)(BYTE *thisa,int eventstate, unsigned int color))0x00779740)
#define NewUIButtonSetFont								((void(__thiscall*)(BYTE *thisa, HFONT hFont))0x007909D0)
#define NewUIButtonChangeText							((void(__thiscall*)(BYTE *thisa, int a1, int a2, int a3, int a4, int a5, int a6, int a7))0x00790970)
#define ChartoString									((void *(__thiscall*)(void *thisa, char *a4))0x00409A50)
#define NewUIButtonGetBTState							((int(__thiscall*)(BYTE * thisa))0x0077E610)

class CNewUIButton
{
public:
	CNewUIButton( );
	virtual ~CNewUIButton( );

	enum BUTTON_STATE
	{
		BUTTON_STATE_UP = 0,
		BUTTON_STATE_DOWN,
		BUTTON_STATE_OVER,
	};

	void Construct();
	bool UpdateMouseEvent();
	void ChangeText(char * btname);
	bool Render(bool RendOption = false);
	void CButtonInfo( int x, int y, int sx, int sy );
	void ChangeImgColor(BUTTON_STATE eventstate, unsigned int color);
	void ChangeButtonImgState(bool imgregister, int imgindex, bool overflg = false, bool isimgwidth = false, bool bClickEffect = false);
	int GetBTState( );
private:
	BYTE thisa[172];
	bool isCreate;
};

