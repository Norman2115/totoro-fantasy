#pragma once
#include <gl/glut.h>
#include <iostream>
#include "Colors.h"
#include "Color.h"

class Island
{
private:
	virtual void draw(float x, float y, float size, Color color) = 0;
};

class IslandOne : public Island {
public:
    void draw(float x, float y, float size, Color color) {

        glColor3f(0.57, 0.58, 0.58);
        glBegin(GL_POLYGON);
        glVertex2f(x - 0.28 * size, y + 0.22 * size);
        glVertex2f(x + 0.28 * size, y + 0.22 * size);
        glVertex2f(x + 0.29  * size, y + 0.16 * size);
        glVertex2f(x + 0.276  * size, y + 0.035  * size);
        glVertex2f(x + 0.175 * size, y - 0.074 * size);
        glVertex2f(x + 0.127 * size, y - 0.144 * size);
        glVertex2f(x + 0.1125 * size, y - 0.253 * size);
        glVertex2f(x + 0.0552 * size, y - 0.2108* size);
        glVertex2f(x + 0 * size, y - 0.1 * size);
        glVertex2f(x - 0.0765 * size, y - 0.0295 * size);
        glVertex2f(x - 0.1834  * size, y + 0.024 * size);
        glVertex2f(x - 0.26744 * size, y + 0.06604 * size);
        glVertex2f(x - 0.2885 * size, y + 0.1445 * size);
        glEnd();

        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_POLYGON);
        glVertex2f(x - 0.27 * size, y + 0.27 * size);
        glVertex2f(x + 0.27 * size, y + 0.27 * size);
        glVertex2f(x + 0.28 * size, y + 0.21 * size);
        glVertex2f(x - 0.28 * size, y + 0.21 * size);
        glEnd();


        glColor3f(0.57, 0.58, 0.58);
        glBegin(GL_POLYGON);
        glVertex2f(x - 0.3865 * size, y + 0.037 * size);
        glVertex2f(x - 0.3381 * size, y + 0.0354 * size);
        glVertex2f(x - 0.32085 * size, y - 0.02674 * size);
        glVertex2f(x - 0.3157 * size, y - 0.0768 * size);
        glVertex2f(x - 0.33295 * size, y - 0.1372 * size);
        glVertex2f(x - 0.36055 * size, y - 0.10785 * size);
        glVertex2f(x - 0.3792 * size, y - 0.0439 * size);
        glEnd();
    }
};

class IslandTwo : public Island {
public:
    void draw(float x, float y, float size, Color color) {

        glColor3f(0.57, 0.58, 0.58);
        glBegin(GL_POLYGON);
        glVertex2f(x - 0.2 * size, y + 0.2 * size);
        glVertex2f(x + 0.2 * size, y + 0.2 * size);
        glVertex2f(x + 0.19445 * size, y + 0.12241  * size);
        glVertex2f(x + 0.17474 * size, y + 0.04028 * size);
        glVertex2f(x + 0.08493 * size, y - 0.01338 * size);
        glVertex2f(x - 0.0344 * size, y - 0.067 * size);
        glVertex2f(x - 0.12095 * size, y - 0.01668 * size);
        glVertex2f(x - 0.18556 * size, y + 0.04794 * size);
        glVertex2f(x - 0.1987 * size, y + 0.13885 * size);
        glEnd();

        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_POLYGON);
        glVertex2f(x - 0.2 * size, y + 0.2 * size);
        glVertex2f(x + 0.2 * size, y + 0.2 * size);
        glVertex2f(x + 0.1977 * size, y + 0.16881 * size);
        glVertex2f(x - 0.1993 * size, y + 0.16881 * size);
        glEnd();

        glColor3f(0.57, 0.58, 0.58);
        glBegin(GL_POLYGON);
        glVertex2f(x + 0.161 * size, y - 0.032 * size);
        glVertex2f(x + 0.2368 * size, y - 0.0216 * size);
        glVertex2f(x + 0.273 * size, y - 0.0561 * size);  
        glVertex2f(x + 0.2523 * size, y - 0.10785 * size);
        glVertex2f(x + 0.18326 * size, y - 0.10268 * size);
        glVertex2f(x + 0.15393 * size, y - 0.07162 * size); 
        glEnd();
    }
};