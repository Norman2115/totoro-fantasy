#pragma once
#include <gl/glut.h>
#include <iostream>
#include "Circle.h"
#include "Colors.h"
#include "Color.h"

class Mushroom1
{
private:
    virtual void draw(float x, float y, float size, Color color) = 0;
};

class mushroom1 : public Mushroom1
{
public:
    void draw(float x, float y, float size, Color color) override
    {
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_POLYGON);
        glVertex2f(x - 0.25 * size, y - 0.5 * size);
        glVertex2f(x + 0.25 * size, y - 0.5 * size);
        glVertex2f(x + 0.25 * size, y);
        glVertex2f(x - 0.25 * size, y);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f); 
        glBegin(GL_LINE_LOOP);
        glVertex2f(x - 0.25 * size, y - 0.5 * size);
        glVertex2f(x + 0.25 * size, y - 0.5 * size);
        glVertex2f(x + 0.25 * size, y);
        glVertex2f(x - 0.25 * size, y);
        
        glEnd();


        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 180; i++) {
            float rad = i * 3.14159 / 180;
            glVertex2f(x + cos(rad) * 0.5 * size, y - 1.0 + sin(rad) * 0.5 * size);
        }
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i <= 180; i++) {
            float rad = i * 3.14159 / 180;
            glVertex2f(x + cos(rad) * 0.5 * size, y - 1.0 + sin(rad) * 0.5 * size);
        }
        glEnd();

        glColor3f(1.0f, 1.0f, 1.0f);
        drawCircle(x - 0.35 * size, y + 0.2 * size, 0.07 * size);//first
        drawCircle(x - 0.1 * size , y + 0.35 * size, 0.07 * size);
        drawCircle(x + 0.35 * size, y + 0.15 * size, 0.07 * size);//forth
        drawCircle(x + 0.1 * size, y + 0.25 * size, 0.07 * size);// third
        drawCircle(x - 0.1 * size, y + 0.09 * size, 0.07 * size);//second

        
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

class mushroom2 : public Mushroom1
{
public:
    void draw(float x, float y, float size, Color color)
    {

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_POLYGON);
        glVertex2f(x - 0.15 * size, y - 0.5 * size);
        glVertex2f(x + 0.15 * size, y - 0.5 * size);
        glVertex2f(x + 0.15 * size, y);
        glVertex2f(x - 0.15 * size, y);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f); 
        glBegin(GL_LINE_LOOP);
        glVertex2f(x - 0.15 * size, y - 0.5 * size);
        glVertex2f(x + 0.15 * size, y - 0.5 * size);
        glVertex2f(x + 0.15 * size, y);
        glVertex2f(x - 0.15 * size, y);
        glEnd();


        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 180; i++) {
            float rad = i * 3.14159 / 180;
            glVertex2f(x + cos(rad) * 0.4 * size, y - 1.0 + sin(rad) * 0.55 * size);
        }
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i <= 180; i++) {
            float rad = i * 3.14159 / 180;
            glVertex2f(x + cos(rad) * 0.4 * size, y - 1.0 + sin(rad) * 0.55 * size);
        }
        glEnd();

        glColor3f(1.0f, 1.0f, 1.0f);
        drawCircle(x - 0.20 * size, y + 0.32 * size, 0.05 * size);
        drawCircle(x - 0.01 * size, y + 0.35 * size, 0.08 * size);
        drawCircle(x - 0.30 * size, y + 0.13 * size, 0.055 * size);
        drawCircle(x + 0.24 * size, y + 0.20 * size, 0.09 * size);
       
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

class mushroom3 : public Mushroom1
{
public:
    void draw(float x, float y, float size, Color color)
    {

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_POLYGON);
        glVertex2f(x - 0.35 * size, y - 0.35 * size);
        glVertex2f(x + 0.35 * size, y - 0.35 * size);
        glVertex2f(x + 0.35 * size, y);
        glVertex2f(x - 0.35 * size, y);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f); 
        glBegin(GL_LINE_LOOP);
        glVertex2f(x - 0.35 * size, y - 0.35 * size);
        glVertex2f(x + 0.35 * size, y - 0.35 * size);
        glVertex2f(x + 0.35 * size, y);
        glVertex2f(x - 0.35 * size, y);
        glEnd();


        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 180; i++) {
            float rad = i * 3.14159 / 180;
            glVertex2f(x + cos(rad) * 0.5 * size, y - 1.0  + sin(rad) * 0.5 * size);
        }
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i <= 180; i++) {
            float rad = i * 3.14159 / 180;
            glVertex2f(x + cos(rad) * 0.5 * size, y - 1.0 + sin(rad) * 0.5 * size);
        }
        glEnd();

        glColor3f(1.0f, 1.0f, 1.0f);
        drawCircle(x - 0.05 * size, y + 0.35 * size, 0.07 * size);
        drawCircle(x - 0.2 * size, y + 0.09 * size, 0.05 * size);
        drawCircle(x + 0.35 * size, y + 0.2 * size, 0.05 * size);
        drawCircle(x + 0.15 * size, y + 0.3 * size, 0.05 * size);
        drawCircle(x - 0.25 * size, y + 0.3 * size, 0.05 * size);
        drawCircle(x + 0.10 * size, y + 0.1 * size, 0.05 * size);
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
