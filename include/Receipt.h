#ifndef RECEIPT_H
#define RECEIPT_H

#include "Date.h"
#include "Book.h"
#include "Customer.h"
class Receipt
{
    Date date;
    Customer customer;
    double amount;
    static int id;
    public:

        Receipt()
        {
            id++;
        }
        void takInfo(string name, string phone,string day, string month , string year ,double amount)
        {
            //
            customer.setPhone(phone);
            customer.setName(name);
            date.setDay(day);
            date.setMonth(month);
            date.setYear(year);
            this->amount=amount;

        }

        void displayReceipt(string name[],int copies[] ,int Size)
        {
            cout<<"Name : "<< customer.getName()<<endl;
            cout<<"Phone : "<< customer.getPhone()<<endl;
            cout<<"Date : "<<date.getDay()<<"/"<<date.getMonth()<<"/"<<date.getYear()<<endl;
            cout << "ID :"  << id <<endl;
            for(int i=0 ; i<Size ; i++)
            {
                if(copies[i]<0)
                    cout<<"Name of Book :"  << name[i] <<endl;
            }
            cout<<"Price Amount : "<<this->amount<<endl;
          
        }

        //virtual ~Receipt();

    protected:

    private:
};
int Receipt::id=0;
#endif // RECEIPT_H
