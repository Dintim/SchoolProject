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
	void gotoXY(int X, int Y);
	COORD getPos();
	void clearScreen()const { system("cls"); }
	string pasEntry();
	int intEntry(int c, bool e);
	int choice(vector<string> ch, int x, int y);
	void menuA();
	void menuT(int id);
	void menuS(int id);

	void addTest(int id); //++
	void addQuesToTest(Test& t); //++
	void addAnswers(Question& q, int varNum); //++

	void showMyTests(int id); //++
	void testMenu(int idTest); //++
	void studentsPassedTest(int idTest); //++
	void changeTest(int idTest); //++
	void changeQuestion(Test &t, int quesNum); //++
	void changeVarQuestion(Question& q); //++
	void changeRightAnswers(Question& q); //++
	void delQuesFromTest(Test& t); //++
};

