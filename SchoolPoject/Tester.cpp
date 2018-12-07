#include "Tester.h"



Tester::Tester(int idStudent, int idTest, int testResult)
{
	this->idStudent = idStudent;
	this->idTest = idTest;
	this->testResult = testResult;
}

void Tester::setIdStudent(int idStudent)
{
	this->idStudent = idStudent;
}

void Tester::setIdTest(int idTest)
{
	this->idTest = idTest;
}

void Tester::setTestResult(int res)
{
	this->testResult = testResult;
}
