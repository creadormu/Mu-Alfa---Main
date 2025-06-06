#pragma once

#define MAX_OBJECT			250
#define MAX_WIN_WIDTH		640
#define MAX_WIN_HEIGHT		480
#define MAX_WINDOW_EX		100
#define pDrawInterfaceNumBer   ((double(__stdcall*)(float X, float Y, int num, float size)) 0x854FE0)



class newInterface
{
public:
	void		Load();
	//-- post item
	static void DrawItemIMG(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
	static void Work2();
    static void DrawChat ( int mode, char* character, char* message );
    static void DrawItemToolTipText ( void * item, int x, int y );
    void * item_post_;
    DWORD last_tickcount_view_;
private:
	
};
extern newInterface gPostInterface;