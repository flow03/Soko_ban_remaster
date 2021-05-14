#include "MultiStr.h"

extern HANDLE consoleHandle;
extern int Localization;
extern bool isGameStart;
extern unsigned char RestartKey;
const unsigned char symbolHero = 2;

MultiStr continueStr, newGameStr, loadMenuStr, settingsStr, staticsticStr, exitStr;
MultiStr strYes, strNo;
MultiStr attentionStr, keyWarningOne, keyWarningTwo, saveWarning;
MultiStr cancelStr, saveStr, loadStr;


MultiStr::MultiStr()
{
	str = nullptr;
	indent = 0;
}

MultiStr::MultiStr(const char * c_str)
{
	//strcpy_s(str, strlen(c_str) + 1, c_str);
	//strncpy_s(str, c_str, strlen(c_str) + 1);
	str = c_str;
	indent = static_cast<short>(40 - (strlen(str) / 2 + 1));
}

MultiStr::operator const char*() const { return str; }

short MultiStr::getI() const { return indent; }	// + symbolHero and space

std::ostream & operator<<(std::ostream &out, const MultiStr &multi)
{
	//SetConsoleCursorPosition(consoleHandle, COORD{ multi.indent, 6 });	// y???
	out << multi.str;

	return out;
}

void MenuInit()
{
	switch (Localization)
	{
	case 1: //UA
		continueStr = "Продовжити";
		newGameStr = "Нова гра";
		loadMenuStr = "Завантажити/Зберегти";
		settingsStr = "Налаштування";
		staticsticStr = "Статистика";
		exitStr = "Вихiд";

		strYes = "Так";
		strNo = "Hi";
		attentionStr = "Увага!";
		keyWarningOne = "Клавiшi W, A, S, D, Esc та стрiлки не можуть перезапускати гру";
		keyWarningTwo = "Перезапускати гру можна тiльки клавiшами латинського алфавiту A-Z";
		saveWarning = "Буде збережена тiльки статистика гравця, досягнення та поточний рiвень";

		saveStr = "Зберегти";
		loadStr = "Завантажити";
		cancelStr = "Назад";

		break;
	case 2: //RU
		continueStr = "Продолжить";
		newGameStr = "Новая игра";
		loadMenuStr = "Сохранить/Загрузить";
		settingsStr = "Настройки";
		staticsticStr = "Статистика";
		exitStr = "Выход";

		strYes = "Да";
		strNo = "Нет";
		attentionStr = "Внимание!";
		keyWarningOne = "Клавиши W, A, S, D, Esc и стрелочки отвечают за управление";
		keyWarningTwo = "Допускаются только клавиши латиницы от A до Z";
		saveWarning = "Игра сохраняет только статистику игрока, достижения и текущий уровень";

		saveStr = "Сохранить игру";
		loadStr = "Загрузить игру";
		cancelStr = "Отмена";

		break;
	case 3: //ENG
		continueStr = "Continue";
		newGameStr = "New game";
		loadMenuStr = "Save/Load";
		settingsStr = "Settings";
		staticsticStr = "Statistic";
		exitStr = "Exit";

		strYes = "Yes";
		strNo = "No";
		attentionStr = "Attention!";
		keyWarningOne = "Keys W, A, S, D, Esc and arrows couldn't restart the game";
		keyWarningTwo = "Please, use A-Z keys only";
		saveWarning = "The game only saves player statistics, achievements and current level";

		saveStr = "Save";
		loadStr = "Load";
		cancelStr = "Cancel";

		break;
	default:
		continueStr = newGameStr = loadMenuStr = settingsStr = staticsticStr = exitStr = "";
		break;
	}
}

