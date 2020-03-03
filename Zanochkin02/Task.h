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
	int countOfDoneExercises;
	int studentIndex;
	const char* maleOrFemale;
	int rgz;

public:
	int getMark() const;
	void setMark(int);

	int getCountOfDoneExercises() const;
	void setCountOfDoneExercises(int);

	int getStudentIndex() const;
	void setStudentIndex(int);

	const char* getMaleOrFemale() const;
	void setMaleOrFemale(const char*);

	int getRgz() const;
	void setRgz(int);

	Task();
	Task(char*, int, int, int, int);
	Task(const Task& stud);
	~Task();
};

void Menu();