#include "MainMenu.h"

const unsigned char symbolHero = 2;
extern unsigned char RestartKey;

// extern
void NextLevel(int); 
int ReadKey();
bool KeyValidation(int);

bool ExitAsk()
{
	bool result = false;
	bool ask = true;
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

	do {
		// Render
		out_YesNo(ask);

		// Update
		char Key = ReadKey();

		switch (Key)
		{
		// Left
		case 'A':
		{
			ask = true;
			break;
		}
		// Right
		case 'D':
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
	bool NewAskActive = true;
	bool ask = false;
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

	do {
		// Render
		out_YesNo(ask);

		// Update
		char Key = ReadKey();

		switch (Key)
		{
		// Left
		case 'A':
		{
			ask = true;
			break;
		}
		// Right
		case 'D':
		{
			ask = false;
			break;
		}
		// Enter
		case 13:
			if (ask) AchievesClear();	// Yes
			NewAskActive = false;
			break;
		// Esc
		case 27:
			NewAskActive = false;	// Cancel
			result = false;
			break;
		}
	} while (NewAskActive);

	system("cls");

	return result;
}
// internal	 
void NewGame()
{
	if (!isGameStart)
	{
		NextLevel(1);
		isGameStart = true;
		isMenuActive = false;
	}
	else if (NewAsk()) 
	{ 
		NextLevel(1); 
		isMenuActive = false;
	}
}
// internal	


void UpdateSettings(int &selector, char &key, bool &isSettingsActive)
{
	// Update
	switch (ReadKey())
	{
	// Arrow down
	case 80:
	case 's':
	case 'S':
	{
		selector++;
		if (selector > 2)
			selector = 0;
		break;
	}
	// Arrow up
	case 72:
	case 'w':
	case 'W':
	{
		selector--;
		if (selector < 0)
			selector = 2;
		break;
	}
	// Left
	case 'a':
	case 'A':
	case 75:
	{
		if (selector == 0)		// Language
		{
			Localization--;
			if (Localization < 1) Localization = 3;
			MenuInit();
		}
		else if (selector == 1)	// Font
		{
			font--;
			if (font < 0) font = 1;
			SetupFont();
			CenterWindow();
		}
		break;
	}
	// Right
	case 'd':
	case 'D':
	case 77:
	{
		if (selector == 0)		// Language
		{
			Localization++;
			if (Localization > 3) Localization = 1;
			MenuInit();
		}
		else if (selector == 1)	// Font
		{
			font++;
			if (font > 1) font = 0;
			SetupFont();
			CenterWindow();
		}
		break;
	}
	// Enter
	case 13:
		if (selector == 0)		// Language
		{
			Localization++;
			if (Localization > 3) Localization = 1;
			MenuInit();
		}
		else if (selector == 1)	// Font
		{
			font++;
			if (font > 1) font = 0;
			SetupFont();
			CenterWindow();
		}
		else if (selector == 2)	// Restart key
		{
			SetConsoleCursorPosition(consoleHandle, COORD{ 59, 8 });
			printColorText(consoleHandle, '_', Yellow);
			int tempKey = ReadKey();
			
			if (KeyValidation(tempKey))
			{
				RestartKey = tempKey;
			}
			else key = tempKey;
		}
		break;
	// Esc
	case 27:
	{
		isSettingsActive = false;	// Cancel
		break;
	}
	}
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

	auto UpdateMenu = [&selector](int up, int down)
	{
		// Render
		out_Menu(selector);

		// Update
		char Key = ReadKey();

		switch (Key)
		{
		// Arrow down
		case 'S':
		{
			selector++;
			if (selector > up)
				selector = down;

			break;
		}
		// Arrow up
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
				NewSettings();
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
			if (isGameStart) isMenuActive = false;	// Cancel
			else if (ExitAsk())
			{
				isGameActive = false;
				isMenuActive = false;
			}
			break;
		}
	};

	isMenuActive = true;
	do
	{
		UpdateMenu(up, down);
	} 
	while (isMenuActive == true);


	system("cls");

	if (isGameActive) Description();
}

void NewSettings()
{
	bool isSettingsActive = true;
	int selector = 0;
	char key = 0;

	system("cls");

	do
	{
		out_RenderSettings(selector, key);
		UpdateSettings(selector, key, isSettingsActive);
	} 
	while (isSettingsActive == true);

	system("cls");
	//isMenuActive = true;
}

void GameLoadMenu()
{
	bool LoadMenuActive = true;
	Save savegame;
	int down = 0;
	if (!isGameStart) down = 1;
	int selector = 2;	// Cancel

	

	auto UpdateLoad = [&selector, &savegame, &LoadMenuActive, down]()
	{
		// Render
		out_LoadMenu(selector);

		// Update
		char Key = ReadKey();

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
				AppendSave();
				//savegame.SaveToFile();
			}
			else if (selector == 1)	// Load
			{
				LoadAllSaves();
				if (!Saves.empty()) SaveList();
				//out_SaveList(Saves);
				/*savegame.LoadFromFile();
				savegame.applySave();
				std::queue<Warning> temp_warn;
				warning.swap(temp_warn);
				NextLevel(levelSelector);
				isGameStart = true;
				isMenuActive = false;*/
			}

			LoadMenuActive = false;
			break;
		}
		// Esc
		case 27:
		{
			LoadMenuActive = false;	// Cancel
			break;
		}
		}
	};

	system("cls");

	out_SaveDescription();	// one time output

	do UpdateLoad();
	while (LoadMenuActive == true);

	system("cls");
	//if (!isGameStart) isMenuActive = true;
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

void SaveList()
{
	//LoadAllSaves();
	bool ListMenuActive = true;
	int up = static_cast<int>(Saves.size()) - 1;
	//if (!isGameStart) down = 1;
	int selector = 0;	// Cancel
	
	auto UpdateList = [&selector, &ListMenuActive, up]()
	{
		char Key = ReadKey();

		switch (Key)
		{
		// Arrow down
		case 'S':
		{
			selector++;
			if (selector > up)
				selector = 0;
			break;
		}
		// Arrow up
		case 'W':
		{
			selector--;
			if (selector < 0)
				selector = up;
			break;
		}
		// Enter
		case 13:
		{
			

			ListMenuActive = false;
			break;
		}
		// Esc
		case 27:
		{
			ListMenuActive = false;	// Cancel
			break;
		}
		}
	};

	system("cls");
	do
	{
		out_SaveList(Saves, selector);	// Render
		UpdateList();					// Update
	}
	while (ListMenuActive == true);

	system("cls");
}