#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include "TestProgram.h"
#include"PrimeNumber.h"

// test cases for bool IsPrime(int num);

void TCZeroBoundary()
{
	int num = 0;

	if (IsPrime(num))
	{
		printf("num = %d is a prime number\n", num);
	}
	else
	{
		printf("num = %d is NOT a prime number\n", num);

	}
}

void TCOneBoundary()
{
	int num = 1;

	if (IsPrime(num))
	{
		printf("num = %d is a prime number\n", num);
	}
	else
	{
		printf("num = %d is NOT a prime number\n", num);

	}
}

void TCNonPrimeBoundary()
{
	int num = 6;

	if (IsPrime(num))
	{
		printf("num = %d is a prime number\n", num);
	}
	else
	{
		printf("num = %d is NOT a prime number\n", num);

	}
}

void TCPrimeBoundary()
{
	int num = 7;

	if (IsPrime(num))
	{
		printf("num = %d is a prime number\n", num);
	}
	else
	{
		printf("num = %d is NOT a prime number\n", num);

	}
}

void TCExtremeNonPrimeBoundary()
{
	int num = 1239465;

	if (IsPrime(num))
	{
		printf("num = %d is a prime number\n", num);
	}
	else
	{
		printf("num = %d is NOT a prime number\n", num);

	}
}

void TCExtremePrimeBoundary()
{
	int num = 7919;

	if (IsPrime(num))
	{
		printf("num = %d is a prime number\n", num);
	}
	else
	{
		printf("num = %d is NOT a prime number\n", num);

	}
}

//test cases for int CalculateNextPrime(int num);
void TCCalcForZero()
{
	int num = 0;
	int prime = CalculateNextPrime(num);

	printf("The next prime number after %d is %d\n", num, prime);
}

void TCCalcForOne()
{
	int num = 1;
	int prime = CalculateNextPrime(num);

	printf("The next prime number after %d is %d\n", num, prime);
}

void TCCalcForSmallNonPrime()
{

	int num = 14;
	int prime = CalculateNextPrime(num);

	printf("The next prime number after %d is %d\n", num, prime);
}
void TCCalcForSmallPrime()
{
	int num = 3;
	int prime = CalculateNextPrime(num);

	printf("The next prime number after %d is %d\n", num, prime);
}
void TCCalcForExtremeNonPrime()
{

	int num = 17246;
	int prime = CalculateNextPrime(num);

	printf("The next prime number after %d is %d\n", num, prime);
}
void TCCalcForExtremePrime()
{

	int num = 7919;
	int prime = CalculateNextPrime(num);

	printf("The next prime number after %d is %d\n", num, prime);
}

//test cases for void GetNextPrime();

void TCVersionGetNextPrime(int n)
{
	int Size = 1;
	int* PrimeArray = (int*)malloc(Size * sizeof(int));
	*PrimeArray = 2;

	printf("%d ", *(PrimeArray + (Size - 1)));

	for(int i=0;i<n;i++)
	{
		++Size;
		PrimeArray = (int*)realloc(PrimeArray, Size * sizeof(int)); //dynamic allocation
		*(PrimeArray + (Size - 1)) = CalculateNextPrime(*(PrimeArray + (Size - 2)));
		printf("%d ", *(PrimeArray + (Size - 1)));


	} 
}

void TCZeroLoop()
{
	printf("TCZeroLoop\n");
	int n = 0;
	TCVersionGetNextPrime(n);

	printf("\n\n\n");
}

void TCOneLoop()
{
	printf("TCOneLoop\n");
	int n = 1;
	TCVersionGetNextPrime(n);

	printf("\n\n\n");
}

void TCFiftyLoop()
{
	printf("TCFiftyLoop\n");
	int n = 50;
	TCVersionGetNextPrime(n);

	printf("\n\n\n");
}

void TCTenThousandLoop()
{

	printf("TCTenThousandLoop\n");
	int n = 10000;
	TCVersionGetNextPrime(n);

	printf("\n\n\n");
}

void IntegralTesting()
{
	TCZeroBoundary();
	TCOneBoundary();
	TCNonPrimeBoundary();
	TCPrimeBoundary();
	TCExtremeNonPrimeBoundary();
	TCExtremePrimeBoundary();

	//test cases for int CalculateNextPrime(int num);
	TCCalcForZero();
	TCCalcForOne();
	TCCalcForSmallNonPrime();
	TCCalcForSmallPrime();
	TCCalcForExtremeNonPrime();
	TCCalcForExtremePrime();

	//test cases for void GetNextPrime();
	TCZeroLoop();
	TCOneLoop();
	TCFiftyLoop();
	TCTenThousandLoop();
}
