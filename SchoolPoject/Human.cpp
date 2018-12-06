#include "Human.h"



Human::Human(string firstName, string surname, bool sex, date_ birthDay)
{
	this->firstName = firstName;
	this->surname = surname;
	this->sex = sex;
	this->birthDay = birthDay;
}

void Human::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Human::setSurname(string surname)
{
	this->surname = surname;
}

void Human::setSex(bool sex)
{
	this->sex = sex;
}

void Human::setBirthDay(date_ birthDay)
{
	this->birthDay = birthDay;
}

void Human::info() const
{
	cout << "First name: " << firstName << endl;
	cout << "Surname: " << surname << endl;
	cout << "Sex (male or not): " << boolalpha << sex << endl;
	cout << "Birth day: " << birthDay << endl;
}

string Human::convertToString()
{
	string res = firstName + ";";
	res += surname + ";";
	res += to_string(sex) + ";";
	res += birthDay.dateToString() + ";";
	return res;
}
