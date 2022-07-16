#include <stdio.h>
#include <stdlib.h>

/*X11, Xlib header files
  Xlib.h must be first */
#include <X11/Xlib.h>
#include <X11/Xcms.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>
#include <X11/Xresource.h>
#include <X11/cursorfont.h>
#include <X11/keysym.h>
#include <X11/Xlibint.h>
#include <X11/Xproto.h>



int main(void)
{
    //display_name set to NULL to pick the one
    //in environment variables
    Display *mydisplay;
    int screen_num, widt, height;

    //open X display connected to default environment variable
    //NULL
    //returns a Display struct.
    //You can't dereference mydisplay normally.
    //Must use X functions
    mydisplay = XOpenDisplay(NULL);

    if(!mydisplay){
      puts("Could not open X display.");
    }

    //correct method to call DefaultScreen
    screen_num = DefaultScreen(mydisplay);
    printf("Screen number: %d\n", screen_num);

    XCloseDisplay(mydisplay);

    return 0;
    

}