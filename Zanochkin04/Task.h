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

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::stringstream;
using std::regex;

class Task
{
private:
	int studentIndex;
	string name;
	int mark;
	int countOfDoneExercises;
	int rgz;
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

	Task();
	Task(int, string, int, int, int);
	Task(const Task& stud);
	~Task();
};

void Menu();