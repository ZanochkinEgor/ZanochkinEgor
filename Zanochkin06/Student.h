#pragma once
#include <iostream>
#include <string>

using std::string;

class Student {
private:
	int age;
	int listSize;
	int* list;

public:
	int getAge()const;
	void setAge(const int);
	void deleteList();
	int* createList(int size);
	int students(int value);

	Student();
	Student(int age);
	Student(const Student& other);
	~Student();
};