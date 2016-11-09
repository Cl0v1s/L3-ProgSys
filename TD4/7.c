#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>

jmp_buf buffer;


void f()
{
    longjmp(buffer,10);
}

int  g()
{
    return setjmp(buffer);
}

int main()
{
    int i = 0 ;
    int r;
    r = g();
    printf("%d %d\n",i, r);
    i++;
    if(i<5)
        f();
    return 0;
}