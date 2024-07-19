#pragma once
#include <gl/glut.h>
#include <iostream>
#include "Circle.h"
#include "Colors.h"
#include "Color.h"

class Mushroom1
{
private:
    virtual void draw(float x, float y, float size, Color color, bool Line) = 0;
};

class mushroomOne : public Mushroom1
{
public:
    void draw(float x, float y, float size, Color color, bool Line) override
    {
        // mushroom stem
        glColor3f(1, 0.97, 0.89);
        glBegin(GL_POLYGON);
        glVertex2f(x - 0.25 * size, y);
        glVertex2f(x + 0.25 * size, y);
        glVertex2f(x + 0.25 * size, y + 0.5 * size);
        glVertex2f(x - 0.25 * size, y + 0.5 * size);
        glEnd();

        if (Line)
        {
            glPushMatrix();
            glLineWidth(1.0f);
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(x - 0.25 * size, y);
            glVertex2f(x + 0.25 * size, y);
            glVertex2f(x + 0.25 * size, y + 0.5 * size);
            glVertex2f(x - 0.25 * size, y + 0.5 * size);
            glEnd();
            glPopMatrix();
        }

        if (Line)
        {
            glColor3f(0.87, 0.83, 0.74);
            glBegin(GL_LINES);
            glVertex2f(x - 0.09 * size, y + 0.45 * size);
            glVertex2f(x - 0.09 * size, y + 0.25 * size);
            glVertex2f(x - 0.2 * size, y + 0.50 * size);
            glVertex2f(x - 0.2 * size, y + 0.30 * size);
            glVertex2f(x + 0.12 * size, y + 0.25 * size);
            glVertex2f(x + 0.12 * size, y + 0.05 * size);
            glVertex2f(x + 0.07 * size, y + 0.50 * size);
            glVertex2f(x + 0.07 * size, y + 0.43 * size);
            glVertex2f(x, y + 0.15 * size);
            glVertex2f(x, y);
            glEnd();
        }


        // mushroom top
        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 180; i++) {
            float rad = i * 3.14159 / 180;
            glVertex2f(x + cos(rad) * 0.5 * size, y + 0.5 * size + sin(rad) * 0.5 * size);
        }
        glEnd();


        if (Line)
        {
            glPushMatrix();
            glLineWidth(1.0f);
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            for (int i = 0; i <= 180; i++) {
                float rad = i * 3.14159 / 180;
                glVertex2f(x + cos(rad) * 0.5 * size, y + 0.5 * size + sin(rad) * 0.5 * size);
            }
            glEnd();
            glPopMatrix();
        }

        // mushroom spots
        glColor3f(1.0f, 1.0f, 1.0f);
        drawCircle(x - 0.35 * size, y + 0.7 * size, 0.07 * size);
        drawCircle(x - 0.1 * size, y + 0.85 * size, 0.07 * size);
        drawCircle(x + 0.35 * size, y + 0.65 * size, 0.07 * size);
        drawCircle(x + 0.1 * size, y + 0.75 * size, 0.07 * size);
        drawCircle(x - 0.1 * size, y + 0.59 * size, 0.07 * size);
    
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

class mushroomTwo : public Mushroom1
{
public:
    void draw(float x, float y, float size, Color color, bool Line)
    {
        // Stem
        glColor3f(1, 0.97, 0.89);
        glBegin(GL_POLYGON);
        glVertex2f(x - 0.15 * size, y);
        glVertex2f(x + 0.15 * size, y);
        glVertex2f(x + 0.15 * size, y + 0.5 * size);
        glVertex2f(x - 0.15 * size, y + 0.5 * size);
        glEnd();

        if (Line)
        {
            glPushMatrix();
            glLineWidth(1.0f);
            // Stem outline
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(x - 0.15 * size, y);
            glVertex2f(x + 0.15 * size, y);
            glVertex2f(x + 0.15 * size, y + 0.5 * size);
            glVertex2f(x - 0.15 * size, y + 0.5 * size);
            glEnd();
            glPopMatrix();
        }

        // Cap
        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 180; i++) {
            float rad = i * 3.14159 / 180;
            glVertex2f(x + cos(rad) * 0.4 * size, y + 0.5 * size + sin(rad) * 0.55 * size);
        }
        glEnd();

