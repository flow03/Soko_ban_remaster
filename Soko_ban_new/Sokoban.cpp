
// Include libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h> 
#include <conio.h>
#include <ctype.h>
#include <locale.h>
//#include <assert.h>
#include <strsafe.h> //StringCchPrintf
#include <iostream>

#include "ConsoleColor.h"




// Game settings
const int rowsCount = 18;
const int columnsCount = 16;

const unsigned char symbolHero = 2;
const unsigned char symbolWall = 219;
const unsigned char symbolBox = 254;
const unsigned char symbolExit = 176;
const unsigned char symbolCrystal = 3;
const unsigned char symbolDoorV = 186;
const unsigned char symbolDoorG = 205;
const unsigned char symbolPortal = 79;
const unsigned char symbolPoint = 46;
const unsigned char symbolKey = 21;
const unsigned char symbolBomb = 15;


const unsigned char levelData1[10][16] =  {
	"#####2#########",
	"#  X   #   X ##",
	"# X ### X  #  #",
	"#X X  X  ## X #",
	"# X    ##  #  #",
	"#######    # X#",
	"#   X   XX #X #",
	"#XXX # # X   ##",
	"#1 X #   X X  #",
	"##2############",
                                                                };

const int rowsCount2 = 18;
const int columnsCount2 = 15;

const unsigned char levelData2[rowsCount2][columnsCount2 + 1] = {
	"###2#########",
	"#cb   # k# p#",
	"2  c#g## X   ",
	"# t #   ## ##",
	"#     1     2",
	"#g# #b  ## X#",
	"# # c# #  X #",
	"#  # #   # ##",
	"#X   # ##c c#",
	"#  # #  #####",
	"#     # v #k#",
	"#c#XXX# # b #",
	"#p#   X #   #",
	"##    ### # #",
	"#  c# c  X  #",
	"#   #XbX  bc#",
	"#c   c c c t#",
	"##2##########",

                                                                  };

const int rowsCount3 = 13;
//const int columnsCount3 = 16;

const unsigned char levelData3[rowsCount3][columnsCount] = {
	"#######2#######",
	"#          XkX#",
	"#       c   XX#",
	"#     c       #",
	"#         c   #",
	"2  c   1       ",
	"#          c  #",
	"#      c       ",
	"#        c    #",
	"#XX           #",
	"#XcX          #",
	"##### #2#######",
	"               "
                                                               };

const unsigned char levelData4[rowsCount3][columnsCount] = {
	"############22#",
	"#   X   X  #  #",
	"#X  X  X XX#tt#",
	"#  ####### #  #",
	"#  # v   # #  #",
	"#XX# #   # #  #",
	"#  # ##### #tt#",
	"#  #       #  #",
	"#XX#########  #",
	"#  b   bXXXXtt#",
	"#    b tXXXX  #",
	"###############",
	"               ",
};



// Logic variables
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
int Localization = 2; //Language
int font = 1; // Font
TCHAR szbuff[255]; //StringCchPrintf
CONSOLE_FONT_INFOEX defaultFont;

#include "Warnings.h"

//bool warning1 = false;
//bool warning2 = false;
//bool bombSelector = false;
//bool bonusWallSelector = false;
//bool bonusWallWarning = false;
//bool secretDoorSelector = false;
//bool secretDoorWarning = false;
//bool secretBombsWarning = false;
//bool bonusLevelWarning = false;

bool futureSelector = false;



