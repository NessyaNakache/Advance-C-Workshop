#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

#define SIZE 3


void printMatrix(int m[SIZE][SIZE], int S)
{

	for (int i = 0; i < S; i++)
	{
		for (int j = 0; j < S; j++)
			printf("\t%d", m[i][j]);
		printf("\n\n");
	}
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

int main()
{
	int matrix[SIZE][SIZE] = { {0,2,3},{2,5,6},{3,6,9} };
	int matrix1[SIZE][SIZE] = { {0,2,3},{-2,5,6},{-3,-6,9} };

	printMatrix(matrix, SIZE);

	
	printMatrix(matrix1, SIZE);

	
}