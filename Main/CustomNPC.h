#pragma once

class NPC {
  public:
    void        Load();
    // ----
    static void FixShowLevel();
    static void ElfSoldier();
    static void Marlon();
    static void ChaosCardMaster();
    static void Guard1();
    static void Guard2();
	static void CursedWizard();
	static void LuckLeoTheHelper();
    // ----
}; extern NPC gNPC;