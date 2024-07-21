#pragma once
#include <gl/glut.h>
#include "Circle.h"
#include "Colors.h"
#include "Color.h"

class BusSignBoard
{
public:
    void draw(float x, float y, float size, float scale)
    {
        // Adjust the size with scale
        float scaledSize = size * scale;

        glColor3f(0.76, 0.49, 0.23);

        glBegin(GL_POLYGON);
        glVertex2f(x + 1.9 * scaledSize, y + 0.295 * scaledSize);
        glVertex2f(x + 2.35 * scaledSize, y + 0.295 * scaledSize);
        glVertex2f(x + 2.35 * scaledSize, y + 0.05 * scaledSize);
        glVertex2f(x + 1.9 * scaledSize, y + 0.05 * scaledSize);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x + 1.9 * scaledSize, y + 0.295 * scaledSize);
        glVertex2f(x + 2.35 * scaledSize, y + 0.295 * scaledSize);
        glVertex2f(x + 2.35 * scaledSize, y + 0.05 * scaledSize);
        glVertex2f(x + 1.9 * scaledSize, y + 0.05 * scaledSize);
        glEnd();

        glColor3f(0.76, 0.49, 0.23);
        glBegin(GL_POLYGON);
        glVertex2f(x + 2.15 * scaledSize, y + 0.05 * scaledSize);
        glVertex2f(x + 2.10 * scaledSize, y + 0.05 * scaledSize);
        glVertex2f(x + 2.10 * scaledSize, y - 0.275 * scaledSize);
        glVertex2f(x + 2.15 * scaledSize, y - 0.275 * scaledSize);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x + 2.15 * scaledSize, y + 0.05 * scaledSize);
        glVertex2f(x + 2.10 * scaledSize, y + 0.05 * scaledSize);
        glVertex2f(x + 2.10 * scaledSize, y - 0.275 * scaledSize);
        glVertex2f(x + 2.15 * scaledSize, y - 0.275 * scaledSize);
        glEnd();

        // Draw cat head with yellow color
        glColor3f(0.93, 0.71, 0.15);
        float radius = 0.07 * scaledSize;
        int numSegments = 100;
        glBegin(GL_POLYGON);
        for (int i = 0; i < numSegments; i++) {
            float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
            float dx = radius * cosf(theta);
            float dy = radius * sinf(theta);
            glVertex2f(x + 2.125 * scaledSize + dx, y + 0.17 * scaledSize + dy);
        }
        glEnd();

        // Draw black outline for cat head
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < numSegments; i++) {
            float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
            float dx = radius * cosf(theta);
            float dy = radius * sinf(theta);
            glVertex2f(x + 2.125 * scaledSize + dx, y + 0.17 * scaledSize + dy);
        }
        glEnd();

        // Draw cat ears with yellow color
        glColor3f(0.93, 0.71, 0.15);
        glBegin(GL_POLYGON);
        glVertex2f(x + 2.19 * scaledSize, y + 0.2 * scaledSize);
        glVertex2f(x + 2.2 * scaledSize, y + 0.27 * scaledSize);
        glVertex2f(x + 2.14 * scaledSize, y + 0.24 * scaledSize);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(x + 2.10 * scaledSize, y + 0.24 * scaledSize);
        glVertex2f(x + 2.05445 * scaledSize, y + 0.18957 * scaledSize);
        glVertex2f(x + 2.03576 * scaledSize, y + 0.26577 * scaledSize);
        glEnd();

        // Draw black outline for cat ears
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x + 2.19 * scaledSize, y + 0.2 * scaledSize);
        glVertex2f(x + 2.2 * scaledSize, y + 0.27 * scaledSize);
        glVertex2f(x + 2.14 * scaledSize, y + 0.24 * scaledSize);
        glEnd();


        glBegin(GL_LINE_STRIP);
        glVertex2f(x + 2.10 * scaledSize, y + 0.24 * scaledSize);
        glVertex2f(x + 2.03576 * scaledSize, y + 0.26577 * scaledSize);
        glVertex2f(x + 2.05445 * scaledSize, y + 0.18957 * scaledSize);

        glEnd();
    }
};