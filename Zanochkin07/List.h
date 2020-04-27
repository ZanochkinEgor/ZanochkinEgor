#pragma once
#include "Task.h"
#include "Inheritor1.h"
#include "Inheritor2.h"

class List
{
private:
	int listSize;
	Task** studentList;
public:
	int getListSize() const;
	Task** addStudent(Task*, Task**);
	Task* newStudent(Student*, int);
	Task** deleteStudent(int, Task**);
	void printAll(Task**) const;
	void printOneStudent(stringstream&) const;
	Task** createList(int, Student*);
	int getStudentID(int,Task**)const;
	int getStudentRGZ(int,Task**)const;
	Task** ReadFile(string);
	int FileString(string);
	void WriteFile(string) const;
	Task** enterNewStudent();
	int regexTask(List&);
	static bool sortAsc(const int&, const int&);
	static bool sortDesc(const int&, const int&);
	void sort(comp);
	~List();
};
int generateID();
int generateRGZ();