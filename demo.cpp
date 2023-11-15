#include <GL/glut.h>
#include <iostream>
#include <GL/freeglut_std.h>
#include <GL/gl.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    
    glBegin(GL_TRIANGLES);
	//Vertex 1: green
    glColor3f(0.0,1.0, 0.0);  
    glVertex2f(0.0, 0.5);
	//Vertex 2: red
	glColor3f(1.0,0.0, 0.0);
    glVertex2f(-0.5, -0.5);
    //Vertex 3:green
	glColor3f(0.0,0.0, 1.0);
	glVertex2f(0.5, -0.5);
    
	glEnd();

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("A Simple coloured Triangle");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(0.0, 0.0, 0.0, 0.0);  // Set the background color to black

    glutMainLoop();
    return 0;
}