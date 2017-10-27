#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<math.h>

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
    int i;
    float PI = 3.1416;
    int triangleAmount = 50; //# of triangles used to draw circle
    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle

    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
        x + (radius * cos(i * twicePi / triangleAmount)),
        y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void display(void)
{
/* clear all pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

/* draw white polygon (rectangle) with corners at
 * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
 */


     glColor3f (0.0, 1.0, 0.0);
   glBegin(GL_POLYGON);
      glVertex3f (1.0, 8.0, 0.0);
      glVertex3f (1.0, 1.0, 0.0);
      glVertex3f (9.0, 1.0, 0.0);
      glVertex3f (9.0, 8.0, 0.0);
   glEnd();

    glColor3f (1.0, 0.0, 0.0);
   drawFilledCircle(4.5,4.5,2);

/* don't wait!
 * start processing buffered OpenGL routines
 */
   glFlush ();
}

void init (void)
{
/* select clearing color 	*/
   glClearColor (0.0, 0.0, 0.0, 0.0);

/* initialize viewing values  */
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);
}

/*
 * Declare initial window size, position, and display mode
 * (single buffer and RGBA).  Open window with "hello"
 * in its title bar.  Call initialization routines.
 * Register callback function to display graphics.
 * Enter main loop and process events.
 */
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (350, 250);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("hello");
   init ();
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;   /* ANSI C requires main to return int. */
}