// Functions
void CenterWindow()
{
	HWND consoleWindow = GetConsoleWindow();

	RECT r;
	GetWindowRect(consoleWindow, &r);
	int x = GetSystemMetrics(SM_CXSCREEN) / 2 - (r.right - r.left) / 2;
	int y = GetSystemMetrics(SM_CYSCREEN) / 2 - (r.bottom - r.top) / 2;

	SetWindowPos(consoleWindow, NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

void SetupFont()
{
	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.cbSize = sizeof(fontInfo);

	GetCurrentConsoleFontEx(consoleHandle, TRUE, &fontInfo); // Получить текущий шрифт

	if (font == 0)
	{
		fontInfo.dwFontSize.X = 8;
		fontInfo.dwFontSize.Y = 12;
	}
	else if (font == 1)
	{
		fontInfo.dwFontSize.X = 12;
		fontInfo.dwFontSize.Y = 16;
	}

	fontInfo.FontFamily = FF_MODERN;
	wcscpy_s(fontInfo.FaceName, L"Terminal");
	fontInfo.nFont = 6;

	SetCurrentConsoleFontEx(consoleHandle, TRUE, &fontInfo); // Установить измененный шрифт

	CenterWindow();
}

void SetupSystem()
{
	//consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFOEX scrBuffer;
	scrBuffer.cbSize = sizeof(scrBuffer);

	_CONSOLE_CURSOR_INFO cursorInfo;

	GetCurrentConsoleFontEx(consoleHandle, TRUE, &defaultFont); // Запомнить текущий шрифт
	GetConsoleScreenBufferInfoEx(consoleHandle, &scrBuffer);
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);

	//Размер буфера консоли
	scrBuffer.dwSize = COORD{ 80,26 };
	//Размер окна консоли
	scrBuffer.srWindow = SMALL_RECT{ 0,0,80,26 };
	//Максимальный(растягиваемый) размер окна консоли
	scrBuffer.dwMaximumWindowSize = COORD{ 80,26 };
	//Полноэкранный режим
	scrBuffer.bFullscreenSupported = false;
	//Делаем курсор невидимым
	cursorInfo.bVisible = false;

	SetConsoleScreenBufferInfoEx(consoleHandle, &scrBuffer);
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
	//SetCurrentConsoleFontEx(consoleHandle, TRUE, &fontInfo); // Установить измененный шрифт

	SetupFont();
	CenterWindow();

	setlocale(LC_ALL, "RUS");
}

void RenderLanguage()
{
	SetConsoleCursorPosition(consoleHandle, COORD{ 0,0 });
	setlocale(LC_ALL, "Russian");
	//setlocale(LC_ALL, ".UTF-8");
	//setlocale(LC_CTYPE, ".866");
	//setlocale(0, "");
	std::cout << std::endl;

	switch (Localization)
	{
		case 1:
		{
			std::wcout << L"\n\t\t\t Будь ласка, оберiть вашу мову"; //54
			break;
		}
		case 2:
		{
			std::wcout << L"\n\t\t\t\t Выберите язык\t\t\t"; //46
			break;
		}
		case 3:
		{
			std::wcout << L"\n\t\t\t      Select your language    "; 
			break;
		}
	}

	std::cout << "\n\n";

	if (Localization == 1)
	{
		std::cout << "\n\t\t\t\t ";
		printColorText(consoleHandle, symbolHero, LightGreen);
		printColorText(consoleHandle, " Українська\n", Yellow);
	}
	else
	{
		std::cout << "\n\t\t\t\t   Українська\n";
	}

	if (Localization == 2)
	{
		std::cout << "\n\t\t\t\t ";
		printColorText(consoleHandle, symbolHero, LightGreen);
		printColorText(consoleHandle, "  Русский\n", Yellow);
	}
	else
	{
		std::cout << "\n\t\t\t\t    Русский\n";
	}

	if (Localization == 3)
	{
		std::cout << "\n\t\t\t\t ";
		printColorText(consoleHandle, symbolHero, LightGreen);
		printColorText(consoleHandle, "  English\n", Yellow);
	}
	else
	{
		std::cout << "\n\t\t\t\t    English\n";
	}

	std::cout << "\n\n";

	switch (Localization)
	{
	case 1:
	{
		std::cout << "\n\t\t\t\tНатиснiть Enter"; //32+15
		break;
	}
	case 2:
	{
		std::cout << "\n\t\t\t\t Нажмите Enter\t"; //33+13
		break;
	}
	case 3:
	{
		std::cout << "\n\t\t\t\t  Press Enter\t"; //34+11
		break;
	}
	}
}

void UpdateLanguage()
{
	char Key = _getch();

	switch (Key)
	{
		// Arrow down
		case 80:
		case 's':
		case 'S':
		{
			Localization++;
			if (Localization > 3)
				Localization = 1;

			break;
		}
		// Arrow up
		case 72:
		case 'w':
		case 'W':
		{
			Localization--;
			if (Localization < 1)
				Localization = 3;

			break;
		}
		// Enter
		case 13:
		{
			isGameActive = false;
			break;
		}
	}
}

void RenderFont()
{
	SetConsoleCursorPosition(consoleHandle, COORD{ 0, 13 }); //(y, x)
	//system("cls");
	setlocale(LC_ALL, "Russian");
	//setlocale(0, "");
	std::cout << std::endl << std::endl;


	std::cout << "\n\t\t\t\t   "; 
	if (font == 0)
	{
		printColorText(consoleHandle, symbolHero, LightGreen);
		printColorText(consoleHandle, " 8x12\n", Yellow);
	}
	else
	{
		std::cout << "  8x12\n";
	}

	std::cout << "\n\t\t\t\t   ";
	if (font == 1)
	{
		printColorText(consoleHandle, symbolHero, LightGreen);
		printColorText(consoleHandle, " 12x16\n", Yellow);
	}
	else
	{
		std::cout << "  12x16\n";
	}

	std::cout << std::endl << std::endl;

	switch (Localization)
	{
	case 1:
	{
		std::cout << "\t\t\t\t Розмiр шрифту";
		break;
	}
	case 2:
	{
		std::cout << "\t\t\t\t Выберите шрифт\t\t\t";
		break;
	}
	case 3:
	{
		std::cout << "\t\t\t     Select your font size";
		break;
	}
	}
}

void UpdateFont()
{
	char Key = _getch();

	switch (Key)
	{
	// Arrow down
	case 80:
	case 's':
	case 'S':
	{
		font++;
		if (font > 1)
			font = 0;

		break;
	}
	// Arrow up
	case 72:
	case 'w':
	case 'W':
	{
		font--;
		if (font < 0)
			font = 1;

		break;
	}
	// Enter
	case 13:
	{
		isGameActive = false;
		break;
	}
	}

	/*if (font == 0) SetupFont(8, 12);
	else if (font == 1) SetupFont(12, 16);*/
	SetupFont();
	CenterWindow();
}

void InitialiseOld(int rows, int columns)
{
	// Load level
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < columns; c++)
		{
			
			unsigned char symbol = levelData1[r][c];

			switch (symbol)
			{
				// Wall
				case '#':
				{
					levelData[r][c] = symbolWall;
					break;
				}
				// Hero
				case '1':
				{
					levelData[r][c] = symbolHero;
					// Catch hero position
					heroRow = r;
					heroColumn = c;

					break;
				}
				// Exit
				case '2':
				{
					levelData[r][c] = symbolExit;
					break;
				}
				// Box
				case 'X':
				{
					levelData[r][c] = symbolBox;
					break;
				}
				// Other symbols (like spaces)
				default:
				{
					levelData[r][c] = symbol;
					break;
				}
			}
		}
	}
}

