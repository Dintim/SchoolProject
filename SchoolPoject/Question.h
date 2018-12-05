#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;


class Question
{
	static int num;
	int quesNum;
	string quesText;
	vector<string> answerChoice;
	vector<int> rightAnswers;	
public:
	Question();
	Question(string question);
	void setQuesText(string text);
	void setAnswerChoice(string answer);	
	void setRightAnswers(int var);

	int getQuesNum()const { return this->quesNum; }
	string getQuesText()const { return this->quesText; }
	string convertQuesToString();

	virtual void info();	
};

