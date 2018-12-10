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
	string password;
public:
	Human(string firstName, string surname, bool sex, date_ birthDay);
	Human() = default;
	void setFirstName(string firstName);
	void setSurname(string surname);
	void setSex(bool sex);
	void setBirthDay(date_ birthDay);
	void setPassword(string password);

	string getFirstName()const { return firstName; }
	string getSurname()const { return surname; }
	bool getSex()const { return sex; }
	date_ getBirthDay()const { return birthDay; }
	string getPassword()const { return password; }

	virtual void info()const;
	virtual string convertToString();
	virtual void readFromString(string& str);
};

