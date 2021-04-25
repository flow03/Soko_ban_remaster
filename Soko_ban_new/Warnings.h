#pragma once

enum Warning
{
	None,
	keyWarning,
	crystalWarning,
	bombWarning,
	bonusWallWarning,
	bonusLevelWarning,
	portalWarning,
	secretDoorWarning,
	secretBombsWarning,
	secretBombLeft,
	secretBombRight,
	secretBombDamn = 100,	// set enum range
};

void Warnings(short &x_position) {

	// new warning clear
	SetConsoleCursorPosition(consoleHandle, COORD{ 0, x_position });
	std::cout << std::setw(80) << std::right << "";		// don't work properly without empty str
	SetConsoleCursorPosition(consoleHandle, COORD{ 0, x_position });

	if (!warning.empty())
	{
		Warning warn = warning.front();
		const char * str = nullptr;
		short y = 0;

		setlocale(LC_ALL, "Russian");
		
		switch (warn)
		{
		case None:
			//std::cout << "\t\t\t\t\t\t\t\t"; // 64
			break;
		case keyWarning:
			switch (Localization)
			{
			case 1:
			{
				printColorText(consoleHandle, "\t\t\t    I ���� �� ��� ", Yellow);
				printColorText(consoleHandle, "�����", LightMagenta);
				printColorText(consoleHandle, " �i��� ? ", Yellow);
				break;
			}
			case 2:
			{
				printColorText(consoleHandle, "\t\t\t\t    ����� ", Yellow);
				printColorText(consoleHandle, "����     ", LightMagenta);
				break;
			}
			case 3:
			{
				//setlocale(LC_ALL, "C");
				printColorText(consoleHandle, "\t\t\t\t  Need some ", Yellow);
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
				printColorText(consoleHandle, "\t\t\t   ���� �i������? � �� ", Yellow);
				printColorText(consoleHandle, symbolCrystal, Magenta);
				printColorText(consoleHandle, " ������!", Yellow);
				break;
			}
			case 2:
			{
				//
				printColorText(consoleHandle, "\t\t\t\t  ����� ������ ", Yellow);
				printColorText(consoleHandle, symbolCrystal, Magenta);
				break;
			}
			case 3:
			{
				//setlocale(LC_ALL, "C");
				printColorText(consoleHandle, "\t\t\t\t  Collect more ", Yellow);
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
				printColorText(consoleHandle, "\t\t\t     � � ����� �� �i��� � ", Yellow);
				printColorText(consoleHandle, "���", Red);
				printColorText(consoleHandle, "!", Yellow);
				break;
			}
			case 2:
			{
				//
				printColorText(consoleHandle, "\t\t\t\t    ���������", Yellow);
				break;
			}
			case 3:
			{
				//setlocale(LC_ALL, "C");
				printColorText(consoleHandle, "\t\t\t       Oops! You just died", Yellow);
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
				printColorText(consoleHandle, "\t\t\t\t��i�� � ���������", Yellow);
				break;
			}
			case 2:
			{
				//
				printColorText(consoleHandle, "\t\t\t\t     �������", Yellow);
				break;
			}
			case 3:
			{
				//setlocale(LC_ALL, "C");
				printColorText(consoleHandle, "\t\t\t\t     Surprise", Yellow);
				break;
			}
			}
			break;
		case bonusLevelWarning:
			if (Localization == 1)
			{
				//
				printColorText(consoleHandle, "\t\t\t       ��� ��� ������i�����!", Yellow);
			}
			else if (Localization == 2)
			{
				printColorText(consoleHandle, "\t\t\t\t  ��� ��� �������!", Yellow);
			}
			else if (Localization == 3)
			{
				//setlocale(LC_ALL, "�");
				printColorText(consoleHandle, "\t\t\t      Surprise, motherfucker!", Yellow);
			}
			//warning = None;	// ???
			break;
		case secretDoorWarning:
			switch (Localization)
			{
			case 1:
			{
				//
				printColorText(consoleHandle,
					"\t\t     �� ������� ������ ���. �i���� ����������", Yellow); //41+21=62
				break;
			}
			case 2:
			{
				//
				printColorText(consoleHandle, "\t\t\t  ��! ��� ������ ������ �������?!", Yellow); //57
				break;
			}
			case 3:
			{
				//setlocale(LC_ALL, "C");
				printColorText(consoleHandle, "\t\t\t  Hey! You found the secret door!", Yellow); //57
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
				printColorText(consoleHandle, "\t\t\t  ��������! ��� ��������i ", Yellow);  // 25+33=58
				printColorText(consoleHandle, "������", Red);
				printColorText(consoleHandle, '!', Yellow);
				break;
			}
			case 2:
			{
				//
				printColorText(consoleHandle, "\t\t\t ���������! ����� ���������� ", Yellow); // 24+33=57
				printColorText(consoleHandle, "����", Red);
				printColorText(consoleHandle, '!', Yellow);
				break;
			}
			case 3:
			{
				//setlocale(LC_ALL, "C");
				printColorText(consoleHandle, "\t\t\t Carreful! There are hidden ", Yellow); // 25+33=58
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
				printColorText(consoleHandle, "\t\t\t  �������� ", Yellow);
				printColorText(consoleHandle, "������", Red);
				printColorText(consoleHandle, '!', Yellow);
				printColorText(consoleHandle, " �� ����� ��� ", Yellow);
				if (warn == secretBombLeft) printColorText(consoleHandle, "��i��", Yellow);
				else if (warn == secretBombRight) printColorText(consoleHandle, "������", Yellow);
				break;
			}
			case 2:
			{
				printColorText(consoleHandle, "\t\t\t������� ", Yellow);
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
				printColorText(consoleHandle, "\t\t\t     Bomb", Red);
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
				printColorText(consoleHandle, "\t\t\t\t�� ����� ���� �����!", Yellow);
				break;
			}
			case 2:
			{
				printColorText(consoleHandle, "\t\t\t\t    ׸�� ������!", Yellow); 
				break;
			}
			case 3:
			{
				//setlocale(LC_ALL, "C");
				printColorText(consoleHandle, "\t\t\t\t Damn! I warned you", Yellow);
				break;
			}
			}
			break;
		case portalWarning:
			switch (Localization)
			{
			case 1:
				printColorText(consoleHandle, "\t\t\t       ���i ����� ���� �����?", Yellow);
				break;
			case 2:
				printColorText(consoleHandle, "\t\t\t\t      �� ����!", Yellow);
				break;
			case 3:
				printColorText(consoleHandle, "\t\t\t\t       DON'T!", Yellow);
				break;
			}
		break;

		// Ahievements
		case (Warning)lvl3_RestartsAchieve:
		case (Warning)lvl3_CrystalsAchieve:
		case (Warning)OnMyWayAchieve:
		case (Warning)AllAchievesAchieve:
			str = Achieve::getLabel(static_cast<Achieve_id>(warn));
			y = static_cast<short>(40 - (strlen(str) / 2) + 1);		// 40 - the middle of a line
			SetConsoleCursorPosition(consoleHandle, COORD{ y, x_position });

			printColorText(consoleHandle, str, Yellow);
			printColorText(consoleHandle, '!', Yellow);
			break;
		case (Warning)AllMinesAchieve:
			str = AllMinesAchieve_.getLabel();
			y = static_cast<short>(40 - (strlen(str) / 2 + 2) + 1);	// "(1/2)" = 5 symbols / 2 = 2.5
			SetConsoleCursorPosition(consoleHandle, COORD{ y, x_position });

			printColorText(consoleHandle, str, Yellow);
			printColorText(consoleHandle, '(', Yellow);
			if(AllMinesAchieve_)
				printColorText(consoleHandle, '2', Yellow);
			else
				printColorText(consoleHandle, '1', Yellow);

			printColorText(consoleHandle, "/2)", Yellow);
			break;
		}

		warning.pop();
	}

	//++x_position;
	//warning = None; //Warnings reset
	setlocale(LC_ALL, "C");
}

