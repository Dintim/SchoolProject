//#include "Question.h"
#include <Windows.h>
#include "Test.h"
#include "Teacher.h"
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
	q.setQuesText("Как разговаривает собака?");
	q.addAnswerChoice("1. гав-гав");
	q.addAnswerChoice("2. мяу");
	q.addAnswerChoice("3. рр-гав");
	q.addRightAnswers(1);
	q.addRightAnswers(3);

	Question q2;
	q2.setQuesText("Как зовут собаку?");
	q2.addAnswerChoice("1. Мурзик");
	q2.addAnswerChoice("2. Тузик");
	q2.addAnswerChoice("3. Микеланджело");
	q2.addRightAnswers(2);

	Question q3;
	q3.setQuesText("Как зовут кошку?");
	q3.addAnswerChoice("1. Мурзик");
	q3.addAnswerChoice("2. Тузик");
	q3.addAnswerChoice("3. Микеланджело");
	q3.addRightAnswers(1);
	
	Test tt("животные");
	tt.addQuestion(q);
	tt.addQuestion(q2);
	tt.addQuestion(q3);
	
	Test tt2("животные");
	tt2.readFromFile("3.txt");
	tt2.print();*/
	//tt2.writeToFile("tests\\1.txt");

	
	
	/*Teacher t1("Динара", "Мукашева", 0, date_(22, 5, 1983), "123");
	Teacher t2("Асель", "Ибрагимова", 0, date_(26, 5, 1983), "456");
	Teacher t3("Тимур", "Кадырбаев", 1, date_(18, 6, 1970), "777");

	School sh("ITSTEP");
	sh.addTeacher(t1);
	sh.addTeacher(t2);
	sh.addTeacher(t3);
	sh.delTeacher(11);
	sh.readTeachersFromFile();
	sh.writeTeachersToFile();
	
	vector<string> v = sh.getTeacherStatus();
	for (auto&i : v) {
		cout << i << endl;
	}*/

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
				cout << "Твои варианты ответов (0 - exit):\n";
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
			cout << "твой результат: " << res << endl;
		}
	}*/
	
	

	


	



	system("pause");
	return 0;
}