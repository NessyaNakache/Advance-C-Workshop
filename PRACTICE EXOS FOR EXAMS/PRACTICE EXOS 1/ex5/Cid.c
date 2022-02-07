#include "Cid.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define _CRT_SECURE_NO_WARNINGS

//convert id into an array of digits
void ArrID(int id, int arr[])
{
	arr[0] = 0; //to compensate for missing check digit
	for (int i = 1; i < 9; i++)
	{
		arr[i] = id % 10;
		id /= 10;	
	}
}

//using LuhnAlgo, calculate the check digit
int LuhnAlgorithm(int id)
{
	int arr[9], arrDoubleSum[9], sum = 0;

	ArrID(id, &arr);//convert id into array

	//insert digits into merged array of double and sum
	//double the value of every two digits
	//check that its lower than 9, else substract 9
	for (int i = 0; i < 9; i++)
	{
		if (i % 2 == 0)
			arrDoubleSum[i] = arr[i];
		else
		{
			arrDoubleSum[i] = arr[i] * 2;
			if (arrDoubleSum[i] > 9)
				arrDoubleSum[i] -= 9;
		}
		sum += arrDoubleSum[i]; //calculate the total sum of the values in arrDoubleSum
	}

	//the modulo 10 of the sum will bring us to the check digit
	return sum % 10;
}

int FixId(int id)
{
	int CDigit = LuhnAlgorithm(id);

	return id * 10 + (10 - CDigit); // check digit = 10 - sum%10, append it to invalid id
}

