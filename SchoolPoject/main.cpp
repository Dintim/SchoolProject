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

	vector<string> vv = q.getAnswerChoice();
	vector<int> x = q.getRightAnswers();
	ostream_iterator<int> os(cout, "\n");
	copy(begin(x), end(x), os);

	Teacher t(14, "������", "��������", 0, date_(22, 5, 1983));
	t.info();

	system("pause");
}