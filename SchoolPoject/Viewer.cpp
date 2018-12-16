#include "Viewer.h"

Viewer::Viewer() :sch("ITStep")
{

}

void Viewer::LogIn()
{
	clearScreen();
	gotoXY(15, 5);
	green();
	cout << "Добро пожаловать в ITStep!";
	gotoXY(15, 8);
	vector<string> st1 = { "Войти", "Зарегистрироватся" };
	int m = 1, k;
	m = choice(st1, 15, 8);
	if (m == 1)
	{
		clearScreen();
		gotoXY(15, 5); green();
		cout << "Добро пожаловать в ITStep!";
		vector<string> st = { "Преподователь", "Студент", "Администратор" };
		int v = choice(st, 15, 8);
		string l, p;
		if (v == 3)
		{
			clearScreen();
			gotoXY(15, 5); green();
			cout << "Добро пожаловать в ITStep!";
			gotoXY(15, 8); white();
			cout << "Фамилия: ";
			gotoXY(24, 8);
			cin >> l;
			gotoXY(15, 9);
			cout << "Пароль: ";
			gotoXY(24, 9);
			p = pasEntry();
			if (l == "Администратор"&&p == "111")
			{
				menuA();
			}
			else
			{
				gotoXY(15, 10); red();
				cout << "Фамилия или пароль не верны" << endl;
				Sleep(2000);
				LogIn();
			}
		}
		else if (v == 1)
		{
			clearScreen();
			gotoXY(15, 5); green();
			cout << "Добро пожаловать в ITStep!";
			gotoXY(15, 8); white();
			cout << "Фамилия: ";
			gotoXY(24, 8);
			cin >> l;
			gotoXY(15, 9);
			cout << "Пароль: ";
			gotoXY(24, 9);
			p = pasEntry();
			sch.readTeachersFromFile();
			try
			{
				Teacher tmp1 = sch.getTeacher(l);
				if (tmp1.getPassword() == p)
				{
					menuT(tmp1.getIdTeacher());
					//return tmp1.getIdTeacher();
				}
			}
			catch (...)
			{
				gotoXY(15, 10); red();
				cout << "Преподователь не найден" << endl;
				Sleep(2000);
				LogIn();
			}
		}
		else if (v == 2)
		{
			clearScreen();
			gotoXY(15, 5); green();
			cout << "Добро пожаловать в ITStep!";
			gotoXY(15, 8); white();
			cout << "Фамилия: ";
			gotoXY(24, 8);
			cin >> l;
			gotoXY(15, 9);
			cout << "Пароль: ";
			gotoXY(24, 9);
			p = pasEntry();
			sch.readStudentsFromFile();
			try
			{
				Student tmp = sch.getStudent(l);
				if (tmp.getPassword() == p)
				{
					menuS(tmp.getIdStudent());
					//return tmp.getIdStudent();
				}
			}
			catch (...)
			{
				gotoXY(15, 10); red();
				cout << "Cтудент не найден" << endl;
				Sleep(2000);
				LogIn();
			}
		}
	}
	else if (m == 2)
	{
		clearScreen();
		gotoXY(15, 5); green();
		cout << "Добро пожаловать в ITStep!";
		gotoXY(15, 8); white();
		cout << "Вы регистриретесь как: ";
		gotoXY(15, 9); yellow();
		int st = 1;
		vector<string> st2 = { "Преподователь", "Студент" };
		st = choice(st2, 15, 9);
		clearScreen();
		gotoXY(15, 5); green();
		cout << "Добро пожаловать в ITStep!";
		string fn, sn, pas, pas1;
		bool sex = 1;
		int d, m, y;
		gotoXY(15, 8); white();
		cout << "Фамилия: ";
		gotoXY(32, 8); cin >> sn;
		gotoXY(15, 9); white();
		cout << "Имя: ";
		gotoXY(32, 9); cin >> fn;
		gotoXY(15, 10); white();
		cout << "Пол: ";
		vector<string> st3 = { "Мужской", "Женский" };
		int s = choice(st3, 15, 11);
		sex = s - 1;
		gotoXY(15, 13); white();
		cout << "Дата рождения:";
		gotoXY(15, 14); white();
		cout << "Год: ";
		gotoXY(32, 14);
		y = intEntry(4, false);
		gotoXY(15, 15); white();
		cout << "Месяц (цифрами): ";
		gotoXY(32, 15);
		m = intEntry(2, true);
		if (m > 12)m = 12;
		gotoXY(15, 16); white();
		cout << "День: ";
		gotoXY(32, 16);
		d = intEntry(2, true);
		do
		{
			k = 0;
			gotoXY(15, 17); white();
			cout << "                                                                ";
			gotoXY(15, 18); white();
			cout << "                                                                ";
			gotoXY(15, 19); white();
			cout << "                                                                ";
			gotoXY(15, 17); white();
			cout << "*Введите пароль: ";
			gotoXY(15, 21); white();
			cout << "*Нажмите Tab для просмотра/скрытия пароля";
			gotoXY(32, 17); white();
			pas = pasEntry();
			gotoXY(15, 18); white();
			cout << "*Повторите: ";
			gotoXY(32, 18); white();
			pas1 = pasEntry();
			if (pas1 == pas)
			{
				gotoXY(15, 19); green();
				cout << "Пароль принят!";
				k = 1;
			}
			else
			{
				gotoXY(15, 19); red();
				cout << "Вы не верно ввели пароль";
				Sleep(1000);
			}
		} while (k == 0);

		if (st == 1)
		{
			Teacher t;
			t.setFirstName(fn);
			t.setSurname(sn);
			t.setBirthDay(d, m, y);
			t.setSex(sex);
			t.setPassword(pas);
			t.setStatus(sch.getTeacherStatus().operator[](0));
			sch.readTeachersFromFile();
			sch.addTeacher(t);
			sch.writeTeachersToFile();
		}
		else if (st == 2)
		{
			Student s;
			s.setFirstName(fn);
			s.setSurname(sn);
			s.setBirthDay(d, m, y);
			s.setSex(sex);
			s.setPassword(pas);
			s.setStatus(sch.getStudentStatus().operator[](0));
			sch.readStudentsFromFile();
			sch.addStudent(s);
			sch.writeStudentsToFile();
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

void Viewer::gotoXY(int X, int Y)
{
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hConsole, coord);
}

COORD Viewer::getPos()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD coord;

	if (GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
	{
		coord.X = csbi.dwCursorPosition.X;
		coord.Y = csbi.dwCursorPosition.Y;
		return coord;
	}
	else
	{
		coord.X = 0;
		coord.Y = 0;
		return coord;
	}
}

string Viewer::pasEntry()
{
	string str;
	COORD c;
	bool fl = false;
	int code, k;
	do
	{
		k = 1;
		code = _getch();
		if (code == 8)
		{
			c = getPos();
			gotoXY(c.X - 1, c.Y);
			cout << " ";
			gotoXY(c.X - 1, c.Y);
			str.pop_back();
		}
		if (code == 9)
		{
			if (fl == false)
				fl = true;
			else
			{
				fl = false;
			}
		}
		if (code != 13 && code != 9 && code != 8)
		{
			if (fl == false)
			{
				c = getPos();
				gotoXY(c.X - str.size(), c.Y);
				for (int i = 0; i < str.size(); i++)
					cout << "*";
				cout << "*";
			}
			else
			{
				c = getPos();
				gotoXY(c.X - str.size(), c.Y);
				cout << str;
				cout << (char)code;
			}
			str += code;
		}
		if (code == 13)
		{
			k = 0;
		}
	} while (k == 1);
	return str;
}

int Viewer::intEntry(int c, bool e)
{
	int code, rs;
	string is;
	for (int i = 0; i < c; i++)
	{
		code = _getch();
		if (code == 13 && e == true)
		{
			break;
		}
		else if (code < 48 || code > 57 && code != 13)
		{
			code = _getch();
			i--;
		}
		else if (code >= 48 || code <= 57 && code != 13)
		{
			is += code;
			cout << (char)code;
		}
	}
	rs = stoi(is);
	return rs;
}

int Viewer::choice(vector<string> ch, int x, int y)
{
	int choice = 1, x1 = x, y1 = y, k, code;
	x1 = x; y1 = y;
	for (int i = 1; i <= ch.size(); i++)
	{
		gotoXY(x1, y1);
		if (i == choice)
		{
			yellow();
			cout << "-> " + ch[i - 1];
		}
		else
		{
			white();
			cout << "   " + ch[i - 1];
		}
		y1++;
	}
	do
	{
		k = 1;
		code = _getch();
		if (code == 224 || code == 0)
			code = _getch();
		if (code == 80)
		{
			if (choice != ch.size()) choice += 1;
			else choice = 1;
			x1 = x; y1 = y;
			for (int i = 1; i <= ch.size(); i++)
			{
				gotoXY(x1, y1);
				if (i == choice)
				{
					yellow();
					cout << "-> " + ch[i - 1];
				}
				else
				{
					white();
					cout << "   " + ch[i - 1];
				}
				y1++;
			}
		}
		else if (code == 72)
		{
			if (choice != 1) choice -= 1;
			else choice = ch.size();
			x1 = x; y1 = y;
			for (int i = 1; i <= ch.size(); i++)
			{
				gotoXY(x1, y1);
				if (i == choice)
				{
					yellow();
					cout << "-> " + ch[i - 1];
				}
				else
				{
					white();
					cout << "   " + ch[i - 1];
				}
				y1++;
			}
		}
		else if (code == 13)
		{
			k = 1;
			return choice;
		}
	} while (k == 1);
}

void Viewer::menuA() //++
{	
	while (true) {
		clearScreen();
		gotoXY(15, 5);
		green();
		cout << "Добро пожаловать в консоль администратора ITStep!";
		gotoXY(15, 8);
		vector<string> vec = { "Список преподавателей", "Список студентов", "Добавить преподавателя", "Добавить студента", "Выйти" };		
		int ch = choice(vec, 15, 8);
		if (ch == 5)
		{
			LogIn();
		}
		else if (ch == 1)
		{
			showTeachers();
		}
		else if (ch == 2)
		{
			showStudents();
		}
		else if (ch == 3)
		{
			addTeacherMenu();
		}
		else if (ch == 4)
		{
			addStudentMenu();
		}

	}

}

void Viewer::addTeacherMenu() //++
{
	if (sch.getCntTeachers() == 0)
		sch.readTeachersFromFile();
	clearScreen();
	gotoXY(15, 5); green();
	cout << "Добавление нового преподавателя!";
	Teacher t;
	string firstName, surname, password; bool sex; 
	
	gotoXY(15, 8); white();
	cout << "Имя:";
	gotoXY(32, 8);
	if (cin.peek() == '\n')
		cin.get();
	getline(cin, firstName);
	t.setFirstName(firstName);
	
	gotoXY(15, 9); 
	cout << "Фамилия:";
	gotoXY(32, 9);
	if (cin.peek() == '\n')
		cin.get();
	getline(cin, surname);
	t.setSurname(surname);
	
	gotoXY(15, 10); 
	cout << "Пол:";
	vector<string> v = { "Женский", "Мужской" };
	int s = choice(v, 15, 11);
	sex = s - 1;
	t.setSex(sex);

	gotoXY(15, 13); white();
	cout << "Дата рождения:";
	gotoXY(15, 14); 
	int d, m, y;
	cout << "Год: ";
	gotoXY(32, 14);	
	cin >> y;
	gotoXY(15, 15); 
	cout << "Месяц (цифрами): ";
	gotoXY(32, 15);
	cin >> m;	
	gotoXY(15, 16);
	cout << "День: ";
	gotoXY(32, 16);
	cin >> d;
	t.setBirthDay(date_(d, m, y));

	gotoXY(15, 17);
	cout << "Пароль:";
	gotoXY(32, 17);
	if (cin.peek() == '\n')
		cin.get();
	getline(cin, password);
	t.setPassword(password);
	t.setStatus("работает");
	sch.addTeacher(t);
	sch.writeTeachersToFile();
	clearScreen();
	gotoXY(15, 8); white();
	cout << "Преподаватель " << t.getFirstName() << " " << t.getSurname() << " добавлен!";
	Sleep(1000);
}

void Viewer::addStudentMenu() //++
{
	if (sch.getCntStudents() == 0)
		sch.readStudentsFromFile();
	clearScreen();
	gotoXY(15, 5); green();
	cout << "Добавление нового студента!";	
	Student st;
	string firstName, surname, password; bool sex;

	gotoXY(15, 8); white();
	cout << "Имя:";
	gotoXY(32, 8);
	if (cin.peek() == '\n')
		cin.get();
	getline(cin, firstName);
	st.setFirstName(firstName);

	gotoXY(15, 9);
	cout << "Фамилия:";
	gotoXY(32, 9);
	if (cin.peek() == '\n')
		cin.get();
	getline(cin, surname);
	st.setSurname(surname);

	gotoXY(15, 10);
	cout << "Пол:";
	vector<string> v = { "Женский", "Мужской" };
	int s = choice(v, 15, 11);
	sex = s - 1;
	st.setSex(sex);

	gotoXY(15, 13); white();
	cout << "Дата рождения:";
	gotoXY(15, 14);
	int d, m, y;
	cout << "Год: ";
	gotoXY(32, 14);
	cin >> y;
	gotoXY(15, 15);
	cout << "Месяц (цифрами): ";
	gotoXY(32, 15);
	cin >> m;
	gotoXY(15, 16);
	cout << "День: ";
	gotoXY(32, 16);
	cin >> d;
	st.setBirthDay(date_(d, m, y));

	gotoXY(15, 17);
	cout << "Пароль:";
	gotoXY(32, 17);
	if (cin.peek() == '\n')
		cin.get();
	getline(cin, password);
	st.setPassword(password);
	st.setStatus("абитуриент");	
	
	sch.addStudent(st);
	sch.writeStudentsToFile();
	clearScreen();
	gotoXY(15, 8); white();
	cout << "Студент " << st.getFirstName() << " " << st.getSurname() << " добавлен!";
	Sleep(1000);
}

void Viewer::showTeachers() //++
{
	if (sch.getCntTeachers() == 0)
		sch.readTeachersFromFile();
	while (true) {
		clearScreen();
		gotoXY(15, 5); green();
		cout << "Список преподавателей ITStep!";
		gotoXY(15, 8); white();
		vector<string> vec;
		for (auto&i : sch.getTeachersList()) {
			string tmp = i.getFirstName() + " " + i.getSurname();
			vec.push_back(tmp);
		}
		vec.push_back("Выйти");
		int s = choice(vec, 15, 8);
		if (s == vec.size())
			break;
		teacherMenu(s);
	}
}

void Viewer::teacherMenu(int idTeacher) //++
{
	if (sch.getCntListTests() == 0)
		sch.readListTestsFromFile();
	if (sch.getCntTesters() == 0)
		sch.readTestersFromFile();
	while (true) {
		clearScreen();
		gotoXY(15, 5); green();
		cout << "Преподаватель " << sch.getTeacher(idTeacher).getFirstName() << " " << sch.getTeacher(idTeacher).getSurname();
		gotoXY(15, 8); white();
		vector<string> vec = { "Список тестов","Изменить","Выйти" };
		int ch = choice(vec, 15, 8);
		if (ch == 3)
			break;
		if (ch == 1) {
			clearScreen();
			gotoXY(15, 8); white();
			vector<string> vec2;
			vector<int> idTests;
			for (auto&i : sch.vectorListTests()) {
				if (i.getIdCreator() == idTeacher) {
					vec2.push_back(i.getTestName());
					idTests.push_back(i.getIdTest());
				}
			}
			vec2.push_back("Выйти");
			int ch2 = choice(vec2, 15, 8);
			if (ch2 == vec2.size())
				break;			
			testMenu(idTests[ch2-1]);
		}
		if (ch == 2) {
			changeTeacher(idTeacher);
		}
		Sleep(1000);
	}
}

void Viewer::changeTeacher(int idTeacher) //++
{	
	string firstName, surname, status, password;
	int day, month, year;
	while (true) {
		clearScreen();
		gotoXY(15, 5);
		cout << "Изменение полей аккаунта преподавателя " << sch.getTeacher(idTeacher).getFirstName() << " " << sch.getTeacher(idTeacher).getSurname();
		vector<string> vec = { "Имя", "Фамилия", "Дата рождения", "Статус", "Пароль", "Выйти" };
		int ch = choice(vec, 15, 8);
		if (ch == 6)
			break;
		if (ch == 1) {
			clearScreen();
			gotoXY(15, 8); white();
			cout << "Введите новое имя:";
			gotoXY(40, 8);
			if (cin.peek() == '\n')
				cin.get();
			getline(cin, firstName);
			sch.getTeacher(idTeacher).setFirstName(firstName);
			clearScreen();
			gotoXY(15, 8); white();
			cout << "Имя изменено!";
			Sleep(1000);
		}
		if (ch == 2) {
			clearScreen();
			gotoXY(15, 8); white();
			cout << "Введите новую фамилию:";
			gotoXY(45, 8);
			if (cin.peek() == '\n')
				cin.get();
			getline(cin, surname);
			sch.getTeacher(idTeacher).setSurname(surname);
			clearScreen();
			gotoXY(15, 8); white();
			cout << "Фамилия изменена!";
			Sleep(1000);
		}
		if (ch == 3) {
			clearScreen();
			gotoXY(15, 8); white();
			cout << "Введите новую дату рождения:";
			gotoXY(15, 9);
			cout << "Год:";
			gotoXY(32, 9);
			cin >> year;
			gotoXY(15, 10);
			cout << "Месяц(цифрами):";
			gotoXY(32, 10);
			cin >> month;
			gotoXY(15, 11);
			cout << "День:";
			gotoXY(32, 11);
			cin >> day;
			sch.getTeacher(idTeacher).setBirthDay(date_(day, month, year));
			clearScreen();
			gotoXY(15, 8); white();
			cout << "Дата рождения изменена!";
			Sleep(1000);
		}
		if (ch == 4) {
			clearScreen();
			gotoXY(15, 8); white();
			vector<string> vec2 = { "работает", "не работает" };
			int ch2 = choice(vec2, 15, 8);
			if (ch2 == 1) {
				sch.getTeacher(idTeacher).setStatus("работает");
			}
			if (ch2 == 2) {
				sch.getTeacher(idTeacher).setStatus("не работает");
			}
			clearScreen();
			gotoXY(15, 8); white();
			cout << "Статус изменен!";
			Sleep(1000);
		}
		if (ch == 5) {
			clearScreen();
			gotoXY(15, 8); white();
			cout << "Введите новый пароль:";
			gotoXY(40, 8);
			if (cin.peek() == '\n')
				cin.get();
			getline(cin, password);
			sch.getTeacher(idTeacher).setPassword(password);
			clearScreen();
			gotoXY(15, 8); white();
			cout << "Пароль изменен!";
			Sleep(1000);
		}
	}
	sch.writeTeachersToFile();
}

void Viewer::showStudents() //++
{
	if (sch.getCntStudents() == 0)
		sch.readStudentsFromFile();
	while (true) {
		clearScreen();
		gotoXY(15, 5); green();
		cout << "Список студентов ITStep!";
		gotoXY(15, 8); white();
		vector<string> vec;
		for (auto&i : sch.getStudentsList()) {
			string tmp = i.getFirstName() + " " + i.getSurname();
			vec.push_back(tmp);
		}
		vec.push_back("Выйти");
		int s = choice(vec, 15, 8);
		if (s == vec.size())
			break;
		studentMenu(s);
	}
}

void Viewer::studentMenu(int idStudent) //++&&
{
	if (sch.getCntListTests() == 0)
		sch.readListTestsFromFile();
	if (sch.getCntTesters() == 0)
		sch.readTestersFromFile();
	while (true) {
		clearScreen();
		gotoXY(15, 5); green();
		cout << "Студент " << sch.getStudent(idStudent).getFirstName() << " " << sch.getStudent(idStudent).getSurname();
		gotoXY(15, 8); white();
		vector<string> vec = { "Список пройденных тестов","Изменить","Выйти" };
		int ch = choice(vec, 15, 8);
		if (ch == 3)
			break;
		if (ch == 1) {
			
		}
		if (ch == 2) {
			changeStudent(idStudent);
		}
		Sleep(1000);
	}
}

void Viewer::changeStudent(int idStudent) //++
{
	string firstName, surname, status, password;
	int day, month, year;
	while (true) {
		clearScreen();
		gotoXY(15, 5);
		cout << "Изменение полей аккаунта студента " << sch.getStudent(idStudent).getFirstName() << " " << sch.getStudent(idStudent).getSurname();
		vector<string> vec = { "Имя", "Фамилия", "Дата рождения", "Статус", "Пароль", "Выйти" };
		int ch = choice(vec, 15, 8);
		if (ch == 6)
			break;
		if (ch == 1) {
			clearScreen();
			gotoXY(15, 8); white();
			cout << "Введите новое имя:";
			gotoXY(40, 8);
			if (cin.peek() == '\n')
				cin.get();
			getline(cin, firstName);
			sch.getStudent(idStudent).setFirstName(firstName);
			clearScreen();
			gotoXY(15, 8); white();
			cout << "Имя изменено!";
			Sleep(1000);
		}
		if (ch == 2) {
			clearScreen();
			gotoXY(15, 8); white();
			cout << "Введите новую фамилию:";
			gotoXY(45, 8);
			if (cin.peek() == '\n')
				cin.get();
			getline(cin, surname);
			sch.getStudent(idStudent).setSurname(surname);
			clearScreen();
			gotoXY(15, 8); white();
			cout << "Фамилия изменена!";
			Sleep(1000);
		}
		if (ch == 3) {
			clearScreen();
			gotoXY(15, 8); white();
			cout << "Введите новую дату рождения:";
			gotoXY(15, 9);
			cout << "Год:";
			gotoXY(32, 9);
			cin >> year;
			gotoXY(15, 10);
			cout << "Месяц(цифрами):";
			gotoXY(32, 10);
			cin >> month;
			gotoXY(15, 11);
			cout << "День:";
			gotoXY(32, 11);
			cin >> day;
			sch.getStudent(idStudent).setBirthDay(date_(day, month, year));
			clearScreen();
			gotoXY(15, 8); white();
			cout << "Дата рождения изменена!";
			Sleep(1000);
		}
		if (ch == 4) {
			clearScreen();
			gotoXY(15, 8); white();
			vector<string> vec2 = { "абитуриент", "студент", "выпускник" };
			int ch2 = choice(vec2, 15, 8);
			if (ch2 == 1) {
				sch.getStudent(idStudent).setStatus("абитуриент");
			}
			if (ch2 == 2) {
				sch.getStudent(idStudent).setStatus("студент");
			}
			if (ch2 == 3) {
				sch.getStudent(idStudent).setStatus("выпускник");
			}
			clearScreen();
			gotoXY(15, 8); white();
			cout << "Статус изменен!";
			Sleep(1000);
		}
		if (ch == 5) {
			clearScreen();
			gotoXY(15, 8); white();
			cout << "Введите новый пароль:";
			gotoXY(40, 8);
			if (cin.peek() == '\n')
				cin.get();
			getline(cin, password);
			sch.getStudent(idStudent).setPassword(password);
			clearScreen();
			gotoXY(15, 8); white();
			cout << "Пароль изменен!";
			Sleep(1000);
		}
	}
	sch.writeStudentsToFile();
}

void Viewer::menuT(int id) //++
{
	while (true) {
		clearScreen();
		gotoXY(15, 5);
		green();
		cout << "Добро пожаловать в консоль преподавателя ITStep!";
		gotoXY(15, 8);
		vector<string> st1 = { "Добавить тест", "Список тестов", "Выйти" };
		int m = 1;
		m = choice(st1, 15, 8);
		if (m == 3)
		{
			LogIn();
		}
		else if (m == 1)
		{
			addTest(id);
		}
		else if (m == 2)
		{
			showMyTests(id);
		}		
	}
}

void Viewer::menuS(int id)
{
	clearScreen();
	gotoXY(15, 5);
	green();
	cout << "Добро пожаловать в ITStep!";
	gotoXY(15, 8);
	vector<string> st1 = { "Пройти тест", "Пройденные тесты", "Выйти" };
	int m = 1;
	m = choice(st1, 15, 8);
	if (m == 3)
	{
		LogIn();
	}
	else if (m == 1)
	{

	}
	else if (m == 2)
	{

	}

}

void Viewer::addTest(int id) //++
{
	clearScreen();
	gotoXY(15, 5); green();
	cout << "Добавление нового теста!";
	gotoXY(15, 8); white();
	string nameTest;
	cout << "Тема теста:";
	gotoXY(32, 8);
	if (cin.peek()=='\n')
		cin.get();
	getline(cin, nameTest);
	Test t(nameTest);
	t.setIdCreator(id);		
	int cnt = 1;
	while (true) 
	{		
		while (cnt < 3) 
		{
			addQuesToTest(t);
			cnt++;
		}
		clearScreen();
		gotoXY(15, 8); white();
		cout << "Добавить еще вопрос?";
		vector<string> v = { "да", "нет" };
		int s = choice(v, 15, 9);
		if (s == 2)
			break;
		if (s == 1) 		
			addQuesToTest(t);	
	}	
	if (sch.getCntListTests() == 0) 
	{
		sch.readListTestsFromFile();
	}	
	int x = sch.getCntListTests();
	t.setIdTest(++x);
	t.setTestMaxResult(t.sumRightAnswers());

	clearScreen();
	gotoXY(15, 5); green();
	cout << "Тест создан!";
	gotoXY(15, 8); white();
	cout << "Сохранить тест в файл?";
	vector<string> v = { "да","нет" };
	int s = choice(v, 15, 9);
	if (s == 1) 
	{		
		t.writeToFile();
	}	
	ListTests lt(t.getIdTest(), t.getTestName(), t.getIdCreator());
	sch.addListTests(lt);
	sch.writeListTestsToFile();
}

void Viewer::addQuesToTest(Test& t) //++
{
	clearScreen();
	gotoXY(15, 5);
	cout << "Добавление нового вопроса!";
	gotoXY(15, 8); white();	
	string quesText;		
	cout << "Напишите вопрос:";
	gotoXY(32, 8);
	if (cin.peek() == '\n')
		cin.get();
	getline(cin, quesText);
	Question q(quesText);	
	int k = 1;	
	while (true) 
	{		
		while (k < 3) 
		{
			addAnswers(q, k);
			k++;			
		}
		clearScreen();
		gotoXY(15, 8); white();
		cout << "Добавить еще вариант ответа?";
		vector<string> v = { "да", "нет" };
		int s = choice(v, 15, 9);
		if (s == 2) {
			if (q.getCntRightAnswers()!=0)
				break;
			else
			{
				clearScreen();
				gotoXY(15, 8);
				cout << "Вы не отметили ни одного правильного ответа. Введите еще ответ";				
				Sleep(1000);
				continue;
			}
		}
		if (s == 1)
		{
			addAnswers(q, k);
			k++;			
		}		
	}	
	t.addQuestion(q);	
}

void Viewer::addAnswers(Question & q, int varNum) //++
{	
	string answer;
	clearScreen();
	gotoXY(15, 8); white();
	cout << "Вариант ответа:";
	gotoXY(32, 8);
	if (cin.peek() == '\n')
		cin.get();
	getline(cin, answer);
	gotoXY(15, 9);
	cout << "Является ли этот вариант ответа правильным?";
	vector<string> vs = { "да","нет" };
	int ss = choice(vs, 15, 10);
	if (ss == 1)
		q.addRightAnswers(varNum);
	q.addAnswerChoice(answer);
}

void Viewer::showMyTests(int id) //++
{
	if (sch.getCntListTests() == 0)
		sch.readListTestsFromFile();
	while (true) {
		clearScreen();
		gotoXY(15, 5); green();
		cout << "Список ваших тестов";
		gotoXY(15, 8); white();
		int k1 = 8;
		vector<string> vec;
		for (auto&i : sch.vectorListTests()) {
			if (i.getIdCreator() == id) {				
				vec.push_back(i.getTestName());				
			}
		}
		vec.push_back("Выйти");
		int k2 = ++k1; int testNum;
		gotoXY(15, k2);		
		int s = choice(vec, 15, k2);
		if (s == vec.size())
			break;		
		string tmp = vec[s-1];
		auto it = find_if(begin(sch.vectorListTests()), end(sch.vectorListTests()), [&tmp](ListTests&i) {
			return i.getTestName() == tmp;
		});
		testNum = it->getIdTest();
		testMenu(testNum);		
	}
}

void Viewer::testMenu(int idTest) //++
{
	while (true) {
		clearScreen();
		gotoXY(18, 8); white();
		auto it = find_if(sch.getBeginVectorListTests(), sch.getEndVectorListTests(), [&idTest](ListTests&i) {
			return i.getIdTest() == idTest;
		});
		cout << it->getIdTest();
		gotoXY(32, 8);
		cout << it->getTestName();
		gotoXY(15, 10);
		vector<string> v = { "Список студентов, прошедших тест", "Изменить тест", "Выйти" };
		int ch = choice(v, 15, 11);
		if (ch == 3)
			break;
		if (ch == 1) {
			studentsPassedTest(idTest);
		}
		if (ch == 2) {
			changeTest(idTest);
		}
	}
}

void Viewer::studentsPassedTest(int idTest) //++
{
	if (sch.getCntTesters() == 0)
		sch.readTestersFromFile();
	if (sch.getCntStudents() == 0)
		sch.readStudentsFromFile();
	clearScreen();
	gotoXY(15, 5); green();
	cout << "Список студентов, прошедших тест №" << idTest;
	gotoXY(15, 8); white();
	cout << "ID студента";
	gotoXY(32, 8);
	cout << "Фамилия студента";
	gotoXY(55, 8);
	cout << "Баллы за тест";
	gotoXY(15, 9); 
	int k = 9;
	for_each(sch.getBeginTesters(), sch.getEndTesters(), [&idTest, &k, this](Tester&i) {
		if (i.getIdTest() == idTest) {
			gotoXY(15, k);
			cout << i.getIdStudent();
			gotoXY(32, k);
			auto it = find_if(sch.getBeginStudents(), sch.getEndStudents(), [&i](Student&j) {
				return j.getIdStudent() == i.getIdStudent();
			});
			cout << it->getSurname();
			gotoXY(55, k);
			cout << i.getTestResult();
			k++;
		}
	});
	gotoXY(15, ++k);
	cout << "Вернуться в меню теста?";	
	int x = ++k;
	gotoXY(15, x);	
	vector<string> v = { "да" };
	int ch = choice(v, 15, x);
	if (ch == 1)
		return;	
}

void Viewer::changeTest(int idTest) //++
{
	Test tmp;
	tmp.readFromFile("tests\\" + to_string(idTest));
	while (true) {
		clearScreen();
		gotoXY(15, 5); green();
		cout << "Изменение теста №" << idTest;
		gotoXY(15, 8); white();		
		vector<string> v = { "изменить вопрос", "добавить вопрос", "удалить вопрос", "сохранить изменения и выйти" };
		int ch = choice(v, 15, 9);
		if (ch == 1) {
			int quesNum;
			clearScreen();			
			vector<string> vec;
			for (auto i = tmp.getBeginTestQuestions(); i != tmp.getEndTestQuestions(); i++)
			{				
				vec.push_back(i->second.getQuesText());				
			}
			vec.push_back("Выйти");
			int s = choice(vec, 15, 8);
			if (s == vec.size())
				break;			
			changeQuestion(tmp, s);
		}
		if (ch == 2) {
			clearScreen();
			gotoXY(15, 5); green();
			cout << "Добавление вопроса к тесту №" << idTest;
			gotoXY(15, 8); white();
			vector<string> v2 = { "добавить вручную", "добавить из файла" };
			int ch2 = choice(v2, 15, 8);
			if (ch2 == 1) {
				addQuesToTest(tmp);
				tmp.setTestMaxResult(tmp.sumRightAnswers());				
			}
			if (ch2 == 2) {
				string str;
				gotoXY(15, 11); white();
				cout << "Название файла, где хранится вопрос:";
				gotoXY(15, 12);
				if (cin.peek() == '\n')
					cin.get();
				getline(cin, str);
				ifstream is(str);
				while (!is.eof()) {
					string s;
					getline(is, s);
					if (s.size() != 0) {
						tmp.addQuestionFromString(s);
						tmp.setTestMaxResult(tmp.sumRightAnswers());
					}
				}
			}
			clearScreen();
			gotoXY(15, 8); yellow();
			cout << "Вопрос добавлен!";
			Sleep(1000);
		}
		if (ch == 3) {
			delQuesFromTest(tmp);
		}
		if (ch == 4) {
			break;
		}
	}
	tmp.setTestMaxResult(tmp.sumRightAnswers());
	tmp.writeToFile();	
}

void Viewer::changeQuestion(Test& t, int quesNum) //++
{
	Question q = t[quesNum];
	while (true) {
		clearScreen();
		gotoXY(15, 5); green();
		cout << "Изменение вопроса №" << quesNum;
		gotoXY(15, 8); white();
		vector<string> v = { "формулировка вопроса", "варианты ответов", "правильные ответы", "выйти" };
		int ch = choice(v, 15, 8);
		if (ch == 4)
			break;
		if (ch == 1) {
			string str;
			clearScreen();
			gotoXY(15, 5); green();
			cout << q.getQuesText();
			gotoXY(15, 8); white();
			cout << "Новая формулировка:";
			gotoXY(15, 9);
			if (cin.peek() == '\n')
				cin.get();
			getline(cin, str);
			q.setQuesText(str);
			clearScreen();
			gotoXY(15, 8);
			cout << "Текст вопроса изменен!";
			Sleep(1000);
		}
		if (ch == 2) {
			changeVarQuestion(q);
		}
		if (ch == 3) {
			changeRightAnswers(q);
		}
	}
	t.setTestMaxResult(t.sumRightAnswers());
	t[quesNum] = q;
}

void Viewer::changeVarQuestion(Question & q) //++
{
	while (true) {
		clearScreen();
		gotoXY(15, 5); green();
		cout << "Изменение вариантов ответов";
		gotoXY(15, 8); white();
		vector<string> v = { "изменить текст варианта", "добавить новый вариант", "удалить вариант", "выйти" };
		int ch = choice(v, 15, 8);
		if (ch == 4)
			break;
		if (ch == 1) {
			int varNum; string str;
			clearScreen();
			gotoXY(15, 8); white();
			vector<string> vec;
			for (auto&i : q.getAnswerChoice()) {
				vec.push_back(i);
			}
			vec.push_back("Выйти");
			int s = choice(vec, 15, 8);
			if (s == vec.size())
				break;
			int k = 8 + vec.size();
			gotoXY(15, ++k); 
			cout << "Новая формулировка:";
			gotoXY(15, ++k);
			if (cin.peek() == '\n')
				cin.get();
			getline(cin, str);
			q.getAnswerChoice()[s-1] = str;
			clearScreen();
			gotoXY(15, 8);
			cout << "Текст варианта ответа изменен!";
			Sleep(1000);			
		}
		if (ch == 2) {
			int x = q.getCntAnswerChoice();
			addAnswers(q, ++x);
			clearScreen();
			gotoXY(15, 8);
			cout << "Вариант ответа добавлен!";
			Sleep(1000);
		}
		if (ch == 3) {			
			int varNum; string str;
			clearScreen();
			gotoXY(15, 8); white();			
			vector<string> vec;
			for (auto&i : q.getAnswerChoice()) {
				vec.push_back(i);
			}
			vec.push_back("Выйти");
			int s = choice(vec, 15, 8);
			if (s == vec.size())
				break;
			q.getAnswerChoice().erase(begin(q.getAnswerChoice()) + (s - 1));
			auto it = find(begin(q.getRightAnswers()), end(q.getRightAnswers()), s);
			if (it != end(q.getRightAnswers())) {
				q.getRightAnswers().erase(it);
			}
			for_each(begin(q.getRightAnswers()), end(q.getRightAnswers()), [&s](int&i) {
				if (i > s)
					i--;
			});			
			clearScreen();
			gotoXY(15, 8);
			cout << "Вариант ответа удален!";
			Sleep(1000);
		}
	}
}

void Viewer::changeRightAnswers(Question & q) //++
{
	while (true) {
		clearScreen();
		gotoXY(15, 5); green();
		cout << "Изменение метки правильных вариантов ответов";
		gotoXY(15, 8); white();
		vector<string> v = { "добавить", "удалить", "выйти" };
		int ch = choice(v, 15, 8);
		if (ch == 3)
			break;
		if (ch == 1) {
			clearScreen();
			gotoXY(15, 8); white();			
			vector<string> vec;
			for (auto&i : q.getAnswerChoice()) {				
				vec.push_back(i);				
			}
			vec.push_back("Выйти");
			int s = choice(vec, 15, 8);
			if (s == vec.size())
				break;
			auto it = find(begin(q.getRightAnswers()), end(q.getRightAnswers()), s);
			if (it == end(q.getRightAnswers()))
				q.addRightAnswers(s);			
			clearScreen();
			gotoXY(15, 8);
			cout << "Вариант ответа помечен правильным!";
			Sleep(1000);
		}
		if (ch == 2) {
			clearScreen();
			gotoXY(15, 8); white();			
			vector<string> vec;
			for (auto&i : q.getAnswerChoice()) {				
				vec.push_back(i);				
			}
			vec.push_back("Выйти");
			int s = choice(vec, 15, 8);
			if (s == vec.size())
				break;
			auto it = find(begin(q.getRightAnswers()), end(q.getRightAnswers()), s);
			if (it != end(q.getRightAnswers()))
				q.getRightAnswers().erase(it);			
			clearScreen();
			gotoXY(15, 8);
			cout << "Отметка с варианта ответа снята!";
			Sleep(1000);			
		}
	}

}

void Viewer::delQuesFromTest(Test & t) //++
{
	while (true) {
		clearScreen();
		gotoXY(15, 5); green();
		cout << "Удаление вопроса из теста №" << t.getIdTest();
		gotoXY(15, 8); white();		
		vector<string> vec;
		for (auto i = t.getBeginTestQuestions(); i != t.getEndTestQuestions(); i++)
		{			
			vec.push_back(i->second.getQuesText());			
		}
		vec.push_back("Выйти");
		int s = choice(vec, 15, 8);
		if (s == vec.size())
			break;
		t.getTestQuestions().erase(s);
		clearScreen();
		gotoXY(15, 8);
		cout << "Вопрос удален!";
		Sleep(1000);		
	}

}
