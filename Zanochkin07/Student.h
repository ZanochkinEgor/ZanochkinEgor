#pragma once
#include <iostream>
#include <string>

using std::string;

class Student {
private:
	int age;
	int listSize;
	Student* list;

public:
	int getAge()const;
	void setAge(const int);
	void deleteList();
	Student* createList(int size);
	Student students(int value);

	Student();
	Student(int);
	Student(const Student& other);
	~Student();
};