#include<stdio.h>

int main()
{
	int a = 1, b = 0, x;
	if (a < b)
	{
		x = -1;
	}
	else {
		x = 1;
	}

	__asm{
		cmp    ax, bx;
		jl     Less;
		mov    word[X], 1;
		jmp    Both;
	Less:
		mov    word[X], -1;
	Both:
	}

    int i;

    switch (i)
    {
    case 1:
    {
        printf("Case 1\n");
        break;
    }
    case 2:
    {           printf("Case 2\n");
    break;
    }
    case 3:
    {
        printf("Case 3\n");
        break;
    }
    case 4:
    {
        printf("Case 4\n");
        break;
    }
    case 5:
    {
        printf("Case 5\n");
        break;
    }
    case 6:
    {
        printf("Case 6\n");
        break;
    }
    case 7:
    {
        printf("Case 7\n");
        break;
    }
    case 8:
    {
        printf("Case 8\n");
        break;
    }
    case 9:
    {
        printf("Case 9\n");
        break;
    }
    case 10:
    {
        printf("Case 10\n");
        break;
    }
    default:
    {
        printf("Nothing\n");
        break;
    }
    }

	__asm {
        movl    $5, -4(% ebp)
        cmpl    $10, -4(% ebp)
        ja  L13
        movl - 4(% ebp), % eax
        sall    $2, % eax
        movl    L14(% eax), % eax
        jmp*% eax
        .section.rdata, "dr"
        .align 4
        L14:
        .long   L13
            .long   L3
            .long   L4
            .long   L5
            .long   L6
            .long   L7
            .long   L8
            .long   L9
            .long   L10
            .long   L11
            .long   L12
            .text
            L3 :
        movl    $LC0, (% esp)
            call    _printf
            jmp L2
            L4 :
        movl    $LC1, (% esp)
            call    _printf
            jmp L2
            L5 :
        movl    $LC2, (% esp)
            call    _printf
            jmp L2
            L6 :
        movl    $LC3, (% esp)
            call    _printf
            jmp L2
            L7 :
        movl    $LC4, (% esp)
            call    _printf
            jmp L2
            L8 :
        movl    $LC5, (% esp)
            call    _printf
            jmp L2
            L9 :
        movl    $LC6, (% esp)
            call    _printf
            jmp L2
            L10 :
        movl    $LC7, (% esp)
            call    _printf
            jmp L2
            L11 :
        movl    $LC8, (% esp)
            call    _printf
            jmp L2
            L12 :
        movl    $LC9, (% esp)
            call    _printf
            jmp L2
            L13 :
        movl    $LC10, (% esp)
            call    _printf
            L2 :
	}



    int x = (a < b) ? -1 : 1;

    __asm {
        cmp    ax, bx;
        jl     Less;
        mov    word[X], 1;
        jmp    Both;
    Less:
        mov    word[X], -1;
    Both:
    }
}