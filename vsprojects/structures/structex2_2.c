#include <stdio.h>

int main()
{
	static int array[10] = {10,20,30,40,50,60,70,80,90,100};
	int *pntr;
	int i;
	
	printf("\n *** Example of pointer arith *pntr++ *** \n");
	printf("Memory Loc	Array Element	Content \n");
	
	for(i=0; i<10; i++)
	{
	printf("%d		array[%d]	%d\n", &array[i], i, array[i]);
	}
	
	pntr = array;
	
	printf("\n****** Note efect of '*pntr++'  ******\n");
	printf("Before *pntr++	:   pntr = %15d		array = %d\n", pntr, array);
	printf("At *pntr++	:  *pntr = %15d\n", *pntr++);
	printf("After *pntr++	:  *pntr = %15d		pntr = %d\n", *pntr, pntr); 
	
	pntr = array;
	
	printf("\n****** Note efect of '*(pntr++)'  ******\n");
	printf("Before *(pntr++)  :   pntr = %15d         array = %d\n", pntr, array);
	printf("At *(pntr++)      :  *pntr = %15d\n", *(pntr++));
	printf("After *(pntr++)   :  *pntr = %15d         pntr = %d\n", *pntr, pntr);
	
	pntr = array;
	
	printf("\n****** Note efect of '(*pntr)++'  ******\n");
	printf("Before (*pntr)++  :   pntr = %15d         array = %d\n", pntr, array);
	printf("At (*pntr)++      :  *pntr = %15d\n", (*pntr)++);
	printf("After (*pntr)++   :  *pntr = %15d         pntr = %d\n", *pntr, pntr);
	                        
	                        
}