        if (Line)
        {
            glPushMatrix();
            glLineWidth(1.0f);
            // Cap outline
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            for (int i = 0; i <= 180; i++) {
                float rad = i * 3.14159 / 180;
                glVertex2f(x + cos(rad) * 0.4 * size, y + 0.5 * size + sin(rad) * 0.55 * size);
            }
            glEnd();
            glPopMatrix();
        }

        // Cap circles
        glColor3f(1.0f, 1.0f, 1.0f);
        drawCircle(x - 0.20 * size, y + 0.82 * size, 0.05 * size);
        drawCircle(x - 0.01 * size, y + 0.85 * size, 0.08 * size);
        drawCircle(x - 0.30 * size, y + 0.63 * size, 0.055 * size);
        drawCircle(x + 0.24 * size, y + 0.70 * size, 0.09 * size);
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

class mushroomThree : public Mushroom1
{
public:
    void draw(float x, float y, float size, Color color, bool Line)
    {
        // Stem
        glColor3f(1, 0.97, 0.89);
        glBegin(GL_POLYGON);
        glVertex2f(x - 0.35 * size, y);
        glVertex2f(x + 0.35 * size, y);
        glVertex2f(x + 0.35 * size, y + 0.35 * size);
        glVertex2f(x - 0.35 * size, y + 0.35 * size);
        glEnd();

        if (Line)
        {
            glPushMatrix();
            glLineWidth(1.0f);
            // Stem outline
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(x - 0.35 * size, y);
            glVertex2f(x + 0.35 * size, y);
            glVertex2f(x + 0.35 * size, y + 0.35 * size);
            glVertex2f(x - 0.35 * size, y + 0.35 * size);
            glEnd();
            glPopMatrix();

        }

        if (Line)
        {
            glColor3f(0.87, 0.83, 0.74);
            glBegin(GL_LINES);
            glVertex2f(x - 0.25 * size, y + 0.15 * size);
            glVertex2f(x - 0.25 * size, y);
            glVertex2f(x - 0.15 * size, y + 0.30 * size);
            glVertex2f(x - 0.15 * size, y + 0.15 * size);
            glVertex2f(x - 0.035 * size, y + 0.20 * size);
            glVertex2f(x - 0.035 * size, y + 0.10 * size);
            glVertex2f(x + 0.07 * size, y + 0.35 * size);
            glVertex2f(x + 0.07 * size, y + 0.25 * size);
            glVertex2f(x + 0.15 * size, y + 0.15 * size);
            glVertex2f(x + 0.15 * size, y + 0.05 * size);
            glVertex2f(x + 0.25 * size, y + 0.35 * size);
            glVertex2f(x + 0.25 * size, y + 0.30 * size);
            glVertex2f(x + 0.30 * size, y + 0.08 * size);
            glVertex2f(x + 0.30 * size, y);
            glEnd();
        }

        // Cap
        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 180; i++) {
            float rad = i * 3.14159 / 180;
            glVertex2f(x + cos(rad) * 0.5 * size, y + 0.35 * size + sin(rad) * 0.5 * size);
        }
        glEnd();

        if (Line)
        {
            glPushMatrix();
            glLineWidth(1.0f);
            // Cap outline
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            for (int i = 0; i <= 180; i++) {
                float rad = i * 3.14159 / 180;
                glVertex2f(x + cos(rad) * 0.5 * size, y + 0.35 * size + sin(rad) * 0.5 * size);
            }
            glEnd();
            glPopMatrix();
        }

        // Cap circles
        glColor3f(1.0f, 1.0f, 1.0f);
        drawCircle(x - 0.05 * size, y + 0.7 * size, 0.07 * size);
        drawCircle(x - 0.2 * size, y + 0.44 * size, 0.05 * size);
        drawCircle(x + 0.35 * size, y + 0.55 * size, 0.05 * size);
        drawCircle(x + 0.15 * size, y + 0.65 * size, 0.05 * size);
        drawCircle(x - 0.25 * size, y + 0.65 * size, 0.05 * size);
        drawCircle(x + 0.10 * size, y + 0.45 * size, 0.05 * size);
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
