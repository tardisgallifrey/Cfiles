#include <stdio.h>
#include <stdlib.h>
#include "dave.h"

int main( int argc, char* argv[]){

char *mystring = (char*)malloc(255);

mystring=getstring(25);

fputs( mystring, stdout);

printf("\nEnter a character: ");
char a = getch();

printf("\nEnter a character: ");
char b = getche();

printf("\nYou entered, in order, %c and %c \n", a, b);

free(mystring);

return 0;
}



