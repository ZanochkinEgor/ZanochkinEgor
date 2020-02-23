#include "Task.h"
#include "List.h"

int Task::getMark() const { return mark; }
void Task::setMark(int mark1) { mark = mark1; }

int Task::getCount_of_done_exercises() const { return count_of_done_exercises; }
void Task::setCount_of_done_exercises(int count_of_done_exercises1) { count_of_done_exercises = count_of_done_exercises1; }

int Task::getStudent_index() const { return student_index; }
void Task::setStudent_index(int exercises1) { student_index = exercises1; }

const char* Task::getMale_or_female() const { return male_or_female; }
void Task::setMale_or_female(const char* male_or_female1) { male_or_female = male_or_female1; } 

int Task::getRgz() const { return rgz; }
void Task::setRgz(int rgz1) { rgz = rgz1; }

Task Create_student()
{
	Task stud;
	stud.setMark(5);
	stud.setCount_of_done_exercises(5);
	stud.setMale_or_female("Male");
	stud.setRgz(5);
	return stud;
}
Task Create_student2()
{
	Task stud;
	stud.setMark(2);
	stud.setCount_of_done_exercises(2);
	stud.setMale_or_female("Female");
	stud.setRgz(2);
	return stud;
}

Task::Task(char* male_or_female, int mark, int count_of_done_exercises, int student_index,int rgz):mark(mark), count_of_done_exercises(count_of_done_exercises), student_index(student_index), male_or_female(male_or_female),rgz(rgz)
{
	cout << "Constructor with parameter" << endl;
}
Task::Task():mark(0), count_of_done_exercises(0), student_index(0), male_or_female("None"),rgz(0)
{ 
	cout << "Default constructor" << endl; 
}
Task::Task(const Task& stud):mark(stud.mark), count_of_done_exercises(stud.count_of_done_exercises), student_index(stud.student_index), male_or_female(stud.male_or_female),rgz(stud.rgz)
{
	cout << "Copy constructor" << endl;
}
Task::~Task()
{
	cout << "Destructor" << endl;
}