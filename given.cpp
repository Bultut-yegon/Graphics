#include <GL/glut.h>
#include <iostream>
#include <GL/freeglut_std.h>
#include <GL/gl.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the outer rectangle (double lines)
    glBegin(GL_QUADS);
        // Outer rectangle (larger)
        glColor3f(1.0, 0.0, 0.0); // Red (left side)
        glVertex2f(-0.51, -0.51);
        glVertex2f(0.51, -0.51);
        glVertex2f(0.51, 0.51);
        glVertex2f(-0.51, 0.51);

        glColor3f(0.0, 1.0, 0.0); // Green (bottom side)
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(-0.5, 0.5);

        // Inner rectangle (smaller)
        glColor3f(0.0, 0.0, 1.0); // Blue (left side)
        glVertex2f(-0.5, -0.5);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(-0.51, -0.5);
        glColor3f(1.0, 0.0, 1.0);

        glVertex2f(-0.51, 0.5);
        glColor3f(0.0, 1.0, 0.0);

        glVertex2f(-0.5, 0.5);
    glEnd();

    // Draw the triangle (roof of the hut)
    glBegin(GL_TRIANGLES);
        glColor3f(0.8, 0.0, 0.0); // Red
        glVertex2f(-0.5, 0.5);
        glColor3f(0.0, 0.8, 0.0); // Green
        glVertex2f(0.5, 0.5);
        glColor3f(0.0, 0.0, 0.8); // Blue
        glVertex2f(0.0, 1.0);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Colored Hut");
    glutInitWindowSize(400, 400);
    glutDisplayFunc(display);
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    glutMainLoop();
    return 0;
}