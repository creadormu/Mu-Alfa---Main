#pragma once
#include "Interface.h"

class BankOfJewel
{
public:
	bool CheckBank(){ return gInterface.Data[eJewelOfBank].OnShow; };
	void SendJewel();
	void RecvJewel();
	void RenderJewelOFBank();
	void OpenBank();
	void CloseBank(){ gInterface.Data[eJewelOfBank].OnShow = false; };
};
extern BankOfJewel JewelOfBack;