#include "Inheritor1.h"

int Inheritor::getRgzForTeacher() const { return rgzForTeacher; }
void Inheritor::setRgzForTeacher(int rgz1) { rgzForTeacher = rgz1; }

stringstream Inheritor::getStr() const
{
	stringstream temp;

	temp << " " << studentIndex << " " << name << " " << age.getAge() << " " << mark << " " << countOfDoneExercises
		<< " " << rgz << " " << date.getDay() << " " << date.getMonth()
		<< " " << date.getYear() << " " << rgzForTeacher;

	return temp;
}

string Inheritor::getInfo() const
{
	stringstream temp;

	temp << std::left << setw(6) << studentIndex << setw(18) << name << setw(8) << age.getAge()
		<< setw(10) << mark << setw(13) << countOfDoneExercises << setw(10) << rgz
		<< setw(3) << date.getDay() << setw(3) << date.getMonth()
		<< setw(13) << date.getYear() << rgzForTeacher << endl;

	return temp.str();
}

void Inheritor::input(istream& input)
{
	input >> studentIndex >> name >> age >> mark >> countOfDoneExercises >> rgz >> date >> rgzForTeacher;
}

Inheritor::Inheritor() : Task(), rgzForTeacher(0) {}
Inheritor::Inheritor(int studentIndex, string name, Student age, int mark, int countOfDoneExercises, int rgz, sint day, sint month, sint year, int rgzForTeacher) : Task(studentIndex, name, age, mark, countOfDoneExercises, rgz, day, month, year), rgzForTeacher(rgzForTeacher) {}
Inheritor::Inheritor(const Inheritor& object) : Task(object), rgzForTeacher(object.rgzForTeacher) {}
Inheritor::~Inheritor() {}

Inheritor& Inheritor::operator=(Inheritor& temp)
{
	if (this == &temp) 
		return *this;
	Task::operator=(temp);
	int rgzForTeacher = temp.rgzForTeacher;
	return *this;
}
bool Inheritor::operator==(const string name) const
{
	return this->name == name;
}