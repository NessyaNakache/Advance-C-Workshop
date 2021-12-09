#include <stdio.h>
#include "PrintBin.h"

int main(void)
{
	int n = 0x11223344;
	toBin(&n, sizeof(n));

	return 0;
}