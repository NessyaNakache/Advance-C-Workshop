#include <stdio.h>

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

// this program will print out all even numbers under 5 starting from 1.


void assemblyEquivalence()
{
    __asm{
        li $x, 0;  //int i = 0

        li 0x0A, 5; //limit = 5

        //while loop
        mov eax, $x;
        cmp eax, 0x0A;
        jg end;
    beginning :
        inc eax; //i++

        //i%2
        mov ecx, 2;
        cdq; //this will clear EDX due to the sign extension
        idiv ecx;
        
        comp edx, $zero;
        jl printf;
        jle beginning;

    printf:
        //idk

        cmp eax, 0x0A;
        jle beginning;
    end :


    }
}