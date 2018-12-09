#pragma once
#include "Question.h"


class Test
{	
	static int seqIdTest;
	int idTest;
	int quesNum = 0;
	string testName;
	map<int, Question> testQuestions;
	int testMaxResult;	
public:
	Test(string testName);	
	void setIdTest(int idTest);
	int getIdTest()const { return this->idTest; }
	void setTestName(string testName);
	string getTestName()const { return testName; }
	void setTestMaxResult(int testMaxResult);
	int getTestMaxResult()const { return testMaxResult; }
	Question& operator[](int number);	
	
	void addQuestion(Question& ques);
	void delQuestion(int number);
	int getCntTestQuestions()const { return testQuestions.size(); }
	auto getBeginTestQuestions()const { return begin(testQuestions); }
	auto getEndTestQuestions()const { return end(testQuestions); }
	void print()const;	
};

