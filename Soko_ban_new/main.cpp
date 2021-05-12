//#define _CRT_SECURE_NO_WARNINGS
//#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1

// Include libraries
#include <random>		// std::default_random_engine and std::random_device
#include <algorithm>	// std::remove_if
#include <ctime>
#include <Windows.h> 
#include <conio.h>
#include <locale.h>
#include <strsafe.h>	// StringCchPrintf
#include <iostream>
#include <iomanip>		// std::setw and others
#include <vector>
#include <queue>		// #include <deque>

#include "Variables.h"
#include "ConsoleColor.h"
#include "Achievements.h"
#include "Warnings.h"
#include "Level_3.h"
#include "Save.h"
#include "MultiStr.h"
#include "MainMenu.h"




// Functions

void LevelClear();

void NextLevel(int);

void SetupSystem()
{
	time(&start_time); // start_time = time(0);

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

	SetupFont();
	CenterWindow();

	setlocale(LC_ALL, "RUS");
}

//template <size_t N>
void Initialise(const unsigned char(*lvl_begin)[columnsCount], 
				const unsigned char(*lvl_end)[columnsCount])
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
		if (levelSelector == 4)
		{
			futureBoxes = markedBoxes;
			futureMines = markedMines;
		}

		markedBoxes = pastBoxes;
		//markedMines = pastMines;	// if you need

		levelSelector = 3;
		futureSelector = false;
		portalWarn = false;
		randomCrystals = 10;	// maybe better add another const variable
		Initialise(std::begin(levelData3), std::end(levelData3));
		RandomizeCrystals(randomCrystals);
	}
}

void NextLevel(int new_level)
{
	system("cls");
	levelSelector = new_level;
	
	if (levelSelector == 3)
	{
		Initialise(std::begin(levelData3sub), std::end(levelData3sub));
		InitVectors();

		markedMines.push_back(COORD{ 7,12 });
		markedMines.push_back(COORD{ 7,13 });
		markedMines.push_back(COORD{ 4,12 });
		markedMines.push_back(COORD{ 4,13 });

		futureBoxes = markedBoxes;
		futureMines = markedMines;

		LevelClear();		// future init here
		InitVectors();

		CheckBox( 1, 13 );
		CheckBox( 10, 1 );
		a_UniBoxMove -= 2;	// non-elegant way to solve it

		pastBoxes = markedBoxes;
	}
	else
	{
		LevelClear();	// Initialise + RandomizeCrystals
		InitVectors();
	}

	if (levelSelector > 4) isGameActive = false;
	//else isGameActive = true;

	if (isGameActive && isGameStart && !isMenuActive) Description();
}

