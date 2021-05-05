#include "Save.h"

Save::Save()
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

void Save::applySave() const
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

void Save::SaveToFile()
{
	using namespace std;

	ofstream fout("Saves.bin", ios::out | ios::trunc | ios::binary); // | ios::app
	if (fout.is_open())
	{
		fout.write((char *)this, sizeof(*this));
	}
	else cout << "file open write error";
}

void Save::LoadFromFile()
{
	using namespace std;

	ifstream fin("Saves.bin", ios::in | ios::binary);
	if (fin.is_open())
	{
		fin.read((char *)this, sizeof(*this));
	}
	else cout << "file open read error";
}

int Save::getLevel() { return l_Selector; }