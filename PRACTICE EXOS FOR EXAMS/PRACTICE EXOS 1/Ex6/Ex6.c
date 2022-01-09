#include<stdio.h>
#include"Cid.h"

int main()
{
	printf("invalid Id: %d\n", 87654321);
	printf("fixed Id:   %d\n", FixId(87654321));

	return 0;
}