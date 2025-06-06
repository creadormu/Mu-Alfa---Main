enum iInterface
{
	iNewCharacter = 0x7A48,
	iNewInventory = 0x7A49,
	iNewWinpush = 0x7A4A,
	iNewFastMenu = 0x7A4B,
	iNewSkillBox = 0x7A50,
	iNewParty = 0x910,
	iNewGuild = 0x904,
};

void PetHPBarRemake(signed int x, signed int y, int nameIndex, signed int hp, signed int hpmax, char a9);
void InitInter3();
void RemoveSocket();