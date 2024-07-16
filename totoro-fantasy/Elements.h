#pragma once
#include <gl/glut.h>
#include <iostream>
#include "Colors.h"
#include "Color.h"
#include "Circle.h"

class Elements
{
private:
    virtual void draw(float x, float y, float size, Color color) = 0;
};

class SmallRockOne : public Elements {
    public:
        void draw(float x, float y, float size, Color color) {
            glColor3f(color.getR(), color.getG(), color.getB());

            glBegin(GL_POLYGON);
            glVertex2f(x - 0.49 * size, y - 0.03 * size);
            glVertex2f(x - 0.4 * size, y + 0.2 * size);
            glVertex2f(x - 0.29 * size, y + 0.28 * size);
            glVertex2f(x - 0.14 * size, y + 0.25 * size);
            glVertex2f(x + 0.28 * size, y + 0.11 * size);
            glVertex2f(x + 0.33 * size, y + 0.03 * size);
            glVertex2f(x + 0.2 * size, y - 0.2 * size);
            glVertex2f(x - 0.28 * size, y - 0.18 * size);
            glEnd();

            glColor3f(0.0, 0.0, 0.0); 
            glBegin(GL_LINE_STRIP);
            glVertex2f(x - 0.49 * size, y - 0.03 * size);
            glVertex2f(x - 0.4 * size, y + 0.2 * size);
            glVertex2f(x - 0.29 * size, y + 0.28 * size);
            glVertex2f(x - 0.14 * size, y + 0.25 * size);
            glVertex2f(x + 0.28 * size, y + 0.11 * size);
            glVertex2f(x + 0.33 * size, y + 0.03 * size);
            glVertex2f(x + 0.2 * size, y - 0.2 * size);
            glVertex2f(x - 0.28 * size, y - 0.18 * size);
            glVertex2f(x - 0.49 * size, y - 0.03 * size);  
            glEnd();
        }
};

class SmallRockTwo : public Elements {
public:
    void draw(float x, float y, float size, Color color) {
        glColor3f(color.getR(), color.getG(), color.getB());

        glBegin(GL_POLYGON);
        glVertex2f(x - 0.21 * size, y - 0.03 * size);
        glVertex2f(x - 0.19 * size, y + 0.09 * size);
        glVertex2f(x - 0.14 * size, y + 0.14 * size);
        glVertex2f(x - 0.06 * size, y + 0.18 * size);
        glVertex2f(x + 0.04 * size, y + 0.17 * size);
        glVertex2f(x + 0.16 * size, y + 0.12 * size);
        glVertex2f(x + 0.27 * size, y + 0.06 * size);
        glVertex2f(x + 0.28 * size, y - 0.03 * size);
        glVertex2f(x + 0.21 * size, y - 0.09 * size);
        glVertex2f(x + 0.14 * size, y - 0.1 * size);
        glVertex2f(x + 0.07 * size, y - 0.11* size);
        glVertex2f(x - 0.13 * size, y - 0.08 * size);
        glEnd();

        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x - 0.21 * size, y - 0.03 * size);
        glVertex2f(x - 0.19 * size, y + 0.09 * size);
        glVertex2f(x - 0.14 * size, y + 0.14 * size);
        glVertex2f(x - 0.06 * size, y + 0.18 * size);
        glVertex2f(x + 0.04 * size, y + 0.17 * size);
        glVertex2f(x + 0.16 * size, y + 0.12 * size);
        glVertex2f(x + 0.27 * size, y + 0.06 * size);
        glVertex2f(x + 0.28 * size, y - 0.03 * size);
        glVertex2f(x + 0.21 * size, y - 0.09 * size);
        glVertex2f(x + 0.14 * size, y - 0.1 * size);
        glVertex2f(x + 0.07 * size, y - 0.11 * size);
        glVertex2f(x - 0.13 * size, y - 0.08 * size);
        glVertex2f(x - 0.21 * size, y - 0.03 * size);
        glEnd();
    }
};

