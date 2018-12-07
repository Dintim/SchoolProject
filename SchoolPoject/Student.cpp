#include "Student.h"



Student::Student(int idStudent, string firstName, string surname, bool sex, date_ birthDay)
	:Human(firstName, surname, sex, birthDay)
{
	this->idStudent = idStudent;	
}

void Student::setIdStudent(int idStudent)
{
	this->idStudent = idStudent;
}

void Student::info() const
{
	cout << "Student's id: " << idStudent << endl;	
	Human::info();
}

string Student::convertToString()
{
	string res = to_string(idStudent) + ";";	
	res += Human::convertToString();
	return res;
}
