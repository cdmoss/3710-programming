#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <iostream>

using namespace std;

GLfloat scaleFactor = 1.0;

void draw_frustum()
{
    // Scaling
    glPushMatrix();
    glScalef(scaleFactor, scaleFactor, scaleFactor);
    // bottom face
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-.5, -.5, -.5);
    glVertex3f(.5, -.5, -.5);
    glVertex3f(.5, .5, -.5);
    glVertex3f(-.5, .5, -.5);
    // top face
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-.25, -.25, -.25);
    glVertex3f(.25, -.25, -.25);
    glVertex3f(.25, .25, -.25);
    glVertex3f(-.25, .25, -.25);
    // side face -y
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-.5, -.5, -.5);
    glVertex3f(-.25, -.25, -.25);
    glVertex3f(.25, -.25, -.25);
    glVertex3f(.5, -.5, -.5);
    // side face +y
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(.5, .5, -.5);
    glVertex3f(.25, .25, -.25);
    glVertex3f(-.25, .25, -.25);
    glVertex3f(-.5, .5, -.5);
    // side face -x
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-.5, .5, -.5);
    glVertex3f(-.25, .25, -.25);
    glVertex3f(-.25, -.25, -.25);
    glVertex3f(-.5, -.5, -.5);
    // side face +x
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(.5, -.5, -.5);
    glVertex3f(.25, -.25, -.25);
    glVertex3f(.25, .25, -.25);
    glVertex3f(.5, .5, -.5);
    glEnd();
    // inner triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.5, 1, 0.3);
    glVertex3f(-0.25, -.25, -0.375);
    glVertex3f(0.0, 0.25, -0.375);
    glVertex3f(0.25, -.25, -0.375);
    glEnd();
    glPopMatrix();
}

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5, 5, -5, 5, 5, -5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, -1, 0.5, 0.0, 0.0, .0, 0.0, 0.0, 1.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw_frustum();
    glutSwapBuffers();
}

// increases scaleFactor by 10% when PageUp is pressed, decreases it by 10% when PageDown is pressed
void handleKey(int key, int x, int y) {
    switch (key)
    {
        case GLUT_KEY_PAGE_UP:
            scaleFactor *= 1.1;
            break;
        case GLUT_KEY_PAGE_DOWN:
            scaleFactor /= 1.1;
            break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3710 - Assignment 2");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(handleKey);
    glutMainLoop();

    return 0;
}