#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int fibonacci(int n)
{
	int first = 0;
	int second = 1;
	int temp;

	for (int i = 0; i < n; i++)
	{
		temp = first;
		first += second;
		second = temp;
	}

	return second;
}

int main()
{
	int n = 5;
	printf("fib = %d\n", fibonacci(n));
}