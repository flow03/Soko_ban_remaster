#pragma once

//#include <iostream>
//#include <Windows.h>
//#include <conio.h>

#include "Save.h"
#include "Warnings.h"
#include "ConsoleColor.h"
#include "MultiStr.h"


extern int Localization;
extern HANDLE consoleHandle;
extern bool isMenuActive;
extern bool isGameActive;
extern bool isGameStart;
extern int font;

void NextLevel(int); // extern

void RenderLanguage();

void UpdateLanguage();

void RenderFont();

void UpdateFont();

void UpdateLoad(int &selector, Save &savegame, int down);

void MainMenu();

void Settings();

void GameLoadMenu();

void CenterWindow();

void SetupFont();

