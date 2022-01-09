/* Write a similar function that takes a variable’s address and its size in bytes, 
   but this time prints the binary representation of that variable. */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void PrintBin(void const* const ptr, size_t const size)
{
    unsigned char* b = (unsigned char*)ptr;
    unsigned char byte;
    int i, j;

    for (i = size - 1; i >= 0; i--)
    {
        for (j = 7; j >= 0; j--)
        {
            if (j == 3)
            {
                printf(" ");
            }
            byte = b[i] & (1 << j);
            byte >>= j;
            printf("%u", byte);
        }
        printf("\n");
    }
    printf("\n");
}


int main()
{
    char c = 'A';
    int i = 0x11223344;

    PrintBin(&c, sizeof(c));
    PrintBin(&i, sizeof(i));

}