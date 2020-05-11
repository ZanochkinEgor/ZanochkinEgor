#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
using std::ostream;
using std::istream;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::exception;
using std::istringstream;

class Student
{
private:
	string name;
	string surname;
	Student* array;
	int age;
public:
	Student* createArray(int) noexcept;
	Student students(int) const noexcept;

	friend ostream& operator<<(ostream&, const Student) noexcept;
	friend istream& operator>>(istream&, Student&) noexcept;
	bool operator==(const Student) const noexcept;
	bool operator<(const Student) const noexcept;
	bool operator>(const Student) const noexcept;

	Student();
	Student(string, string, int);
	Student(const Student&);
	~Student();
};

void Menu() noexcept;
void intArray() noexcept (false);
void floatArray() noexcept (false);
void classArray() noexcept (false);