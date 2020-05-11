#include "InheritorClass.h"

Mark::Mark() : Student(), mark(5) {}
Mark::Mark(string name, string surname, int age, int mark) : Student(name, surname, age), mark(mark) {}
Mark::Mark(const Mark& obj) : Student(obj), mark(obj.mark) {}
Mark::~Mark() {}

string Mark::getInfo() const
{
	stringstream temp;
	temp.setf(std::ios::left);
	temp << setw(9) << name << setw(14) << surname << setw(8) << age << mark;
	return temp.str();
}