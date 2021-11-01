#include <stdio.h>

void functFor()
{
    int i; 

    for (i = 0; i < 5; i++)
    {
        if ((i % 2) == 0)
        {
            printf("%d\n", i);
        }
    }
}

// this program will print out all even numbers under 5 starting from 1.

/*

DIFFERENCE BETWEEN FOR AND WHILE LOOP:

the difference between for loop and while loop is that in for loop the number 
of iterations to be done is already known and is used to obtain a certain result 
whereas in while loop the command runs until a certain condition is reached and 
the statement is proved to be false.

also, in the absence of a condition, the for loop iterates for an infinite number of 
times till it reaches break command. whereas a while loop would show an error.

another difference is that the initialization in for loop is done only once when the program 
starts. a while loop's initialization is done every time the loop is iterated.

finally, for loops are used to obtain the result only when the number of iterations is known.
a while loop, is used to satisfy the condition when the number of iterations is unknown.

*/

void funcWhile()
{

    int i = 0;

    do {
        i++;
        if ((i % 2) == 0)
        {
            printf("%d\n", i);
        }
    } while (i < 5);

    for (i = 0; i < 5; i++)
    {
        i++;
        if ((i % 2) == 0)
        {
            printf("%d\n", i);
        }
    }
}

/*

While loop is executed only when given condition is true.
Whereas, do-while loop is executed for first time 
irrespective of the condition. After executing while loop for first time, then condition is checked.


*/


int main()
{
    int i = 0; //li - load immediate

    while (i < 5)
    {
        i++;
        if ((i % 2) == 0)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}