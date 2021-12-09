#include "PrintBin.h"
#include <stdio.h>

void toBin(void* addrs, int size)
{
	//tun void ptr to char ptr
	char* p = (unsigned char*)addrs;
	//go through each byte in the char
	for (char i = 0; i < size; i++) {
		//convert each bit into binary and print
		for (int j = 0; j < 8; j++) {
			printf("%d", !!((*(p + i)) & 0x80));
			//print space between each byte
			if (j == 3) {
				printf(" ");
			}
		}
		printf("\n");
	}
}