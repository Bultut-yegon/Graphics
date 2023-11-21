#include <iostream>
#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glut.h>
void getShape(){
    glClearColor(0.3f,0.5f,0.7f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    //glColor3f(0.8f,0.6f,0.4f);
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0, 0.0);
	glVertex2f(-0.3, -0.3);
    glColor3f(0.0,0.0, 1.0);
	glVertex2f(0.3, -0.3);
    glColor3f(0.0,1.0, 0.0);
	glVertex2f(0.3, -0.8);
    glColor3f(0.0,0.0, 1.0);
	glVertex2f(-0.3, -0.8);
    
     
    glEnd();

    //border
    //red
    glBegin(GL_POLYGON);
    glColor4f(1.0,0.0,0.0,0.0);

	 glVertex2f(-0.4, -0.5);
     glVertex2f(-0.3, -0.5);
     glVertex2f(-0.4, -0.8);
     glVertex2f(-0.3, -0.8);
    glEnd();
   // glColor3f(0.0,0.0, 0.0);
	//glVertex2f(0.4, -0.9);
    //glColor3f(0.0,0.0, 0.0);
	//glVertex2f(-0.4, -0.9);
    //Greeen
   
    glBegin(GL_POLYGON); 
    glColor4f(0.0,1.0,0.0,0.0);

	 glVertex2f(-0.4, -0.8);
     glVertex2f(-0.4, -0.9);
     glVertex2f(0.4, -0.8);
     glVertex2f(0.4, -0.9);
    glEnd();
    //Blue
    
    glBegin(GL_POLYGON);
    glColor4f(0.0,0.0,1.0,0.0);

	 glVertex2f(0.3, -0.5);
     glVertex2f(0.4, -0.5);
     glVertex2f(0.3, -0.8);
     glVertex2f(0.4, -0.8);
    glEnd();


    //glColor3f(0.5f,0.3f,0.1f);
    glBegin(GL_TRIANGLES);
     //Vertex 1: green
    glColor3f(0.0,1.0, 0.0);  
    glVertex2f(0.0, 0.5);
	//Vertex 2: red
	glColor3f(1.0,0.0, 0.0);
    glVertex2f(-0.5, -0.5);
    //Vertex 3:blue
	glColor3f(0.0,0.0, 1.0);
	glVertex2f(0.5, -0.5);
    glEnd();

    //door
   /*glColor3f(0.2f,0.2f,0.2f);
    glBegin(GL_POLYGON);
     glVertex2f(-10.0f,-15.0f);
     glVertex2f(-5.0f,-15.0f);
     glVertex2f(-5.0f,-5.0f);
     glVertex2f(-10.0f,-5.0f);
    glEnd();*/

    //flush
    glFlush();
    glutSwapBuffers();

}
int main(int argc, char** argv) {
    glutInit(&argc, argv);  
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    //glutInitWindowSize(800,600);
    //glutInitWindowPosition(100,100);
    int width = 800, height = 600;
    int x = (1368 - width) / 2, y = (768 - height)/ 2;
    glutInitWindowPosition(x, y);
    glutInitWindowSize(width, height);
    glutCreateWindow("Simple Hut");
    glClearColor(0.0,0.0,0.0,0.0);

    //callback
    glutDisplayFunc(getShape);

    glutMainLoop();


    return 0;
}