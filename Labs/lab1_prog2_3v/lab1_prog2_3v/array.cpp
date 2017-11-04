
#include "array.h"

#include <cmath>
#include <iostream>
#include <iomanip>

const int n = 4;

double** initMatrix()
{
	double** outmatrix = new double*[n];

	for (int i = 0; i < n; i++)
		*(outmatrix + i) = new double[n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(*(outmatrix + i) + j) = sqrt(i + j + 1);
		}
	}
	return outmatrix;
}


double* convertMatrix(double** matrix)
{
	double* myarray = new double[n*n];

	int mark = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= 0; --j)
		{
			*(myarray + mark++) = *(*(matrix + i) + j);
		}
	}

	return myarray;
}

void printInfo(double** matrix, double* myarray)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << std::setprecision(3) << *(*(matrix + i) + j) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < n*n; i++)
	{
		std::cout << std::setprecision(5) << *(myarray + i) << " ";
	}
}