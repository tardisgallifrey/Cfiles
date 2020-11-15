
// C program to demonstrate
// drawing a circle using
// OpenGL
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857


 
// function to initialize window
void myInit (void)
{
    // making background color black as first 
    // 3 arguments all are 0.0
    // glClearColor( Red , Green , Blue , Alpha)
    glClearColor(0.0, 0.0, 0.0, 1.0);
     
    // making foreground (pen) color green (in RGB mode), as middle argument is 1.0
    // glColor3f( Red , Green, Blue)
    glColor3f(0.0, 1.0, 0.0);
     
    // breadth of picture boundary is 1 pixel
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity();
     
    // setting window dimension in X- and Y- direction
    //  looks like index at 780, then subtract 780 for X and index at 420, then subtract 420 for Y.
    gluOrtho2D(-780, 780, -420, 420);
}
 
void display (void) 
{

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    float x, y, i;
     
    // iterate y up to 2*pi, i.e., 360 degree
    // with small increment in angle as
    // glVertex2i just draws a point on specified co-ordinate
    for ( i = 0; i < (2 * pi); i += 0.001)
    {
        // 200 is radius of circle and as,
        // circle is defined as x=r*cos(i) and y=r*sin(i)

        //Looks like, calculate x,y point on circle in x,y plane coordinates.
        x = 200 * cos(i);
        y = 200 * sin(i);
         
         //Write point in color from above?
        glVertex2i(x, y);
        glVertex2i(x + 20, y + 20);
    }

    glEnd();
    glFlush();
}
 
int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     
    // giving window size in X- and Y- direction
    glutInitWindowSize(1366, 768);
    glutInitWindowPosition(0, 0);
     
    // Giving name to window as we create it
    glutCreateWindow("Circle Drawing");
    myInit();
     
    glutDisplayFunc(display);
    glutMainLoop();
}