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