#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

// Define truck body colors
GLfloat bodyColor[] = { 0.8f, 0.6f, 0.4f };
GLfloat wheelColor[] = { 0.3f, 0.3f, 0.3f };

// Truck dimensions
GLfloat truckWidth = 2.0f;
GLfloat truckLength = 5.0f;
GLfloat wheelRadius = 0.5f;

// Global rotation angle for the wheels
GLfloat wheelAngle = 0.0f;

// Function to draw the truck body
void drawTruckBody() {
  glColor3fv(bodyColor);
  glBegin(GL_QUADS);

  // Front face
  glVertex3f(-truckWidth / 2.0f, truckLength / 2.0f, 0.0f);
  glVertex3f(truckWidth / 2.0f, truckLength / 2.0f, 0.0f);
  glVertex3f(truckWidth / 2.0f, -truckLength / 2.0f, 0.0f);
  glVertex3f(-truckWidth / 2.0f, -truckLength / 2.0f, 0.0f);

  // Back face
  glVertex3f(-truckWidth / 2.0f + truckWidth / 3.0f, truckLength / 2.0f - truckLength / 4.0f, truckWidth / 3.0f);
  glVertex3f(truckWidth / 2.0f - truckWidth / 3.0f, truckLength / 2.0f - truckLength / 4.0f, truckWidth / 3.0f);
  glVertex3f(truckWidth / 2.0f - truckWidth / 3.0f, -truckLength / 2.0f + truckLength / 4.0f, truckWidth / 3.0f);
  glVertex3f(-truckWidth / 2.0f + truckWidth / 3.0f, -truckLength / 2.0f + truckLength / 4.0f, truckWidth / 3.0f);

  // Side faces
  glVertex3f(-truckWidth / 2.0f, truckLength / 2.0f, 0.0f);
  glVertex3f(-truckWidth / 2.0f + truckWidth / 3.0f, truckLength / 2.0f - truckLength / 4.0f, truckWidth / 3.0f);
  glVertex3f(-truckWidth / 2.0f + truckWidth / 3.0f, -truckLength / 2.0f + truckLength / 4.0f, truckWidth / 3.0f);
  glVertex3f(-truckWidth / 2.0f, -truckLength / 2.0f, 0.0f);

  glVertex3f(truckWidth / 2.0f, truckLength / 2.0f, 0.0f);
  glVertex3f(truckWidth / 2.0f - truckWidth / 3.0f, truckLength / 2.0f - truckLength / 4.0f, truckWidth / 3.0f);
  glVertex3f(truckWidth / 2.0f - truckWidth / 3.0f, -truckLength / 2.0f + truckLength / 4.0f, truckWidth / 3.0f);
  glVertex3f(truckWidth / 2.0f, -truckLength / 2.0f, 0.0f);

  glEnd();
}

// Function to draw the wheels
void drawWheels() {
  glPushMatrix();
  glRotatef(wheelAngle, 0.0f, 0.0f, 1.0f);

  // Front left wheel
  glColor3fv(wheelColor);
  glPushMatrix();
  glTranslatef(-truckWidth / 2.0f + truckWidth / 6.0f, -truckLength / 2.0f + wheelRadius, 0.0f);
  glutSolidSphere(wheelRadius, 20, 20);
  glPopMatrix();

  // Front right wheel
  glPushMatrix();
  glTranslatef(truckWidth / 2.0f - truckWidth / 6.0f, -truckLength / 2.0f + wheelRadius, 0.0f);