template <size_t N>
void Initialise(const unsigned char(*lvl_begin)[N], const unsigned char(*lvl_end)[N])
{
	// Load level

	// Clear levelData from previos level
	for (int r = 0; r < rowsCount; r++)
	{
		for (int c = 0; c < columnsCount; ++c)
		{
			levelData[r][c] = '\0';
		}
	}

	
	int currentRow = 0;
	//Initialise
	for (const unsigned char(*row)[N] = lvl_begin; row != lvl_end; ++row)
	{
		for (int c = 0; c < N; ++c)
		{
			switch ((*row)[c])
			{
			// Wall
			case '#':
			{
				levelData[currentRow][c] = symbolWall;
				break;
			}
			// Hero
			case '1':
			{
				levelData[currentRow][c] = symbolHero;
				// Catch hero position
				heroRow = currentRow;
				heroColumn = c;

				break;
			}
			// Exit
			case '2':
			{
				levelData[currentRow][c] = symbolExit;
				break;
			}
			// Box
			case 'X':
			{
				levelData[currentRow][c] = symbolBox;
				break;
			}
			// Crystal
			case 'c':
			{
				levelData[currentRow][c] = symbolCrystal;
				break;
			}
			// Vertical door
			case 'v':
			{
				levelData[currentRow][c] = symbolDoorV;
				break;
			}
			// Gorisontal door
			case 'g':
			{
				levelData[currentRow][c] = symbolDoorG;
				break;
			}
			// Portal
			case 'p':
			{
				levelData[currentRow][c] = symbolPortal;
				break;
			}
			// Point
			case '.':
			{
				levelData[currentRow][c] = symbolPoint;
				break;
			}
			// Key
			case 'k':
			{
				levelData[currentRow][c] = symbolKey;
				break;
			}
			// Bomb
			case 'b':
			{
				levelData[currentRow][c] = symbolBomb;
				break;
			}
			// Other symbols (like spaces)
			default:
			{
				levelData[currentRow][c] = (*row)[c];
				break;
			}
			}
		}
		++currentRow;
	}
}

