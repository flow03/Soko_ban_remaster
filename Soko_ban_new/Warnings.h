#pragma once
//int Localization;
//HANDLE consoleHandle;

enum Warning
{
	None,
	keyWarning,		
	crystalWarning,	
	bombWarning,    
	bonusWallWarning,
	bonusLevelWarning,
	secretDoorWarning,
	secretBombsWarning,
	secretBombLeft, 
	secretBombRight,
	secretBombDamn
};

Warning warning = None; //None test

void Warnings(Warning warn) {

	switch (warn)
	{
	case None:
		std::cout << "\n\t\t\t\t\t\t\t\t"; // 64
		break;
	case keyWarning:
		switch (Localization)
		{
		case 1:
		{
			setlocale(LC_ALL, "Russian");
			printColorText(consoleHandle, "\n\t\t\t    I ���� �� ��� ", Yellow);
			printColorText(consoleHandle, "�����", LightMagenta);
			printColorText(consoleHandle, " �i��� ? ", Yellow);
			break;
		}
		case 2:
		{
			setlocale(LC_ALL, "Russian");
			/*if (levelSelector == 3 || levelSelector == 4)
				printf(" ");*/
			printColorText(consoleHandle, "\n\t\t\t\t    ����� ", Yellow);
			printColorText(consoleHandle, "����     ", LightMagenta);
			break;
		}
		case 3:
		{
			//setlocale(LC_ALL, "C");
			printColorText(consoleHandle, "\n\t\t\t\t  Need some ", Yellow);
			printColorText(consoleHandle, "Key     ", LightMagenta);
			break;
		}
		}
		break;
	case crystalWarning:
		switch (Localization)
		{
		case 1:
		{
			setlocale(LC_ALL, "Russian");
			printColorText(consoleHandle, "\n\t\t\t   ���� �i������? � �� ", Yellow);
			printColorText(consoleHandle, symbolCrystal, Magenta);
			printColorText(consoleHandle, " ������!", Yellow);
			break;
		}
		case 2:
		{
			setlocale(LC_ALL, "Russian");
			printColorText(consoleHandle, "\n\t\t\t\t  ����� ������ ", Yellow);
			printColorText(consoleHandle, symbolCrystal, Magenta);
			break;
		}
		case 3:
		{
			setlocale(LC_ALL, "C");
			printColorText(consoleHandle, "\n\t\t\t\t  Collect more ", Yellow);
			printColorText(consoleHandle, symbolCrystal, Magenta);
			break;
		}
		}
		break;
	case bombWarning:
		switch (Localization)
		{
		case 1:
		{
			setlocale(LC_ALL, "Russian");
			printColorText(consoleHandle, "\n\t\t\t     � � ����� �� �i��� � ", Yellow);
			printColorText(consoleHandle, "���", Red);
			printColorText(consoleHandle, "!", Yellow);
			break;
		}
		case 2:
		{
			setlocale(LC_ALL, "Russian");
			printColorText(consoleHandle, "\n\t\t\t\t    ���������", Yellow);
			break;
		}
		case 3:
		{
			setlocale(LC_ALL, "C");
			printColorText(consoleHandle, "\n\t\t\t       Oops! You just died", Yellow);
			break;
		}
		}
		break;
	case bonusWallWarning:
		switch (Localization)
		{
		case 1:
		{
			setlocale(LC_ALL, "Russian");
			printColorText(consoleHandle, "\n\t\t\t\t��i�� � ���������", Yellow);
			break;
		}
		case 2:
		{
			setlocale(LC_ALL, "Russian");
			printColorText(consoleHandle, "\n\t\t\t\t     �������", Yellow);
			break;
		}
		case 3:
		{
			setlocale(LC_ALL, "C");
			printColorText(consoleHandle, "\n\t\t\t\t     Surprise", Yellow);
			break;
		}
		}
		break;
	case bonusLevelWarning:
		if (Localization == 1)
		{
			setlocale(LC_ALL, "Russian");
			printColorText(consoleHandle, "\n\t\t\t       ��� ��� ������i�����!", Yellow);
		}
		else if (Localization == 2)
		{
			setlocale(LC_ALL, "Russian");
			printColorText(consoleHandle, "\n\t\t\t\t  ��� ��� �������!", Yellow);
		}
		else if (Localization == 3)
		{
			setlocale(LC_ALL, "�");
			printColorText(consoleHandle, "\n\t\t\t      Surprise, motherfucker!", Yellow);
		}
		warning = None;
		break;
	case secretDoorWarning:
		switch (Localization)
		{
		case 1:
		{
			setlocale(LC_ALL, "Russian");
			printColorText(consoleHandle,
				"\n\t\t     �� ������� ������ ���. �i���� ����������", Yellow); //41+21=62
			break;
		}
		case 2:
		{
			setlocale(LC_ALL, "Russian");
			printColorText(consoleHandle, "\n\t\t\t  ��! ��� ������ ������ �������?!", Yellow); //57
			break;
		}
		case 3:
		{
			setlocale(LC_ALL, "C");
			printColorText(consoleHandle, "\n\t\t\t  Hey! You found the secret door!", Yellow); //57
			break;
		}
		}
		break;
	case secretBombsWarning:
		switch (Localization)
		{
			case 1:
			{
				setlocale(LC_ALL, "Russian");
				printColorText(consoleHandle, "\n\t\t\t  ��������! ��� ��������i ", Yellow);  // 25+33=58
				printColorText(consoleHandle, "������", Red);
				printColorText(consoleHandle, '!', Yellow);
				break;
			}
			case 2:
			{
				setlocale(LC_ALL, "Russian");
				printColorText(consoleHandle, "\n\t\t\t ���������! ����� ���������� ", Yellow); // 24+33=57
				printColorText(consoleHandle, "����", Red);
				printColorText(consoleHandle, '!', Yellow);
				break;
			}
			case 3:
			{
				setlocale(LC_ALL, "C");
				printColorText(consoleHandle, "\n\t\t\t Carreful! There are hidden ", Yellow); // 25+33=58
				printColorText(consoleHandle, "bombs", Red);
				printColorText(consoleHandle, '!', Yellow);
				break;
			}
		}
		break;
	case secretBombLeft:
	case secretBombRight:
		switch (Localization)
		{
			case 1:
			{
				setlocale(LC_ALL, "Russian");
				printColorText(consoleHandle, "\n\t\t\t  �������� ", Yellow); 
				printColorText(consoleHandle, "������", Red);
				printColorText(consoleHandle, '!', Yellow);
				printColorText(consoleHandle, " �� ����� ��� ", Yellow);
				if (warn == secretBombLeft) printColorText(consoleHandle, "��i��", Yellow);
				if (warn == secretBombRight) printColorText(consoleHandle, "������", Yellow);
				break;
			}
			case 2:
			{
				setlocale(LC_ALL, "Russian");
				printColorText(consoleHandle, "\n\t\t\t������� ", Yellow); 
				printColorText(consoleHandle, "����", Red);
				printColorText(consoleHandle, '!', Yellow);
				printColorText(consoleHandle, " �� ������� ������� ", Yellow);
				if (warn == secretBombLeft) printColorText(consoleHandle, "�����", Yellow);
				if (warn == secretBombRight) printColorText(consoleHandle, "������", Yellow);
				break;
			}
			case 3:
			{
				setlocale(LC_ALL, "C");
				printColorText(consoleHandle, "\n\t\t\t     Bomb", Red);
				printColorText(consoleHandle, " ahead! Don't go ", Yellow);
				if (warn == secretBombLeft) printColorText(consoleHandle, "left", Yellow);
				if (warn == secretBombRight) printColorText(consoleHandle, "right", Yellow);
				break;
			}
		}
		break;
	case secretBombDamn:
		switch (Localization)
		{
		case 1:
		{
			setlocale(LC_ALL, "Russian");
			printColorText(consoleHandle, "\n\t\t\t\t�� ����� ���� �����!", Yellow);
			break;
		}
		case 2:
		{
			setlocale(LC_ALL, "Russian");
			printColorText(consoleHandle, "\n\t\t\t\t    ׸�� ������!", Yellow);
			break;
		}
		case 3:
		{
			setlocale(LC_ALL, "C");
			printColorText(consoleHandle, "\n\t\t\t\t Damn! I warned you", Yellow);
			break;
		}
		}
		break;
	}
	
		/*_getch();
		LevelClear();
		if (levelSelector == 2)
			Initialise2(rowsCount2, columnsCount2);
		if (levelSelector == 3)
			Initialise2(rowsCount3, columnsCount3);
		if (levelSelector == 4)
		{
			levelSelector = 3;
			Initialise2(rowsCount3, columnsCount3);

			break;
		}*/

		//}
		//else
		//{
		//	bombSelector = false;
		//	if (levelSelector == 2)
		//		Render2(rowsCount2, columnsCount2);
		//	if (levelSelector == 3)
		//		Render2(rowsCount3, columnsCount);
		//}

	warning = None; //Warnings reset
	setlocale(LC_ALL, "C");
}

