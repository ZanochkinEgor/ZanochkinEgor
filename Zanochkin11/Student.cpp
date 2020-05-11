#include "Student.h"

Student::Student() : name("Egor"), surname("Zanochkin"), age(18) {}
Student::Student(string name, string surname, int age) : name(name), surname(surname), age(age) {}
Student::Student(const Student& obj) : name(obj.name), surname(obj.surname), age(obj.age) {}
Student::~Student() {}

string Student::getInfo() const
{
	stringstream temp;
	temp.setf(std::ios::left);
	temp << setw(9) << name << setw(14) << surname << age;
	return temp.str();
}

ostream& operator<<(ostream& output, const Student& obj) noexcept
{
	output.setf(std::ios::left);
	output << obj.getInfo();
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