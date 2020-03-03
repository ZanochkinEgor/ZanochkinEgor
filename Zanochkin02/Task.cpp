#include "Task.h"
#include "List.h"

int Task::getMark() const { return mark; }
void Task::setMark(int mark1) { mark = mark1; }

int Task::getCountOfDoneExercises() const { return countOfDoneExercises; }
void Task::setCountOfDoneExercises(int count_of_done_exercises1) { countOfDoneExercises = count_of_done_exercises1; }

int Task::getStudentIndex() const { return studentIndex; }
void Task::setStudentIndex(int exercises1) { studentIndex = exercises1; }

const char* Task::getMaleOrFemale() const { return maleOrFemale; }
void Task::setMaleOrFemale(const char* male_or_female1) { maleOrFemale = male_or_female1; }

int Task::getRgz() const { return rgz; }
void Task::setRgz(int rgz1) { rgz = rgz1; }

Task Create_student()
{
	Task stud;
	stud.setMark(5);
	stud.setCountOfDoneExercises(5);
	stud.setMaleOrFemale("Male");
	return stud;
}
Task Create_student2()
{
	Task stud;
	stud.setMark(2);
	stud.setCountOfDoneExercises(2);
	stud.setMaleOrFemale("Female");
	return stud;
}

Task::Task(char* male_or_female, int mark, int count_of_done_exercises, int student_index, int rgz) :mark(mark), countOfDoneExercises(count_of_done_exercises), studentIndex(student_index), maleOrFemale(male_or_female), rgz(rgz)
{
	cout << "Constructor with parameter" << endl;
}
Task::Task() : mark(0), countOfDoneExercises(0), studentIndex(0), maleOrFemale("None"), rgz(0)
{
	cout << "Default constructor" << endl;
}
Task::Task(const Task& stud) : mark(stud.mark), countOfDoneExercises(stud.countOfDoneExercises), studentIndex(stud.studentIndex), maleOrFemale(stud.maleOrFemale), rgz(stud.rgz)
{
	cout << "Copy constructor" << endl;
}
Task::~Task()
{
	cout << "Destructor Task" << endl;
}