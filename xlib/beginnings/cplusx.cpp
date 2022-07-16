/* first include the standard headers that we're likely to need */
/* basic set up for C++ */
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xresource.h>
#include <iostream>
#include <string.h>

int main(int argc, char ** argv){
	int screen_num, width, height;
	unsigned long background, border;
	Window win;
	XEvent ev;
	Display *dpy;

	/* First connect to the display server, as specified in the DISPLAY 
	environment variable. */
	dpy = XOpenDisplay(NULL);
	if (!dpy) {fprintf(stderr, "unable to connect to display");return 7;}

	/* these are macros that pull useful data out of the display object */
	/* we use these bits of info enough to want them in their own variables */
	screen_num = DefaultScreen(dpy);
	background = WhitePixel(dpy, screen_num);
	border = BlackPixel(dpy, screen_num);     //doesn't seem to do anything

	width = 400; /* start with a small window */
	height = 400;

	/*
	XCreateSimpleWindow(display, parentwin, originx, originy, width, height, borderw, bcolor, bgcolor);
	*/
	win = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy), 0,0, width, height, 100, border, background); 

	/* tell the display server what kind of events we would like to see */
	/* we will track button presses and changes to window size (and more, too) */
	XSelectInput(dpy, win, ButtonPressMask|StructureNotifyMask );

	/* okay, put the window on the screen, please */
	XMapWindow(dpy, win);

	/* as each event that we asked about occurs, we respond.  In this
	 * case we note if the window's shape changed, and exit if a button
	 * is pressed inside the window */
	while(1){
		/* get next window event about our window from event variable*/
		XNextEvent(dpy, &ev);

		switch(ev.type){
			//from StructureNotifyMask
		case ConfigureNotify:
		//if reported width or height doesn't match existing, set it
			if (width != ev.xconfigure.width || height != ev.xconfigure.height) {
				width = ev.xconfigure.width;
				height = ev.xconfigure.height;
				std::cout << "Size changed to: ";
				std::cout << width << " by " << height;
				std::cout << std::endl;
			}
			break;
			//from ButtonPressMask
		case ButtonPress:
			//close display
			XCloseDisplay(dpy);
			return 0;
		}
	}
}
