#include "stdafx.h"
#include "JCEntryproy.h"
#include "JCButton.h"
#include "Import.h"
#include "Util.h"
#include "Common.h"

JCButton::JCButton( )
{
	this->JCRenderX = 0;
	this->JCRenderY = 0;
	this->JCWidth   = 15.0;
	this->JCHeight  = 15.0;
	ZeroMemory(this->JCtext, sizeof(this->JCtext));
	wsprintf(this->JCtext, "new JCButton");
}

JCButton::~JCButton()
{

}

void JCButton::SetText(char * Unknown)
{
	ZeroMemory(this->JCtext, sizeof(this->JCtext));
	wsprintf(this->JCtext, Unknown);
}

void JCButton::LoadAction( int Pointer, int Action )
{
	this->JCActive = Pointer;
	this->JCAction = Action;

	switch ( this->JCAction )
	{
	/*case JCDINAMIC_EFFECT:
		{
		this->JCActive = GetPrivateProfileIntA("AntiLag", "DisableDynamicEffect", 0, "./Settings.ini");
		SetByte((0x0074CD80 + 2), ( this->JCActive == 0 ) ? 1 : 0 );
		}
		break;
	case JCSTATIC_EFFECT:
		{
		this->JCActive = GetPrivateProfileIntA("AntiLag", "DisableStaticEffect", 0, "./Settings.ini");
		SetByte((0x00771359 + 3), ( this->JCActive == 0 ) ? 1 : 0 );
		}
		break;
	case JCSKILL_EFFECT:
		{
		this->JCActive = GetPrivateProfileIntA("AntiLag", "DisableSkillEffect", 0, "./Settings.ini");
		 //SetByte((0x006D9113 + 3), ( DisableSkillEffect == 0 ) ? 1 : 0 );
		SetDword((0x0072D1BA + 3), ( this->JCActive == 0 ) ? 0 : 500 );
		}
		break;
	case JCITEMGLOW_EFFECT:
		{
		this->JCActive = GetPrivateProfileIntA("AntiLag", "DisableGlowEffect", 0, "./Settings.ini");
		}
		break;
	case JCOBJECTSHADOW:
		{
		this->JCActive = GetPrivateProfileIntA("AntiLag", "DisableShadow", 0, "./Settings.ini");
		DisableShadow = this->JCActive;
		}
		break;
	case JCOBJECTWORLDHIDE:
		{
		this->JCActive = GetPrivateProfileIntA("AntiLag", "DisableObject", 0, "./Settings.ini");
		SetByte(0x005DE2B3 + 1, ( this->JCActive == 0 ) ? 0x85 : 0x84 ); // Ocultamos objetos del mapa
		}
		break;*/
	case NONE:
		break;
	case DEFAULT:
		break;
	}

}

void JCButton::SetBounds(JCRECT Bound)
{
	this->JCRenderX = Bound.x;
	this->JCRenderY = Bound.y;
	this->JCWidth   = Bound.w;
	this->JCHeight  = Bound.h;
}

void JCButton::SetBounds(float x, float y, float Width, float Height)
{
	this->JCRenderX = x;
	this->JCRenderY = y;
	this->JCWidth   = Width;
	this->JCHeight  = Height;
}

int JCButton::SetVisible( )
{
	
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu); //-- eWhite

	pDrawText(pTextThis(), this->JCRenderX + 18, this->JCRenderY + 3, this->JCtext, 0, 0, (LPINT)1, 0);
	
	if ( pCheckMouseOver(this->JCRenderX, this->JCRenderY, this->JCWidth, this->JCHeight) && *(BYTE*) 0x8793386 )
	{
		RenderBitmap(61542, this->JCRenderX, this->JCRenderY, this->JCWidth, this->JCHeight, 0.0, 0.268338412, 0.7135385275, 0.2283384204, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61542, this->JCRenderX, this->JCRenderY, this->JCWidth, this->JCHeight, 0.0, 0.02, 0.7135385275, 0.2283384204, 1, 1, 0);
	}

	return this->JCActive;
}

void JCButton::SetSize(float Width, float Height)
{
	this->JCWidth  = Width;
	this->JCHeight = Height;
}

void JCButton::SetLocation(float x, float y)
{
	this->JCRenderX = x;
	this->JCRenderY = y;
}

void JCButton::SetLocationX(float x)
{
	this->JCRenderX = x;
}

void JCButton::SetLocationY(float y)
{
	this->JCRenderY = y;
}

char * JCButton::GetText( )
{
	return this->JCtext;
}

JCRECT JCButton::GetBounds( )
{
	JCRECT Bounds;
	Bounds.x = this->JCRenderX;
	Bounds.y = this->JCRenderY;
	Bounds.w = this->JCWidth;
	Bounds.h = this->JCHeight;

	return Bounds;
}

void JCButton::mouseClicked( )
{
	if ( pCheckMouseOver(this->JCRenderX, this->JCRenderY, this->JCWidth, this->JCHeight) && *(BYTE*) 0x8793386 )
	{
		if( GetTickCount() >= this->JCTimerEvent + 300 )
		{
			if ( this->JCActive )
			{
				this->JCActive = 0;
			}
			else
			{
				this->JCActive = 1;
			}
			this->ActionListener( );
			this->JCTimerEvent = GetTickCount();
		}
		PlayBuffer(25, 0, 0);
	}
}

void JCButton::mouseEntered( )
{
}

void JCButton::ActionListener( )
{
	switch ( this->JCAction )
	{
	case JCDINAMIC_EFFECT:
		{
		WritePrivateProfileStringA("AntiLag","DisableDynamicEffect", ( this->JCActive != 0) ? "1": "0","./Settings.ini");
		SetByte((0x0074CD80 + 2), ( this->JCActive == 0 ) ? 1 : 0 );
		}
		break;
	case JCSTATIC_EFFECT:
		{
		WritePrivateProfileStringA("AntiLag","DisableStaticEffect", ( this->JCActive != 0) ? "1": "0","./Settings.ini");
		SetByte((0x00771359 + 3), ( this->JCActive == 0 ) ? 1 : 0 );
		}
		break;
	case JCSKILL_EFFECT:
		{
		WritePrivateProfileStringA("AntiLag","DisableSkillEffect", ( this->JCActive != 0) ? "1": "0","./Settings.ini");
		SetDword((0x0072D1BA + 3), ( this->JCActive == 0 ) ? 0 : 500 ); //SetByte((0x006D9113 + 3), ( DisableSkillEffect == 0 ) ? 1 : 0 );
		}
		break;
	case JCITEMGLOW_EFFECT:
		{
		WritePrivateProfileStringA("AntiLag","DisableGlowEffect", ( this->JCActive != 0) ? "1": "0","./Settings.ini");
		}
		break;
	case JCOBJECTSHADOW:
		{
		WritePrivateProfileStringA("AntiLag","DisableShadow", ( this->JCActive != 0) ? "1": "0","./Settings.ini");
		DisableShadow = this->JCActive;
		}
		break;
	case JCOBJECTWORLDHIDE:
		{
		WritePrivateProfileStringA("AntiLag","DisableObject", ( this->JCActive != 0) ? "1": "0","./Settings.ini");
		//SetByte(0x0057D4F5 + 1, ( this->JCActive == 0 ) ? 0 : 1 ); // Mostramos los monster
		SetByte(0x005DE2B3 + 1, ( this->JCActive == 0 ) ? 0x85 : 0x84 ); // Ocultamos objetos del mapa
		}
		break;
	case NONE:
		break;
	case DEFAULT:
		break;
	}
}