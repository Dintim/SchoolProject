#include "Question.h"


Question::Question()
{	
	this->quesText = "";	
}

Question::Question(string question){	
	
	this->quesText = question;
}

void Question::setQuesText(string text)
{	
	this->quesText = text;
}

void Question::addAnswerChoice(string answer)
{
	answerChoice.push_back(answer);
}

void Question::addRightAnswers(int var)
{
	rightAnswers.push_back(var);
}


string Question::convertToString()
{
	string res = quesText+';';
	for (auto &i : answerChoice) {
		res += i + ';';
	}
	for (auto&i : rightAnswers) {
		res += to_string(i) + ';';
	}
	return res;
}

void Question::readFromString(string & str)
{
	int c = count(begin(str), end(str), ';');
	string tmp;
	vector<string> v;
	for (size_t i = 0; i < c; i++)
	{
		tmp = str.substr(0, str.find(';'));
		v.push_back(tmp);
		str = str.substr(str.find(';') + 1);
	}
	quesText = v[0];
	for (size_t i = 1; i < 4; i++)
	{
		addAnswerChoice(v[i]);
	}
	for (size_t i = 4; i < c; i++)
	{
		addRightAnswers(stoi(v[i]));
	}
}

void Question::info()
{	
	cout << this->quesText << endl;
	cout << "Варианты ответов:\n";
	ostream_iterator<string> oss(cout, "\n");	
	copy(begin(answerChoice), end(answerChoice), oss);	
}

ostream & operator<<(ostream & os, const Question & obj)
{
	os << obj.getQuesText() << endl;
	os << "Варианты ответов:\n";	
	for (size_t i = 0; i < obj.getCntAnswerChoice(); i++)
	{
		os << obj.getAnswer(i) << endl;
	}	
	return os;
	// TODO: вставьте здесь оператор return
}
