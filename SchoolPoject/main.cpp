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

	Question q3;
	q3.setQuesText("Как зовут кошку?");
	q3.setAnswerChoice("1. Мурзик");
	q3.setAnswerChoice("2. Тузик");
	q3.setAnswerChoice("3. Микеланджело");
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

	Teacher t(14, "Динара", "Мукашева", 0, date_(22, 5, 1983));
	t.info();*/

	Teacher t1(14, "Динара", "Мукашева", 0, date_(22, 5, 1983));
	Teacher t2(12, "Асель", "Ибрагимова", 0, date_(26, 5, 1983));
	Teacher t3(15, "Тимур", "Кадырбаев", 1, date_(18, 6, 1970));

	School sh("ITSTEP");
	sh.addTeacher(t1);
	sh.addTeacher(t2);
	sh.addTeacher(t3);
	sh.delTeacher(14);
	cout << sh.getCntTeachers();
	
	//sh.getTeacher(12).info();

	
	


	system("pause");
}