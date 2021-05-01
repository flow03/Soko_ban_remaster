#include "Achievements.h"

//extern int Localization;
//extern HANDLE consoleHandle;

// Achieve sub variables(with a_ prefix)
int a_UniBombsDie = 0;				// ������ �� ����� �����
int a_UniBoxMove = 0;				// ������ ������ ���������
int a_lvl3_Restarts = 0;			// �������� ������ 3 �� ����� ��������
bool a_lvl2_Mines = false;			// ��� ���� ������ 2
bool a_lvl4_Mines = false;			// ��� ���� ������ 4

//const size_t a_AchievesMax = 8;	// ���������� �����
//int a_AchievesCount = 0;		// �������������� ����������

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
			label = "�i����� ��i �������� � ��i"; break;
		case lvl3_CrystalsAchieve:
			label = "�i����� ��i �������� �� �i��i 3"; break;
		case lvl3_RestartsAchieve:
			label = "10 �������i� �i���� �� �i��i 3"; break;
		case NullRestartsAchieve:
			label = "0 �������i� ���"; break;
		case PovorotNeTydaAchieve:
			label = "������� �� ����"; break;
		case OnMyWayAchieve:
			label = "�� ���� ��i���"; break;
		case AllMinesAchieve:
			label = "�i�i������� �� ��i� �i���"; break;
		case AllAchievesAchieve:
			label = "��I ���������� ������������"; break;
		}
	else if (Localization == 2)
		switch (id)
		{
		case AllCrystalsAchieve:
			label = "������� ��� ��������� � ����"; break;
		case lvl3_CrystalsAchieve:
			label = "������� ��� ��������� �� ������ 3"; break;
		case lvl3_RestartsAchieve:
			label = "10 ��������� ������ �� ������ 3"; break;
		case NullRestartsAchieve:
			label = "0 ��������� ����"; break;
		case PovorotNeTydaAchieve:
			label = "������� �� ����"; break;
		case OnMyWayAchieve:
			label = "�� ����� ������"; break;
		case AllMinesAchieve:
			label = "���������� �� ���� �����"; break;
		case AllAchievesAchieve:
			label = "��� ���������� �������"; break;
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