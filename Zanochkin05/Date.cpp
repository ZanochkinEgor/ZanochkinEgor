#include "Date.h"

sint Date::getDay() const { return day; }
void Date::setDay(sint day1) { day = day1; }

sint Date::getMonth() const { return month; }
void Date::setMonth(sint month1) { month = month1; }

sint Date::getYear() const { return year; }
void Date::setYear(sint year1) { year = year1; }

Date::Date() : day(2), month(2), year(2002) {}
Date::Date(sint day, sint month, sint year) : day(day), month(month), year(year) {}
Date::Date(const Date& date) : day(date.day), month(date.month), year(date.year) {}
Date::~Date() {}
