#include <stdio.h>
#include <stdlib.h> /* required for malloc() and free() */

int function1( int *myptr ); /* proper declaration of function */

 
int main()
{ 
    int x;            /* A normal integer*/
    int *p;           /* A pointer to an integer ("*p" is an integer, so p
                       must be a pointer to an integer) */
     /* Old way to do pointers */

    p = &x;           /* Read as: "assign the address of x to p: */
    printf("Enter an integer:  ");

    scanf( "%d", &x );  /* Put a value in x, we could also use p here */
    printf( "I point to an: %d\n", *p ); /* Note the use of the * to get the value */
    getchar();

    /* A better way to do pointers */
    int *ptr = malloc( sizeof(*ptr) );

    printf("Enter another integer: ");
    scanf("%d", ptr);
    printf("Your new integer is: %d\n", *ptr);
    getchar();

    /* How to pass value of a variable by reference using a pointer in a function */

    x = function1( ptr );
    printf("%d\n", *ptr);

    /* Required after done with the pointers */
    free( ptr );
    
}


/* a function to show passing values by reference using pointers */

int function1( int *myptr ){

     printf("If this worked correctly\n");
     printf("this value should be four more than\n");
     printf("entered.\n");

     return *myptr += 4;

}