void Description()
{
	using std::cout;

	short x_position = 0;
	if (levelSelector == 1)
		x_position = 14;
	else if (levelSelector == 2) 
		x_position = 22;
	else if (levelSelector == 3 || levelSelector == 4)
		x_position = 17;

	SetConsoleCursorPosition(consoleHandle, COORD{ 0, x_position });

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
			std::cout << "\n   ���������� ";
			printColorText(consoleHandle, "������", LightGreen);
			std::cout << ". ��������� ";
			printColorText(consoleHandle, symbolCrystal, Magenta);
			std::cout << " � ";
			printColorText(consoleHandle, "�����", LightMagenta);
			std::cout << "(";
			printColorText(consoleHandle, symbolKey, LightMagenta);
			std::cout << ") ����� ��������. R - ����������.\n   ����������� ";
			printColorText(consoleHandle, "�������", LightCyan);
			std::cout << "(";
			printColorText(consoleHandle, 'O', LightCyan);
			std::cout << ") � ����� (";
			setlocale(LC_ALL, "C");
			std::cout << symbolDoorG << ", " << symbolDoorV;
			setlocale(LC_ALL, "Russian");
			std::cout << "). ������ ��������� � ";
			printColorText(consoleHandle, "������", Red);
			std::cout << "(";
			printColorText(consoleHandle, symbolBomb, Red);
			std::cout << "). �����";
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
			printColorText(consoleHandle,"Bombs", Red);
			printf("(");
			printColorText(consoleHandle, symbolBomb, Red);
			printf(").\n\tGood luck");
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
			printf("\n\n\tUse WASD to move your ");
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
			//SetConsoleCursorPosition(consoleHandle, COORD{ 3, 23 });
			setlocale(LC_ALL, "Russian");
			cout << "\n   ����������� ������� WASD ����� ��������� ";
			printColorText(consoleHandle, "������", LightGreen);
			cout << ". �������� ";
			printColorText(consoleHandle, "�����", Yellow);
			cout << "(";
			setlocale(LC_ALL, "C");
			printColorText(consoleHandle, symbolBox, Yellow);
			setlocale(LC_ALL, "Russian");
			cout << ") �����\n   ��������� �� ������(";
			setlocale(LC_ALL, "C");
			printColorText(consoleHandle, symbolExit, Red);
			setlocale(LC_ALL, "Russian");
			cout << "). R - ������������� �������.";
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

void Counters(short &x_position)
{
	if (levelSelector == 2) ++x_position;
	SetConsoleCursorPosition(consoleHandle, COORD{ 38, x_position });
	if (CrystalCount != 0 || CrystalMaxCount > 0)
	{
		printColorText(consoleHandle, symbolCrystal, Magenta);
		if (CrystalMaxCount == 0)
			std::cout << CrystalCount << ' ';
		else 
			std::cout << CrystalCount << '/' << CrystalMaxCount << ' ';
	}
	//else std::cout << "   "; //3
	if (KeyCount != 0)
	{
		printColorText(consoleHandle, symbolKey, LightMagenta);
		std::cout << KeyCount;
	}
	else std::cout << "          "; //10

	++x_position;	// set x on the next row
}

void Statistic()
{
	using std::cout; using std::endl;

	// time stuff
	//time_t total_time = static_cast<time_t>(difftime(time(0), start_time));
	total_time = time(0) - start_time; // faster

	struct tm diff_tm;
	gmtime_s(&diff_tm, &total_time);

	char time_buffer[10];
	strftime(time_buffer, 10, "%H:%M:%S", &diff_tm);

	size_t f_size = 3; // size of global values output

	// std::setw and cout.width works only with 1 next str link, right/left flags/manips works all time
	// cout.setf(std::ios::left) flag works only with cout.unsetf(std::ios::right)
	// but cout << std::left manip always work, and reset right manips/flags independently
	// right flags/manips always works

	if (global_Restarts == 0)
		NullRestartsAchieve_ = true;
	else NullRestartsAchieve_ = false;

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
			SetConsoleCursorPosition(consoleHandle, COORD{ 6, 1 }); // 30, 1
			cout << "���������� ������\t\t\t���������� (" 
				<< AchievesCount() << '/' << a_AchievesMax << ')';

			cout.setf(std::ios::right); // default
			cout << "\n\n\n �������� �������\t" << std::setw(f_size) << global_Crystals;
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

			/*cout << "&AllCrystalsAchieve_ before " << &AllCrystalsAchieve_ << endl;
			AllCrystalsAchieve_ = true;
			cout << "&AllCrystalsAchieve_ after  " << &AllCrystalsAchieve_ << endl;
			cout << "AllCrystalsAchieve_.id " << AllCrystalsAchieve_.id << endl;*/
			//cout << AllMinesAchieve_.getLabel() << endl;
			//cout << (int *)"asdasd" << ' ' << (int *)"sdasd" << endl;
			// Achieves output
			AchievesOutput(COORD{ 40, 4 });

			

			break;
		}
		case 1:
		{
			setlocale(LC_ALL, "Russian");
			printf("\n\t ������ �i�����, ��������� ��...");
			break;
		}
	}

	_getch();

	system("cls");
}