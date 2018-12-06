//#include "Question.h"
#include <Windows.h>
#include "Test.h"
#include "Teacher.h"


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	Question q;
	q.setQuesText("Как разговаривает собака?");
	q.setAnswerChoice("1. гав-гав");
	q.setAnswerChoice("2. мяу");
	q.setAnswerChoice("3. рр-гав");
	q.setRightAnswers(1);
	q.setRightAnswers(3);	

	Question q2;
	q2.setQuesText("Как зовут собаку?");
	q2.setAnswerChoice("1. Мурзик");
	q2.setAnswerChoice("2. Тузик");
	q2.setAnswerChoice("3. Микеланджело");
	q2.setRightAnswers(2);
	
	Test tt(123);
	tt.addQuestion(q);
	tt.addQuestion(q2);

	vector<string> vv = q.getAnswerChoice();
	vector<int> x = q.getRightAnswers();
	ostream_iterator<int> os(cout, "\n");
	copy(begin(x), end(x), os);

	Teacher t(14, "Динара", "Мукашева", 0, date_(22, 5, 1983));
	t.info();

	system("pause");
}