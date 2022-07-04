#ifndef VACOP_DATE__H
#define VACOP_DATE__H

#include <iostream>

class Date 
{
private:
    int day;
    int month;
    int year;

public:
    Date() = default;

    Date(int day, int month, int year);

    int getDay() const;

    int getMonth() const;

    int getYear() const;

    bool setDay(const int day);

    bool setMonth(const int month);

    bool setYear(const int year);

    bool checkDateValidation();

    bool operator==(const Date& other) const;

    bool operator!=(const Date& other) const;

    bool operator<(const Date& other) const;

    bool operator>(const Date& other) const;

    bool operator<=(const Date& other) const;

    bool operator>=(const Date& other) const;


    friend std::ostream& operator<<(std::ostream& os, const Date& date)
    {
        os  << date.day << "/" << date.month << "/" << date.year;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Date& date)
    {
        is >> date.day >> date.month >> date.year;
        return is;
    }

    

};

#endif // VACOP_DATE__H



