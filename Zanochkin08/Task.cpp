#include "Task.h"
#include "List.h"

int Task::getMark() const { return mark; }
int Task::getCountOfDoneExercises() const { return countOfDoneExercises; }
int Task::getStudentIndex() const { return studentIndex; }
int Task::getRgz() const { return rgz; }
string Task::getName() const { return name; }
sint Task::getDay() const { return date.getDay(); }
sint Task::getMonth() const { return date.getMonth(); }
sint Task::getYear() const { return date.getYear();; }
int Task::getAge() const { return age.getAge(); }

Task::Task(int student_index, string name, Student age, int mark, int countOfDoneExercises, int rgz, sint day, sint month, sint year) : studentIndex(student_index), name(name), age(age), mark(mark), countOfDoneExercises(countOfDoneExercises), rgz(rgz), date(day, month, year) {}
Task::Task() : studentIndex(1), name("Vasya"), mark(5), countOfDoneExercises(5), rgz(5) {}
Task::Task(const Task& stud) : studentIndex(stud.studentIndex), name(stud.name), age(stud.age), mark(stud.mark), countOfDoneExercises(stud.countOfDoneExercises), rgz(stud.rgz) {}
Task::~Task() {}

ostream& operator<< (ostream& output, const Task& obj)
{
	output << obj.getInfo();
	return output;
}

istream& operator>> (istream& input, Task& obj)
{
	obj.input(input);
	return input;
}

bool Task::operator==(const string name) const
{
	return this->name == name;
}

Task& Task::operator= (Task& temp)
{
	if (this == &temp) 
		return *this;
	int studentIndex = temp.studentIndex;
	string name = temp.name;
	Student age = temp.age;
	int mark = temp.mark;
	int countOfDoneExercises = temp.countOfDoneExercises;
	int rgz = temp.rgz;
	Date date = temp.date;
	return *this;
}