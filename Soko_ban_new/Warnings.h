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

	setlocale(LC_ALL, "Russian");

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
			printColorText(consoleHandle, "\n\t\t\t    I ���� �� ��� ", Yellow);
			printColorText(consoleHandle, "�����", LightMagenta);
			printColorText(consoleHandle, " �i��� ? ", Yellow);
			break;
		}
		case 2:
		{
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
			//
			printColorText(consoleHandle, "\n\t\t\t   ���� �i������? � �� ", Yellow);
			printColorText(consoleHandle, symbolCrystal, Magenta);
			printColorText(consoleHandle, " ������!", Yellow);
			break;
		}
		case 2:
		{
			//
			printColorText(consoleHandle, "\n\t\t\t\t  ����� ������ ", Yellow);
			printColorText(consoleHandle, symbolCrystal, Magenta);
			break;
		}
		case 3:
		{
			//setlocale(LC_ALL, "C");
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
			//
			printColorText(consoleHandle, "\n\t\t\t     � � ����� �� �i��� � ", Yellow);
			printColorText(consoleHandle, "���", Red);
			printColorText(consoleHandle, "!", Yellow);
			break;
		}
		case 2:
		{
			//
			printColorText(consoleHandle, "\n\t\t\t\t    ���������", Yellow);
			break;
		}
		case 3:
		{
			//setlocale(LC_ALL, "C");
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
			//
			printColorText(consoleHandle, "\n\t\t\t\t��i�� � ���������", Yellow);
			break;
		}
		case 2:
		{
			//
			printColorText(consoleHandle, "\n\t\t\t\t     �������", Yellow);
			break;
		}
		case 3:
		{
			//setlocale(LC_ALL, "C");
			printColorText(consoleHandle, "\n\t\t\t\t     Surprise", Yellow);
			break;
		}
		}
		break;
	case bonusLevelWarning:
		if (Localization == 1)
		{
			//
			printColorText(consoleHandle, "\n\t\t\t       ��� ��� ������i�����!", Yellow);
		}
		else if (Localization == 2)
		{
			//
			printColorText(consoleHandle, "\n\t\t\t\t  ��� ��� �������!", Yellow);
		}
		else if (Localization == 3)
		{
			//setlocale(LC_ALL, "�");
			printColorText(consoleHandle, "\n\t\t\t      Surprise, motherfucker!", Yellow);
		}
		warning = None;
		break;
	case secretDoorWarning:
		switch (Localization)
		{
		case 1:
		{
			//
			printColorText(consoleHandle,
				"\n\t\t     �� ������� ������ ���. �i���� ����������", Yellow); //41+21=62
			break;
		}
		case 2:
		{
			//
			printColorText(consoleHandle, "\n\t\t\t  ��! ��� ������ ������ �������?!", Yellow); //57
			break;
		}
		case 3:
		{
			//setlocale(LC_ALL, "C");
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
				//
				printColorText(consoleHandle, "\n\t\t\t  ��������! ��� ��������i ", Yellow);  // 25+33=58
				printColorText(consoleHandle, "������", Red);
				printColorText(consoleHandle, '!', Yellow);
				break;
			}
			case 2:
			{
				//
				printColorText(consoleHandle, "\n\t\t\t ���������! ����� ���������� ", Yellow); // 24+33=57
				printColorText(consoleHandle, "����", Red);
				printColorText(consoleHandle, '!', Yellow);
				break;
			}
			case 3:
			{
				//setlocale(LC_ALL, "C");
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
				printColorText(consoleHandle, "\n\t\t\t  �������� ", Yellow);
				printColorText(consoleHandle, "������", Red);
				printColorText(consoleHandle, '!', Yellow);
				printColorText(consoleHandle, " �� ����� ��� ", Yellow);
				if (warn == secretBombLeft) printColorText(consoleHandle, "��i��", Yellow);
				else if (warn == secretBombRight) printColorText(consoleHandle, "������", Yellow);
				break;
			}
			case 2:
			{
				printColorText(consoleHandle, "\n\t\t\t������� ", Yellow);
				printColorText(consoleHandle, "����", Red);
				printColorText(consoleHandle, '!', Yellow);
				printColorText(consoleHandle, " �� ������� ������� ", Yellow);
				if (warn == secretBombLeft) printColorText(consoleHandle, "�����", Yellow);
				else if (warn == secretBombRight) printColorText(consoleHandle, "������", Yellow);
				break; // 32-33
			}
			case 3:
			{
				//setlocale(LC_ALL, "C");
				printColorText(consoleHandle, "\n\t\t\t     Bomb", Red);
				printColorText(consoleHandle, " ahead! Don't go ", Yellow);
				if (warn == secretBombLeft) printColorText(consoleHandle, "left", Yellow);
				else if (warn == secretBombRight) printColorText(consoleHandle, "right", Yellow);
				break; // 34-35
			}
		}
		break;
	case secretBombDamn:
		switch (Localization)
		{
		case 1:
		{
			printColorText(consoleHandle, "\n\t\t\t\t�� ����� ���� �����!\t\t", Yellow);
			break;
		}
		case 2:
		{
			printColorText(consoleHandle, "\n\t\t\t\t    ׸�� ������!\t\t", Yellow); 
			break;
		}
		case 3:
		{
			//setlocale(LC_ALL, "C");
			printColorText(consoleHandle, "\n\t\t\t\t Damn! I warned you\t\t", Yellow);
			break;
		}
		}
		break;
	}

	warning = None; //Warnings reset
	setlocale(LC_ALL, "C");
}

