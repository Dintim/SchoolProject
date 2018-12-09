#pragma once
#include <map>
#include "Human.h"

class Student :
	public Human
{
	static int seqIdStudent;
	int idStudent;
	string status;
public:
	Student(string firstName, string surname, bool sex, date_ birthDay);
	Student() = default;
	void setIdStudent(int idStudent);	
	int getIdStudent()const { return idStudent; }
	void setStatus(string status);
	string getStatus()const { return status; }

	void info()const override;
	string convertToString() override;
	void readFromString(string& str) override;
};

