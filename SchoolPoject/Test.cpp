#include "Test.h"



Test::Test()
{
}

Test::Test(int idTest)
{
	this->idTest = idTest;
}

void Test::setIdTest(int idTest)
{
	this->idTest = idTest;
}

string Test::getQuestion(int quesNum)
{
	string str;
	for (auto &i:testQuestions)
	{
		if (i.getQuesNum() == quesNum)
			str=i.convertQuesToString();
	}
	return str;
}

void Test::addQuestion(Question ques)
{
	testQuestions.push_back(ques);
}

void Test::delQuestion(int quesNum)
{	
	for (size_t i=0; i< testQuestions.size(); i++)
	{
		if (testQuestions[i].getQuesNum() == quesNum) {
			testQuestions.erase(begin(testQuestions)+i);
		}
	}	
}

void Test::insertStudentResult(string surname, int res)
{
	studentsResults.insert(make_pair(surname, res));
}

void Test::delStidentResult(string surname)
{
	studentsResults.erase(surname);
}

int Test::getStudentResult(string surname)
{
	return studentsResults.find(surname)->second;	
}


