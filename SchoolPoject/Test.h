#pragma once
#include "Question.h"
#include <map>


class Test
{
	int idTest;
	vector<Question> testQuestions;
	int result;
	map<int, int> studentsResults;
public:
	Test();
	Test(int idTest);
	void setIdTest(int idTest);
	int getIdTest()const { return this->idTest; }
	string getQuestion(int number);	
	
	void addQuestion(Question ques);
	void delQuestion(int quesNum);
	void insertStudentResult(int id, int res);
	void delStidentResult(int id);
	int getStudentResult(int id);
};

