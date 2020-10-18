/*
PRASHIL SONI - S00375453
CSCI 6970, HW-3
DUE DATE: 07/13/2020
*/

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

void more_logout();
void show_labs();
void initialize();
void login();
void logout();
void more_login();
void show_menu();
void bonus();

//array that build lab's Computers(PC)
string *arr[4];
int num[] = {10, 6, 3, 12};

int main()
{
    arr[0] = new string[num[0]];
    arr[1] = new string[num[1]];
    arr[2] = new string[num[2]];
    arr[3] = new string[num[3]];

    initialize();
    try
    {
        show_menu();
    }
    catch (const char *msg) //catch following the try block catches any exception
    {
        cerr << msg << endl;
    }

    return 0;
}

// main menu for activity
void show_menu() //throw ()
{
    int ch;
    do
    {
        cout << endl
             << "Menu: " << endl
             << "1. Print current status of computers" << endl; //print 1st option
        cout << "2. Log in a new student" << endl               //print 2nd option
             << "3. Logout a student" << endl                   //print 3rd option
             << "4. Exit" << endl;                              //print 4th option
        cout << "5. Adding computers to lab" << endl            //print 5th option
             << "What do you want to do?";                      //asking user for next activity
        cin >> ch;                                              //take input from the user for main menu
        switch (ch)                                             //switch case that follow input
        {
        case 1:
            show_labs();
            break;
        case 2:
            login();
            break;
        case 3:
            logout();
            break;
        case 4:
            break;
        case 5:
            bonus();
        }
    } while (ch != 4);
}

//5th option in the main menu To add more computers to any lab 1 to lab 4
void bonus()
{
    int l, c;
    cout << endl
         << "Enter lab number: ";
    cin >> l;
    cout << endl
         << "Enter how many computers to add: ";
    cin >> c;

    if (l > 4)
    {
        cout << endl
             << "Invalid lab number" << endl;
        return;
    }

    c = c + num[l - 1];             // total compupters
    string *newarr = new string[c]; //add new computer

    for (int i = 0; i < c; i++)
        newarr[i] = "Free";

    for (int i = 0; i < num[l - 1]; i++)
        newarr[i] = arr[l - 1][i];

    arr[l - 1] = newarr;
    num[l - 1] = c;
}

//Logging into to the Computers(PC) in the respective lab the student wants by
void login()
{

    string name;
    int r, c;
    cout << endl
         << "Enter name of student: ";
    cin >> name;
    cout << endl
         << "Enter lab number: ";
    cin >> r;
    cout << endl
         << "Enter computer number: ";
    cin >> c;

    if (r > 4)
    {
        cout << endl
             << "Invalid lab number" << endl;
        return;
    }
    if (c > num[r - 1])
    {
        cout << endl
             << "Invalid computer number" << endl;
        return;
    }

    if (arr[r - 1][c - 1] == "Free")
        //cout<<"Free";
        arr[r - 1][c - 1] = name;
    else
        cout << endl
             << "The computer is already occupied.";
    more_login();
}

//ask user to do login again or not
void more_login()
{
    char ch1;
    cout << endl
         << "Do you want to login another student (Y/N) ? ";
    cin >> ch1;
    switch (ch1)
    {
    case 'Y':
    case 'y':
        login();
        break;

    case 'N':
    case 'n':
        break;
    }
}

//Logging out the student from the Computers(PC) from the respective lab the student was assigned
void logout()
{
    int r, c;
    cout << endl
         << "Enter lab number: ";
    cin >> r;
    cout << endl
         << "Enter computer number: ";
    cin >> c;

    if (r > 4)
    {
        cout << endl
             << "Invalid lab number" << endl;
        return;
    }
    if (c > num[r - 1])
    {
        cout << endl
             << "Invalid computer number" << endl;
        return;
    }

    if (arr[r - 1][c - 1] != "Free")
    {
        cout << " Logging out " << arr[r - 1][c - 1] << endl;
        arr[r - 1][c - 1] = "Free";
    }

    else
        cout << endl
             << "The computer is empty.";
    more_logout();
}
//Logging out any other student from the Computers(PC) from the respective lab that student was assigned
void more_logout()
{
    char ch1;
    cout << endl
         << "Do you want to logout another student (Y/N) ? "; //asking user to do next activity
    cin >> ch1;                                               //take input from the student
    switch (ch1)                                              // switch case that follow user's input and give appropriate output
    {
    case 'Y':
    case 'y':
        logout();
        break;

    case 'N':
    case 'n':
        break;
    }
}
//At first keeping all PC from Labs free and displaying it
void initialize()
{
    for (int i = 0; i < num[0]; i++)
        arr[0][i] = "Free";

    for (int i = 0; i < num[1]; i++)
        arr[1][i] = "Free";

    for (int i = 0; i < num[2]; i++)
        arr[2][i] = "Free";

    for (int i = 0; i < num[3]; i++)
        arr[3][i] = "Free";
}

//printing the current status of Computers(PC) in Labs
void show_labs()
{
    cout << endl
         << "Lab 1" << endl;
    for (int i = 0; i < num[0]; i++) //loop for lab1
        cout << " PC" << i + 1 << " -> " << arr[0][i] << endl;

    cout << endl
         << "Lab 2" << endl;
    for (int i = 0; i < num[1]; i++) //loop for lab2
        cout << " PC" << i + 1 << " -> " << arr[1][i] << endl;

    cout << endl
         << "Lab 3" << endl;
    for (int i = 0; i < num[2]; i++) //loop for lab3
        cout << " PC" << i + 1 << " -> " << arr[2][i] << endl;

    cout << endl
         << "Lab 4" << endl;
    for (int i = 0; i < num[3]; i++) //loop for lab4
        cout << " PC" << i + 1 << " -> " << arr[3][i] << endl;
}
