//#define _CRT_SECURE_NO_WARNINGS
//#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1

// Include libraries
#include <random>		//std::default_random_engine and std::random_device
#include <algorithm>	// std::remove_if
//#include <stdio.h>
//#include <stdlib.h>
#include <ctime>
#include <Windows.h> 
#include <conio.h>
//#include <ctype.h>
#include <locale.h>
//#include <assert.h>
#include <strsafe.h>	//StringCchPrintf
#include <iostream>
#include <iomanip>		//std::setw and others
#include <vector>

#include "Variables.h"
#include "ConsoleColor.h"
#include "Achievements.h"
#include "Warnings.h"
#include "Level_3.h"





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
	"2      1      2",
	"#             #",
	"#             #",
	"#             #",
	"#XX           #",
	"#XcX          #",
	"#######2#######",
	"               "
};



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

	GetCurrentConsoleFontEx(consoleHandle, TRUE, &fontInfo); // �������� ������� �����

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

	SetCurrentConsoleFontEx(consoleHandle, TRUE, &fontInfo); // ���������� ���������� �����

	CenterWindow();
}

void SetupSystem()
{
	//consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	time(&start_time); // start_time = time(0);

	CONSOLE_SCREEN_BUFFER_INFOEX scrBuffer;
	scrBuffer.cbSize = sizeof(scrBuffer);

	_CONSOLE_CURSOR_INFO cursorInfo;

	GetCurrentConsoleFontEx(consoleHandle, TRUE, &defaultFont); // ��������� ������� �����
	GetConsoleScreenBufferInfoEx(consoleHandle, &scrBuffer);
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);

	//������ ������ �������
	scrBuffer.dwSize = COORD{ 80,26 };
	//������ ���� �������
	scrBuffer.srWindow = SMALL_RECT{ 0,0,80,26 };
	//������������(�������������) ������ ���� �������
	scrBuffer.dwMaximumWindowSize = COORD{ 80,26 };
	//������������� �����
	scrBuffer.bFullscreenSupported = false;
	//������ ������ ���������
	cursorInfo.bVisible = false;

	SetConsoleScreenBufferInfoEx(consoleHandle, &scrBuffer);
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
	//SetCurrentConsoleFontEx(consoleHandle, TRUE, &fontInfo); // ���������� ���������� �����

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
			std::wcout << L"\n\t\t\t ���� �����, ����i�� ���� ����"; //54
			break;
		}
		case 2:
		{
			std::wcout << L"\n\t\t\t\t �������� ����\t\t\t"; //46
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
		printColorText(consoleHandle, " ���������\n", Yellow);
	}
	else
	{
		std::cout << "\n\t\t\t\t   ���������\n";
	}

	if (Localization == 2)
	{
		std::cout << "\n\t\t\t\t ";
		printColorText(consoleHandle, symbolHero, LightGreen);
		printColorText(consoleHandle, "  �������\n", Yellow);
	}
	else
	{
		std::cout << "\n\t\t\t\t    �������\n";
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
		std::cout << "\n\t\t\t\t������i�� Enter"; //32+15
		break;
	}
	case 2:
	{
		std::cout << "\n\t\t\t\t ������� Enter\t"; //33+13
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
		std::cout << "\t\t\t\t ����i� ������";
		break;
	}
	case 2:
	{
		std::cout << "\t\t\t\t �������� �����\t\t\t";
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
	CrystalMaxCount = 0;
	KeyCount = 0;

	if (levelSelector == 1)
		Initialise(std::begin(levelData1), std::end(levelData1));
	else if (levelSelector == 2)
		Initialise(std::begin(levelData2), std::end(levelData2));
	else if (levelSelector == 3 || levelSelector == 4)
	{
		levelSelector = 3;
		futureSelector = false;
		randomCrystals = 10;
		Initialise(std::begin(levelData3), std::end(levelData3));
		RandomizeCrystals(randomCrystals);

		if (!lvl3_RestartsAchieve_)
		{
			++a_lvl3Restarts;
			if (a_lvl3Restarts == 10)
			{
				lvl3_RestartsAchieve_ = true;
				warning = a_RestartsWarning;
				//AchievesComplete.push_back(&lvl3_RestartsAchieve_);
			}
		}
	}

}

