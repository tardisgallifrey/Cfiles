#include<GL/glut.h>
#include<GL/gl.h>

#define FONT			    GLUT_BITMAP_8_BY_13
#define CHAR_W			    8
#define CHAR_H			    13
#define CHAR_DESCENT		3
#define LINE_SEP		    2
#define CARRIAGE_RETURN		13
#define BACK_SPACE		    8

void emitString(char *s, int tx, int ty)
{
  int x,y;

  x = tx;
  y = ty;
  while( *s ) {
    if( *s == CARRIAGE_RETURN ) {
      x = tx;
      y += CHAR_H + LINE_SEP;
    } else {
      glRasterPos2i(x,y);
      glutBitmapCharacter(FONT,*s);
      x += CHAR_W;
   }
    ++s;
  }
}

GLvoid InitGL(GLvoid)
{
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0.0, 400, 0.0, 400);

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();
  glClearColor(0.0, 0.0, 0.0, 1.0);


}

  

GLvoid DrawGLScene(GLvoid)
{
  glClear(GL_COLOR_BUFFER_BIT);
  
  glColor3f(0.0,1.0,0.0);
  emitString("What does this do?",10,CHAR_H);
  emitString("I don't know.", 10, CHAR_H + 25);
  glutSwapBuffers();
}


void main(int argc, char**argv) { 
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (400, 400);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
 
    InitGL();
 
    glutDisplayFunc(DrawGLScene);
 
    glutMainLoop();
}

