#pragma once
#include <cstring>
#include <iostream>
#include <Windows.h>

class MultiStr
{
public:
	MultiStr();
	MultiStr(const char * c_str);
	friend std::ostream& operator<< (std::ostream &, const MultiStr &);
private:
	char * str;
	short indent;
};
