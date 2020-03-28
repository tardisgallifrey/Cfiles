
#include <ncurses.h>		/* needed for windows functions	*/
#include <string.h>		/* needed for strlen()		*/

int main()
{
   int row, col, maxrow, maxcol, x;
   char inputmesg[]="Please enter your full name:  ";
   char fullname[50];
   	
	initscr(); cbreak(); noecho();						/* Start curses mode 		  */
	getmaxyx(stdscr, maxrow, maxcol);
	row = maxrow;
	col = maxcol;
	
	mvprintw(row/2, (col/2) - strlen("Hellow World"), "Hello World !!!");	/* Print Hello World		  */
	
	mvprintw((row/2) + 1, (col/2) - strlen("Rows x Cols x"), "Rows %d, Cols %d", row, col);
	
	getyx(stdscr,row,col);
	mvprintw(0,0,"Last known location of cursor was row %d, column %d ", row, col);
	mvprintw( row + 2, col - 20, "%s", inputmesg);
	getyx(stdscr, row, col );
	
	echo();
	move( row, col + 1 );
	getstr(fullname);
	
	move( row, 0);
	clrtoeol();	
	
	noecho();		
	mvprintw( row, col - (1 + strlen(fullname) + strlen(inputmesg)), "Your name is %s", fullname);
	         	
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */
					
	return 0;
}
