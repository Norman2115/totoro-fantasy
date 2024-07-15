#include <GL/glut.h>
#include "house.h"

House house;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    house.draw(-0.7f, 0.0f, 1.3f); // Draw the house at the center with size 1.0
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1980, 1080);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("House Drawing");
    house.init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
