#pragma once
#include <string>
#include <vector>
using namespace std;

class Tester
{
	int idStudent;
	int idTest;
	int testResult;
public:
	Tester(int idStudent=0, int idTest=0, int testResult=0);
	void setIdStudent(int idStudent);
	void setIdTest(int idTest);
	void setTestResult(int res);

	int getIdStudent()const { return idStudent; } //++
	int getIdTest()const { return idTest; } //++
	int getTestResult()const { return testResult; } //++

	void readFromString(string& str); 
	string convertToString(); 
};

