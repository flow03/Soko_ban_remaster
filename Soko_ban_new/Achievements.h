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
				label = "���������� �� ���� �����"; break;
			case 1:
				label = "������� ��� ��������� � ����"; break;
			case 2:
				label = "������� ��� ��������� �� ������ 3"; break;
			case 3:
				label = "10 ��������� ������ �� ������ 3"; break;
			}

		return label;
	}


	Ahieve operator=(bool val) { this->value = val; return *this; }
	Ahieve operator=(const char * lab) { this->label = lab; return *this; }
};

// Achieve sub variables(with a_ prefix)
int a_UniBombsDie = 0;			// ������ �� ����� �����
int a_UniBoxMove = 0;			// ������ ������ ���������
int a_AchievesCount = 0;		// �������������� ����������
int a_AchievesMax = 10;			// ���������� �����

// Achievements
Ahieve AllMinesAchieve		( true, 0 );	// ���������� �� ���� �����
Ahieve AllCrystalsAchieve	( true, 1 );	// ������� ��� ��������� � ����
Ahieve lvl3_CrystalsAchieve	{ true, 2 };	// ������� ��� ��������� �� ������ 3
Ahieve TenRestartsAchieve	{ true, 3 };	// 10 ��������� ������ �� ������ 3
//bool NullRestartsAchieve = false;			// 0 ��������� ����
//bool PovorotNeTydaAchieve = false;		// ������� �� ����(�� ���������� ��������� �������)
//bool OnMyWayAchieve = false;			// �� ����� ������
//
//bool AllAchieves = false;				// ���� ���� ����������