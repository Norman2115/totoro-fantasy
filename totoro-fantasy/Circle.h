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
    static void draw(float cx, float cy, float radius, bool isClockwise) {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        int startAngle = isClockwise ? 0 : 180;
        int endAngle = isClockwise ? 180 : 360;
        for (int i = startAngle; i <= endAngle; i++) {
            float theta = i * Constants::PI / 180.0f;
            float x = cos(theta) * radius;
            float y = sin(theta) * radius;
            glVertex2f(x + cx, y + cy);
        }
        glEnd();
    }
};