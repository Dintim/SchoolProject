#include "Student.h"



Student::Student(string firstName, string surname, bool sex, date_ birthDay, string password)
	:Human(firstName, surname, sex, birthDay, password)
{	
	this->status = "студент";
}

void Student::setIdStudent(int idStudent)
{
	this->idStudent = idStudent;
}

void Student::setStatus(string status)
{
	this->status = status;
}

void Student::info() const
{
	cout << "Id студента: " << idStudent << endl;	
	Human::info();
	cout << "Статус: " << status << endl;
}

string Student::convertToString()
{
	string res = to_string(idStudent) + ';';	
	res += Human::convertToString();
	res += status + ';';
	return res;
}

void Student::readFromString(string & str)
{
	this->idStudent = stoi(str.substr(0, str.find(';')));
	str = str.substr(str.find(';') + 1);
	Human::readFromString(str);
	this->status = str.substr(0, str.find(';'));
}
