// MergeList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
using namespace std;
typedef struct node {
	int data;
	
	struct node* next;

}NODE, * PNODE;
class List
{
	PNODE Head;
public:
	List();
	~List();
	PNODE GetHead();
	void insertAtBegining(int element);
	void Display();
	void MergeList(List &l1,List &l2);
};
List:: List()
{
	Head == NULL;
}
List::~List()
{
	PNODE curr = Head, temp;
	if (curr != NULL)
	{
		while (curr != NULL)
		{
			temp = curr;

			curr = curr->next;
			cout << "Deleted data is" << temp->data << endl;
			delete temp;
		}

	}
}
PNODE List::GetHead()
{
	return Head;
}
void List:: insertAtBegining(int element)
{
	PNODE temp = NULL, curr = Head;
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
void List:: Display()
{
	PNODE curr = Head;
	if (curr != NULL)
	{
		while (curr != NULL)
		{
			cout << "|" << curr->data << "|--";
			curr = curr->next;

		}

	}
	cout << endl;
}
void List:: MergeList(List& l1, List& l2)
{
	PNODE curr1 = l1.GetHead();
	PNODE curr2 = l2.GetHead();
	while (curr1 != NULL && curr2 != NULL)
	{
		if (curr1->data > curr2->data)
		{
			insertAtBegining(curr1->data);
			curr1 = curr1->next;
		}
		else
		{
			insertAtBegining(curr2->data);
			curr2 = curr2->next;
		}
	}
	while (curr1 != NULL)
	{
		insertAtBegining(curr1->data);
		curr1 = curr1->next;
	}

	while (curr2 != NULL)
	{
		insertAtBegining(curr2->data);
		curr2 = curr2->next;
	}
}
int main()
{ 
	List l1;
	List l2;
	List l3;
	l1.insertAtBegining(2);
	l1.insertAtBegining(4);
	l1.insertAtBegining(6);
	l1.insertAtBegining(8);
	l1.Display();
	l2.insertAtBegining(1);
	l2.insertAtBegining(3);
	l2.insertAtBegining(5);
	l2.insertAtBegining(7);
	l2.Display();
	l3.MergeList(l1, l2);
	l3.Display();
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
