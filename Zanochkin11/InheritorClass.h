#pragma once
#include "Student.h"

class Mark final : public Student
{
private:
	int mark;
public:
	string getInfo() const override final;

	Mark();
	Mark(string, string, int, int);
	Mark(const Mark&);
	~Mark() override final;
};