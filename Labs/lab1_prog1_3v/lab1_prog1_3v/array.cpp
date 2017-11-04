
#include "array.h"
#include <iostream>
#include <cstdio>
#include <iomanip>

int b, q;
using namespace std;
void initAgrs()
{
	printf("Enter b ");
	scanf_s("%d", &b);
	printf("Enter q ");
	scanf_s("%d", &q);
}

int processArray(int* myarray, int len, int* outarray)
{
	myarray[0] = b;
	
	for (int i = 1; i < len; i++)
	{
		myarray[i] = myarray[i - 1] * q;
	}

	int cnt = 0;

	for (int i = 0; i < len; i++)
	{
		if (myarray[i] / 100 > 0 && myarray[i] / 100 < 10)
		{
			++cnt;
		}
	}
	
	int mark = 0;
	for (int i = 0; i < len; i++)
	{
		if (myarray[i] % 3 != 1)
		{
			outarray[mark++] = myarray[i];
		}
	}

	return cnt;
}

void printArray(int* myarray, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ",myarray[i]);
	}
}

void printInfo(int* myarray, int len, int* outarray, int cnt)
{

	printf("\nstart");
	for (int i = 0; i < len; i++)
	{
		printf("%d ", myarray[i]);
	}
	printf("\ncount: %d", cnt);

	printf("\noutput");
	for (int i = 0; i < len; i++)
	{
		if (outarray[i] != 0)
			printf("%d ", outarray[i]);
	}
}