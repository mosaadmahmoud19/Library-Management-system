#include <iostream>
#include <string.h>
#include<string>
#include <conio.h>
#include <windows.h>
#include <cstdlib>

#include <Book.h>
#include <Casheir.h>
#include<Receipt.h>
#include "Admin.h"

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto

void gotoXY(int,int); // function defined below.
void displayBanner(); // function defined below.

int main()
{
    Admin admin;
    Casheir casheir;
    Casheir *casheirs = new Casheir[5];
    string nameB;
    string category;
    string publisher;
    float price;
    int available_copies;
    int menu_item=0,y=7;
    bool running = true;
    char c='y';

    displayBanner();
    gotoXY(18,7);
    cout << "->";
    admin.setName("nadeen");
    admin.setPassword("123");
    admin.setPhone("0111");
    while(running)
    {
        gotoXY(20,7);
        cout << "1) Admin";

        gotoXY(20,8);
        cout << "2) Cashier";

        gotoXY(20,9);
        cout << "Quit Program";

        system("pause>nul"); // the >nul bit causes it the print no message

        if(GetAsyncKeyState(VK_DOWN) && y != 9) //down button pressed
        {
            gotoXY(18,y);
            cout << "  ";
            y++;
            gotoXY(18,y);
            cout << "->";
            menu_item++;
            continue;
        }

        if(GetAsyncKeyState(VK_UP) && y != 7) //up button pressed
        {
            gotoXY(18,y);
            cout << "  ";
            y--;
            gotoXY(18,y);
            cout << "->";
            menu_item--;
            continue;
        }

        if(GetAsyncKeyState(VK_DOWN) && y == 9) //down button pressed
        {
            gotoXY(18,y);
            cout << "  ";
            y=7;
            gotoXY(18,y);
            cout << "->";
            menu_item=0;
            continue;
        }

        if(GetAsyncKeyState(VK_UP) && y == 7) //up button pressed
        {
            gotoXY(18,y);
            cout << "  ";
            y=9;
            gotoXY(18,y);
            cout << "->";
            menu_item=2;
            continue;
        }

        if(GetAsyncKeyState(VK_RETURN))  // Enter key pressed
        {
            switch(menu_item)
            {
            case 0:
            {
                gotoXY(20,16);
                cout << " You chose Admin...     ";
                string adminUser;
                string adminPassword;
                /*char ADMINUSER[]="admin",ADMINPASSWORD[]="password";*/
                int chance=3;
                while (chance)
                {
                    system("cls");
                    cout<<"\n ---------- Admin Login -------";
                    cout<<"\n\n Enter username: ";
                    cin>>adminUser;
                    cout<<"\n Enter password: ";
                    cin>>adminPassword;

                    if(admin.logIn(adminUser,adminPassword))
                    {
                        system("cls");
                        string name , phone;
                        while(c=='y')
                        {
                            cout<<"\n ---------- Create Account Casheir -------";
                            cout<<"\n\n Enter username: ";
                            cin>>name;
                            cout<<"\n Enter phone: ";
                            cin>>phone;
                            casheirs=admin.createAccount(name,phone);
                            cout<<"\n ID : " <<casheirs[admin.getIndex()].getCode()<<endl;
                            cout <<"If You want to Create Another Account ,Please Enter y :";
                            cin >> c;

                        }
                        //getch();
                        break;
                    }
                    else
                    {
                        cout<<"You have entered incorrect Username or Password!!";
                        chance--;
                    }
                }
                system("cls");
                displayBanner();
                gotoXY(18,7+menu_item);
                cout << "->";
                break;
            }

            case 1:
            {
                gotoXY(20,16);
                cout << "You chose Cashier...     ";
                /*char cashierUser[10];
                char cashierPassword[10];
                char CASHIERUSER[] = "cashier",CASHIERPASSWORD[] = "password";*/
                int chances = 3;
                int menu_item2=0,y2=7;
                bool running2= true;
                while (chances)
                {
                    system("cls");
                    int id;
                    bool flag;
                    string cashierPassword;
                    cout<<"\n ---------- Cashier Login -------";
                    cout<<"\n\n Enter ID: ";
                    cin>>id;
                    cout<<"\n Enter password: ";
                    cin>>cashierPassword;

                    flag= casheir.logIn(casheirs,admin.getIndex(),id,cashierPassword);
                    if(flag)
                    {
                        cout<< "Your Password is Correct \n";
                        cout <<"If You want Edit Password  ,Please Enter y :";
                        cin >> c;
                        if(c=='y')
                        {
                            cout<<"Please , Enter New Password: ";
                            cin >>cashierPassword;
                           if( casheir.editPassword(casheirs,admin.getIndex(),id,cashierPassword) )
                                cout<<"Your Password Changed Successfully \n";

                        }

                        system("cls");
                        displayBanner();
                        gotoXY(18,7);
                        cout << "->";
                        while(running2)
                        {
                            gotoXY(20,7);
                            cout << "1) Add a Book";
                            gotoXY(20,8);
                            cout << "2) Sort a Book";
                            gotoXY(20,9);
                            cout << "3) Buy a Book";
                            gotoXY(20,10);
                            cout << "4) Search for a Book";
                            gotoXY(20,11);
                            cout << "5) Display Books";
                            gotoXY(20,12);
                            cout << "6) Display by Categorie";
                            gotoXY(20,13);
                            cout << "7) Edit Book Number";
                            gotoXY(20,14);
                             cout << "8) Display SoldOut";
                            gotoXY(20,15);
                            cout << "Back";

                            system("pause>nul"); // the >nul bit causes it the print no message

                            if(GetAsyncKeyState(VK_DOWN) && y2 != 15) //down button pressed
                            {
                                gotoXY(18,y2);
                                cout << "  ";
                                y2++;
                                gotoXY(18,y2);
                                cout << "->";
                                menu_item2++;
                                continue;
                            }

                            if(GetAsyncKeyState(VK_UP) && y2 != 7) //up button pressed
                            {
                                gotoXY(18,y2);
                                cout << "  ";
                                y2--;
                                gotoXY(18,y2);
                                cout << "->";
                                menu_item2--;
                                continue;
                            }

                            if(GetAsyncKeyState(VK_DOWN) && y2 == 15) //down button pressed
                            {
                                gotoXY(18,y2);
                                cout << "  ";
                                y2=7;
                                gotoXY(18,y2);
                                cout << "->";
                                menu_item2=0;
                                continue;
                            }

                            if(GetAsyncKeyState(VK_UP) && y2 == 7) //up button pressed
                            {
                                gotoXY(18,y2);
                                cout << "  ";
                                y2=15;
                                gotoXY(18,y2);
                                cout << "->";
                                menu_item2=8;
                                continue;
                            }

                            if(GetAsyncKeyState(VK_RETURN))  // Enter key pressed
                            {
                                switch(menu_item2)
                                {
                                case 0:
                                {

                                    system("cls");
                                    gotoXY(20,16);

                                    cout<< "\n Please ,Enter Name of Book";
                                    cin>> nameB;
                                    cout<< "\n Please ,Enter Publisher of Book";
                                    cin>> publisher;
                                    cout<< "\n Please ,Enter Category of Book";
                                    cin>> category;
                                    cout<< "\n Please ,Enter Price of Book";
                                    cin>> price;
                                    cout<< "\n Please ,Enter Number of Copies of Book";
                                    cin>> available_copies;
                                    Book book(nameB,category,publisher,price,available_copies);
                                    casheir.addBook(book);

                                    getch();
                                    system("cls");
                                    displayBanner();
                                    gotoXY(18,7+ menu_item2);
                                    cout << "->";
                                    break;
                                }
                                case 1:
                                {

                                    system("cls");
                                    gotoXY(20,16);

                                    casheir.sortBooks();
                                    casheir.displayAll();
                                    getch();

                                    system("cls");
                                    displayBanner();
                                    gotoXY(18,7+ menu_item2);
                                    cout << "->";
                                    break;


                                }
                                case 2:
                                {
                                    system("cls");
                                    gotoXY(20,16);

                                    int num;
                                    cout<<"Please Enter Number of Books : ";
                                    cin>> num;
                                    string name[num];
                                    int counter[num];
                                    for(int i=0 ; i< num ;i++)
                                    {
                                        cout<<"name : "<<endl;
                                        cin>> name[i];
                                        cout<<"counter"<<endl;
                                        cin>> counter[i];
                                    }

                                    int countt = casheir.buyBoook(name,counter,num);
                                    if(countt > 0)
                                    {
                                        Receipt r;
                                        r.takInfo("nada","01284","10","2", "2022",countt);
                                        r.displayReceipt(name,counter,num);
                                    }



                                    getch();
                                    system("cls");
                                    displayBanner();
                                    gotoXY(18,7+ menu_item2);
                                    cout << "->";
                                    break;
                                }
                                case 3:
                                {

                                    system("cls");
                                    gotoXY(20,16);

                                    cout<< "\n Please ,Enter Name of Book";
                                    cin>> nameB;
                                    casheir.search_(nameB);

                                    getch();
                                    system("cls");
                                    displayBanner();
                                    gotoXY(18,7+menu_item2);
                                    cout << "->";
                                    break;
                                }
                                case 4:

                                {


                                    system("cls");
                                    gotoXY(20,16);

                                    casheir.displayAll();


                                    getch();
                                    system("cls");
                                    displayBanner();
                                    gotoXY(18,7+menu_item2);
                                    cout << "->";
                                    break;


                                }
                                case 5:
                                {

                                    system("cls");
                                    gotoXY(20,16);

                                    cout<< "\n Please ,Enter Category of Book";
                                    cin>> category;
                                    casheir.displayCategory(category);

                                    getch();
                                    system("cls");
                                    displayBanner();
                                    gotoXY(18,7+menu_item2);
                                    cout << "->";
                                    break;
                                }
                                case 6:
                                {

                                    system("cls");
                                    gotoXY(20,16);

                                    cout<< "\n Please ,Enter Name of Book";
                                    cin>> nameB;
                                    cout<< "\n Please ,Enter Number of Copies of Book";
                                    cin>> available_copies;
                                    if(casheir.edit(nameB,available_copies)!=-1)
                                        cout <<"Edit Done";


                                    getch();
                                    system("cls");
                                    displayBanner();
                                    gotoXY(18,7+menu_item2);
                                    cout << "->";
                                    break;
                                }

                                case 7:
                                {

                                    system("cls");
                                    gotoXY(20,16);

                                    casheir.soldout();

                                    getch();
                                    system("cls");
                                    displayBanner();
                                    gotoXY(18,7+menu_item2);
                                    cout << "->";
                                    break;
                                }
                                case 8:
                                {
                                    casheir.exit();
                                    gotoXY(20,16);
                                    cout << "The program has now terminated!!";
                                    running2 = false;
                                }
                                }
                            }
                        }
                        break;
                    }
                    else
                    {
                        chances--;
                    }
                }
                system("cls");
                displayBanner();
                gotoXY(18,7+menu_item);
                cout << "->";
                break;
            }
            case 2:
            {
                casheir.exit();
                gotoXY(20,16);
                cout << "The program has now terminated!!";
                running = false;
            }
            }
        }
    }
    gotoXY(20,21);
    return 0;
}
void gotoXY(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console,CursorPosition);
}

void displayBanner()
{
    cout<<"\n\t----------------------------------------------------------------------\n";
    cout<<"\t         L i b r a r y     M a n a g e m e n t     S y s t e m\n";
    cout<<"\t----------------------------------------------------------------------\n";
}
































