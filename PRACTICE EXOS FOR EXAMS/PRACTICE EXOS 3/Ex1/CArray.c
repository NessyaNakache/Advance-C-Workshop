#include<stdio.h>
#include<stdlib.h>
#include "CArray.h"

#define FIB_SIZE 100
int FibArray[FIB_SIZE] = { 0,1 };


void printArray(int* arr, int length)
{
	for (int i = 0; i < length; i++)
		printf("%d ", arr[i]);

	printf("\n");
}

int mySum(int* arr, int length)
{
	int sum = 0;

	for (int i = 0; i < length; i++)
	{
		sum += arr[i];
	}

	return sum;
}

void Sort(int* arr, int length)
{
	int temp = 0;

	for(int i=0;i<length;++i)
		for (int j = 0; j < length; ++j)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
}

unsigned long long Fibonacci(int num)
{
	int n1 = 0, n2 = 1, temp = 0;

	if (num == 0 || num == -1)
		return n1;
	else
	{
		for (int i = 1; i < num; ++i)
		{
			temp = n2;
			n2 += n1;
			n1 = temp;
		}

		return n2;
	}
}

unsigned long long Exist(unsigned long long num)
{
	if (FibArray[num] != NULL)
		return FibArray[num];
	else
		return -1;

}

unsigned long long lazyFibonacci(unsigned long long num)
{
	unsigned long long n1 = 0, n2 = 1, temp = 0;

	if (Exist(num) != -1)
		return FibArray[num];
	else
	{
		FibArray[num] = Fibonacci(num);
		return FibArray[num];
	}
}

void printMatrix(int m[SIZE][SIZE], int S)
{

	for (int i = 0; i < S; i++)
	{
		for (int j = 0; j < S; j++)
			printf("\t%d", m[i][j]);
		printf("\n\n");
	}
}

void transposeMatrix(int m[SIZE][SIZE], int S)
{
	int temp[SIZE][SIZE];
	for (int i = 0; i < S; i++)
		for (int j = 0; j < S; j++)
			temp[j][i] = m[i][j];

	//copy elements of temp into m, so as m becomes its transpose
	for (int i = 0; i < S; i++)
		for (int j = 0; j < S; j++)
			m[i][j] = temp[i][j];
}

void upgradedTransposeMatrix(int m[SIZE][SIZE], int S)
{
	int temp[SIZE][SIZE];
	for (int i = 0; i < S; i++)
		for (int j = 0; j < S; j++)
			temp[j][i] = m[i][j];

	//copy elements of temp into m, so as m becomes its transpose
	for (int i = 0; i < S; i++)
		for (int j = 0; j < S; j++)
			m[i][j] = temp[i][j];

	if (checkSymmetry(m, S))
		printf("symmetric\n\n");
	
	if (checkSkewSymmetry(m, S))
		printf("skew symmetric\n\n");
	}

bool checkSymmetry(int m[SIZE][SIZE], int S)
{
	int cnt = 0, symmCnt = S * S;

	for (int i = 0; i < S; i++)
		for (int j = 0; j < S; j++)
			if (m[i][j] == m[j][i])
				++cnt;

	return cnt == symmCnt;
}

bool checkSkewSymmetry(int m[SIZE][SIZE], int S)
{
	int cnt = 0, skewCnt = S * S - S;

	for (int i = 0; i < S; i++)
		for (int j = 0; j < S; j++)
		{
			if (m[i][j] == -1 * m[j][i])
				++cnt;
			if (m[i][j] == 0)
				--cnt;
		}

	return cnt == skewCnt;
}