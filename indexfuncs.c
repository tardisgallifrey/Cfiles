//Effective C book
//Exercise to declare an array of pointers to functions and 
//choose which function to do based on index value.
#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b)
{
    printf("The sum of %d and %d is %d\n", a, b, a + b);
}

int square(int a, int b)
{
    printf("The square of %d is %d\n", a, a * a);
}

int diff(int a, int b)
{
    printf("The difference of %d from %d is %d\n", a, b, b - a);
}


int main(void){

//had to look this up on Stack Overflow
//https://stackoverflow.com/questions/14071378/c-initialize-an-array-of-pointers-to-functions#14071430
//Use last answer
int (*mathfunc[3])(int, int) = { sum, diff, square };

int a = 2;

switch(a){
    case 0 :
        mathfunc[a](4, 5);
        break;
    case 1 :
        mathfunc[a](4, 5);
        break;
    case 2 :
        mathfunc[a](4, 0);
        break;
    default :
        puts("You did something wrong.");

}

return 0;

}