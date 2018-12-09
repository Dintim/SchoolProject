#include "Test.h"

int Test::seqIdTest = 0;

Test::Test(string testName)
{
	this->testName = testName;
	this->idTest = ++seqIdTest;
}

void Test::setIdTest(int idTest)
{
	this->idTest = idTest;
}

void Test::setTestName(string testName)
{
	this->testName = testName;
}

void Test::setTestMaxResult(int testMaxResult)
{
	this->testMaxResult = testMaxResult;
}

Question& Test::operator[](int number)
{
	return testQuestions.find(number)->second;	
}

void Test::addQuestion(Question& ques)
{		
	testQuestions.insert(make_pair(++quesNum, ques));
}

void Test::delQuestion(int number)
{	
	try
	{
		testQuestions.erase(number);
	}
	catch (exception& e)
	{
		cout << e.what();
	}
}

void Test::print() const
{
	for (auto &i : testQuestions) {		
		cout << "Вопрос №" << i.first << ": " << i.second;
	}
}



