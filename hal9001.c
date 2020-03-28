#include <stdio.h>
#include <stdlib.h> /* needed for fgets() function */

int main()
{
  char stringvar[100];
  char *name=stringvar; 
  
	printf("I am HAL, What is your name---> ");
	fgets(name, 100, stdin);
	printf("I can't open the pod bay doors, %s \n", name);
	return 0;
	
}
