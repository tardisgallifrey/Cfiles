#include<GL/glut.h>
#include<GL/gl.h>

#define WINX_SIZE 600
#define WINY_SIZE 600

void glutwritechar( char s , int font, int x, int y, int winx, int winy);


GLvoid InitGL(GLvoid)
{
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();
  glClearColor(0.0, 0.0, 0.0, 1.0);


}

  

GLvoid DrawGLScene(GLvoid)
{
  glClear(GL_COLOR_BUFFER_BIT);
  
  glutwritechar('X', 1, 15, WINY_SIZE - 15, WINX_SIZE, WINY_SIZE);
}


void main(int argc, char**argv) 
{ 
    //This app is to test and formulate two functions
    //glutwritechar() and glutwritestring()
  
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (WINX_SIZE, WINY_SIZE);
    glutInitWindowPosition (50, 50); 
    glutCreateWindow (argv[0]);
 
    InitGL();
 
    glutDisplayFunc(DrawGLScene);
 
    glutMainLoop();
}



void glutwritechar( char s , int font, int x, int y, int winx, int winy)
{

  void* font_chosen;

  //The base code for this idea came from here.
  //https://stackoverflow.com/questions/14318/using-glut-bitmap-fonts/14319#14319

  //setup the projection and modelview matrices for 2D rendering:
  //One matrix is GL_PROJECTION
  //The other is GL_MODELVIEW
  //gluOrtho2D does the work of changing to rendering text, I think.
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0.0, winx, 0.0, winy);

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  //Set the text color
  //Needs to be sent in too
  glColor3f(0.0, 1.0, 0.0); // Green

  //Turn this into another function choose_font()
  if(font == 1)
  {
    font_chosen = GLUT_BITMAP_9_BY_15;
  }

  //Position start of text (character only at this time)
  glRasterPos2i(x, y);

  //Write a character to window at position above
  //Font needs to be entered from above
  glutBitmapCharacter(font_chosen, s);

  //Now restore matrices back to former state?
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();

  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glutSwapBuffers();

}

