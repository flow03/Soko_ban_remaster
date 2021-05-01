#include "MainMenu.h"

const unsigned char symbolHero = 2;

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
		MenuInit();
		isMenuActive = false;
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
		isMenuActive = false;
		break;
	}
	}

	SetupFont();
	CenterWindow();
}

void UpdateLoad(int &selector, Save &savegame, int down)
{
	// Render
	SetConsoleCursorPosition(consoleHandle, COORD{ 0, 6 });
	setlocale(LC_ALL, "Russian");

	if (isGameStart)
	{
		std::cout << "\t\t\t     ";
		if (selector == 0)
		{
			printColorText(consoleHandle, symbolHero, LightGreen);
			printColorText(consoleHandle, " Сохранить игру\n", Yellow);
		}
		else
		{
			std::cout << "  Сохранить игру   \n";
		}
	}

	std::cout << "\n\t\t\t     ";
	if (selector == 1)
	{
		printColorText(consoleHandle, symbolHero, LightGreen);
		printColorText(consoleHandle, " Загрузить игру\n", Yellow);
	}
	else
	{
		std::cout << "  Загрузить игру   \n";
	}

	std::cout << "\n\t\t\t     ";
	if (selector == 2)
	{
		printColorText(consoleHandle, symbolHero, LightGreen);
		printColorText(consoleHandle, " Отмена\n", Yellow);
	}
	else
	{
		std::cout << "  Отмена   \n";
	}

	// Update
	char Key = _getch();

	switch (Key)
	{
		// Arrow down
	case 80:
	case 's':
	case 'S':
	{
		selector++;
		if (selector > 2)
			selector = down;

		break;
	}
	// Arrow up
	case 72:
	case 'w':
	case 'W':
	{
		selector--;
		if (selector < down)
			selector = 2;

		break;
	}
	// Enter
	case 13:
	{
		if (selector == 0)	// Save
		{
			savegame.SaveToFile();
		}
		else if (selector == 1)	// Load
		{
			savegame.LoadFromFile();
			savegame.applySave();
			std::queue<Warning> temp_warn;
			warning.swap(temp_warn);
			NextLevel(savegame.getLevel());
			isGameStart = true;
		}

		isMenuActive = false;	// Cancel
		break;
	}
	// Esc
	case 27:
	{
		isMenuActive = false;	// Cancel
		break;
	}
	}

	//SetupFont();
	//CenterWindow();
}

// internal	  
bool ExitAsk()
{
	bool result = false;
	const char * strAsk;
	bool ExitMenuActive = true;

	switch (Localization)
	{
	case 1: //UA
		strAsk = "Бажаете вийти з гри?";
		break;
	case 2: //RU
		strAsk = "Вы действительно желаете выйти?";
		break;
	case 3: //ENG
		strAsk = "Do you want exit?";
		break;
	default:
		strAsk = "";
		break;
	}

	system("cls");

	setlocale(LC_ALL, "Russian");
	short y = static_cast<short>(40 - (strlen(strAsk) / 2) + 1);
	SetConsoleCursorPosition(consoleHandle, COORD{ y, 6 });
	std::cout << strAsk;

	bool ask = false;
	do {
		// Render
		YesNoOut(ask);

		// Update
		char Key = _getch();

		switch (Key)
		{
			// Left
		case 'a':
		case 'A':
		case 75:
		{
			ask = true;
			break;
		}
		// Right
		case 'd':
		case 'D':
		case 77:
		{
			ask = false;
			break;
		}
		// Enter
		case 13:
			if (ask) result = true;	// Yes
			else result = false;	// No
			ExitMenuActive = false;
			break;
			// Esc
		case 27:
			result = false;
			ExitMenuActive = false;	// Cancel
			break;
		}
	} while (ExitMenuActive);

	system("cls");

	return result;
}
// internal	 
bool NewAsk()
{
	bool result = true;
	const char * strAsk;

	switch (Localization)
	{
	case 1: //UA
		strAsk = "Затерти всі досягнення?";
		break;
	case 2: //RU
		strAsk = "Сбросить все достижения?";
		break;
	case 3: //ENG
		strAsk = "Do you want reset all ahievements?";
		break;
	default:
		strAsk = "";
		break;
	}

	system("cls");

	setlocale(LC_ALL, "Russian");
	short y = static_cast<short>(40 - (strlen(strAsk) / 2) + 1);
	SetConsoleCursorPosition(consoleHandle, COORD{ y, 6 });
	std::cout << strAsk;

	bool ask = false;
	do {
		// Render
		YesNoOut(ask);

		// Update
		char Key = _getch();

		switch (Key)
		{
			// Left
		case 'a':
		case 'A':
		case 75:
		{
			ask = true;
			break;
		}
		// Right
		case 'd':
		case 'D':
		case 77:
		{
			ask = false;
			break;
		}
		// Enter
		case 13:
			if (ask) AchievesClear();	// Yes
			isMenuActive = false;
			break;
			// Esc
		case 27:
			isMenuActive = false;	// Cancel
			result = false;
			break;
		}
	} while (isMenuActive);

	//system("cls");

	return result;
}
// internal	 
void NewGame()
{
	if (!isGameStart)
	{
		NextLevel(1);
		isGameStart = true;
	}
	else if (NewAsk()) NextLevel(1);

	isMenuActive = false;
}
// internal	
void UpdateMenu(int &selector, int up, int down)
{
	// Render
	MenuOut(selector);

	// Update
	char Key = _getch();

	switch (Key)
	{
		// Arrow down
	case 80:
	case 's':
	case 'S':
	{
		selector++;
		if (selector > up)
			selector = down;

		break;
	}
	// Arrow up
	case 72:
	case 'w':
	case 'W':
	{
		selector--;
		if (selector < down)
			selector = up;

		break;
	}
	// Enter
	case 13:
	{
		if (selector == 0)	// Continue
		{
			isMenuActive = false;
		}
		else if (selector == 1)	// New
		{
			NewGame();
		}
		else if (selector == 2)	// Save/Load
		{
			GameLoadMenu();
		}
		else if (selector == 3)	// Settings
		{
			Settings();
		}
		else if (selector == 4)	// Statistic
		{
			Statistic();
		}
		else if (selector == 5)	// Exit
		{
			if (ExitAsk())
			{
				isGameActive = false;
				isMenuActive = false;
			}
		}
		break;
	}
	// Esc
	case 27:
	{
		if (isGameStart) isMenuActive = false;	// Cancel
		else ExitAsk();
		break;
	}
	}

	//SetupFont();
	//CenterWindow();
}

void MainMenu()
{
	MenuInit();

	system("cls");

	// Select
	int up = 5;
	int down = 0;

	if (!isGameStart) down = 1;

	int selector = down;

	isMenuActive = true;
	do
	{
		UpdateMenu(selector, up, down);
	} while (isMenuActive == true);


	system("cls");

	if (isGameActive) Description();
}

void Settings()
{
	system("cls");
	// Select Language
	isMenuActive = true;
	do
	{
		RenderLanguage();
		UpdateLanguage();
	} while (isMenuActive == true);

	// Select Font Size
	isMenuActive = true;
	do
	{
		RenderFont();
		UpdateFont();
	} while (isMenuActive == true);

	system("cls");
	isMenuActive = true;
}

void GameLoadMenu()
{
	system("cls");

	LoadDescription();

	Save savegame;
	int down = 0;
	if (!isGameStart) down = 1;
	int selector = down;

	isMenuActive = true;
	do UpdateLoad(selector, savegame, down);
	while (isMenuActive == true);

	system("cls");
	if (!isGameStart) isMenuActive = true;
}

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