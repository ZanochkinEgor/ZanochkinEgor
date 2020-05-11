#pragma once
#include <iostream>

typedef short sint;
using std::istream;
using std::ostream;

class Date
{
private:
	sint day;
	sint month;
	sint year;
public:
	sint getDay() const;
	sint getMonth() const;
	sint getYear() const;

	friend istream& operator>> (istream&, Date&);
	friend ostream& operator<< (ostream&, const Date&);

	Date();
	Date(sint, sint, sint);
	Date(const Date& date);
	~Date();
};