
//Include necessary header files
//app will be linked with GL, GLU, and glut libraries
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

//This example is the same as in Red Book 1
//but is written for the freeglut usage/conformance I have
void display(void)
{
/* clear all pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

/* draw white polygon (rectangle) with corners at
 * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)  
 */
   glColor3f (1.0, 1.0, 1.0);
   glBegin(GL_POLYGON);
      glVertex3f (0.25, 0.25, 0.0);
      glVertex3f (0.75, 0.25, 0.0);
      glVertex3f (0.75, 0.75, 0.0);
      glVertex3f (0.25, 0.75, 0.0);
   glEnd();

/* don't wait!  
 * start processing buffered OpenGL routines 
 */
   glFlush ();
}

//These parts of what Red Book uses
//Needed to go in their own function to fit in
//with freeglut calls
void init (void) 
{
/* select clearing color 	*/
   glClearColor (0.0, 0.0, 0.0, 0.0);

/* initialize viewing values  */
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}


int main(int argc, char **argv)
{
    //OpenGL does not contain anything
    //for window management, keyboard, mouse, etc.
    //We use freeglut for that
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(512, 512);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("OpenGL Redbook 1");

   //Initialize my OpenGL set up
   init();

    //Always write your OpenGL code as a display
    //function to be called here by freeglut
   glutDisplayFunc(display);

   glutMainLoop();
   return 0; /* ANSI C requires main to return int. */
}