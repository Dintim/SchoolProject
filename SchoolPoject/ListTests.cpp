#include "ListTests.h"



ListTests::ListTests(int idTest, string testName, int idCreator)
{
	this->idTest = idTest;
	this->testName = testName;
	this->idCreator = idCreator;
}

void ListTests::setIdTest(int idTest)
{
	this->idTest = idTest;
}

void ListTests::setTestName(string testName)
{
	this->testName = testName;
}

void ListTests::setIdCreator(int idCreator)
{
	this->idCreator = idCreator;
}

void ListTests::readFromString(string & str) //++
{
	vector<string> v(3);
	for (auto& i : v) {
		i = str.substr(0, str.find(';'));
		str = str.substr(str.find(';') + 1);
	}
	this->idTest = stoi(v[0]);
	this->testName = v[1];
	this->idCreator = stoi(v[2]);
}

string ListTests::convertToString() //++
{	
	string res = to_string(idTest) + ';';
	res += testName + ';';
	res += to_string(idCreator) + ';';
	return res;
}


