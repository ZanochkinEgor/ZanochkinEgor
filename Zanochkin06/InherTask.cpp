#include "InherTask.h"

int Inheritor::getRgzForTeacher() const { return rgzForTeacher; }
void Inheritor::setRgzForTeacher(int rgz1) { rgzForTeacher = rgz1; }

Inheritor InherCreateStudent()
{
	Inheritor stud;
	stud.setMark(5);
	stud.setCountOfDoneExercises(5);
	stud.setName("Petrova Katya");
	stud.setDay(5);
	stud.setMonth(5);
	stud.setYear(5555);
	stud.setAge(5);
	return stud;
}
Inheritor InherCreateStudent2()
{
	Inheritor stud;
	stud.setMark(2);
	stud.setCountOfDoneExercises(2);
	stud.setName("Ivanov Petya");
	stud.setDay(2);
	stud.setMonth(2);
	stud.setYear(2222);
	stud.setAge(2);
	return stud;
}

int Inheritor::InherGenerateID()
{
	static int id = 1;
	return id++;
}

int Inheritor::InherGenerateRGZ()
{
	static int RGZ = 5;
	return RGZ++;
}

int Inheritor::InherGenerateRGZForTeacher()
{
	static int rgzForTeacher = 5;
	return rgzForTeacher++;
}

Inheritor::Inheritor() : Task(), rgzForTeacher(0) {}
Inheritor::Inheritor(int student_index, string name, int age, int mark, int countOfDoneExercises, int rgz, sint day, sint month, sint year,int rgzForTeacher) : Task(student_index, name, age, mark, countOfDoneExercises, rgz, day, month, year), rgzForTeacher(rgzForTeacher) {}
Inheritor::Inheritor(const Inheritor& object) : Task(object), rgzForTeacher(object.rgzForTeacher) {}
Inheritor::~Inheritor() {}
