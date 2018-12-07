#pragma once
#include "Human.h"
class Teacher :
	public Human
{
	int idTeacher;	
public:
	Teacher(int idTeacher, string firstName, string surname, bool sex, date_ birthDay);
	void setIdTeacher(int idTeacher);	
	int getIdTeacher()const { return idTeacher; }	

	void info()const override;
	string convertToString() override;
};

