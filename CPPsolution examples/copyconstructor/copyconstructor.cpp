// copyconstructor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
using namespace std;
class String {
	char* ptr;
  public:
	  String()
	  {
		  ptr = NULL;
	  }
	String(const char *str)
	{
		ptr = new char[strlen(str)+1];
		strcpy_s(ptr, strlen(str) + 1, str);
		
		
	}
void 	print()
	{
	cout << ptr;
	}
	~String()
	{
		if (ptr != NULL)
		{
			delete[] ptr;
		}
	}
	String(const String &str)// copy constructor
	{
		ptr = new char[strlen(str.ptr) + 1];
		strcpy_s(ptr, strlen(str.ptr) + 1, str.ptr);

	}
	String& operator= (const String& s)
	{
		ptr = new char[strlen(s.ptr) + 1];
		strcpy_s(ptr, strlen(s.ptr) + 1, s.ptr);
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& out, const String& s1);
 };
std::ostream& operator<<(std::ostream& out, const String& s)
{
	out << s.ptr;
	return out;
}
int main()
{
	String *s1 = new String("Hello");

	
	String s2 = *s1;
	s1->print();
	//s2.print();
	delete s1;
	//s2.print();
	String s4;
	s4 = s2;
	cout << s2;


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
