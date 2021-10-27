#include "Diamond.h"
#include<stdio.h>
#include<math.h>

void PrintLine(int i, int s)
{
	while (i != 0)
	{
		printf("%s", " ");
		i--;
	}

	while (s != 0)
	{
		printf("%s", "*");
		s--;
	}
	printf("%s", "\n");
}

int NumStars(int n, int i)
{
	return n - 2 * i;
}

void PrintDiamond(int d)
{
	int HalfSize = d / 2;

	for (int i = HalfSize; i > 0; i--)
	{
		PrintLine(i, NumStars(d, i));
	}

	PrintLine(0, d);

	for (int i = 1; i < HalfSize + 1; i++)
	{
		PrintLine(i, NumStars(d, i));
	}
}

