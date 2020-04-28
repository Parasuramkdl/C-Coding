#include "Polar.h"
#include<iostream>
#include<stdio.h>
using namespace std;

// Initialize static member of class Polar
int Polar::count = 0;
Polar::Polar()
{
	cout << "Constructor called." << endl;
	m_angle=0;
	m_radius=0;
	count++;
}
Polar ::Polar(float a, int r)
{
	cout << "Constructor called." << endl;
	m_angle = a;
	m_radius = r;
	count++;
}
void Polar::PrintPolarCount()
{
	cout << "Total no of objects: " <<Polar::count << endl;
}
Polar::~Polar()
{
	count--;
}
