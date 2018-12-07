#pragma once
#include <string>
#include <iostream>
#include <vector>
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
	void setAnswerChoice(string answer);	
	void setRightAnswers(int var);	
	
	string getQuesText()const { return this->quesText; }	
	vector<string>& getAnswerChoice() { return this->answerChoice; }
	vector<int>& getRightAnswers() { return this->rightAnswers; }

	string convertQuesToString();
	virtual void info();	
};

