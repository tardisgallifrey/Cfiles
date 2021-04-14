#include <stdio.h>
#include <stdlib.h>

int main(){

FILE *fp;
fp=fopen("test.bin", "rb");
char x[10]="";
fread(x, sizeof(x[0]), sizeof(x)/sizeof(x[0]), fp);

printf("%s\n", x);

fclose(fp);



}
