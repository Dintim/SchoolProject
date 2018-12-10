#include "Teacher.h"



Teacher::Teacher(string firstName, string surname, bool sex, date_ birthDay)
	:Human(firstName, surname, sex, birthDay)
{	
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
	string res = to_string(idTeacher) + ';';	
	res += Human::convertToString();
	res += status + ';';
	return res;
}

void Teacher::readFromString(string & str)
{
	this->idTeacher = stoi(str.substr(0, str.find(';')));
	str = str = str.substr(str.find(';') + 1);
	Human::readFromString(str);
	this->status = str.substr(0, str.find(';'));	
}
