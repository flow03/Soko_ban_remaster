#pragma once

enum Achieve_id
{
	AllAchieves = 0,		// ���� ���� ����������
	AllCrystalsAchieve,		// ������� ��� ��������� � ����
	lvl3_CrystalsAchieve,	// ������� ��� ��������� �� ������ 3
	TenRestartsAchieve,		// 10 ��������� ������ �� ������ 3
	NullRestartsAchieve,	// 0 ��������� ����
	PovorotNeTydaAchieve,	// ������� �� ����(�� ���������� ��������� �������)
	OnMyWayAchieve,			// �� ����� ������
	AllMinesAchieve			// ���������� �� ���� �����
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
int a_UniBombsDie = 0;			// ������ �� ����� �����
int a_UniBoxMove = 0;			// ������ ������ ���������
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
		case TenRestartsAchieve:
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