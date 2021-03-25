#pragma once

const unsigned char levelData3sub[rowsCount3][columnsCount] = {
	"############22#",
	"#   X   X  #  #",
	"#X  X  X XX#tt#",
	"#  ####### #  #",
	"#  # v   # #  #",
	"#XX# #   # #  #",
	"#  # ##### #tt#",
	"#  #       #  #",
	"#XX#########  #",
	"#  b   bXXXXtt#",
	"#    b tXXXX  #",
	"###############",
	"               ",
};

void Initialise(const unsigned char(*)[columnsCount], const unsigned char(*)[columnsCount]);

void RandomizeCrystals(int crystalCount, short clear_x = heroRow, short clear_y = heroColumn)
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
}

void LoadFutureFunction()
{
	if (!futureSelector)
	{
		for (int r = 0; r < rowsCount3; r++)
			for (int c = 0; c < columnsCount; c++)
				Future[r][c] = levelData3sub[r][c];

		futureSelector = true;
		warning = bonusLevelWarning;
	}

	Initialise(std::begin(Future), std::end(Future));

	levelSelector = 4;

	heroRow = 10;	// 5
	heroColumn = 6;	// 7
}

void SavePastFunction()
{
	for (int r = 0; r < rowsCount3; r++)
		for (int c = 0; c < columnsCount; c++)
		{
			Past[r][c] = levelData[r][c];
		}
}

void LoadPastFunction()
{
	/*for (int r = 0; r < rowsCount3; r++)
		for (int c = 0; c < columnsCount; c++)
		{
			levelData[r][c] = Past[r][c];
		}*/

	Initialise(std::begin(Past), std::end(Past));

	levelSelector = 3;
	heroRow = 6;
	heroColumn = 7;
}


void InitVectors()	// Don't work with objects appered after init
{
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

void CkeckBomb(short x, short  y)
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
}

void CkeckBox(short x, short  y)
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