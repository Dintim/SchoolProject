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
	void cyan();
	void white();
	void red();
	void green();
	void gotoXY(int X, int Y);
	COORD getPos();
	void clearScreen()const { system("cls"); }
	string pasEntry();
	int intEntry(int c, bool e);
	int choice(vector<string> ch, int x, int y);
	int choiceTest(Test t, int idStudent);
	
	void menuA(); 
	void addTeacherMenu(); 
	void addStudentMenu(); 
	void showTeachers(); 
	void teacherMenu(int idTeacher); 
	void changeTeacher(int idTeacher); 
	void showStudents(); 
	void studentMenu(string stSurname); //++
	void changeStudent(string stSurname); //++

	void menuT(int id);
	void menuS(int id);	

	void addTest(int id); 
	void addQuesToTest(Test& t); 
	void addAnswers(Question& q, int varNum); 

	void showMyTests(int id); 
	void testMenu(int idTest); 
	void studentsPassedTest(int idTest); 
	void changeTest(int idTest); 
	void changeQuestion(Test &t, int quesNum); 
	void changeVarQuestion(Question& q); 
	void changeRightAnswers(Question& q); 
	void delQuesFromTest(Test& t); 

	void passingTest(int idStudent);//+++
	void ansC(int cnt, int ta, vector<int> fa);//+++
	void viewA(vector<string> ans, int x, int y, int &ch, vector<int> chS);//+++
	bool fi(vector<int> i, int ch);//+++
	void viewRes(int res, int idStudent);//+++
	int checkScore(Test t, vector<int> chS, int nq);//+++
	bool availability(vector<int> chS, int ch);//+++
	void hintT();//+++
	void finishTest(int idStudent);//+++
	void finishTestForAdmin(int idStudent);//+++
};

