//#define _CRT_SECURE_NO_WARNINGS
//#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1

// Include libraries
#include <random>		//std::default_random_engine and std::random_device
#include <algorithm>	// std::remove_if
#include <stdio.h>
#include <stdlib.h>
//#include <ctime>
#include <Windows.h> 
#include <conio.h>
#include <ctype.h>
#include <locale.h>
//#include <assert.h>
#include <strsafe.h>	//StringCchPrintf
#include <iostream>
#include <vector>

#include "Variables.h"
#include "ConsoleColor.h"
#include "Warnings.h"



// Level settings

const unsigned char levelData1[10][columnsCount] =  {
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

const unsigned char levelData2[18][columnsCount] = {
	"###2#########",
	"#cb   # k# p#",
	"2  c#g## X   ",
	"# t #   ## ##",
	"# k   1     2",
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

const unsigned char levelData3[rowsCount3][columnsCount] = {
	"#######2#######",
	"#          XkX#",
	"#           XX#",
	"#             #",
	"#             #",
	"2      1      #",
	"#             #",
	"#             #",
	"#             #",
	"#XX           #",
	"#XcX          #",
	"#######2#######",
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


// Functions

void RandomizeCrystals(int);

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

	SetupFont();
	CenterWindow();
}

//template <size_t N>
void Initialise(const unsigned char(*lvl_begin)[columnsCount], const unsigned char(*lvl_end)[columnsCount])
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
	
	//Initialise
	int currentRow = 0;
	for (const unsigned char(*row)[columnsCount] = lvl_begin; row != lvl_end; ++row)
	{
		for (int c = 0; c < columnsCount; ++c)
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
			// Point
			/*case '.':
			{
				levelData[currentRow][c] = '.';
				break;
			}*/
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
	else if (levelSelector == 3 || levelSelector == 4)
	{
		levelSelector = 3;
		Initialise(std::begin(levelData3), std::end(levelData3));
		RandomizeCrystals(randomCrystals);
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

				break;
			}
			// Point - LightCyan
			case '.':
			{
				printColorText(consoleHandle, '.', LightCyan);
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
			// Other
			default:
				std::cout << symbol;
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

	// Clear getch input stream
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
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

	// Clear getch input stream
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); // STD_OUTPUT_HANDLE is not fit here
}

void SaveFutureFunction()
{
	//levelData[heroRow][heroColumn] = ' ';
	// Save Future array
	for (int r = 0; r < rowsCount3; r++)
		for (int c = 0; c < columnsCount; c++)
		{
			Future[r][c] = levelData[r][c];
		}
}

void LoadFutureFunction()
{
	for (int r = 0; r < rowsCount3; r++)
		for (int c = 0; c < columnsCount; c++)
		{
			levelData[r][c] = Future[r][c];
		}

	levelSelector = 4;
	heroRow = 5;
	heroColumn = 7;
}

void SavePastFunction()
{
	// Save Past array
	for (int r = 0; r < rowsCount3; r++)
		for (int c = 0; c < columnsCount; c++)
		{
			Past[r][c] = levelData[r][c];
		}
}

void LoadPastFunction()
{
	for (int r = 0; r < rowsCount3; r++)
		for (int c = 0; c < columnsCount; c++)
		{
			levelData[r][c] = Past[r][c];
		}

	levelSelector = 3;
	heroRow = 6;
	heroColumn = 7;
}

void MoveHeroTo(int row, int column)
{
	unsigned char destinationCell = levelData[row][column];
	bool canMoveToCell = false;

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
			canMoveToCell = true; // error purpose
			if (levelSelector == 3)
			{
				if (CrystalCount == 1) //5
				{
					levelData[6][5] = symbolPortal;
					levelData[6][9] = symbolPortal;
					//canMoveToCell = true;
				}
				else if (CrystalCount == 2) // 7
				{
					RandomizeCrystals(6);
					//canMoveToCell = true;
				}
				else if (CrystalCount == 13) //13
				{
					canMoveToCell = false;
					levelData[heroRow][heroColumn] = ' ';	// replace hero
					levelData[row][column] = ' ';			// replace crystal
					//levelData[6][5] = '.';				// потом нельзя будет вернуться
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
			// Before each portal
			levelData[heroRow][heroColumn] = ' ';

			// Level 2 portals
			if (levelSelector == 2)
			{
				if (row == 1 && column == 11)
				{
					heroRow = 1;
					heroColumn = 7;
				}
				else if (row == 12 && column == 1)
				{
					heroRow = 15;
					heroColumn = 2;
				}
			}
			// Level 3 portals
			else if (levelSelector == 3)
			{
				if (row == 6 && column == 9) // Key Portal
				{
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
				}
				else if (row == 6 && column == 5) // Left Portal
				{
					// Save Past array
					SavePastFunction();

					if (futureSelector == false)
					{
						levelSelector = 4;
						Initialise(std::begin(levelData4), std::end(levelData4));
						heroRow = 10;
						heroColumn = 6;

						warning = bonusLevelWarning;
						futureSelector = true;
					}
					else LoadFutureFunction(); // Load future array
				}
			}
			// Level 4 portal
			else if (levelSelector == 4 && row == 4 && column == 7) // New Portal
			{
				// Save Future array
				SaveFutureFunction();
				// Load Past array
				LoadPastFunction();
			}
			
			// After each portal
			levelData[heroRow][heroColumn] = symbolHero;

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
						//levelData[5][10] = symbolWall;
						//levelData[4][9] = ' ';
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
						//levelData[5][10] = symbolWall;
						//levelData[4][9] = ' ';
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
	case 'W':
	case 150:	//ц
	case 230:	//Ц
	case 72:
	{
		MoveHeroTo(heroRow - 1, heroColumn);
		break;
	}
	// Down
	case 's':
	case 'S':
	case 155:	//ы
	case 235:	//Ы
	case 63:	//і
	case 80:
	{
		MoveHeroTo(heroRow + 1, heroColumn);
		break;
	}
	// Left
	case 'a':
	case 'A':
	case 148:	//ф
	case 228:	//Ф
	case 75:
	{
		MoveHeroTo(heroRow, heroColumn - 1);
		break;
	}
	// Right
	case 'd':
	case 'D':
	case 130:	//в
	case 162:	//В
	case 77:
	{
		MoveHeroTo(heroRow, heroColumn + 1);
		break;
	}

	// Restart level
	/*case 114:
	case 82:*/
	case 'r':
	case 'R':
	case 170:	//к
	case 138:	//К
	{
		LevelClear();
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

void RandomizeCrystals(int crystalCount)
{
	std::vector<COORD> crystals;
	crystals.reserve((rowsCount3 - 5) * (columnsCount - 5)); // 8 * 11 = 88 - 6 = 82
	// 5 = 2 wall rows + 2 near wall rows + 1 empty row 
	// 5 = 2 wall cols + 2 near wall cols + 1 \0 col

	//Random
	std::mt19937 engine; //minstd_rand, mt19937, mt19937_64, default_random_engine
	std::random_device device;
	//double en = device.entropy();
	//engine.seed(static_cast<unsigned int>(time(0)));
	engine.seed(device());

	auto funcClear = [&crystals](short x, short y)
	{
		//std::vector<COORD>::iterator
		auto result = std::remove_if(crystals.begin(), crystals.end(), [x, y](COORD a)
		{
			return	(a.X >= (x - 1) && a.X <= (x + 1) && a.Y == y) ||
					(a.Y >= (y - 1) && a.Y <= (y + 1) && a.X == x);			// 5
		/*	return	((a.X >= (x - 1)) && (a.X <= (x + 1))) &&
					((a.Y >= (y - 1)) && (a.Y <= (y + 1)));*/				// 3x3
		/*	return
					(a.X == x - 1) && (a.Y == y) ||
					(a.X == x + 1) && (a.Y == y) ||
					(a.Y == y - 1) && (a.X == x) ||
					(a.Y == y + 1) && (a.X == x) ||
					(a.Y == y) && (a.X == x);*/
		});

		crystals.erase(result, crystals.end());
	};

	auto funcCheck = [](short x, short y) -> bool
	{
		return (levelData[x + 1][y] == ' ' && levelData[x - 1][y] == ' ' &&
				levelData[x][y + 1] == ' ' && levelData[x][y - 1] == ' ');
	};

	// initialise empty cells vector
	for (short i = 2; i < rowsCount3 - 3; ++i)
		for (short j = 2; j < columnsCount - 3; ++j)
		{
			if (levelData[i][j] == ' ') // && funcCheck(i, j))
				crystals.push_back(COORD{ i, j });
		}

	// remove some empty cells around invisible portals
	funcClear(6, 5); 
	funcClear(6, 9);
	funcClear(heroRow, heroColumn);

	int index = 0;
	short x = 0; short y = 0;

	while (crystalCount > 0 && crystals.size() != 0)
	{
		index = engine() % crystals.size();
		x = crystals.at(index).X;
		y = crystals.at(index).Y;

		if (funcCheck(x, y))
		{
			levelData[x][y] = symbolCrystal;
			funcClear(x, y);
			--crystalCount;
		}
		else
			crystals.erase(crystals.begin() + index);
	}

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
	//system("cls");
	//isGameActive = true;
	//levelSelector = 1;
	//Initialise(std::begin(levelData1), std::end(levelData1));
	//do
	//{
	//	Render();
	//	Update();
	//} 
	//while ( isGameActive );

	// Level 2
	/*system("cls");
	isGameActive = true;
	levelSelector = 2;
	Initialise(std::begin(levelData2), std::end(levelData2));
	do
	{
		Render();
		Update();
	} while (isGameActive);*/
	
	// Level 3
	system("cls");
	isGameActive = true;
	LevelClear();
	levelSelector = 3;
	Initialise(std::begin(levelData3), std::end(levelData3));
	RandomizeCrystals(randomCrystals);
	do
	{
		Render();
		Update();
	} while (isGameActive);
	

	Shutdown();

	return 0;
}