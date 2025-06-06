#include "StdAfx.h"
#include "Util.h"
#include "Import.h"
#include "GLFont.h"
#include "SEASON3B.h"
#include "UIControl.h"

GLFont g_pRenderText;
HFONT m_hFont;
HFONT m_hFontBold;
HFONT m_hFontBig;
HFONT m_hFontNum;

GLFont::GLFont( )
{
	this->ShadowFlower = false;
}

GLFont::~GLFont( )
{
}

HDC GLFont::GetFontHDC( )
{
	return hFontDC(g_Fontthis());
}

void GLFont::glCreateFont()
{
	char pszFaceName[32];
	GetPrivateProfileStringA("FontConfig", "FontNameFontName", "Arial", pszFaceName, sizeof(pszFaceName), ".\\Settings.ini");

	int FixFontSize = 12;
	switch ( *(DWORD*)0xE8C240 )
	{
		case 0:
			FixFontSize = 12;
			break;
		case 1:
			FixFontSize = 13;
			break;
		case 2:
			FixFontSize = 14;
			break;
		case 3:
			FixFontSize = 15;
			break;
		case 4:
			FixFontSize = 16;
			break;
	}

	m_hFont = CreateFont(FixFontSize, 0, 0, 0, FW_NORMAL, 0, 0, 0, 1u, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, NONANTIALIASED_QUALITY, DEFAULT_PITCH|FF_DONTCARE, pszFaceName);
	m_hFontBold = CreateFont(FixFontSize, 0, 0, 0, FW_BOLD, 0, 0, 0, 1u, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, NONANTIALIASED_QUALITY, DEFAULT_PITCH|FF_DONTCARE, pszFaceName);
	m_hFontBig = CreateFont(FixFontSize*2, 0, 0, 0, FW_BOLD, 0, 0, 0, 1u, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, NONANTIALIASED_QUALITY, DEFAULT_PITCH|FF_DONTCARE, pszFaceName);
	m_hFontNum = CreateFont(FixFontSize + 2, 0, 0, 0, FW_SEMIBOLD, 0, 0, 0, 1u, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, NONANTIALIASED_QUALITY, DEFAULT_PITCH|FF_DONTCARE, pszFaceName);
}

DWORD GLFont::GetTextColor() const
{
	return pRender_GetTextColor(g_Fontthis());
}
DWORD GLFont::GetBgColor() const
{
	return pRender_GetBGColor(g_Fontthis());
}

void GLFont::SetTextColor(BYTE byRed, BYTE byGreen, BYTE byBlue, BYTE byAlpha)
{
	pRender_SetTextColor1(g_Fontthis(), byRed, byGreen, byBlue, byAlpha);
}

void GLFont::SetTextColor(DWORD dwColor)
{
	pRender_SetTextColor2(g_Fontthis(), dwColor);
}

void GLFont::SetBgColor(BYTE byRed, BYTE byGreen, BYTE byBlue, BYTE byAlpha)
{
	pRender_SetBGColor1(g_Fontthis(), byRed, byGreen, byBlue, byAlpha);
}

void GLFont::SetBgColor(DWORD dwColor)
{
	pRender_SetBGColor2(g_Fontthis(), dwColor);
}

void GLFont::SetFont(HFONT hFont) 
{
	SelectObject(this->GetFontHDC(), hFont);
}

void GLFont::RenderText(int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth , int iBoxHeight , int iSort, OUT SIZE * lpTextSize)
{
	pRender_rendertext(g_Fontthis(), iPos_x, iPos_y, pszText, iBoxWidth, iBoxHeight, iSort, lpTextSize);
}

void GLFont::CRenderText(int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth , int iBoxHeight , int iSort, OUT SIZE * lpTextSize)
{
	this->ShadowFlower = true;
	this->typeshadow = 1;
	pRender_rendertext(g_Fontthis(), iPos_x, iPos_y, pszText, iBoxWidth, iBoxHeight, iSort, lpTextSize);
	this->ShadowFlower = false;
}