void out_Menu(int selector)
{
	setlocale(LC_ALL, "Russian");
	short y = 6;

	if (isGameStart)
	{
		SetConsoleCursorPosition(consoleHandle, COORD{ continueStr.getI() - 2, y });
		if (selector == 0)
		{
			printColorText(consoleHandle, symbolHero, LightGreen);
			std::cout << ' ';
			printColorText(consoleHandle, continueStr, Yellow);
		}
		else std::cout << "  " << continueStr;
		y += 2;
	}

	SetConsoleCursorPosition(consoleHandle, COORD{ newGameStr.getI() - 2, y });
	if (selector == 1)
	{
		printColorText(consoleHandle, symbolHero, LightGreen);
		std::cout << ' ';
		printColorText(consoleHandle, newGameStr, Yellow);
	}
	else std::cout << "  " << newGameStr;
	y += 2;

	SetConsoleCursorPosition(consoleHandle, COORD{ loadMenuStr.getI() - 2, y });
	if (selector == 2)
	{
		printColorText(consoleHandle, symbolHero, LightGreen);
		std::cout << ' ';
		printColorText(consoleHandle, loadMenuStr, Yellow);
	}
	else std::cout << "  " << loadMenuStr;
	y += 2;

	SetConsoleCursorPosition(consoleHandle, COORD{ settingsStr.getI() - 2, y });
	if (selector == 3)
	{
		printColorText(consoleHandle, symbolHero, LightGreen);
		std::cout << ' ';
		printColorText(consoleHandle, settingsStr, Yellow);
	}
	else std::cout << "  " << settingsStr;
	y += 2;

	SetConsoleCursorPosition(consoleHandle, COORD{ staticsticStr.getI() - 2, y });
	if (selector == 4)
	{
		printColorText(consoleHandle, symbolHero, LightGreen);
		std::cout << ' ';
		printColorText(consoleHandle, staticsticStr, Yellow);
	}
	else std::cout << "  " << staticsticStr;
	y += 2;

	SetConsoleCursorPosition(consoleHandle, COORD{ exitStr.getI() - 2, y });
	if (selector == 5)
	{
		printColorText(consoleHandle, symbolHero, LightGreen);
		std::cout << ' ';
		printColorText(consoleHandle, exitStr, Yellow);
	}
	else std::cout << "  " << exitStr;
	//y += 2;
}

void out_YesNo(bool ask)
{
	const char* indent_ = "           ";
	short y = static_cast<short>(40 - ((strlen(strYes) + strlen(indent_) + strlen(strNo) + 2) / 2));	// 2 + 2 + 2
	SetConsoleCursorPosition(consoleHandle, COORD{ y, 8 });

	if (ask)
	{
		printColorText(consoleHandle, symbolHero, LightGreen);
		std::cout << ' ';
		printColorText(consoleHandle, strYes, Yellow);
		std::cout << indent_ << "  " << strNo;
	}
	else
	{
		std::cout << "  " << strYes << indent_;
		printColorText(consoleHandle, symbolHero, LightGreen);
		std::cout << ' ';
		printColorText(consoleHandle, strNo, Yellow);
	}
}

void out_RenderSettings(int selector, char &key)
{
	//system("cls");
	
	setlocale(LC_ALL, "Russian");
	short y = 1;
	SetConsoleCursorPosition(consoleHandle, COORD{ 0, y });
	std::cout << std::setw(80) << std::setfill(' ') << "";
	SetConsoleCursorPosition(consoleHandle, COORD{ settingsStr.getI(), y });
	std::cout << settingsStr;

	const char *languageStr, *fontStr, *currentLanguage, *currentFont, *RkeyStr;
	

	switch (Localization)
	{
	case 1:
		languageStr = "Будь ласка, оберiть вашу мову";
		fontStr = "Розмiр шрифту";
		currentLanguage = "Українська";
		RkeyStr = "Клавiша перезапуску";
		break;
	case 2:
		languageStr = "Выберите язык";
		fontStr = "Выберите шрифт";
		currentLanguage = "Русский";
		RkeyStr = "Кнопка рестарта";
		break;
	case 3:
		languageStr = "Select your language";
		fontStr = "Select font size";
		currentLanguage = "English";
		RkeyStr = "Restart key";
		break;
	default:
		languageStr = fontStr = currentLanguage = RkeyStr = "Language Error";
		break;
	}

	switch (font)
	{
	case 0:
		currentFont = "8x12";
		break;
	case 1:
		currentFont = "12x16";
		break;
	default:
		currentFont = "Font Error";
		break;
	}

	y += 3;
	SetConsoleCursorPosition(consoleHandle, COORD{ 0, y });
	std::cout << "\t\t" << std::setw(40) << std::left << languageStr;
	SetConsoleCursorPosition(consoleHandle, COORD{ 45, y });
	std::cout << std::setw(15) << std::right;
	if (selector == 0) printColorText(consoleHandle, currentLanguage, Yellow);
	else std::cout << currentLanguage;

	y += 2;
	SetConsoleCursorPosition(consoleHandle, COORD{ 0, y });
	std::cout << "\t\t" << std::setw(40) << std::left << fontStr;
	SetConsoleCursorPosition(consoleHandle, COORD{ 45, y });
	std::cout << std::setw(15) << std::right;
	if (selector == 1) printColorText(consoleHandle, currentFont, Yellow);
	else std::cout << currentFont;

	y += 2;
	SetConsoleCursorPosition(consoleHandle, COORD{ 0, y });
	std::cout << "\t\t" << std::setw(40) << std::left << RkeyStr;
	SetConsoleCursorPosition(consoleHandle, COORD{ 45, y });
	std::cout << std::setw(15) << std::right;
	if (selector == 2) printColorText(consoleHandle, RestartKey, Yellow);
	else std::cout << RestartKey;

	if (selector == 2 && key != 0)
	{
		out_WrongKey(key);
		key = 0;
	}
	else
	{
		SetConsoleCursorPosition(consoleHandle, COORD{ 0, 21 });
		std::cout << std::setw(80) << std::setfill(' ') << "";
		//SetConsoleCursorPosition(consoleHandle, COORD{ 0, 22 });
		std::cout << std::setw(80) << std::setfill(' ') << "";
	}
}

