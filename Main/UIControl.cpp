#include "StdAfx.h"
#include "SEASON3B.h"
#include "Util.h"
#include "UIControl.h"

CTextFont g_pRenderText2;

CTextFont::CTextFont( )
{
}


CTextFont::~CTextFont( )
{
}

HDC CTextFont::GetFontHDC( )
{
	return hFontDC(g_Fontthis());
}

DWORD CTextFont::GetTextColor() const
{
	return pRender_GetTextColor(g_Fontthis());
}
DWORD CTextFont::GetBgColor() const
{
	return pRender_GetBGColor(g_Fontthis());
}

void CTextFont::SetTextColor(BYTE byRed, BYTE byGreen, BYTE byBlue, BYTE byAlpha)
{
	pRender_SetTextColor1(g_Fontthis(), byRed, byGreen, byBlue, byAlpha);
}

void CTextFont::SetTextColor(DWORD dwColor)
{
	pRender_SetTextColor2(g_Fontthis(), dwColor);
}

void CTextFont::SetBgColor(BYTE byRed, BYTE byGreen, BYTE byBlue, BYTE byAlpha)
{
	pRender_SetBGColor1(g_Fontthis(), byRed, byGreen, byBlue, byAlpha);
}

void CTextFont::SetBgColor(DWORD dwColor)
{
	pRender_SetBGColor2(g_Fontthis(), dwColor);
}

void CTextFont::SetFont(HFONT hFont) 
{
	SelectObject(this->GetFontHDC(), hFont);
}

void CTextFont::RenderText(int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth , int iBoxHeight , int iSort, OUT SIZE * lpTextSize)
{
	pRender_rendertext(g_Fontthis(), iPos_x, iPos_y, pszText, iBoxWidth, iBoxHeight, iSort, lpTextSize);
}

float WConvertX(float x)
{
	return (float)x / g_fScreenRate_x * g_fScreenRate_y;
}

void CTextFont::WRenderText(int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth , int iBoxHeight , int iSort, OUT SIZE * lpTextSize)
{
	pRender_rendertext(g_Fontthis(), (int)WConvertX(iPos_x), iPos_y, pszText, (int)WConvertX(iBoxWidth), iBoxHeight, iSort, lpTextSize);
}

void CTextFont::CRenderText(int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth , int iBoxHeight , int iSort, OUT SIZE * lpTextSize)
{
	this->ShadowFlower = true;
	this->typeshadow = 1;
	pRender_rendertext(g_Fontthis(), iPos_x, iPos_y, pszText, iBoxWidth, iBoxHeight, iSort, lpTextSize);
	this->ShadowFlower = false;
}

void CTextFont::CRenderBoldText(int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth , int iBoxHeight , int iSort, OUT SIZE * lpTextSize)
{
	this->ShadowFlower = true;
	this->typeshadow = 2;
	pRender_rendertext(g_Fontthis(), iPos_x, iPos_y, pszText, iBoxWidth, iBoxHeight, iSort, lpTextSize);
	this->ShadowFlower = false;
}

/*void WriteTextShadow(int Texture,float x,float y,float Width,float Height,float u,float v,float uWidth,float vHeight,bool Scale,bool StartScale,float Alpha)
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
}*/

void CTextFont::Init( )
{
	//SetCompleteHook(0xE8, 0x00420814, &WriteTextShadow);
}
