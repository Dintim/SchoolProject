#include "Student.h"



Student::Student(int idStudent, string groupName, string firstName, string surname, bool sex, date_ birthDay)
	:Human(firstName, surname, sex, birthDay)
{
	this->idStudent = idStudent;
	this->groupName = groupName;
}

void Student::setIdStudent(int idStudent)
{
	this->idStudent = idStudent;
}

void Student::setGroupName(string groupName)
{
	this->groupName = groupName;
}

void Student::info() const
{
	cout << "Student's id: " << idStudent << endl;
	cout << "Group: " << groupName << endl;
	Human::info();
}

string Student::convertToString()
{
	string res = to_string(idStudent) + ";";
	res += groupName + ";";
	res += Human::convertToString();
	return res;
}
