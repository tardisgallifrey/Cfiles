
#include <ncurses.h>		/* needed for windows functions	*/
#include <string.h>		/* needed for strlen()		*/

int main()
{
   int row, col;
   	
	initscr();								/* Start curses mode 		  */
	getmaxyx(stdscr, row, col);
	mvprintw(row/2, (col/2) - strlen("Hellow World"), "Hello World !!!");	/* Print Hello World		  */
	
	mvprintw((row/2) + 1, (col/2) - strlen("Rows x Cols x"), "Rows %d, Cols %d", row, col);
	
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */
					
	return 0;
}
