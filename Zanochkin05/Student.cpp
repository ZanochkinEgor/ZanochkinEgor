#include "Student.h"

int Student::getAge() const
{
	return age;
}
void Student::setAge(const int age1)
{
	age = age1;
}

int* Student::createList(int size)
{
	listSize = size;
	list = new int[size];
	for (int i = 0; i < size; i++)
		list[i] = students(i);
	return list;
}

int Student::students(int value)
{
	int age;
	switch (value)
	{
	case 1:
		age = 5;
		return age;
	case 2:
		age = 15;
		return age;
	}
}

void Student::deleteList()
{
	delete[] list;
}

Student::Student() : age(0) {}
Student::Student(int age) : age(age) {}
Student::Student(const Student& student) : age(student.age) {}
Student::~Student() {}