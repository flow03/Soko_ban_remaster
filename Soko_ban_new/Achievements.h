#pragma once

enum Achieve_id
{
	AllAchieves = 0,		// ���� ���� ����������
	AllCrystalsAchieve,		// ������� ��� ��������� � ����
	lvl3_CrystalsAchieve,	// ������� ��� ��������� �� ������ 3
	lvl3_RestartsAchieve,	// 10 ��������� ������ �� ������ 3
	NullRestartsAchieve,	// 0 ��������� ����
	PovorotNeTydaAchieve,	// ������� �� ����(�� ���������� ��������� �������)
	OnMyWayAchieve,			// �� ����� ������
	AllMinesAchieve			// ���������� �� ���� �����
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
int a_UniBombsDie = 0;			// ������ �� ����� �����
int a_UniBoxMove = 0;			// ������ ������ ���������
int a_lvl3Restarts = 0;			// �������� ������ 3 �� ����� ��������
//int a_AchievesCount = 0;		// �������������� ����������
const size_t a_AchievesMax = 8;	// ���������� �����

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

		case AllAchieves:
			label = "��� ���������� �������"; break;
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