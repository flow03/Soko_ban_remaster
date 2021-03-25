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
int Localization = 2;	//Language
int font = 1;			// Font
TCHAR szbuff[255];		//StringCchPrintf
CONSOLE_FONT_INFOEX defaultFont;
int randomCrystals = 10;
time_t start_time = 0;

std::vector<COORD> markedMines;
std::vector<COORD> markedBoxes;

bool futureSelector = false;

// Global counters
int global_Crystals = 0;
int global_Keys = 0;
int global_Bombs = 0;
int global_Portals = 0;
int global_Boxes = 0;			// Всего ящиков подвигано раз
int global_Restarts = 0;

// Achieve sub variables(with a_ prefix)
int a_UniBombsDie = 0;			// Смерть на новой бомбе
int a_UniBoxMove = 0;			// Разных ящиков подвигано
int a_AchievesCount = 0;		// Разблокировано достижений
int a_AchievesMax = 10;			// Достижений всего

struct Ahieve;

// Achievements
Ahieve AllMinesAchieve = { true, "Взорваться на всех минах" };			// Взорваться на всех минах
Ahieve AllCrystalsAchieve = true;			// Собрать все кристаллы в игре
Ahieve lvl3_CrystalsAchieve = true;			// Собрать все кристаллы на уровне 3
Ahieve TenRestartsAchieve = false;			// 10 рестартов подряд на уровне 3
//bool NullRestartsAchieve = false;			// 0 рестартов игры
//bool PovorotNeTydaAchieve = false;		// Поворот не туда(за нахождение секретной комнаты)
//bool OnMyWayAchieve = false;			// По своим следам
//
//bool AllAchieves = false;				// Сбор всех достижений

struct Ahieve
{
	bool value;
	const char * label;

	Ahieve(bool val, const char * lab) : value(val), label(lab) {}
	Ahieve(bool val) : value(val) {}

	Ahieve operator=(bool val) { this->value = val; return this;}
	Ahieve operator=(const char * lab) { this->label = lab; return this;}
};