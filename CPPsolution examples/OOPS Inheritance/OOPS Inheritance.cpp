// OOPS Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
using namespace std;

class Vehicle
{
public:
	char vehicletype[256];
	int noofwheels;
	Vehicle();
	Vehicle(char *type,int wheels);
	~Vehicle();
	virtual void Mode() = 0;
};
Vehicle::Vehicle()
{
	
	strcpy_s(vehicletype, "");
	noofwheels = 0;
}
Vehicle::Vehicle(char* type, int wheels)
{
	strcpy_s(vehicletype, type);
	noofwheels = wheels;
}

Vehicle::~Vehicle()
{

}
class Fourwheeler :public Vehicle
{
 public:
	void Mode()
	{
		cout << "This is fourwheeler " << endl;
		cout << "The type of vehicle is " << vehicletype << "and noofwheels are " << noofwheels << endl;;
	}
	Fourwheeler(char *type,int wheels);
	~Fourwheeler();
};
Fourwheeler::Fourwheeler(char *type,int wheels)
{
	strcpy_s(vehicletype, type);
	noofwheels = wheels;
}
Fourwheeler::~Fourwheeler()
{

}
class Bicycle :public Vehicle
{
 public:
	void Mode()
	{
		cout << "This is twowheeler " << endl;;
		cout << "The type of vehicle is " << vehicletype << "and noofwheels are " << noofwheels << endl;;
	}
	Bicycle(char *type,int wheels);
	~Bicycle();
};
Bicycle::Bicycle(char *type,int wheels):Vehicle(type,wheels)
{
	//strcpy(vehicletype, type);
	//noofwheels = wheels;
}
Bicycle::~Bicycle()
{

}
int main()
{
	
	
	char str[] = "Car";
	Fourwheeler f(str, 4);
	Fourwheeler *ptr = &f;
	ptr->Mode();
	char str1[] = "Bicycle";
	Bicycle b(str1, 2);
	Bicycle *ptr1 = &b;
	ptr1->Mode();
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
