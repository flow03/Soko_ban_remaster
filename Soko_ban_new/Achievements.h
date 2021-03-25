#pragma once

struct Ahieve
{
	bool value;
	unsigned char id;
	const char * label;
	

	explicit Ahieve(bool val, unsigned char id_) 
		: value(val), id(id_) {}

	const char * getLabel()
	{
		if (Localization == 2)
			switch (id)
			{
			case 0:
				label = "Взорваться на всех минах"; break;
			case 1:
				label = "Собрать все кристаллы в игре"; break;
			case 2:
				label = "Собрать все кристаллы на уровне 3"; break;
			case 3:
				label = "10 рестартов подряд на уровне 3"; break;
			}

		return label;
	}


	Ahieve operator=(bool val) { this->value = val; return *this; }
	Ahieve operator=(const char * lab) { this->label = lab; return *this; }
};

// Achieve sub variables(with a_ prefix)
int a_UniBombsDie = 0;			// Смерть на новой бомбе
int a_UniBoxMove = 0;			// Разных ящиков подвигано
int a_AchievesCount = 0;		// Разблокировано достижений
int a_AchievesMax = 10;			// Достижений всего

// Achievements
Ahieve AllMinesAchieve		( true, 0 );	// Взорваться на всех минах
Ahieve AllCrystalsAchieve	( true, 1 );	// Собрать все кристаллы в игре
Ahieve lvl3_CrystalsAchieve	{ true, 2 };	// Собрать все кристаллы на уровне 3
Ahieve TenRestartsAchieve	{ true, 3 };	// 10 рестартов подряд на уровне 3
//bool NullRestartsAchieve = false;			// 0 рестартов игры
//bool PovorotNeTydaAchieve = false;		// Поворот не туда(за нахождение секретной комнаты)
//bool OnMyWayAchieve = false;			// По своим следам
//
//bool AllAchieves = false;				// Сбор всех достижений