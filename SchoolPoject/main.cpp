//#include "Question.h"
#include <Windows.h>
#include "Test.h"
#include "Teacher.h"
#include "School.h"


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	/*Question q;
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

	Question q3;
	q3.setQuesText("��� ����� �����?");
	q3.setAnswerChoice("1. ������");
	q3.setAnswerChoice("2. �����");
	q3.setAnswerChoice("3. ������������");
	q3.setRightAnswers(1);
	
	Test tt(123);
	tt.addQuestion(q);
	tt.addQuestion(q2);
	tt.delQuestion(1);

	tt.print();

	Test tt2(456);
	tt2.addQuestion(q3);	

	tt2.print();*/

	/*vector<string> vv = q.getAnswerChoice();
	vector<int> x = q.getRightAnswers();
	ostream_iterator<int> os(cout, "\n");
	copy(begin(x), end(x), os);

	Teacher t(14, "������", "��������", 0, date_(22, 5, 1983));
	t.info();*/

	Teacher t1(14, "������", "��������", 0, date_(22, 5, 1983));
	Teacher t2(12, "�����", "����������", 0, date_(26, 5, 1983));
	Teacher t3(15, "�����", "���������", 1, date_(18, 6, 1970));

	School sh("ITSTEP");
	sh.addTeacher(t1);
	sh.addTeacher(t2);
	sh.addTeacher(t3);
	sh.delTeacher(14);
	cout << sh.getCntTeachers();
	
	//sh.getTeacher(12).info();

	
	


	system("pause");
}