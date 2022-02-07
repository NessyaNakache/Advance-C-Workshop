/* Write a program that receives an unknown number of numbers from the user.
   Input from the user ends when the user types a non-numeric string.
   The program will then print the numbers in reverse order.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main()
{
	char input;
	int flag = 1, Size = 0;
	char* ptr;
	
	ptr = (char*)malloc(Size * sizeof(char)); //dynamic allocation

	while (flag == 1)
	{
		scanf(" %c", &input);

		if (isdigit(input))
		{
			++Size;

			ptr = (char*)realloc(ptr, Size * sizeof(char)); //dynamic allocation
			*(ptr + (Size - 1)) = input;

		}
		else
			flag = 0;
	}

	for (int i = Size - 1; i >= 0; i--)
		printf("%c ", *(ptr + i));
}