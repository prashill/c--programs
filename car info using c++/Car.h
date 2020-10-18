#include<iostream>
#include<string.h>
using namespace std;

class Car
{
    public:

    string VIN;
    string make;
    string model;
    int year;
    int price;

    Car()
    {

    }

    Car(string newVIN, string newMake, string newModel, int newYear, int newPrice)
    {
        this->VIN = newVIN;
        this->make = newMake;
        this->model = newModel;
        this->year = newYear;
        this->price = newPrice;
    }

    void setVIN(string newVIN)
    {
        this->VIN = newVIN;
    }

    void setMake(string newMake)
    {
        this->make = newMake;
    }

    void setModel(string newModel)
    {
        this->model = newModel;
    }

    void setYear(int newYear)
    {
        this->year = newYear;
    }

    void setPrice(int newPrice)
    {
        this->price = newPrice;
    }

    string getVIN()
    {
        return VIN;
    }

    string getMake()
    {
        return make;
    }

    string getModel()
    {
        return model;
    }

    int getYear()
    {
        return year;
    }

    int getPrice()
    {
        return price;
    }

    void print()
    {
        cout<<endl<<"Car Data: "<<endl;
        cout<<"VIN: "<<VIN<<endl;
        cout<<"Make: "<<make<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Year: "<<year<<endl;
        cout<<"Price: "<<price<<endl;
    }
};
