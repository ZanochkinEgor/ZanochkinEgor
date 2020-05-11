#include "Task.h"
#pragma once
class Inheritor : public Task
{
private:
	int rgzForTeacher;
public:
	int getRgzForTeacher() const;
	void setRgzForTeacher(int rgz1);

	string getInfo() const override final;
	stringstream getStr() const override final;
	void input(istream&) override final;

	Inheritor& operator= (Inheritor&);
	bool operator==(const string) const override final;

	Inheritor();
	Inheritor(int, string, Student, int, int, int, sint, sint, sint, int);
	Inheritor(const Inheritor& object);
	~Inheritor() override;
};