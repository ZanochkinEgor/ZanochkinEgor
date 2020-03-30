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
	void setDay(sint day);

	sint getMonth() const;
	void setMonth(sint month);

	sint getYear() const;
	void setYear(sint year);

	Date();
	Date(sint, sint, sint);
	Date(const Date& date);
	~Date();
};