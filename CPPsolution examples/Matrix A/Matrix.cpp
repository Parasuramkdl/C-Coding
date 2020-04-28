// Matrix A.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class Matrix {

	int rows, columns;
	int** Arr;
public:
	Matrix();
	Matrix(int r, int j);
	~Matrix();
	int MatrixDialgonalSum();
};
Matrix::Matrix()
{
	rows = 0;
	columns = 0;
}
Matrix::Matrix(int r,int c)
{
	rows = r;
	columns = c;

	Arr = (int**)new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		Arr[i] = (int*)new int[columns];


	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			Arr[i][j] = 1;
		}

	}


}
Matrix::~Matrix()
{

	

	for (int i = 0; i < rows; i++)
	{
		delete Arr[i];
	}
	delete[] Arr;

}
int Matrix::MatrixDialgonalSum()
{
	int sum = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (i > j)
			{
				sum = sum + Arr[i][j];
			}
		}

	}
	return sum;
}



int main()
{
	Matrix m1(3,3);
	cout << "Matrix diagonal sum is " << m1.MatrixDialgonalSum() << endl;
	


	return 0;

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
