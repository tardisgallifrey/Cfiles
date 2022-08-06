//Xlib using OpenGL through GLX
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>
#include "version.h"


//Here, we are making our X variables, global
//Those beginning with GL are OpenGL or GLX
//variables
Display                 *dpy;
Window                  root;           //root is our top-level window
GLint                   att[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
XVisualInfo             *vi;
Colormap                cmap;
XSetWindowAttributes    swa;
Window                  win;
GLXContext              glc;
XWindowAttributes       gwa;
XEvent                  xev;

//an OpenGL function to draw a quad (rectangle)
void DrawAQuad() {
 glClearColor(1.0, 1.0, 1.0, 1.0);
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-1., 1., -1., 1., 1., 20.);

 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 gluLookAt(0., 0., 10., 0., 0., 0., 0., 1., 0.);

 glBegin(GL_QUADS);
  glColor3f(1., 0., 0.); glVertex3f(-.75, -.75, 0.);
  glColor3f(0., 1., 0.); glVertex3f( .75, -.75, 0.);
  glColor3f(0., 0., 1.); glVertex3f( .75,  .75, 0.);
  glColor3f(1., 1., 0.); glVertex3f(-.75,  .75, 0.);
 glEnd();
} 


int main(int argc, char *argv[]) {

 printf("%s version %s\n", PROJECT, PROJECT_VERSION);

 dpy = XOpenDisplay(NULL);
 
 if(dpy == NULL) {
 	printf("\n\tcannot connect to X server\n\n");
        exit(0);
 }

    //get a handle to the default window opened
    //root is a top-level window
    root = DefaultRootWindow(dpy);

    //In short, assign opened display w/ attributes (above)
    //to our X context
    vi = glXChooseVisual(dpy, 0, att);

    //See if it works
    if(vi == NULL) {
        printf("\n\tno appropriate visual found\n\n");
            exit(0);
    } 
    else {

        /* %p creates hexadecimal output like in glxinfo */
        /* VisualInfo vi is a pointer to a struct
            we use a void pointer cast to point to members */
        printf("\n\tvisual %p selected\n", (void *)vi->visualid); 
    }

    //create color map in X
    cmap = XCreateColormap(dpy, root, vi->visual, AllocNone);

    //set color map and event masks
    swa.colormap = cmap;
    swa.event_mask = ExposureMask | KeyPressMask;

    //create the window, returns a window handle
    //top level windows ignore border commands, but fill them in anyway
    //top level windows ignore origin x/y, but fill in anyway
    win = XCreateWindow(dpy, root, 100, 100, 600, 600, 0, vi->depth, InputOutput, vi->visual, CWColormap | CWEventMask, &swa);

    //Engage!
    XMapWindow(dpy, win);

    //change window title
    XStoreName(dpy, win, "VERY SIMPLE APPLICATION");

    //create and bind a GLX context to the active window
    glc = glXCreateContext(dpy, vi, NULL, GL_TRUE);
    glXMakeCurrent(dpy, win, glc);

    //enable the DEPTH TEST for our buffers
    glEnable(GL_DEPTH_TEST); 

    //The main loop, like glut
    while(1) {
        XNextEvent(dpy, &xev);

        switch(xev.type){

            case Expose :
                XGetWindowAttributes(dpy, win, &gwa);
                glViewport(0, 0, gwa.width, gwa.height);
                DrawAQuad(); 
                glXSwapBuffers(dpy, win);
                break;

            case KeyPress :
                glXMakeCurrent(dpy, None, NULL);
                glXDestroyContext(dpy, glc);
                XDestroyWindow(dpy, win);
                XCloseDisplay(dpy);
                exit(0);
                break;
            default:
                break;
        }
        
    } /* this closes while(1) { */

    
} /* this is the } which closes int main(int argc, char *argv[]) { */

