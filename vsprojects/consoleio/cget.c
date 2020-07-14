
/*You want the "popen" function. Here's an example
 of running the command "ls /etc" and 
 outputing to the console.*/

#include <stdio.h>
#include <stdlib.h>


int main( int argc, char *argv[] )
{

  FILE *fp;
  char path[1035];

  /* Open the command for reading. */
  /* Use of wget -q -O - gets contents at
     URL and sends outpu to STDOUT, in this
     case, to the fp variable. */

  fp = popen("wget -q -O - http://localhost:47800/api/v1/bacnet/devices/1000/objects/0.12", "r");
  if (fp == NULL) {
    printf("Failed to run command\n" );
    exit(1);
  }

  /* Read the output a line at a time - output it. */
  while (fgets(path, sizeof(path), fp) != NULL) {
    printf("%s", path);
  }

  /* close */
  pclose(fp);

  return 0;
}
