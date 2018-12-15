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

void Test::setIdCreator(int idCreator)
{
	this->idCreator = idCreator;
}

Question& Test::operator[](int number)
{
	return testQuestions.find(number)->second;	
}

void Test::addQuestion(Question& ques)
{		
	testQuestions.insert(make_pair(++quesNum, ques));
}

void Test::addQuestionFromString(string & str)
{
	Question tmp;
	tmp.readFromString(str);
	addQuestion(tmp);
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

string Test::convertToString() //++
{
	string res = to_string(idTest) + '\n';
	res += testName + '\n';
	res += to_string(testQuestions.size()) + '\n';
	for (auto&i : testQuestions) {
		res += i.second.convertToString()+'\n';		
	}
	res += to_string(testMaxResult)+'\n';
	res += to_string(idCreator);
	return res;
}

void Test::readFromFile(string fileName) 
{
	ifstream is(fileName);
	vector<string> v;
	string tmp;
	while (!is.eof()) {
		getline(is, tmp);
		v.push_back(tmp);
	}	
	idTest = stoi(v[0]);
	testName = v[1];
	for (size_t i = 3; i < 3+stoi(v[2]); i++)
	{
		Question q;
		q.readFromString(v[i]);
		addQuestion(q);
	}
	testMaxResult = stoi(v[v.size()-2]);
	idCreator = stoi(v[v.size() - 1]);
	is.close();
}

void Test::writeToFile() 
{
	string name = "tests\\" + to_string(idTest);
	ofstream os(name);	
	string str = convertToString();
	os << str;
	os.close();
}

int Test::sumRightAnswers() const 
{
	int sum = 0;
	for (auto&i : testQuestions) {
		sum += i.second.getCntRightAnswers();
	}
	return sum;
}

void Test::print() const
{
	for (auto &i : testQuestions) {		
		cout << "Вопрос №" << i.first << ": " << i.second;
	}
}



