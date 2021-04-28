#pragma once
#include "Warnings.h"

enum Achieve_id
{
	// (start_value > Min_Warnings) && (start_value < Max_Warnings)
	AllAchievesAchieve = 17,// Сбор всех достижений
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
	// Constructor + implicit conversion from Achieve_id to Achieve
	Achieve(Achieve_id id_, bool val = false)
		: id(id_), value(val) {}

	const char * getLabel() const;
	static const char * getLabel(Achieve_id id);

	Achieve operator=(bool val);
	//Achieve operator=(Achieve_id val) { return Achieve(val); }
	//Achieve operator=(const char * lab) { this->label = lab; return *this; }
	operator bool() const { return value; }
	//operator Achieve_id() const { return id; }

private:
	bool value;
	Achieve_id id;
	//const char * label;
};

// Achieve sub variables(with a_ prefix)
extern int a_UniBombsDie;
extern int a_UniBoxMove;
extern int a_lvl3_Restarts;
extern bool a_lvl2_Mines;
extern bool a_lvl4_Mines;

const size_t a_AchievesMax = 8;		// Достижений всего

// Achievements
extern Achieve AllAchievesAchieve_;
extern Achieve AllCrystalsAchieve_;
extern Achieve lvl3_CrystalsAchieve_;
extern Achieve lvl3_RestartsAchieve_;
extern Achieve NullRestartsAchieve_;
extern Achieve PovorotNeTydaAchieve_;
extern Achieve OnMyWayAchieve_;
extern Achieve AllMinesAchieve_;

extern Achieve* AchievesComplete[a_AchievesMax];

void AchievesOutput(COORD coord);

size_t AchievesCount();

void AchievesClear();

size_t AchievesMax();