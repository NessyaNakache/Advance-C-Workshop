/* Write a function that takes a variable’s address and its size in bytes, 
   then prints the hexadecimal representation of that variable from that address forward 
   (similar to Visual Studio’s memory view). */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void PrintHex(void* ptr, int size)
{
    unsigned char* p = ptr;
    int i;
    for (i = 0; i < size; i++) {
        printf("%02hhX ", p[i]);
    }
    printf("\n");
}

/*
Using %02hhx as the format string.

From CppReference, %02x accepts unsigned int. When you pass the arguments to printf(), which is a variadic 
function, buff[i] is automatically converted to int. Then the format specifier %02x makes printf() interprets 
the value as int, so potential negative values like (char)-1 get interpreted and printed as (int)-1, which is 
the cause of what you observed.
It can also be inferred that your platform has signed char type, and a 32-bit int type.
The length modifier hh will tell printf() to interpret whatever supplied as char type, so %hhx is the correct 
format specifier for unsigned char.
*/

void printBits(void const* const ptr, size_t const size)
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

    PrintHex(&c, sizeof(c));
    PrintHex(&i, sizeof(i));
    printBits(&c, sizeof(c));
    printBits(&i, sizeof(i));

}