class GrassOne : public Elements {
public:
    void draw(float x, float y, float size, Color color) {
        glColor3f(color.getR(), color.getG(), color.getB());

        glBegin(GL_POLYGON);
        glVertex2f(x - 0.14 * size, y - 0.08 * size);
        glVertex2f(x - 0.172 * size, y + 0.11 * size);
        glVertex2f(x - 0.116 * size, y + 0.083 * size);
        glVertex2f(x - 0.09 * size, y + 0.06 * size);
        glVertex2f(x - 0.038 * size, y + 0.201 * size);
        glVertex2f(x - 0.019 * size, y + 0.133 * size);
        glVertex2f(x - 0.006 * size, y + 0.095 * size);
        glVertex2f(x + 0.007 * size, y + 0.062 * size);
        glVertex2f(x + 0.096 * size, y + 0.135 * size);
        glVertex2f(x + 0.12 * size, y + 0.148 * size);
        glVertex2f(x + 0.112 * size, y + 0.111 * size);
        glVertex2f(x + 0.098 * size, y + 0.082 * size);
        glVertex2f(x + 0.092 * size, y + 0.05 * size);
        glVertex2f(x + 0.089 * size, y + 0.023 * size);
        glVertex2f(x + 0.086 * size, y - 0.006 * size);
        glVertex2f(x + 0.085 * size, y - 0.037 * size);
        glVertex2f(x + 0.09 * size, y - 0.058 * size);
        glVertex2f(x + 0.112 * size, y - 0.08 * size);
        glEnd();

        glColor3f(0.22, 0.3, 0.17);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x - 0.14 * size, y - 0.08 * size);  
        glVertex2f(x - 0.172 * size, y + 0.11 * size);   
        glVertex2f(x - 0.116 * size, y + 0.083 * size);  
        glVertex2f(x - 0.09 * size, y + 0.06 * size);  
        glVertex2f(x - 0.038 * size, y + 0.201 * size);  
        glVertex2f(x - 0.019 * size, y + 0.133 * size);  
        glVertex2f(x - 0.006 * size, y + 0.095 * size);  
        glVertex2f(x + 0.007 * size, y + 0.062 * size);   
        glVertex2f(x + 0.096 * size, y + 0.135 * size);  
        glVertex2f(x + 0.12 * size, y + 0.148 * size); 
        glVertex2f(x + 0.112 * size, y + 0.111 * size);
        glVertex2f(x + 0.098 * size, y + 0.082 * size);  
        glVertex2f(x + 0.092 * size, y + 0.05 * size);
        glVertex2f(x + 0.089 * size, y + 0.023 * size);
        glVertex2f(x + 0.086 * size, y - 0.006 * size);
        glVertex2f(x + 0.085 * size, y - 0.037 * size);
        glVertex2f(x + 0.09 * size, y - 0.058 * size);
        glVertex2f(x + 0.112 * size, y - 0.08 * size);
        glEnd();
    }

    void drawWithRotation(float x, float y, float size, float angle, Color color) {
        glPushMatrix();
        glColor3f(color.getR(), color.getG(), color.getB());
        glTranslatef(x, y, 0.0f); // Move to the position (x, y)
        glRotatef(angle, 0.0f, 0.0f, 1.0f); // Rotate around the z-axis
        glTranslatef(-x, -y, 0.0f); // Move back to the origin

        glBegin(GL_POLYGON);
        glVertex2f(x - 0.14 * size, y - 0.08 * size);
        glVertex2f(x - 0.172 * size, y + 0.11 * size);
        glVertex2f(x - 0.116 * size, y + 0.083 * size);
        glVertex2f(x - 0.09 * size, y + 0.06 * size);
        glVertex2f(x - 0.038 * size, y + 0.201 * size);
        glVertex2f(x - 0.019 * size, y + 0.133 * size);
        glVertex2f(x - 0.006 * size, y + 0.095 * size);
        glVertex2f(x + 0.007 * size, y + 0.062 * size);
        glVertex2f(x + 0.096 * size, y + 0.135 * size);
        glVertex2f(x + 0.12 * size, y + 0.148 * size);
        glVertex2f(x + 0.112 * size, y + 0.111 * size);
        glVertex2f(x + 0.098 * size, y + 0.082 * size);
        glVertex2f(x + 0.092 * size, y + 0.05 * size);
        glVertex2f(x + 0.089 * size, y + 0.023 * size);
        glVertex2f(x + 0.086 * size, y - 0.006 * size);
        glVertex2f(x + 0.085 * size, y - 0.037 * size);
        glVertex2f(x + 0.09 * size, y - 0.058 * size);
        glVertex2f(x + 0.112 * size, y - 0.08 * size);
        glEnd();

        glColor3f(0.22, 0.3, 0.17);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x - 0.14 * size, y - 0.08 * size);
        glVertex2f(x - 0.172 * size, y + 0.11 * size);
        glVertex2f(x - 0.116 * size, y + 0.083 * size);
        glVertex2f(x - 0.09 * size, y + 0.06 * size);
        glVertex2f(x - 0.038 * size, y + 0.201 * size);
        glVertex2f(x - 0.019 * size, y + 0.133 * size);
        glVertex2f(x - 0.006 * size, y + 0.095 * size);
        glVertex2f(x + 0.007 * size, y + 0.062 * size);
        glVertex2f(x + 0.096 * size, y + 0.135 * size);
        glVertex2f(x + 0.12 * size, y + 0.148 * size);
        glVertex2f(x + 0.112 * size, y + 0.111 * size);
        glVertex2f(x + 0.098 * size, y + 0.082 * size);
        glVertex2f(x + 0.092 * size, y + 0.05 * size);
        glVertex2f(x + 0.089 * size, y + 0.023 * size);
        glVertex2f(x + 0.086 * size, y - 0.006 * size);
        glVertex2f(x + 0.085 * size, y - 0.037 * size);
        glVertex2f(x + 0.09 * size, y - 0.058 * size);
        glVertex2f(x + 0.112 * size, y - 0.08 * size);
        glEnd();

        glPopMatrix();
    }
};

