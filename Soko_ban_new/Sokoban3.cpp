
// Include libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h> 
#include <conio.h>
#include <ctype.h>
#include <locale.h>
#include <iostream>

#include "ConsoleColor.h"




// Game settings
const int rowsCount = 10;
const int columnsCount = 15;

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


const unsigned char levelData0[rowsCount][columnsCount + 1] =  {
	"#####2#########",
	"#  X   #   X ##",
	"# X ### X  #  #",
	"#X X  X  ## X #",
	"# X    ##  #  #",
	"#######    # X#",
	"#   X   XX #X #",
	"#XXX # # X   ##",
	"#1 X #   X X  #",
	"###############",
                                                                };

const int rowsCount2 = 18;
const int columnsCount2 = 15;

const unsigned char levelData2[rowsCount2][columnsCount2 + 1] = {
	"#############",
	"#cb   # k# p#",
	"#  c#g## X  #",
	"# ###   ## ##",
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
	"#c   c c c  #",
	"##2##########",

                                                                  };

const int rowsCount3 = 13;
const int columnsCount3 = 15;

const unsigned char levelData3[rowsCount3][columnsCount3 + 1] = {
	"#######2#######",
	"#          XkX#",
	"#       c   XX#",
	"#     c       #",
	"#         c   #",
	"2  c   1      2",
	"#          c  #",
	"#      c      #",
	"#        c    #",
	"#XX           #",
	"#XcX          #",
	"#######2#######",
	"               "
                                                               };

const unsigned char levelData4[rowsCount3][columnsCount3 + 1] = {
	"############22#",
	"#   X   X  #  #",
	"#X  X  X XX   #",
	"#  #######    #",
	"#  # v        #",
	"#XX# #   # #  #",
	"#  # ##### #  #",
	"#  #       #  #",
	"#XX### #####  #",
	"#  b   bXXXX  #",
	"#    b  XXXX  #",
	"###############",
	"               ",
																};



// Logic variables
HANDLE consoleHandle = 0;
bool isGameActive = true;
unsigned char levelData[rowsCount+10][columnsCount]; // Change for need
unsigned char Past[rowsCount3][columnsCount3];
unsigned char Future[rowsCount3][columnsCount3];
int heroRow = 0;
int heroColumn = 0;
int levelSelector = 1;
int CrystalCount = 0;
int KeyCount = 0;
int Localization = 1;

#include "Warnings.h"

//bool warning1 = false;
//bool warning2 = false;
//bool bombSelector = false;
bool bonusWallSelector = false;
//bool bonusWallWarning = false;
bool secretDoorSelector = false;
//bool secretDoorWarning = false;
//bool secretBombsWarning = false;
//bool bonusLevelWarning = false;

bool futureSelector = false;



