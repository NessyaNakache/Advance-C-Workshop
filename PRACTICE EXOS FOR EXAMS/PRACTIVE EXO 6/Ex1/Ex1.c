/* Write a program that reads a number n from the user, followed by n other numbers.
The program will then print the numbers in reverse order. */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int Size, * ptr, num;

	printf("Enter number of elements: ");
	scanf("%d", &Size);

	ptr = (int*)malloc(Size * sizeof(int)); //dynamic allocation

	if (ptr == NULL) {
		printf("Error! memory not allocated.");
		exit(0);
	}

	printf("Enter elements: \n");

	for (int i = 0; i < Size; i++)
		scanf("%d", ptr + i);

	for (int i = Size - 1; i > -1; --i)
		printf("%d ", *(ptr + i));

	free(ptr);

}
