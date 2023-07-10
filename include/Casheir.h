#ifndef CASHEIR_H
#define CASHEIR_H
#include "Book.h"
#include "Person.h"
#include "Receipt.h"
#include "Customer.h"

#include "file.h"



#include <iostream>
#include <string.h>
#include<string>
using namespace std;

class Casheir:public Person
{
    string password;
    int code;
    Book *book=new Book[20];
    //Book book[5];
    Receipt *receipt;
    static int count_book;
    file f;
    public:
        Casheir():Person(){f.readBooks(book,count_book);}

        void setPassword(string password)
        {
            this->password=password;
        }

        string getPassword()
        {
            return password;
        }

        void setCode(int code)
        {
            this->code=code;
        }

        int getCode()
        {
            return code;
        }

        void setAvailable_copies(int available_copies)
        {
            available_copies=available_copies;
        }
/*******************************************************************************************************************************/
        int found(string name)
        {
            for(int i=0 ;i< count_book ; i++)
            {
                if( book[i].getName()==name )
                    return i;
            }
            return -1;
        }
/*******************************************************************************************************************************/
        void addBook(Book b)
        {

            int index=found(b.getName());
            if(index==-1)
            {
               // cout<<"count_book "<<count_book<<endl;
                book[count_book].setName(b.getName());
                book[count_book].setPublisher(b.getPublisher());
                book[count_book].setCategory(b.getCategory());
                book[count_book].setPrice(b.getPrice());
                book[count_book].setAvailable_copies(b.getAvailable_copies());
                count_book++;
            }
            else
            {
                edit(b.getName(),b.getAvailable_copies());

            }
        }
/*******************************************************************************************************************************/

        int edit(string name , int num)
        {
            int index = found(name);
            if(index != -1)
            {
                int counter=book[index].getAvailable_copies() + num;
                if(counter>=0)
                    book[index].setAvailable_copies(counter);
                else
                {
                    cout<< "available copies : " <<book[index].getName();
                    book[index].setAvailable_copies(0);
                }

                return index;
            }
            else
                return -1;
        }
/*******************************************************************************************************************************/

        void displayAll()
        {
            //cout<<"dd count_book "<<count_book<<endl;
            for(int i=0;i<count_book ;i++)
            {

                cout <<"Name: " << book[i].getName()<<"\t \t";
                cout <<"Publisher: "<< book[i].getPublisher()<<"\t";
                cout <<"Category: "<<  book[i].getCategory() <<"\t";
                cout <<"Price: "<<book[i].getPrice() <<"\t";
                cout <<"Available copies: "<<book[i].getAvailable_copies() <<endl;            }

        }
/*******************************************************************************************************************************/

        void displayCategory(string cate)
        {
            bool check=true;
            for(int i=0;i<count_book ;i++)
            {
                if(cate==book[i].getCategory())
                {
                    cout <<"Name: " << book[i].getName()<<"\t \t";
                    cout <<"Publisher: "<< book[i].getPublisher()<<"\t";
                    cout <<"Price: "<<book[i].getPrice() <<"\t";
                    cout <<"Available_copies: "<<book[i].getAvailable_copies() <<endl;
                    check=false;
                }
            }
            if(check==true)
                cout<<"Not Found Category: " <<cate <<endl;

        }
/*******************************************************************************************************************************/

        void soldout()
        {
            bool check=true;
            for(int i=0;i<count_book ;i++)
            {
                 if(book[i].getAvailable_copies()==0)
                {
                    cout << book[i].getName()<<endl;
                    cout << book[i].getPublisher()<<endl;
                    cout << book[i].getCategory() <<endl;
                    cout << book[i].getPrice() <<endl;
                    cout << book[i].getAvailable_copies() <<endl;
                    check=false;
                }
            }
            if(check==true)
                cout<<"All Books are Found"<<endl;
        }
/*******************************************************************************************************************************/

        void search_(string name)
        {
            int index= found(name);
            if(index!=-1)
            {
                cout << book[index].getName()<<endl;
                cout << book[index].getPublisher()<<endl;
                cout << book[index].getCategory() <<endl;
                cout << book[index].getPrice() <<endl;
                cout << book[index].getAvailable_copies() <<endl;
            }
            else
                cout <<" Book is Not Found"<<endl;
        }
/*******************************************************************************************************************************/

        int  buyBoook(string *name,int *copies,int &Size)
        {
            //int Size = sizeof(name)/ sizeof(name[0]);
            int countt=0;
            for(int i=0 ; i< Size ;i++)
            {
                copies[i]=copies[i]*(-1);
                int check = edit(name[i], copies[i]);
                if(check==-1)
                {
                    cout<< "Book is not found: " << name[i] <<endl;
                    copies[i]=0;
                    //countt++;
                }
                else
                {
                    countt+=getamount(check,copies[i]);
                }
            }
            return countt;
            //if(countt< Size)
              //  receipt->displayReceipt(name, copies, Size);
                //receipt->takInfo("01284","10","2", "2022");

        }
/*******************************************************************************************************************************/
double getamount(int index ,int num)
{
    num=num*-1;
    double amoutBook = book[index].getPrice();
    amoutBook= amoutBook*num;
    return amoutBook;

}

/*******************************************************************************************************************************/
        void sortBooks()
        {
            int i, j, min ;
            Book temp;
            for (i = 0; i < count_book - 1; i++)
            {
               min = i;
               for (j = i + 1; j < count_book; j++)
                 if (book[j].getAvailable_copies() < book[min].getAvailable_copies())
                     min = j;
               temp = book[i];
               book[i] = book[min];
               book[min] = temp;
           }
        }
/*******************************************************************************************************************************/
        bool logIn(Casheir c[] , int counter , int id , string pass )
        {
            for (int i = 0; i<counter+1; i++)
            {
                if (c[i].getCode() == id)
                {
                    if (c[i].getPassword()== pass)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
/*******************************************************************************************************************************/
        bool editPassword(Casheir c[] , int counter , int id , string pass )
        {
           for (int i = 0; i<counter+1; i++)
            {
                if (c[i].getCode() == id)
                {
                    c[i].setPassword(pass);
                    return true;
                }
            }
            return false;
        }


/*******************************************************************************************************************************/
        void exit()
        {
            f.writeBooks(book,count_book);
        }
        //virtual ~Casheir();

    protected:

    private:
};
int Casheir::count_book=0;
#endif // CASHEIR_H