class GrassTwo : public Elements {
public:
    void draw(float x, float y, float size, Color color) {
        glColor3f(color.getR(), color.getG(), color.getB());

        glBegin(GL_POLYGON);
        glVertex2f(x - 0.4 * size, y - 0.1 * size); 
        glVertex2f(x - 0.433 * size, y + 0.1 * size);  
        glVertex2f(x - 0.336 * size, y + 0.08 * size);  
        glVertex2f(x - 0.27 * size, y + 0.0165 * size);   
        glVertex2f(x - 0.11 * size, y + 0.19 * size); 
        glVertex2f(x + 0.04 * size, y + 0.27 * size);  
        glVertex2f(x + 0.02 * size, y + 0.22 * size);  
        glVertex2f(x + 0 * size, y + 0.1 * size);    
        glVertex2f(x + 0.008 * size, y + 0.034 * size);    
        glVertex2f(x + 0.05 * size, y + 0.047 * size); 
        glVertex2f(x + 0.122 * size, y + 0.08 * size);  
        glVertex2f(x + 0.109 * size, y + 0.038 * size);       
        glVertex2f(x + 0.24 * size, y + 0.07 * size);   
        glVertex2f(x + 0.345 * size, y + 0.114 * size); 
        glVertex2f(x + 0.3 * size, y + 0 * size);       
        glVertex2f(x + 0.28 * size, y - 0.06 * size);    
        glVertex2f(x + 0.3 * size, y - 0.1 * size);   
        glEnd();

        glColor3f(0.22, 0.3, 0.17);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x - 0.4 * size, y - 0.1 * size);
        glVertex2f(x - 0.433 * size, y + 0.1 * size);
        glVertex2f(x - 0.336 * size, y + 0.08 * size);
        glVertex2f(x - 0.27 * size, y + 0.0165 * size);
        glVertex2f(x - 0.11 * size, y + 0.19 * size);
        glVertex2f(x + 0.04 * size, y + 0.27 * size);
        glVertex2f(x + 0.02 * size, y + 0.22 * size);
        glVertex2f(x + 0 * size, y + 0.1 * size);
        glVertex2f(x + 0.008 * size, y + 0.034 * size);
        glVertex2f(x + 0.05 * size, y + 0.047 * size);
        glVertex2f(x + 0.122 * size, y + 0.08 * size);
        glVertex2f(x + 0.109 * size, y + 0.038 * size);
        glVertex2f(x + 0.24 * size, y + 0.07 * size);
        glVertex2f(x + 0.345 * size, y + 0.114 * size);
        glVertex2f(x + 0.3 * size, y + 0 * size);
        glVertex2f(x + 0.28 * size, y - 0.06 * size);
        glVertex2f(x + 0.3 * size, y - 0.1 * size);
        glEnd();
    }

    void drawWithRotation(float x, float y, float size, float angle, Color color) {
        glPushMatrix();
        glColor3f(color.getR(), color.getG(), color.getB());
        glTranslatef(x, y, 0.0f); // Move to the position (x, y)
        glRotatef(angle, 0.0f, 0.0f, 1.0f); // Rotate around the z-axis
        glTranslatef(-x, -y, 0.0f); // Move back to the origin

        glBegin(GL_POLYGON);
        glVertex2f(x - 0.4 * size, y - 0.1 * size);
        glVertex2f(x - 0.433 * size, y + 0.1 * size);
        glVertex2f(x - 0.336 * size, y + 0.08 * size);
        glVertex2f(x - 0.27 * size, y + 0.0165 * size);
        glVertex2f(x - 0.11 * size, y + 0.19 * size);
        glVertex2f(x + 0.04 * size, y + 0.27 * size);
        glVertex2f(x + 0.02 * size, y + 0.22 * size);
        glVertex2f(x + 0 * size, y + 0.1 * size);
        glVertex2f(x + 0.008 * size, y + 0.034 * size);
        glVertex2f(x + 0.05 * size, y + 0.047 * size);
        glVertex2f(x + 0.122 * size, y + 0.08 * size);
        glVertex2f(x + 0.109 * size, y + 0.038 * size);
        glVertex2f(x + 0.24 * size, y + 0.07 * size);
        glVertex2f(x + 0.345 * size, y + 0.114 * size);
        glVertex2f(x + 0.3 * size, y + 0 * size);
        glVertex2f(x + 0.28 * size, y - 0.06 * size);
        glVertex2f(x + 0.3 * size, y - 0.1 * size);
        glEnd();

        glColor3f(0.22, 0.3, 0.17);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x - 0.4 * size, y - 0.1 * size);
        glVertex2f(x - 0.433 * size, y + 0.1 * size);
        glVertex2f(x - 0.336 * size, y + 0.08 * size);
        glVertex2f(x - 0.27 * size, y + 0.0165 * size);
        glVertex2f(x - 0.11 * size, y + 0.19 * size);
        glVertex2f(x + 0.04 * size, y + 0.27 * size);
        glVertex2f(x + 0.02 * size, y + 0.22 * size);
        glVertex2f(x + 0 * size, y + 0.1 * size);
        glVertex2f(x + 0.008 * size, y + 0.034 * size);
        glVertex2f(x + 0.05 * size, y + 0.047 * size);
        glVertex2f(x + 0.122 * size, y + 0.08 * size);
        glVertex2f(x + 0.109 * size, y + 0.038 * size);
        glVertex2f(x + 0.24 * size, y + 0.07 * size);
        glVertex2f(x + 0.345 * size, y + 0.114 * size);
        glVertex2f(x + 0.3 * size, y + 0 * size);
        glVertex2f(x + 0.28 * size, y - 0.06 * size);
        glVertex2f(x + 0.3 * size, y - 0.1 * size);
        glEnd();

        glPopMatrix();
    }
};

