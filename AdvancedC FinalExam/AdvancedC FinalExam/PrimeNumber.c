#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include "PrimeNumber.h"

/**
* @num is the number to verify its primeness
* @flag signals if prime or not
*/
bool IsPrime(int num)
{
    int flag = 0;
    
    for (int i = 2; i <= num / 2; ++i) 
    {

        // if n is divisible by i, then n is not prime
        // change flag to 1 for non-prime number
        if (num % i == 0) {
            flag = 1;
            break;
        }
    }

    // 0 and 1 are not prime numbers nor composite
    if (num == 0 || num == 1) 
    {
        return false;
    }
    else 
    {
        // flag is 0 for prime numbers
        if (flag == 0)
            return true;
        else
            return false;
    }

}

/**
* @num is the integer that defines next prime number
*/
int CalculateNextPrime(int num)
{
    //increment num until it becomes a prime number
    do
    {
        ++num;
    } while (!IsPrime(num));

    return num;
}


/**
* @ input is the user's input, can simply be enter key
* @ Size is the dynamic size of PrimeArray
* @ PrimeArray is a dynamic array whose first element is initialized to 2, first prime number
*/
void GetNextPrime()
{
    char input;
    int Size = 1;
    int* PrimeArray = (int*)malloc(Size * sizeof(int));
    *PrimeArray = 2;

    printf("%d ", *(PrimeArray + (Size - 1)));


    do    
    {
        scanf("%c", &input);

        ++Size;
        PrimeArray = (int*)realloc(PrimeArray, Size * sizeof(int)); //dynamic reallocation
        *(PrimeArray + (Size - 1)) = CalculateNextPrime(*(PrimeArray + (Size - 2))); //last element is next prime number
        printf("%d ", *(PrimeArray + (Size - 1)));


    } while (!isdigit(input));
}
