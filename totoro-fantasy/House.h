#ifndef HOUSE_H
#define HOUSE_H
//help

#include <GL/glut.h>

class House {
public:
    House() {}

    void display() {
        glClear(GL_COLOR_BUFFER_BIT);

        // Set background color (light green)
        glClearColor(0.678f, 1.0f, 0.184f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // House Body (dark blue) with half the previous width
        glColor3f(0.0f, 0.0f, 0.545f);
        glBegin(GL_QUADS);
        glVertex2f(-0.25f, -0.5f); // left-bottom
        glVertex2f(0.25f, -0.5f);  // right-bottom
        glVertex2f(0.25f, -0.15f); // right-top
        glVertex2f(-0.25f, -0.15f);// left-top
        glEnd();

        // Right Rectangle (half the width, half the height) with darker blue
        glColor3f(0.0f, 0.0f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(0.25f, -0.5f);  // left-bottom
        glVertex2f(0.5f, -0.5f);   // right-bottom
        glVertex2f(0.5f, -0.15f);  // right-top
        glVertex2f(0.25f, -0.15f); // left-top
        glEnd();

        // Brown Triangle on top of the smaller rectangle
        glColor3f(0.545f, 0.271f, 0.075f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.25f, -0.15f); // bottom-left
        glVertex2f(0.5f, -0.15f);  // bottom-right
        glVertex2f(0.375f, 0.1f);  // top-center
        glEnd();

        // Black Rhomboid slanted at the same angle as the triangle and connected to it
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.1f, 0.1f);   // top-left
        glVertex2f(0.375f, 0.1f);  // top-right
        glVertex2f(0.25f, -0.15f); // bottom-right
        glVertex2f(-0.25f, -0.15f);// bottom-left
        glEnd();

        glLineWidth(2.0f);

        // Window 1 (left)
        glColor3f(1.0f, 1.0f, 0.0f);  // yellow color
        glBegin(GL_QUADS);
        glVertex2f(-0.19f, -0.3f); // left-bottom
        glVertex2f(-0.04f, -0.3f); // right-bottom
        glVertex2f(-0.04f, -0.2f); // right-top
        glVertex2f(-0.19f, -0.2f); // left-top
        glEnd();

        // Horizontal rail of Window 1
        glColor3f(0.0f, 0.0f, 0.0f);  // black color
        glBegin(GL_LINES);
        glVertex2f(-0.19f, -0.25f); // left-middle
        glVertex2f(-0.04f, -0.25f); // right-middle
        glEnd();

        // Vertical rail of Window 1
        glBegin(GL_LINES);
        glVertex2f(-0.115f, -0.3f); // bottom-middle
        glVertex2f(-0.115f, -0.2f); // top-middle
        glEnd();

        // Window 2 (right)
        glColor3f(1.0f, 1.0f, 0.0f);  // yellow color
        glBegin(GL_QUADS);
        glVertex2f(0.04f, -0.3f);  // left-bottom
        glVertex2f(0.19f, -0.3f); // right-bottom
        glVertex2f(0.19f, -0.2f); // right-top
        glVertex2f(0.04f, -0.2f);  // left-top
        glEnd();

        // Horizontal rail of Window 2
        glColor3f(0.0f, 0.0f, 0.0f);  // black color
        glBegin(GL_LINES);
        glVertex2f(0.04f, -0.25f);  // left-middle
        glVertex2f(0.19f, -0.25f); // right-middle
        glEnd();

        // Vertical rail of Window 2
        glBegin(GL_LINES);
        glVertex2f(0.115f, -0.3f);  // bottom-middle
        glVertex2f(0.115f, -0.2f);  // top-middle
        glEnd();

        // Door centered on the smaller rectangle
        glColor3f(0.545f, 0.271f, 0.075f); // brown color
        glBegin(GL_QUADS);
        glVertex2f(0.325f, -0.5f); // left-bottom
        glVertex2f(0.425f, -0.5f); // right-bottom
        glVertex2f(0.425f, -0.35f); // right-top
        glVertex2f(0.325f, -0.35f); // left-top
        glEnd();

        // Doorknob on the centered door
        glColor3f(1.0f, 1.0f, 1.0f); // white color
        glPointSize(5.0);
        glBegin(GL_POINTS);
        glVertex2f(0.41f, -0.43f);
        glEnd();

        // Lane adjusted for the centered door position
        glColor3f(0.4f, 0.6f, 0.8f); // light blue color
        glBegin(GL_QUADS);
        glVertex2f(0.325f, -0.5f); // left-bottom
        glVertex2f(0.425f, -0.5f); // right-bottom
        glVertex2f(0.525f, -0.9f); // right-top
        glVertex2f(0.225f, -0.9f); // left-top
        glEnd();

        glFlush();
    }

    void init() {
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glMatrixMode(GL_PROJECTION);
        gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    }
};

#endif // HOUSE_H
