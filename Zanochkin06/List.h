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
	stringstream DataToString();
	Task StringToObject(stringstream);
	Task enterNewStudent();
	void regexTask();
	static bool sortAsc(const int&, const int&);
	static bool sortDesc(const int&, const int&);
	void sort(comp);
	~List();
};