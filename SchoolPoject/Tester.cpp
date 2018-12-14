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

void Tester::readFromString(string & str) 
{	
	vector<int> v(3);
	for (auto& i : v) {
		i = stoi(str.substr(0, str.find(';')));		
		str = str.substr(str.find(';') + 1);
	}
	this->idStudent = v[0];
	this->idTest = v[1];
	this->testResult = v[2];
}

string Tester::convertToString() 
{	
	string res = to_string(idStudent) + ';';
	res += to_string(idTest) + ';';
	res += to_string(testResult) + ';';
	return res;
}
