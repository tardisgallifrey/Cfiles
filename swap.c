//Effective C book

#include <stdio.h>

//function declaration
//declarations no long need variables, just types
void swap(int, int);

//better with pointers to fix bug from swap
//swap doesn't change original values, only creates new ones local to swap()
void swap_ptr(int*, int*);


int main(void)
{
    int a = 21;
    int b = 17;

    //This function swaps values,
    //but only local to the function
    //main is untouched
    swap(a, b);

    //This function swaps values at locations
    //sent, therefore main a and b are altered
    //as expected
    swap_ptr(&a, &b);

    printf("Main: a = %d, b = %d\n", a, b);
    return 0;

}

void swap(int a, int b)
{
    int t = a;
    a = b;
    b = t;
    printf("swap: a = %d, b = %d\n", a, b);

}

void swap_ptr(int *pa, int *pb)
{
    int t = *pa;
    *pa = *pb;
    *pb = t;
    return;
}