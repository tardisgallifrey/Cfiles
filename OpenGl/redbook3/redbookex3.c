
//Include necessary header files
//app will be linked with GL, GLU, and glut libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

//These parts of what Red Book uses
//Needed to go in their own function to fit in
//with freeglut calls
void init (void) 
{
    //Things here only need doing once, hence an init function

    //Set the clear color for the background
    //Uses RGBA, so all these 0's are black
    glClearColor(0.0, 0.0, 0.0, 0.0);   

    //This also clears screen depth
    glClearDepth(1.0);

    //Now, do the clear
    //We bit-wise OR the color and depth clear
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}

//This example is the same as in Red Book 1
//but is written for the freeglut usage/conformance I have
void display(void)
{
    //For ReShape to work effectively
    //init must be called each time through display function
    //Must define/declare init before this function or error results
    init();

        //Draw a circle on Screen
        glColor3f(0.0, 1.0, 1.0);
        #define PI 3.1415926535898
        GLint circle_points = 100;

        glBegin(GL_LINE_LOOP);
            for (int i = 0; i < circle_points; i++) {
                GLfloat angle = 2*PI*i/circle_points;
                glVertex2f(cos(angle), sin(angle));
            }
        glEnd();

    glFlush();
}


//Reshape handles what to do when we resize the screen
void reshape (int w, int h)
{
    //reshape receives the new width and height of the window
    //glViewport sets the new size
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);

    //standard necessary calls
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();

    //Sets 2D coordinate system
    //the 0, 0 params sets 0,0 at lower left of new window
    //with new maxes of w and h from above
    gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);

    //Tell glut to repost display function
    glutPostRedisplay();

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
   glutReshapeFunc(reshape);
   glutCreateWindow("OpenGL Redbook 3 -- draw a circle");

   //Initialize my OpenGL set up
   init();

    //Always write your OpenGL code as a display
    //function to be called here by freeglut
   glutDisplayFunc(display);

   glutMainLoop();
   return 0; /* ANSI C requires main to return int. */
}