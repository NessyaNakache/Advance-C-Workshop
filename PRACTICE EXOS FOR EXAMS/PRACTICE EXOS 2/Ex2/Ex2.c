#include<stdio.h>
#include <string.h>
#include"CString.h"

int main()
{
    char str[50]; // size of char string  
    printf(" Enter the string: ");
    gets(str); // use gets() function to take string  
    reverseWords(str);
    printf("%s", str);
    return 0;
}