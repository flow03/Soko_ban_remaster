#pragma once

struct Achieve
{
	bool value;
	unsigned char id;
	//const char * label;
	

	explicit Achieve(bool val, unsigned char id_) 
		: value(val), id(id_) {}

	const char * getLabel() const;

	Achieve operator=(bool val) { this->value = val; return *this; }
	//Achieve operator=(const char * lab) { this->label = lab; return *this; }
};

// Achieve sub variables(with a_ prefix)
int a_UniBombsDie = 0;			// Смерть на новой бомбе
int a_UniBoxMove = 0;			// Разных ящиков подвигано
int a_AchievesCount = 0;		// Разблокировано достижений
int a_AchievesMax = 10;			// Достижений всего

// Achievements
Achieve AllCrystalsAchieve	( true, 1 );	// Собрать все кристаллы в игре
Achieve lvl3_CrystalsAchieve	{ true, 2 };	// Собрать все кристаллы на уровне 3
Achieve TenRestartsAchieve	{ true, 3 };	// 10 рестартов подряд на уровне 3
Achieve NullRestartsAchieve	{ true, 4 };	// 0 рестартов игры
Achieve PovorotNeTydaAchieve	{ true, 5 };	// Поворот не туда(за нахождение секретной комнаты)
Achieve OnMyWayAchieve		{ true, 6 };	// По своим следам
Achieve AllMinesAchieve		{ true, 7 };	// Взорваться на всех минах

Achieve AllAchieves			{ true, 0 };	// Сбор всех достижений


const char * Achieve::getLabel() const
{
	const char * label;

	if (Localization == 2)
		switch (id)
		{
		case 1:
			label = "Собрать все кристаллы в игре"; break;
		case 2:
			label = "Собрать все кристаллы на уровне 3"; break;
		case 3:
			label = "10 рестартов подряд на уровне 3"; break;
		case 4:
			label = "0 рестартов игры"; break;
		case 5:
			label = "Поворот не туда"; break;
		case 6:
			label = "По своим следам"; break;
		case 7:
			label = "Взорваться на всех минах"; break;

		case 0:
			label = "ВСЕ ДОСТИЖЕНИЯ ОТКРЫТЫ"; break;
		}

	return label;
}

void AchieveOutput(short x, short y)
{
	y = 40;
	x = 3;

	auto funcOut = [x, y](const Achieve &A) {

		if (A.value)
		{
			SetConsoleCursorPosition(consoleHandle, COORD{ y, x });
			printColorText(consoleHandle, A.getLabel(), Yellow);
			x += 2;
		}
	};

	if (AllMinesAchieve.value)
	{
		SetConsoleCursorPosition(consoleHandle, COORD{ y, x });
		printColorText(consoleHandle, AllMinesAchieve.getLabel(), Yellow);
		x += 2;
	}
	if (lvl3_CrystalsAchieve.value)
	{
		SetConsoleCursorPosition(consoleHandle, COORD{ y, x });
		printColorText(consoleHandle, lvl3_CrystalsAchieve.getLabel(), Yellow);
		x += 2;
	}

}