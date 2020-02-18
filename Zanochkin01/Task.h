#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW

#include <cstdio> 	  
#include <iostream>
using namespace std;

class Task {
private:
	int mark;
	int count_of_done_exercises;
	int variant;

public:
	int getMark() const;
	void setMark(int);

	int getCount_of_done_exercises() const;
	void setCount_of_done_exercises(int);

	int getVariant() const;
	void setVariant(int);
};

void Menu();