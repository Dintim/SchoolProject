#include "School.h"



School::School(string schoolName)
{
	this->schoolName = schoolName;
}

void School::setSchoolName(string schoolName)
{
	this->schoolName = schoolName;
}


void School::addStudent(Student & st)
{
	int s = getCntStudents();
	st.setIdStudent(++s);
	students.push_back(st);	
}

void School::delStudent(int idStudent)
{
	auto it = find_if(begin(students), end(students), [&idStudent](const Student& s) {
		return (s.getIdStudent() == idStudent);
	});
	if (it != students.end())
		students.erase(it);
	else
		return;
}

void School::addTeacher(Teacher & t)
{
	int s = getCntTeachers();
	t.setIdTeacher(++s);
	teachers.push_back(t);
}

void School::delTeacher(int idTeacher)
{
	auto it = find_if(begin(teachers), end(teachers), [&idTeacher](const Teacher& t) {
		return(t.getIdTeacher() == idTeacher);
	});
	if (it != teachers.end())
		teachers.erase(it);
	else
		return;
}

void School::addTester(Tester & t) 
{
	testers.push_back(t);
}

void School::addListTests(ListTests & lt) 
{
	listTests.push_back(lt);
}

const Student & School::getStudent(int idStudent) const
{
	for (size_t i = 0; i < students.size(); i++)
	{
		if (students[i].getIdStudent() == idStudent)
			return students[i];
	}
	Student st;
	return st;
}

const Student & School::getStudent(string surname) const
{
	for (size_t i = 0; i < students.size(); i++)
	{
		if (students[i].getSurname() == surname)
			return students[i];
	}
	Student st;
	return st;
}

const Teacher & School::getTeacher(int idTeacher) const
{
	for (size_t i = 0; i < teachers.size(); i++)
	{
		if (teachers[i].getIdTeacher() == idTeacher)
			return teachers[i];
	}
	Teacher t;
	return t;
}

const Teacher & School::getTeacher(string surname) const
{
	for (size_t i = 0; i < teachers.size(); i++)
	{
		if (teachers[i].getSurname() == surname)
			return teachers[i];
	}
	Teacher t;
	return t;
}

void School::writeStudentsToFile()
{
	ofstream os("students");
	string s;
	for (auto i = begin(students); i != end(students); i++)
	{
		s = i->convertToString();
		os << s;
		if (i != end(students) - 1)
			os << endl;
	}
	os.close();
}

void School::writeTeachersToFile() 
{
	ofstream os("teachers");
	string s;
	for (auto i = begin(teachers); i != end(teachers); i++)
	{
		s = i->convertToString();
		os << s;
		if (i != end(teachers) - 1)
			os << endl;
	}
	os.close();
}

void School::writeTestersToFile() 
{
	ofstream os("testers");
	string s;
	for (auto i = begin(testers); i != end(testers); i++)
	{
		s = i->convertToString();
		os << s;
		if (i != end(testers) - 1)
			os << endl;
	}
	os.close();
}

void School::writeListTestsToFile()
{
	ofstream os("listTest");
	string s;	
	for (auto i = begin(listTests); i != end(listTests); i++)
	{
		s = i->convertToString();
		os << s;
		if (i != end(listTests) - 1)
			os << endl;
	}
	os.close();
}

void School::readStudentsFromFile() 
{
	ifstream is("students");
	string s;
	while (!is.eof()) {
		getline(is, s);
		Student st;
		st.readFromString(s);
		addStudent(st);		
	}	
	is.close();
}

void School::readTeachersFromFile() 
{
	ifstream is("teachers");
	string s;
	while (!is.eof()) {
		getline(is, s);
		Teacher t;
		t.readFromString(s);
		addTeacher(t);		
	}
	is.close();
}

void School::readTestersFromFile() 
{
	ifstream is("testers");
	string s;
	while (!is.eof()) {
		getline(is, s);
		Tester t;
		t.readFromString(s);
		addTester(t);
	}
	is.close();
}

void School::readListTestsFromFile() 
{
	ifstream is("listTest");
	string s;
	while (!is.eof()) {
		getline(is, s);
		ListTests lt;
		lt.readFromString(s);
		addListTests(lt);
	}
	is.close();
}
