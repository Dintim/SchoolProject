#include "Teacher.h"



Teacher::Teacher(int idTeacher, string firstName, string surname, bool sex, date_ birthDay)
	:Human(firstName, surname, sex, birthDay)
{
	this->idTeacher = idTeacher;
	this->status = "работает";
}

void Teacher::setIdTeacher(int idTeacher)
{
	this->idTeacher = idTeacher;
}

void Teacher::setStatus(string status)
{
	this->status = status;
}


void Teacher::info() const
{
	cout << "Id преподавателя: " << idTeacher << endl;
	Human::info();
	cout << "Статус: "<< status << endl;
}

string Teacher::convertToString()
{
	string res = Human::convertToString();
	res += to_string(idTeacher) + ";";	
	res += status + ";";
	return res;
}

void Teacher::readFromString(string & str)
{
	Human::readFromString(str);
	vector<string> v(2);
	for (auto& i : v) {
		i = str.substr(0, str.find(';'));
		str = str.substr(str.find(';') + 1);
	}
	this->idTeacher = stoi(v[0]);
	this->status = v[1];
}
