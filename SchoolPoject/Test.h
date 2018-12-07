#pragma once
#include "Question.h"
#include <map>


class Test
{	
	int idTest;
	vector<Question> testQuestions;
	int result;	
public:
	Test();
	Test(int idTest);
	void setIdTest(int idTest);
	int getIdTest()const { return this->idTest; }	
	Question& getQuestion(int number);	
	
	void addQuestion(Question& ques);
	void delQuestion(int number);
	void print()const;	
};

