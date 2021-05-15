#pragma once

//#include <iostream>
//#include <Windows.h>
//#include <conio.h>

#include "Save.h"
#include "Warnings.h"
#include "ConsoleColor.h"
#include "MultiStr.h"


//extern int Localization;
//extern HANDLE consoleHandle;
//extern bool isMenuActive;
//extern bool isGameActive;
//extern bool isGameStart;
//extern int font;

void MainMenu();

void NewSettings();

void SaveLoadMenu();

void CenterWindow();

void SetupFont();

void LoadList();

void SaveList();

template <class f_type>
void Confirmation(MultiStr str, f_type func);