#pragma once
#include "Human.h"
class Teacher :
	public Human
{
	int idTeacher;
	//vector<string> listGroups;
public:
	Teacher(int idTeacher, string firstName, string surname, bool sex, date_ birthDay);
	void setIdTeacher(int idTeacher);
	//void setListGroups(string group);
	int getIdTeacher()const { return idTeacher; }
	//vector<string>& getListGroups() { return listGroups; }

	void info()const override;
	string convertToString() override;
};

