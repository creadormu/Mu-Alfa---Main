#include "stdafx.h"
#include "CUIMng.h"
#include "Util.h"
#include "Protect.h"
#include "AdvancedFPSManager.h"
#include "ImprovedHackCheck.h"
#include "OptimizedShaders.h"


// ---------------------------------------------------------------------------------------------
CUIMng gCUIMng;
CGlobalBitmapWide gCGlobalBitmapWide;
// ---------------------------------------------------------------------------------------------

void CUIMng::CLoadBitmap(char* Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6)
{

	LoadBitmapA("Interface\\KMUA2_Loading.tga", 531123, 0x2601, 0x2901, 1, 0);
	LoadBitmapA("Interface\\KMUA2_BarFrame.tga", 531124, 0x2601, 0x2901, 1, 0);
	//LoadBitmapA("Interface\\KMUA2_Back01.jpg", 531122, 0x2600, 0x2900, 1, 0);
	//LoadBitmapA("Interface\\KMUA2_Back02.jpg", 531125, 0x2600, 0x2900, 1, 0);
	LoadBitmapA("Interface\\KMUA2_Porcento.tga", 531126, 0x2601, 0x2901, 1, 0);
	LoadBitmapA("Interface\\newui_number1.tga", 31337, 9729, 10496, 1, 0);

	if (gProtect.m_MainInfo.EnableLoading == 2)
	{
		LoadBitmapA("Interface\\KMUA2_Back03.jpg", 531122, 0x2600, 0x2900, 1, 0);
		LoadBitmapA("Interface\\KMUA2_Back04.jpg", 531125, 0x2600, 0x2900, 1, 0);
		LoadBitmapA("Interface\\KMUA2_Bar.jpg", 31122, 0x2601, 0x2901, 1, 0);

	}

	if (gProtect.m_MainInfo.EnableLoading == 1)
	{
		LoadBitmapA("Interface\\KMUA2_Back01.jpg", 531122, 0x2600, 0x2900, 1, 0);
		LoadBitmapA("Interface\\KMUA2_Back02.jpg", 531125, 0x2600, 0x2900, 1, 0);
		LoadBitmapA("Interface\\KMUA2_Bar.jpg", 31122, 0x2601, 0x2901, 1, 0);

	}

	if (gProtect.m_MainInfo.EnableLoading == 3)
	{
		LoadBitmapA("Interface\\KMUA2_Back05.jpg", 531122, 0x2600, 0x2900, 1, 0);
		LoadBitmapA("Interface\\KMUA2_Back06.jpg", 531125, 0x2600, 0x2900, 1, 0);
		LoadBitmapA("Interface\\KMUA2_Bar6.jpg", 31122, 0x2601, 0x2901, 1, 0);
	}

	if (gProtect.m_MainInfo.EnableLoading == 4)
	{
		LoadBitmapA("Interface\\KMUA2_Back07.jpg", 531122, 0x2600, 0x2900, 1, 0);
		LoadBitmapA("Interface\\KMUA2_Back08.jpg", 531125, 0x2600, 0x2900, 1, 0);
		LoadBitmapA("Interface\\KMUA2_Bar6.jpg", 31122, 0x2601, 0x2901, 1, 0);
	}



}


bool CGlobalBitmapWide::GameResolution()
{
	return *(int*)0x0E8C240 == 4 || *(int*)0x0E8C240 == 8 || *(int*)0x0E8C240 == 7 || *(int*)0x0E8C240 == 6 || *(int*)0x0E8C240 == 5;
}

void CGlobalBitmapWide::cRenderBitmap(int TextureID, float X, float Y, float Width, float Height, float DropX, float DropY, float ScaleX, float ScaleY, char a13, char a14, float a15)
{
	int i; // ST1C_4@5
	float v33; // ST1C_4@5
	float TextureCoord[4][2];
	float VertexCoord[4][2];

	if (gCGlobalBitmapWide.GameResolution())
	{
		if (a14)
		{
			X = (float)((double)(unsigned int)pWinWidth * X / 845.0);
			Y = (float)((double)(unsigned int)pWinHeight * Y / 480.0);
		}
		if (a13)
		{
			Width = (float)((double)(unsigned int)pWinWidth * Width / 845.0);
			Height = (float)((double)(unsigned int)pWinHeight * Height / 480.0);
		}
	}
	else
	{
		if (a14)
		{
			X = (float)((double)(unsigned int)pWinWidth * X / 640.0);
			Y = (float)((double)(unsigned int)pWinHeight * Y / 480.0);
		}
		if (a13)
		{
			Width = (float)((double)(unsigned int)pWinWidth * Width / 640.0);
			Height = (float)((double)(unsigned int)pWinHeight * Height / 480.0);
		}



	}

	v33 = (double)pWinHeight - Y;

	BindTexture(TextureID);

	VertexCoord[0][0] = X;
	VertexCoord[0][1] = v33;

	VertexCoord[1][0] = X;
	VertexCoord[1][1] = v33 - Height;

	VertexCoord[2][0] = X + Width;
	VertexCoord[2][1] = v33 - Height;

	VertexCoord[3][0] = X + Width;
	VertexCoord[3][1] = v33;

	TextureCoord[0][0] = DropX;
	TextureCoord[0][1] = DropY;

	TextureCoord[1][0] = DropX;
	TextureCoord[1][1] = DropY + ScaleY;

	TextureCoord[2][0] = DropX + ScaleX;
	TextureCoord[2][1] = DropY + ScaleY;

	TextureCoord[3][0] = DropX + ScaleX;
	TextureCoord[3][1] = DropY;

	glBegin(GL_TRIANGLE_FAN);

	for (i = 0; i < 4; ++i)
	{
		if (a15 > 0.0)
			glColor4f(1.0, 1.0, 1.0, a15);

		glTexCoord2f(TextureCoord[i][0], TextureCoord[i][1]);
		glVertex2f(VertexCoord[i][0], VertexCoord[i][1]);

		if (a15 > 0.0)
			glColor4f(1.0, 1.0, 1.0, 1.0);
	}
	glEnd();
}

