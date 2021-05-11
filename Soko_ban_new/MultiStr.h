#pragma once
#include <cstring>	// strlen
#include <iostream>
#include <iomanip>
#include <Windows.h>

#include "ConsoleColor.h"
#include "Save.h"

extern int font;

class MultiStr
{
public:
	MultiStr();
	MultiStr(const char *);
	friend std::ostream& operator<< (std::ostream &, const MultiStr &);
	operator const char *() const;
	short getI() const;
private:
	const char * str;
	short indent;
};


void MenuInit();

void out_Menu(int);

void out_YesNo(bool);

void out_RenderSettings(int, char &);

void out_WrongKey(char);

void out_LoadMenu(int);

void out_SaveDescription();

void out_SaveList(std::vector<Save> &, int);