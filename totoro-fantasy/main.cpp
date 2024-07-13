#include <windows.h>
#include <iostream>
#include <gl/glut.h>
#include "Cloud.h"
#include "Colors.h"
#include "Character.h"

static void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

static void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Totoro Fantasy");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}