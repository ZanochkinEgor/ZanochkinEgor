#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using std::ostream;
using std::istream;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::exception;
using std::istringstream;
using std::stringstream;

class Student
{
protected:
	string name;
	string surname;
	int age;
public:
	virtual string getInfo() const;

	friend ostream& operator<<(ostream&, const Student&) noexcept;
	friend istream& operator>>(istream&, Student&) noexcept;
	bool operator==(const Student) const noexcept;
	bool operator<(const Student) const noexcept;
	bool operator>(const Student) const noexcept;

	Student();
	Student(string, string, int);
	Student(const Student&);
	virtual ~Student();
};

void Menu() noexcept;
Student** createArray(int);
void intArray() noexcept (false);
void floatArray() noexcept (false);
void classArray() noexcept (false);