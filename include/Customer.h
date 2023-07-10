#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Person.h"

class Customer:public Person
{
    public:
        Customer():Person(){}
        Customer(string name ,string phone ):Person(name , phone ){}
        //virtual ~Customer();

    protected:

    private:
};

#endif // CUSTOMER_H