float CRenderNumber(float x, float y, int iNum, float fScale)
{
	EnableAlphaTest(1);

	float width, height;

	if (fScale < 0.3f)
	{
		return x;
	}

	width = 12.f * (fScale - 0.3f);
	height = 16.f * (fScale - 0.3f);

	char strText[32];
	itoa(iNum, strText, 10);
	int iLength = (int)strlen(strText);

	x -= width * iLength / 2;

	for (int i = 0; i < iLength; ++i)
	{
		float fU = (float)(strText[i] - 48) * 12.f / 128.f;
		RenderBitmap(31337, x, y, width, height, fU, 0.f, 12.f / 128.f, 14.f / 16.f, 1, 1, 0.0);
		x += width * 0.8f;
	}
	RenderBitmap(531126, x, y, width + 3, height, 0.f, 0.f, 9.f / 16.f, 14.f / 16.f, 1, 1, 0.0);

	return x;
}

void CUIMng::CpgbLoding(void* This, int a2, int a3, int a4, int a5, int a6, int a7, int a8, char a9, float a10, float a11)
{
	RECT rc = { -36, 4, 656 + 36, 8 };
	m_pgbLoding_Create(This, 4, 15, 31122, &rc, a6, a7, a8, a9, a10, a11);
}

void CUIMng::RenderTitleSceneUI(int This, HDC hDC, DWORD dwNow, DWORD dwTotal)
{
	float WH, rate, SizeNew, Center, Porcento;
	double AnimX, AnimY;

	BeginOpengl(0, 0, 640, 480);
	glAlphaFunc(GL_GREATER, 0.0f);
	glClear(0x4100u);
	BeginBitmap();
	m_pgbLoding_SetValue(*(DWORD*)(This + 37256), dwNow, dwTotal);

	if (gCGlobalBitmapWide.GameResolution())
	{
		Center = 0.0;
	}
	else
	{
		Center = -107;
	}

	gCGlobalBitmapWide.cRenderBitmap(531122, Center, -1.0, 427, 480, 0, 0, 1.0, 1.0, 1, 1, 0.0);//Back
	gCGlobalBitmapWide.cRenderBitmap(531125, Center + 427, -1.0, 427, 480, 0, 0, 1.0, 1.0, 1, 1, 0.0);//Back

	RenderBitmap(531123, 0.0, 406.0, 640.0, 74.0, 0, 0, 1.0, 0.94, 1, 1, 0.0);//Loading Back

	m_pgbLoding_Render(*(DWORD*)(This + 37256));

	WH = 0.25;
	int Anim = (int)(timeGetTime() * 0.5f) % 600 / 40;
	AnimX = (double)(Anim % 4) * WH;
	AnimY = (double)(Anim / 4) * WH;
	rate = 580.f / (float)dwTotal;
	SizeNew = rate * dwNow;
	RenderBitmap(531124, SizeNew - 27, 391.0, 81.0, 81.0, AnimX, AnimY, WH, WH, 1, 1, 0.0);//Bar Frame

	glColor3f(0.84, 0.85, 0.86);
	rate = 100.f / (float)dwTotal;
	Porcento = rate * dwNow;
	CRenderNumber(590, 454, Porcento, 1.0);
	glColor3f(1.0, 1.0, 1.0);

	glAlphaFunc(GL_GREATER, 0.25f);
	EndBitmap();
	EndOpengl();
	glFlush();
	SwapBuffers(hDC);

	//gAdvancedFPSManager.Update();

}

void CUIMng::Load()
{
	SetCompleteHook(0xE8, 0x004D5691, this->CLoadBitmap);
	SetCompleteHook(0xE8, 0x00483246, this->CpgbLoding);
	SetCompleteHook(0xE9, 0x004833D0, this->RenderTitleSceneUI);
	SetDword((DWORD)0x004D562C + 1, (DWORD)"Interface\\none.tga");
}