#include "Date.h"
#include <iostream>
using namespace std;


Date::Date(const int day, const int month, const int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}


int Date::getDay() const
{
	return this->day;
}


int Date::getMonth() const
{
	return this->month;
}


int Date::getYear() const
{
	return this->year;
}

bool Date::setDay(const int day)
{
	if (day > 0 && (((month == 1 || month == 3 || month == 5 || month == 7 || month == 9 || month == 11) && day <= 31) || (month == 2 && day <= 28) ||
		((month == 4 || month == 6 || month == 8 || month == 10 || month == 12) && day <= 30))) {
		this->day = day;
		return true;
	}
	else
		return false;
}

bool Date::setMonth(const int month)
{
	if (month > 0 && month <= 12) {
		this->month = month;
		return true;
	}
	else
		return false;
}

bool Date::setYear(const int year)
{
	if (year < 2022)
		return false;
	if (year == 2022)
	{
		if (this->getMonth() > 6 && this->getMonth() < 13)
		{
			this->year = year;
			return true;
		}
		else
			return false;
		
	}
	this->year = year;
	return true;
}

bool Date::checkDateValidation()
{
	if (!this->setDay(this->getDay()) || !this->setMonth(this->getMonth()) || !this->setYear(this->getYear()))
		return false;
	return true;
}

bool Date::operator==(const Date& other) const
{
	return this->day == other.getDay() && this->month == other.getMonth() && this->year == other.getYear();
}

bool Date::operator!=(const Date& other) const
{
	return !(*this == other);
}

bool Date::operator<(const Date& other) const
{
	return (year < other.year || (year == other.year && month < other.month) || (year == other.year && month == other.month && day < other.day));
}

bool Date::operator>(const Date& other) const
{
	return !(*this < other) && (*this != other);
}

bool Date::operator<=(const Date& other) const
{
	return (*this < other) || (*this == other);
}

bool Date::operator>=(const Date& other) const
{
	return *this > other || *this == other;
}