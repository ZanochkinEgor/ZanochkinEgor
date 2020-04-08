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
	void addStudent(const Task);
	void deleteStudent(int);
	void printAll() const;
	void printOneStudent(stringstream&) const;
	void createList();
	int getStudentID(int)const;
	int getStudentRGZ(int)const;
	void ReadFile(string, int);
	int FileString(string);
	void WriteFile(string) const;
	stringstream getObj(int i) const;
	Task enterNewStudent();
	~List();
};

Task CreateStudent();
Task CreateStudent2();