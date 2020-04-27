#pragma once
typedef short sint;

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

	Date();
	Date(sint, sint, sint);
	Date(const Date& date);
	~Date();
};