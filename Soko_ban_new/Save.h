#pragma once
#include <fstream>

#include "Achievements.h"

//extern HANDLE consoleHandle;
//extern int Localization;

struct Save
{
	Save();

	void applySave() const;

	void SaveToFile();

	void LoadFromFile();

	int getLevel();

private:
	// Global counters
	int g_Crystals;
	int g_Keys;
	int g_Bombs;
	int g_Portals;
	int g_Boxes;
	int g_Restarts;

	// Achievements - maybe bool might be better
	bool AllAchieves_A;
	bool AllCrystals_A;
	bool lvl3_Crystals_A;
	bool lvl3_Restarts_A;
	bool NullRestarts_A;
	bool PovorotNeTyda_A;
	bool OnMyWay_A;
	bool AllMines_A;

	time_t t_time;

	//int heroRow;
	//int heroColumn;
	int l_Selector;	// Level
	//int KeyCount;
	//int CrystalCount;
	//int CrystalMaxCount;
	//int randomCrystals = 10;
	//int Localization = 2;	// Language
	//int font = 1;			// Font

	//bool EasyMode = true;
	//bool futureSelector = false;
	//bool portalWarn = false;
};

void LoadDescription();