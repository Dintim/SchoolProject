#pragma once
#include "date_.h"
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

class Human abstract
{
	string firstName;
	string surname;
	bool sex;
	date_ birthDay;	
public:
	Human(string firstName, string surname, bool sex, date_ birthDay);
	void setFirstName(string firstName);
	void setSurname(string surname);
	void setSex(bool sex);
	void setBirthDay(date_ birthDay);	

	string getFirstName()const { return firstName; }
	string getSurname()const { return surname; }
	bool getSex()const { return sex; }
	date_ getBirthDay()const { return birthDay; }	

	virtual void info()const;
	virtual string convertToString();
	virtual void readFromString(string& str);
};

