#include "Student.h"

int Student::seqIdStudent = 0;

Student::Student(string firstName, string surname, bool sex, date_ birthDay)
	:Human(firstName, surname, sex, birthDay)
{
	this->idStudent = ++seqIdStudent;
	this->status = "учится";
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
