#pragma once
//int Localization;
//HANDLE consoleHandle;

enum Warning
{
	None,
	keyWarning,		//warning1
	crystalWarning,	//warning2
	bombWarning,   //bombSelector
	/*bonusWallSelector,
	bonusWallWarning,
	secretDoorSelector,
	secretDoorWarning,
	secretBombsWarning,
	bonusLevelWarning*/
};

void Warnings1(Warning warn) {

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


		//	else
		//	{
		//		if (bombSelector == true)
		//		{
		//			switch (Localization)
		//			{
		//			case 1:
		//			{
		//				setlocale(LC_ALL, "Russian");
		//				SetConsoleTextAttribute(consoleHandle, 14);
		//				printf("\n\t\t\t     � � ����� �� �i��� � ");
		//				SetConsoleTextAttribute(consoleHandle, 12);
		//				printf("���");
		//				SetConsoleTextAttribute(consoleHandle, 14);
		//				printf("!");
		//				break;
		//			}
		//			case 2:
		//			{
		//				setlocale(LC_ALL, "Russian");
		//				SetConsoleTextAttribute(consoleHandle, 14);
		//				printf("\n\t\t\t\t");
		//				if (levelSelector == 4)
		//					printf(" ");
		//				printf("    ���������");
		//				break;
		//			}
		//			case 3:
		//			{
		//				setlocale(LC_ALL, "C");
		//				SetConsoleTextAttribute(consoleHandle, 14);
		//				printf("\n\t\t\t       Oops! You just died");
		//				break;
		//			}
		//			}

		//			_getch();
		//			LevelClear();
		//			if (levelSelector == 2)
		//				Initialise2(rowsCount2, columnsCount2);
		//			if (levelSelector == 3)
		//				Initialise2(rowsCount3, columnsCount3);
		//			if (levelSelector == 4)
		//			{
		//				levelSelector = 3;
		//				Initialise2(rowsCount3, columnsCount3);
		//			}
		//		}
		//		else
		//			if (bonusWallWarning == true)
		//			{
		//				switch (Localization)
		//				{
		//				case 1:
		//				{
		//					setlocale(LC_ALL, "Russian");
		//					SetConsoleTextAttribute(consoleHandle, 14);
		//					printf("\n\t\t\t\t��i�� � ���������");
		//					break;
		//				}
		//				case 2:
		//				{
		//					setlocale(LC_ALL, "Russian");
		//					SetConsoleTextAttribute(consoleHandle, 14);
		//					printf("\n\t\t\t\t     �������");
		//					break;
		//				}
		//				case 3:
		//				{
		//					setlocale(LC_ALL, "C");
		//					SetConsoleTextAttribute(consoleHandle, 14);
		//					printf("\n\t\t\t\t     Surprise");
		//					break;
		//				}
		//				}

		//				if (levelData[16][6] == symbolKey)
		//				{
		//					bonusWallWarning = false;
		//				}
		//			}
		//			else
		//				if (bonusLevelWarning == true)
		//				{
		//					switch (Localization)
		//					{
		//					case 1:
		//					{
		//						setlocale(LC_ALL, "Russian");
		//						SetConsoleTextAttribute(consoleHandle, 14);
		//						printf("\n\t\t\t       ��� ��� ������i�����!");
		//						break;
		//					}
		//					case 2:
		//					{
		//						setlocale(LC_ALL, "Russian");
		//						SetConsoleTextAttribute(consoleHandle, 14);
		//						printf("\n\t\t\t\t  ��� ��� �������!");
		//						break;
		//					}
		//					case 3:
		//					{
		//						setlocale(LC_ALL, "�");
		//						SetConsoleTextAttribute(consoleHandle, 14);
		//						printf("\n\t\t\t      Surprise, motherfucker!");
		//						break;
		//					}
		//					}
		//					bonusLevelWarning = false;
		//				}
		//				else
		//					if (secretDoorWarning == true)
		//					{
		//						switch (Localization)
		//						{
		//						case 1:
		//						{
		//							setlocale(LC_ALL, "Russian");
		//							SetConsoleTextAttribute(consoleHandle, 14);
		//							printf("\n\t\t     �� ������� ������ ���. �i���� ����������"); //41+21=62
		//							break;
		//						}
		//						case 2:
		//						{
		//							setlocale(LC_ALL, "Russian");
		//							SetConsoleTextAttribute(consoleHandle, 14);
		//							printf("\n\t\t\t  ��! ��� ������ ������ �������?!"); //57
		//							break;
		//						}
		//						case 3:
		//						{
		//							setlocale(LC_ALL, "C");
		//							SetConsoleTextAttribute(consoleHandle, 14);
		//							printf("\n\t\t\t  Hey! You found the secret door!"); //57
		//							break;
		//						}
		//						}

		//						secretDoorWarning = false;
		//					}
		//					else
		//						if (secretBombsWarning == true)
		//						{
		//							switch (Localization)
		//							{
		//							case 1:
		//							{
		//								setlocale(LC_ALL, "Russian");
		//								SetConsoleTextAttribute(consoleHandle, 14);
		//								printf("\n\t\t\t  ��������! ��� ��������i ");  // 25+33=58
		//								SetConsoleTextAttribute(consoleHandle, 12);
		//								printf("������");
		//								SetConsoleTextAttribute(consoleHandle, 14);
		//								printf("!");
		//								break;
		//							}
		//							case 2:
		//							{
		//								setlocale(LC_ALL, "Russian");
		//								SetConsoleTextAttribute(consoleHandle, 14);
		//								printf("\n\t\t\t ���������! ����� ���������� ");  // 24+33=57
		//								SetConsoleTextAttribute(consoleHandle, 12);
		//								printf("����");
		//								SetConsoleTextAttribute(consoleHandle, 14);
		//								printf("!");
		//								break;
		//							}
		//							case 3:
		//							{
		//								setlocale(LC_ALL, "C");
		//								SetConsoleTextAttribute(consoleHandle, 14);
		//								printf("\n\t\t\t Carreful! There are hidden ");  // 25+33=58
		//								SetConsoleTextAttribute(consoleHandle, 12);
		//								printf("mines");
		//								SetConsoleTextAttribute(consoleHandle, 14);
		//								printf("!");
		//								break;
		//							}
		//							}

		//							secretBombsWarning = false;
		//						}
		//						else
		//							printf("\n\t\t\t\t\t\t\t\t"); // 64
		//	}
		//}
		//if (bombSelector == false)
		//{
		//	switch (Localization)
		//	{
		//	case 1:
		//	{
		//		setlocale(LC_ALL, "Russian");
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf("\n   ����� ");
		//		SetConsoleTextAttribute(consoleHandle, 10);
		//		printf("�������");
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf(". ������ ");
		//		SetConsoleTextAttribute(consoleHandle, 5);
		//		printf("%c", symbolCrystal);
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf(" i ");
		//		SetConsoleTextAttribute(consoleHandle, 13);
		//		printf("����i");
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf("(");
		//		SetConsoleTextAttribute(consoleHandle, 13);
		//		printf("%c", symbolKey);
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf(") ��� �������. R - ��������� ��������.");
		//		printf("\n   ������������ ");
		//		SetConsoleTextAttribute(consoleHandle, 11);
		//		printf("����i �����i");
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf("(");
		//		SetConsoleTextAttribute(consoleHandle, 11);
		//		printf("O");
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf(") i ������ �������� (");
		//		setlocale(LC_ALL, "C");
		//		printf("%c, %c", symbolDoorG, symbolDoorV);
		//		setlocale(LC_ALL, "Russian");
		//		printf("). �� �������� � ");
		//		SetConsoleTextAttribute(consoleHandle, 12);
		//		printf("���");
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf("(");
		//		SetConsoleTextAttribute(consoleHandle, 12);
		//		printf("%c", symbolBomb);
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf(").");
		//		break;
		//	}
		//	case 2:
		//	{
		//		setlocale(LC_ALL, "Russian");
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf("\n   ���������� ");
		//		SetConsoleTextAttribute(consoleHandle, 10);
		//		printf("������");
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf(". ��������� ");
		//		SetConsoleTextAttribute(consoleHandle, 5);
		//		printf("%c", symbolCrystal);
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf(" � ");
		//		SetConsoleTextAttribute(consoleHandle, 13);
		//		printf("�����");
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf("(");
		//		SetConsoleTextAttribute(consoleHandle, 13);
		//		printf("%c", symbolKey);
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf(") ����� ��������. R - ����������.");
		//		printf("\n   ����������� ");
		//		SetConsoleTextAttribute(consoleHandle, 11);
		//		printf("�������");
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf("(");
		//		SetConsoleTextAttribute(consoleHandle, 11);
		//		printf("O");
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf(") � ����� (");
		//		setlocale(LC_ALL, "C");
		//		printf("%c, %c", symbolDoorG, symbolDoorV);
		//		setlocale(LC_ALL, "Russian");
		//		printf("). ������ ��������� � ");
		//		SetConsoleTextAttribute(consoleHandle, 12);
		//		printf("������");
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf("(");
		//		SetConsoleTextAttribute(consoleHandle, 12);
		//		printf("%c", symbolBomb);
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf("). �����");
		//		break;
		//	}
		//	case 3:
		//	{
		//		setlocale(LC_ALL, "C");
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf("\n\tMove your ");
		//		SetConsoleTextAttribute(consoleHandle, 10);
		//		printf("Hero");
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf(". Collect ");
		//		SetConsoleTextAttribute(consoleHandle, 5);
		//		printf("%c", symbolCrystal);
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf(" and ");
		//		SetConsoleTextAttribute(consoleHandle, 13);
		//		printf("Keys");
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf("(");
		//		SetConsoleTextAttribute(consoleHandle, 13);
		//		printf("%c", symbolKey);
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf(") to win. R - Restart level.");
		//		printf("\n\tUse the ");
		//		SetConsoleTextAttribute(consoleHandle, 11);
		//		printf("Portals");
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf("(");
		//		SetConsoleTextAttribute(consoleHandle, 11);
		//		printf("O");
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf(") and the Doors (%c, %c). Carreful with ", symbolDoorG, symbolDoorV);
		//		SetConsoleTextAttribute(consoleHandle, 12);
		//		printf("Mines");
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf("(");
		//		SetConsoleTextAttribute(consoleHandle, 12);
		//		printf("%c", symbolBomb);
		//		SetConsoleTextAttribute(consoleHandle, 7);
		//		printf("). Gl hf");
		//		break;
		//	}
		//	}

		//}
		//else
		//{
		//	bombSelector = false;
		//	if (levelSelector == 2)
		//		Render2(rowsCount2, columnsCount2);
		//	if (levelSelector == 3)
		//		Render2(rowsCount3, columnsCount);
		//}

		
	
	setlocale(LC_ALL, "C");
}