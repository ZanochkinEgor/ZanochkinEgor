#include "Inheritor2.h"

string Inheritor2::getMaleFemale() const { return maleFemale; }
void Inheritor2::setMaleFemale(int rgz1) { maleFemale = rgz1; }

stringstream Inheritor2::getStr() const
{
	stringstream temp;

	temp << " " << studentIndex << " " << name << " " << age.getAge() << " " << mark << " " << countOfDoneExercises
		<< " " << rgz << " " << date.getDay() << " " << date.getMonth()
		<< " " << date.getYear() << " " << maleFemale;

	return temp;
}

string Inheritor2::getInfo() const
{
	stringstream temp;

	temp << std::left << setw(6) << studentIndex << setw(18) << name << setw(8) << age.getAge()
		<< setw(10) << mark << setw(13) << countOfDoneExercises << setw(10) << rgz
		<< setw(3) << date.getDay() << setw(3) << date.getMonth()
		<< setw(13) << date.getYear() << maleFemale << endl;

	return temp.str();
}

void Inheritor2::input(istream& input)
{
	input >> studentIndex >> name >> age >> mark >> countOfDoneExercises >> rgz >> date >> maleFemale;
}

Inheritor2::Inheritor2() : Task(), maleFemale("Male") {}
Inheritor2::Inheritor2(int studentIndex, string name, Student age, int mark, int countOfDoneExercises, int rgz, sint day, sint month, sint year, string maleFemale) : Task(studentIndex, name, age, mark, countOfDoneExercises, rgz, day, month, year), maleFemale(maleFemale) {}
Inheritor2::Inheritor2(const Inheritor2& object) : Task(object), maleFemale(object.maleFemale) {}
Inheritor2::~Inheritor2() {}

Inheritor2& Inheritor2::operator=(Inheritor2& temp)
{
	if (this == &temp) 
		return *this;
	Task::operator=(temp);
	string maleFemale = temp.maleFemale;
	return *this;
}

bool Inheritor2::operator==(const string name) const
{
	return this->name == name;
}