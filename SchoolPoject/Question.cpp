#include "Question.h"

int Question::num = 0;

Question::Question()
{
	this->quesNum = ++num;
	this->quesText = "";	
}

Question::Question(string question)
{	
	this->quesNum = ++num;
	this->quesText = question;
}

void Question::setQuesText(string text)
{	
	this->quesText = text;
}

void Question::setAnswerChoice(string answer)
{
	answerChoice.push_back(answer);
}

void Question::setRightAnswers(int var)
{
	rightAnswers.push_back(var);
}


string Question::convertQuesToString()
{
	string res = "Вопрос #";
	res+=to_string(quesNum)+":\n";
	res += quesText+"\n";
	for (auto &i : answerChoice) {
		res += i + "\n";
	}
	return res;
}

void Question::info()
{	
	cout << "Вопрос #" << quesNum << ":\n" << this->quesText << endl;
	cout << "Варианты ответов:\n";
	ostream_iterator<string> oss(cout, "\n");	
	copy(begin(answerChoice), end(answerChoice), oss);	
}
