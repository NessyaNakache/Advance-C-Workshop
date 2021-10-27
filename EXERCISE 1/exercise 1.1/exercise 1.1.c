#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch = ' ';

    while ((ch != 'q') & (ch != 'Q'))
    {
        printf("Enter a character: ");
        scanf_s(" %c", &ch, 1);
        printf("Entered character: %c\n", ch);
    }

    return 0;
}
