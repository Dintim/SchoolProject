#include "Viewer.h"

Viewer::Viewer() :sch("ITStep")
{
}

void Viewer::LogIn()
{
	clearScreen();
	GotoXY(15, 5);
	green();
	cout << "Добро пожаловать в ITStep!";
	GotoXY(15, 8);
	yellow();
	cout << "-> Войти";
	white();
	GotoXY(15, 9);
	cout << "   Зарегистрироватся";
	int r, m = 1, k, code;
	do
	{
		k = 0;
		code = _getch();
		if (code == 224 || code == 0)
			code = _getch();
		if (code == 80)
		{
			if (m != 2) m += 1;
			else m = 1;
			if (m == 1)
			{
				yellow(); GotoXY(15, 8); printf("-> Войти");
				white(); GotoXY(15, 9);  printf("   Зарегистрироватся");
			}
			else if (m == 2)
			{
				white(); GotoXY(15, 8); printf("   Войти");
				yellow(); GotoXY(15, 9);  printf("-> Зарегистрироватся");
			}
		}
		else if (code == 72)
		{
			if (m != 1) m -= 1;
			else m = 2;
			if (m == 1)
			{
				yellow(); GotoXY(15, 8); printf("-> Войти");
				white(); GotoXY(15, 9);  printf("   Зарегистрироватся");
			}
			else if (m == 2)
			{
				white(); GotoXY(15, 8); printf("   Войти");
				yellow(); GotoXY(15, 9);  printf("-> Зарегистрироватся");
			}
		}
		else if (code == 13)
		{
			k = 1;
		}
	} while (k == 0);
	if (m == 1)
	{
		clearScreen();
		GotoXY(15, 5); green();
		cout << "Добро пожаловать в ITStep!";
		GotoXY(15, 8); white();
		string l, p;
		cout << "Фамилия: ";
		GotoXY(24, 8);
		cin >> l;
		GotoXY(15, 9);
		cout << "Пароль: ";
		GotoXY(24, 9);
		do
		{
			//k = 0;
			code = _getch();
			cout << "*";
			p += code;
			if (code == 13)
			{
				k = 0;
			}
		} while (k == 1);
		sch.readStudentsFromFile();
		Student tmp = sch.getStudent(l);
		//tmp.info();
	}
	else if (m == 2)
	{
		clearScreen();
		GotoXY(15, 5); green();
		cout << "Добро пожаловать в ITStep!";
		GotoXY(15, 8); white();
		cout << "Вы регистриретесь как: ";
		GotoXY(15, 9); yellow();
		cout << "-> Преподователь";
		GotoXY(15, 10); white();
		cout << "   Студент";
		int st = 1;
		do
		{
			k = 0;
			code = _getch();
			if (code == 224 || code == 0)
				code = _getch();
			if (code == 80)
			{
				if (st != 2) st += 1;
				else st = 1;
				if (st == 1)
				{
					yellow(); GotoXY(15, 9); cout << "-> Преподователь";
					white(); GotoXY(15, 10);  cout << "   Студент";
				}
				else if (st == 2)
				{
					white(); GotoXY(15, 9); cout << "   Преподователь";
					yellow(); GotoXY(15, 10);  cout << "-> Студент";
				}
			}
			else if (code == 72)
			{
				if (st != 1) st -= 1;
				else st = 2;
				if (st == 1)
				{
					yellow(); GotoXY(15, 9); cout << "-> Преподователь";
					white(); GotoXY(15, 10);  cout << "   Студент";
				}
				else if (st == 2)
				{
					white(); GotoXY(15, 9); cout << "   Преподователь";
					yellow(); GotoXY(15, 10);  cout << "-> Студент";
				}
			}
			else if (code == 13)
			{
				k = 1;
			}
		} while (k == 0);
		clearScreen();
		GotoXY(15, 5); green();
		cout << "Добро пожаловать в ITStep!";
		Human *N = nullptr;
		string fn, sn, pas, pas1;
		bool sex = 1;
		int d, m, y;
		GotoXY(15, 8); white();
		cout << "Фамилия: ";
		cin >> sn;
		GotoXY(15, 9); white();
		cout << "Имя: ";
		cin >> fn;
		GotoXY(15, 10); white();
		cout << "Пол: ";
		GotoXY(15, 11); yellow();
		cout << "-> Мужской";
		GotoXY(15, 12); white();
		cout << "   Женский";
		do
		{
			k = 0;
			code = _getch();
			if (code == 224 || code == 0)
				code = _getch();
			if (code == 80)
			{
				if (sex != 1) sex += 1;
				else sex = 0;
				if (sex == 1)
				{
					yellow(); GotoXY(15, 11); cout << "-> Мужской";
					white(); GotoXY(15, 12);  cout << "   Женский";
				}
				else if (sex == 0)
				{
					white(); GotoXY(15, 11); cout << "   Мужской";
					yellow(); GotoXY(15, 12);  cout << "-> Женский";
				}
			}
			else if (code == 72)
			{
				if (sex != 0) sex -= 1;
				else sex = 1;
				if (sex == 1)
				{
					yellow(); GotoXY(15, 11); cout << "-> Мужской";
					white(); GotoXY(15, 12);  cout << "   Женский";
				}
				else if (sex == 0)
				{
					white(); GotoXY(15, 11); cout << "   Мужской";
					yellow(); GotoXY(15, 12);  cout << "-> Женский";
				}
			}
			else if (code == 13)
			{
				k = 1;
			}
		} while (k == 0);
		GotoXY(15, 13); white();
		cout << "Дата рождения:";
		GotoXY(15, 14); white();
		cout << "Год: "; cin >> y;
		GotoXY(15, 15); white();
		cout << "Месяц (цифрами): "; cin >> m;
		GotoXY(15, 16); white();
		cout << "День: "; cin >> d;
		GotoXY(15, 17); white();
		cout << "Введите пароль: "; cin >> pas;
		GotoXY(15, 18); white();
		cout << "Повторите: "; cin >> pas1;
		if (pas1 == pas)
		{
			GotoXY(15, 19); green();
			cout << "Пароль принят!";
		}
		else
		{
			GotoXY(15, 19); red();
			cout << "Вы не верно ввели пароль";
		}
		if (st == 1)
		{
			N = new Teacher();
		}
		else if (st == 2)
		{
			N = new Student();
		}
	}
}

void Viewer::yellow()
{
	SetConsoleTextAttribute(hConsole, 14);
}

void Viewer::white()
{
	SetConsoleTextAttribute(hConsole, 15);
}

void Viewer::red()
{
	SetConsoleTextAttribute(hConsole, 12);
}

void Viewer::green()
{
	SetConsoleTextAttribute(hConsole, 11);
}

void Viewer::GotoXY(int X, int Y)
{
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hConsole, coord);
}

