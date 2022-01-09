/* Write a program that receives character input from the user and prints it.
The program terminates when the input is 'Q' or 'q'. */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char ch = ' ';

	while ((ch != 'q') & (ch != 'Q'))
	{
		printf("Enter a character:\n");
		scanf(" %c", &ch); //dont forget space or else the while will incorrectly print prompts twice
		printf("Your character: %c \n\n", ch);
	}

	return 0;
}