void Description() 
{
	std::cout << std::endl;

	if (levelSelector != 1)
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
	else
	switch (Localization)
	{
		case 3:
		{
			//setlocale(LC_ALL, "Russian");
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
			printf("\n\n\t����������� ������� AWSD ����� ��������� ");
			SetConsoleTextAttribute(consoleHandle, 10);
			printf("������");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(".\n\t�������� ");
			SetConsoleTextAttribute(consoleHandle, 14);
			printf("�����");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("(");
			setlocale(LC_ALL, "C");
			SetConsoleTextAttribute(consoleHandle, 14);
			printf("%c", symbolBox);
			setlocale(LC_ALL, "Russian");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(") ����� ��������� �� ������(");
			setlocale(LC_ALL, "C");
			SetConsoleTextAttribute(consoleHandle, 12);
			printf("%c", symbolExit);
			setlocale(LC_ALL, "Russian");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(").");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("\n\tR - ������������� �������.");
			break;
		}
		case 1:
		{
			setlocale(LC_ALL, "Russian");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("\n\n\t���������� AWSD ��� �������� ");
			SetConsoleTextAttribute(consoleHandle, 10);
			printf("�������");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(". R - ��������� ��������.");
			printf("\n\t����� ");
			SetConsoleTextAttribute(consoleHandle, 14);
			printf("�����");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("(");
			setlocale(LC_ALL, "C");
			SetConsoleTextAttribute(consoleHandle, 14);
			printf("%c", symbolBox);
			setlocale(LC_ALL, "Russian");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(") ��� �i������� ������(");
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

void Counters()
{
	std::cout << "\n\t\t\t\t      "; // 34 to level render +4 = 38 spases
	if (CrystalCount != 0)
	{
		printColorText(consoleHandle, symbolCrystal, Magenta);
		std::cout << CrystalCount << ' ';
	}
	//else std::cout << "   "; //3
	if (KeyCount != 0)
	{
		printColorText(consoleHandle, symbolKey, LightMagenta);
		std::cout << KeyCount;
	}
	else std::cout << "       "; //7
}

void Statistic()
{
	using std::cout; using std::endl;

	//time_t diff_time = static_cast<time_t>(difftime(time(0), start_time));
	time_t diff_time = time(0) - start_time; // faster
	struct tm diff_tm;
	char time_buffer[10];
	gmtime_s(&diff_tm, &diff_time);
	strftime(time_buffer, 10, "%H:%M:%S", &diff_tm);

	size_t f_size = 3; // size of global values output

	// std::setw and cout.width works only with 1 next str link, right/left flags/manips works all time
	// cout.setf(std::ios::left) flag works only with cout.unsetf(std::ios::right)
	// but cout << std::left manip always work, and reset right manips/flags independently
	// right flags/manips always works

	if (global_Restarts == 0)
	{
		AchievesComplete.push_back(&NullRestartsAchieve_);
		NullRestartsAchieve_ = true;
	}

	//AchievesComplete.push_back(&AllCrystalsAchieve_);
	//AchievesComplete.push_back(&OnMyWayAchieve_);

	system("cls");
	switch (Localization)
	{
		case 3:
		{
			setlocale(LC_ALL, "C");
			printf("\n\t Well play. Press any key to exit...");
			break;
		}
		case 2:
		{
			setlocale(LC_ALL, "RUS");
			SetConsoleCursorPosition(consoleHandle, COORD{ 5, 1 }); // 30, 1
			cout << "���������� ������\t\t\t���������� (" 
				<< AchievesComplete.size() << '/' << a_AchievesMax << ')';

			cout.setf(std::ios::right); // default
			cout << "\n\n �������� �������\t" << std::setw(f_size) << global_Crystals;
			printColorText(consoleHandle, symbolCrystal, Magenta);

			cout << "\n\n ������ �������\t\t";
			cout.width(f_size);
			cout << global_Keys;
			printColorText(consoleHandle, symbolKey, LightMagenta);

			cout << "\n\n ��� ��������\t\t" << std::setw(f_size) << global_Bombs;
			printColorText(consoleHandle, symbolBomb, Red);

			cout << "\n\n �������� ��������\t" << std::setw(f_size) << global_Portals;
			printColorText(consoleHandle, symbolPortal, LightCyan);

			cout << "\n\n ������ ���������\t" << std::setw(f_size) << a_UniBoxMove;
			setlocale(LC_ALL, "C");
			printColorText(consoleHandle, symbolBox, Yellow);	// 254
			setlocale(LC_ALL, "Russian");
			cout << "\n\n ������ ��������� ���\t" << std::setw(f_size) << global_Boxes;

			cout << "\n\n ���������\t\t" << std::setw(f_size) << global_Restarts;
			cout << "\n\n\n ����� � ����\t" << std::setw(f_size + 8) << time_buffer << endl;
			cout << "\n\n";
			cout << " a_UniBombsDie\t" << std::setw(f_size) << a_UniBombsDie << endl;
			//cout << " a_UniBoxMove\t" << std::setw(f_size) << a_UniBoxMove << endl;

			/*cout << "&AllCrystalsAchieve_ before " << &AllCrystalsAchieve_ << endl;
			AllCrystalsAchieve_ = true;
			cout << "&AllCrystalsAchieve_ after  " << &AllCrystalsAchieve_ << endl;
			cout << "AllCrystalsAchieve_.id " << AllCrystalsAchieve_.id << endl;*/
			// Achieves output
			AchievesOutput(COORD{ 40, 3 });

			break;
		}
		case 1:
		{
			setlocale(LC_ALL, "Russian");
			printf("\n\t ������ �i�����, ��������� ��...");
			break;
		}
	}
}