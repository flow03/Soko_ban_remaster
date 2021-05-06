#include "MultiStr.h"

extern HANDLE consoleHandle;
extern int Localization;
extern bool isGameStart;
extern int RestartKey;
const unsigned char symbolHero = 2;

MultiStr continueStr, newGameStr, loadStr, settingsStr, staticsticStr, exitStr;
MultiStr strYes, strNo;
MultiStr attentionSrt, keyWarningOne, keyWarningTwo;

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
		loadStr = "Завантажити/Зберегти";
		settingsStr = "Налаштування";
		staticsticStr = "Статистика";
		exitStr = "Вихiд";

		strYes = "Так";
		strNo = "Hi";
		attentionSrt = "Увага!";
		keyWarningOne = "Клавiша _ не може перезапускати гру";
		keyWarningTwo = "Перезапускати гру можна тiльки клавiшами латинського алфавiту A-Z";

		break;
	case 2: //RU
		continueStr = "Продолжить";
		newGameStr = "Новая игра";
		loadStr = "Сохранить/Загрузить";
		settingsStr = "Настройки";
		staticsticStr = "Статистика";
		exitStr = "Выход";

		strYes = "Да";
		strNo = "Нет";
		attentionSrt = "Внимание!";
		keyWarningOne = "Клавиша _ не может быть назначена для рестарта игры";
		keyWarningTwo = "Допускаются только клавиши латиницы от A до Z";

		break;
	case 3: //ENG
		continueStr = "Continue";
		newGameStr = "New game";
		loadStr = "Save/Load";
		settingsStr = "Settings";
		staticsticStr = "Statistic";
		exitStr = "Exit";

		strYes = "Yes";
		strNo = "No";
		attentionSrt = "Attention!";
		keyWarningOne = "Key _ cannot be a restart key";
		keyWarningTwo = "Please, use A-Z keys only";

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

	SetConsoleCursorPosition(consoleHandle, COORD{ loadStr.getI() - 2, y });
	if (selector == 2)
	{
		printColorText(consoleHandle, symbolHero, LightGreen);
		std::cout << ' ';
		printColorText(consoleHandle, loadStr, Yellow);
	}
	else std::cout << "  " << loadStr;
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

void YesNoOut(bool ask)
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

void RenderSettings(int selector, char &key)
{
	//system("cls");
	
	setlocale(LC_ALL, "Russian");
	short y = 1;
	SetConsoleCursorPosition(consoleHandle, COORD{ 35, y });	// ukr indent
	std::cout << std::setw(12) << std::setfill(' ') << "";
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
	if (selector == 2) printColorText(consoleHandle, static_cast<char>(RestartKey), Yellow);
	else std::cout << static_cast<char>(RestartKey);

	if (selector == 2 && key != 0)
	{
		WrongKeyWarning(key);
		key = 0;
	}
	else
	{
		SetConsoleCursorPosition(consoleHandle, COORD{ 0, 21 });
		std::cout << std::setw(80) << std::right;
		SetConsoleCursorPosition(consoleHandle, COORD{ 0, 22 });
		std::cout << std::setw(80) << std::right;
	}
}

void WrongKeyWarning(char key)
{
	char keyStr[4];
	bool otherKey = false;
	//short x = 22;
	//short y = 0;
	COORD coord = { 0, 21 };

	switch (key)
	{
	case 27:
		strcpy_s(keyStr, "Esc");
		break;
		//case 80:
		//	keyStr = "\2193";	//"Arrow Down";
		//	break;
		//case 77:
		//	keyStr = "\2192";		//"Arrow Right";
		//	break;
		//case 75:
		//	keyStr = "\2190";	//"Arrow Left";
		//	break;
		//case 72:
		//	keyStr = "\2191";	//"Arrow Up";
		//	break;
	case 'W':
	case 'A':
	case 'S':
	case 'D':
		keyStr[0] = key;
		keyStr[1] = '\0';
		//strcat(keyStr, key);
		break;
	default:
		//keyStr = "Error";
		otherKey = true;
		break;
	}

	setlocale(LC_ALL, "Russian");
	/*SetConsoleCursorPosition(consoleHandle, coord);
	std::cout << std::setw(80) << std::right << "";
	SetConsoleCursorPosition(consoleHandle, coord);*/


	//if (!strcmp(keyStr, "Error Key"))
	if (!otherKey)
	{
		SetConsoleCursorPosition(consoleHandle, COORD{ attentionSrt.getI(), coord.Y });
		printColorText(consoleHandle, attentionSrt, Yellow);
		coord.Y += 1;
		coord.X = keyWarningOne.getI();
		SetConsoleCursorPosition(consoleHandle, coord);
		std::cout << keyWarningOne;
		coord.X += 8;
		SetConsoleCursorPosition(consoleHandle, coord);
		std::cout << keyStr;
	}
	//else
	//	switch (Localization)
	//	{
	//	case 1: //UA
	//	{
	//		printColorText(consoleHandle, "Увага!", Yellow);
	//		std::cout << " Перезапускати гру можна тiльки клавiшами латинського алфавiту A-Z";
	//		break;
	//	}
	//	case 2: //RU
	//	{
	//		printColorText(consoleHandle, "Внимание!", Yellow);
	//		std::cout << " Допускаются только клавиши латиницы от A до Z";
	//		break;
	//	}
	//	case 3: //ENG
	//	{
	//		printColorText(consoleHandle, "Attention!", Yellow);
	//		std::cout << " Please, use A-Z only";
	//		break;
	//	}
	//	}
}
