#pragma once
#include "Human.h"
class Student :
	public Human
{
	int idStudent;
	string groupName;
public:
	Student(int idStudent, string groupName, string firstName, string surname, bool sex, date_ birthDay);
	void setIdStudent(int idStudent);
	void setGroupName(string groupName);
	int getIdStudent()const { return idStudent; }
	string getGroupName()const { return groupName; }

	void info()const override;
	string convertToString() override;
};

