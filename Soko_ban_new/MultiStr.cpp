#include "MultiStr.h"

extern HANDLE consoleHandle;
extern int Localization;
extern bool isGameStart;
const unsigned char symbolHero = 2;
//short y = 6; // start value

MultiStr continueStr, newGameStr, loadStr, settingsStr, staticsticStr, exitStr;

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
	indent = static_cast<short>(40 - (strlen(str) / 2) + 1);
}

MultiStr::operator const char*() const { return str; }

short MultiStr::getI() const { return indent - 2; }	// + symbolHero and space

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
		loadStr = "Завантажити/Зберегти";
		settingsStr = "Налаштування";
		staticsticStr = "Статистика";
		exitStr = "Вихiд";
		break;
	case 2: //RU
		continueStr = "Продолжить";
		newGameStr = "Новая игра";
		loadStr = "Сохранить/Загрузить";
		settingsStr = "Настройки";
		staticsticStr = "Статистика";
		exitStr = "Выход";
		break;
	case 3: //ENG
		continueStr = "Continue";
		newGameStr = "New game";
		loadStr = "Save/Load";
		settingsStr = "Settings";
		staticsticStr = "Statistic";
		exitStr = "Exit";
		break;
	default:
		continueStr = newGameStr = loadStr = settingsStr = staticsticStr = exitStr = "";
		break;
	}
}

void MenuOut(int selector)
{
	setlocale(LC_ALL, "Russian");
	short y = 6;

	if (isGameStart)
	{
		SetConsoleCursorPosition(consoleHandle, COORD{ continueStr.getI(), y });
		if (selector == 0)
		{
			printColorText(consoleHandle, symbolHero, LightGreen);
			std::cout << ' ';
			printColorText(consoleHandle, continueStr, Yellow);
		}
		else std::cout << "  " << continueStr;
		y += 2;
	}

	SetConsoleCursorPosition(consoleHandle, COORD{ newGameStr.getI(), y });
	if (selector == 1)
	{
		printColorText(consoleHandle, symbolHero, LightGreen);
		std::cout << ' ';
		printColorText(consoleHandle, newGameStr, Yellow);
	}
	else std::cout << "  " << newGameStr;
	y += 2;

	SetConsoleCursorPosition(consoleHandle, COORD{ loadStr.getI(), y });
	if (selector == 2)
	{
		printColorText(consoleHandle, symbolHero, LightGreen);
		std::cout << ' ';
		printColorText(consoleHandle, loadStr, Yellow);
	}
	else std::cout << "  " << loadStr;
	y += 2;

	SetConsoleCursorPosition(consoleHandle, COORD{ settingsStr.getI(), y });
	if (selector == 3)
	{
		printColorText(consoleHandle, symbolHero, LightGreen);
		std::cout << ' ';
		printColorText(consoleHandle, settingsStr, Yellow);
	}
	else std::cout << "  " << settingsStr;
	y += 2;

	SetConsoleCursorPosition(consoleHandle, COORD{ staticsticStr.getI(), y });
	if (selector == 4)
	{
		printColorText(consoleHandle, symbolHero, LightGreen);
		std::cout << ' ';
		printColorText(consoleHandle, staticsticStr, Yellow);
	}
	else std::cout << "  " << staticsticStr;
	y += 2;

	SetConsoleCursorPosition(consoleHandle, COORD{ exitStr.getI(), y });
	if (selector == 5)
	{
		printColorText(consoleHandle, symbolHero, LightGreen);
		std::cout << ' ';
		printColorText(consoleHandle, exitStr, Yellow);
	}
	else std::cout << "  " << exitStr;
	//y += 2;
}
