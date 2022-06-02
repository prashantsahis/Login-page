#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void registration();
void login();
void forgot_password();

int main()
{
    int c;
    cout << "\t\t\t_______________________________________________________________\n\n\n";
    cout << "\t\t\t                    Welcome to Login Page                      \n\n\n";
    cout << "\t\t\t____________                Menu                _______________\n\n\n";
    cout << endl;
    cout << "\t|  Press 1 to LOGIN                           |" << endl;
    cout << "\t|  Press 2 to REGISTER                        |" << endl;
    cout << "\t|  Press 3 if you forgot your PASSWORD        |" << endl;
    cout << "\t|  Press 1 to EXIT                            |" << endl;
    cout << "\n\t\t\t Please enter your choice : ";
    cin >> c;
    cout << endl;
    switch (c)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgot_password();
        break;
    case 4:
        cout << "\t\t\t  Thank you!  \n\n";
        break;
    default:
        system("cls");
        cout << "\t\t\t Please select from the options given above \n"
             << endl;
        main();
    }
    return 0;
}
void login()
{
    int count;
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\tPlease enter the username and password : " << endl;
    cout << "\t\t\t USERNAME ";
    cin >> userId;
    cout << "\t\t\t PASSWORD ";
    cin >> password;

    ifstream input("records.txt");

    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if (count == 1)
    {
        cout << userId << "\n Your Login is successful \n Thanks for logging in tour our system ! \n";
        main();
    }
    else
    {
        cout << "\n LOGIN ERROR \n Please check your username and password \n Or \n Register first. \n";
        main();
    }
}

void registration()
{
    string ruserId, rpassword, rid, rpass;
    system("cls");
    cout << "\t\t\t Enter the username : ";
    cin >> ruserId;
    cout << "\t\t\t Enter the password : ";
    cin >> rpassword;

    ofstream f1("records.txt, ios::app");
    f1 << ruserId << ' ' << rpassword << endl;
    system("cls");
    cout << "\n\t\t\t Yor Registration is successful! \n";
    main();
}

void forgot_password()
{
    int option;
    system("cls");
    cout << "\t\t\t You forgot the pssword? No worries \n";
    cout << "Press 1 to search your id by username " << endl;
    cout << "Press 2 to go back to main menu " << endl;
    cout << "Enter your choice :" << endl;
    cin >> option;
    cout << endl;

    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserId, sId, spass;
        cout << "\n\t\t\t Enter your username which u remember :" << endl;
        cin >> suserId;

        ifstream f2("records.txt");
        while (f2 >> sId >> spass)
        {
            if (sId == suserId)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            if (count == 1)
            {
                cout << "\n\n Your account is found! \n";
                cout << "\n\n Your password is " << spass;
                main();
            }
            else
            {
                cout << "\n\t Sorry your account is not found! \n";
            }
            break;
        }
    }
    case 2:
        main();
    default:
        cout << "\t\t\t Wrong choice ! Please try again. " << endl;
        forgot_password();
    }
}