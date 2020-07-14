#include <stdio.h>

int main()
{
  char stringvar[100]; /* Use of scanf to enter strings MUST have sized arrays */
  char *name=stringvar; 
  
	printf("I am HAL, What is your name---> ");
	scanf("%s", name);
	printf("I can't open the pod bay doors, %s \n", name);
	return 0;
	
}
