#pragma once
#include <gl/glut.h>
#include "Circle.h"
#include "Colors.h"
#include "Color.h"

class BusSignBoard
{
public:
	void draw(float x, float y, float size, Color color)
	{
		glColor3f(color.getR(), color.getG(), color.getB());
        
        glBegin(GL_POLYGON);
        glVertex2f(x + 1.9 * size, y + 0.295 * size);
        glVertex2f(x + 2.35 * size, y + 0.295 * size);
        glVertex2f(x + 2.35 * size, y + 0.05 * size);
        glVertex2f(x + 1.9 * size, y + 0.05 * size);
        glEnd();

        
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x + 1.9 * size, y + 0.295 * size);
        glVertex2f(x + 2.35 * size, y + 0.295 * size);
        glVertex2f(x + 2.35 * size, y + 0.05 * size);
        glVertex2f(x + 1.9 * size, y + 0.05 * size);
        glEnd();

        
        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_POLYGON);
        glVertex2f(x + 2.15 * size, y + 0.05 * size);
        glVertex2f(x + 2.10 * size, y + 0.05 * size);
        glVertex2f(x + 2.10 * size, y - 0.275 * size);
        glVertex2f(x + 2.15 * size, y - 0.275 * size);
        glEnd();

        
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x + 2.15 * size, y + 0.05 * size);
        glVertex2f(x + 2.10 * size, y + 0.05 * size);
        glVertex2f(x + 2.10 * size, y - 0.275 * size);
        glVertex2f(x + 2.15 * size, y - 0.275 * size);
        glEnd();

        // Draw cat head with yellow color
        glColor3f(1.0f, 1.0f, 0.0f);
        float radius = 0.07 * size;
        int numSegments = 100;
        glBegin(GL_POLYGON);
        for (int i = 0; i < numSegments; i++) {
            float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
            float dx = radius * cosf(theta);
            float dy = radius * sinf(theta);
            glVertex2f(x + 2.125 * size + dx, y + 0.17 * size + dy);
        }
        glEnd();

        // Draw black outline for cat head
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < numSegments; i++) {
            float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
            float dx = radius * cosf(theta);
            float dy = radius * sinf(theta);
            glVertex2f(x + 2.125 * size + dx, y + 0.17 * size + dy);
        }
        glEnd();

        // Draw cat ears with yellow color
        glColor3f(1.0f, 1.0f, 0.0f);
        glBegin(GL_POLYGON);
        glVertex2f(x + 2.19 * size, y + 0.2 * size); 
        glVertex2f(x + 2.2 * size, y + 0.27 * size); 
        glVertex2f(x + 2.14 * size, y + 0.24 * size); 
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(x + 2.10 * size, y + 0.24 * size);
        glVertex2f(x + 2.05445 * size, y + 0.18957 * size);
        glVertex2f(x + 2.03576 * size, y + 0.26577 * size);
        glEnd();

        // Draw black outline for cat ears
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x + 2.19 * size, y + 0.2 * size);
        glVertex2f(x + 2.2 * size, y + 0.27 * size);
        glVertex2f(x + 2.14 * size, y + 0.24 * size);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glVertex2f(x + 2.10 * size, y + 0.24 * size);
        glVertex2f(x + 2.05445 * size, y + 0.18957 * size);
        glVertex2f(x + 2.03576 * size, y + 0.26577 * size);
        
        
        glEnd();
    }
	
};