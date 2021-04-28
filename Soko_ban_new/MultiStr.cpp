#include "MultiStr.h"

extern HANDLE consoleHandle;

MultiStr::MultiStr()
{
	str = nullptr;
	indent = 0;
}

MultiStr::MultiStr(const char * c_str)
{
	//strcpy_s(str, strlen(c_str), c_str);
	strncpy(str, c_str, strlen(c_str) + 1);
	indent = static_cast<short>(40 - (strlen(str) / 2) + 1);
}

std::ostream & operator<<(std::ostream &out, const MultiStr &multi)
{
	//SetConsoleCursorPosition(consoleHandle, COORD{ multi.indent, 6 });	// y???
	out << multi.str;

	return out;
}
