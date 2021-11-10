#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, num;
	int* arr = calloc(256,sizeof(int));

	printf("Enter amount of desired numbers: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("Enter a number: ");
		scanf("%d", &num);
		*(arr + i) = num;
	}

	printf("Reverse order: ");

	for (int i = n-1; i >= 0; i--)
		printf("%d ", *(arr + i));
	printf("\n");

	free(arr);
	return 0;
}