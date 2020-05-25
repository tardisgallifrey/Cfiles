#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void myFunction();

int main( int argc, char* argv[1]){

char *buffer= malloc( 50 * sizeof(char));

myFunction();

printf("%c\n", argv[1][0]);
int num = atoi(argv[1]);
printf("%d\n", num);


}



void myFunction()
{
printf("Before asm\n");

asm("movl %ecx, %eax\n\t");

printf("After asm");
}
