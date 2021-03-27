#pragma once

enum Achieve_id
{
	AllAchieves = 0,		// Сбор всех достижений
	AllCrystalsAchieve,		// Собрать все кристаллы в игре
	lvl3_CrystalsAchieve,	// Собрать все кристаллы на уровне 3
	TenRestartsAchieve,		// 10 рестартов подряд на уровне 3
	NullRestartsAchieve,	// 0 рестартов игры
	PovorotNeTydaAchieve,	// Поворот не туда(за нахождение секретной комнаты)
	OnMyWayAchieve,			// По своим следам
	AllMinesAchieve			// Взорваться на всех минах
};

struct Achieve
{
	Achieve_id id;
	const char * label;

	// Constructor + implicit conversion from Achieve_id to Achieve
	Achieve(Achieve_id id_) : id(id_) { setLabel(); }

	void setLabel();
	const char * getLabel() const { return label; }
	
	Achieve operator=(Achieve_id val) { return Achieve(val); }
	//operator Achieve_id() const { return id; }
	//Achieve operator=(const char * lab) { this->label = lab; return *this; }
};


// Achievements
std::vector<Achieve> AchievesComplete;

// Achieve sub variables(with a_ prefix)
int a_UniBombsDie = 0;			// Смерть на новой бомбе
int a_UniBoxMove = 0;			// Разных ящиков подвигано
//int a_AchievesCount = 0;		// Разблокировано достижений
int a_AchievesMax = 8;			// Достижений всего


void Achieve::setLabel()
{
	if (Localization == 2)
		switch (id)
		{
		case AllCrystalsAchieve:
			label = "Собрать все кристаллы в игре"; break;
		case lvl3_CrystalsAchieve:
			label = "Собрать все кристаллы на уровне 3"; break;
		case TenRestartsAchieve:
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

void changeLabels(std::vector<Achieve> &Achieves)
{
	for (Achieve ach : Achieves)
		ach.setLabel();
}

void AchievesOutput(COORD coord)
{
	for (Achieve ach : AchievesComplete)
	{
		SetConsoleCursorPosition(consoleHandle, coord);
		printColorText(consoleHandle, ach.getLabel(), Yellow);
		coord.Y += 2;
	}
}