
#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <string.h>
 
/* Set default window size */
#define kWindowWidth 400
#define kWindowHeight 300
 
GLvoid InitGL(GLvoid);
GLvoid DrawGLScene(GLvoid);
GLvoid ReSizeGLScene(int Width, int Height);
GLfloat Xconvert(int X);
GLfloat Yconvert(int Y);
GLvoid mouseHandler(int x, int y);

/*
This struct is needed since I can't 
seem to rely on the return values of 
GLUT_SCREEN_WIDTH and _Height

The struct allows passing width and heigth
among OpenGL callback functions that have 
to be of void type
*/

struct screensize {
    int width;
    int height;
    int x;
    int y;
} Screen, XYselect;

 
int main(int argc, char** argv)
{
    /*This first part allows us
    to state our window size on the 
    command line */
    int width = 0;
    int height = 0;

    if( !argv[1] || !argv[2] )
    {
        printf("You didn't enter a window size.\n");
        exit(0);
    }
    else
    {
        width = atoi(argv[1]);
        height = atoi(argv[2]);
    }
    
    if(width < kWindowWidth)
    {
        width = kWindowWidth;
    }

    if(height < kWindowHeight)
    {
        height = kWindowHeight;
    }

/* All of this is from a basic glut/freeglut tutorial */
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 glutInitWindowSize (width, height);
 glutInitWindowPosition (100, 100);
 glutCreateWindow (argv[0]);
 
 InitGL();
 
 /* The target of these two functions
 are callbacks that you write.  It is a way 
 of overriding non-overridable C functions */

 //This can't sent extra values to DrawGLScene
 glutDisplayFunc(DrawGLScene);

 //This does correctly send window width and height
 //in addition to the callback function
 glutReshapeFunc(ReSizeGLScene);
 
 glutPassiveMotionFunc( mouseHandler );
 //Makes the world go round
 glutMainLoop();
 
 return 0;
}
 
//Resets things that need reset when the screen size
//is changed with your mouse
GLvoid ReSizeGLScene(int width, int height)
{
    if (height==0)
    {
    height=1;
    }

    //This use of the struct gets
    //altered window size for functions
    //that can't get it otherwise
    Screen.width = width;
    Screen.height = height;

    //Set the viewport to the new size
    //Set Matrix Mode to Projection type
    //Load the new matrix
    //Then go back to modelview with new window size
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 
    glMatrixMode(GL_MODELVIEW);
}
 
//Sets up initial window stuff
GLvoid InitGL(GLvoid)
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 
    glMatrixMode(GL_MODELVIEW);
}
 
//This is our workhorse
//Draws stuff on screen
GLvoid DrawGLScene(GLvoid)
{
    //Get screen width and height from struct
    int w = Screen.width;
    int h = Screen.height;

    //Clear color buffer and depth buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    //Set the new viewport and set modelview and load it
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
 
    //I can't get glOrtho or gluOrtho to work
    //This accomplishes the same
    //Sets x,y = 0,0 in lower left corner
    glTranslatef(-1.0f, -1.0f, -0.1);
    //Set the color red
    glColor3f(1.0, 0.0, 0.0);
 
    
    //This is minimal code to 
    //draw a line from 0,0 to X max, Y max
    glBegin(GL_LINE_STRIP);
        glVertex2f(Xconvert(0), Yconvert(0));
        glVertex2f(Xconvert(Screen.width), Yconvert(Screen.height));   
    glEnd();
    

    glBegin(GL_TRIANGLES);
        glVertex2f(Xconvert(100), Yconvert(100));
        glVertex2f(Xconvert(100) + 0.1f, Yconvert(100));
        glVertex2f(Xconvert(100), Yconvert(100) + 0.1f);
    glEnd();

    glutSwapBuffers();
}

GLfloat Xconvert(int X)
{
    GLfloat myX = (GLfloat) X;
    return 2.0f / (GLfloat) Screen.width  * myX;
}

GLfloat Yconvert(int Y)
{
    GLfloat myY = (GLfloat) Y;
    return  2.0f - ( 2.0f / (GLfloat) Screen.height  * myY);
}

GLvoid mouseHandler(int x, int y)
{
    XYselect.x = x;
    XYselect.y = y;
    printf("%d , %d\n", XYselect.x, XYselect.y);
}

