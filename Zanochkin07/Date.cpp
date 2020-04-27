#include "Date.h"

sint Date::getDay() const { return day; }

sint Date::getMonth() const { return month; }

sint Date::getYear() const { return year; }

Date::Date() : day(2), month(2), year(2002) {}
Date::Date(sint day, sint month, sint year) : day(day), month(month), year(year) {}
Date::Date(const Date& date) : day(date.day), month(date.month), year(date.year) {}
Date::~Date() {}