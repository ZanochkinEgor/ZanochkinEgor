#include "Inheritor1.h"

int Inheritor::getRgzForTeacher() const { return rgzForTeacher; }
void Inheritor::setRgzForTeacher(int rgz1) { rgzForTeacher = rgz1; }

void Inheritor::print() const
{
	cout << setw(6) << studentIndex;
	cout << setw(18) << name;
	cout << setw(8) << age.getAge();
	cout << setw(13) << mark;
	cout << setw(13) << countOfDoneExercises;
	cout << setw(10) << rgz;
	cout << setw(3) << date.getDay() << setw(3) << date.getMonth() << setw(12) << date.getYear();
	cout << rgzForTeacher << endl;
}
stringstream Inheritor::getStr() const
{
	stringstream temp;

	temp << " " << studentIndex << " " << name << " " << age.getAge() << " " << mark << " " << countOfDoneExercises
		 << " " << rgz << " " << date.getDay() << " " << date.getMonth()
		 << " " << date.getYear() << " " << rgzForTeacher;

	return temp;
}
void Inheritor::writeInFile(ofstream& el)
{
	el << std::left << setw(6) << studentIndex << setw(18) << name << setw(8) << age.getAge()
		<< setw(10) << mark << setw(13) << countOfDoneExercises << setw(12) << rgz
		<< setw(3) << date.getDay() << setw(3) << date.getMonth()
		<< setw(10) << date.getYear() << rgzForTeacher << endl;
}

Inheritor::Inheritor() : Task(), rgzForTeacher(0) {}
Inheritor::Inheritor(int studentIndex, string name, Student age, int mark, int countOfDoneExercises, int rgz, sint day, sint month, sint year, int rgzForTeacher) : Task(studentIndex, name, age, mark, countOfDoneExercises, rgz, day, month, year), rgzForTeacher(rgzForTeacher) {}
Inheritor::Inheritor(const Inheritor& object) : Task(object), rgzForTeacher(object.rgzForTeacher) {}
Inheritor::~Inheritor() {}
