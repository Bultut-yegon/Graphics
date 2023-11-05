#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void display() {
  // Clear the color buffer.
  glClearColor(0.5f, 0.2f, 1.0f, 0.3f);
  glClear(GL_COLOR_BUFFER_BIT);

  // Draw a red square.
  glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.5f, 1.0f, 0.2f);
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.5f, -0.5f);
    glColor3f(0.2f, 1.0f, 0.5f);
    glVertex2f(0.5f, 0.5f);
    glColor3f(0.4f, 1.0f, 0.6f);
    glVertex2f(-0.5f, 0.5f);
  glEnd();

  // Swap the buffers.
  glutSwapBuffers();
}

int main(int argc, char** argv) {
  // Initialize GLUT.
  glutInit(&argc, argv);

  // Create a window.
  glutCreateWindow("OpenGL Test");

  // Set the display callback function.
  glutDisplayFunc(display);

  // Start the main loop.
  glutMainLoop();

  return 0;
}
