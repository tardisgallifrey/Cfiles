#include <stdio.h>
#include <string.h>  /* required for handling strings strlen() */
#include <stdlib.h>  /* required for malloc()  */
#include <ctype.h>   /* required for isdigit() */
#include "dave.h"    /* required for getstring() */


int main( int argc, char* argv[] ){

char *csv_buffer=(char*)malloc(255);
char *filename_buffer = (char*)malloc(50);
FILE *file_handle;
int arg_num;

clrscr();

if( argc == 2 ){

  for( int i=0; i < strlen(argv[1]); i++){

      if( isdigit(argv[1][i])){

         arg_num = atoi(argv[1]);

      }else{

          printf("You did not enter a number. Exiting...\n");
          exit(1);

      }
   }

   printf("Enter a filename of your choice,\n ");
   printf("  No filename extension needed:  ");

   filename_buffer = getstring(50);
   strcat(filename_buffer, ".csv");
   printf("Your filename will be: %s \n", filename_buffer);

   if( file_handle=fopen(filename_buffer, "a+")){

      for(int c=0 ;c < arg_num; c++){

         printf("Enter a line of CSV data, separated by commas:\n ");
         csv_buffer=getstring(255);
         csv_buffer[strlen(csv_buffer)] = '\n';
         fputs(csv_buffer, file_handle);

      }

   }else{

      printf("Could not open file: %s\n", filename_buffer);
      exit(1);

   }


}else{

  printf("Usage: csv 'num' : where 'num' is\n");
  printf("         quantity of csv records you desire.\n");
}

fclose(file_handle);

}  /* End of main */
