#include "matrix.h"

#include <iostream>
#include <iomanip>



using namespace std;

Matrix::Matrix(int r, int c) : r(r), c(c)
{
	pMatrix = new double*[r];

	for (int i(0); i < r; i++)
		*(pMatrix + i) = new double[c];
}

void Matrix::initialize()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			*(*(pMatrix + i) + j) = sqrt(i + j + 1);
		}
	}

}

Vector* Matrix::make1DArray()
{
	Vector* tmp_vector = new Vector(r * c);
	
	int mark = 0;

	for (int i = 0; i < r; i++)
	{
		for (int j = c - 1; j >= 0; --j)
		{
			*(tmp_vector->getpArray() + mark++) = *(*(pMatrix + i) + j);
		}
	}

	return tmp_vector;

}

void Matrix::printMatrix()
{

	for (int i(0); i < r; i++)
	{
		for (int j(0); j < c; j++)
		{
			cout << setprecision(3) << setw(10) << *(*(pMatrix + i) + j);
		}
		cout << endl;
	}
	cout << "\n\n\n" << "=>" << "\n\n\n";
}

double Matrix::at(int i, int j) const
{
	return *(*(pMatrix + i) + j);
}

void Matrix::setAt(int i, int j, double value)
{
	*(*(pMatrix + i) + j) = value;
}

Matrix::~Matrix()
{
	for (int i(0); i < r; i++)
	{
		delete[] *(pMatrix + i);
	}
}
