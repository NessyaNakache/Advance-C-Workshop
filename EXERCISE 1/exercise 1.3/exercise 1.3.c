#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "CString.h"


int main()
{
	char str[100] = " ";
	printf("Enter a string: ");
	scanf("%s", str);
	printf("String Length = %d", CStrlen(str));

	return 0;
}