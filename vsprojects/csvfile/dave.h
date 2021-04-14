/* my special header file for my own functions */


#include <termios.h>				/*needed for getch() and getche() */
#include <stdio.h>


/*Variable declarations */
static struct termios old, new;			/*needed for getch() and getche() */


/*Function declarations*/
char* getstring( int length );
void initTermios(int echo);
void resetTermios(void);
char getch_(int echo);
char getch(void);
char getche(void);
void gotoxy(int x,int y);
void clrscr(void);

char* getstring( int length ){

char *buffer = (char*)malloc(255);
char buff_char;

for(int i=0; i < length; i++){

   buff_char = getc(stdin);

   if( buff_char == '\n'){

      buffer[i]='\0';
      return buffer;

   }else{

      buffer[i]=buff_char;

   }
}

buffer[length]='\0';
return buffer;
}



/*						*/
/*The following are copied from;		*/
/*htts://includehelp.com			*/
/*						*/


/* Initialize new terminal i/o settings */
void initTermios(int echo){

  tcgetattr(0, &old); //grab old terminal i/o settings
  new = old; //make new settings same as old settings
  new.c_lflag &= ~ICANON; //disable buffered i/o
  new.c_lflag &= echo ? ECHO : ~ECHO; //set echo mode
  tcsetattr(0, TCSANOW, &new); //apply terminal io settings

}



/* Restore old terminal i/o settings */
void resetTermios(void){

  tcsetattr(0, TCSANOW, &old);

}



/* Read 1 character - echo defines echo mode */
char getch_(int echo){

  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;

}


/*Read 1 character without echo
  getch() function definition.*/
char getch(void){

  return getch_(0);

}


/*Read 1 character with echo
    getche() function definition.*/
char getche(void){

  return getch_(1);

}


/*gotoxy() function definition*/
void gotoxy(int x,int y){

    printf("%c[%d;%df",0x1B,y,x);
}


/*clrscr() function definition*/
void clrscr(void){

    system("clear");
}



