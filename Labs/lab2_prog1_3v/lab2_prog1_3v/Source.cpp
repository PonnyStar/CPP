#include "matrix.h"
#include "vector.h"

#include <stdlib.h>
#include <iostream>

int main()
{
	Matrix* matrix = new Matrix(4,4);
	matrix->initialize();
	matrix->printMatrix();

	Vector* vector = matrix->make1DArray();
	vector->printVector();


	delete vector;
	delete matrix;

	std::cout << std::endl;
	system("pause");
}