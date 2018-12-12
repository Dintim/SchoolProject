#pragma once
#include "Student.h"
#include "Teacher.h"
#include "Tester.h"
#include "ListTests.h"
#include <fstream>
class School
{	
	string schoolName;
	vector<Student> students;
	vector<Teacher> teachers;
	vector<Tester> testers; //++
	vector<ListTests> listTests; //++
	vector<string> studentStatus = { "абитуриент", "студент", "выпускник" }; //++
	vector<string> teacherStatus = { "работает", "не работает" }; //++
public:
	School(string schoolName);

	void setSchoolName(string schoolName);
	string getSchoolName()const { return schoolName; }	

	void addStudent(Student& st);
	void delStudent(int idStudent);
	void addTeacher(Teacher& t);
	void delTeacher(int idTeacher);
	void addTester(Tester& t); //++
	void addListTests(ListTests& lt); //++
	const vector<Student>& getStudentsList()const { return students; }
	const vector<Teacher>& getTeachersList()const { return teachers; }
	const Student& getStudent(int idStudent)const;
	const Student& getStudent(string surname)const;
	const Teacher& getTeacher(int idTeacher) const;
	const Teacher& getTeacher(string surname) const;
	int getCntStudents()const { return students.size(); }
	int getCntTeachers()const { return teachers.size(); }
	void writeStudentsToFile(); //++
	void writeTeachersToFile(); //++
	void readStudentsFromFile(); //++
	void readTeachersFromFile(); //++
};



