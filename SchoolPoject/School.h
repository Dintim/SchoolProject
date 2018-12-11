#pragma once
#include "Student.h"
#include "Teacher.h"
#include "Tester.h"
#include <fstream>
class School
{	
	string schoolName;
	vector<Student> students;
	vector<Teacher> teachers;
	vector<Tester> testers; //++
	string password;
public:
	School(string schoolName);

	void setSchoolName(string schoolName);
	string getSchoolName()const { return schoolName; }
	void setPassword(string password);
	string getPassword()const { return password; }

	void addStudent(Student& st);
	void delStudent(int idStudent);
	void addTeacher(Teacher& t);
	void delTeacher(int idTeacher);
	void addTester(Tester& t); //++
	const vector<Student>& getStudentsList()const { return students; }
	const vector<Teacher>& getTeachersList()const { return teachers; }
	const Student& getStudent(int idStudent)const;
	const Teacher& getTeacher(int idTeacher) const;
	int getCntStudents()const { return students.size(); }
	int getCntTeachers()const { return teachers.size(); }
	void writeStudentsToFile(string fileName);
	void writeTeachersToFile(string fileName);
	void readStudentsFromFile(string fileName);
	void readTeachersFromFile(string fileName);
};



