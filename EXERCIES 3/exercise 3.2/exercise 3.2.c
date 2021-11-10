#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int SortArray(int arr[], int N)
{
	int temp;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
	return arr;
}

void PrintArray(int* arr, int N)
{

	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
}

int main()
{
	int const SIZE = 8;
	int arr[] = { 6,3,9,6,8,10,3,2 };
	int* sortedArr = SortArray(arr, SIZE);
	PrintArray(sortedArr, SIZE);

	return 0;
}