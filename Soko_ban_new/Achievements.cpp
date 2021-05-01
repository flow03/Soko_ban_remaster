#include "Achievements.h"

//extern int Localization;
//extern HANDLE consoleHandle;

// Achieve sub variables(with a_ prefix)
int a_UniBombsDie = 0;				// Смерть на новой бомбе
int a_UniBoxMove = 0;				// Разных ящиков подвигано
int a_lvl3_Restarts = 0;			// Рестарты уровня 3 до сбора сердечек
bool a_lvl2_Mines = false;			// Все мины уровня 2
bool a_lvl4_Mines = false;			// Все мины уровня 4

//const size_t a_AchievesMax = 8;	// Достижений всего
//int a_AchievesCount = 0;		// Разблокировано достижений

// Achievements
Achieve AllAchievesAchieve_(AllAchievesAchieve);		// +
Achieve AllCrystalsAchieve_(AllCrystalsAchieve);
Achieve lvl3_CrystalsAchieve_(lvl3_CrystalsAchieve);	// +
Achieve lvl3_RestartsAchieve_(lvl3_RestartsAchieve);	// +
Achieve NullRestartsAchieve_(NullRestartsAchieve);		// +
Achieve PovorotNeTydaAchieve_(PovorotNeTydaAchieve);
Achieve OnMyWayAchieve_(OnMyWayAchieve);				// +/- In its wake	
Achieve AllMinesAchieve_(AllMinesAchieve);				// +

Achieve* AchievesComplete[a_AchievesMax] = {

	&AllCrystalsAchieve_,
	&lvl3_CrystalsAchieve_,
	&lvl3_RestartsAchieve_,
	&NullRestartsAchieve_,
	&PovorotNeTydaAchieve_,
	&OnMyWayAchieve_,
	&AllMinesAchieve_,
	&AllAchievesAchieve_
};


const char *  Achieve::getLabel(Achieve_id id)
{
	const char * label = nullptr;

	if (Localization == 1)
		switch (id)
		{
		case AllCrystalsAchieve:
			label = "Зiбрати усi кристали в грi"; break;
		case lvl3_CrystalsAchieve:
			label = "Зiбрати усi кристали на рiвнi 3"; break;
		case lvl3_RestartsAchieve:
			label = "10 рестартiв пiдряд на рiвнi 3"; break;
		case NullRestartsAchieve:
			label = "0 рестартiв гри"; break;
		case PovorotNeTydaAchieve:
			label = "Звернув не туди"; break;
		case OnMyWayAchieve:
			label = "По своїх слiдах"; break;
		case AllMinesAchieve:
			label = "Пiдiрватись на усiх мiнах"; break;
		case AllAchievesAchieve:
			label = "ВСI ДОСЯГНЕННЯ РОЗБЛОКОВАНО"; break;
		}
	else if (Localization == 2)
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
		case AllAchievesAchieve:
			label = "ВСЕ ДОСТИЖЕНИЯ ОТКРЫТЫ"; break;
		}
	else if (Localization == 3)
		switch (id)
		{
		case AllCrystalsAchieve:
			label = "Collect all crystals"; break;
		case lvl3_CrystalsAchieve:
			label = "Collect all crystals on level 3"; break;
		case lvl3_RestartsAchieve:
			label = "10 restarts on level 3"; break;
		case NullRestartsAchieve:
			label = "0 restarts"; break;
		case PovorotNeTydaAchieve:
			label = "Wrong Turn"; break;
		case OnMyWayAchieve:
			label = "On my way"; break;
		case AllMinesAchieve:
			label = "All bobms were detonated"; break;
		case AllAchievesAchieve:
			label = "ALL ACHIEVEMENTS UNLOCKED"; break;
		}

	return label;
}

Achieve Achieve::operator=(bool val)
{
	this->value = val;
	if (val) warning.push(static_cast<Warning>(this->id));
	return *this;
}

const char * Achieve::getLabel() const
{
	return getLabel(this->id);
}


void AchievesOutput(COORD coord)
{
	for (Achieve* ach : AchievesComplete)
	{
		if (*ach)
		{
			SetConsoleCursorPosition(consoleHandle, coord);
			printColorText(consoleHandle, ach->getLabel(), Yellow);
			coord.Y += 2;
		}
	}
}

size_t AchievesCount()
{
	size_t size = 0;
	for (Achieve* ach : AchievesComplete)
		if (*ach) ++size;

	if (!AllAchievesAchieve_)
		if (size >= a_AchievesMax - 1)	// Minus AllAchievesAchieve_
			AllAchievesAchieve_ = true;

	return size;
}

void AchievesClear()
{
	a_UniBombsDie = 0;
	a_UniBoxMove = 0;
	a_lvl3_Restarts = 0;
	a_lvl2_Mines = false;
	a_lvl4_Mines = false;

	for (size_t i = 0; i < a_AchievesMax; ++i)
		AchievesComplete[i]->operator=(false);
}

size_t AchievesMax() { return a_AchievesMax; }