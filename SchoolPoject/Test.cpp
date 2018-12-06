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

void Test::insertStudentResult(int id, int res)
{
	studentsResults.insert(make_pair(id, res));
}

void Test::delStidentResult(int id)
{
	studentsResults.erase(id);
}

int Test::getStudentResult(int id)
{
	return studentsResults.find(id)->second;	
}


