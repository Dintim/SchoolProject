#pragma once
#include "School.h"
#include <Windows.h>
#include <conio.h>

static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class Viewer
{
public:
	School sch;
	Viewer();
	void LogIn();
	void yellow();
	void white();
	void red();
	void green();
	void GotoXY(int X, int Y);
	void clearScreen()const { system("cls"); }
};