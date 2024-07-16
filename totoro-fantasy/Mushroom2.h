#pragma once
#include <gl/glut.h>
#include "Circle.h"
#include "Colors.h"
#include "Color.h"

class Mushroom2
{
private:
    virtual void draw(float x, float y, float size, Color color) = 0;
};

class mushroom2 : public Mushroom2
{
public:
    void draw(float x, float y, float size, Color color)
    {
        
        glColor3f(1.0f, 1.0f, 1.0f); 
        glBegin(GL_POLYGON);
        glVertex2f(x - 0.25 * size, y - 0.5 * size);
        glVertex2f(x + 0.25 * size, y - 0.5 * size);
        glVertex2f(x + 0.25 * size, y);
        glVertex2f(x - 0.25 * size, y);
        glEnd();

        
        glColor3f(128.0f / 255.0f, 0.0f / 255.0f, 32.0f / 255.0f);
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 180; i++) {
            float rad = i * 3.14159 / 180;
            glVertex2f(x + cos(rad) * 0.5 * size, y + sin(rad) * 0.5 * size);
        }
        glEnd();

        
        glColor3f(1.0f, 1.0f, 1.0f); 
        drawCircle(x - 0.25 * size, y + 0.35 * size, 0.08 * size);
        drawCircle(x + 0.3 * size, y + 0.25 * size, 0.1 * size);
        drawCircle(x + 0.10 * size, y + 0.4 * size, 0.10 * size);
        drawCircle(x - 0.2 * size, y + 0.1 * size, 0.07 * size);
        drawCircle(x + 0.1 * size, y + 0.15 * size, 0.09 * size);
    }

    void drawCircle(float cx, float cy, float r) {
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float rad = i * 3.14159 / 180;
            glVertex2f(cx + cos(rad) * r, cy + sin(rad) * r);
        }
        glEnd();


    }
};
