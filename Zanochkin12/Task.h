#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <memory>

using std::string;
using std::stringstream;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::ostream;
using std::istream;
using std::vector;
using std::map;
using std::list;
using std::set;
using std::advance;
using std::unique_ptr;
using std::pair;

class Task
{
protected:
	int studentIndex;
	string name;
	int mark;
	int countOfDoneExercises;
	int rgz;
public:
	int getStudentIndex() const;
	virtual string getInfo() const;

	friend ostream& operator<< (ostream&, const Task&);
	virtual bool operator==(const int) const;

	Task();
	Task(int, string, int, int, int);
	Task(const Task&);
	virtual ~Task();
};

void Menu();
void vectorMenu();
void setMenu();
void listMenu();
void mapMenu();
Task* newStudent(int);
int generateID();
int generateRGZ();
int generateRgzForTeacher();