void LevelClear()
{
	CrystalCount = 0;
	KeyCount = 0;
	futureSelector = false;

	if (levelSelector == 1)
		Initialise(std::begin(levelData1), std::end(levelData1));
	else if (levelSelector == 2)
		Initialise(std::begin(levelData2), std::end(levelData2));
	else if (levelSelector == 3)
		Initialise(std::begin(levelData3), std::end(levelData3));
	else if (levelSelector == 4)
	{
		levelSelector = 3;
		Initialise(std::begin(levelData3), std::end(levelData3));
	}

	/*std::cin.clear();
	fflush(stdin);*/
}

void Render()
{
	// Move console cursor to (0,0)
	SetConsoleCursorPosition(consoleHandle, COORD{ 0,0 });
	//system("cls");

	setlocale(LC_ALL, "C");

	std::cout<<'\n';
	/*for (int r = 0; r < rowsCount; ++r)
	{
		if (levelData[r][0] != '\0')
			std::cout << "\n\t\t\t\t  " << levelData[r];
	}*/
	for (int r = 0; r < rowsCount; ++r)
	{
		if (levelData[r][0] != '\0')
		{
		std::cout << "\n\t\t\t\t  ";
		for (int c = 0; c < columnsCount; ++c)
		{
			unsigned char symbol = levelData[r][c];

			switch (symbol)
			{
				// Walls - grey
			case symbolWall:
			{
				std::cout << symbolWall;
				break;
			}
			// Empty cells
			case ' ':
			{
				std::cout << ' ';
				break;
			}
			// Hero - green
			case symbolHero:
			{
				printColorText(consoleHandle, symbolHero, LightGreen);
				break;
			}
			// Boxes - yellow
			case symbolBox:
			{
				printColorText(consoleHandle, symbolBox, Yellow);
				break;
			}
			// Exit - red
			case symbolExit:
			{
				printColorText(consoleHandle, symbolExit, Red);
				break;
			}
			// Crystal - Magenta
			case symbolCrystal:
			{
				printColorText(consoleHandle, symbolCrystal, Magenta);
				break;
			}
			// Portal - LightCyan
			case symbolPortal:
			{
				if (levelSelector != 3)
					printColorText(consoleHandle, symbolPortal, LightCyan);
				else
				{
					if ((r == 6) && (c == 5))
						printColorText(consoleHandle, symbolPortal, Magenta);
					else if ((r == 6) && (c == 9))
						printColorText(consoleHandle, symbolPortal, LightMagenta);
					else
						printColorText(consoleHandle, symbolPortal, LightCyan);
				}

				/*if ((levelSelector == 3) && (r == 6) && (c == 5))
					printColorText(consoleHandle, symbolPortal, Magenta);
				else if ((levelSelector == 3) && (r == 6) && (c == 9))
					printColorText(consoleHandle, symbolPortal, LightMagenta);
				else printColorText(consoleHandle, symbolPortal, LightCyan);*/
				break;
			}
			// Point - LightCyan
			case symbolPoint:
			{
				printColorText(consoleHandle, symbolPoint, LightCyan);
				break;
			}
			// Gorisontal door - grey
			case symbolDoorG:
			{
				std::cout << symbolDoorG;
				break;
			}
			case symbolDoorV:
			{
				std::cout << symbolDoorV;
				break;
			}
			// Key - LightMagenta
			case symbolKey:
			{
				printColorText(consoleHandle, symbolKey, LightMagenta);
				break;
			}
			// Bomb - Red
			case symbolBomb:
			{
				printColorText(consoleHandle, symbolBomb, Red);
				break;
			}
			// Trap
			case 't': //t
			{
				std::cout << ' ';
				break;
			}
			// SymbolHeroDie
			case 'd':
			{
				//symbol = symbolHero;
				printColorText(consoleHandle, symbolHero, Red);
				break;
			}
			case '\0': // нулевой символ
				break;
			}

			//printf("%c", symbol);
			//std::cout << symbol;
		}
		}
		else break; // delete if /0 row is not in the end of lvl array
	}

	// Crystal/Key counters
	Counters();

	// Warnings
	Warnings(warning); //warning reset in the end of Warnings func(not in the MoveHeroTo func)
	Description();

	//SetConsoleTitle
	StringCchPrintf(szbuff, 255, TEXT("row %d column %d"), heroRow, heroColumn);
	SetConsoleTitle(szbuff);
}

