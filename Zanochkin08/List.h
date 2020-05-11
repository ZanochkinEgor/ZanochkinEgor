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
	void addStudent(Task*);
	Task* newStudent(Student*, int);
	void deleteStudent(int);
	void printAll() const;
	void printOneStudent(int) const;
	void createList(int, Student*);
	int getStudentID(int)const;
	int getStudentRGZ(int)const;
	void readFile(string);
	int fileString(string) const;
	void writeFile(string) const;
	void enterNewStudent();
	int regexTask();
	static bool sortAsc(const int&, const int&);
	static bool sortDesc(const int&, const int&);
	void sort(comp);
	Task*& operator[] (int);
	~List();
};
int generateID();
int generateRGZ();