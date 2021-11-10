#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int SumOfArray(int* arr, int N)
{
	int sum = 0;

	for (int i = 0; i < N; i++)
		sum += arr[i];

	return sum;
}

int main()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	printf("sum = %d\n", SumOfArray(arr, 10));

	return 0;
}
