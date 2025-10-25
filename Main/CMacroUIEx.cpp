#include "stdafx.h"
#include "CMacroUIEx.h"
#include "Util.h"
#include "Offset.h"
#include "Import.h"
#include "User.h"
#include "Interface.h"
#include "Defines.h"
#include "MuHelper.h"
#include "Protocol.h"
#include "Common.h"
#include "MiniMap.h"
#include "InfoLog.h"
//
#include "ConnectServer.h"
#include "CustomFont.h"
#include "SwitchServer.h"
//

// ---------------------------------------------------------------------------------------------
CMacroUIEx gCMacroUIEx;
// ---------------------------------------------------------------------------------------------
CMacroUIEx::CMacroUIEx()
{
	char i;

	gCMacroUIEx.macroSwitchServer = new GUIbutton;
	gCMacroUIEx.macroSwitchServer->data = new GUIButton(12.5, 3, 35, 10, 150);
	gCMacroUIEx.macroSwitchServer->normalFrame = new GUIresource(0xF3001, 59, 20, 779, 42, 1024, 256, 1.5, 1.75);
	gCMacroUIEx.macroSwitchServer->hoverFrame = new GUIresource(0xF3001, 59, 20, 720, 42, 1024, 256, 1.5, 1.75);
	gCMacroUIEx.macroSwitchServer->clickedFrame = new GUIresource(0xF3001, 59, 20, 779, 42, 1024, 256, 1.5, 1.75);
	gCMacroUIEx.macroSwitchServer->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);


	gCMacroUIEx.macroSwitchServerHover = new GUIbutton;
	gCMacroUIEx.macroSwitchServerHover->data = new GUIButton(12.5, 3, 166 / 1.5, 24 / scale_ratio, 0);
	gCMacroUIEx.macroSwitchServerHover->normalFrame = new GUIresource(0xF3001, 0, 0, 385, 44, 1024, 256, 2, 2);
	gCMacroUIEx.macroSwitchServerHover->hoverFrame = new GUIresource(0xF3001, 166, 20, 385, 45, 1024, 256, 1.5, 1.5);
	gCMacroUIEx.macroSwitchServerHover->clickedFrame = new GUIresource(0xF3001, 0, 0, 385, 44, 1024, 256, 2, 2);
	gCMacroUIEx.macroSwitchServerHover->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);


	gCMacroUIEx.macroSwitchServerSliderUp = new GUIbutton;
	gCMacroUIEx.macroSwitchServerSliderUp->data = new GUIButton(121, 21.5, 24 / 1.5, 16 / 1.5, 150);
	gCMacroUIEx.macroSwitchServerSliderUp->normalFrame = new GUIresource(0xF3001, 24, 16, 547 - 24, 73, 1024, 256, 1.5, 1.5);
	gCMacroUIEx.macroSwitchServerSliderUp->hoverFrame = new GUIresource(0xF3001, 24, 16, 523 - 24, 73, 1024, 256, 1.5, 1.5);
	gCMacroUIEx.macroSwitchServerSliderUp->clickedFrame = new GUIresource(0xF3001, 24, 16, 403, 73, 1024, 256, 1.5, 1.5);
	gCMacroUIEx.macroSwitchServerSliderUp->disabledFrame = new GUIresource(0xF3001, 24, 16, 499 - 24, 73, 1024, 256, 1.5, 1.5);

	gCMacroUIEx.macroSwitchServerSliderDown = new GUIbutton;
	gCMacroUIEx.macroSwitchServerSliderDown->data = new GUIButton(121, 158.5, 24 / 1.5, 16 / 1.5, 150);
	gCMacroUIEx.macroSwitchServerSliderDown->normalFrame = new GUIresource(0xF3001, 24, 16, 451, 73, 1024, 256, 1.5, 1.5);
	gCMacroUIEx.macroSwitchServerSliderDown->hoverFrame = new GUIresource(0xF3001, 24, 16, 427, 73, 1024, 256, 1.5, 1.5);
	gCMacroUIEx.macroSwitchServerSliderDown->clickedFrame = new GUIresource(0xF3001, 24, 16, 571, 73, 1024, 256, 1.5, 1.5);
	gCMacroUIEx.macroSwitchServerSliderDown->disabledFrame = new GUIresource(0xF3001, 24, 16, 547, 73, 1024, 256, 1.5, 1.5);

	gCMacroUIEx.macroLog = new GUIbutton;
	gCMacroUIEx.macroLog->data = new GUIButton(151.5, 7.5, 18, 18, 150);
	gCMacroUIEx.macroLog->normalFrame = new GUIresource(0xF3001, 28, 28, 752, 1, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroLog->hoverFrame = new GUIresource(0xF3001, 28, 28, 783, 1, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroLog->clickedFrame = new GUIresource(0xF3001, 28, 28, 814, 1, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroLog->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);

	gCMacroUIEx.macroConfig = new GUIbutton;
	gCMacroUIEx.macroConfig->data = new GUIButton(151.5 + 19.5, 7.5, 18, 18, 150);
	gCMacroUIEx.macroConfig->normalFrame = new GUIresource(0xF3001, 28, 28, 877, 1, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroConfig->hoverFrame = new GUIresource(0xF3001, 28, 28, 970, 1, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroConfig->clickedFrame = new GUIresource(0xF3001, 28, 28, 355, 44, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroConfig->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);

	gCMacroUIEx.macroAuto = new GUIbutton;
	gCMacroUIEx.macroAuto->data = new GUIButton(151.5 + 19.5 * 2, 7.5, 18, 18, 150);
	gCMacroUIEx.macroAuto->normalFrame = new GUIresource(0xF3001, 28, 28, 231, 44, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroAuto->hoverFrame = new GUIresource(0xF3001, 28, 28, 262, 44, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroAuto->clickedFrame = new GUIresource(0xF3001, 28, 28, 293, 44, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroAuto->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);

	gCMacroUIEx.macroPauseAuto = new GUIbutton;
	gCMacroUIEx.macroPauseAuto->data = new GUIButton(151.5 + 19.5 * 2, 7.5, 18, 18, 150);
	gCMacroUIEx.macroPauseAuto->normalFrame = new GUIresource(0xF3001, 28, 28, 691, 1, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroPauseAuto->hoverFrame = new GUIresource(0xF3001, 28, 28, 722, 1, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroPauseAuto->clickedFrame = new GUIresource(0xF3001, 28, 28, 908, 1, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroPauseAuto->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);

	//custom window

	this->CustomList = new GUIObj(200, 20, 190, 340, true);

	/*Windows Struct x803*/
	this->CloseWindowsUP= new GUIbutton;
	this->CloseWindowsUP->data = new GUIButton(190 + 190 / 1.5, 30, 20 / 1.5, 20 / 1.5, 150);
	this->CloseWindowsUP->normalFrame = new GUIresource(0xF1009, 20, 19, 1002, 20, 1024, 512, pWinWidthReal, pWinHeightReal);
	this->CloseWindowsUP->hoverFrame = new GUIresource(0xF1009, 20, 19, 981, 20, 1024, 512, pWinWidthReal, pWinHeightReal);
	this->CloseWindowsUP->clickedFrame = new GUIresource(0xF1009, 20, 19, 1002, 0, 1024, 512, pWinWidthReal, pWinHeightReal);
	this->CloseWindowsUP->disabledFrame = new GUIresource(0xF1009, 20, 19, 981, 0, 1024, 512, pWinWidthReal, pWinHeightReal);
}

CMacroUIEx::~CMacroUIEx()
{
}

bool CMacroUIEx::isLockCursor()
{
	return gCMacroUIEx.macroSwitchServer->data->state && gCMacroUIEx.macroSwitchServerHoving;
}

void CMacroUIEx::DrawGui(short ObjID, float X, float Y, float W, float H, float SourceX, float SourceY, float SourceW, float SourceH, float ScaleW, float ScaleH, bool ScaleUp) {
	float v1, v2;

	if (W) {
		W /= ScaleW;
		v1 = ScaleW / (SourceW / W);
	}
	else {
		v1 = ScaleW;
	}

	if (H) {
		H /= ScaleH;
		v2 = ScaleH / (SourceH / H);
	}
	else {
		v2 = ScaleH;
	}
	pNIDrawGUI(gInterface.Data[ObjID].ModelID, X, Y, W, H, SourceX / SourceW, SourceY / SourceH, v1, v2, ScaleUp, 1, 0);
}

float CMacroUIEx::resizeX(float a1) 
{
	return a1 / ((float)pWinWidth / 800.0f);
}

float CMacroUIEx::resizeY(float a1) 
{
	return a1 / ((float)pWinHeight / 600.0f);
}

void CMacroUIEx::DrawToolTipBG(float a1, float a2, float a3, float a4) 
{
	float v0 = this->resizeX(8);
	float v1 = v0 / resizeGuiRate;
	float v2 = a3 - v1 * 2;
	float v3 = this->resizeY(7);
	float v4 = this->resizeY(6);
	float v5 = a4 - v3 / resizeGuiRate;
	float wRatio = (v2 / v0) * resizeGuiRate;
	float hRatio = (v5 / v4) * resizeGuiRate;
/*
	//left corner top
	this->DrawGui(eToolTip_ID, a1, a2, 8, 7, 20, 0, 128, 8, 1.5, 1.5);
	//center top
	this->DrawGui(eToolTip_ID, a1 + v1, a2, 8, 7, 10, 0, 128, 8, 1.5 / wRatio, 1.5);
	//right corner top
	//not correctly yet
	this->DrawGui(eToolTip_ID, a1 + this->resizeX(8 + v2 * resizeGuiRateX) / resizeGuiRate, a2, 8, 7, 0, 0, 128, 8, 1.5, 1.5);

	//left body
	this->DrawGui(eToolTip_ID, a1, a2 + v3 / resizeGuiRate, 8, 6, 80, 1, 128, 8, 1.5, 1.5 / hRatio);
	//center body
	this->DrawGui(eToolTip_ID, a1 + v1, a2 + v3 / resizeGuiRate, 8, 6, 70, 1, 128, 8, 1.5 / wRatio, 1.5 / hRatio);
	//right body
	this->DrawGui(eToolTip_ID, a1 + this->resizeX(8 + v2 * resizeGuiRateX) / resizeGuiRate, a2 + v3 / resizeGuiRate, 8, 6, 60, 1, 128, 8, 1.5, 1.5 / hRatio);

	//left corner bottom
	this->DrawGui(eToolTip_ID, a1, a2 + a4, 8, 7, 50, 1, 128, 8, 1.5, 1.5);
	//center body
	this->DrawGui(eToolTip_ID, a1 + v1, a2 + a4, 8, 7, 40, 1, 128, 8, 1.5 / wRatio, 1.5);
	//right corner bottom
	this->DrawGui(eToolTip_ID, a1 + this->resizeX(8 + v2 * resizeGuiRateX) / resizeGuiRate, a2 + a4, 8, 7, 30, 1, 128, 8, 1.5, 1.5);
*/
}

void CMacroUIEx::DrawWindowBG(float a1, float a2) {
	static float v1;
	static float v2;
	static float v3;

	v1 = a2 + 74 / scale_ratio;
	v2 = v1 + 179 / scale_ratio;
	v3 = scale_height / 1.3;
	gCMacroUIEx.DrawFrame(0xF1003, a1, a2, 325, 74, 652, 106, 1024, 512, scale_width, scale_height, 0);
	gCMacroUIEx.DrawFrame(0xF1003, a1, v1, 325, 179, 326, 1, 1024, 512, scale_width, scale_height, 0);
	gCMacroUIEx.DrawFrame(0xF1003, a1, v2, 325, 386, 0, 1, 1024, 495, scale_width, v3, 0);
}

bool CMacroUIEx::IsWorkZone(float a1, float a2, float a3, float a4) 
{
	return pCursorX <= (a1 + a3) && pCursorX >= a1 && pCursorY <= (a2 + a4) && pCursorY >= a2;
}

void CMacroUIEx::DrawFrame(DWORD ModelID, float X, float Y, float W, float H, float SourceX, float SourceY, float SourceW, float SourceH, float ScaleW, float ScaleH, bool ScaleUp) {
	float v1, v2;

	if (W) {
		W /= ScaleW;
		v1 = ScaleW / (SourceW / W);
	}
	else {
		v1 = ScaleW;
	}

	if (H) {
		H /= ScaleH;
		v2 = ScaleH / (SourceH / H);
	}
	else {
		v2 = ScaleH;
	}
	pNIDrawGUI(ModelID, X, Y, W, H, SourceX / SourceW, SourceY / SourceH, v1, v2, ScaleUp, 1, 0);
}

textSize CMacroUIEx::getTextSize(char* a1)
{
	textSize res;
	struct tagSIZE psizl;
	sub_401C10();
	sub_9593B0((HDC)sub_41FF80(pTextThis()), a1, lstrlenA(a1), &psizl);

	if (pCheckWindow(pWindowThis(), 57) == 1)
		res.resize_height = (float)psizl.cy / (*(float*)0xE7C3D8 / 1.3);
	else
		res.resize_height = (float)psizl.cy / (*(float*)0xE7C3D8 / 1.1);
	res.width = (float)psizl.cx / *(float*)0xE7C3D4;
	res.height = (float)psizl.cy;
	res.resize_width = (float)psizl.cx / *(float*)0xE7C3D4;
	return res;
}

bool CMacroUIEx::Drawbutton(GUIbutton* gui, float X, float Y, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	gui->data->X = X;
	gui->data->Y = Y;
	gui->data->Max_X = gui->data->X + gui->data->Width;
	gui->data->Max_Y = gui->data->Y + gui->data->Height;
	return this->Drawbutton(gui, Buff);
}

bool CMacroUIEx::Drawbutton(GUIbutton* gui, LPCSTR Text, ...)
{
	static float v1;
	static float v2;
	static float v3;
	static float v4;
	static float v5;
	static float v6;
	static float v7;
	static float v8;
	static float v9;
	static float v10;
	bool res = false;


	bool hoving = this->IsWorkZone(gui->data->X, gui->data->Y, gui->data->Width, gui->data->Height);

	v1 = gui->normalFrame->ScaleX ? gui->normalFrame->ScaleX / pWinWidthReal : pWinWidthReal;
	v2 = gui->normalFrame->ScaleY ? gui->normalFrame->ScaleY / pWinWidthReal : pWinWidthReal;

	v3 = gui->hoverFrame->ScaleX ? gui->hoverFrame->ScaleX / pWinWidthReal : pWinWidthReal;
	v4 = gui->hoverFrame->ScaleY ? gui->hoverFrame->ScaleY / pWinWidthReal : pWinWidthReal;

	v5 = gui->clickedFrame->ScaleX ? gui->clickedFrame->ScaleX / pWinWidthReal : pWinWidthReal;
	v6 = gui->clickedFrame->ScaleY ? gui->clickedFrame->ScaleY / pWinWidthReal : pWinWidthReal;

	char Buff[2048];
	int BuffLen = sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	textSize tS = gCMacroUIEx.getTextSize(Buff);


	//CustomFont.Draw(CustomFont.FontNormal, gui->data->X, gui->data->Y, 0xffffffff, 0xff000055, gui->data->Width, gui->data->Height, 0, " ");
	if (gui->data->state == 4)
	{
		gCMacroUIEx.DrawFrame(gui->disabledFrame->ID, gui->data->X, gui->data->Y, gui->disabledFrame->CellWidth, gui->disabledFrame->CellHeight,
			gui->disabledFrame->SourceX, gui->disabledFrame->SourceY, gui->disabledFrame->SourceWidth, gui->disabledFrame->SourceHeight, v3, v4);


		v5 = gui->data->Y + (gui->data->Height - tS.resize_height) / 2;
		CustomFont.Draw(CustomFont.FontNormal, gui->data->X, v5 + 1, gui->disabledFrame->TextColor, gui->disabledFrame->TextBGColor, gui->data->Width, tS.resize_height, 3, Buff);

		return res;
	}
	if (hoving) {
		if (GetKeyState(VK_LBUTTON) & 0x8000) { //clicked
			if (gui->data->lastActionTime + gui->data->delay <= GetTickCount() && !gui->data->clickDown) {
				gui->data->clickDown = true;
				gui->data->lastActionTime = GetTickCount();
			}
			gCMacroUIEx.DrawFrame(gui->clickedFrame->ID, gui->data->X, gui->data->Y, gui->clickedFrame->CellWidth, gui->clickedFrame->CellHeight,
				gui->clickedFrame->SourceX, gui->clickedFrame->SourceY, gui->clickedFrame->SourceWidth, gui->clickedFrame->SourceHeight, v5, v6);

			v5 = gui->data->Y + (gui->data->Height - tS.resize_height) / 2;
			CustomFont.Draw(CustomFont.FontNormal, gui->data->X, v5 + 1, gui->clickedFrame->TextColor, gui->clickedFrame->TextBGColor, gui->data->Width, tS.resize_height, 3, Buff);
		}
		else { //hoving
			if (gui->data->clickDown) {
				gui->data->state = !gui->data->state;
				res = true;
				gui->data->clickDown = false;
			}
			gCMacroUIEx.DrawFrame(gui->hoverFrame->ID, gui->data->X, gui->data->Y, gui->hoverFrame->CellWidth, gui->hoverFrame->CellHeight,
				gui->hoverFrame->SourceX, gui->hoverFrame->SourceY, gui->hoverFrame->SourceWidth, gui->hoverFrame->SourceHeight, v3, v4);

			v5 = gui->data->Y + (gui->data->Height - tS.resize_height) / 2;
			CustomFont.Draw(CustomFont.FontNormal, gui->data->X, v5 + 1, gui->hoverFrame->TextColor, gui->hoverFrame->TextBGColor, gui->data->Width, tS.resize_height, 3, Buff);
		}
	}
	else //normal
	{

		gCMacroUIEx.DrawFrame(gui->normalFrame->ID, gui->data->X, gui->data->Y, gui->normalFrame->CellWidth, gui->normalFrame->CellHeight,
			gui->normalFrame->SourceX, gui->normalFrame->SourceY, gui->normalFrame->SourceWidth, gui->normalFrame->SourceHeight, v1, v2);

		v5 = gui->data->Y + (gui->data->Height - tS.resize_height) / 2;
		CustomFont.Draw(CustomFont.FontNormal, gui->data->X, v5 + 1, gui->normalFrame->TextColor, gui->normalFrame->TextBGColor, gui->data->Width, tS.resize_height, 3, Buff);
	}


	return res;
}

void CMacroUIEx::RenderFrame(int *This)
{
	char Cord[256];
	float X = (double)*((DWORD *)This + 5);
	float Y = (double)*((signed int *)This + 6);
	float renderMenu = 15.0f;
	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	renderMenu = 10.0f;

	gCMacroUIEx.DrawFrame(0xF3001, X + 135, Y, 186, 30, 502, 0, 1024, 256, 1.5 / pWinWidthReal, 1.5 / pWinHeightReal);
	gCMacroUIEx.DrawFrame(0xF3001, X, Y, 232, 37, 270, 0, 1024, 256, 1.5 / pWinWidthReal, 1.5 / pWinHeightReal);

	if (gCMacroUIEx.Drawbutton(gCMacroUIEx.macroLog, ""))
		if(gProtect.m_MainInfo.CustomInterfaceType == 3)
		{
		    gCMacroUIEx.CustomList->onShow = !gCMacroUIEx.CustomList->onShow;
		}
		else
		{
		    if (gInterface.CheckMenuWindow())
			{
		        gInterface.CloseMenuWindow();
	        }
			else
			{
		        gInterface.OpenMenuWindow();
	        }
		}

	gCMacroUIEx.Drawbutton(gCMacroUIEx.macroConfig, "");
	gCMacroUIEx.Drawbutton(gCMacroUIEx.macroAuto, "");
	gCMacroUIEx.macroAuto->data->state = pMUHelperStat;

	if(gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
	ConnectServer.currently_subcode = *(DWORD*)0x0986C128;

	if (gCMacroUIEx.Drawbutton(gCMacroUIEx.macroSwitchServer, " "))
	{
		if (gCMacroUIEx.macroSwitchServer->data->state == 1)
		{
			ConnectServer.ReqServerList(true);
		}
	}
	if (ConnectServer.currently_subcode)
	{
		if (ConnectServer.SrvStat[ConnectServer.currently_subcode - 1].type == 0)
			pSetTextColor(pTextThis(), 240, 50, 50, 255);
		else if (ConnectServer.SrvStat[ConnectServer.currently_subcode - 1].type == 1)
			pSetTextColor(pTextThis(), 50, 240, 50, 255);
		else
			pSetTextColor(pTextThis(), 160, 160, 160, 255);
		wsprintf(Cord, "sub: %d", ConnectServer.currently_subcode);
		pDrawText(pTextThis(), X + 17.5, Y + 3, Cord, 30, 0, (LPINT)0, 0);
	}

	if (gCMacroUIEx.macroSwitchServer->data->state == 1)
	{
		ConnectServer.ReqServerList(false);
		gCMacroUIEx.DrawFrame(0xF3001, X + 7.5 , Y + 21.5, 198, 226, 1, 3, 1024, 256, 1.5 / pWinWidthReal, 1.5 / pWinHeightReal);
		if (gCMacroUIEx.IsWorkZone(X + 7.5, Y + 21.5, 198 / 1.5, 226 / 1.5))
		{
			gCMacroUIEx.macroSwitchServerHoving = true;
		}
		else 
		{
			gCMacroUIEx.macroSwitchServerHoving = false;
		}
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
		pSetTextColor(pTextThis(), 160, 160, 160, 255);
		bool showToolTip = false;

		for (char i = 0; i < ConnectServer.server_list_count; i++)
		{
			if (ConnectServer.currently_subcode - 1 != i)
			{
				if (gCMacroUIEx.Drawbutton(gCMacroUIEx.macroSwitchServerHover, X + 11, Y + 21.5 + 14.65 * i, ""))
				{
					if (!gCMacroUIEx.isSwitchServer && gCMacroUIEx.lastSwitch + DelaySwitchServer < GetTickCount())
					{
						SwitchServer.switchServer(ConnectServer.SrvStat[i].ServerCode);
						*(DWORD*)0x0986C128 = ConnectServer.SrvStat[i].ServerCode + 1;
						gCMacroUIEx.lastSwitch = GetTickCount();
						gCMacroUIEx.macroSwitchServer->data->state = 0;
					}
				}
			}
			else 
			{
				if (gCMacroUIEx.IsWorkZone(X + 11, Y + 21.5 + 14.65 * i, 110, 14))
				{
					showToolTip = true;
				}
			}
			pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
			if (ConnectServer.SrvStat[i].type == 0)
				pSetTextColor(pTextThis(), 240, 50, 50, 255);
			else if (ConnectServer.SrvStat[i].type == 1)
				pSetTextColor(pTextThis(), 50, 240, 50, 255);
			else
				pSetTextColor(pTextThis(), 160, 160, 160, 255);
			wsprintf(Cord, "sub: %d", ConnectServer.SrvStat[i].ServerCode + 1);
			pDrawText(pTextThis(), X + 17.5, Y + 23.5 + 14.65 * i, Cord, 30, 0, (LPINT)0, 0);
			pSetTextColor(pTextThis(), 120, 120, 120, 200);
			//new
			
			char* ServerTypeName[] = 
			{
				"[Gold]","[Gold(PvP)]", "[NoN-PvP]", "[Normal]", "[Unknow]" 
			};
			if(ConnectServer.SrvStat[i].ServerCode >= 0 && ConnectServer.SrvStat[i].ServerCode <= 3)
			{
				pDrawText(pTextThis(), X + 50, Y + 23.5 + 14.65 * i, ServerTypeName[0], 30, 0, (LPINT)0, 0);
			}
			else if(ConnectServer.SrvStat[i].ServerCode == 4)
			{
			    pDrawText(pTextThis(), X + 50, Y + 23.5 + 14.65 * i, ServerTypeName[1], 30, 0, (LPINT)0, 0);
			}
			else if(ConnectServer.SrvStat[i].ServerCode >= 5 && ConnectServer.SrvStat[i].ServerCode <= 8)
			{
				pDrawText(pTextThis(), X + 50, Y + 23.5 + 14.65 * i, ServerTypeName[2], 30, 0, (LPINT)0, 0);
			}
			else if(ConnectServer.SrvStat[i].ServerCode >= 9 && ConnectServer.SrvStat[i].ServerCode <= 20)
			{
			    pDrawText(pTextThis(), X + 50, Y + 23.5 + 14.65 * i, ServerTypeName[3], 30, 0, (LPINT)0, 0);
			}
			else
			{
				pDrawText(pTextThis(), X + 50, Y + 23.5 + 14.65 * i, ServerTypeName[4], 30, 0, (LPINT)0, 0);
			}
			if (ConnectServer.SrvStat[i].UserTotal < 100){
				pSetTextColor(pTextThis(), 50, 240, 50, 255);
				wsprintf(Cord, "%d%%", ConnectServer.SrvStat[i].UserTotal);
			}
			else
			{
				pSetTextColor(pTextThis(), 240, 50, 50, 255);
				wsprintf(Cord, "Full");
			}
			pDrawText(pTextThis(), X + 102.5, Y + 23.5 + 14.65 * i, Cord, 30, 4, (LPINT)0, 0);
		}
		gCMacroUIEx.Drawbutton(gCMacroUIEx.macroSwitchServerSliderUp, "");
		gCMacroUIEx.Drawbutton(gCMacroUIEx.macroSwitchServerSliderDown, "");

		if (showToolTip)
		{
			textSize tS = gCMacroUIEx.getTextSize("El canal seleccionado actualmente");
			gCMacroUIEx.DrawToolTipBG(pCursorX + 25, pCursorY, tS.resize_width + 10, tS.resize_height + 4);
			pSetTextColor(pTextThis(), 160, 160, 160, 255);

			pDrawText(pTextThis(), pCursorX + 25, pCursorY + 4, "El canal seleccionado actualmente", tS.resize_width + 10, 0, (LPINT)3, 0);
		}
	}
	}



	if (gCMacroUIEx.macroAuto->data->state)
		gCMacroUIEx.Drawbutton(gCMacroUIEx.macroPauseAuto, "");

	//Mapa y Coordenadas

	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 240, 240, 240, 255);

	if (World >= 82 && World <= 100)
	{
		pDrawText(pTextThis(), X + 55, Y + 4, pGetTextLine(pTextLineThis, (3810 + World - 82)), 45, 0, (LPINT)3, 0);
	}
	else
	{
		pDrawText(pTextThis(), X + 55, Y + 4, pMapName(World), 45, 0, (LPINT)3, 0);
	}

	wsprintf(Cord, "%d,%d", gObjUser.lpViewPlayer->MapPosX, gObjUser.lpViewPlayer->MapPosY);
	pDrawText(pTextThis(), X + 97.5, Y + 4, Cord, 35, 0, (LPINT)4, 0);
	//Extra
	DWORD Color = Color4f(255, 189, 25, 255);
	if(gCMacroUIEx.macroAuto->data->state == 1)
	{
	    gInterface.DrawFormat(Color, X + 205, Y + 2.5, 27.5, 3, "1");
	}
	else
	{
		gInterface.DrawFormat(Color, X + 205, Y + 2.5, 27.5, 3, "0");
	}
//-------------------------------------------------------------------------------
	
//Botones
	renderMenu = 15.0f;
	gInterface.DrawButtonRender(ButtonSettings, 156.0f + renderMenu, 7.0, 0, 0);
	//-- Config
	if (gInterface.IsWorkZone(ButtonSettings))
	{
		gInterface.DrawToolTip(X + 156.0f + renderMenu, Y + 50, "Config Helper");

	if (gInterface.Data[ButtonSettings].OnClick)
	{
		RenderBitmap(51546, X + 156.0f + renderMenu, Y + 9.0, 19, 19, 0.0, 0.451f, 0.878, 0.225, 1, 1, 0.0);
		}
	else
	{
		RenderBitmap(51546, X + 156.0f + renderMenu, Y + 9.0, 19, 19, 0.0, 0.2255f, 0.878, 0.225, 1, 1, 0.0);
		}
	}
	else
	{
		RenderBitmap(51546, X + 156.0f + renderMenu, Y + 9.0, 19, 19, 0.0, 0.0, 0.878, 0.225, 1, 1, 0.0);
	}
	if (!*(BYTE*)(*(DWORD*)(MUHELPER_STRUC)+0x08))
	{
		gInterface.DrawButtonRender(ButtonStart, 175.0f  + renderMenu, 7.0 , 0, 0.0f);
		//-- Play
		if (gInterface.IsWorkZone(ButtonStart))
		{
			gInterface.DrawToolTip(X + 175.0f + renderMenu, Y + 50,"Play Helper");

		if (gInterface.Data[ButtonStart].OnClick)
		{
			RenderBitmap(51547, X + 175.0f + renderMenu, Y + 9.0, 19, 19, 0.0, 0.451f, 0.878, 0.225, 1, 1, 0.0);
			}
		else
		{
			RenderBitmap(51547, X + 175.0f + renderMenu, Y + 9.0, 19, 19, 0.0, 0.2255f, 0.878, 0.225, 1, 1, 0.0);
			}
		}
	else
	{
		RenderBitmap(51547, X + 175.0f + renderMenu, Y + 9.0, 19, 19, 0.0, 0.0, 0.878, 0.225, 1, 1, 0.0);
	}
	}
	else
	{
		gInterface.DrawButtonRender(ButtonStop, 175.0f + renderMenu, 7.0 , 0, 0.0f);

		if(offhelper == 1)
		{
			gMuHelper.RunningOffHelper();
		}
		//-- Pause
		if (gInterface.IsWorkZone(ButtonStop))
		{
			gInterface.DrawToolTip(X + 175.0f + renderMenu, Y + 50,"Pause Helper");

			if (gInterface.Data[ButtonStop].OnClick)
			{
				RenderBitmap(51548, X + 175.0f + renderMenu, Y + 7.0, 19, 19, 0.0, 0.451f, 0.878, 0.225, 1, 1, 0.0);
			}
			else
			{
				RenderBitmap(51548, X + 175.0f + renderMenu, Y + 7.0, 19, 19, 0.0, 0.2255f, 0.878, 0.225, 1, 1, 0.0);
			}
		}
		else
		{
			RenderBitmap(51548, X + 175.0f + renderMenu, Y + 7.0, 19, 19, 0.0, 0.0, 0.878, 0.225, 1, 1, 0.0);
		}
	}
	gInterface.DrawButtonRender(eMenu, X + 137.0f + renderMenu, Y + 7.0 , 0, 0.0f);

	if (gInterface.IsWorkZone(eMenu))
	{
		gInterface.DrawToolTip(X + 137.0f + renderMenu, 50, "Especial Menu");
		// ----
	if (gInterface.Data[eMenu].OnClick)
	{
		RenderBitmap(51553, X + 137.0f + renderMenu, Y + 9.0, 19, 19, 0.0, 0.451f, 0.878, 0.225, 1, 1, 0.0);
		}
	else
	{
		RenderBitmap(51553, X + 137.0f + renderMenu, Y + 9.0, 19, 19, 0.0, 0.2255f, 0.878, 0.225, 1, 1, 0.0);
		}
	}
	else
	{
		RenderBitmap(51553, X + 137.0f + renderMenu, Y + 9.0, 19, 19, 0.0, 0.0, 0.878, 0.225, 1, 1, 0.0);
	}
//-------------------------------------------------------------------------------
	pGLSwitch();
	EnableAlphaTest(0);
	return;

	
}

void CMacroUIEx::Button(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();

	if( gInterface.IsWorkZone(ButtonSettings) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[ButtonSettings].EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[ButtonSettings].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[ButtonSettings].OnClick = false;
		// ----
		if( Delay < 1000 )
		{
			return;
		}
		// ----
		gInterface.Data[ButtonSettings].EventTick = GetTickCount();
		// ----
	}
	else if( gInterface.IsWorkZone(ButtonStart) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[ButtonStart].EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[ButtonStart].OnClick = true;

			return;
		}
		// ----
		gInterface.Data[ButtonStart].OnClick = false;
		// ----
		if( Delay < 1000 )
		{
			return;
		}
		// ----
		gInterface.Data[ButtonStart].EventTick = GetTickCount();
		// ----
		}
	else if( gInterface.IsWorkZone(ButtonStop) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[ButtonStop].EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[ButtonStop].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[ButtonStop].OnClick = false;
		// ----
		if( Delay < 1000 )
		{
			return;
		}
		// ----
		gInterface.Data[ButtonStop].EventTick = GetTickCount();
		// ----
	}
}

char BarTime_1(int This)
{
	float v1; // ST10_4@2
	float v2; // ST0C_4@2
	float v3; // ST30_4@3
	float v4; // ST08_4@3
	float v5; // ST04_4@3
	int v13; // [sp+30h] [bp-4h]@1

	 v13 = This;

	if ( *(BYTE *)(v13 + 72) == 1 )
	{
		v1 = (double)*(signed int *)(This + 20);
		v2 = (double)*(signed int *)(This + 16);
		RenderImage2(51522, v5, v4);
		if ( *(DWORD *)(v13 + 88) == 1 )
		{
			v3 = *(float *)(v13 + 92) * 50.0;
			v4 = (double)(*(DWORD *)(v13 + 20) + 2);
			v5 = (double)(*(DWORD *)(v13 + 16) + 2);
			RenderImage(51549, v5 + 108.0, v4 - 16.0, v3, 3.0);
		}
		else if ( *(DWORD *)(v13 + 88) > 1 )
		{
			RenderImage2(51522, v5, v4);
			v3 = *(float *)(v13 + 92) * 50.0;
			v4 = (double)(*(DWORD *)(v13 + 20) + 2);
			v5 = (double)(*(DWORD *)(v13 + 16) + 2);
			RenderImage(51549, v5 + 108.0, v4 - 16.0, v3, 3.0);
		}
		/*if ( *(BYTE *)(v13 + 128) == 1 )
		{
			v14 = (const CHAR *)sub_402880((void *)(v16 + 100));
			sub_597220(*(_DWORD *)(v16 + 132), *(_DWORD *)(v16 + 136), v14);
		}*/
	}
  return 1;
}
//-- (007D25C0)
__declspec(naked) void MuHelperRemake_01_1()  //<- ConfigHelper
{
	static DWORD Remake_Buffer = 0x007D26DA;
	static DWORD W = gCMacroUIEx.macroConfig->data->Width;
	static DWORD H = gCMacroUIEx.macroConfig->data->Height;
	static DWORD X = gCMacroUIEx.macroConfig->data->X;
	static DWORD Y = gCMacroUIEx.macroConfig->data->Y;


	_asm
	{
		PUSH H; | Arg6 = 0000000D
			PUSH W; | Arg5 = 00000012
			MOV EDX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EAX, DWORD PTR DS : [EDX + 0x18]; |
			PUSH Y; | Arg4
			MOV ECX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EDX, DWORD PTR DS : [ECX + 0x14]; |
			MOV EAX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV ECX, DWORD PTR DS : [EAX + 0xC]; |
			LEA EDX, DWORD PTR DS : [EDX + ECX + 0x29]; |
			PUSH X; | Arg3
			JMP[Remake_Buffer]
	}
}
//-- (007D25C0)
__declspec(naked) void MuHelperRemake_02_1()  //<- PlayHelper
{
	static DWORD Remake_Buffer = 0x007D2776;
	static DWORD W = gCMacroUIEx.macroAuto->data->Width;
	static DWORD H = gCMacroUIEx.macroAuto->data->Height;
	static DWORD X = gCMacroUIEx.macroAuto->data->X;
	static DWORD Y = gCMacroUIEx.macroAuto->data->Y;


	_asm
	{
		PUSH H; | Arg6 = 0000000D
			PUSH W; | Arg5 = 00000012
			MOV EAX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV ECX, DWORD PTR DS : [EAX + 0x18]; |
			PUSH Y; | Arg4
			MOV EDX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EAX, DWORD PTR DS : [EDX + 0x14]; |
			MOV ECX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EDX, DWORD PTR DS : [ECX + 0xC]; |
			LEA EAX, DWORD PTR DS : [EAX + EDX + 0x3B]; |
			PUSH X; | Arg3
			JMP[Remake_Buffer]
	}
}
//-- (007D25C0)
__declspec(naked) void MuHelperRemake_03_1()  //<- PauseHelper
{
	static DWORD Remake_Buffer = 0x007D2821;
	static DWORD W = gCMacroUIEx.macroPauseAuto->data->Width;
	static DWORD H = gCMacroUIEx.macroPauseAuto->data->Height;
	static DWORD X = gCMacroUIEx.macroPauseAuto->data->X;
	static DWORD Y = gCMacroUIEx.macroPauseAuto->data->Y;

	_asm
	{
		PUSH H; | Arg6 = 0000000D
			PUSH W; | Arg5 = 00000012
			MOV EAX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV ECX, DWORD PTR DS : [EAX + 0x18]; |
			PUSH Y; | Arg4
			MOV EDX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EAX, DWORD PTR DS : [EDX + 0x14]; |
			MOV ECX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EDX, DWORD PTR DS : [ECX + 0xC]; |
			LEA EAX, DWORD PTR DS : [EAX + EDX + 0x3B]; |
			PUSH X; | Arg3
			JMP[Remake_Buffer]
	}
}

//==========================================================================================

void CMacroUIEx::ButtonNew(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
}

//-- (007D25C0)
__declspec(naked) void MuHelperRemake_01()  //<- ConfigHelper
{
	static DWORD Remake_Buffer = 0x007D26DA;
	static DWORD W = gCMacroUIEx.macroConfig->data->Width;
	static DWORD H = gCMacroUIEx.macroConfig->data->Height;
	static DWORD X = gCMacroUIEx.macroConfig->data->X;
	static DWORD Y = gCMacroUIEx.macroConfig->data->Y;


	_asm
	{
		PUSH H; | Arg6 = 0000000D
			PUSH W; | Arg5 = 00000012
			MOV EDX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EAX, DWORD PTR DS : [EDX + 0x18]; |
			PUSH Y; | Arg4
			MOV ECX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EDX, DWORD PTR DS : [ECX + 0x14]; |
			MOV EAX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV ECX, DWORD PTR DS : [EAX + 0xC]; |
			LEA EDX, DWORD PTR DS : [EDX + ECX + 0x29]; |
			PUSH X; | Arg3
			JMP[Remake_Buffer]
	}
}
//-- (007D25C0)
__declspec(naked) void MuHelperRemake_02()  //<- PlayHelper
{
	static DWORD Remake_Buffer = 0x007D2776;
	static DWORD W = gCMacroUIEx.macroAuto->data->Width;
	static DWORD H = gCMacroUIEx.macroAuto->data->Height;
	static DWORD X = gCMacroUIEx.macroAuto->data->X;
	static DWORD Y = gCMacroUIEx.macroAuto->data->Y;


	_asm
	{
		PUSH H; | Arg6 = 0000000D
			PUSH W; | Arg5 = 00000012
			MOV EAX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV ECX, DWORD PTR DS : [EAX + 0x18]; |
			PUSH Y; | Arg4
			MOV EDX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EAX, DWORD PTR DS : [EDX + 0x14]; |
			MOV ECX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EDX, DWORD PTR DS : [ECX + 0xC]; |
			LEA EAX, DWORD PTR DS : [EAX + EDX + 0x3B]; |
			PUSH X; | Arg3
			JMP[Remake_Buffer]
	}
}
//-- (007D25C0)
__declspec(naked) void MuHelperRemake_03()  //<- PauseHelper
{
	static DWORD Remake_Buffer = 0x007D2821;
	static DWORD W = gCMacroUIEx.macroPauseAuto->data->Width;
	static DWORD H = gCMacroUIEx.macroPauseAuto->data->Height;
	static DWORD X = gCMacroUIEx.macroPauseAuto->data->X;
	static DWORD Y = gCMacroUIEx.macroPauseAuto->data->Y;

	_asm
	{
		PUSH H; | Arg6 = 0000000D
			PUSH W; | Arg5 = 00000012
			MOV EAX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV ECX, DWORD PTR DS : [EAX + 0x18]; |
			PUSH Y; | Arg4
			MOV EDX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EAX, DWORD PTR DS : [EDX + 0x14]; |
			MOV ECX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EDX, DWORD PTR DS : [ECX + 0xC]; |
			LEA EAX, DWORD PTR DS : [EAX + EDX + 0x3B]; |
			PUSH X; | Arg3
			JMP[Remake_Buffer]
	}
}

void CMacroUIEx::RenderHelperFrame(int *This)
{
	char Cord[256];
	float X = (double)*((DWORD *)This + 5);
	float Y = (double)*((signed int *)This + 6);
	float RenderX; 

	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	RenderImage(31602, X, Y, 22.0, 25.0);

	for(int i = 0 ; i < 5 ; i ++)
	{
		RenderX = (double) X + 22.0 + (i * 26.0);
		RenderImage(31603, RenderX, Y, 26.0, 25.0);
	}

	RenderImage(31604, RenderX, Y, 73.0, 20.0);
	
	//Mapa y Coordenadas
	if (World >= 82 && World <= 100)
	{
		wsprintf(Cord, "%s  (%d , %d)", pGetTextLine(pTextLineThis, (3810 + World - 82)), gObjUser.CoordenadaX, gObjUser.CoordenadaY);
	}
	else
	{
		wsprintf(Cord, "%s  (%d , %d)", pGetMapName(World), gObjUser.CoordenadaX, gObjUser.CoordenadaY);
	}
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 240, 240, 240, 255);
	pDrawText(pTextThis(), X - 30, Y + 4, Cord, 190, 0, (LPINT)3, 0);
	pGLSwitch();
	EnableAlphaTest(0);
	//-- Config
	gInterface.DrawButtonRender(ButtonSettings, 146, 1, 0, 0);

	if (gInterface.IsWorkZone(ButtonSettings))
	{
		gInterface.DrawToolTip(146, Y + 50, "Config Helper");

		if (gInterface.Data[ButtonSettings].OnClick)
		{
			pDrawButton(31761, 146, 1.6, 18.0f, 13.3, 0, 26.9);
		}
		else
		{
			pDrawButton(31761, 146, 1.6, 18.0f, 13.3, 0, 13.6);
		}
	}
	else
	{
		pDrawButton(31761, 146, 1.0,18.0f, 13.3, 0, 0);
	}

	if (!*(BYTE*)(*(DWORD*)(MUHELPER_STRUC)+0x08))
	{
		gInterface.DrawButtonRender(ButtonStart, 146 + 18, 1, 0, 0);
		//-- Play
		if (gInterface.IsWorkZone(ButtonStart))
		{
			gInterface.DrawToolTip(146 + 18, Y + 50,"Play Helper");

			if (gInterface.Data[ButtonStart].OnClick)
			{
				pDrawButton(31762, 146 + 18, 1.6, 18.0f, 13.3, 0, 26.9);
			}
			else
			{
				pDrawButton(31762, 146 + 18, 1.6, 18.0f, 13.3, 0, 13.6);
			}
		}
		else
		{
			pDrawButton(31762, 146 + 18, 1.0,18.0f, 13.3, 0, 0);
		}
	}
	else
	{
		gInterface.DrawButtonRender(ButtonStop, 146 + 18, 1, 0, 0);

		if(offhelper == 1)
		{
			gMuHelper.RunningOffHelper();
		}
		//-- Pause
		if (gInterface.IsWorkZone(ButtonStop))
		{
			gInterface.DrawToolTip(146 + 18, Y + 50,"Pause Helper");

			if (gInterface.Data[ButtonStop].OnClick)
			{
				pDrawButton(31763, 146 + 18, 1.6, 18.0f, 13.3, 0, 26.9);
			}
			else
			{
				pDrawButton(31763, 146 + 18, 1.6, 18.0f, 13.3, 0, 13.6);
			}
		}
		else
		{
			pDrawButton(31763, 146 + 18, 1.0, 18.0f, 13.3, 0, 0);
		}
	}
//=======================================================
	DWORD Color;
	if (gProtect.m_MainInfo.CustomMenuSwitch != 0)
	{
		pDrawButton(30983, 146 + 37.2, 0.0, 36, 18, 0, 0);

		gInterface.DrawButtonRender(eMenu, 146 + 37.2, Y + 1.0 , 0, 0.0f);

		if (gInterface.IsWorkZone(eMenu))
		{
			gInterface.DrawToolTip(146 + 37.2, 50, "Especial Menu");
			// ----
			if (gInterface.Data[eMenu].OnClick)
			{
				Color = eGray150;

				gInterface.DrawColoredGUI(eMenu, 146 + 37.2, Y + 1.0, Color);
			}
			else
			{
				gInterface.DrawButtonRender(eMenu, 146 + 37.2, Y + 1.0 , 0, 0.0f);
			}
		}
		else
		{
			gInterface.DrawButtonRender(eMenu, 146 + 37.2, Y + 1.0 , 0, 0.0f);
		}
	}
}

__declspec(naked) void MuHelperRemake2_01()  //<- ConfigHelper
{
	static DWORD Addr_JMP = 0x007D26DA;
	static DWORD W = 18;
	static DWORD H = 13.3;
	static DWORD X = 146.0f;
	static DWORD Y = 1;
 
	_asm
	{
		PUSH H                                  ; |Arg6 = 0000000D
		PUSH W                                  ; |Arg5 = 00000012
		MOV EDX,DWORD PTR SS:[EBP-0xB8]         ; |
		MOV EAX,DWORD PTR DS:[EDX+0x18]            ; |
		PUSH Y                                 ; |Arg4
		MOV ECX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EDX,DWORD PTR DS:[ECX+0x14]            ; |
		MOV EAX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV ECX,DWORD PTR DS:[EAX+0xC]             ; |
		LEA EDX,DWORD PTR DS:[EDX+ECX+0x29]        ; |
		PUSH X                                 ; |Arg3
		JMP [Addr_JMP]
	}
}
//-- (007D25C0)
__declspec(naked) void MuHelperRemake2_02()  //<- PlayHelper
{
	static DWORD Addr_JMP = 0x007D2776;
	static DWORD W = 18;
	static DWORD H = 13.3;
	static DWORD X = 146.0f + 18.0f;
	static DWORD Y = 1;
 
	_asm
	{
		PUSH H                                     ; |Arg6 = 0000000D
		PUSH W                                     ; |Arg5 = 00000012
		MOV EAX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV ECX,DWORD PTR DS:[EAX+0x18]            ; |
		PUSH Y                                     ; |Arg4
		MOV EDX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EAX,DWORD PTR DS:[EDX+0x14]            ; |
		MOV ECX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EDX,DWORD PTR DS:[ECX+0xC]             ; |
		LEA EAX,DWORD PTR DS:[EAX+EDX+0x3B]        ; |
		PUSH X                                     ; |Arg3
		JMP [Addr_JMP]
	}
}
//-- (007D25C0)
__declspec(naked) void MuHelperRemake2_03()  //<- PauseHelper
{
	static DWORD Addr_JMP = 0x007D2821;
	static DWORD W = 18;
	static DWORD H = 13.3;
	static DWORD X = 146.0f + 18.0f;
	static DWORD Y = 1;
 
	_asm
	{
		PUSH H                                     ; |Arg6 = 0000000D
		PUSH W                                     ; |Arg5 = 00000012
		MOV EAX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV ECX,DWORD PTR DS:[EAX+0x18]            ; |
		PUSH Y                                     ; |Arg4
		MOV EDX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EAX,DWORD PTR DS:[EDX+0x14]            ; |
		MOV ECX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EDX,DWORD PTR DS:[ECX+0xC]             ; |
		LEA EAX,DWORD PTR DS:[EAX+EDX+0x3B]        ; |
		PUSH X                                     ; |Arg3
		JMP [Addr_JMP]
	}
}


void OffHelper(DWORD id, float x, float y, float w, float h)
{
	pDrawGUI(id, x, y, w, h);

	if( gInterface.IsWorkZone(ButtonStartAttack) )
	{
		if( gInterface.Data[ButtonStartAttack].OnClick )
		{
			if(offhelper == 0)
			{
				offhelper = 1;
			}
			else
			{
				offhelper = 0;
			}
			gInterface.Data[ButtonStartAttack].OnClick = false;
		}
	}
	if(offhelper == 1)
	{
		gInterface.DrawButtonRender(ButtonStartAttack, x + 50, y + 8, 0, 0);
	}
	else
	{
		gInterface.DrawButtonRender(ButtonStartAttack, x + 50, y + 8, 0, 15);
	}
	gInterface.DrawFormat(eGold, x + 50 + 16, y + 12, 60, 1, "MuOffHelper");
}

#define pHelperMouseClick		((char(__thiscall*)(int a1)) 0x007D2920)

char FixHelperMouseClick(int a1)
{
	if(gInterface.CheckWindow(ChaosBox) || gInterface.CheckWindow(Warehouse))
		return 0;

	return pHelperMouseClick(a1);
}

void RenderWindowsHelper(int a1, float a2, float a3){
	gCMacroUIEx.DrawWindowBG(a2, a3);
	if(gCMacroUIEx.Drawbutton(gCMacroUIEx.CloseWindowsUP, a2 + 158.8, a3 + 24, ""))
	{
		gInterface.CloseWindow(MuHelper);
	}
	gInterface.DrawFormat(-1, a2, a3 + 24, *(float*)(0x00D24E88), 3, pGetTextLine(pTextLineThis, 3536));
	return;
}

void RenderWindowsHelperConfig(int a1, float a2, float a3)
{
	gCMacroUIEx.DrawWindowBG(a2, a3);
	if(gCMacroUIEx.Drawbutton(gCMacroUIEx.CloseWindowsUP, a2 + 158.8, a3 + 24, ""))
	{
		gInterface.CloseWindow(MuHelperConf);
	}
	gInterface.DrawFormat(-1, a2, a3 + 24, *(float*)(0x00D24E88), 3, "Config Helper");
	return;
}

void LoadWindowsNone_New(DWORD id, float x, float y, float w, float h){
	pDrawGUI(51522, x, y, w, h);
}

void CMacroUIEx::Load()
{
	//-------------------
	this->isSwitchServer = false;
	this->lastSwitch = GetTickCount() - DelaySwitchServer;
	this->macroSwitchServerHoving = false;
	
	//Test xD
	CustomFont.load();
	//--------------------------------------

	SetCompleteHook(0xE8,0x007D2B0C,&FixHelperMouseClick);

	SetCompleteHook(0xE8, 0x007F76CD, &OffHelper);

	if( gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4 )
	{
	    SetOp(0x007F65A6, RenderWindowsHelper, ASM::CALL);
	    SetCompleteHook(0xE8, 0x007F65E6, &LoadWindowsNone_New);
	    SetCompleteHook(0xE8, 0x007F6638, &LoadWindowsNone_New);
	    SetCompleteHook(0xE8, 0x007F66A2, &LoadWindowsNone_New);
    	SetCompleteHook(0xE8, 0x007F66FA, &LoadWindowsNone_New);
	    SetRange(0x007F6753, 5, ASM::NOP);//title
	    SetOp(0x0080C848, RenderWindowsHelperConfig, ASM::CALL);
	    SetCompleteHook(0xE8, 0x0080C87C, &LoadWindowsNone_New);
	    SetCompleteHook(0xE8, 0x0080C8BC, &LoadWindowsNone_New);
	    SetCompleteHook(0xE8, 0x0080C90E, &LoadWindowsNone_New);
	    SetCompleteHook(0xE8, 0x0080C954, &LoadWindowsNone_New);
	    SetRange(0x0080D78F, 5, ASM::NOP);//title auto recovery
	    SetRange(0x0080D772, 5, ASM::NOP);//title activation skill
		SetCompleteHook(0xE9, 0x007D2BC0, gCMacroUIEx.RenderFrame);
		//SetCompleteHook(0xE9, 0x007D2BC0, this->RenderFrame);
		SetCompleteHook(0xE9, 0x0080B8E0, &BarTime_1);
		SetCompleteHook(0xE9, 0x007D26B5, &MuHelperRemake_01);
		SetCompleteHook(0xE9, 0x007D2751, &MuHelperRemake_02);
		SetCompleteHook(0xE9, 0x007D27FC, &MuHelperRemake_03);
	}
	else
	{
		SetCompleteHook(0xE9, 0x007D26B5, &MuHelperRemake2_01);
		SetCompleteHook(0xE9, 0x007D2751, &MuHelperRemake2_02);
		SetCompleteHook(0xE9, 0x007D27FC, &MuHelperRemake2_03);
		SetCompleteHook(0xE9, 0x007D2BC0, this->RenderHelperFrame);
	}
}
