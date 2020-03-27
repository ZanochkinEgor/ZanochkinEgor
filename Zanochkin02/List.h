#pragma once
#include "Task.h"

class List
{
private:
	int listSize;

public:
	Task* stud;

	int getListSize() const;
	void setListSize(int);
	void addStudent(Task);
	void deleteStudent(int);
	void printAll() const;
	void printOneStudent(int) const;
	void createList();
	void getStudentID(int)const;
	void getStudentRGZ(int)const;
	~List();
};

Task CreateStudent();
Task CreateStudent2();