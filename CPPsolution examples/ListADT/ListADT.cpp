// ListADT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
using namespace std;
typedef struct node {
	int data;
	struct node* next;

}NODE,*PNODE;
class List
{
	PNODE Head;
	

public:
	List();
	~List();

	void insertAtBegining(int element);
	void insertAfter(int ele,int afterele);
	void insertBefore(int ele, int beforeele);
	void insertEnd(int ele);
	void DeleteBegining();
	void DeleteEnd();
	void DeleteSpecific(int ele);
	void Display();
	bool Find(int ele);
	void selfAdjust(int ele);
};
List::List()
{
	Head = NULL;
}
List::~List()
{

}

void List::insertAtBegining(int element)
{
	PNODE temp=NULL,curr=Head;
	temp = new NODE;
	temp->data = element;
	temp->next = NULL;

	if (Head == NULL) {
		Head = temp;
	}
	else
	{
		temp->next = Head;
		Head = temp;
	}
}
void List::insertAfter(int ele,int afterele)
{
	PNODE temp = NULL,curr=Head;
	temp = new NODE;
	temp->data = ele;
	temp->next = NULL;
	
	if (Head == NULL) {
		cout << "item not found" << endl;
	}
	else
	{
		
		while (curr != NULL &&  curr->data != afterele)
		{
			curr = curr->next;
		}
		if (curr != NULL)
		{
			temp->next = curr->next;
			curr->next = temp;
		}
		else
		{
			cout << "Search Element not found in the List" << endl;
		}
	}
}
void List::insertEnd(int ele)
{
	PNODE curr = Head,temp=NULL;
	temp = new NODE;
	temp->data = ele;
	temp->next = NULL;
	if (Head == NULL)
	{
		insertAtBegining(ele);
	}
	else
	{
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = temp;
	}
}
void List::insertBefore(int ele, int beforeele)
{
	PNODE temp = NULL, curr = Head;
	temp = new NODE;
	temp->data = ele;
	temp->next = NULL;
	if (Head == NULL) {
		cout << "item not found" << endl;
	}
	else if (Head->data == beforeele)
	{
		Head = temp;
		temp->next = curr;
	}


	else
	{
		while (curr->next != NULL && curr->next->data != beforeele)
		{
			curr = curr->next;
	    }

		if (curr->next != NULL)

		{
			temp->next = curr->next;
			curr->next = temp;
		}
		else {
			cout << "Search Element not found in the List" << endl;
		}
		
	}
}
void List::DeleteBegining()
{
	PNODE curr = Head;
	if (Head == NULL) {
		cout << "List is empty cannot perform delete" << endl;
	}
	else
	{
		Head = curr->next;
		delete curr;
	}
}
void List::DeleteEnd()
{

	PNODE curr = Head;
	if (Head == NULL) {
		cout << "List is empty cannot perform delete" << endl;
	}
	if (Head->next == NULL)
	{
		delete Head;
		Head = NULL;
	 }
	else {
		while (curr->next->next != NULL)
		{
			curr = curr->next;
		}
		delete curr->next;
		curr->next = NULL;
	}
}
void List::DeleteSpecific(int ele)
{
	PNODE curr = Head,temp=NULL;
	if (Head == NULL) {
		cout << "List is empty cannot perform delete" << endl;
	}
	else if (curr->next == NULL && curr->data == ele)
	{
		DeleteBegining();
	}
	else if (curr->data == ele)
	{
		temp = curr;
		Head = Head->next;
		delete temp;
		
	}
	else
	{
		
		while (curr->next != NULL && curr->next->data != ele)
		{
			curr = curr->next;
	    }
		if (curr->next != NULL)
		{
			temp = curr->next;
			curr->next = curr->next->next;
			delete temp;
		}
		else {
			cout << "Search Element not found in the List" << endl;
		}
	}
}
void List::Display()
{
	PNODE curr = Head;
	if (curr != NULL) 
	{
		while (curr != NULL)
		{
			cout << "|" << curr->data<<"|--";
            curr = curr->next;
			
		}
		
	}
}
bool List::Find(int ele)
{
	PNODE curr = Head;
	
		while (curr != NULL)
		{
			if (ele == curr->data)
			{
				selfAdjust(ele);
				cout << "The element found in the list" << ele << endl;
				return true;
			}
			else
			{
				curr = curr->next;
			}
		}
	
	    cout << "search element not found in the list" << endl;
		return false;
	}
void List::selfAdjust(int ele)
{
	DeleteSpecific(ele);
	insertAtBegining(ele);
}
int main()
{
	List l1;
	l1.insertAtBegining(10);
	l1.insertAtBegining(20);
	l1.insertAtBegining(30);
	l1.insertAtBegining(40);
	l1.insertAtBegining(50);
	/*l1.insertAfter(60, 30);
	l1.insertAfter(70, 20);
	l1.insertAfter(80, 10);
	l1.Display();
	cout << "" << endl;
	/*l1.insertEnd(90);
	l1.insertEnd(100);
	l1.insertEnd(110);
	l1.insertEnd(120);
	l1.insertEnd(130);
	l1.Display();
	cout << "" << endl;
	l1.insertBefore(140, 20);
	l1.insertBefore(150, 50);
	l1.Display();
	cout << "" << endl;
	l1.DeleteBegining();
	l1.Display();
	cout << "" << endl;
	l1.DeleteBegining();
	l1.Display();
	cout << "" << endl;
	l1.DeleteEnd();
	l1.Display();
	cout << "" << endl;
	l1.DeleteSpecific(70);
	l1.Display();
	cout << "" << endl;
	l1.DeleteSpecific(180);
	l1.Display();
	cout << endl << endl;*/
	l1.Find(50);
	l1.Display();
	cout << endl;
	l1.Find(40);
	l1.Display();
	cout << endl;
	l1.Find(130);
	l1.Display();
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
