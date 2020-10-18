#include<iostream>
#include<string.h>
#include<fstream>
#include "Car.h"
using namespace std;

void printAllCars();  // This Method is declared for displaying all the cars
void printByMake();    // Method is declared for showing the cars based on their model
void printByPrice();  // Method is declared for displaying the care based on price



//Declaration
Car cars[250];
    string VIN;
    string make;
    string model;
    int year;
    int price;
ifstream fin;

int main()
{

    int choice;
    int i = 0;
    fin.open("cardata.txt"); //Reading the file
     
    while (fin >> VIN >> make >> model >> year >> price)
    {
        //fetching the data from file and storing it into cars[] array.
        cars[i++] = Car(VIN, make, model, year, price);
    }
    fin.close();

    do
    {
        //Making user select the options from 1 to 4
        cout << endl
             << "Menu" << endl;
        cout << "1.Print All Cars" << endl
             << "2.Print All Cars By Make" << endl
             << "3.Print All Cars By Price" << endl;
        cout << "4.Exit" << endl
             << "What do you want to do?  ";
        cin >> choice;

        switch (choice)
        {
            //if the user enters 1 then printAllCars method will be called
        case 1:
            printAllCars(); //Calling the method
            break;
            //if the user enters 2 then printByMake method will be called
        case 2:
            printByMake(); //Calling the method
            break;
            //if the user enters 1 then printByPrice method will be called
        case 3:
            printByPrice(); //Calling the method
            break;
        case 4:
            cout << endl
                 << "Exiting" << endl;
            break;
        default:
            cout << endl
                 << "Enter valid choice " << endl;
        }
    } while (choice != 4);

    return 0;
}

void printAllCars() // Now, this Method is defined for displaying all the cars
{
    int i = 0;
    while (i < 250) //This loop will search all the 250 cars
    {
        cout << endl
             << "For Car " << i << endl;
        cars[i].print(); //It will print the data of the cars one by one till the loop is running
        i++;
    }
    cout << endl
         << "There are 250 cars in total " << endl;
}

void printByMake() // Now, this method is declared for showing the cars based on their model name
{
    string newmodel;
    int j = 0;
    cout << "Enter model name: ";
    cin >> newmodel;
    cout << "Printing All Cars With Model " << newmodel << endl;
    for (int i = 0; i < 250; i++) //This loop will search all the 250 cars
    {
        if (cars[i].model == newmodel) //condition will check the model name and it will match it from the cars[i] with the help of loop
        {
            cars[i].print(); // if the condition satisifes then it will display the data the cars of that model name
            j++;
        }
    }
    cout << endl
         << "There are " << j << " cars with model " << newmodel << endl;
}

void printByPrice() // Now, this method is declared for showing the cars based on their price
{
    int newprice, j = 0;
    cout << "Enter maximum price allowed: ";
    cin >> newprice;
    cout << "Printing All Cars Under Price " << newprice << endl;
    
    for (int i = 0; i < 250; i++) //This loop will search all the 250 cars
    {
        if (cars[i].price < newprice) //condition will check the max price and it will match it from the cars[i] with the help of loop
        {
            cars[i].print(); // if the condition satisifes then it will display the data all the cars 
            j++;
        }
    }
    cout << endl
         << "There are " << j << " cars under price " << newprice << endl;
}

