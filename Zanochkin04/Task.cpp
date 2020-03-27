#include "Task.h"
#include "List.h"

int Task::getMark() const { return mark; }
void Task::setMark(int mark1) { mark = mark1; }

int Task::getCountOfDoneExercises() const { return countOfDoneExercises; }
void Task::setCountOfDoneExercises(int count_of_done_exercises1) { countOfDoneExercises = count_of_done_exercises1; }

int Task::getStudentIndex() const { return studentIndex; }
void Task::setStudentIndex(int exercises1) { studentIndex = exercises1; }

int Task::getRgz() const { return rgz; }
void Task::setRgz(int rgz1) { rgz = rgz1; }

string Task::getName() const { return name; }
void Task::setName(string name1) { name = name1; }

Task CreateStudent()
{
	Task stud;
	stud.setMark(5);
	stud.setCountOfDoneExercises(5);
	stud.setName("Petrova Katya");
	return stud;
}
Task CreateStudent2()
{
	Task stud;
	stud.setMark(2);
	stud.setCountOfDoneExercises(2);
	stud.setName("Ivanov Petya");
	return stud;
}

Task::Task(int student_index, string name, int mark, int countOfDoneExercises, int rgz) : studentIndex(student_index), name(name), mark(mark), countOfDoneExercises(countOfDoneExercises), rgz(rgz)
{
	cout << "Constructor with parameter" << endl;
}
Task::Task() : studentIndex(0), name(" "), mark(0), countOfDoneExercises(0), rgz(0)
{
	cout << "Default constructor" << endl;
}
Task::Task(const Task& stud) : studentIndex(stud.studentIndex), name(stud.name), mark(stud.mark), countOfDoneExercises(stud.countOfDoneExercises), rgz(stud.rgz)
{
	cout << "Copy constructor" << endl;
}
Task::~Task()
{
	cout << "Destructor Task" << endl;
}