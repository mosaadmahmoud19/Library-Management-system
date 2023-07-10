#ifndef PERSON_H
#define PERSON_H
#include <iostream>

#include <string.h>
#include<string>
using namespace std;

class Person
{
    private:
        string name;
        string phone;
    public:
        Person()
        {
            name="";
            phone="";
        }
        Person(string name , string phone )
        {
            this->name=name;
            this->phone=phone;
        }
        void setName(string name)
        {
            this->name=name;
        }
        void setPhone(string phone)
        {
            this->phone=phone;
        }
        string getName()
        {
            return name;
        }
        string getPhone()
        {
            return phone;
        }

        virtual ~Person() {}

    protected:

};

#endif // PERSON_H
