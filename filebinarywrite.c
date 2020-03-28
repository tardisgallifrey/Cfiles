#include <stdio.h>
#include <stdlib.h>

int main(){

FILE *fp;
if(fp=fopen("test.bin", "wb")){
   char x[10]="ABCDEFGHI\n";
   fwrite(x, sizeof(x[0]), sizeof(x)/sizeof(x[0]), fp);
   } else {
          printf("Could not open file.\n");
   }


fclose(fp);



}
