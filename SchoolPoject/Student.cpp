#include "Student.h"



Student::Student(int idStudent, string firstName, string surname, bool sex, date_ birthDay)
	:Human(firstName, surname, sex, birthDay)
{
	this->idStudent = idStudent;
	this->status = "������";
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
	cout << "Id ��������: " << idStudent << endl;	
	Human::info();
	cout << "������: " << status << endl;
}

string Student::convertToString()
{
	string res = to_string(idStudent) + ";";	
	res += Human::convertToString();
	res += status + ";";
	return res;
}
