#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;


class Question
{	
	string quesText;
	vector<string> answerChoice;
	vector<int> rightAnswers;	
public:
	Question();
	Question(string question);
	void setQuesText(string text);
	void addAnswerChoice(string answer);	
	void addRightAnswers(int var);	
	
	string getQuesText()const { return this->quesText; }	
	const vector<string>& getAnswerChoice()const { return this->answerChoice; }
	string getAnswer(int index)const { return answerChoice[index]; }
	const vector<int>& getRightAnswers()const { return this->rightAnswers; }
	int getCntAnswerChoice()const { return answerChoice.size(); }
	int getCntRightAnswers()const { return rightAnswers.size(); }

	string convertToString();
	void readFromString(string& str);
	void info();	
};

ostream&operator<<(ostream&os, const Question&obj);