void GLFont::CRenderBoldText(int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth , int iBoxHeight , int iSort, OUT SIZE * lpTextSize)
{
	this->ShadowFlower = true;
	this->typeshadow = 2;
	pRender_rendertext(g_Fontthis(), iPos_x, iPos_y, pszText, iBoxWidth, iBoxHeight, iSort, lpTextSize);
	this->ShadowFlower = false;
}

void WriteTextShadow(int Texture,float x,float y,float Width,float Height,float u,float v,float uWidth,float vHeight,bool Scale,bool StartScale,float Alpha)
{
	if( g_pRenderText.ShadowFlower )
	{
		GLfloat ColorFont[4];
		glGetFloatv(GL_CURRENT_COLOR, ColorFont);

		glColor4f(0.0, 0.0, 0.0, 0.75);
		if( g_pRenderText.typeshadow == 1)
		{
			CRenderBitmaps(Texture, x - 0.5, y - 0.5, Width, Height, u, v, uWidth, vHeight, Scale, StartScale, Alpha);
			CRenderBitmaps(Texture, x - 0.5, y + 0.5, Width, Height, u, v, uWidth, vHeight, Scale, StartScale, Alpha);
			CRenderBitmaps(Texture, x + 0.5, y - 0.5, Width, Height, u, v, uWidth, vHeight, Scale, StartScale, Alpha);
			CRenderBitmaps(Texture, x + 0.5, y + 0.5, Width, Height, u, v, uWidth, vHeight, Scale, StartScale, Alpha);
		}
		else
		{
			CRenderBitmaps(Texture, x - 1.25, y - 1.25, Width, Height, u, v, uWidth, vHeight, Scale, StartScale, Alpha);
			CRenderBitmaps(Texture, x - 1.25, y + 1.25, Width, Height, u, v, uWidth, vHeight, Scale, StartScale, Alpha);
			CRenderBitmaps(Texture, x + 1.25, y - 1.25, Width, Height, u, v, uWidth, vHeight, Scale, StartScale, Alpha);
			CRenderBitmaps(Texture, x + 1.25, y + 1.25, Width, Height, u, v, uWidth, vHeight, Scale, StartScale, Alpha);
		}
		//--
		glColor4fv(ColorFont);
		CRenderBitmaps(Texture, x, y, Width, Height, u, v, uWidth, vHeight, Scale, StartScale, Alpha);
	}
	else
	{
		CRenderBitmaps(Texture, x, y, Width, Height, u, v, uWidth, vHeight, Scale, StartScale, Alpha);
	}
}

int m_exp;

void GLFont::SetFontChat(int thisa, HFONT hFont)
{
	pRender_SetTextSetFon(thisa, g_FontBold);
}

void GLFont::SetFontChatColorBG(int thisa, BYTE red, BYTE green, BYTE blue, BYTE alpha)
{
	//if(g_InputBox.ShadowChatLog)
	//{
	//	pRender_SetBGColor1(thisa, 0, 0, 0, 0);
	//}
	//else
	//{
	g_pRenderText.SetBgColor(0, 0, 0, 10);
	//}
	m_exp = 0;
}

void GLFont::SetFontChatColorBG_Exp(int thisa, BYTE red, BYTE green, BYTE blue, BYTE alpha)
{
	m_exp = 1;
	g_pRenderText.SetBgColor(0, 0, 0, 10);
}

int GLFont::CRenderTextChat(int thisa, int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth, int iBoxHeight, int iSort, OUT SIZE* lpTextSize)
{
	g_pRenderText.CRenderBoldText(iPos_x, iPos_y, pszText, iBoxWidth, iBoxHeight, iSort, lpTextSize);
	return 1;
}

