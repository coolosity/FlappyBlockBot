#pragma once

#include <iostream>
#include <windows.h>
#include <string>

class ConsoleUtils
{
//swagswagswgagsnlguicrewtnhiouceghngthnutvnhgvwnhougvnhopugw5vohnpuvgohnugvhngv5inphg5vnhginophg
private:
	COORD lastPos;
public:
	void writeInColor(std::string text, WORD color);
	void savePosition();
	void setPosition();
	void setPosition(int clearLines);
	void clearLines(int num);
};

void ConsoleUtils::writeInColor(std::string text, WORD color)
{
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);
	SetConsoleTextAttribute(hstdout, color);
	std::cout << text;
	SetConsoleTextAttribute(hstdout, csbi.wAttributes);
}

void ConsoleUtils::savePosition()
{
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);
	lastPos = csbi.dwCursorPosition;
}

void ConsoleUtils::setPosition()
{
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hstdout, lastPos);
}

void ConsoleUtils::setPosition(int clearLines)
{
	setPosition();
	if (clearLines > 0)
	{
		this->clearLines(clearLines);
		setPosition();
	}
}

void ConsoleUtils::clearLines(int num)
{
	for (int i = 0; i < num; i++)
	{
		std::cout << "                                                                                " << std::endl;
	}
}
