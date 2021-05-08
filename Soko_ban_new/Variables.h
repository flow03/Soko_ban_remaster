#pragma once

// Level settings
const int rowsCount = 18;
const int columnsCount = 16;
const int rowsCount3 = 13;

const unsigned char levelData1[10][columnsCount] = {
	"#####2#########",
	"#  X   #   X ##",
	"# X ### X  #  #",
	"#X X  X  ## X #",
	"# X    ##  #  #",
	"#######    # X#",
	"#   X   XX #X #",
	"#XXX # # X   ##",
	"#1 X #   X X  #",
#ifdef _DEBUG
	"##2############",
#else
	"###############",
#endif
};

#ifdef _DEBUG
const unsigned char levelData2[rowsCount][columnsCount] = {
	"###2#########",
	"#cb   # k# p#",
	"2  c#g## X   ",
	"# t #   ## ##",
	"# k   1   c 2",
	"#g# #b  ## X#",
	"# # c# #  X #",
	"#  # #   # ##",
	"#X   # ##c c#",
	"#  # #  #####",
	"#     # v #k#",
	"#c#XXX# # X #",
	"#p#   X #   #",
	"##    ### # #",
	"#  c# c  X  #",
	"#   #XXX  Xc#",
	"#c   c c c t#",
	"##2##########",

};
#else
const unsigned char levelData2[rowsCount][columnsCount] = {
	"#############",
	"#cb   # k# p#",
	"#  c#g## X  #",
	"#####   ## ##",
	"#     1 X   #",
	"#g# #   ## X#",
	"# # c# #  X #",
	"#  # #   # ##",
	"#X # # ##c c#",
	"#  # #  #####",
	"# #   # v #k#",
	"#c#XXX# # b #",
	"#p#   X #   #",
	"####  ### ###",
	"#  c# c  X  #",
	"#   #XbX  bc#",
	"#c  #c c c t#",
	"##2##########",
};
#endif
const unsigned char levelData3[rowsCount3][columnsCount] = {
	"#######2#######",
	"#          XkX#",
	"#           XX#",
	"#             #",
	"#             #",
	"2      1      2",
	"#             #",
	"#             #",
	"#             #",
	"#XX           #",
	"#XcX          #",
	"#######2#######",
	"               "
};

// Symbols
const unsigned char symbolHero = 2;
const unsigned char symbolWall = 219;
const unsigned char symbolBox = 254;
const unsigned char symbolExit = 176;
const unsigned char symbolCrystal = 3;
const unsigned char symbolDoorV = 186;
const unsigned char symbolDoorG = 205;
const unsigned char symbolPortal = 79;
const unsigned char symbolKey = 21;
const unsigned char symbolBomb = 15;

// Logic variables
HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
unsigned char levelData[rowsCount][columnsCount]; // Change for need
unsigned char Past[rowsCount3][columnsCount];
unsigned char Future[rowsCount3][columnsCount];
int heroRow = 0;
int heroColumn = 0;
int levelSelector = 3;	// Level
int KeyCount = 0;
int CrystalCount = 0;
int CrystalMaxCount = 0;
int randomCrystals = 10;
int Localization = 2;	// Language
int font = 1;			// Font
TCHAR szbuff[255];		// StringCchPrintf
CONSOLE_FONT_INFOEX defaultFont;
time_t start_time = 0;
time_t total_time;
unsigned char RestartKey = 'R';

bool isGameStart = false;
bool isGameActive = true;
bool isMenuActive = true;
bool EasyMode = false;
bool futureSelector = false;
bool portalWarn = false;



std::vector<COORD> markedMines;
std::vector<COORD> markedBoxes;
std::vector<COORD> futureMines;
std::vector<COORD> futureBoxes;
std::vector<COORD> pastBoxes;	// no mines in the past

// Global counters
int global_Crystals = 0;
int global_Keys = 0;
int global_Bombs = 0;
int global_Portals = 0;
int global_Boxes = 0;			// Всего ящиков подвигано раз
int global_Restarts = 0;

