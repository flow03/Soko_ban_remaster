#pragma once
//#include <Windows.h>

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

void SetColor(HANDLE hStdOut, int textColor, int backgroundColor = 0)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((backgroundColor << 4) | textColor));
}

void printColorText(HANDLE hStdOut, const char* text, int textColor)
{
	SetColor(hStdOut, textColor);
	std::cout << text;
	SetColor(hStdOut, LightGray, Black);
}

void printColorText(HANDLE hStdOut, const unsigned char text, int textColor)
{
	SetColor(hStdOut, textColor);
	std::cout << text;
	SetColor(hStdOut, LightGray, Black);
}

//void SetColor(int textColor, int backgroundColor)
//{
//	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hStdOut, (WORD)((backgroundColor << 4) | textColor));
//}

//void SetColor(int textColor, ConsoleColor backgroundColor)
//{
//	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hStdOut, (WORD)((backgroundColor << 4) | textColor));
//}