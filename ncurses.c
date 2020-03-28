#include <ncurses.h>

int main()
{
   int row, col;
   	
	initscr();			/* Start curses mode 		  */
	getmaxyx(stdscr, row, col);
	printw("Hello World !!!\n");	/* Print Hello World		  */
	
	printw("Rows %d, Cols %d", row, col);
	
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */
					
	return 0;
}
