#include "Student.h"

int Student::getAge() const { return age; }

Student* Student::createList(int size)
{
	listSize = size;
	list = new Student[size];
	for (size_t i = 0; i < size; i++)
		list[i] = students(i);
	return list;
}

Student Student::students(int value)
{
	if (value == 0)
	{
		Student age1 = 10;
		return age1;
	}
	else if (value == 1)
	{
		Student age2 = 15;
		return age2;
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

istream& operator>> (istream& input, Student& age1)
{
	input >> age1.age;
	return input;
}

ostream& operator<< (ostream& output, const Student& age1)
{
	output << age1.age;
	return output;
}

bool Student::operator==(const int age1) const
{
	return this->age == age1;
}