void BonusWall()
{
	warning = bonusWallWarning;
	levelData[14][8] = symbolWall;
	Render();
	Sleep(275);

	warning = bonusWallWarning;
	levelData[15][8] = symbolWall;
	Render();
	Sleep(275);

	warning = bonusWallWarning;
	levelData[16][8] = symbolWall;
	Render();
	Sleep(275);

	warning = bonusWallWarning;
	levelData[16][6] = symbolKey;
}

void DieAnimation(int row, int column) {

	for (int i = 0; i < 3; ++i)
	{
		warning = bombWarning;
		levelData[row][column] = 'd';
		Render();
		Sleep(225);

		warning = bombWarning;
		levelData[row][column] = ' ';
		Render();
		Sleep(225);
	}

	//using namespace std;
	/*std::cin.clear();
	fflush(stdin);*/
	//_getch();
	//_getch();
	//system("cls");
}

void MoveHeroTo(int row, int column)
{
	unsigned char destinationCell = levelData[row][column];
	bool canMoveToCell = false;
	//warning = None; //warning reset

	switch (destinationCell)
	{
		// Empty cell
		case ' ':
		{
			canMoveToCell = true;
			break;
		}
		// Exit cell
		case symbolExit:
		{
			if ((levelSelector == 2) && (CrystalCount < 1)) //13
			{
				warning = crystalWarning;
				//warning2 = true;
				canMoveToCell = false;
			}
			else
			if (levelSelector == 3)
			{
				levelData[row][column] = symbolWall;
				canMoveToCell = false;
			}
			else
			if ((levelSelector == 4) && (CrystalCount < 14)) //13
			{
				//warning2 = true;
				warning = crystalWarning;
				canMoveToCell = false;
				levelData[4][7] = symbolPortal;
			}
			else
			isGameActive = false;
		    
			break;
		}
		// Crystal
		case symbolCrystal:
		{
			++CrystalCount;
			//canMoveToCell = true; // error purpose
			if (levelSelector == 3)
			{
				if (CrystalCount == 1) //5
				{
					levelData[6][5] = symbolPortal;
					levelData[6][9] = symbolPortal;
					canMoveToCell = true;
				}
				else if (CrystalCount == 7)
				{
					levelData[5][6] = symbolCrystal;
					levelData[5][7] = symbolCrystal;
					levelData[5][8] = symbolCrystal;
					levelData[4][6] = symbolCrystal;
					levelData[4][7] = symbolCrystal;
					levelData[4][8] = symbolCrystal;
					canMoveToCell = true;
				}
				else if (CrystalCount == 13) 
				{
					levelData[heroRow][heroColumn] = ' ';
					levelData[row][column] = ' ';
					// Save Past array
					for (int r = 0; r < rowsCount3; r++)
						for (int c = 0; c < columnsCount; c++)
						{
							Past[r][c] = levelData[r][c];
						}

					if (futureSelector == false)
					{
						levelSelector = 4;
						Initialise(std::begin(levelData4), std::end(levelData4));
						warning = bonusLevelWarning;
						futureSelector = true;

						heroRow = 5;
						heroColumn = 7;
						levelData[heroRow][heroColumn] = symbolHero;
					}
					else
					{
						levelSelector = 4;
						// Load future array
						for (int r = 0; r < rowsCount3; r++)
							for (int c = 0; c < columnsCount; c++)
							{
								levelData[r][c] = Future[r][c];
							}

						heroRow = 5;
						heroColumn = 7;
						levelData[heroRow][heroColumn] = symbolHero;
					}
				}
				else canMoveToCell = true;
			}
			else canMoveToCell = true;

			break;
		}
		// Portal
		case symbolPortal:
		{
			if (levelSelector == 2 && row == 1 && column == 11)
			{
				levelData[heroRow][heroColumn] = ' ';
				heroRow = 1;
				heroColumn = 7;
				levelData[1][7] = symbolHero;
			}
			else if (levelSelector == 2 && row == 12 && column == 1)
			{
				levelData[heroRow][heroColumn] = ' ';
				heroRow = 15;
				heroColumn = 2;
				levelData[15][2] = symbolHero;
			}
			else if (levelSelector == 3 && row == 6 && column == 9) // Key Portal
			{
				levelData[heroRow][heroColumn] = ' ';
				if (levelData[1][12] == symbolKey)
				{
					heroRow = 1;
					heroColumn = 13;
				}
				else
				{
					heroRow = 10;
					heroColumn = 1;
				}
				levelData[heroRow][heroColumn] = symbolHero;
			}
			else if (levelSelector == 3 && row == 6 && column == 5) // Old Portal
			{
				levelData[heroRow][heroColumn] = ' ';
				// Save Past array
				for (int r = 0; r < rowsCount3; r++)
				for (int c = 0; c < columnsCount; c++)
				{
					Past[r][c] = levelData[r][c];
				}

				if (futureSelector == false)
				{
					levelSelector = 4;
					Initialise(std::begin(levelData4), std::end(levelData4));
					heroRow = 10;
					heroColumn = 6;
					levelData[heroRow][heroColumn] = symbolHero;

					warning = bonusLevelWarning;
					futureSelector = true;
				}
				else
				{
					// Load future array
					for (int r = 0; r < rowsCount3; r++)
						for (int c = 0; c < columnsCount; c++)
						{
							levelData[r][c] = Future[r][c];
						}

					levelSelector = 4;
					heroRow = 5;
					heroColumn = 7;
					levelData[heroRow][heroColumn] = symbolHero;
				}
			}
			else
			if (levelSelector == 4 && row == 4 && column == 7) // New Portal
			{
				levelData[heroRow][heroColumn] = ' ';
				// Save Future array
				for (int r = 0; r < rowsCount3; r++)
					for (int c = 0; c < columnsCount; c++)
					{
						Future[r][c] = levelData[r][c];
					}
				// Load Past array
				for (int r = 0; r < rowsCount3; r++)
					for (int c = 0; c < columnsCount; c++)
					{
						levelData[r][c] = Past[r][c];
					}

				levelSelector = 3;
				heroRow = 6;
				heroColumn = 7;
				levelData[6][7] = symbolHero;
			}
			
			break;
		}
		// Key
		case symbolKey:
		{
			++KeyCount;
			canMoveToCell = true;

			if (levelSelector == 4)
				if((levelData[8][6] != ' ') && row == 10 && column == 13)
					levelData[8][6] = symbolDoorG;
			break;
		}
		// Gorisontal door
		case symbolDoorG:
		{
			if (KeyCount > 0)
			{
				KeyCount = KeyCount - 1;
				canMoveToCell = true;

				if (levelSelector == 4)
				{
					if (row == 1 && column == 12)
						levelData[1][13] = ' ';
					else if (row == 1 && column == 13)
						levelData[1][12] = ' ';
					else if (row == 8 && column == 6)
						levelData[10][13] = symbolKey;
				}
			}
			else
			{
				//warning1 = true;
				warning = keyWarning;
			}
			break;
		}
		// Vertical door
		case symbolDoorV:
		{
			if (KeyCount > 0)
			{
				--KeyCount;
				canMoveToCell = true;
			}
			else warning = keyWarning;
			break;
		}
		// Bomb
		case symbolBomb:
		{
			levelData[heroRow][heroColumn] = ' ';
			
			DieAnimation(row, column);
			LevelClear();
			
			break;
		}
		// Box
		case symbolBox:
		{
			// Calculate hero move direction
			int heroDirectionR = row - heroRow;
			int heroDirectionC = column - heroColumn;

			// Check for empty space behind the box
			if (levelData[row + heroDirectionR][column + heroDirectionC] == ' ')
			{
				canMoveToCell = true;

				// Remove box symbol from previous position
				levelData[row][column] = ' ';

				// Set box symbol to new position
				levelData[row + heroDirectionR][column + heroDirectionC] = symbolBox;
			}
			break;
		}
		// Trap
		case 't': //116ui8 /t
		{
			// Bonus wall
			if (levelSelector == 2) // && row == 16 && column == 11) // && (bonusWallSelector == false))
			{
				//canMoveToCell = true;
				levelData[heroRow][heroColumn] = ' ';
				heroRow = row;
				heroColumn = column;
				levelData[heroRow][heroColumn] = symbolHero;

				BonusWall();
			}
			
			else if (levelSelector == 4)
			{
				// Secret door
				if (row == 10 && column == 7)
				{
					warning = secretDoorWarning;

					levelData[11][7] = ' ';
					levelData[11][12] = 't';
					levelData[11][13] = 't';
				}
				// Secret bombs warning
				else if ((row == 11 && column == 12))
				{
					warning = secretBombsWarning;
					levelData[11][13] = ' ';
				}
				else if ((row == 11 && column == 13))
				{
					warning = secretBombsWarning;
					levelData[11][12] = ' ';
				}
				// Secret bombs
				else if (row == 9 && column == 12)
				{
					levelData[7][12] = symbolBomb;
					if (levelData[7][13] != symbolBomb) warning = secretBombRight;
					else 
					{ 
						warning = secretBombDamn; 
						levelData[6][11] = ' ';
					}
				}
				else if (row == 9 && column == 13)
				{
					levelData[7][13] = symbolBomb;
					if(levelData[7][12] != symbolBomb) warning = secretBombLeft;
					else
					{
						warning = secretBombDamn;
						levelData[6][11] = ' ';
					}
				}
				else if (row == 6 && column == 12)
				{
					levelData[4][12] = symbolBomb;
					if (levelData[4][13] != symbolBomb) warning = secretBombRight;
					else 
					{
						warning = secretBombDamn;
						levelData[3][11] = ' ';
						levelData[5][10] = symbolWall;
						levelData[4][9] = ' ';
					}
				}
				else if (row == 6 && column == 13)
				{
					levelData[4][13] = symbolBomb;
					if (levelData[4][12] != symbolBomb) warning = secretBombLeft;
					else 
					{
						warning = secretBombDamn;
						levelData[3][11] = ' ';
						levelData[5][10] = symbolWall;
						levelData[4][9] = ' ';
					}
				}
				// Final Door
				else if ((row == 2) && (column == 12 || column == 13))
				{
					levelData[1][12] = symbolDoorG;
					levelData[1][13] = symbolDoorG;
					levelData[10][13] = symbolKey;
					levelData[4][9] = ' '; // shortcut

					if (column == 12) levelData[2][13] = ' ';
					else if (column == 13) levelData[2][12] = ' ';
				}

				canMoveToCell = true;
			}
		}
	}
	if (canMoveToCell)
	{
		// Remove hero symbol from previous position
		levelData[heroRow][heroColumn] = ' ';

		// Set new hero position
		heroRow = row;
		heroColumn = column;

		// Set hero symbol on new position
		levelData[heroRow][heroColumn] = symbolHero;

	}
}

