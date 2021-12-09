#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <math.h>

int DecToHex(int dec)
{
    int hex = 0 , temp, i = 0, remainder[100];

    while (dec != 0)
    {
        temp = dec % 16;
        dec /= 16;
        remainder[i] = temp;
        i++;
    }

    for (int j = 0; i != 0; j++, i--)
    {
        hex += remainder[j] * pow(10, i);
    }

    return hex;
}

void PrintHex(int address, int t_size)
{
    printf("%d", DecToHex(address));
}

int main()
{
    PrintHex(65, 0);
    return 0;
}