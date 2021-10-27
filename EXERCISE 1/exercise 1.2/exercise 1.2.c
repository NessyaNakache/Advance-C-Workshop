#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char ch = ' ';

    while ((ch != 'q') & (ch != 'Q'))
    {
        printf("Enter a character: ");
        scanf_s(" %c", &ch, 1);
        printf("Entered character: %c\n", toupper(ch));
    }
}
