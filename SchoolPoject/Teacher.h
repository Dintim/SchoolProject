#pragma once
#include "Human.h"
#include "Test.h"

class Teacher :
	public Human
{	
	int idTeacher;
	string status;
	vector<int> idTests;
public:
	Teacher(string firstName, string surname, bool sex, date_ birthDay);
	Teacher() = default;
	void setIdTeacher(int idTeacher);	
	int getIdTeacher()const { return idTeacher; }
	void setStatus(string status);
	string getStatus()const { return status; }
	

	void info()const override;
	string convertToString() override;
	void readFromString(string& str) override;
};