void Render()
{
	short x = 2;
	// Move console cursor to 34 column
	SetConsoleCursorPosition(consoleHandle, COORD{ 34, x });

	setlocale(LC_ALL, "C");

	for (int r = 0; r < rowsCount; ++r)
	{
		if (levelData[r][0] != '\0')
		{
		// Move console cursor for each line
		SetConsoleCursorPosition(consoleHandle, COORD{ 34, x++ });
		
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
			case '\0': // ������� ������
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
	StringCchPrintf(szbuff, 255, TEXT("Level %d row %d column %d"), levelSelector, heroRow, heroColumn);
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
			canMoveToCell = false;
			if ((levelSelector == 2) && (CrystalCount < 1)) //13
			{
				warning = crystalWarning;
				CrystalMaxCount = 1;
				//canMoveToCell = false;
			}
			else if (levelSelector == 3)
			{
				levelData[row][column] = symbolWall;
				//canMoveToCell = false;
			}
			else if ((levelSelector == 4) && (CrystalCount < 14)) //13
			{
				warning = crystalWarning;
				CrystalMaxCount = 14;
				//canMoveToCell = false;
				levelData[4][7] = symbolPortal;	// New portal
				levelData[4][9] = ' ';			// shortcut
			}
			else
			isGameActive = false;
		    
			break;
		}
		// Crystal
		case symbolCrystal:
		{
			++CrystalCount;
			++global_Crystals;
			canMoveToCell = true; // error purpose

			if (levelSelector == 3)
			{
				if (row == 10 && column == 2)
					randomCrystals += 6;

				ClearCrystals();
				if (randomCrystals > 0)
					RandomizeCrystals(--randomCrystals, row, column);

				if (!lvl3_CrystalsAchieve_)
					if (CrystalCount >= 16)
					{
						lvl3_CrystalsAchieve_ = true;
						warning = a_CrystalsWarning;
					}

				if (!lvl3_RestartsAchieve_)
					a_lvl3Restarts = 0;

				if (CrystalCount == 1) //5
				{
					levelData[6][5] = symbolPortal;
					levelData[6][9] = symbolPortal;
				}
				//else if (CrystalCount == 2) // 7
				//{
				//	randomCrystals += 6;
				//}
				else if (CrystalCount == 13 && futureSelector == false) //13
				{
					canMoveToCell = false;
					levelData[heroRow][heroColumn] = ' ';	// replace hero
					levelData[row][column] = ' ';			// replace crystal
					// Save Past array
					SavePastFunction();
					// Load Future array
					LoadFutureFunction();

					levelData[heroRow][heroColumn] = symbolHero;
				}
				else canMoveToCell = true;
			}
			else canMoveToCell = true;

			break;
		}
		// Portal
		case symbolPortal:
		{
			++global_Portals;
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
					else if (levelData[10][2] == symbolCrystal)
					{
						heroRow = 10;
						heroColumn = 1;
					}
					else levelData[6][9] = ' '; // Portal disapear
						
				}
				else if (row == 6 && column == 5) // Left Portal
				{
					// Save Past array
					SavePastFunction();
					// Load Future array
					LoadFutureFunction(); 
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
			++global_Keys;
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
			++global_Bombs;
			++global_Restarts;
			CheckBomb(row, column);
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
				++global_Boxes;
				CheckBox(row, column);
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
				canMoveToCell = true;
				/*levelData[heroRow][heroColumn] = ' ';
				heroRow = row;
				heroColumn = column;
				levelData[heroRow][heroColumn] = symbolHero;*/

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
					//levelData[4][9] = ' '; // shortcut

					// Reset the same trap near
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
	//inputChar = tolower(inputChar); // work only with english symbols

	// miss first char arrows and Num codes
	if (inputChar == 0 || inputChar == 224)
		inputChar = _getch();
	
	switch (inputChar)
	{
	// Up
	case 'w':
	case 'W':
	case 150:	//�
	case 230:	//�
	case 72:
	{
		MoveHeroTo(heroRow - 1, heroColumn);
		break;
	}
	// Down
	case 's':
	case 'S':
	case 155:	//�
	case 235:	//�
	case 63:	//�, �
	case 80:
	{
		MoveHeroTo(heroRow + 1, heroColumn);
		break;
	}
	// Left
	case 'a':
	case 'A':
	case 148:	//�
	case 228:	//�
	case 75:
	{
		MoveHeroTo(heroRow, heroColumn - 1);
		break;
	}
	// Right
	case 'd':
	case 'D':
	case 130:	//�
	case 162:	//�
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
	case 170:	//�
	case 138:	//�
	{
		++global_Restarts;
		LevelClear();
		break;
	}


	}
}

void Shutdown()
{
	Statistic();
	
	_getch();

	SetCurrentConsoleFontEx(consoleHandle, TRUE, &defaultFont); // ���������� ������� �����
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
	system("cls");
	isGameActive = true;
	levelSelector = 2;
	Initialise(std::begin(levelData2), std::end(levelData2));
	InitVectors(); // Bombs and Boxes vectors
	do
	{
		Render();
		Update();
	} while (isGameActive);
	
	// Level 3
	system("cls");
	isGameActive = true;
	levelSelector = 3;
	//Initialise(std::begin(levelData3), std::end(levelData3));
	LevelClear();	// Initialise + RandomizeCrystals
	InitVectors();
	//RandomizeCrystals(randomCrystals);
	do
	{
		Render();
		Update();
	} while (isGameActive);
	

	Shutdown();

	return 0;
}