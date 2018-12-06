#pragma once
#include <map>
#include "Human.h"
class Student :
	public Human
{
	int idStudent;
	string groupName;
	map<int, int> listTestResult;
public:
	Student(int idStudent, string groupName, string firstName, string surname, bool sex, date_ birthDay);
	void setIdStudent(int idStudent);
	void setGroupName(string groupName);
	void setTestResult(int idTest, int result);
	int getIdStudent()const { return idStudent; }
	string getGroupName()const { return groupName; }
	map<int, int>& getListTestResult() { return listTestResult; }
	int getTestResultById(int idTest);

	void info()const override;
	string convertToString() override;
};

