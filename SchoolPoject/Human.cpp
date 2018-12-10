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

void Human::setPassword(string password)
{
	this->password = password;
}

void Human::info() const
{
	cout << "Имя: " << firstName << endl;
	cout << "Фамилия: " << surname << endl;
	cout << "Пол (1-муж, 0-жен): " << sex << endl;
	cout << "Дата рождения: " << birthDay;	
}

string Human::convertToString()
{
	string res = firstName + ';';
	res += surname + ';';
	res += to_string(sex) + ';';
	res += birthDay.dateToString() + ';';
	res += password + ';';
	return res;
}

void Human::readFromString(string & str)
{
	vector<string> v(5);
	for (auto&i : v) {
		i = str.substr(0, str.find(';'));
		str = str.substr(str.find(';') + 1);
	}
	this->firstName = v[0];
	this->surname = v[1];
	this->sex = stoi(v[2]);
	this->birthDay = date_(v[3]);
	this->password = v[4];
}
