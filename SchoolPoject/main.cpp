//#include "Question.h"
#include <Windows.h>
#include "School.h"
#include "Viewer.h"
#include <iterator>




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	/*Viewer v;
	v.LogIn();*/


	/*Question q;
	q.setQuesText("��� ������������� ������?");
	q.addAnswerChoice("1. ���-���");
	q.addAnswerChoice("2. ���");
	q.addAnswerChoice("3. ��-���");
	q.addRightAnswers(1);
	q.addRightAnswers(3);

	Question q2;
	q2.setQuesText("��� ����� ������?");
	q2.addAnswerChoice("1. ������");
	q2.addAnswerChoice("2. �����");
	q2.addAnswerChoice("3. ������������");
	q2.addRightAnswers(2);

	Question q3;
	q3.setQuesText("��� ����� �����?");
	q3.addAnswerChoice("1. ������");
	q3.addAnswerChoice("2. �����");
	q3.addAnswerChoice("3. ������������");
	q3.addRightAnswers(1);
	
	Test tt("��������");
	tt.addQuestion(q);
	tt.addQuestion(q2);
	tt.addQuestion(q3);
	
	Test tt2("��������");
	tt2.readFromFile("3.txt");
	tt2.print();*/
	//tt2.writeToFile("tests\\1.txt");

	ListTests lt1(11, "sdff", 451);
	ListTests lt2(22, "asdd", 888);
		

	School sh("ITSTEP");
	sh.addListTests(lt1);
	sh.addListTests(lt2);
	sh.writeListTestsToFile();

	
	
	

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
	
	

	


	



	system("pause");
	return 0;
}