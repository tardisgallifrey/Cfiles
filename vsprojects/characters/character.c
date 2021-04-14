#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

char* getstring(int length, int mode);

int main(int argc, char* argv[]){

char *mystring=(char*)malloc(2550);

mystring=getstring(25,1);

fputs(mystring, stdout);
fputc('\n',stdout);

return 0;
}

char* getstring(int length, int mode){

char c;
char *buffer= (char*)malloc(255);

initscr();
raw();
if(mode == 1){

   echo();

}else{

  noecho();

}

   for( int i = 0; i < length; i++){

      c = getch();
      buffer[i]=c;

      if( c == '\n'){

         buffer[i + 1]='\0';
         endwin();
         return buffer;

      }
   }
buffer[length]='\0';
endwin();
return buffer;

}
