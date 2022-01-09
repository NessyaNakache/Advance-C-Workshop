#define _CRT_SECURE_NO_WARNINGS
#include "CDiamond.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

bool CheckOddness(int num)
{
	if (num % 2 == 1)
		return true;
	else
		false;
}

void PrintLine(int i, int s)
{
	while (i != 0) //i reps number of spaces to be printed
	{
		printf("%s", " ");
		i--;
	}

	while (s != 0) //s reps number of stars to be printed
	{
		printf("%s", "*");
		s--;
	}
	printf("%s", "\n");
}

//calculates number of stars depending on which line were up to in diamond
int NumStars(int n, int i)
{
	return n - 2 * i;
}

void PrintDiamond(int d) //d reps diamond size == num of stars in middle line == num of lines in diamond
{
	//check if d is odd, else give new value to odd thats odd
	if (CheckOddness(d) == false)
	{
		int num = 0;
		printf("ERROR :  size is not an odd number!!! try again\n");
		printf("Enter new size of diamond: ");
		scanf(" %d", &num);
		d = num;
	}
	
	
	int HalfSize = d / 2; //halfsize represents number of lines of half of diamond

	//print first half of diamond
	for (int i = HalfSize; i > 0; i--)
	{
		PrintLine(i, NumStars(d, i));
	}

	PrintLine(0, d); //print full line of stars == middle line

	//print second half of diamond
	for (int i = 1; i < HalfSize + 1; i++)
	{
		PrintLine(i, NumStars(d, i));
	}
}