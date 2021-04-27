#pragma once
#include <fstream>

struct Save
{
	Save()
	{
		this->g_Crystals = global_Crystals;
		this->g_Keys = global_Keys;
		this->g_Bombs = global_Bombs;
		this->g_Portals = global_Portals;
		this->g_Boxes = global_Boxes;
		this->g_Restarts = global_Restarts;

		this->AllAchieves_A = AllAchievesAchieve_;
		this->AllCrystals_A = AllCrystalsAchieve_;
		this->lvl3_Crystals_A = lvl3_CrystalsAchieve_;
		this->lvl3_Restarts_A = lvl3_RestartsAchieve_;
		this->NullRestarts_A = NullRestartsAchieve_;
		this->PovorotNeTyda_A = PovorotNeTydaAchieve_;
		this->OnMyWay_A = OnMyWayAchieve_;
		this->AllMines_A = AllMinesAchieve_;

		this->t_time = time(0) - start_time;
		this->l_Selector = levelSelector;
	};

	void applySave() const
	{
		global_Crystals = this->g_Crystals;
		global_Keys = this->g_Keys;
		global_Bombs = this->g_Bombs;
		global_Portals = this->g_Portals;
		global_Boxes = this->g_Boxes;
		global_Restarts = this->g_Restarts;

		AllAchievesAchieve_ = this->AllAchieves_A;
		AllCrystalsAchieve_ = this->AllCrystals_A;
		lvl3_CrystalsAchieve_ = this->lvl3_Crystals_A;
		lvl3_RestartsAchieve_ = this->lvl3_Restarts_A;
		NullRestartsAchieve_ = this->NullRestarts_A;
		PovorotNeTydaAchieve_ = this->PovorotNeTyda_A;
		OnMyWayAchieve_ = this->OnMyWay_A;
		AllMinesAchieve_ = this->AllMines_A;

		start_time = this->t_time;
		levelSelector = this->l_Selector;
	}

	void SaveToFile()
	{
		using namespace std;

		ofstream fout("Saves.bin", ios::out | ios::trunc | ios::binary); // | ios::app
		if (fout.is_open())
		{
			fout.write((char *)this, sizeof(*this));
		}
		else cout << "file open write error";
	}

	void LoadFromFile()
	{
		using namespace std;

		ifstream fin("Saves.bin", ios::in | ios::binary);
		if (fin.is_open())
		{
			fin.read((char *)this, sizeof(*this));
		}
		else cout << "file open read error";
	}

	int getLevel() { return l_Selector; }

private:
	// Global counters
	int g_Crystals;
	int g_Keys;
	int g_Bombs;
	int g_Portals;
	int g_Boxes;
	int g_Restarts;

	// Achievements - maybe bool might be better
	bool AllAchieves_A;
	bool AllCrystals_A;
	bool lvl3_Crystals_A;
	bool lvl3_Restarts_A;
	bool NullRestarts_A;
	bool PovorotNeTyda_A;
	bool OnMyWay_A;
	bool AllMines_A;

	time_t t_time;

	//int heroRow;
	//int heroColumn;
	int l_Selector;	// Level
	//int KeyCount;
	//int CrystalCount;
	//int CrystalMaxCount;
	//int randomCrystals = 10;
	//int Localization = 2;	// Language
	//int font = 1;			// Font

	//bool EasyMode = true;
	//bool futureSelector = false;
	//bool portalWarn = false;
};

void LoadDescription()
{
	SetConsoleCursorPosition(consoleHandle, COORD{ 0, 22 });

	setlocale(LC_ALL, "Russian");

	switch (Localization)
	{
	case 1: //UA
	{
		printColorText(consoleHandle, " ”вага!", Yellow);
		std::cout << " Ѕуде збережена тiльки статистика гравц€, дос€гненн€ та поточний рiвень";
		break;
	}
	case 2: //RU
	{
		printColorText(consoleHandle, "  ¬нимание!", Yellow);
		std::cout << " »гра сохран€ет только статистику игрока, достижени€ и текущий\n  уровень";
		//std::cout << " ѕосле загрузки весь остальной прогресс будет сброшен!";
		break;
	}
	case 3: //ENG
	{
		printColorText(consoleHandle, "  Attention!", Yellow);
		std::cout << " The game only saves player statistics, achievements and current\n  level";
		break;
	}
	}
}