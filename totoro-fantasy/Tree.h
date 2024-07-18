#pragma once
#include <gl/glut.h>
#include "Circle.h"
#include "Colors.h"
#include "Color.h"

class Tree
{
private:
	virtual void draw(float x, float y, float size, Color color) = 0;
};

class TreeOne : public Tree
{
public:
    void draw(float x, float y, float size, Color color)
    {
        // Draw the trunk
        glColor3f(0.38, 0.26, 0.17); // Brown color
        glBegin(GL_POLYGON);
        glVertex2f(x - 0.1 * size, y);
        glVertex2f(x + 0.1 * size, y);
        glVertex2f(x + 0.1 * size, y + 0.6 * size);
        glVertex2f(x - 0.1 * size, y + 0.6 * size);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f); // Black outline
        glBegin(GL_LINE_STRIP);
        glVertex2f(x + 0.1 * size, y);
        glVertex2f(x + 0.1 * size, y + 0.6 * size);
        glVertex2f(x - 0.1 * size, y + 0.6 * size);
        glVertex2f(x - 0.1 * size, y);
        glEnd();

        glColor3f(0.25, 0.17, 0.11);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x + 0.01 * size, y + 0.24545 * size);
        glVertex2f(x + 0.0214 * size, y + 0.2492 * size);
        glVertex2f(x + 0.0306 * size, y + 0.2283 * size);
        glVertex2f(x + 0.0273 * size, y + 0.205 * size);
        glVertex2f(x + 0.015 * size, y + 0.175 * size);
        glVertex2f(x + 0.0112 * size, y + 0.1498 * size);
        glVertex2f(x + 0 * size, y + 0.148 * size);
        glVertex2f(x - 0.008 * size, y + 0.1545 * size);
        glVertex2f(x - 0.0163 * size, y + 0.1697 * size);
        glVertex2f(x - 0.0187 * size, y + 0.179 * size);
        glVertex2f(x - 0.0172 * size, y + 0.2164 * size);
        glVertex2f(x - 0.01 * size, y + 0.2292 * size);
        glVertex2f(x + 0.001 * size, y + 0.2455 * size);
        glEnd();

        glColor3f(0.25, 0.17, 0.11);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x + 0.069 * size, y + 0.197 * size);
        glVertex2f(x + 0.0691 * size, y + 0.192 * size);
        glVertex2f(x + 0.074 * size, y + 0.174 * size);
        glVertex2f(x + 0.073 * size, y + 0.138 * size);
        glVertex2f(x + 0.07 * size, y + 0.126 * size);
        glVertex2f(x + 0.068 * size, y + 0.098 * size);
        glVertex2f(x + 0.064 * size, y + 0.062 * size);
        glVertex2f(x + 0.0625 * size, y + 0.0465 * size);
        glVertex2f(x + 0.056 * size, y + 0.015 * size);
        glEnd();

        glColor3f(0.25, 0.17, 0.11);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x - 0.052 * size, y + 0.324 * size);
        glVertex2f(x - 0.052 * size, y + 0.319 * size);
        glVertex2f(x - 0.056 * size, y + 0.3055 * size);
        glVertex2f(x - 0.0575 * size, y + 0.2905 * size);
        glVertex2f(x - 0.056 * size, y + 0.2496 * size);
        glEnd();

        glColor3f(0.25, 0.17, 0.11);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x + 0.03 * size, y + 0.415 * size);
        glVertex2f(x + 0.04 * size, y + 0.395 * size);
        glVertex2f(x + 0.05 * size, y + 0.371 * size);
        glVertex2f(x + 0.054 * size, y + 0.356 * size);
        glVertex2f(x + 0.06 * size, y + 0.339 * size);
        glVertex2f(x + 0.065 * size, y + 0.314 * size);
        glEnd();

        glColor3f(0.25, 0.17, 0.11);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x - 0.005 * size, y + 0.403 * size);
        glVertex2f(x - 0.011 * size, y + 0.3975 * size);
        glVertex2f(x - 0.015 * size, y + 0.3855 * size);
        glVertex2f(x - 0.022 * size, y + 0.3705 * size);
        glVertex2f(x - 0.023 * size, y + 0.361* size);
        glEnd();

        glColor3f(0.25, 0.17, 0.11);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x - 0.082 * size, y + 0.158 * size);
        glVertex2f(x - 0.082 * size, y + 0.139 * size);
        glVertex2f(x - 0.08 * size, y + 0.125 * size);
        glVertex2f(x - 0.076 * size, y + 0.118 * size);
        glVertex2f(x - 0.072 * size, y + 0.106 * size);
        glVertex2f(x - 0.062 * size, y + 0.092 * size);
        glEnd();

        glColor3f(0.25, 0.17, 0.11);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x + 0.02 * size, y + 0.125 * size);
        glVertex2f(x + 0.02 * size, y + 0.093 * size);
        glVertex2f(x + 0.0218 * size, y + 0.0772 * size);
        glEnd();

        glColor3f(0.25, 0.17, 0.11);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x - 0.055 * size, y + 0.04 * size);
        glVertex2f(x - 0.057 * size, y + 0.034 * size);
        glVertex2f(x - 0.056 * size, y + 0.019 * size);
        glVertex2f(x - 0.0535 * size, y + 0.01 * size);
        glEnd();

        // Draw the bottom triangle
        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_TRIANGLES);
        glVertex2f(x, y + 1.0 * size);
        glVertex2f(x - 0.6 * size, y + 0.4 * size);
        glVertex2f(x + 0.6 * size, y + 0.4 * size);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f); // Black outline
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y + 1.0 * size);
        glVertex2f(x - 0.6 * size, y + 0.4 * size);
        glVertex2f(x + 0.6 * size, y + 0.4 * size);
        glEnd();

        // Draw the middle triangle
        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_TRIANGLES);
        glVertex2f(x, y + 1.4 * size);
        glVertex2f(x - 0.6 * size, y + 0.8 * size);
        glVertex2f(x + 0.6 * size, y + 0.8 * size);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f); // Black outline
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y + 1.4 * size);
        glVertex2f(x - 0.6 * size, y + 0.8 * size);
        glVertex2f(x + 0.6 * size, y + 0.8 * size);
        glEnd();

        // Draw the top triangle
        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_TRIANGLES);
        glVertex2f(x, y + 1.8 * size);
        glVertex2f(x - 0.6 * size, y + 1.2 * size);
        glVertex2f(x + 0.6 * size, y + 1.2 * size);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f); // Black outline
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y + 1.8 * size);
        glVertex2f(x - 0.6 * size, y + 1.2 * size);
        glVertex2f(x + 0.6 * size, y + 1.2 * size);
        glEnd();
    }
};

