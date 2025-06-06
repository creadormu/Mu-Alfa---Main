
#pragma once

#include "Protocol.h"

class CSelectChar
{
public:
	CSelectChar();
	~CSelectChar();
	// ----
	static void SelectChar();
	void	EventSelectChar(DWORD Event);
	// ----
public:
	int m_CharacterPage;
	// ----
}; extern CSelectChar gSelectChar;
