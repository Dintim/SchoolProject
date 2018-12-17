#include "Viewer.h"
#include <iterator>




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	Viewer v;
	v.LogIn();
	/*v.menuA;
	v.menuT(1);
	v.menuS(1);*/	


	system("pause");
	return 0;
}