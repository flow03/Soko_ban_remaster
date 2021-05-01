#pragma once
#include <cstring>	// strlen
#include <iostream>
#include <Windows.h>

#include "ConsoleColor.h"

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

void MenuOut(int);

void YesNoOut(bool);