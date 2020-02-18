#include "Task.h"
#include "List.h"

int Task::getMark() const { return mark; }
void Task::setMark(int mark1) { Task::mark = mark1; }

int Task::getCount_of_done_exercises() const { return count_of_done_exercises; }
void Task::setCount_of_done_exercises(int count_of_done_exercises1) { Task::count_of_done_exercises = count_of_done_exercises1; }

int Task::getStudent_index() const { return student_index; }
void Task::setStudent_index(int exercises1) { Task::student_index = exercises1; }

Task Create_student()
{
	Task stud;
	stud.setMark(5);
	stud.setCount_of_done_exercises(5);
	return stud;
}
Task Create_student2()
{
	Task stud;
	stud.setMark(2);
	stud.setCount_of_done_exercises(2);
	return stud;
}