#include "Inheritor2.h"

string Inheritor2::getMaleFemale() const { return maleFemale; }
void Inheritor2::setMaleFemale(int rgz1) { maleFemale = rgz1; }

void Inheritor2::print() const
{
	cout << setw(6) << studentIndex;
	cout << setw(18) << name;
	cout << setw(8) << age.getAge();
	cout << setw(13) << mark;
	cout << setw(13) << countOfDoneExercises;
	cout << setw(10) << rgz;
	cout << setw(3) << date.getDay() << setw(3) << date.getMonth() << setw(12) << date.getYear();
	cout << maleFemale << endl;
}
stringstream Inheritor2::getStr() const
{
	stringstream temp;

	temp << " " << studentIndex << " " << name << " " << age.getAge() << " " << mark << " " << countOfDoneExercises
		 << " " << rgz << " " << date.getDay() << " " << date.getMonth()
		 << " " << date.getYear() << " " << maleFemale;

	return temp;
}
void Inheritor2::writeInFile(ofstream& el)
{
	el << std::left << setw(6) << studentIndex << setw(18) << name << setw(8) << age.getAge()
		<< setw(10) << mark << setw(13) << countOfDoneExercises << setw(12) << rgz
		<< setw(3) << date.getDay() << setw(3) << date.getMonth()
		<< setw(10) << date.getYear() << maleFemale << endl;
}

Inheritor2::Inheritor2() : Task(), maleFemale("Male") {}
Inheritor2::Inheritor2(int studentIndex, string name, Student age, int mark, int countOfDoneExercises, int rgz, sint day, sint month, sint year, string maleFemale) : Task(studentIndex, name, age, mark, countOfDoneExercises, rgz, day, month, year), maleFemale(maleFemale) {}
Inheritor2::Inheritor2(const Inheritor2& object) : Task(object), maleFemale(object.maleFemale) {}
Inheritor2::~Inheritor2() {}
