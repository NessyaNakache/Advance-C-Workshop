#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int NumInput()
{
	int input = 0, num = 0;

	do
	{
		num= num * 10 + input;
		scanf(" %d", &input);
	} while (input != 0);

	return num;
}

void PrintReverse(int num)
{
	while (num != 0)
	{
		printf("%d", num % 10);
		num /= 10;
	}
}

int main()
{
	int number = NumInput();
	printf("\n%d\n", number);
	PrintReverse(number);
}