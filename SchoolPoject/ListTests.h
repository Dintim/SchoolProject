#pragma once
#include <string>
#include <vector>
using namespace std;

class ListTests
{
	int idTest;
	string testName;
	int idCreator;
public:
	ListTests(int idTest=0, string testName="", int idCreator=0);
	void setIdTest (int idTest);
	void setTestName(string testName);
	void setIdCreator(int idCreator);
	int getIdTest()const { return idTest; }
	string getTestName()const { return testName; }
	int getIdCreator()const { return idCreator; }
	void readFromString(string& str); 
	string convertToString(); 
};

