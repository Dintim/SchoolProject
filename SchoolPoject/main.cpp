//#include "Question.h"
#include <Windows.h>
#include "Test.h"


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	Question q;
	q.setQuesText("��� ������������� ������?");
	q.setAnswerChoice("1. ���-���");
	q.setAnswerChoice("2. ���");
	q.setAnswerChoice("3. ��-���");
	q.setRightAnswers(1);
	q.setRightAnswers(3);
	

	Question q2;
	q2.setQuesText("��� ����� ������?");
	q2.setAnswerChoice("1. ������");
	q2.setAnswerChoice("2. �����");
	q2.setAnswerChoice("3. ������������");
	q2.setRightAnswers(2);
	
	Test tt(123);
	tt.addQuestion(q);
	tt.addQuestion(q2);


	system("pause");
}