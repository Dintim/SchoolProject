#pragma once
#include "Student.h"
#include "Teacher.h"
class School
{
	string schoolName;
	vector<Student> students;
	vector<Teacher> teachers;
public:
	School(string schoolName);

	void setSchoolName(string schoolName);
	void addStudent(Student& st);
	void delStudent(int idStudent);
	void addTeacher(Teacher& t);
	void delTeacher(int idTeacher);
	const Student& getStudent(int idStudent)const;
	const Teacher& getTeacher(int idTeacher) const;
	int getCntStudents()const { return students.size(); }
	int getCntTeachers()const { return teachers.size(); }
};

