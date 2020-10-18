/*
Prashil Soni – S00375453
CSCI 6970, HW-5
(07/29/2020)
*/ 



#include <iostream>

using namespace std;

class Item{
public:
	int ID;
	int Type;
	int Price;
	string Name;

	Item() //default constructor
	{

	}

	virtual void print() //Virtual Function 
	{

	}

	float discountPrice(float rate)
	{
        return Price * (1.0 - rate);
	}
};

class Pen: public Item{
public:
    string inkColor;
    float PointSize;

    Pen(int ID, int Type, int Price,string name, string color, float pointsize) // Parameterized Constructor for class Pen
    {
        this->ID = ID;
        this->Type = Type;
        this->Name = name;
        this->Price = Price;
        this->inkColor = color;
        this->PointSize = pointsize;
    }

    void print() //The virtual print() called from class Item
    {
        cout<<endl<<"=================="<<" ID: "<<ID<<" "<<"==================";
        cout<<endl<<"Name: "<<Name;
        cout<<endl<<"Type: "<<Type;
        cout<<endl<<"Price: "<<Price<<"\t Ink Color: "<<inkColor<<"\tPointSize: "<<PointSize;
    }
};

class Folder: public Item{
public:
	string color;
	bool expanding;

	Folder(int ID, int Type, int Price,string name, string color, bool expanding ) //Parameterized Constructor for class Folder
	{
        this->ID = ID;
        this->Type = Type;
        this->Name = name;
        this->Price = Price;
        this->color = color;
        this->expanding = expanding;
	}

	void print() //The virtual print() called from class Item
	{
        cout<<endl<<"=================="<<" ID: "<<ID<<" "<<"==================";
        cout<<endl<<"Name: "<<Name;
        cout<<"\tType: "<<Type;
        cout<<endl<<"Price: "<<Price<<"\t Color: "<<color<<"\tExpanding: "<<expanding;
	}

};

class Paper: public Item{
public:
	string Size;
	int quantity;

	Paper(int ID, int Type, int Price,string name, string Size, int quantity) //Parameterized Constructor for class Paper
	{
        this->ID = ID;
        this->Type = Type;
        this->Name = name;
        this->Price = Price;
        this->Size = Size;
        this->quantity = quantity;
	}

	void print() //The virtual print() called from class Item
	{
        cout<<endl<<"=================="<<" ID: "<<ID<<" "<<"=================="; 
        cout<<endl<<"Name: "<<Name;
        cout<<endl<<"Type: "<<Type;
        cout<<endl<<"Price: "<<Price<<"\t Size: "<<Size<<"\t Quantity: "<<quantity;
	}
};
