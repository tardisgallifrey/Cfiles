#include <ncurses.h>			/* ncurses.h includes stdio.h */  
#include <string.h> 


 
 int main()
 {
     char mesg[]="Enter a string: ";			/* message to be appeared on the screen */
     char str[80];
     int maxrow, maxcol, row, col;			/* to store the number of rows and *
        					 	 * the number of colums of the screen */
	
	initscr();					/* start the curses mode */
    	getmaxyx(stdscr,maxrow,maxcol);			/* get the number of rows and columns */
    	
    	
    	col = maxcol;
    	row = maxrow;
    	do{
    	
    		mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);	/* print the message at the center of the screen */
		getstr(str);
	
		mvprintw( 0, 0, "You Entered: %s", str);
		mvprintw( 2, 0, "Do you wish to continue? (y or n)");
		
		}while( getch() != 'n');
		
	/* getch(); */
    	endwin();
    	return 0;
}
