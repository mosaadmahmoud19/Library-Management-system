#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string.h>
#include<string>
using namespace std;
class Date
{
    private:
        string day;
        string month;
        string year;
    public:
        Date()
        {
            this->day="";
            this->month="";
            this->year="";

        }
        Date(string day,string month,string year)
        {
            this->day=day;
            this->month=month;
            this->year=year;

        }
        void setDay(string day)
        {
            this->day=day;
        }
        string getDay()
        {
            return day;
        }

        void setMonth(string month)
        {
            this->month=month;
        }

        string getMonth()
        {
            return month;
        }

        void setYear(string year)
        {
            this->year=year;
        }

        string getYear()
        {
            return year;
        }

        virtual ~Date() {}


    private:
};

#endif // DATE_H
