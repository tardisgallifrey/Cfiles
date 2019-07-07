#include <stdio.h>

struct SX  //declares a type of struct called SX
{
	//SX contains two int vars, x and y
	int x;
	int y;
} X;  //declares a variable instance of struct type SX, called X


//declare a function of type SX, LEGAL, which is a pointer to the function
struct SX *funcB()
{
	extern struct SX X; //declare a local struct X
	struct SX *Xp = &X; //declare a local ptr to a struct and assign it X address 
	
	return Xp;         //return the pointer pointing at X
}

int main()
{
	struct SX *ip;       //declare a pointer to a struct of type SX
	struct SX *funcB();  //declare a pointer to the function B of type SX
	
	ip = funcB();
	// *ip is assigned the address of X, through funcB()
	
	printf( "struct values before reassignment\n");
	printf("ip->x %d, ip->y %d\n", ip->x, ip->y);
	
	ip->x = 8;
	ip->y = 4;
	//X.x == 8 and X.y == 4
	
	
	printf("\n\nstruct values after reassignment\n");
	printf("ip->x %d, ip->y %d\n", ip->x, ip->y);
}
