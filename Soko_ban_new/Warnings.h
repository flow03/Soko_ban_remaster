#pragma once

#include <iostream>
#include <iomanip>
#include <queue>
#include <Windows.h>
#include <conio.h>

#include "ConsoleColor.h"
#include "Achievements.h"

enum Warning
{
	None,
	keyWarning,
	crystalWarning,
	bombWarning,
	bonusWallWarning,
	bonusLevelWarning,
	portalWarning,
	secretDoorWarning,
	secretBombsWarning,
	secretBombLeft,
	secretBombRight,
	secretBombDamn = 100,	// set enum range
};

extern int levelSelector;
extern int Localization;
extern HANDLE consoleHandle;
extern int CrystalCount;
extern int CrystalMaxCount;
extern int KeyCount;
extern time_t start_time;
extern time_t total_time;

// Global counters
extern int global_Crystals;
extern int global_Keys;
extern int global_Bombs;
extern int global_Portals;
extern int global_Boxes;
extern int global_Restarts;

extern std::queue<Warning> warning;

void Warnings(short &x_position);

void Description();

void Counters(short &x_position);

void Statistic();

void out_SaveDescription();