#pragma once

#include <GL/glut.h>

class House {
private:
    boolean isDay;

public:
    House() : isDay(false) {}

    void draw(float x, float y, float size, bool isPath, boolean isDay) {
        glPushMatrix();
        glTranslatef(x, y, 0.0f);
        glScalef(size, size, 1.0f);

        // Colors based on the time of day
        GLfloat bodyColor[] = { isDay ? 0.9f : 0.3176f, isDay ? 0.9f : 0.2941f, isDay ? 0.75f : 0.1373f };
        GLfloat rightRectColor[] = { isDay ? 0.85f : 0.5059f, isDay ? 0.75f : 0.4667f, isDay ? 0.6f : 0.2157f };
        GLfloat triangleColor[] = { isDay ? 0.85f : 0.7216f, isDay ? 0.35f : 0.0000f, isDay ? 0.35f : 0.0000f };
        GLfloat rhomboidColor[] = { isDay ? 0.9f : 0.5451f, isDay ? 0.4f : 0.0f, isDay ? 0.4f : 0.0f };
        GLfloat windowColor[] = { isDay ? 0.68f : 0.8902f, isDay ? 0.85f : 0.7098f, isDay ? 0.90f : 0.0196f };
        GLfloat doorColor[] = { isDay ? 0.7f : 0.545f, isDay ? 0.5f : 0.271f, isDay ? 0.1f : 0.075f };

        // House Body
        glColor3fv(bodyColor);
        glBegin(GL_QUADS);
        glVertex2f(-0.25f, -0.5f); // left-bottom
        glVertex2f(0.25f, -0.5f);  // right-bottom
        glVertex2f(0.25f, -0.15f); // right-top
        glVertex2f(-0.25f, -0.15f);// left-top
        glEnd();

        // Right Rectangle
        glColor3fv(rightRectColor);
        glBegin(GL_QUADS);
        glVertex2f(0.25f, -0.5f);  // left-bottom
        glVertex2f(0.5f, -0.5f);   // right-bottom
        glVertex2f(0.5f, -0.15f);  // right-top
        glVertex2f(0.25f, -0.15f); // left-top
        glEnd();

        // Triangle on top of the smaller rectangle
        glColor3fv(triangleColor);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.25f, -0.15f); // bottom-left
        glVertex2f(0.5f, -0.15f);  // bottom-right
        glVertex2f(0.375f, 0.1f);  // top-center
        glEnd();

        // Rhomboid slanted at the same angle as the triangle and connected to it
        glColor3fv(rhomboidColor);
        glBegin(GL_QUADS);
        glVertex2f(-0.1f, 0.1f);   // top-left
        glVertex2f(0.375f, 0.1f);  // top-right
        glVertex2f(0.25f, -0.15f); // bottom-right
        glVertex2f(-0.25f, -0.15f);// bottom-left
        glEnd();

        glLineWidth(2.0f);

        // Window 1 (left)
        glColor3fv(windowColor);
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
        glColor3fv(windowColor);
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
        glColor3fv(doorColor);
        glBegin(GL_QUADS);
        glVertex2f(0.325f, -0.5f); // left-bottom
        glVertex2f(0.425f, -0.5f); // right-bottom
        glVertex2f(0.425f, -0.31f); // right-top
        glVertex2f(0.325f, -0.31f); // left-top
        glEnd();

        // Doorknob on the centered door
        glPushAttrib(GL_POINT_BIT);
        glColor3f(1.0f, 1.0f, 1.0f); // white color
        glPointSize(5.0);
        glBegin(GL_POINTS);
        glVertex2f(0.41f, -0.41f);
        glEnd();
        glPopAttrib();

        if (isPath)
        {
            // Lane adjusted for the centered door position
            glColor3f(0.0157f, 0.1647f, 0.1686f);
            glBegin(GL_QUADS);
            glVertex2f(0.325f, -0.5f); // left-bottom
            glVertex2f(0.425f, -0.5f); // right-bottom
            glVertex2f(0.9f, -0.9f); // right-top
            glVertex2f(0.45f, -0.9f); // left-top
            glEnd();
        }
        glPopMatrix();
        glFlush();
    }

    void init() {
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        float aspectRatio = 1920.0f / 1080.0f;
        if (aspectRatio > 1.0f) {
            gluOrtho2D(-aspectRatio, aspectRatio, -1.0, 1.0);
        }
        else {
            gluOrtho2D(-1.0, 1.0, -1.0 / aspectRatio, 1.0 / aspectRatio);
        }
    }
};