#pragma once
//OpenGL
#include <gl\GL.h>
#pragma comment(lib,"Opengl32.lib")
//timeGetTime
#include <Mmsystem.h>
#pragma comment(lib,"Winmm.lib")

#define LoadBitmapA									((int(__cdecl*)(char * Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6)) 0x00772330)
#define pWinWidth									*(GLsizei*)0x0E61E58
#define pWinHeight									*(GLsizei*)0x0E61E5C
#define BindTexture									((bool(__cdecl*)(int a1)) 0x00635CF0)
#define RenderBitmap								((void(__cdecl*)(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, char a10, char a11, float a12)) 0x00637C60)
#define m_pgbLoding_Create							((int(__thiscall*)(void *This, int nGaugeWidth, int nGaugeHeight, int nGaugeTexID, RECT* prcGauge, int nBackWidth, int nBackHeight, int nBackTexID, bool bShortenLeft, float fScaleX, float fScaleY)) 0x00407290)
#define BeginOpengl									((int(__cdecl*)(GLint a1, int a2, GLsizei width, GLsizei height)) 0x00636480)
#define BeginBitmap									((void(*)()) 0x637770)
#define m_pgbLoding_SetValue						((int(__thiscall*)(int This, unsigned int a2, unsigned int a3)) 0x00407650)
#define m_pgbLoding_Render							((void(__thiscall*)(int This)) 0x00407970)
#define EndBitmap									((void(*)())0x00637870)
#define EndOpengl									((void(*)()) 0x6366F0)
#define EnableAlphaTest								((void(__cdecl*)(char a1)) 0x00635FD0)

class CGlobalBitmapWide
{
public:
	bool	GameResolution();
//	float	num();
//	int		ConvertX(float num);
//	int		ConvertY(float num);
	void	cRenderBitmap(int TextureID, float X, float Y, float Width, float Height, float DropX, float DropY, float ScaleX, float ScaleY, char a13, char a14, float a15);
//	bool	CheckMouseIn(int x, int y, int width, int height);
private:
	
};
extern CGlobalBitmapWide gCGlobalBitmapWide;

class CUIMng
{
public:
	void Load();

	static void __thiscall CpgbLoding(void *This, int a2, int a3, int a4, int a5, int a6, int a7, int a8, char a9, float a10, float a11);

	static void __thiscall RenderTitleSceneUI(int This, HDC hDC, DWORD dwNow, DWORD dwTotal);

	static void CLoadBitmap(char * Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6);

private:
	
};
extern CUIMng gCUIMng;