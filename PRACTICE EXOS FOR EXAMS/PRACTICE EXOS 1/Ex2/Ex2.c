/* Write a program that receives character input from the user and prints it in upper-case. 
The program terminates when the input is 'Q' or 'q'. */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
	char ch = ' ';

	while ((ch != 'q') & (ch != 'Q'))
	{
		printf("Enter a character:\n");
		scanf(" %c", &ch); //dont forget space or else the while will incorrectly print prompts twice
		printf("Your character: %c \n\n", toupper(ch)); //toupper returns caps of ch
	}

	return 0;
}