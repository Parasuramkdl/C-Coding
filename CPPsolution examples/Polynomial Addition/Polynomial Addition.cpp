// Polynomial Addition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include<stdio.h>
using namespace std;
typedef struct node {
	int coeficient;
	int power;
	struct node* next;
	
}NODE,* PNODE;
class Polynomial
{
	PNODE Head;

public:
	Polynomial();
	~Polynomial();
	PNODE GetPloynomialHead();
	void insertAtBegining(int coef, int pow);
	void Addition(Polynomial &p1, Polynomial  &p2);
    void Display();
};
Polynomial::Polynomial()
{
	Head = NULL;

}
PNODE Polynomial::GetPloynomialHead()
{
	return Head;
}
Polynomial::~Polynomial()
{
	PNODE curr = Head,temp;
	if (curr != NULL)
	{
		while (curr != NULL)
		{
			temp = curr;
			
			curr = curr->next;
			delete temp;
		}

	}
}
void Polynomial::insertAtBegining(int coef,int pow)
{
	PNODE temp = NULL, curr = Head;
	temp = new NODE;
	temp->coeficient =coef ;
	temp->power = pow;
	temp->next = NULL;

	if (Head == NULL) {
		Head = temp;
	}
	else
	{
		temp->next=Head;
		Head = temp;
	}
}
void Polynomial::Display()
{
	PNODE curr = Head;
	if (curr != NULL)
		while (curr != NULL)
		{
			cout << curr->coeficient << "X^" << curr->power;
			
			if (curr->next != NULL)
			{
				cout<<"+";
			}
			curr = curr->next;
		}
	cout << endl<<endl;
	
}
void Polynomial:: Addition( Polynomial &p1,Polynomial  &p2)
{
	PNODE curr1 = p1.GetPloynomialHead();
	PNODE curr2 = p2.GetPloynomialHead();


	while (curr1 != NULL && curr2 != NULL)
	{
		if (curr1->power == curr2->power)
		{
			insertAtBegining(curr1->coeficient+curr2->coeficient, curr1->power);
			curr1 = curr1->next;
			curr2 = curr2->next;
		}
		else if (curr1->power > curr2->power)
		{
			insertAtBegining(curr1->coeficient, curr1->power);
			curr1 = curr1->next;
		}
		else
		{
			insertAtBegining(curr2->coeficient, curr2->power);
			curr2 = curr2->next;
		}
	}
	

	
		while (curr1 != NULL)
		{
			insertAtBegining(curr1->coeficient, curr1->power);
			curr1 = curr1->next;
		}
	
		while (curr2 != NULL)
		{
			insertAtBegining(curr2->coeficient, curr2->power);
			curr2 = curr2->next;
		}

  
}
int main()
{
	Polynomial p1;
	Polynomial p2;
	Polynomial p3;
	p1.insertAtBegining(2,0);
	p1.insertAtBegining(3, 1);
	p1.insertAtBegining(4, 2);
	p1.insertAtBegining(5, 3);
	p1.Display();
	p2.insertAtBegining(3,0);
	p2.insertAtBegining(4, 1);
	p2.insertAtBegining(6, 2);
	p2.insertAtBegining(4, 3);
	p2.Display();
	p3.Addition(p1, p2);
	p3.Display();
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
