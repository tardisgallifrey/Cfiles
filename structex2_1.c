#include <stdio.h>

//Program: example01.c
//Purpose: demonstrate use of pointers in C
//From: Structures in ANSI C book

int main()
{
	int a, b = 199, c;
	int *pointer_1;   //pointer to an integer variable
	
	//pointer 1 has no contect.  Allocates space for ptr var only.
	
	printf("\n Enter a = ");
	scanf("%d", &a);
	
	pointer_1 = &a; //assign pointer_1 to point at variable a
	
	printf("\n Content of a: %3d  Address of a: %d\n ", a, pointer_1);
	printf(" Content of Pointer to a: %d \n", pointer_1);
	
	//assign a value to a using the pointer
	*pointer_1 = -200;
	
	printf("\n Content of a: %3d  Address of a: %d\n ", *pointer_1, pointer_1);
	printf(" Content of Pointer to a: %d \n", pointer_1);

	//calculate c = a + b 
	c = a + b;
	pointer_1 = &c;  //reassign poiner_1 to point at c
	
	printf("\n Content of c: %3d  Address of c: %d\n ", c, pointer_1);
	printf(" Content of Pointer to c: %d \n\n", pointer_1);
}
