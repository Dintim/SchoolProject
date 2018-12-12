#pragma once
#include <string>
using namespace std;

class ListTests
{
	int idTest;
	string testName;
	int idCreator;
public:
	ListTests();
	void setIdTest (int idTest);
	void setTestName(string testName);
	void setIdCreator(int idCreator);
	int getIdTest()const { return idTest; }
	string getTestName()const { return testName; }
	int getIdCreator()const { return idCreator; }
};

