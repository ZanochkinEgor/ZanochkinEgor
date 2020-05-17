#include "Inheritor.h"

string Inheritor::getInfo() const
{
	stringstream temp;
	temp.setf(std::ios::left);
	temp << setw(7) << studentIndex << setw(10) << name << setw(8) << mark << setw(8) << countOfDoneExercises << setw(8) << rgz << rgzForTeacher;
	return temp.str();
}

bool Inheritor::operator==(const int id) const
{
	return this->studentIndex == id;
}

Inheritor::Inheritor() : Task(), rgzForTeacher(generateRgzForTeacher()) {}
Inheritor::Inheritor(int studentIndex, string name, int mark, int countOfDoneExercises, int rgz, int rgzForTeacher) : Task(studentIndex, name, mark, countOfDoneExercises, rgz), rgzForTeacher(rgzForTeacher) {}
Inheritor::Inheritor(const Inheritor& object) : Task(object), rgzForTeacher(object.rgzForTeacher) {}
Inheritor::~Inheritor() {}