#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <cstdlib>
#include <cstdio>


char* test_strcat(char* dest, char* src)
{
	int mark = 0;
	for (int i = strlen(dest); i < 255; i++)
	{
		*(dest + i) = *(src + mark++);
	}
	return dest;
}

int main()
{
	char dest[255] = {0};
	char destX[255] = {0};
	char src[255] = {0};

	scanf("%s", &dest);
	strcpy(destX,dest);
	scanf(" %s", &src);

	printf("\nlib: ");
	printf("%s\n", std::strcat(dest, src));
	printf("\ntest: ");
	printf("%s", test_strcat(destX, src));


	system("pause");
	return 0;
}