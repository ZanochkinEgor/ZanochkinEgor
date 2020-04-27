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

Task::Task(int student_index, string name, Student age, int mark, int countOfDoneExercises, int rgz, sint day, sint month, sint year) : studentIndex(student_index), name(name), age(age), mark(mark), countOfDoneExercises(countOfDoneExercises), rgz(rgz) ,date(day,month,year) {}
Task::Task() : studentIndex(1), name("Vasya"), mark(5), countOfDoneExercises(5), rgz(5)  {}
Task::Task(const Task& stud) : studentIndex(stud.studentIndex), name(stud.name), age(stud.age), mark(stud.mark), countOfDoneExercises(stud.countOfDoneExercises), rgz(stud.rgz) {}
Task::~Task() {}