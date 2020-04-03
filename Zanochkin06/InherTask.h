#include "Task.h"
#pragma once
class Inheritor : public Task
{
private:
	int rgzForTeacher;
public:
	int getRgzForTeacher() const;
	void setRgzForTeacher(int rgz1);

	int InherGenerateID();
	int InherGenerateRGZ();
	int InherGenerateRGZForTeacher();

	Inheritor();
	Inheritor(int, string, int, int, int, int, sint, sint, sint, int);
	Inheritor(const Inheritor& object);
	~Inheritor();
};

Inheritor InherCreateStudent();
Inheritor InherCreateStudent2();