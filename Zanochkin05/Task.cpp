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

sint Task::getDay() const { return date.getDay(); }
void Task::setDay(sint day1) { date.setDay(day1); }

sint Task::getMonth() const { return date.getMonth(); }
void Task::setMonth(sint month1) { date.setMonth(month1); }

sint Task::getYear() const { return date.getYear();; }
void Task::setYear(sint year1) { date.setYear(year1); }

int Task::getAge() const { return age.getAge(); }
void Task::setAge(const int age1) { age.setAge(age1); }

Task CreateStudent()
{
	Task stud;
	stud.setMark(5);
	stud.setCountOfDoneExercises(5);
	stud.setName("Petrova Katya");
	stud.setDay(5);
	stud.setMonth(5);
	stud.setYear(5555);
	stud.setAge(5);
	return stud;
}
Task CreateStudent2()
{
	Task stud;
	stud.setMark(2);
	stud.setCountOfDoneExercises(2);
	stud.setName("Ivanov Petya");
	stud.setDay(2);
	stud.setMonth(2);
	stud.setYear(2222);
	stud.setAge(2);
	return stud;
}

Task::Task(int student_index, string name, int age, int mark, int countOfDoneExercises, int rgz, sint day, sint month, sint year) : studentIndex(student_index), name(name), age(age), mark(mark), countOfDoneExercises(countOfDoneExercises), rgz(rgz), date(day, month, year)
{
	cout << "Constructor with parameter" << endl;
}
Task::Task() : studentIndex(0), name(" "), age(0), mark(0), countOfDoneExercises(0), rgz(0), date(0, 0, 0000)
{
	cout << "Default constructor" << endl;
}
Task::Task(const Task& stud) : studentIndex(stud.studentIndex), name(stud.name), age(stud.age), mark(stud.mark), countOfDoneExercises(stud.countOfDoneExercises), rgz(stud.rgz),date(stud.date)
{
	cout << "Copy constructor" << endl;
}
Task::~Task()
{
	cout << "Destructor Task" << endl;

}