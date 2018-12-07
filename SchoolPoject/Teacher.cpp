#include "Teacher.h"



Teacher::Teacher(int idTeacher, string firstName, string surname, bool sex, date_ birthDay)
	:Human(firstName, surname, sex, birthDay)
{
	this->idTeacher = idTeacher;
}

void Teacher::setIdTeacher(int idTeacher)
{
	this->idTeacher = idTeacher;
}

void Teacher::info() const
{
	cout << "Teacher's id: " << idTeacher << endl;	
	Human::info();
}

string Teacher::convertToString()
{
	string res = to_string(idTeacher) + ";";	
	res += Human::convertToString();
	return res;
}