// Functions
void SetupSystem()
{
	//srand(time(0));

	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

void RenderLanguage()
{
	//system("cls");
	SetConsoleCursorPosition(consoleHandle, COORD{ 0,0 });
	//setlocale(LC_ALL, "Russian");
	setlocale(0, "");
	std::cout << std::endl;

	switch (Localization)
	{
		case 1:
		{
			std::cout << "\n\t\t\t Будь ласка, оберiть вашу мову"; //54
			break;
		}
		case 2:
		{
			std::cout << "\n\t\t\t\t Выберите язык\t\t\t"; //46
			break;
		}
		case 3:
		{
			std::cout << "\n\t\t\t      Select your language"; //50
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
	//std::cout << std::endl;
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

void Initialise(int rows, int columns)
{
	// Load level
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < columns; c++)
		{
			
			unsigned char symbol = levelData0[r][c];

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

void Initialise2(int rows, int columns)
{
	//system("cls");
	// Load level

	//auto * symbol = levelData0;
	const unsigned char(*symbol)[16] = nullptr;
	// Select level
	if (levelSelector == 1)
	{
		symbol = levelData0;
	}
	else if (levelSelector == 2)
	{
		symbol = levelData2;
	}
	else if (levelSelector == 3)
	{
		symbol = levelData3;
	}
	else if (levelSelector == 4)
	{
		symbol = levelData4;
	}

	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < columns; c++)
		{
			switch (symbol[r][c])
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
			// Crystal
			case 'c':
			{
				levelData[r][c] = symbolCrystal;
				break;
			}
			// Vertical door
			case 'v':
			{
				levelData[r][c] = symbolDoorV;
				break;
			}
			// Gorisontal door
			case 'g':
			{
				levelData[r][c] = symbolDoorG;
				break;
			}
			// Portal
			case 'p':
			{
				levelData[r][c] = symbolPortal;
				break;
			}
			// Point
			case '.':
			{
				levelData[r][c] = symbolPoint;
				break;
			}
			// Key
			case 'k':
			{
				levelData[r][c] = symbolKey;
				break;
			}
			// Bomb
			case 'b':
			{
				levelData[r][c] = symbolBomb;
				break;
			}
			// Other symbols (like spaces)
			default:
			{
				levelData[r][c] = symbol[r][c];
				break;
			}
			}
		}
	}
}

void LevelClear()
{
	CrystalCount = 0;
	KeyCount = 0;
	bonusWallSelector = false;
	secretDoorSelector = false;
	futureSelector = false;

	if (levelSelector == 1)
		Initialise2(rowsCount, columnsCount);
	else if (levelSelector == 2)
		Initialise2(rowsCount2, columnsCount2);
	else if (levelSelector == 3)
		Initialise2(rowsCount3, columnsCount3);
	else if (levelSelector == 4)
	{
		levelSelector = 3;
		Initialise2(rowsCount3, columnsCount3);
	}
}

void Render()
{
	// Move console cursor to (0,0)
	SetConsoleCursorPosition(consoleHandle, COORD{ 0,0 });

	setlocale(LC_ALL, "C");

	printf("\n\n\t");
	for (int r = 0; r < rowsCount; r++)
	{
		for (int c = 0; c < columnsCount; c++)
		{
			unsigned char symbol = levelData[r][c];

			switch (symbol)
			{
				// Walls - grey
				case symbolWall:
				{
					SetConsoleTextAttribute(consoleHandle, 7);
					break;
				}
				// Hero - green
				case symbolHero:
				{
					SetConsoleTextAttribute(consoleHandle, 10);
					break;
				}
				// Boxes - yellow
				case symbolBox:
				{
					SetConsoleTextAttribute(consoleHandle, 14);
					break;
				}
				// Exit - red
				case symbolExit:
				{
					SetConsoleTextAttribute(consoleHandle, 12);
					break;
				}
			}

			printf("%c", symbol);
		}
		printf("\n\t");
	}

	switch (Localization)
	{
		case 3:
		{
			setlocale(LC_ALL, "C");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("\n\n\tUse AWSD to move your ");
			SetConsoleTextAttribute(consoleHandle, 10);
			printf("Hero");
			SetConsoleTextAttribute(consoleHandle, 7);
			
			printf(". Move ");
			SetConsoleTextAttribute(consoleHandle, 14);
			printf("Boxes");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("(");
			SetConsoleTextAttribute(consoleHandle, 14);
			printf("%c", symbolBox);
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(") to get to the Exit(");
			SetConsoleTextAttribute(consoleHandle, 12);
			printf("%c", symbolExit);
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(").");
			printf("\n\tR - Restart level.");
			break;
		}
		case 2:
		{
			setlocale(LC_ALL, "Russian");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("\n\n\tИспользуйте клавиши AWSD чтобы управлять ");
			SetConsoleTextAttribute(consoleHandle, 10);
			printf("Героем");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(".\n\tДвигайте ");
			SetConsoleTextAttribute(consoleHandle, 14);
			printf("Ящики");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("(");
			setlocale(LC_ALL, "C");
			SetConsoleTextAttribute(consoleHandle, 14);
			printf("%c", symbolBox);
			setlocale(LC_ALL, "Russian");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(") чтобы добраться до Выхода(");
			setlocale(LC_ALL, "C");
			SetConsoleTextAttribute(consoleHandle, 12);
			printf("%c", symbolExit);
			setlocale(LC_ALL, "Russian");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(").");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("\n\tR - перезапустить уровень.");
			break;
		}
		case 1:
		{
			setlocale(LC_ALL, "Russian");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("\n\n\tКористуйся AWSD щоб керувати ");
			SetConsoleTextAttribute(consoleHandle, 10);
			printf("Козаком");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(". R - розпочати спочатку.");
			printf("\n\tРухай ");
			SetConsoleTextAttribute(consoleHandle, 14);
			printf("Снопи");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("(");
			setlocale(LC_ALL, "C");
			SetConsoleTextAttribute(consoleHandle, 14);
			printf("%c", symbolBox);
			setlocale(LC_ALL, "Russian");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(") щоб дiстатись Виходу(");
			setlocale(LC_ALL, "C");
			SetConsoleTextAttribute(consoleHandle, 12);
			printf("%c", symbolExit);
			setlocale(LC_ALL, "Russian");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(").");
			break;
		}
	}
}

void Render2(int rows, int columns)
{
	// Move console cursor to (0,0)
	
	/*COORD cursorCoord;
	cursorCoord.X = 0;
	cursorCoord.Y = 0;*/
	SetConsoleCursorPosition(consoleHandle, COORD{ 0,0 });

	setlocale(LC_ALL, "C");

	std::cout<<'\n';
	for (int r = 0; r < rows; r++)
	{
		std::cout<< "\n\t\t\t\t  ";
		for (int c = 0; c < columns; c++)
		{
			unsigned char symbol = levelData[r][c];

			switch (symbol)
			{
				// Walls - grey
			case symbolWall:
			{
				SetConsoleTextAttribute(consoleHandle, 7);
				break;
			}
			// Hero - green
			case symbolHero:
			{
				/*if (bombSelector)
				{
					SetConsoleTextAttribute(consoleHandle, Red);
				}
				else */
				SetConsoleTextAttribute(consoleHandle, LightGreen);
				
				break;
			}
			// Boxes - yellow
			case symbolBox:
			{
				SetConsoleTextAttribute(consoleHandle, 14);
				break;
			}
			// Exit - red
			case symbolExit:
			{
				SetConsoleTextAttribute(consoleHandle, Red);
				break;
			}
			// Crystal - fioletovi
			case symbolCrystal:
			{
				SetConsoleTextAttribute(consoleHandle, 5);
				break;
			}
			// Portal - biruza
			case symbolPortal:
			{
				if ((levelSelector == 3) && (r == 6) && (c == 5))
				{
					SetConsoleTextAttribute(consoleHandle, 5);
				}
				else
					if ((levelSelector == 3) && (r == 6) && (c == 9))
					{
						SetConsoleTextAttribute(consoleHandle, 13);
					}
					else
				SetConsoleTextAttribute(consoleHandle, 11);
				break;
			}
			// Point - biruza
			case symbolPoint:
			{
				SetConsoleTextAttribute(consoleHandle, 11);
				break;
			}
			// Gorisontal door - grey
			case symbolDoorG:
			{
				SetConsoleTextAttribute(consoleHandle, 7);
				break;
			}
			case symbolDoorV:
			{
				SetConsoleTextAttribute(consoleHandle, 7);
				break;
			}
			// Key - pink
			case symbolKey:
			{
				SetConsoleTextAttribute(consoleHandle, 13);
				break;
			}
			// Bomb - red
			case symbolBomb:
			{
				SetConsoleTextAttribute(consoleHandle, Red);
				break;
			}
	 		}
    	
			//printf("%c", symbol);
			std::cout << symbol;
		}
		//printf("\n\t\t\t\t  ");
	}

	// Crystal/Key counters
	std::cout<< "\n\t\t\t\t      "; // 34 to level render +4 = 38 spases
	if (CrystalCount != 0)
	{
		printColorText(consoleHandle, symbolCrystal, Magenta);
		std::cout << CrystalCount << ' ';
	}
	if (KeyCount != 0)
	{
		printColorText(consoleHandle, symbolKey, LightMagenta);
		std::cout << KeyCount;
	}
	else
	{
		std::cout << "  ";
	}

	// Warnings
	//Warnings();
	Warnings(warning); //warning reset in the end of Warnings func(not in the MoveHeroTo func)
	Description();
}

//void Warnings() {
//	if (warning1 == true)
//	{
//		switch (Localization)
//		{
//		case 1:
//		{
//			setlocale(LC_ALL, "Russian");
//			SetConsoleTextAttribute(consoleHandle, 14);
//			printf("\n\t\t\t    I куди ти без ");
//			SetConsoleTextAttribute(consoleHandle, 13);
//			printf("Ключа");
//			SetConsoleTextAttribute(consoleHandle, 14);
//			printf(" лiзеш?     ");
//			warning1 = false;
//			break;
//		}
//		case 2:
//		{
//			setlocale(LC_ALL, "Russian");
//			SetConsoleTextAttribute(consoleHandle, 14);
//			printf("\n\t\t\t\t    ");
//			if (levelSelector == 3 || levelSelector == 4)
//				printf(" ");
//			printf("Нужен ");
//			SetConsoleTextAttribute(consoleHandle, 13);
//			printf("Ключ     ");
//			warning1 = false;
//			break;
//		}
//		case 3:
//		{
//			setlocale(LC_ALL, "C");
//			SetConsoleTextAttribute(consoleHandle, 14);
//			printf("\n\t\t\t\t  Need some ");
//			SetConsoleTextAttribute(consoleHandle, 13);
//			printf("Key     ");
//			warning1 = false;
//			break;
//		}
//		}
//	}
//	else
//	{
//		if (warning2 == true)
//		{
//			switch (Localization)
//			{
//			case 1:
//			{
//				setlocale(LC_ALL, "Russian");
//				SetConsoleTextAttribute(consoleHandle, 14);
//				printf("\n\t\t\t   Куди зiбрався? А ну ");
//				SetConsoleTextAttribute(consoleHandle, 5);
//				printf("%c", symbolCrystal);
//				SetConsoleTextAttribute(consoleHandle, 14);
//				printf(" збирай!");
//				warning2 = false;
//				break;
//			}
//			case 2:
//			{
//				setlocale(LC_ALL, "Russian");
//				SetConsoleTextAttribute(consoleHandle, 14);
//				printf("\n\t\t\t\t  Нужно больше ");
//				SetConsoleTextAttribute(consoleHandle, 5);
//				printf("%c", symbolCrystal);
//				warning2 = false;
//				break;
//			}
//			case 3:
//			{
//				setlocale(LC_ALL, "C");
//				SetConsoleTextAttribute(consoleHandle, 14);
//				printf("\n\t\t\t\t  Collect more ");
//				SetConsoleTextAttribute(consoleHandle, 5);
//				printf("%c", symbolCrystal);
//				warning2 = false;
//				break;
//			}
//			}
//		}
//		else
//		{
//			if (bombSelector == true)
//			{
//				switch (Localization)
//				{
//				case 1:
//				{
//					setlocale(LC_ALL, "Russian");
//					SetConsoleTextAttribute(consoleHandle, 14);
//					printf("\n\t\t\t     Я ж казав не лiзти в ");
//					SetConsoleTextAttribute(consoleHandle, 12);
//					printf("Яму");
//					SetConsoleTextAttribute(consoleHandle, 14);
//					printf("!");
//					break;
//				}
//				case 2:
//				{
//					setlocale(LC_ALL, "Russian");
//					SetConsoleTextAttribute(consoleHandle, 14);
//					printf("\n\t\t\t\t");
//					if (levelSelector == 4)
//						printf(" ");
//					printf("    ПОТРАЧЕНО");
//					break;
//				}
//				case 3:
//				{
//					setlocale(LC_ALL, "C");
//					SetConsoleTextAttribute(consoleHandle, 14);
//					printf("\n\t\t\t       Oops! You just died");
//					break;
//				}
//				}
//
//				_getch();
//				LevelClear();
//				if (levelSelector == 2)
//					Initialise2(rowsCount2, columnsCount2);
//				if (levelSelector == 3)
//					Initialise2(rowsCount3, columnsCount3);
//				if (levelSelector == 4)
//				{
//					levelSelector = 3;
//					Initialise2(rowsCount3, columnsCount3);
//				}
//			}
//			else
//				if (bonusWallWarning == true)
//				{
//					switch (Localization)
//					{
//					case 1:
//					{
//						setlocale(LC_ALL, "Russian");
//						SetConsoleTextAttribute(consoleHandle, 14);
//						printf("\n\t\t\t\tСтiна в подарунок");
//						break;
//					}
//					case 2:
//					{
//						setlocale(LC_ALL, "Russian");
//						SetConsoleTextAttribute(consoleHandle, 14);
//						printf("\n\t\t\t\t     Сюрприз");
//						break;
//					}
//					case 3:
//					{
//						setlocale(LC_ALL, "C");
//						SetConsoleTextAttribute(consoleHandle, 14);
//						printf("\n\t\t\t\t     Surprise");
//						break;
//					}
//					}
//
//					if (levelData[16][6] == symbolKey)
//					{
//						bonusWallWarning = false;
//					}
//				}
//				else
//					if (bonusLevelWarning == true)
//					{
//						switch (Localization)
//						{
//						case 1:
//						{
//							setlocale(LC_ALL, "Russian");
//							SetConsoleTextAttribute(consoleHandle, 14);
//							printf("\n\t\t\t       Оце так несподiванка!");
//							break;
//						}
//						case 2:
//						{
//							setlocale(LC_ALL, "Russian");
//							SetConsoleTextAttribute(consoleHandle, 14);
//							printf("\n\t\t\t\t  Вот это поворот!");
//							break;
//						}
//						case 3:
//						{
//							setlocale(LC_ALL, "С");
//							SetConsoleTextAttribute(consoleHandle, 14);
//							printf("\n\t\t\t      Surprise, motherfucker!");
//							break;
//						}
//						}
//						bonusLevelWarning = false;
//					}
//					else
//						if (secretDoorWarning == true)
//						{
//							switch (Localization)
//							{
//							case 1:
//							{
//								setlocale(LC_ALL, "Russian");
//								SetConsoleTextAttribute(consoleHandle, 14);
//								printf("\n\t\t     Ти знайшов таємний лаз. Нiчого особливого"); //41+21=62
//								break;
//							}
//							case 2:
//							{
//								setlocale(LC_ALL, "Russian");
//								SetConsoleTextAttribute(consoleHandle, 14);
//								printf("\n\t\t\t  Эй! Кто открыл тайную комнату?!"); //57
//								break;
//							}
//							case 3:
//							{
//								setlocale(LC_ALL, "C");
//								SetConsoleTextAttribute(consoleHandle, 14);
//								printf("\n\t\t\t  Hey! You found the secret door!"); //57
//								break;
//							}
//							}
//
//							secretDoorWarning = false;
//						}
//						else
//							if (secretBombsWarning == true)
//							{
//								switch (Localization)
//								{
//								case 1:
//								{
//									setlocale(LC_ALL, "Russian");
//									SetConsoleTextAttribute(consoleHandle, 14);
//									printf("\n\t\t\t  Обережно! Тут прихованi ");  // 25+33=58
//									SetConsoleTextAttribute(consoleHandle, 12);
//									printf("пастки");
//									SetConsoleTextAttribute(consoleHandle, 14);
//									printf("!");
//									break;
//								}
//								case 2:
//								{
//									setlocale(LC_ALL, "Russian");
//									SetConsoleTextAttribute(consoleHandle, 14);
//									printf("\n\t\t\t Осторожно! Здесь припрятаны ");  // 24+33=57
//									SetConsoleTextAttribute(consoleHandle, 12);
//									printf("мины");
//									SetConsoleTextAttribute(consoleHandle, 14);
//									printf("!");
//									break;
//								}
//								case 3:
//								{
//									setlocale(LC_ALL, "C");
//									SetConsoleTextAttribute(consoleHandle, 14);
//									printf("\n\t\t\t Carreful! There are hidden ");  // 25+33=58
//									SetConsoleTextAttribute(consoleHandle, 12);
//									printf("mines");
//									SetConsoleTextAttribute(consoleHandle, 14);
//									printf("!");
//									break;
//								}
//								}
//
//								secretBombsWarning = false;
//							}
//							else
//								printf("\n\t\t\t\t\t\t\t\t"); // 64
//		}
//	}
//	if (bombSelector == false)
//	{
//		switch (Localization)
//		{
//		case 1:
//		{
//			setlocale(LC_ALL, "Russian");
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf("\n   Керуй ");
//			SetConsoleTextAttribute(consoleHandle, 10);
//			printf("Козаком");
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf(". Збирай ");
//			SetConsoleTextAttribute(consoleHandle, 5);
//			printf("%c", symbolCrystal);
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf(" i ");
//			SetConsoleTextAttribute(consoleHandle, 13);
//			printf("Ключi");
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf("(");
//			SetConsoleTextAttribute(consoleHandle, 13);
//			printf("%c", symbolKey);
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf(") щоб виграти. R - розпочати спочатку.");
//			printf("\n   Використовуй ");
//			SetConsoleTextAttribute(consoleHandle, 11);
//			printf("Таємнi тунелi");
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf("(");
//			SetConsoleTextAttribute(consoleHandle, 11);
//			printf("O");
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf(") i Пункти пропуску (");
//			setlocale(LC_ALL, "C");
//			printf("%c, %c", symbolDoorG, symbolDoorV);
//			setlocale(LC_ALL, "Russian");
//			printf("). Не втрапляй у ");
//			SetConsoleTextAttribute(consoleHandle, 12);
//			printf("Ями");
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf("(");
//			SetConsoleTextAttribute(consoleHandle, 12);
//			printf("%c", symbolBomb);
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf(").");
//			break;
//		}
//		case 2:
//		{
//			setlocale(LC_ALL, "Russian");
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf("\n   Управляйте ");
//			SetConsoleTextAttribute(consoleHandle, 10);
//			printf("Героем");
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf(". Собирайте ");
//			SetConsoleTextAttribute(consoleHandle, 5);
//			printf("%c", symbolCrystal);
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf(" и ");
//			SetConsoleTextAttribute(consoleHandle, 13);
//			printf("Ключи");
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf("(");
//			SetConsoleTextAttribute(consoleHandle, 13);
//			printf("%c", symbolKey);
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf(") чтобы выиграть. R - Перезапуск.");
//			printf("\n   Используйте ");
//			SetConsoleTextAttribute(consoleHandle, 11);
//			printf("Порталы");
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf("(");
//			SetConsoleTextAttribute(consoleHandle, 11);
//			printf("O");
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf(") и Двери (");
//			setlocale(LC_ALL, "C");
//			printf("%c, %c", symbolDoorG, symbolDoorV);
//			setlocale(LC_ALL, "Russian");
//			printf("). Будьте осторожны с ");
//			SetConsoleTextAttribute(consoleHandle, 12);
//			printf("Минами");
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf("(");
//			SetConsoleTextAttribute(consoleHandle, 12);
//			printf("%c", symbolBomb);
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf("). Удачи");
//			break;
//		}
//		case 3:
//		{
//			setlocale(LC_ALL, "C");
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf("\n\tMove your ");
//			SetConsoleTextAttribute(consoleHandle, 10);
//			printf("Hero");
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf(". Collect ");
//			SetConsoleTextAttribute(consoleHandle, 5);
//			printf("%c", symbolCrystal);
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf(" and ");
//			SetConsoleTextAttribute(consoleHandle, 13);
//			printf("Keys");
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf("(");
//			SetConsoleTextAttribute(consoleHandle, 13);
//			printf("%c", symbolKey);
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf(") to win. R - Restart level.");
//			printf("\n\tUse the ");
//			SetConsoleTextAttribute(consoleHandle, 11);
//			printf("Portals");
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf("(");
//			SetConsoleTextAttribute(consoleHandle, 11);
//			printf("O");
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf(") and the Doors (%c, %c). Carreful with ", symbolDoorG, symbolDoorV);
//			SetConsoleTextAttribute(consoleHandle, 12);
//			printf("Mines");
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf("(");
//			SetConsoleTextAttribute(consoleHandle, 12);
//			printf("%c", symbolBomb);
//			SetConsoleTextAttribute(consoleHandle, 7);
//			printf("). Gl hf");
//			break;
//		}
//		}
//
//	}
//	else
//	{
//		bombSelector = false;
//		if (levelSelector == 2)
//			Render2(rowsCount2, columnsCount2);
//		if (levelSelector == 3)
//			Render2(rowsCount3, columnsCount);
//	}
//}

void BonusWall()
{
	warning = bonusWallWarning;
	levelData[14][8] = symbolWall;
	Render2(rowsCount2, columnsCount2);
	Sleep(275);

	warning = bonusWallWarning;
	levelData[15][8] = symbolWall;
	Render2(rowsCount2, columnsCount2);
	Sleep(275);

	warning = bonusWallWarning;
	levelData[16][8] = symbolWall;
	Render2(rowsCount2, columnsCount2);
	Sleep(275);

	warning = bonusWallWarning;
	levelData[16][6] = symbolKey;
	bonusWallSelector = true;
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
			if ((levelSelector == 2) && (CrystalCount < 13))
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
			if ((levelSelector == 4) && (CrystalCount < 13))
			{
				//warning2 = true;
				warning = crystalWarning;
				canMoveToCell = false;
				levelData[4][8] = symbolPortal;
			}
			else
			isGameActive = false;
		    
			break;
		}
		// Crystal
		case symbolCrystal:
		{
			CrystalCount = CrystalCount + 1;
			canMoveToCell = true;
			if ((levelSelector == 3) && (CrystalCount == 5))
			{
				levelData[6][5] = symbolPortal;
				levelData[6][9] = symbolPortal;
			}
			if ((levelSelector == 3) && (CrystalCount == 7))
			{
				levelData[5][6] = symbolCrystal;
				levelData[5][7] = symbolCrystal;
				levelData[5][8] = symbolCrystal;
				levelData[4][6] = symbolCrystal;
				levelData[4][7] = symbolCrystal;
				levelData[4][8] = symbolCrystal;
			}
			if ((levelSelector == 3) && (CrystalCount == 13))
			{
					levelData[heroRow][heroColumn] = ' ';
					levelData[row][column] = ' ';
					// Save Past array
					for (int r = 0; r < rowsCount3; r++)
						for (int c = 0; c < columnsCount3; c++)
						{
							Past[r][c] = levelData[r][c];
						}

					if (futureSelector == false)
					{
						levelSelector = 4;
						Initialise2(rowsCount3, columnsCount3);

						warning = bonusLevelWarning;
						futureSelector = true;
					}
					else
					{
						levelSelector = 4;
						// Load future array
						for (int r = 0; r < rowsCount3; r++)
							for (int c = 0; c < columnsCount3; c++)
							{
								levelData[r][c] = Future[r][c];
							}

						heroRow = 5;
						heroColumn = 7;
						levelData[5][7] = symbolHero;
					}
			}
			break;
		}
		// Portal
		case symbolPortal:
		{
			if ( levelSelector == 2 && row==1 && column==11)
			{
				levelData[heroRow][heroColumn] = ' ';
				heroRow = 1;
				heroColumn = 7;
				levelData[1][7] = symbolHero;
			}
			else
			if (levelSelector == 2 && row == 12 && column == 1)
			{
				levelData[heroRow][heroColumn] = ' ';
				heroRow = 15;
				heroColumn = 2;
				levelData[15][2] = symbolHero;
			}
			else
			if (levelSelector == 3 && row == 6 && column == 9)
			{
				levelData[heroRow][heroColumn] = ' ';
				heroRow = 1;
				heroColumn = 13;
				levelData[1][13] = symbolHero;
			}
			else
			if (levelSelector == 3 && row == 6 && column == 5) // Old Portal
			{
				levelData[heroRow][heroColumn] = ' ';
				// Save Past array
				for (int r = 0; r < rowsCount3; r++)
				for (int c = 0; c < columnsCount3; c++)
				{
					Past[r][c] = levelData[r][c];
				}

				if (futureSelector == false)
				{
					levelSelector = 4;
					Initialise2(rowsCount3, columnsCount3);
					heroRow = 5;
					heroColumn = 7;
					levelData[5][7] = symbolHero;

					warning = bonusLevelWarning;
					futureSelector = true;
				}
				else
				{
					// Load future array
					for (int r = 0; r < rowsCount3; r++)
						for (int c = 0; c < columnsCount3; c++)
						{
							levelData[r][c] = Future[r][c];
						}

					levelSelector = 4;
					heroRow = 5;
					heroColumn = 7;
					levelData[5][7] = symbolHero;
				}
			}
			else
			if (levelSelector == 4 && row == 4 && column == 8) // New Portal
			{
				levelData[heroRow][heroColumn] = ' ';
				// Save Future array
				for (int r = 0; r < rowsCount3; r++)
					for (int c = 0; c < columnsCount3; c++)
					{
						Future[r][c] = levelData[r][c];
					}
				// Load Past array
				for (int r = 0; r < rowsCount3; r++)
					for (int c = 0; c < columnsCount3; c++)
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
			KeyCount++;
			canMoveToCell = true;
			break;
		}
		// Gorisontal door
		case symbolDoorG:
		{
			if ( KeyCount > 0 )
			{
			KeyCount = KeyCount - 1;
			canMoveToCell = true;

			if (row == 1 && column == 12)
				levelData[1][13] = ' ';
			if (row == 1 && column == 13)
				levelData[1][12] = ' ';
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
				KeyCount = KeyCount - 1;
				canMoveToCell = true;
			}
			else
			{
				//warning1 = true;
				warning = keyWarning;
			}
			break;
		}
		// Bomb
		case symbolBomb:
		{
			//levelData[heroRow][heroColumn] = ' ';
			//Set hero symbol on new position
			//levelData[row][column] = symbolHero;
			canMoveToCell = true;
			warning = bombWarning;
			//bombSelector = true;
			//_getch();
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
		// Bonus wall
		if ((heroRow == 15) && (heroColumn == 11) && (levelSelector == 2) && (bonusWallSelector == false))
		{
			BonusWall();
		}
		// Secret door
		if (levelSelector == 4 && (heroRow == 10 && heroColumn == 7) )
		{
			if (levelData[11][7] != ' ')
			warning = secretDoorWarning;

			levelData[11][7] = ' ';
			levelData[11][12] = ' ';
			levelData[11][13] = ' ';
		}
		// Secret bombs
		if (levelSelector == 4 && ((heroRow == 10 && heroColumn == 12) || (heroRow == 10 && heroColumn == 13)) && ((levelData[7][12] != symbolBomb) && (levelData[7][13] != symbolBomb)) )
			warning = secretBombsWarning;
		if (levelSelector == 4 && (heroRow == 9 && heroColumn == 12))
			levelData[7][12] = symbolBomb;
		if (levelSelector == 4 && (heroRow == 9 && heroColumn == 13))
			levelData[7][13] = symbolBomb;
		if (levelSelector == 4 && (heroRow == 6 && heroColumn == 12))
			levelData[4][12] = symbolBomb;
		if (levelSelector == 4 && (heroRow == 6 && heroColumn == 13))
			levelData[4][13] = symbolBomb;
		// Final Door
		if (levelSelector == 4 && secretDoorSelector == false && ((heroRow == 2 && heroColumn == 12) || (heroRow == 2 && heroColumn == 13)))
		{
			levelData[1][12] = symbolDoorG;
			levelData[1][13] = symbolDoorG;
			levelData[10][13] = symbolKey;
			secretDoorSelector = true;
		}

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
				Initialise(rowsCount, columnsCount);
			}
			if (levelSelector == 2)
			{
				LevelClear();
				Initialise2(rowsCount2, columnsCount2);
			}
			if (levelSelector == 3)
			{
				LevelClear();
				Initialise2(rowsCount3, columnsCount3);
			}
			if (levelSelector == 4)
			{
				levelSelector = 3;
				LevelClear();
				Initialise2(rowsCount3, columnsCount3);
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
			printf("\n\t Well play. Press any key to exit, dude...");
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
}



int main()
{
	SetupSystem();

	// Select Language
	do
	{
		RenderLanguage();
		UpdateLanguage();
	} 
	while (isGameActive == true);
	
	//// Level 1
	//system("cls");
	//isGameActive = true;
	//levelSelector = 1;
	//Initialise2(rowsCount, columnsCount);
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
	Initialise2(rowsCount2, columnsCount2);
	do
	{
		Render2(rowsCount2, columnsCount2);
		Update();
	} while (isGameActive);
	
	// Level 3
	system("cls");
	isGameActive = true;
	LevelClear();
	levelSelector = 3;
	Initialise2(rowsCount3, columnsCount3);
	do
	{
		Render2(rowsCount3, columnsCount3);
		Update();
	} while (isGameActive);
	

	Shutdown();

	return 0;
}

