#ifndef ADMIN_H
#define ADMIN_H

#include "Casheir.h"


class Admin:public Person
{
    static int index;
    string password;
    Casheir *casheir=new Casheir[5] ;
    public:
        //Admin():Person()
       //  {}
         void setPassword(string password)
        {
            this->password=password;
        }

        string getPassword()
        {
            return password;
        }

        Casheir* createAccount(string name , string phone)
        {
            index++;
            casheir[index].setName(name);
            casheir[index].setPhone(phone);
            casheir[index].setPassword("0000");
            casheir[index].setCode(index+1);
            return  casheir ;
        }
        bool logIn(string name , string pass )
        {
                if (this->getName()==name)
                {
                    if (this->password == pass)
                    {
                        return true;
                    }
                }
            return false;
        }
        int getIndex()
        {
            return index;
        }
       // virtual ~Admin() {}

    protected:

    private:
};
int Admin::index=-1;
#endif // ADMIN_H
