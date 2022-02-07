/* Write a function which receives an odd integer and prints a “diamond” made of ‘*’, 
where the integer specifies the diamond’s base.  */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"CDiamond.h"

int main()
{
	int num = 0;
	printf("Enter a number: ");
	scanf("%d", &num); //NEVER FORGET THE REFERENCE &
	PrintDiamond(num);
}