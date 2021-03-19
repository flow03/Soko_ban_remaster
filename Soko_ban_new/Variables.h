#pragma once

// Symbols
const unsigned char symbolHero = 2;
const unsigned char symbolWall = 219;
const unsigned char symbolBox = 254;
const unsigned char symbolExit = 176;
const unsigned char symbolCrystal = 3;
const unsigned char symbolDoorV = 186;
const unsigned char symbolDoorG = 205;
const unsigned char symbolPortal = 79;
//const unsigned char symbolPoint = 46;
const unsigned char symbolKey = 21;
const unsigned char symbolBomb = 15;

// Logic variables
const int rowsCount = 18;
const int columnsCount = 16;
const int rowsCount3 = 13;

HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
bool isGameActive = true;
unsigned char levelData[rowsCount][columnsCount]; // Change for need
unsigned char Past[rowsCount3][columnsCount];
unsigned char Future[rowsCount3][columnsCount];
int heroRow = 0;
int heroColumn = 0;
int levelSelector = 1;
int CrystalCount = 0;
int KeyCount = 0;
int Localization = 1;	//Language
int font = 1;			// Font
TCHAR szbuff[255];		//StringCchPrintf
CONSOLE_FONT_INFOEX defaultFont;
int randomCrystals = 10;

bool futureSelector = false;

// Global counters
//int global_Keys = 0;
//int global_Crystals = 0;
//int global_Restarts = 0;
//int global_Mines = 0;
//
//// Achievements
//bool AllMinesAchieve = false;
//bool AllCrystalsAchieve = false;
//bool NullRestartsAchieve = false;
//bool PovorotNeTydaAchieve = false;		// Поворот не туда(за нахождение секретной комнаты)
//bool OnMyWayAchieve = false;			// По своим следам
//
//bool AllAchieves = false;				// Сбор всех достижений
