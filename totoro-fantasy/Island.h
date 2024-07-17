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
        glVertex2f(x - 0.29 * size, y + 0.26 * size);
        glVertex2f(x + 0.29 * size, y + 0.26 * size);
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
        glVertex2f(x - 0.3 * size, y + 0.27 * size);
        glVertex2f(x + 0.3 * size, y + 0.27 * size);
        glVertex2f(x + 0.29 * size, y + 0.21 * size);
        glVertex2f(x - 0.29 * size, y + 0.21 * size);
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

