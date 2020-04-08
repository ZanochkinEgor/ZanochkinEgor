#pragma once
#include "InherTask.h"

class InheritorList
{
private:
	int listSize;
public:
	Inheritor* stud;

	int getListSize() const;
	void setListSize(int);
	void addStudent(const Inheritor);
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
	Inheritor StringToObject(stringstream);
	Inheritor enterNewStudent();
	void regexTask();
	static bool sortAsc(const int&, const int&);
	static bool sortDesc(const int&, const int&);
	void sort(comp);
	~InheritorList();
};