class TreeTwo : public Tree
{
public:
    void draw(float x, float y, float size, Color color)
    {
        // Draw the trunk
        glColor3f(0.38, 0.26, 0.17); // Brown color
        glBegin(GL_POLYGON);
        glVertex2f(x - 0.1 * size, y);
        glVertex2f(x + 0.1 * size, y);
        glVertex2f(x + 0.1 * size, y + 0.6 * size);
        glVertex2f(x - 0.1 * size, y + 0.6 * size);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f); // Black outline
        glBegin(GL_LINE_STRIP);
        glVertex2f(x + 0.1 * size, y);
        glVertex2f(x + 0.1 * size, y + 0.6 * size);
        glVertex2f(x - 0.1 * size, y + 0.6 * size);
        glVertex2f(x - 0.1 * size, y);
        glEnd();

        glColor3f(0.25, 0.17, 0.11);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x - 0.01 * size, y + 0.24545 * size);
        glVertex2f(x - 0.0214 * size, y + 0.2492 * size);
        glVertex2f(x - 0.0306 * size, y + 0.2283 * size);
        glVertex2f(x - 0.0273 * size, y + 0.205 * size);
        glVertex2f(x - 0.015 * size, y + 0.175 * size);
        glVertex2f(x - 0.0112 * size, y + 0.1498 * size);
        glVertex2f(x + 0 * size, y + 0.148 * size);
        glVertex2f(x + 0.008 * size, y + 0.1545 * size);
        glVertex2f(x + 0.0163 * size, y + 0.1697 * size);
        glVertex2f(x + 0.0187 * size, y + 0.179 * size);
        glVertex2f(x + 0.0172 * size, y + 0.2164 * size);
        glVertex2f(x + 0.01 * size, y + 0.2292 * size);
        glVertex2f(x - 0.001 * size, y + 0.2455 * size);
        glEnd();

        glColor3f(0.25, 0.17, 0.11);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x - 0.069 * size, y + 0.197 * size);
        glVertex2f(x - 0.0691 * size, y + 0.192 * size);
        glVertex2f(x - 0.074 * size, y + 0.174 * size);
        glVertex2f(x - 0.073 * size, y + 0.138 * size);
        glVertex2f(x - 0.07 * size, y + 0.126 * size);
        glVertex2f(x - 0.068 * size, y + 0.098 * size);
        glVertex2f(x - 0.064 * size, y + 0.062 * size);
        glVertex2f(x - 0.0625 * size, y + 0.0465 * size);
        glVertex2f(x - 0.056 * size, y + 0.015 * size);
        glEnd();

        glColor3f(0.25, 0.17, 0.11);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x + 0.052 * size, y + 0.324 * size);
        glVertex2f(x + 0.052 * size, y + 0.319 * size);
        glVertex2f(x + 0.056 * size, y + 0.3055 * size);
        glVertex2f(x + 0.0575 * size, y + 0.2905 * size);
        glVertex2f(x + 0.056 * size, y + 0.2496 * size);
        glEnd();

        glColor3f(0.25, 0.17, 0.11);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x - 0.03 * size, y + 0.415 * size);
        glVertex2f(x - 0.04 * size, y + 0.395 * size);
        glVertex2f(x - 0.05 * size, y + 0.371 * size);
        glVertex2f(x - 0.054 * size, y + 0.356 * size);
        glVertex2f(x - 0.06 * size, y + 0.339 * size);
        glVertex2f(x - 0.065 * size, y + 0.314 * size);
        glEnd();

        glColor3f(0.25, 0.17, 0.11);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x + 0.005 * size, y + 0.403 * size);
        glVertex2f(x + 0.011 * size, y + 0.3975 * size);
        glVertex2f(x + 0.015 * size, y + 0.3855 * size);
        glVertex2f(x + 0.022 * size, y + 0.3705 * size);
        glVertex2f(x + 0.023 * size, y + 0.361 * size);
        glEnd();

        glColor3f(0.25, 0.17, 0.11);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x + 0.082 * size, y + 0.158 * size);
        glVertex2f(x + 0.082 * size, y + 0.139 * size);
        glVertex2f(x + 0.08 * size, y + 0.125 * size);
        glVertex2f(x + 0.076 * size, y + 0.118 * size);
        glVertex2f(x + 0.072 * size, y + 0.106 * size);
        glVertex2f(x + 0.062 * size, y + 0.092 * size);
        glEnd();

        glColor3f(0.25, 0.17, 0.11);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x - 0.02 * size, y + 0.125 * size);
        glVertex2f(x - 0.02 * size, y + 0.093 * size);
        glVertex2f(x - 0.0218 * size, y + 0.0772 * size);
        glEnd();

        glColor3f(0.25, 0.17, 0.11);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x + 0.055 * size, y + 0.04 * size);
        glVertex2f(x + 0.057 * size, y + 0.034 * size);
        glVertex2f(x + 0.056 * size, y + 0.019 * size);
        glVertex2f(x + 0.0535 * size, y + 0.01 * size);
        glEnd();

        // Draw the bottom triangle
        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_TRIANGLES);
        glVertex2f(x, y + 1.0 * size);
        glVertex2f(x - 0.4 * size, y + 0.4 * size);
        glVertex2f(x + 0.4 * size, y + 0.4 * size);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f); // Black outline
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y + 1.0 * size);
        glVertex2f(x - 0.4 * size, y + 0.4 * size);
        glVertex2f(x + 0.4 * size, y + 0.4 * size);
        glEnd();

        // Draw the middle triangle
        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_TRIANGLES);
        glVertex2f(x, y + 1.4 * size);
        glVertex2f(x - 0.4 * size, y + 0.8 * size);
        glVertex2f(x + 0.4 * size, y + 0.8 * size);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f); // Black outline
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y + 1.4 * size);
        glVertex2f(x - 0.4 * size, y + 0.8 * size);
        glVertex2f(x + 0.4 * size, y + 0.8 * size);
        glEnd();

        // Draw the top triangle
        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_TRIANGLES);
        glVertex2f(x, y + 1.8 * size);
        glVertex2f(x - 0.4 * size, y + 1.2 * size);
        glVertex2f(x + 0.4 * size, y + 1.2 * size);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f); // Black outline
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y + 1.8 * size);
        glVertex2f(x - 0.4 * size, y + 1.2 * size);
        glVertex2f(x + 0.4 * size, y + 1.2 * size);
        glEnd();
    }
};