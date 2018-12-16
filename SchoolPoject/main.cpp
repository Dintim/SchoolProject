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

	Viewer v;
	//v.menuT(1);
	v.menuA();

	

	/*ListTests lt1(11, "sdff", 451);
	ListTests lt2(22, "asdd", 888);
		

	School sh("ITSTEP");
	sh.addListTests(lt1);
	sh.addListTests(lt2);
	sh.writeListTestsToFile();*/

	
	
	

	/*Test tt("");
	tt.readFromFile("tests\\1");
	tt.print();
	int ch;
	int res;
	while (true) {
		res = 0;
		cout << "0 - exit, 1 - pass test\n";
		cin >> ch;
		if (ch == 0) break;
		if (ch == 1) {			
			for (auto i = tt.getBeginTestQuestions(); i != tt.getEndTestQuestions(); i++)
			{
				system("cls");
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