int GLFont::CRenderTextChatExp(int thisa, int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth, int iBoxHeight, int iSort, OUT SIZE* lpTextSize)
{
	if(m_exp = 1) {iPos_x = 5;}
	g_pRenderText.CRenderBoldText(iPos_x, iPos_y, pszText, iBoxWidth, iBoxHeight, iSort, lpTextSize);
	return 1;
}

void GLFont::SetFontColorWisper(int thisa, BYTE red, BYTE green, BYTE blue, BYTE alpha)	//thi thầm
{
	g_pRenderText.SetTextColor(222, 130, 2, 0xFF);
}

void GLFont::SetFontColorSystem(int thisa, BYTE red, BYTE green, BYTE blue, BYTE alpha)	//he thống
{
	g_pRenderText.SetTextColor(81, 137, 255, 0xFF);
}

void GLFont::SetFontColorParty(int thisa, BYTE red, BYTE green, BYTE blue, BYTE alpha)	//party
{
	g_pRenderText.SetTextColor(255, 204, 25, 0xFF);
}

void GLFont::SetFontColorGuild(int thisa, BYTE red, BYTE green, BYTE blue, BYTE alpha)	//chat GUild 
{
	//pRender_SetTextColor1(thisa, 33, 194, 28, 0xFF);
	g_pRenderText.SetTextColor(0, 255, 255, 0xFF);
}

void GLFont::SetFontColorAlianza(int thisa, BYTE red, BYTE green, BYTE blue, BYTE alpha) //lien minh guild
{
	//pRender_SetTextColor1(thisa, 33, 194, 28, 0xFF);
	g_pRenderText.SetTextColor(255, 234, 0, 0xFF);
}

void GLFont::SetFontColorGens(int thisa, BYTE red, BYTE green, BYTE blue, BYTE alpha)	//gia tộc
{
	g_pRenderText.SetTextColor(33, 194, 28, 0xFF);
	//pRender_SetTextColor1(thisa, 245, 161, 30, 0xFF);
}

void GLFont::Init( )
{

	SetCompleteHook(0xE8, 0x00420814, &WriteTextShadow);
	SetCompleteHook(0xE8, 0x00788C1B, &GLFont::SetFontChat);
	//--
	SetCompleteHook(0xE8, 0x007890A4, &GLFont::CRenderTextChat);
	SetCompleteHook(0xE8, 0x007890ED, &GLFont::CRenderTextChatExp);
	//--
	SetCompleteHook(0xE8, 0x00788CBE, &GLFont::SetFontChatColorBG_Exp);
	SetCompleteHook(0xE8, 0x00788C7E, &GLFont::SetFontChatColorBG);
	SetCompleteHook(0xE8, 0x00788D04, &GLFont::SetFontChatColorBG);
	SetCompleteHook(0xE8, 0x00788D47, &GLFont::SetFontChatColorBG);
	SetCompleteHook(0xE8, 0x00788D96, &GLFont::SetFontChatColorBG);
	SetCompleteHook(0xE8, 0x00788DDC, &GLFont::SetFontChatColorBG);
	SetCompleteHook(0xE8, 0x00788E22, &GLFont::SetFontChatColorBG);
	SetCompleteHook(0xE8, 0x00788E68, &GLFont::SetFontChatColorBG);
	SetCompleteHook(0xE8, 0x00788EA8, &GLFont::SetFontChatColorBG);
	SetCompleteHook(0xE8, 0x00788F1E, &GLFont::SetFontChatColorBG);
	//--
	SetCompleteHook(0xE8, 0x00788C95, &GLFont::SetFontColorWisper);
	SetCompleteHook(0xE8, 0x00788CDB, &GLFont::SetFontColorSystem);
	SetCompleteHook(0xE8, 0x00788DAD, &GLFont::SetFontColorParty);
	SetCompleteHook(0xE8, 0x00788DF3, &GLFont::SetFontColorGuild);
	SetCompleteHook(0xE8, 0x00788E7F, &GLFont::SetFontColorAlianza);
	SetCompleteHook(0xE8, 0x00788EFE, &GLFont::SetFontColorGens);
	
}