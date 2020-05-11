#include "Task.h"
#pragma once
class Inheritor2 : public Task
{
private:
	string maleFemale;
public:
	string getMaleFemale() const;
	void setMaleFemale(int);

	string getInfo() const override final;
	stringstream getStr() const override final;
	void input(istream&) override final;

	Inheritor2& operator= (Inheritor2&);
	bool operator==(const string) const override final;

	Inheritor2();
	Inheritor2(int, string, Student, int, int, int, sint, sint, sint, string);
	Inheritor2(const Inheritor2&);
	~Inheritor2() override;
};