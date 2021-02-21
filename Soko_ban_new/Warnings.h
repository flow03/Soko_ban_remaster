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
			printColorText(consoleHandle, "\n\t\t\t    I куди ти без ", Yellow);
			printColorText(consoleHandle, "Ключа", LightMagenta);
			printColorText(consoleHandle, " лiзеш ? ", Yellow);
			break;
		}
		case 2:
		{
			/*if (levelSelector == 3 || levelSelector == 4)
				printf(" ");*/
			printColorText(consoleHandle, "\n\t\t\t\t    Нужен ", Yellow);
			printColorText(consoleHandle, "Ключ     ", LightMagenta);
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
			printColorText(consoleHandle, "\n\t\t\t   Куди зiбрався? А ну ", Yellow);
			printColorText(consoleHandle, symbolCrystal, Magenta);
			printColorText(consoleHandle, " збирай!", Yellow);
			break;
		}
		case 2:
		{
			//
			printColorText(consoleHandle, "\n\t\t\t\t  Нужно больше ", Yellow);
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
			printColorText(consoleHandle, "\n\t\t\t     Я ж казав не лiзти в ", Yellow);
			printColorText(consoleHandle, "Яму", Red);
			printColorText(consoleHandle, "!", Yellow);
			break;
		}
		case 2:
		{
			//
			printColorText(consoleHandle, "\n\t\t\t\t    ПОТРАЧЕНО", Yellow);
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
			printColorText(consoleHandle, "\n\t\t\t\tСтiна в подарунок", Yellow);
			break;
		}
		case 2:
		{
			//
			printColorText(consoleHandle, "\n\t\t\t\t     Сюрприз", Yellow);
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
			printColorText(consoleHandle, "\n\t\t\t       Оце так несподiванка!", Yellow);
		}
		else if (Localization == 2)
		{
			//
			printColorText(consoleHandle, "\n\t\t\t\t  Вот это поворот!", Yellow);
		}
		else if (Localization == 3)
		{
			//setlocale(LC_ALL, "С");
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
				"\n\t\t     Ти знайшов таємний лаз. Нiчого особливого", Yellow); //41+21=62
			break;
		}
		case 2:
		{
			//
			printColorText(consoleHandle, "\n\t\t\t  Эй! Кто открыл тайную комнату?!", Yellow); //57
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
				printColorText(consoleHandle, "\n\t\t\t  Обережно! Тут прихованi ", Yellow);  // 25+33=58
				printColorText(consoleHandle, "пастки", Red);
				printColorText(consoleHandle, '!', Yellow);
				break;
			}
			case 2:
			{
				//
				printColorText(consoleHandle, "\n\t\t\t Осторожно! Здесь припрятаны ", Yellow); // 24+33=57
				printColorText(consoleHandle, "мины", Red);
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
				//
				printColorText(consoleHandle, "\n\t\t\t  Попереду ", Yellow); 
				printColorText(consoleHandle, "пастка", Red);
				printColorText(consoleHandle, '!', Yellow);
				printColorText(consoleHandle, " Не раджу йти ", Yellow);
				if (warn == secretBombLeft) printColorText(consoleHandle, "влiво", Yellow);
				if (warn == secretBombRight) printColorText(consoleHandle, "вправо", Yellow);
				break;
			}
			case 2:
			{
				//
				printColorText(consoleHandle, "\n\t\t\tВпереди ", Yellow); 
				printColorText(consoleHandle, "мина", Red);
				printColorText(consoleHandle, '!', Yellow);
				printColorText(consoleHandle, " Не советую ступать ", Yellow);
				if (warn == secretBombLeft) printColorText(consoleHandle, "влево", Yellow);
				if (warn == secretBombRight) printColorText(consoleHandle, "вправо", Yellow);
				break;
			}
			case 3:
			{
				//setlocale(LC_ALL, "C");
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
			//
			printColorText(consoleHandle, "\n\t\t\t\tТа нехай йому грець!", Yellow);
			break;
		}
		case 2:
		{
			//
			printColorText(consoleHandle, "\n\t\t\t\t    Чёрт побери!", Yellow);
			break;
		}
		case 3:
		{
			//setlocale(LC_ALL, "C");
			printColorText(consoleHandle, "\n\t\t\t\t Damn! I warned you", Yellow);
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
			std::cout << "\n   Керуй ";
			printColorText(consoleHandle, "Козаком", LightGreen);
			std::cout << ". Збирай ";
			printColorText(consoleHandle, symbolCrystal, Magenta);
			std::cout << " i ";
			printColorText(consoleHandle, "Ключi", LightMagenta);
			std::cout << '(';
			printColorText(consoleHandle, symbolKey, LightMagenta);
			std::cout << ") щоб виграти. R - розпочати спочатку.\n   Використовуй ";
			printColorText(consoleHandle, "Таємнi тунелi", LightCyan);
			std::cout << '(';
			printColorText(consoleHandle, 'O', LightCyan);
			std::cout << ") i Пункти пропуску (";
			setlocale(LC_ALL, "C");
			std::cout << symbolDoorG << ", " << symbolDoorV;
			setlocale(LC_ALL, "Russian");
			std::cout << "). Не втрапляй у ";
			printColorText(consoleHandle, "Ями", Red);
			std::cout << '(';
			printColorText(consoleHandle, symbolBomb, Red);
			std::cout << ").";
			break;
		}
		case 2: //RU
		{
			setlocale(LC_ALL, "Russian");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("\n   Управляйте ");
			SetConsoleTextAttribute(consoleHandle, 10);
			printf("Героем");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(". Собирайте ");
			SetConsoleTextAttribute(consoleHandle, 5);
			printf("%c", symbolCrystal);
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(" и ");
			SetConsoleTextAttribute(consoleHandle, 13);
			printf("Ключи");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("(");
			SetConsoleTextAttribute(consoleHandle, 13);
			printf("%c", symbolKey);
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(") чтобы выиграть. R - Перезапуск.");
			printf("\n   Используйте ");
			SetConsoleTextAttribute(consoleHandle, 11);
			printf("Порталы");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("(");
			SetConsoleTextAttribute(consoleHandle, 11);
			printf("O");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(") и Двери (");
			setlocale(LC_ALL, "C");
			printf("%c, %c", symbolDoorG, symbolDoorV);
			setlocale(LC_ALL, "Russian");
			printf("). Будьте осторожны с ");
			SetConsoleTextAttribute(consoleHandle, Red);
			printf("Минами");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("(");
			SetConsoleTextAttribute(consoleHandle, Red);
			printf("%c", symbolBomb);
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("). Удачи");
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
			printf("\n\n\tИспользуйте клавиши AWSD чтобы управлять ");
			SetConsoleTextAttribute(consoleHandle, 10);
			printf("Героем");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(".\n\tДвигайте ");
			SetConsoleTextAttribute(consoleHandle, 14);
			printf("Ящики");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("(");
			setlocale(LC_ALL, "C");
			SetConsoleTextAttribute(consoleHandle, 14);
			printf("%c", symbolBox);
			setlocale(LC_ALL, "Russian");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(") чтобы добраться до Выхода(");
			setlocale(LC_ALL, "C");
			SetConsoleTextAttribute(consoleHandle, 12);
			printf("%c", symbolExit);
			setlocale(LC_ALL, "Russian");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(").");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("\n\tR - перезапустить уровень.");
			break;
		}
		case 1:
		{
			setlocale(LC_ALL, "Russian");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("\n\n\tКористуйся AWSD щоб керувати ");
			SetConsoleTextAttribute(consoleHandle, 10);
			printf("Козаком");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(". R - розпочати спочатку.");
			printf("\n\tРухай ");
			SetConsoleTextAttribute(consoleHandle, 14);
			printf("Снопи");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf("(");
			setlocale(LC_ALL, "C");
			SetConsoleTextAttribute(consoleHandle, 14);
			printf("%c", symbolBox);
			setlocale(LC_ALL, "Russian");
			SetConsoleTextAttribute(consoleHandle, 7);
			printf(") щоб дiстатись Виходу(");
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
	else std::cout << "   ";
	if (KeyCount != 0)
	{
		printColorText(consoleHandle, symbolKey, LightMagenta);
		std::cout << KeyCount;
	}
	else std::cout << "   ";
}