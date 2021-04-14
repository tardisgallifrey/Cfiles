#include <stdio.h>

void myFunction(void);

int main(void)
{
        myFunction();
        return 0;
}


void myFunction(void){

 int foo = 10, bar = 15;
        __asm__ __volatile__("addl  %%ebx,%%eax"
                             :"=a"(foo)
                             :"a"(foo), "b"(bar)
                             );
        printf("foo+bar=%d\n", foo);

}
