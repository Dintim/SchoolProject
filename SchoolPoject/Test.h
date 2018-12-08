#pragma once
#include "Question.h"


class Test
{	
	int idTest;
	int quesNum = 0;
	map<int, Question> testQuestions;
	int result;	
public:
	Test();
	Test(int idTest);
	void setIdTest(int idTest);
	int getIdTest()const { return this->idTest; }	
	Question& operator[](int number);	
	
	void addQuestion(Question& ques);
	void delQuestion(int number);
	int getCntTestQuestions()const { return testQuestions.size(); }
	auto getBeginTestQuestions()const { return begin(testQuestions); }
	auto getEndTestQuestions()const { return end(testQuestions); }
	void print()const;	
};

