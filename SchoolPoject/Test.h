#pragma once
#include "Question.h"
#include <fstream>


class Test
{	
	static int seqIdTest;
	int idTest;
	int quesNum = 0;
	string testName;
	map<int, Question> testQuestions;
	int testMaxResult;
	int idCreator;
public:
	Test(string testName);	
	void setIdTest(int idTest);
	int getIdTest()const { return this->idTest; }
	void setTestName(string testName);
	string getTestName()const { return testName; }
	void setTestMaxResult(int testMaxResult);
	int getTestMaxResult()const { return testMaxResult; }
	void setIdCreator(int idCreator);
	int getIdCreator()const { return idCreator; }
	Question& operator[](int number);	
	
	void addQuestion(Question& ques);
	void addQuestionFromString(string& str);
	void delQuestion(int number);
	int getCntTestQuestions()const { return testQuestions.size(); }
	auto getBeginTestQuestions()const { return begin(testQuestions); }
	auto getEndTestQuestions()const { return end(testQuestions); }
	string convertToString();
	void readFromFile(string fileName);
	void writeToFile(string fileName);
	void print()const;	
};

