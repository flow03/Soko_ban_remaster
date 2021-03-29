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


// Achievements
std::vector<Achieve*> AchievesComplete;

Achieve AllAchieves_(AllAchieves);
Achieve AllCrystalsAchieve_(AllCrystalsAchieve);
Achieve lvl3_CrystalsAchieve_(lvl3_CrystalsAchieve);	// +
Achieve lvl3_RestartsAchieve_(lvl3_RestartsAchieve);	// +
Achieve NullRestartsAchieve_(NullRestartsAchieve);		// +
Achieve PovorotNeTydaAchieve_(PovorotNeTydaAchieve);
Achieve OnMyWayAchieve_(OnMyWayAchieve);
Achieve AllMinesAchieve_(AllMinesAchieve);

// Achieve sub variables(with a_ prefix)
int a_UniBombsDie = 0;			// ������ �� ����� �����
int a_UniBoxMove = 0;			// ������ ������ ���������
int a_lvl3Restarts = 0;			// �������� ������ 3 �� ����� ��������
//int a_AchievesCount = 0;		// �������������� ����������
int a_AchievesMax = 8;			// ���������� �����


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

void changeLabels(std::vector<Achieve*> &Achieves)
{
	for (Achieve* ach : Achieves)
		ach->setLabel();
}

void AchievesOutput(COORD coord)
{
	for (Achieve* ach : AchievesComplete)
	{
		SetConsoleCursorPosition(consoleHandle, coord);
		printColorText(consoleHandle, ach->getLabel(), Yellow);
		coord.Y += 2;
	}
}