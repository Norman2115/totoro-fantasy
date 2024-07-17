#pragma once
#include <gl/glut.h>
#include <iostream>
#include "Constants.h"

class Circle
{
public:
    static void draw(float cx, float cy, float radius) {
        glBegin(GL_TRIANGLE_FAN);
        for (int i = 0; i < 360; i++) {
            float theta = i * Constants::PI / 180.0;
            float x = cosf(theta) * radius;
            float y = sinf(theta) * radius;
            glVertex2f(x + cx, y + cy);
        }
        glEnd();
    }
};



class SemiCircle {
public:
    static void draw(float cx, float cy, float radius, float rotationAngle, bool isClockwise) {
        glPushMatrix();
        glTranslatef(cx, cy, 0.0);  
        glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);  

        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, 0.0f);  // Center point
        float startAngle = isClockwise ? 0.0f : 180.0f;
        float endAngle = isClockwise ? 180.0f : 360.0f;
        for (float i = startAngle; i <= endAngle; i += 1.0f) {
            float theta = i * Constants::PI / 180.0f;
            float x = cos(theta) * radius;
            float y = sin(theta) * radius;
            glVertex2f(x, y);
        }
        glEnd();

        glPopMatrix();
    }
};

