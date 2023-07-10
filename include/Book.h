#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string.h>
#include<string>
using namespace std;
class Book
{
    private:
        string name;
        string category;
        string publisher;
        float price;
        int available_copies;

    public:
        Book() {}
        Book(string name,string category,string publisher,float price,int available_copies)
        {
            this->name=name;
            this->category=category;
            this->publisher=publisher;
            this->price=price;
            this->available_copies=available_copies;
        }
        void setName(string name)
        {
            this->name=name;
        }
        string getName()
        {
            return name;
        }

        void setCategory(string category)
        {
            this->category=category;
        }

        string getCategory()
        {
            return category;
        }

        void setPublisher(string publisher)
        {
            this->publisher=publisher;
        }

        string getPublisher()
        {
            return publisher;
        }

        void setPrice(float price)
        {
            this->price=price;
        }

        float getPrice()
        {
            return price;
        }

        void setAvailable_copies(int available_copies)
        {
            this->available_copies=available_copies;
        }

        int getAvailable_copies()
        {
            return available_copies;
        }

        virtual ~Book() {}

    protected:


};

#endif // BOOK_H