void Description() 
{
	switch (Localization)
	{
		case 1: //UA
		{
			setlocale(LC_ALL, "Russian");
			std::cout << "\n   ����� ";
			printColorText(consoleHandle, "�������", LightGreen);
			std::cout << ". ������ ";
			printColorText(consoleHandle, symbolCrystal, Magenta);
			std::cout << " i ";
			printColorText(consoleHandle, "����i", LightMagenta);
			std::cout << '(';
			printColorText(consoleHandle, symbolKey, LightMagenta);
			std::cout << ") ��� �������. R - ��������� ��������.\n   ������������ ";
			printColorText(consoleHandle, "����i �����i", LightCyan);
			std::cout << '(';
			printColorText(consoleHandle, 'O', LightCyan);
			std::cout << ") i ������ �������� (";
			setlocale(LC_ALL, "C");
			std::cout << symbolDoorG << ", " << symbolDoorV;
			setlocale(LC_ALL, "Russian");
			std::cout << "). �� �������� � ";
			printColorText(consoleHandle, "���", Red);
			std::cout << '(';
			printColorText(consoleHandle, symbolBomb, Red);
			std::cout << ").";
			break;
		}
		case 2: //RU
		{
			setlocale(LC_ALL, "Russian");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("\n   ���������� ");
			SetConsoleTextAttribute(consoleHandle, 10);
			printf("������");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(". ��������� ");
			SetConsoleTextAttribute(consoleHandle, 5);
			printf("%c", symbolCrystal);
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(" � ");
			SetConsoleTextAttribute(consoleHandle, 13);
			printf("�����");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("(");
			SetConsoleTextAttribute(consoleHandle, 13);
			printf("%c", symbolKey);
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(") ����� ��������. R - ����������.");
			printf("\n   ����������� ");
			SetConsoleTextAttribute(consoleHandle, 11);
			printf("�������");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("(");
			SetConsoleTextAttribute(consoleHandle, 11);
			printf("O");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(") � ����� (");
			setlocale(LC_ALL, "C");
			printf("%c, %c", symbolDoorG, symbolDoorV);
			setlocale(LC_ALL, "Russian");
			printf("). ������ ��������� � ");
			SetConsoleTextAttribute(consoleHandle, Red);
			printf("������");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("(");
			SetConsoleTextAttribute(consoleHandle, Red);
			printf("%c", symbolBomb);
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("). �����");
			break;
		}
		case 3: //ENG
		{
			setlocale(LC_ALL, "C");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("\n\tMove your ");
			SetConsoleTextAttribute(consoleHandle, 10);
			printf("Hero");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(". Collect ");
			SetConsoleTextAttribute(consoleHandle, 5);
			printf("%c", symbolCrystal);
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(" and ");
			SetConsoleTextAttribute(consoleHandle, 13);
			printf("Keys");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("(");
			SetConsoleTextAttribute(consoleHandle, 13);
			printf("%c", symbolKey);
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(") to win. R - Restart level.");
			printf("\n\tUse the ");
			SetConsoleTextAttribute(consoleHandle, 11);
			printf("Portals");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("(");
			SetConsoleTextAttribute(consoleHandle, 11);
			printf("O");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(") and the Doors (%c, %c). Carreful with ", symbolDoorG, symbolDoorV);
			SetConsoleTextAttribute(consoleHandle, Red);
			printf("Mines");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("(");
			SetConsoleTextAttribute(consoleHandle, Red);
			printf("%c", symbolBomb);
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("). Gl hf");
			break;
		}
	}
}