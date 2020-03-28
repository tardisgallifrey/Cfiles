#include <stdio.h>

/*	To show the way and effect of passing an array as 
*	a function argument.
*/

int compute_avg( int *array, int size )
{

	int index, sum=0;
	
	for( index = 0; index < size; ++index){
	
		sum += array[index];
	}
	
	return (sum/size);
	
}


void main(void)
{

	static int score[10] = { 10, 20, 30, 40, 50,
	                         60, 70, 80, 90, 100 };
	                         
	int i;			/* index */
	int average;		/* average value */
	
	printf("	Memory Loc	Array Element	Content\n");
	
	for( i = 0; i < sizeof(score)/sizeof(score[0]); i++){
	printf("	%d		score[%d]	%d\n", &score[i], i, score[i]);
	
	}
	
	
	average = compute_avg( score, sizeof(score)/sizeof(score[0]) );
	printf("\n Score Average = %d \n", average);
	
	
}
