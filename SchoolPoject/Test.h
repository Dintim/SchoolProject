#pragma once
#include "Question.h"
#include <map>


class Test
{
	int idTest;
	vector<Question> testQuestions;
	int result;
	map<string, int> studentsResults;
public:
	Test();
	Test(int idTest);
	void setIdTest(int idTest);
	int getIdTest()const { return this->idTest; }
	string getQuestion(int number);	
	
	void addQuestion(Question ques);
	void delQuestion(int quesNum);
	void insertStudentResult(string surname, int res);
	void delStidentResult(string surname);
	int getStudentResult(string surname);
};

