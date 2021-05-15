#pragma once

#include <random>

#include "Global_Variables.h"
#include "Warnings.h"

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

void RandomizeCrystals(int crystalCount, short clear_x = heroRow, short clear_y = heroColumn);

void ClearCrystals();


void SaveFutureFunction();

void LoadFutureFunction();

void SavePastFunction();

void LoadPastFunction();


void InitVectors();

void CheckBomb(short, short);

void CheckBox(short, short);