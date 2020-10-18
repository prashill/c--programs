/*
Semih Dinc-MY_STUDNET_NUMBER: S00375453 (SONI PRASHIL)
CSCI 2000, HW-2
06-29-2020

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

//Function Declarations
int Show_Menu();   //To show main menu
void Show_Chart(); //To show seating chart
void savefile();
const char FULL = '#';   //Seat taken
const char EMPTY = '-';  //Seat open
const int rows = 15;     //Number of rows
const int columns = 30;  //Number of seats per row
char map[rows][columns]; //Array to hold seating chart
int total = 0;
int seat = 450;
int seat2 = 0;
int Quit = 1;

int main()
{
    string line;
    const int Num_Rows = 15;
    int row2, column2, cost;
    int answer;


    for (int i = 0; i < rows; i++) //loop for rows and columns
    {
        for (int j = 0; j < columns; j++)
            map[i][j] = EMPTY;
    }

    ifstream fin; //taking input from tickets.txt file
    fin.open("tickets.txt");

    try
    {
        while (getline(fin, line))
        {

            istringstream ss(line);
            int x = 0, r = 0, c = 0;
            while (ss)
            {
                string word;
                ss >> word;

                stringstream geek(word);
                //convert word to integer
                int z = 0;
                geek >> z;

                if (x == 0)
                {
                    r = z;

                    x = 1;
                }
                else if (x == 1)
                {
                    c = z;
                    x = 2;
                }
            }

            map[(r - 1)][(c - 1)] = FULL;
        }
    }
    catch (std::exception &e)
    {
        cout << "Exception occured";
    }
    fin.close();

    int choice;   
    do
    {
        choice = Show_Menu(); // Shows the main menu function.
        switch (choice)
        {
        case 1:     
            cout << "View Available Seats\n\n";   
            Show_Chart();
            break;
        case 2:     
            cout << "Sell a Ticket\n\n";
            do
            {
                cout << "Please select the row you would like to sit in: ";
                cin >> row2;
                cout << "Please select the seat you would like to sit in: ";
                cin >> column2;
                if (map[(row2 - 1)][(column2 - 1)] == FULL)
                {
                    cout << "Sorry that seat is sold-out, Please select a new seat.";
                    cout << endl;
                }
                else
                {
                    cout << "Confirm Purchase? Enter (1 = YES / 2 = NO)";
                    cin >> answer;
                    seat = seat - answer;
                    seat2 += answer;

                    if (answer == 1)
                    {
                        cout << "Your ticket purchase has been confirmed." << endl;
                        map[(row2 - 1)][(column2 - 1)] = FULL;
                    }
                    else if (answer == 2)
                    {
                        cout << "Would you like to look at another seat? (1 = YES / 2 = NO)";
                        cout << endl;
                        cin >> Quit;
                    }

                    cout << "Would you like to look at another seat?(1 = YES / 2 = NO)";
                    cin >> Quit;
                }
            } while (Quit == 1);

            break;

        case 4: 
            savefile();
            break;

        case 5:
            cout << "quit\n";
            break;
        default:
            cout << "Error input\n";
        }
    } while (choice != 5);
    return 0;
}

//**  Define Functions. **

// Show Menu Function...
int Show_Menu()
{
    int MenuChoice;

    cout << endl
         << endl;
    cout << " \tMAIN MENU\n";
    cout << " 1. View Current seats.\n";
    cout << " 2. Sell Ticket.\n";
    cout << " 3. Refund a ticket.\n";
    cout << " 4. Save the file.\n";
    cout << " 5. Quit the program.\n";
    cout << "_____________________\n\n";
    cout << "Please enter your choice: ";
    cin >> MenuChoice;
    cout << endl
         << endl;

    return MenuChoice;
}

//Show Seating Chart Function
void Show_Chart()
{
    cout << "\tSeats" << endl;
    cout << "   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 \n";
    for (int count = 0; count < 15; count++)
    {
        cout << endl << " " <<(count + 1);
        for (int count2 = 0; count2 < 30; count2++)
        {
            cout << "  " << map[count][count2];
        }
    }
    cout << endl;
}

void savefile()         // to view the data of available seats from the input file
{
    ofstream fout;
    fout.open("tickets.txt");
    for (int count = 0; count < 15; count++)
    {
        for (int count2 = 0; count2 < 30; count2++)
        {
            if (map[count][count2] == FULL)
            {
                cout << count << "  " << count2;
                fout << (count + 1) << "  " << (count2 + 1) << endl;
            }
        }
    }

    fout.close();
}
