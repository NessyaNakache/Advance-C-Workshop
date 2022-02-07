/* Write a function that receives a string and prints its characters in reverse. */
#include<stdio.h>
#include<string.h>
#include"CString.h"

int main()
{
    char str[50]; // size of char string  
    printf(" Enter the string: ");
    gets(str); // use gets() function to take string  

    printf(" \n Before reversing the string: %s \n", str);

    // call revstr() function   
    revstr(str);
    printf(" After reversing the string: %s", str);
}
