#include "School.h"



School::School(string schoolName)
{
	this->schoolName = schoolName;
}

void School::setSchoolName(string schoolName)
{
	this->schoolName = schoolName;
}

void School::setPassword(string password)
{
	this->password = password;
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

const Student & School::getStudent(int idStudent) const
{
	for (size_t i = 0; i < students.size(); i++)
	{
		if (students[i].getIdStudent() == idStudent)
			return students[i];
	}
}

const Teacher & School::getTeacher(int idTeacher) const
{	
	/*auto it = find_if(begin(teachers), end(teachers), [&idTeacher](const Teacher& t) {
		return (t.getIdTeacher() == idTeacher);
	});
	return (begin(teachers)+it);*/

	for (size_t i = 0; i < teachers.size(); i++)
	{
		if (teachers[i].getIdTeacher() == idTeacher)
			return teachers[i];
	}
}

void School::writeStudentsToFile(string fileName)
{
	ofstream os(fileName);
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

void School::writeTeachersToFile(string fileName)
{
	ofstream os(fileName);
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

void School::readStudentsFromFile(string fileName)
{
	ifstream is(fileName);
	string s;
	while (!is.eof()) {
		getline(is, s);
		Student st;
		st.readFromString(s);
		addStudent(st);		
	}	
	is.close();
}

void School::readTeachersFromFile(string fileName)
{
	ifstream is(fileName);
	string s;
	while (!is.eof()) {
		getline(is, s);
		Teacher t;
		t.readFromString(s);
		addTeacher(t);		
	}
	is.close();
}
