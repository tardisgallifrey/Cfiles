#include <ncurses.h>

int main()
{
		
	initscr(); cbreak(); noecho();		/* Start curses mode 		  	*/
	keypad(stdscr, TRUE);			/*turn on F1, etc.		  	*/
	mvprintw(15, 25, "Hello World !!!");	/* Print Hello World at where I say	*/
	refresh();				/* Print it on to the real screen 	*/
	getch();				/* Wait for user input 			*/
	endwin();				/* End curses mode		  	*/
					
	return 0;
}
