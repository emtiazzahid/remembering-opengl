#include <windows.h>
#include <GL/glut.h>

void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT);

   glBegin(GL_POLYGON);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-0.7, 0.3f);
      glVertex2f(-0.4f, -0.3f);
      glVertex2f(-0.5f, 0.0f);
  glEnd();

    glBegin(GL_POLYGON);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-0.4, -0.3f);
      glVertex2f(0.4f, -0.3f);
      glVertex2f(-0.5f, 0.0f);
   glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-0.5f, 0.0f);
      glVertex2f(-0.4, -0.3f);
      glVertex2f(0.4f, -0.3f);
      glVertex2f(0.5f, 0.0f);
   glEnd();

   glBegin(GL_POLYGON);
      glColor3f(1.0f, 0.0f, 0.0f);
       glVertex2f(0.5f, 0.0f);
      glVertex2f(0.4f, -0.3f);
      glVertex2f(0.7f, 0.3f);
   glEnd();

   glBegin(GL_POLYGON);  /* 4 */
      glColor3f(1.0f, 0.5f, 0.0f);
       glVertex2f(-0.5f, 0.0f);
      glVertex2f(-0.3f, 0.4f);
      glVertex2f(-0.1f, 0.0f);
   glEnd();

   glBegin(GL_QUADS);  /* 5 */
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex2f(-0.3f, 0.4f);
      glVertex2f(-0.1, 0.0f);
      glVertex2f(0.5f, 0.0f);
      glVertex2f(0.3f, 0.4f);
   glEnd();

   glFlush();  // Render now
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);          // Initialize GLUT
   glutCreateWindow("Vertex, Primitive & Color");
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(10, 100);
   glutDisplayFunc(display);
   init();
   glutMainLoop();
   return 0;
}
