
#include "array.h"
#include <cstdlib>


int main()
{
	double** matrix = initMatrix();
	double* myarray = convertMatrix(matrix);

	printInfo(matrix, myarray);
	system("pause");


	delete[] myarray;
	for (int i = 0; i < 4; i++)
		delete[] * (matrix + i);

	delete[] matrix;

	return 0;

}