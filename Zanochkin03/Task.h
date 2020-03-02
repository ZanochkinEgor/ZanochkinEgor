#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW

#include <cstdio> 	  
#include <iostream>
using namespace std;

class Task
{
private:
	int mark;
	int count_of_done_exercises;
	int student_index;
	const char* male_or_female;
	int rgz;

public:
	int getMark() const;
	void setMark(int);

	int getCount_of_done_exercises() const;
	void setCount_of_done_exercises(int);

	int getStudent_index() const;
	void setStudent_index(int);

	const char* getMale_or_female() const;
	void setMale_or_female(const char*);

	int getRgz() const;
	void setRgz(int);

	Task();
	Task(char*, int, int, int, int);
	Task(const Task& stud);
	~Task();
};

void Menu();