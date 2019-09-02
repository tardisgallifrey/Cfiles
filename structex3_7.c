#include <stdio.h>


/*	Funciton to compute sum of all elements of the 
 *	Matrix A; return sum demonstrating the pasing
 *	of a two-dimensional array as an argument.
 *	Note that row size of A is not specified
 */
 
int compute_sum( int A[][4], int row_size, int col_size)
{
  int index_1, index_2;
  int sum;
  
  sum = 0;
  
  for( index_1 = 0; index_1 < row_size; ++index_1)
  {
  	for(index_2 = 0; index_2 < col_size; ++index_2 )
  	{
  		sum += A[index_1][index_2];
  		printf("SUM is %d\n", sum );
  	}
  }
  
  return (sum);

}


void main(void)
{

static int A[4][4]=
	{ {  2, -1,  7,  5 },
	  { 22, 10,  3, -4 },
	  { 32,  1, -7,  5 },
	  { 42, 11, -5,  4 } };

int sum=0;	  

sum = compute_sum( int A[][4], sizeof(A)/sizeof(A[0]), sizeof(A[0])/sizeof(A[0][0]) );

printf("SUM is %d\n", sum);

}
