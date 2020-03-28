#include <stdio.h>
#include <string.h>  /* required for handling strings strlen() */
#include <stdlib.h>  /* required for malloc() */

int main( ){


	char *buffer=malloc(50);				/* Use malloc to set a buffer pointer */
	char buff1[50]="How now brown cow.";			/* Set a character array to work with later */


	FILE *fp;						/* Create a pointer of FILE type */

	if(fp=fopen("test.txt", "a+")){				/* If our file open for append (a+) succeeds */

   		fprintf(fp, "Testing...\n");			/* Append the text to the file */
                printf("Wrote \"Testing...to test.txt\n");

	} else {

		printf("File doesn't exist or file problem\n");
	}/* Close of if-else*/

	fclose(fp);						/* Close file pointer */

	if(fp=fopen("test.txt","r")){				/* If our file open for read succeeds */
   
   		fscanf(fp, "%s", buffer);			/* Read in the file (line by line or total?) */
   		printf("We read %s from test.txt\n", buffer);				/* Put string in buffer and print it out */
	} else {

                printf("File doesn't exist or file problem\n");
        }/* Close of if-else*/


	fclose(fp);


	buffer = buff1;						/* set buffer to point at buff1 string */

	if(fp=fopen("test.txt", "a+")){				/* if our open for append succeeds */

   		for( long x = strlen(buffer); x != 0; x--){	/* loop through buffer using decrement counter 
								   strlen returns a long integer, x has to match type */
      			fputc(*buffer, fp);			/* send one character of buffer to file   */
                        printf("Wrote %c to test.txt\n", *buffer);
      			buffer++;				/* increment posiiton of counter (address in memory) in buffer */
   		}

	fputc('\n', fp);					/* add a newline for clarity  */

	} else {

                printf("File doesn't exist or file problem\n");
        }/* Close of if-else*/


	fclose(fp);
   


}  /* End of main */
