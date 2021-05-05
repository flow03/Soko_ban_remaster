#include "MultiStr.h"

extern HANDLE consoleHandle;
extern int Localization;
extern bool isGameStart;
extern int RestartKey;
const unsigned char symbolHero = 2;

MultiStr continueStr, newGameStr, loadStr, settingsStr, staticsticStr, exitStr;
MultiStr strYes, strNo;

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
		continueStr = "����������";
		newGameStr = "���� ���";
		loadStr = "�����������/��������";
		settingsStr = "������������";
		staticsticStr = "����������";
		exitStr = "���i�";

		strYes = "���";
		strNo = "Hi";

		break;
	case 2: //RU
		continueStr = "����������";
		newGameStr = "����� ����";
		loadStr = "���������/���������";
		settingsStr = "���������";
		staticsticStr = "����������";
		exitStr = "�����";

		strYes = "��";
		strNo = "���";

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

void RenderSettings(int selector)
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
		languageStr = "���� �����, ����i�� ���� ����";
		fontStr = "����i� ������";
		currentLanguage = "���������";
		RkeyStr = "������ �����������";
		break;
	case 2:
		languageStr = "�������� ����";
		fontStr = "�������� �����";
		currentLanguage = "�������";
		RkeyStr = "������ ��������";
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
}
