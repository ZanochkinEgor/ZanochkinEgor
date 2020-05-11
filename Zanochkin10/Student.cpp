#include "Student.h"

Student::Student() : name("Egor"), surname("Zanochkin"), age(18) {}
Student::Student(string name, string surname, int age) : name(name), surname(surname), age(age) {}
Student::Student(const Student& obj) : name(obj.name), surname(obj.surname), age(obj.age) {}
Student::~Student() {}

Student* Student::createArray(int size) noexcept
{
	array = new Student[size];
	for (size_t i = 0; i < size; i++)
		array[i] = students(i);
	return array;
}

Student Student::students(int number) const noexcept
{
	if (number == 0)
	{
		Student stud;
		return stud;
	}
	else if (number == 1)
	{
		Student stud("Katya", "Belko", 20);
		return stud;
	}
	else if (number == 2)
	{
		Student stud("Vadim", "Geltz", 40);
		return stud;
	}
	else if (number == 3)
	{
		Student stud("Olya", "Yaremko", 15);
		return stud;
	}
	else
	{
		Student stud("Random", "Random", rand() % 50 + 1);
		return stud;
	}
}

ostream& operator<<(ostream& output, const Student obj) noexcept
{
	output.setf(std::ios::left);
	output << setw(10) << obj.name << setw(12) << obj.surname << obj.age;
	return output;
}

istream& operator>>(istream& input, Student& obj) noexcept
{
	input >> obj.age;
	return input;
}

bool Student::operator==(const Student obj) const noexcept
{
	return this->age == obj.age;
}

bool Student::operator<(const Student obj) const noexcept
{
	return this->age < obj.age;
}

bool Student::operator>(const Student obj) const noexcept
{
	return this->age > obj.age;
}