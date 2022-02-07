#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "CArray.h"



int main()
{
	int array[] = { 6,7,2,4,3,2,1,9 };
	int length = sizeof(array) / sizeof(*array);


	/*  Exercise 1
		Write a function that receives an array of integers and returns the sum of all its elements. 
	*/

	printf("sum = %d\n\n", mySum(array, length));

	printf("\n\n\n\n");



	/*  Exercise 2
		Write a function that receives an array of numbers and sorts them from smallest to largest. 
		do not allocate additional memory dynamically or use other arrays.
	*/

	printf("array before sort: ");
	printArray(array, length);

	printf("array after sort: ");
	Sort(array, length);
	printArray(array, length);

	printf("\n\n\n\n");



	/*  Exercise 3
		Write a function that, given a number n, returns the nth Fibonacci number.
	*/
	
	int c1 = 0;

	while (c1 != -1)
	{
		printf("Enter a number: ");
		scanf("%d", &c1);

		if (c1 == -1)
			printf("exit\n\n");
		else {
			printf("\n%dth number of fibonacci is %lu\n\n", c1, Fibonacci(c1));
		}
	} 

	printf("\n\n\n\n");




	/*  Exercise 4
		Optimize your Fibonacci function using lazy evaluation. 
		Make it work on n ≤ 100. What would your parameter types need to be for that?
	*/

	int c2 = 0;

	printf("lazy fibonacci\n");

	while (c2 != -1)
	{
		printf("Enter a number: ");
		scanf("%d", &c2);

		if (c2 == -1)
			printf("exit\n\n");
		else if (c2 > 100)
		{
			printf("ERROR : number too large!!! try again\nEnter a number: ");
			scanf("%d", c2);
			printf("\n%dth number of fibonacci is %lu\n\n", c2, lazyFibonacci(c2));
		}
		else {
			printf("\n%dth number of fibonacci is %lu\n\n", c2, lazyFibonacci(c2));
		}
	}

	printf("\n\n\n\n");



	/*  Exercise 5
		Write a function that receives a square matrix (which parameters would the function require?) 
		and transposes it in-place.
	*/
	
	int Size = 3;
	int matrix[SIZE][SIZE] = { {1,4,7},{2,5,8},{3,6,9} };

	printf("before transpose:\n\n");
	printMatrix(matrix, Size);

	transposeMatrix(matrix, Size);

	printf("after transpose:\n\n");
	printMatrix(matrix, Size);
	printf("\n\n\n\n");

	/* Upgrade your function so that it also returns whether the input matrix is symmetric, 
	skew-symmetric, or none of the above.
	*/

	int symmMatrix[SIZE][SIZE] = { {0,2,3},{2,5,6},{3,6,9} };
	int skewMatrix[SIZE][SIZE] = { {0,2,3},{-2,5,6},{-3,-6,9} };

	//using symmMatrix
	printf("before transpose:\n\n");
	printMatrix(symmMatrix, Size);

	upgradedTransposeMatrix(symmMatrix, Size);

	printf("after transpose:\n\n");
	printMatrix(symmMatrix, Size);
	printf("\n\n\n\n");

	//using skewMatrix
	printf("before transpose:\n\n");
	printMatrix(skewMatrix, Size);

	upgradedTransposeMatrix(skewMatrix, Size);

	printf("after transpose:\n\n");
	printMatrix(skewMatrix, Size);
	printf("\n\n\n\n");

}