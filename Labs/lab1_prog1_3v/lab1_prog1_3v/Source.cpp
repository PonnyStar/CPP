#include "array.h"
#include <cstdlib>

const int len = 10;

int main()
{
	int myarray[len] = { 0 };
	int outputarray[len] = { 0 };

	initAgrs();	

	int cnt = processArray(myarray, len, outputarray);

	printInfo(myarray, len, outputarray, cnt);

	system("pause");

	return 0;
}