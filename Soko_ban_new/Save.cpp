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
	
	time_t temp_time; 
	time(&temp_time);
	localtime_s(&current_tm, &temp_time);
	this->l_Selector = levelSelector;
};

void Save::ApplySave() const
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

	levelSelector = this->l_Selector;

	std::queue<Warning> temp_warn;
	warning.swap(temp_warn);
	NextLevel(levelSelector);
	isGameStart = true;
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

	fout.close();
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

	fin.close();
}

void Save::outDate()
{
	char time_buffer[50];
	strftime(time_buffer, 50, "%T %d.%m.%G %a", &this->current_tm);
	std::cout << time_buffer << std::endl;
}

void Save::outParam()
{
	size_t width = 3;

	setlocale(LC_ALL, "C");

	std::cout << std::setw(width) << this->g_Crystals;
	printColorText(consoleHandle, symbolCrystal, Magenta, std::cout);

	std::cout << std::setw(width) << this->g_Keys;
	printColorText(consoleHandle, symbolKey, LightMagenta, std::cout);

	std::cout << std::setw(width) << this->g_Boxes;
	printColorText(consoleHandle, symbolBox, Yellow, std::cout);

	std::cout << std::setw(width) << this->g_Bombs;
	printColorText(consoleHandle, symbolBomb, Red, std::cout);

	std::cout << "  Level " << this->l_Selector;
	setlocale(LC_ALL, "RUS");
}

std::ostream & operator<<(std::ostream &out, const Save &save)
{
	size_t width = 3;
	char time_buffer[50];
	strftime(time_buffer, 50, "%T %d.%m.%G %a", &save.current_tm);
	out << time_buffer << std::endl;
	//struct tm * p_temp = &save.current_tm;
	//time_t temp = mktime(const_cast<tm *>(&save.current_tm));
	//mktime(&save.current_tm);
	//ctime_s(time_buffer, 50, &temp);
	//asctime_s(time_buffer, 50, &save.current_tm);
	//out << time_buffer;

	setlocale(LC_ALL, "C");
	//SetColor(consoleHandle, LightGray);

	out << std::setw(width) << save.g_Crystals;
	printColorText(consoleHandle, symbolCrystal, Magenta, out);

	out << std::setw(width) << save.g_Keys;
	printColorText(consoleHandle, symbolKey, LightMagenta, out);

	out << std::setw(width) << save.g_Boxes;
	printColorText(consoleHandle, symbolBox, Yellow, out);

	out << std::setw(width) << save.g_Bombs;
	printColorText(consoleHandle, symbolBomb, Red, out);

	out << "  Level " << save.l_Selector;
	setlocale(LC_ALL, "RUS");

	return out;
}

std::vector<Save> Saves;

void LoadAllSaves()
{
	using namespace std;

	Saves.clear();
	Save temp;
	ifstream fin("Saves.bin", ios::in | ios::binary);
	if (fin.is_open())
	{
		while (fin.read((char *) &temp, sizeof Save))
		{
			Saves.push_back(temp);
		}

		if (fin.eof()) fin.clear();
		else
		{
			cerr << "Error in reading\n";
			exit(EXIT_FAILURE);
		}
	}
	else cout << "file open read error";

	fin.close();
}

void AppendSave()	// Write
{
	using namespace std;

	Save current;

	ofstream fout("Saves.bin", ios::out | ios::app | ios::binary);
	if (fout.is_open())
	{
		fout.write((char *) &current, sizeof current);
	}
	else cerr << "File open to write error";

	if (fout.fail())
		cerr << "Error on attempted write\n";

	fout.close();
}

void RemoveSave(int selector)
{
	//std::vector<Save>::reverse_iterator iter = Saves.rbegin() + selector;
	std::vector<Save>::iterator iter = (Saves.end() - 1) - selector;
	//Saves.erase(iter.base());
	Saves.erase(iter);

	using namespace std;

	ofstream fout("Saves.bin", ios::out | ios::trunc | ios::binary);
	if (fout.is_open())
	{
		for (const Save &save : Saves)
			fout.write((char *)&save, sizeof save);
	}
	else cout << "File open to rewrite error";

	if (fout.fail())
		cerr << "Error on write attempt\n";

	fout.close();
}