void Update()
{
	int inputChar = _getch();
	//inputChar = tolower(inputChar);

	switch (inputChar)
	{
		// Up
		case 'w':
		{
			MoveHeroTo(heroRow - 1, heroColumn);
			break;
		}
		case 'W':
		{
			MoveHeroTo(heroRow - 1, heroColumn);
			break;
		}
		case 72:
		{
			MoveHeroTo(heroRow - 1, heroColumn);
			break;
		}
		// Down
		case 's':
		{
			MoveHeroTo(heroRow + 1, heroColumn);
			break;
		}
		case 'S':
		{
			MoveHeroTo(heroRow + 1, heroColumn);
			break;
		}
		case 80:
		{
			MoveHeroTo(heroRow + 1, heroColumn);
			break;
		}
		// Left
		case 'a':
		{
			MoveHeroTo(heroRow, heroColumn - 1);
			break;
		}
		case 'A':
		{
			MoveHeroTo(heroRow, heroColumn - 1);
			break;
		}
		case 75:
		{
			MoveHeroTo(heroRow, heroColumn - 1);
			break;
		}
		// Right
		case 'd':
		{
			MoveHeroTo(heroRow, heroColumn + 1);
			break;
		}
		case 'D':
		{
			MoveHeroTo(heroRow, heroColumn + 1);
			break;
		}
		case 77:
		{
			MoveHeroTo(heroRow, heroColumn + 1);
			break;
		}

		// Restart level
		case 114:
		case 82:
		//case 'r':
		//case 'R':
		{
			if (levelSelector == 1)
			{
				Initialise(std::begin(levelData1), std::end(levelData1));
			}
			if (levelSelector == 2)
			{
				LevelClear();
				Initialise(std::begin(levelData2), std::end(levelData2));
			}
			if (levelSelector == 3)
			{
				LevelClear();
				Initialise(std::begin(levelData3), std::end(levelData3));
			}
			if (levelSelector == 4)
			{
				levelSelector = 3;
				LevelClear();
				Initialise(std::begin(levelData3), std::end(levelData3));
			}
			break;
		}


	}
}

