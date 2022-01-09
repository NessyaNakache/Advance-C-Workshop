#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int NumInput()
{
	int input = 0, num = 0;

	do
	{
		num = num * 10 + input;
		scanf(" %d", &input);
	} while (input != 0);

	return num;
}

void PrintMax(int num)
{
	int max = 0, digit = 0;
	while (num != 0)
	{
		digit = num % 10;

		if (max < digit)
			max = digit;

		num /= 10;
	}

	printf("max: %d\n", max);
}

void PrintMin(int num)
{
	int min = 10, digit = 0;
	while (num != 0)
	{
		digit = num % 10;

		if (min > digit)
			min = digit;

		num /= 10;
	}

	printf("min: %d\n", min);
}

int main()
{
	int number = NumInput();
	printf("\n%d\n", number);
	PrintMax(number);
	PrintMin(number);
}