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

void Teacher::setListGroups(string group)
{
	listGroups.push_back(group);
}

void Teacher::info() const
{
	cout << "Teacher's id: " << idTeacher << endl;
	cout << "List of groups: ";
	for (auto &i : listGroups) {
		cout << i << "\t";
	}
	cout << endl;
	Human::info();
}

string Teacher::convertToString()
{
	string res = to_string(idTeacher) + ";";
	for (auto &i : listGroups) {
		res += i + "#";
	}
	res += ";";
	res += Human::convertToString();
	return res;
}
