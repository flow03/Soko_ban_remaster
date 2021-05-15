#pragma once

#include <Windows.h>
#include <vector>
#include <ctime>

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
extern HANDLE consoleHandle;
extern unsigned char levelData[rowsCount][columnsCount]; // Change for need
extern unsigned char Past[rowsCount3][columnsCount];
extern unsigned char Future[rowsCount3][columnsCount];
extern int heroRow;
extern int heroColumn;
extern int levelSelector;
extern int KeyCount;
extern int CrystalCount;
extern int CrystalMaxCount;
extern int randomCrystals;
extern int Localization;
extern int font;
extern TCHAR szbuff[255];
extern CONSOLE_FONT_INFOEX defaultFont;
extern time_t start_time;
extern time_t total_time;
extern unsigned char RestartKey;

extern bool isGameStart;
extern bool isGameActive;
extern bool isMenuActive;
extern bool EasyMode;
extern bool futureSelector;
extern bool portalWarn;

typedef std::vector<COORD> vec;

extern std::vector<vec> new_markedMines;
extern std::vector<vec> new_markedBoxes;

extern std::vector<COORD> markedMines;
extern std::vector<COORD> markedBoxes;
extern std::vector<COORD> futureMines;
extern std::vector<COORD> futureBoxes;
extern std::vector<COORD> pastBoxes;

// Global counters
extern int global_Crystals;
extern int global_Keys;
extern int global_Bombs;
extern int global_Portals;
extern int global_Boxes;
extern int global_Restarts;