void Render()
{
	short render_x = 2;
	// Move console cursor to 34 column
	SetConsoleCursorPosition(consoleHandle, COORD{ 34, render_x });

	setlocale(LC_ALL, "C");

	for (int r = 0; r < rowsCount; ++r)
	{
		if (levelData[r][0] != '\0')
		{
		// Move console cursor for each line
		SetConsoleCursorPosition(consoleHandle, COORD{ 34, render_x++ });	// postfix
		
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
				if (!EasyMode)
					printColorText(consoleHandle, symbolBomb, Red);
				else
					printColorText(consoleHandle, symbolBomb, Green);
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
	Counters(render_x);

	// Warnings
	/*warning.push((Warning)AllMinesAchieve);
	warning.push((Warning)OnMyWayAchieve);
	warning.push((Warning)lvl3_RestartsAchieve);
	warning.push((Warning)lvl3_CrystalsAchieve);
	warning.push((Warning)AllAchievesAchieve);*/
	Warnings(render_x); //warning reset in the end of Warnings func(not in the MoveHeroTo func)
	
	//SetConsoleTitle
#ifdef _DEBUG
	StringCchPrintf(szbuff, 255, TEXT("Level %d row %d column %d"), levelSelector, heroRow, heroColumn);
#else
	StringCchPrintf(szbuff, 255, TEXT("Level %d"), levelSelector);
#endif
	SetConsoleTitle(szbuff);
}

void BonusWall(int row, int column)
{
	levelData[heroRow][heroColumn] = ' ';
	levelData[row][column] = symbolHero;

	warning.push(bonusWallWarning);
	levelData[14][8] = symbolWall;
	Render();
	Sleep(275);

	warning.push(bonusWallWarning);
	levelData[15][8] = symbolWall;
	Render();
	Sleep(275);

	warning.push(bonusWallWarning);
	levelData[16][8] = symbolWall;
	Render();
	Sleep(275);

	warning.push(bonusWallWarning);
	levelData[16][6] = symbolKey;

	// Clear getch input stream
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}

void DieAnimation(int row, int column) 
{
	//warning.push(bombWarning);
	levelData[heroRow][heroColumn] = ' ';
	for (int i = 0; i < 3; ++i)
	{
		warning.push(bombWarning);
		levelData[row][column] = 'd';
		Render();
		Sleep(225);

		warning.push(bombWarning);
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
#ifdef _DEBUG
			if ((levelSelector == 2) && (CrystalCount < 1)) //13
#else
			if ((levelSelector == 2) && (CrystalCount < 13))
#endif
			{
				warning.push(crystalWarning);
				CrystalMaxCount = 1;
			}
			else if (levelSelector == 3)
			{
				levelData[row][column] = symbolWall;
			}
			else if ((levelSelector == 4) && (CrystalCount < 14))
			{
				warning.push(crystalWarning);
				CrystalMaxCount = 14;
				levelData[4][7] = symbolPortal;	// New portal
				levelData[4][9] = ' ';			// shortcut
			}
			else NextLevel(levelSelector + 1);	// no modify value
			//isGameActive = false;
		    
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
					randomCrystals += 10;

				ClearCrystals();
				if (randomCrystals > 0)
					RandomizeCrystals(--randomCrystals, row, column);

				if (!lvl3_CrystalsAchieve_)
					if (CrystalCount >= 20)
						lvl3_CrystalsAchieve_ = true;

				if (!lvl3_RestartsAchieve_)
					a_lvl3_Restarts = 0;

#ifdef _DEBUG
				if (CrystalCount == 1) //5
#else
				if (CrystalCount == 5)
#endif
				{
					levelData[6][5] = symbolPortal;
					levelData[6][9] = symbolPortal;
				}
				else if (CrystalCount == 13 && futureSelector == false) //13
				{
					canMoveToCell = false;
					levelData[heroRow][heroColumn] = ' ';	// replace hero
					levelData[row][column] = ' ';			// replace crystal
					// Save Past array
					SavePastFunction();
					// Load Future array
					LoadFutureFunction();

					//levelData[heroRow][heroColumn] = symbolHero;
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
					if (!portalWarn && KeyCount == 0)
					{
						warning.push(portalWarning);
						portalWarn = true;
					}
					else
					{
						// Save Past array
						SavePastFunction();
						// Load Future array
						LoadFutureFunction();
					}
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
				{ 
					levelData[8][6] = symbolDoorG;
					if ((levelData[7][13] == ' ' &&  levelData[4][12] == ' ') ||
						(levelData[7][12] == ' ' &&  levelData[4][13] == ' '))
					{
						OnMyWayAchieve_ = true;
						//warning = (Warning)OnMyWayAchieve;
					}
				}
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
			else warning.push(keyWarning);
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
			else warning.push(keyWarning);
			break;
		}
		// Bomb
		case symbolBomb:
		{
			if (!EasyMode)
			{
				++global_Bombs;
				++global_Restarts;

				DieAnimation(row, column);
				CheckBomb(row, column);

				LevelClear();
			}
			
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

				BonusWall(row, column);
			}
			else if (levelSelector == 4)
			{
				// Secret door
				if (row == 10 && column == 7)
				{
					//warning = secretDoorWarning;
					warning.push(secretDoorWarning);

					levelData[11][7] = ' ';
					levelData[11][12] = 't';
					levelData[11][13] = 't';
				}
				// Secret bombs warning
				else if ((row == 11 && column == 12))
				{
					//warning = secretBombsWarning;
					warning.push(secretBombsWarning);
					levelData[11][13] = ' ';
				}
				else if ((row == 11 && column == 13))
				{
					warning.push(secretBombsWarning);
					levelData[11][12] = ' ';
				}
				// Secret bombs
				else if (row == 9 && column == 12)
				{
					levelData[7][12] = symbolBomb;
					if (levelData[7][13] != symbolBomb) warning.push(secretBombRight);
					else 
					{
						warning.push(secretBombDamn);
						levelData[6][11] = ' ';
					}
				}
				else if (row == 9 && column == 13)
				{
					levelData[7][13] = symbolBomb;
					if(levelData[7][12] != symbolBomb) warning.push(secretBombLeft);
					else
					{
						warning.push(secretBombDamn);
						levelData[6][11] = ' ';
					}
				}
				else if (row == 6 && column == 12)
				{
					levelData[4][12] = symbolBomb;
					if (levelData[4][13] != symbolBomb) warning.push(secretBombRight);
					else
					{
						warning.push(secretBombDamn);
						levelData[3][11] = ' ';
						//levelData[5][10] = symbolWall;
						//levelData[4][9] = ' ';
					}
				}
				else if (row == 6 && column == 13)
				{
					levelData[4][13] = symbolBomb;
					if (levelData[4][12] != symbolBomb) warning.push(secretBombLeft);
					else 
					{
						warning.push(secretBombDamn);
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

bool KeyValidation(int key)
{
	return	(key >= 65 && key <= 90) &&
		(key != 'W' && key != 'S' && key != 'A' && key != 'D' && key != 27);
}

int ReadKey()
{
	int inputChar = _getch();

	if (inputChar == 224)
	{
		inputChar = _getch();
		switch (inputChar)
		{
		case 80:
			inputChar = 'S';
			break;
		case 77:
			inputChar = 'D';
			break;
		case 75:
			inputChar = 'A';
			break;
		case 72:
			inputChar = 'W';
			break;
		default:
			inputChar = 224;
			break;
		}
	}
	else if (inputChar == 0) _getch();

	inputChar = toupper(inputChar);

	return inputChar;
}

void Update()
{
	int inputChar = ReadKey();

	if (inputChar == RestartKey)	// Restart
	{
		++global_Restarts;
		NullRestartsAchieve_ = false;
		if (!lvl3_RestartsAchieve_)
		{
			++a_lvl3_Restarts;
			if (a_lvl3_Restarts == 10)
				lvl3_RestartsAchieve_ = true;
		}
		LevelClear();
	}
	else
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
	case 63:	//і, І
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
	//case 114:
	//case 82:
	//case 170:	//к
	//case 138:	//К
	//{
	//	++global_Restarts;
	//	NullRestartsAchieve_ = false;
	//	if (!lvl3_RestartsAchieve_)
	//	{
	//		++a_lvl3_Restarts;
	//		if (a_lvl3_Restarts == 10)
	//			lvl3_RestartsAchieve_ = true;
	//	}
	//	LevelClear();
	//	break;
	//}
	// Main menu
	case 27:	// Esc
		MainMenu();
		break;

	}
}

void Shutdown()
{
	//Statistic();

	SetCurrentConsoleFontEx(consoleHandle, TRUE, &defaultFont); // Установить прежний шрифт
}


int main()
{
	SetupSystem();

	MainMenu();

	// Main cycle
	//NextLevel(levelSelector);
	if (isGameStart)
	do
	{
		Render();
		Update();
	} 
	while ( isGameActive );

	//if (isGameStart) Statistic();
	Shutdown();
	
	return 0;
}