#pragma once
#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::istream;

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

	friend istream& operator>> (istream&, Student&);
	friend ostream& operator<< (ostream&, const Student&);
	bool operator==(const int) const;

	Student();
	Student(int);
	Student(const Student& other);
	~Student();
};