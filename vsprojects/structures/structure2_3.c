#include <stdio.h>

int modify( int *ip) //receive the pointer
{
	return *ip + 4;  //adds 4 to value of x
}

int modify_x( int *ip)  //receive the pointer
{
	*ip = 2;       //reassigns x to equal 2 (overwrites value stored at x)
	return *ip/2;
}

int main()
{
	int y=0, x = 4;
	int *p = &x;   //*p points to x
	int modify(), modify_x();  //LEGAL to declare functions as ints


	printf("y and x unmodified y = %d x = %d\n\n", y,x);
		
	y = modify(p);  //pass the pointer, which is X not Y
	//at this point, x == 4 and y == 8
	//The function takes action on X and sends the result back to Y
	
	printf("on use of modify() (y = x + 4)");
	printf("  y = %d  x = %d\n", y,x);
		
	y = modify_x(p);   //pass the pointer, which is X not Y
	//at this point, x == 2, and y == 1

	printf("\non use of modify_x() (x is changed to 2: y = x / 2) ");
	printf("y = %d x = %d\n", y,x);

}


