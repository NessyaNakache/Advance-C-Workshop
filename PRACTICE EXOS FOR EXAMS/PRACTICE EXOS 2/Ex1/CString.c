#include<stdio.h>
#include"CString.h"

void revstr(char* str1)
{
    // declare variable  
    int i, len, temp;
    len = strlen(str1); // use strlen() to get the length of str string  

    // use for loop to iterate the string   
    for (i = 0; i < len / 2; i++)
    {
        // temp variable use to temporary hold the string  
        temp = str1[i];
        str1[i] = str1[len - i - 1];
        str1[len - i - 1] = temp;
    }
}

// Function to reverse any sequence
// starting with pointer begin and
// ending with pointer end
void reverse(char* begin, char* end)
{
    char temp;
    while (begin < end) {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

// Function to reverse words*/
void reverseWords(char* s)
{
    char* word_begin = s;

    // Word boundary
    char* temp = s;

    // Reversing individual words as
    // explained in the first step
    while (*temp) {
        temp++;
        if (*temp == '\0') {
            reverse(word_begin, temp - 1);
        }
        else if (*temp == ' ') {
            reverse(word_begin, temp - 1);
            word_begin = temp + 1;
        }
    }

    // Reverse the entire string
    reverse(s, temp - 1);
}

