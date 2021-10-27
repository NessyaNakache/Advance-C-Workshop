#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "Diamond.h"

int main()
{
	int num = 0;
	printf("Enter a number: ");
	scanf("%d", &num);
	PrintDiamond(num);
}