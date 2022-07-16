//From the Effective C book
//Professional C
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //Security requirements recommend
    //Not using printf to post user-data
    //therefore, puts is a better choice these days
    puts("Hello World!");
    printf("%s\n", "a forgotten way to printf");
    return EXIT_SUCCESS;
    
}