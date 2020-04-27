#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <regex>
#include <cstddef>
#include "Date.h"
#include "Student.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::stringstream;
using std::regex;

typedef bool (comp)(const int&, const int&);

class Task
{
protected:
	int studentIndex;
	string name;
	int mark;
	int countOfDoneExercises;
	int rgz;
	Date date;
	Student age;
public:
	int getMark() const;
	void setMark(int);

	int getCountOfDoneExercises() const;
	void setCountOfDoneExercises(int);

	int getStudentIndex() const;
	void setStudentIndex(int);

	int getRgz() const;
	void setRgz(int);

	string getName() const;
	void setName(const string);

	sint getDay() const;
	void setDay(const sint);

	sint getMonth() const;
	void setMonth(const sint);

	sint getYear() const;
	void setYear(const sint);

	int getAge() const;
	void setAge(const int);

	int generateID();
	int generateRGZ();

	Task();
	Task(int, string, int, int, int, int, sint, sint, sint);
	Task(const Task&);
	~Task();
};

void Menu();
Task CreateStudent();
Task CreateStudent2();