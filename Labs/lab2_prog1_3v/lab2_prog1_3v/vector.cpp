#include "vector.h"

#include <iostream>
#include <iomanip>

using namespace std;

#define PI 3.14159265358979323846

Vector::Vector()
{
}

Vector::Vector(int lenght)
{
	nLenght = lenght;
	pArray = new double[lenght];
}


Vector& Vector::operator++()
{
	for (int i(0); i < nLenght; i++)
	{
		*(pArray + i) += 1.0;
	}
	return *this;
}

Vector& Vector::operator--()
{
	for (int i(0); i < nLenght; i++)
	{
		*(pArray + i) -= 1.0;
	}
	return *this;
}

Vector Vector::operator++(int)
{
	Vector vect = this->copyVector();
	for (int i(0); i < nLenght; i++)
	{
		*(pArray + i) += 1.0;
	}
	return vect;
}

Vector Vector::operator--(int)
{
	Vector vect = this->copyVector();

	for (int i(0); i < nLenght; i++)
	{
		*(pArray + i) -= 1.0;
	}
	return vect;
}


double Vector::operator[](int index)
{
	if (index < nLenght && index >= 0)
		return *(pArray + index);
	else
		return NULL;
}

void Vector::printVector()
{
	cout << "[";
	for (int i(0); i < nLenght; i++)
	{
		cout << setprecision(5) << " " << *(pArray + i);
	}
	cout << " ]";
}


Vector::~Vector()
{
	delete[] pArray;
}

double* Vector::getpArray()
{
	return pArray;
}

Vector Vector::copyVector()
{
	Vector tmp(this->nLenght);

	for (int i = 0; i < this->nLenght; i++)
	{
		*(tmp.getpArray() + i) = *(this->getpArray() + i);
	}

	return tmp;
}