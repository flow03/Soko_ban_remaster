#pragma once

#include <iostream>
#include <iomanip>
#include <queue>
#include <Windows.h>
#include <conio.h>

#include "ConsoleColor.h"
#include "Achievements.h"
#include "Global_Variables.h"

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

extern std::queue<Warning> warning;

void Warnings(short &x_position);

void Description();

void Counters(short &x_position);

void Statistic();