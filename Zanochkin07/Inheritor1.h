#include "Task.h"
#pragma once
class Inheritor : public Task
{
private:
	int rgzForTeacher;
public:
	int getRgzForTeacher() const;
	void setRgzForTeacher(int rgz1);

	void print() const override;
	stringstream getStr() const override;
	void writeInFile(ofstream&) override;

	Inheritor();
	Inheritor(int, string, Student, int, int, int, sint, sint, sint, int);
	Inheritor(const Inheritor& object);
	~Inheritor() override;
};