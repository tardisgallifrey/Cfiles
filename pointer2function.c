#include <stdio.h>

//A function to compare two ints
int compare(int x, int y)
{
	return (x > y) ? 1 : 0;  //if x>y then return 1 else 0
}

//a function to sum two ints
int sum( int x, int y)
{
	return x + y;
}


//general purpose function with pointer to a function as variable
//receives var x. receives var y. receives pointer to function
int func( int x, int y, int (*sfunc)())
{
	return (*sfunc)(x, y); //creates call to function passed in args 
				// with x and y passed as args to function pointer
}


int main()
{

	int x = 1;
	int y = 4;
	int compare(), sum(); //create vars of functions compare and sum
	int (*cfunc)();       //create var of pointer to func (empty)
	
	// assign address of function compare to cfunc
	cfunc = compare;
	printf("result = %d\n", func(x, y, cfunc)); //func gets x, y, and compare()
	                                            //result is 0

	//assign the address of function sum to cfunc
	cfunc = sum;
	printf("\nresult = %d\n", func(x, y, cfunc)); //func gets x, y, and sum()
						      //result is 5	                                            
}
