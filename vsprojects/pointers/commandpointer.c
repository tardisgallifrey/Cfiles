#include <stdio.h>
#include <stdio.h>

 
int main ( int argc, char *argv[] )
{

char *fname;
int  count;
 

printf("There were %d files on the command line.\n", argc-1);

    if ( argc < 2 ) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "\n\tusage: %s filename\n", argv[1] );
    }
    else
    {
  
         for(count=argc;count > 0;count--){

                fname = argv[count];
                printf("Opening file %s\n", fname);

      		// We assume argv[1] is a filename to open
        	FILE *file = fopen( fname, "r" );
 
        	/* fopen returns 0, the NULL pointer, on failure */
        	if ( file == 0 )
        	{
            		printf( "Could not open file\n" );
        	}
        	else
        	{
            		int x;
            		/* read one character at a time from file, stopping at EOF, which
               		   indicates the end of the file.  Note that the idiom of "assign
               		   to a variable, check the value" used below works because
               		   the assignment statement evaluates to the value assigned. */
            		while  ( ( x = fgetc( file ) ) != EOF )
            		{
                		printf( "%c", x );
            		}
            		fclose( file );
                    
                        printf("%s\n", fname);
        	}
	}
    }


}
