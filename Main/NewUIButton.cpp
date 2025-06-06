#include "StdAfx.h"
#include "NewUIButton.h"


CNewUIButton::CNewUIButton( )
{
	this->isCreate = false;
	memset(&this->thisa, 0, sizeof(this->thisa));
}


CNewUIButton::~CNewUIButton( )
{
	delete []this->thisa;
}

void CNewUIButton::Construct( )
{
	if(!this->isCreate)
	{
		NewUICreateButton(this->thisa, 172, 1, InitializeButton, DestroyButton);
		this->isCreate = true;
	}
}

void CNewUIButton::ChangeText(char * btname)
{
	int std_String[7];
	ChartoString(&std_String, btname);
	NewUIButtonChangeText(this->thisa, std_String[0], std_String[1], std_String[2], std_String[3], std_String[4], std_String[5], std_String[6]);
}

void CNewUIButton::ChangeButtonImgState(bool imgregister, int imgindex, bool overflg, bool isimgwidth, bool bClickEffect)
{
	NewUIChangeButtonImgState(this->thisa, imgregister, imgindex, overflg, isimgwidth, bClickEffect);
}

void CNewUIButton::CButtonInfo( int x, int y, int sx, int sy )
{
	NewUIChangeButtonInfo(this->thisa,x, y, sx, sy);
}

void CNewUIButton::ChangeImgColor(BUTTON_STATE eventstate, unsigned int color)
{
	NewUIButtonChangeImgColor(this->thisa, eventstate, color);
}

int CNewUIButton::GetBTState( )
{
	return NewUIButtonGetBTState(this->thisa);
}

bool CNewUIButton::UpdateMouseEvent( )
{
	return NewUIUpdateMouseEvent(this->thisa);
}

bool CNewUIButton::Render( bool RendOption )
{
	return NewUIButtonRender(this->thisa, RendOption);
}
