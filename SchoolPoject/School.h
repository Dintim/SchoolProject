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
	void addTester(Tester& t); 
	void addListTests(ListTests& lt); 
	const vector<Student>& getStudentsList()const { return students; }
	const vector<Teacher>& getTeachersList()const { return teachers; }
	const vector<ListTests>& getListTests()const { return listTests; }
	Student& getStudent(int idStudent); //++
	Student& getStudent(string surname); //++
	Teacher& getTeacher(int idTeacher); //++
	const Teacher& getTeacher(string surname) const;
	int getCntStudents()const { return students.size(); }
	int getCntTeachers()const { return teachers.size(); }
	const vector<string>& getStudentStatus()const { return studentStatus; } 
	const vector<string>& getTeacherStatus()const { return teacherStatus; }
	vector<Tester>& getTesters() { return testers; }//+++
	void getFinishTestName(int idStudent, vector<string>& tn);//+++
	void getFinishTestRes(int idStudent, vector<int>& tr);//+++
	void getFinishTestMaxRes(int idStudent, vector<int>& tmr);//+++
	
	void writeStudentsToFile(); 
	void writeTeachersToFile(); 
	void writeTestersToFile(); 
	void writeListTestsToFile(); 

	void readStudentsFromFile(); 
	void readTeachersFromFile(); 
	void readTestersFromFile(); 
	void readListTestsFromFile(); 

	int getCntTesters()const { return testers.size(); } //++
	int getCntListTests()const { return listTests.size(); } //++	
	const ListTests& getListTests(int idCreator)const; //++
	vector<ListTests>& vectorListTests() { return listTests; } //++
	vector<Tester>& vectorTesters() { return testers; } //++
	auto getBeginVectorListTests() { return begin(listTests); } //++
	auto getEndVectorListTests() { return end(listTests); } //++
	auto getBeginTesters() { return begin(testers); } //++
	auto getEndTesters() { return end(testers); } //++
	auto getBeginStudents() { return begin(students); } //++
	auto getEndStudents() { return end(students); } //++
};