class GrassLineOne : public Elements {
public:
    void draw(float x, float y, float size, Color color) {
        glColor3f(color.getR(), color.getG(), color.getB());

        glColor3f(0.22, 0.3, 0.17);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x - 0.14 * size, y - 0.08 * size);
        glVertex2f(x - 0.172 * size, y + 0.11 * size);
        glVertex2f(x - 0.116 * size, y + 0.083 * size);
        glVertex2f(x - 0.09 * size, y + 0.06 * size);
        glVertex2f(x - 0.038 * size, y + 0.201 * size);
        glVertex2f(x - 0.019 * size, y + 0.133 * size);
        glVertex2f(x - 0.006 * size, y + 0.095 * size);
        glVertex2f(x + 0.007 * size, y + 0.062 * size);
        glVertex2f(x + 0.096 * size, y + 0.135 * size);
        glVertex2f(x + 0.12 * size, y + 0.148 * size);
        glVertex2f(x + 0.112 * size, y + 0.111 * size);
        glVertex2f(x + 0.098 * size, y + 0.082 * size);
        glVertex2f(x + 0.092 * size, y + 0.05 * size);
        glVertex2f(x + 0.089 * size, y + 0.023 * size);
        glVertex2f(x + 0.086 * size, y - 0.006 * size);
        glVertex2f(x + 0.085 * size, y - 0.037 * size);
        glVertex2f(x + 0.09 * size, y - 0.058 * size);
        glVertex2f(x + 0.112 * size, y - 0.08 * size);
        glEnd();
    }
};

class GrassLineTwo : public Elements {
public:
    void draw(float x, float y, float size, Color color) {
        glColor3f(color.getR(), color.getG(), color.getB());

        glColor3f(0.22, 0.3, 0.17);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x - 0.4 * size, y - 0.1 * size);
        glVertex2f(x - 0.433 * size, y + 0.1 * size);
        glVertex2f(x - 0.336 * size, y + 0.08 * size);
        glVertex2f(x - 0.27 * size, y + 0.0165 * size);
        glVertex2f(x - 0.11 * size, y + 0.19 * size);
        glVertex2f(x + 0.04 * size, y + 0.27 * size);
        glVertex2f(x + 0.02 * size, y + 0.22 * size);
        glVertex2f(x + 0 * size, y + 0.1 * size);
        glVertex2f(x + 0.008 * size, y + 0.034 * size);
        glVertex2f(x + 0.05 * size, y + 0.047 * size);
        glVertex2f(x + 0.122 * size, y + 0.08 * size);
        glVertex2f(x + 0.109 * size, y + 0.038 * size);
        glVertex2f(x + 0.24 * size, y + 0.07 * size);
        glVertex2f(x + 0.345 * size, y + 0.114 * size);
        glVertex2f(x + 0.3 * size, y + 0 * size);
        glVertex2f(x + 0.28 * size, y - 0.06 * size);
        glVertex2f(x + 0.3 * size, y - 0.1 * size);
        glEnd();
    }
};