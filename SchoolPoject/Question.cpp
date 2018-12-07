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
	string res = quesText+"\n";
	for (auto &i : answerChoice) {
		res += i + "\n";
	}
	return res;
}

void Question::info()
{	
	cout << this->quesText << endl;
	cout << "Варианты ответов:\n";
	ostream_iterator<string> oss(cout, "\n");	
	copy(begin(answerChoice), end(answerChoice), oss);	
}
