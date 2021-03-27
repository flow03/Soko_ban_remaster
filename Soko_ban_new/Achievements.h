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
int a_UniBombsDie = 0;			// ������ �� ����� �����
int a_UniBoxMove = 0;			// ������ ������ ���������
int a_AchievesCount = 0;		// �������������� ����������
int a_AchievesMax = 10;			// ���������� �����

// Achievements
Achieve AllCrystalsAchieve	( true, 1 );	// ������� ��� ��������� � ����
Achieve lvl3_CrystalsAchieve	{ true, 2 };	// ������� ��� ��������� �� ������ 3
Achieve TenRestartsAchieve	{ true, 3 };	// 10 ��������� ������ �� ������ 3
Achieve NullRestartsAchieve	{ true, 4 };	// 0 ��������� ����
Achieve PovorotNeTydaAchieve	{ true, 5 };	// ������� �� ����(�� ���������� ��������� �������)
Achieve OnMyWayAchieve		{ true, 6 };	// �� ����� ������
Achieve AllMinesAchieve		{ true, 7 };	// ���������� �� ���� �����

Achieve AllAchieves			{ true, 0 };	// ���� ���� ����������


const char * Achieve::getLabel() const
{
	const char * label;

	if (Localization == 2)
		switch (id)
		{
		case 1:
			label = "������� ��� ��������� � ����"; break;
		case 2:
			label = "������� ��� ��������� �� ������ 3"; break;
		case 3:
			label = "10 ��������� ������ �� ������ 3"; break;
		case 4:
			label = "0 ��������� ����"; break;
		case 5:
			label = "������� �� ����"; break;
		case 6:
			label = "�� ����� ������"; break;
		case 7:
			label = "���������� �� ���� �����"; break;

		case 0:
			label = "��� ���������� �������"; break;
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