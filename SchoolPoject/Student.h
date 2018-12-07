#pragma once
#include <map>
#include "Human.h"
class Student :
	public Human
{
	int idStudent;	
public:
	Student(int idStudent, string firstName, string surname, bool sex, date_ birthDay);
	void setIdStudent(int idStudent);	
	int getIdStudent()const { return idStudent; }	

	void info()const override;
	string convertToString() override;
};

