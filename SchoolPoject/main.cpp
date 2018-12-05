//#include "Question.h"
#include <Windows.h>
#include "Test.h"


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


	system("pause");
}