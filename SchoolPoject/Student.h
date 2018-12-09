#pragma once
#include <map>
#include "Human.h"
class Student :
	public Human
{
	int idStudent;
	string status;
public:
	Student(int idStudent, string firstName, string surname, bool sex, date_ birthDay);
	void setIdStudent(int idStudent);	
	int getIdStudent()const { return idStudent; }
	void setStatus(string status);
	string getStatus()const { return status; }

	void info()const override;
	string convertToString() override;
};

