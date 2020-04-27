#include "Task.h"
#pragma once
class Inheritor2 : public Task
{
private:
	string maleFemale;
public:
	string getMaleFemale() const;
	void setMaleFemale(int);

	void print() const override;
	stringstream getStr() const override;
	void writeInFile(ofstream&) override;

	Inheritor2();
	Inheritor2(int, string, Student, int, int, int, sint, sint, sint, string);
	Inheritor2(const Inheritor2&);
	~Inheritor2() override;
};