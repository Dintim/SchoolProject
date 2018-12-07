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

Question& Test::getQuestion(int number)
{
	for (size_t i = 0; i < testQuestions.size(); i++)
	{
		if (i == number - 1) {
			return testQuestions[i];
		}
	}	
}

void Test::addQuestion(Question& ques)
{
	testQuestions.push_back(ques);	
}

void Test::delQuestion(int number)
{		
	for (size_t i=0; i< testQuestions.size(); i++)
	{
		if (i == number-1) {
			testQuestions.erase(begin(testQuestions)+i);
		}
	}	
}

void Test::print() const
{
	for (auto i : testQuestions) {
		i.info();
		cout << endl << endl;
	}
}



