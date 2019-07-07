
#include <ncurses.h>		/* needed for windows functions	*/
#include <string.h>		/* needed for strlen()		*/

int main()
{
   int row, col;
   	
	initscr();								/* Start curses mode 		  */
	getmaxyx(stdscr, row, col);
	mvprintw(row/2, (col/2) - strlen("Hellow World"), "Hello World !!!");	/* Print Hello World		  */
	
	mvprintw((row/2) + 1, (col/2) - strlen("Rows x Cols x"), "Rows %d, Cols %d", row, col);
	
	getyx(stdscr,row,col);
	mvprintw(0,0,"Last known location of cursor was row %d, column %d ", row, col);
	move( row + 1, col - 10);
	         	
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */
					
	return 0;
}