void Shutdown()
{
	system("cls");
	switch (Localization)
	{
		case 3:
		{
			setlocale(LC_ALL, "C");
			printf("\n\t Well play. Press any key to exit...");
			break;
		}
		case 2:
		{
			setlocale(LC_ALL, "Russian");
			printf("\n\t Неплохо сыграно. Нажмите любую клавишу для того чтобы выйти...");
			break;
		}
		case 1:
		{
			setlocale(LC_ALL, "Russian");
			printf("\n\t Чудово зiграно, приходьте ще...");
			break;
		}
	}
	
	_getch();

	SetCurrentConsoleFontEx(consoleHandle, TRUE, &defaultFont); // Установить прежний шрифт
}



int main()
{
	SetupSystem();

	// Select Language
	/*do
	{
		RenderLanguage();
		UpdateLanguage();
	} 
	while (isGameActive == true);*/

	// Select Font Size
	/*isGameActive = true;
	do
	{
		RenderFont();
		UpdateFont();
	} while (isGameActive == true);*/
	
	//Level 1
	system("cls");
	isGameActive = true;
	levelSelector = 1;
	Initialise(std::begin(levelData1), std::end(levelData1));
	do
	{
		Render();
		Update();
	} 
	while ( isGameActive );

	// Level 2
	system("cls");
	isGameActive = true;
	levelSelector = 2;
	Initialise(std::begin(levelData2), std::end(levelData2));
	do
	{
		Render();
		Update();
	} while (isGameActive);
	
	// Level 3
	system("cls");
	isGameActive = true;
	LevelClear();
	levelSelector = 3;
	Initialise(std::begin(levelData3), std::end(levelData3));
	do
	{
		Render();
		Update();
	} while (isGameActive);
	

	Shutdown();

	return 0;
}