void out_WrongKey(char key)
{
	bool otherKey = false;
	COORD coord = { 0, 21 };

	if (key != 'W' && key != 'S' && key != 'A' && key != 'D' && key != 27)
		otherKey = true;

	setlocale(LC_ALL, "Russian");
	SetConsoleCursorPosition(consoleHandle, coord);
	std::cout << std::setw(80) << std::setfill(' ') << "";
	std::cout << std::setw(80) << std::setfill(' ') << "";
	SetConsoleCursorPosition(consoleHandle, COORD{ attentionStr.getI(), coord.Y });
	printColorText(consoleHandle, attentionStr, Yellow);
	coord.Y += 1;

	if (!otherKey)
	{
		coord.X = keyWarningOne.getI();
		SetConsoleCursorPosition(consoleHandle, coord);
		std::cout << keyWarningOne;
	}
	else
	{
		coord.X = keyWarningTwo.getI();
		SetConsoleCursorPosition(consoleHandle, coord);
		std::cout << keyWarningTwo;
	}
}

void out_LoadMenu(int selector)
{
	setlocale(LC_ALL, "Russian");
	short y = 6;

	if (isGameStart)
	{
		SetConsoleCursorPosition(consoleHandle, COORD{ saveStr.getI() - 2, y });
		if (selector == 0)
		{
			printColorText(consoleHandle, symbolHero, LightGreen);
			std::cout << ' ';
			printColorText(consoleHandle, saveStr, Yellow);
		}
		else std::cout << "  " << saveStr;
		y += 2;
	}

	SetConsoleCursorPosition(consoleHandle, COORD{ loadStr.getI() - 2, y });
	if (selector == 1)
	{
		printColorText(consoleHandle, symbolHero, LightGreen);
		std::cout << ' ';
		printColorText(consoleHandle, loadStr, Yellow);
	}
	else std::cout << "  " << loadStr;
	y += 2;

	SetConsoleCursorPosition(consoleHandle, COORD{ cancelStr.getI() - 2, y });
	if (selector == 2)
	{
		printColorText(consoleHandle, symbolHero, LightGreen);
		std::cout << ' ';
		printColorText(consoleHandle, cancelStr, Yellow);
	}
	else std::cout << "  " << cancelStr;
	//y += 2;
}

void out_SaveDescription()
{
	COORD coord = { 0, 21 };

	setlocale(LC_ALL, "Russian");
	SetConsoleCursorPosition(consoleHandle, coord);
	std::cout << std::setw(80) << std::setfill(' ') << "";
	std::cout << std::setw(80) << std::setfill(' ') << "";
	SetConsoleCursorPosition(consoleHandle, COORD{ attentionStr.getI(), coord.Y });
	printColorText(consoleHandle, attentionStr, Yellow);
	coord.Y += 1;

	coord.X = saveWarning.getI();
	SetConsoleCursorPosition(consoleHandle, coord);
	std::cout << saveWarning;
}

void out_SaveList(std::vector<Save>&saves, int selector)
{
	//SetConsoleCursorPosition(consoleHandle, COORD{ 0, 0 });
	short x1 = static_cast<short>(40 - (25 / 2 + 1));
	//short x2 = static_cast<short>(40 - (22 / 2 + 1));
	COORD coord = { x1, 3 };
	int i = 0;

	for (auto iter = saves.rbegin(); iter != saves.rend(); ++iter)
	{
		SetConsoleCursorPosition(consoleHandle, coord);
		if (i == selector)
		{
			SetColor(consoleHandle, Yellow);
			iter->outDate(); 
			SetColor(consoleHandle, LightGray);
		}
		else iter->outDate();

		coord.Y++;
		SetConsoleCursorPosition(consoleHandle, coord);
		iter->outParam();
		coord.Y += 2;
		++i;
	}

	//_getch();
}
