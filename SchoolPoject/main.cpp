//#include "Question.h"
#include <Windows.h>
#include "Test.h"
#include "Teacher.h"
#include "School.h"
#include <fstream>


int main()
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
	tt.addQuestion(q3);*/
	/*tt.delQuestion(3);

	cout << tt[1];

	Test tt2(456);
	tt2.addQuestion(q3);	

	tt2.print();*/

	/*vector<string> vv = q.getAnswerChoice();
	vector<int> x = q.getRightAnswers();
	ostream_iterator<int> os(cout, "\n");
	copy(begin(x), end(x), os);*/

	/*Teacher t(14, "������", "��������", 0, date_(22, 5, 1983));
	t.setStatus("������");
	t.info();
	cout << t.convertToString();*/

	/*Teacher t1(14, "������", "��������", 0, date_(22, 5, 1983));
	Teacher t2(12, "�����", "����������", 0, date_(26, 5, 1983));
	Teacher t3(15, "�����", "���������", 1, date_(18, 6, 1970));

	School sh("ITSTEP");
	sh.addTeacher(t1);
	sh.addTeacher(t2);
	sh.addTeacher(t3);
	sh.delTeacher(11);
	cout << sh.getCntTeachers();*/	
	
	//sh.getTeacher(12).info();

	/*int ch;
	int res;
	while (true) {
		res = 0;
		cout << "0 - exit, 1 - pass test\n";
		system("cls");
		cin >> ch;
		if (ch == 0) break;
		if (ch == 1) {			
			for (auto i = tt.getBeginTestQuestions(); i != tt.getEndTestQuestions(); i++)
			{
				cout << tt[i->first];
				cout << "���� �������� ������� (0 - exit):\n";
				vector<int> myAnswers;
				int ans;
				while (true) {
					cin >> ans;
					if (ans == 0) break;
					myAnswers.push_back(ans);
				}
				sort(begin(myAnswers), end(myAnswers));				
				if (tt[i->first].getRightAnswers() == myAnswers) res++;
			}
			cout << "���� ���������: " << res << endl;
		}
	}*/
	
	School sh("xxxx");
	ifstream is("1.txt");
	string s;
	getline(is, s);
	Teacher t;
	t.readFromString(s);	
	Teacher t1("dfgg", "dffggh", 1, date_(14, 11, 1986));	

	sh.readTeachersFromFile("1.txt");
	sh.writeTeachersToFile("2.txt");

	system("pause");
	return 0;
}