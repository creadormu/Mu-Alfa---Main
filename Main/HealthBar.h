#pragma once

#define MAX_MAIN_VIEWPORT 400
#define RGBTOGLFLOAT(x) ((float)x/255.0f)
#define FLOATTORGB(x)	((float)x*255)
#define ABS(x) (((x) < 0) ? (-(x)) : (x))


struct NEW_HEALTH_BAR
{
	WORD index;
	BYTE type;
	BYTE rate;
	BYTE rate2;
};

void ClearNewHealthBar();
void InsertNewHealthBar(WORD index,BYTE type,BYTE rate,BYTE rate2);
NEW_HEALTH_BAR* GetNewHealthBar(WORD index,BYTE type);
void DrawNewHealthBar();