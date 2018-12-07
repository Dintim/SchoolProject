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
	students.push_back(st);
}

void School::delStudent(int idStudent)
{
	auto it = find_if(begin(students), end(students), [&idStudent](const Student& s) {
		return (s.getIdStudent() == idStudent);
	});
	students.erase(it);	
}

void School::addTeacher(Teacher & t)
{
	teachers.push_back(t);
}

void School::delTeacher(int idTeacher)
{
	auto it = find_if(begin(teachers), end(teachers), [&idTeacher](const Teacher& t) {
		return(t.getIdTeacher() == idTeacher);
	});
	teachers.erase(it);
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
