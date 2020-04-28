// Double
//LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include<stdio.h>
using namespace std;
typedef struct node {
	struct node* prev;
	int data;
	struct node* next;

}NODE, * PNODE;
class DlList
{
	PNODE Head;

public:
	DlList();
	~DlList();
	void insertFront(int ele);
	void insertEnd(int ele);
	void insertBefore(int ele, int beforeele);
	void insertAfter(int ele, int afterele);
	void Display();

};
DlList :: DlList()
{
	Head == NULL;
}
DlList::~DlList()
{
	
}
void DlList::insertFront(int ele)
{
	PNODE temp = NULL,curr=Head;
	temp = new NODE;
	temp->prev = NULL;
	temp->next = NULL;
	temp->data = ele;

	if (Head == NULL)
	   {
		Head = temp;
		}
	else
	{
		curr->prev = temp;
		temp->next = Head;
		Head = temp;
	}
		
}
void DlList::insertEnd(int ele)
{
	PNODE temp = NULL, curr = Head;
	temp = new NODE;
	temp->prev = NULL;
	temp->next = NULL;
	temp->data = ele;

	if (Head == NULL)
	{
		Head = temp;
	}
	else
	{
		while (curr->next != NULL)
		{
			curr = curr->next;
		
		}
		curr->next = temp;
		temp->prev = curr;
	}
}
void DlList::insertBefore(int ele, int beforeele)
{
	PNODE temp = NULL, curr = Head;
	temp = new NODE;
	temp->prev = NULL;
	temp->next = NULL;
	temp->data = ele;

	if (Head == NULL)
	{
		cout << beforeele << "not found in the list";
	}
	else if (Head->data == beforeele)
	{
		insertFront(ele);
	}
	else
	{
		while (curr != NULL && curr->data != beforeele)
		{
			curr = curr->next;
		}
		
		if (curr != NULL)
		{
			temp->prev = curr->prev;
			temp->next = curr;
			curr->prev->next= temp;
		}
		else
		{
			cout <<beforeele<< "not found in the list";
		}
	}
}
void DlList::insertAfter(int ele, int afterele)
{

}
void DlList::Display()
{
	PNODE curr = Head;
	if (Head == NULL)
	{
		cout << "List is Empty" << endl;
	}

	else
	{
		while (curr != NULL)
		{
			cout << "<--|" << curr->data << "|-->" ;
			curr = curr->next;
		}
	}
	cout << endl<<endl;
}
int main()
{
	DlList dl1;
	dl1.insertFront(40);
	dl1.insertFront(30);

	dl1.insertFront(20);
	dl1.insertFront(10);
	dl1.Display();
	//dl1.insertEnd(50);
	//dl1.Display();
	//dl1.insertEnd(60);
//	dl1.Display();
	dl1.insertBefore(70, 10);
	dl1.Display();
	dl1.insertBefore(80, 20);
	dl1.Display();
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
