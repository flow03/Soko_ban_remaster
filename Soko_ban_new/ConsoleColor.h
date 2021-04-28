#pragma once

enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

inline void SetColor(HANDLE hStdOut, int textColor, int backgroundColor = 0)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((backgroundColor << 4) | textColor));
}

inline void printColorText(HANDLE hStdOut, const char* text, int textColor)
{
	SetColor(hStdOut, textColor);
	std::cout << text;
	SetColor(hStdOut, LightGray, Black);
}

inline void printColorText(HANDLE hStdOut, const unsigned char symbol, int textColor)
{
	SetColor(hStdOut, textColor);
	std::cout << symbol;
	SetColor(hStdOut, LightGray, Black);
}