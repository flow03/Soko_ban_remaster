#pragma once

enum Achieve_id
{
	AllAchieves = 0,		// Сбор всех достижений
	AllCrystalsAchieve,		// Собрать все кристаллы в игре
	lvl3_CrystalsAchieve,	// Собрать все кристаллы на уровне 3
	lvl3_RestartsAchieve,	// 10 рестартов подряд на уровне 3
	NullRestartsAchieve,	// 0 рестартов игры
	PovorotNeTydaAchieve,	// Поворот не туда(за нахождение секретной комнаты)
	OnMyWayAchieve,			// По своим следам
	AllMinesAchieve			// Взорваться на всех минах
};

struct Achieve
{
	bool value;
	Achieve_id id;
	const char * label;

	// Constructor + implicit conversion from Achieve_id to Achieve
	Achieve(Achieve_id id_, bool val = false)
		: id(id_), value(val) { setLabel(); }

	void setLabel();
	const char * getLabel() const { return label; }
	
	Achieve operator=(bool val) { this->value = val; return *this; } //{ return Achieve(this->id, val); }
	//Achieve operator=(Achieve_id val) { return Achieve(val); }
	//Achieve operator=(const char * lab) { this->label = lab; return *this; }
	operator bool() const { return value; }
	//operator Achieve_id() const { return id; }
};

// Achieve sub variables(with a_ prefix)
int a_UniBombsDie = 0;			// Смерть на новой бомбе
int a_UniBoxMove = 0;			// Разных ящиков подвигано
int a_lvl3Restarts = 0;			// Рестарты уровня 3 до сбора сердечек
//int a_AchievesCount = 0;		// Разблокировано достижений
const size_t a_AchievesMax = 8;	// Достижений всего

// Achievements
Achieve AllAchieves_(AllAchieves);
Achieve AllCrystalsAchieve_(AllCrystalsAchieve);
Achieve lvl3_CrystalsAchieve_(lvl3_CrystalsAchieve);	// +
Achieve lvl3_RestartsAchieve_(lvl3_RestartsAchieve);	// +
Achieve NullRestartsAchieve_(NullRestartsAchieve);		// +
Achieve PovorotNeTydaAchieve_(PovorotNeTydaAchieve);
Achieve OnMyWayAchieve_(OnMyWayAchieve);
Achieve AllMinesAchieve_(AllMinesAchieve);

Achieve* AchievesComplete[a_AchievesMax] = {
	
	&AllCrystalsAchieve_, 
	&lvl3_CrystalsAchieve_,
	&lvl3_RestartsAchieve_,
	&NullRestartsAchieve_,
	&PovorotNeTydaAchieve_,
	&OnMyWayAchieve_,
	&AllMinesAchieve_,
	&AllAchieves_
};


void Achieve::setLabel()
{
	if (Localization == 2)
		switch (id)
		{
		case AllCrystalsAchieve:
			label = "Собрать все кристаллы в игре"; break;
		case lvl3_CrystalsAchieve:
			label = "Собрать все кристаллы на уровне 3"; break;
		case lvl3_RestartsAchieve:
			label = "10 рестартов подряд на уровне 3"; break;
		case NullRestartsAchieve:
			label = "0 рестартов игры"; break;
		case PovorotNeTydaAchieve:
			label = "Поворот не туда"; break;
		case OnMyWayAchieve:
			label = "По своим следам"; break;
		case AllMinesAchieve:
			label = "Взорваться на всех минах"; break;

		case AllAchieves:
			label = "ВСЕ ДОСТИЖЕНИЯ ОТКРЫТЫ"; break;
		}
}

void changeLabels()
{
	/*for (Achieve* ach : Achieves)
		ach->setLabel();*/
	/*for(size_t i = 0; i < a_AchievesMax; ++i)
		Achieves[i]->setLabel();*/
	for (Achieve* ach : AchievesComplete)
		ach->setLabel();
}

void AchievesOutput(COORD coord)
{
	for (Achieve* ach : AchievesComplete)
	{
		if (ach->value)
		{
			SetConsoleCursorPosition(consoleHandle, coord);
			printColorText(consoleHandle, ach->getLabel(), Yellow);
			coord.Y += 2;
		}
	}
}

size_t AchievesSize()
{
	size_t size = 0;
	for (Achieve* ach : AchievesComplete)
		if (ach->value) ++size;

	return size;
}