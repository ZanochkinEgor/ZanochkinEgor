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
using std::ofstream;
using std::ifstream;
using std::ostream;
using std::istream;

typedef bool (comp)(const int&, const int&);

class Task
{
protected:
	int studentIndex;
	string name;
	Student age;
	int mark;
	int countOfDoneExercises;
	int rgz;
	Date date;
public:
	virtual int getMark() const;
	virtual int getCountOfDoneExercises() const;
	virtual int getStudentIndex() const;
	virtual int getRgz() const;
	virtual string getName() const;
	virtual sint getDay() const;
	virtual sint getMonth() const;
	virtual sint getYear() const;
	virtual int getAge() const;

	virtual string getInfo() const = 0;
	virtual void input(istream&) = 0;
	virtual stringstream getStr() const = 0;

	friend ostream& operator<< (ostream& output, const Task& obj);
	friend istream& operator>> (istream& input, Task& obj);
	virtual bool operator==(const string) const;
	Task& operator= (Task& temp);

	Task();
	Task(int, string, Student, int, int, int, sint, sint, sint);
	Task(const Task&);
	virtual ~Task();
};

void Menu();