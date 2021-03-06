#include "Functions.h"

void Initialise(const unsigned char(*)[columnsCount], const unsigned char(*)[columnsCount]);

void RandomizeCrystals(int crystalCount, short clear_x, short clear_y)
{
	std::vector<COORD> crystals;
	crystals.reserve((rowsCount3 - 5) * (columnsCount - 5)); // 8 * 11 = 88 - 6 = 82
	// 5 = 2 wall rows + 2 near wall rows + 1 empty row 
	// 5 = 2 wall cols + 2 near wall cols + 1 \0 col

	//Random
	std::mt19937 engine; //minstd_rand, mt19937, mt19937_64, default_random_engine
	std::random_device device;
	//double en = device.entropy();
	//engine.seed(static_cast<unsigned int>(time(0)));
	engine.seed(device());

	auto funcClear = [&crystals](short x, short y)
	{
		//std::vector<COORD>::iterator
		auto result = std::remove_if(crystals.begin(), crystals.end(), [x, y](COORD a)
		{
			return	(a.X >= (x - 1) && a.X <= (x + 1) && a.Y == y) ||
				(a.Y >= (y - 1) && a.Y <= (y + 1) && a.X == x);			// 5
			/*return	((a.X >= (x - 1)) && (a.X <= (x + 1))) &&
					((a.Y >= (y - 1)) && (a.Y <= (y + 1)));*/				// 3x3
		});

		crystals.erase(result, crystals.end());
	};

	auto funcCheck = [](short x, short y) -> bool
	{
		return (levelData[x + 1][y] == ' ' && levelData[x - 1][y] == ' ' &&
			levelData[x][y + 1] == ' ' && levelData[x][y - 1] == ' ');
	};

	// initialise empty cells vector
	for (short i = 2; i < rowsCount3 - 3; ++i)
		for (short j = 2; j < columnsCount - 3; ++j)
		{
			if (levelData[i][j] == ' ') // && funcCheck(i, j))
				crystals.push_back(COORD{ i, j });
		}

	// remove some empty cells around invisible portals
	funcClear(6, 5);
	funcClear(6, 9);
	// sub arguments
	funcClear(clear_x, clear_y);

	int index = 0;
	short x = 0; short y = 0;

	while (crystalCount > 0 && crystals.size() != 0)
	{
		index = engine() % crystals.size();
		x = crystals.at(index).X;
		y = crystals.at(index).Y;

		if (funcCheck(x, y))
		{
			levelData[x][y] = symbolCrystal;
			funcClear(x, y);
			--crystalCount;
		}
		else
			crystals.erase(crystals.begin() + index);
	}
}

void ClearCrystals()
{
	for (short i = 2; i < rowsCount3 - 3; ++i)
		for (short j = 2; j < columnsCount - 3; ++j)
		{
			if (levelData[i][j] == symbolCrystal)
				levelData[i][j] = ' ';
		}
}


void SaveFutureFunction()
{
	for (int r = 0; r < rowsCount3; r++)
		for (int c = 0; c < columnsCount; c++)
		{
			Future[r][c] = levelData[r][c];
		}

	futureBoxes = markedBoxes;
	futureMines = markedMines;
}

void LoadFutureFunction()
{
	if (!futureSelector)
	{
		for (int r = 0; r < rowsCount3; r++)
			for (int c = 0; c < columnsCount; c++)
				Future[r][c] = levelData3sub[r][c];

		futureSelector = true;
		portalWarn = true;
		warning.push(bonusLevelWarning);
		//InitVectors();	// NOT GOOD, make init 1 time per game
	}

	levelSelector = 4;
	Initialise(std::begin(Future), std::end(Future));

	markedBoxes = futureBoxes;
	markedMines = futureMines;

#ifdef _DEBUG
	heroRow = 10;	// 5
	heroColumn = 6;	// 7
#else
	heroRow = 5;
	heroColumn = 7;
#endif
	levelData[heroRow][heroColumn] = symbolHero;
}

void SavePastFunction()
{
	for (int r = 0; r < rowsCount3; r++)
		for (int c = 0; c < columnsCount; c++)
		{
			Past[r][c] = levelData[r][c];
		}

	pastBoxes = markedBoxes;
}

void LoadPastFunction()
{
	/*for (int r = 0; r < rowsCount3; r++)
		for (int c = 0; c < columnsCount; c++)
		{
			levelData[r][c] = Past[r][c];
		}*/

	Initialise(std::begin(Past), std::end(Past));
	//InitVectors();

	markedBoxes = pastBoxes;

	levelSelector = 3;
	heroRow = 6;
	heroColumn = 7;
}


void InitVectors()	// Don't work with objects appered after init
{
	markedBoxes.clear();
	markedMines.clear();

	for (short i = 0; i < rowsCount; ++i)
		for (short j = 0; j < columnsCount; ++j)
		{
			if (levelData[i][j] == symbolBox)
				markedBoxes.push_back(COORD{ i, j });
			else if (levelData[i][j] == symbolBomb)
				markedMines.push_back(COORD{ i, j });
			else if (levelData[i][j] == '\0')
				break;
		}
}

void CheckBomb(short x, short  y)
{
	for (auto iter = markedMines.begin(); iter != markedMines.end(); iter++)
	{
		if (iter->X == x && iter->Y == y)
		{
			++a_UniBombsDie;
			markedMines.erase(iter);
			break;
		}
	}

	if (markedMines.size() == 0)
	{
		markedMines.push_back(COORD{ 0, 0 });

		if (levelSelector == 2)
			a_lvl2_Mines = true;
		else if (levelSelector == 4)		// no mines on level 3
			a_lvl4_Mines = true;

		if (a_lvl2_Mines && a_lvl4_Mines)
			AllMinesAchieve_ = true;		// carefull, maybe double warning
		else
			warning.push((Warning)AllMinesAchieve);
	}
}

void CheckBox(short x, short  y)
{
	for (auto iter = markedBoxes.begin(); iter != markedBoxes.end(); iter++)
	{
		if (iter->X == x && iter->Y == y)
		{
			++a_UniBoxMove;
			markedBoxes.erase(iter);
			break;
		}
	}
}