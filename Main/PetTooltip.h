#pragma once

struct Tooltip
{
	int ItemIndex;
	char Name[256];
	int Arg[10];
	int Color1[10];
};


class cPetTooltip
{
public:
	void InitLoad();

};extern cPetTooltip gTooltip;