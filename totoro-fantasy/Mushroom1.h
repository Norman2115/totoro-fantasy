#pragma once
#include <gl/glut.h>
#include <iostream>
#include "Circle.h"
#include "Colors.h"
#include "Color.h"

class Mushroom1
{
protected:
    float posX;
    float posY;
    float size;
    Color color;

    Mushroom1(float startX, float startY, float size, Color color) : posX(startX), posY(startY), size(size), color(color) {}

public:
    virtual void draw(bool Line) = 0;

    void moveInfinite(float speed, bool movingRight) {
        if (movingRight) {
            posX += speed;
            if (posX > 2100.0f) {
                posX = -180.0f;
            }
        }
        else {
            posX -= speed;
            if (posX < -180.0f) {
                posX = 2100.0f;
            }
        }
    }

    void move(float speed) {
        posX += speed;
    }

    float getPosX() const {
        return posX;
    }

    void setPosX(float x) {
        posX = x;
    }

    float getPosY() const {
        return posY;
    }

    void setPosY(float y) {
        posY = y;
    }
};

class mushroomOne : public Mushroom1
{
public:
    mushroomOne(float startX, float startY, float size, Color color) : Mushroom1(startX, startY, size, color) {}

    void draw(bool Line) override
    {
        glPushMatrix();
        glTranslatef(posX, posY, 0);
        glScalef(size, size, 1);

        // mushroom stem
        glColor3f(1, 0.97, 0.89);
        glBegin(GL_POLYGON);
        glVertex2f(-0.25, 0);
        glVertex2f(0.25, 0);
        glVertex2f(0.25, 0.5);
        glVertex2f(-0.25, 0.5);
        glEnd();

        if (Line)
        {
            glPushMatrix();
            glLineWidth(1.0f);
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(-0.25, 0);
            glVertex2f(0.25, 0);
            glVertex2f(0.25, 0.5);
            glVertex2f(-0.25, 0.5);
            glEnd();
            glPopMatrix();
        }

        if (Line)
        {
            glColor3f(0.87, 0.83, 0.74);
            glBegin(GL_LINES);
            glVertex2f(-0.09, 0.45);
            glVertex2f(-0.09, 0.25);
            glVertex2f(-0.2, 0.50);
            glVertex2f(-0.2, 0.30);
            glVertex2f(0.12, 0.25);
            glVertex2f(0.12, 0.05);
            glVertex2f(0.07, 0.50);
            glVertex2f(0.07, 0.43);
            glVertex2f(0, 0.15);
            glVertex2f(0, 0);
            glEnd();
        }

        // mushroom top
        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 180; i++) {
            float rad = i * 3.14159 / 180;
            glVertex2f(cos(rad) * 0.5, 0.5 + sin(rad) * 0.5);
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
                glVertex2f(cos(rad) * 0.5, 0.5 + sin(rad) * 0.5);
            }
            glEnd();
            glPopMatrix();
        }

        // mushroom spots
        glColor3f(1.0f, 1.0f, 1.0f);
        drawCircle(-0.35, 0.7, 0.07);
        drawCircle(-0.1, 0.85, 0.07);
        drawCircle(0.35, 0.65, 0.07);
        drawCircle(0.1, 0.75, 0.07);
        drawCircle(-0.1, 0.59, 0.07);

        glPopMatrix();
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
    mushroomTwo(float startX, float startY, float size, Color color) : Mushroom1(startX, startY, size, color) {}

    void draw(bool Line) override
    {
        glPushMatrix();
        glTranslatef(posX, posY, 0);
        glScalef(size, size, 1);

        // Stem
        glColor3f(1, 0.97, 0.89);
        glBegin(GL_POLYGON);
        glVertex2f(-0.15, 0);
        glVertex2f(0.15, 0);
        glVertex2f(0.15, 0.5);
        glVertex2f(-0.15, 0.5);
        glEnd();

        if (Line)
        {
            glPushMatrix();
            glLineWidth(1.0f);
            // Stem outline
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(-0.15, 0);
            glVertex2f(0.15, 0);
            glVertex2f(0.15, 0.5);
            glVertex2f(-0.15, 0.5);
            glEnd();
            glPopMatrix();
        }

        // Cap
        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 180; i++) {
            float rad = i * 3.14159 / 180;
            glVertex2f(cos(rad) * 0.4, 0.5 + sin(rad) * 0.55);
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
                glVertex2f(cos(rad) * 0.4, 0.5 + sin(rad) * 0.55);
            }
            glEnd();
            glPopMatrix();
        }

        // Cap circles
        glColor3f(1.0f, 1.0f, 1.0f);
        drawCircle(-0.20, 0.82, 0.05);
        drawCircle(-0.01, 0.85, 0.08);
        drawCircle(-0.30, 0.63, 0.055);
        drawCircle(0.24, 0.70, 0.09);

        glPopMatrix();
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
    mushroomThree(float startX, float startY, float size, Color color) : Mushroom1(startX, startY, size, color) { }

    void draw(bool Line) override
    {
        glPushMatrix();
        glTranslatef(posX, posY, 0);
        glScalef(size, size, 1);

        // Stem
        glColor3f(1, 0.97, 0.89);
        glBegin(GL_POLYGON);
        glVertex2f(-0.35, 0);
        glVertex2f(0.35, 0);
        glVertex2f(0.35, 0.35);
        glVertex2f(-0.35, 0.35);
        glEnd();

        if (Line)
        {
            glPushMatrix();
            glLineWidth(1.0f);
            // Stem outline
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(-0.35, 0);
            glVertex2f(0.35, 0);
            glVertex2f(0.35, 0.35);
            glVertex2f(-0.35, 0.35);
            glEnd();
            glPopMatrix();

            glColor3f(0.87, 0.83, 0.74);
            glBegin(GL_LINES);
            glVertex2f(-0.25, 0.15);
            glVertex2f(-0.25, 0);
            glVertex2f(-0.15, 0.30);
            glVertex2f(-0.15, 0.15);
            glVertex2f(-0.035, 0.20);
            glVertex2f(-0.035, 0.10);
            glVertex2f(0.07, 0.35);
            glVertex2f(0.07, 0.25);
            glVertex2f(0.15, 0.15);
            glVertex2f(0.15, 0.05);
            glVertex2f(0.25, 0.35);
            glVertex2f(0.25, 0.30);
            glVertex2f(0.30, 0.08);
            glVertex2f(0.30, 0);
            glEnd();
        }

        // Cap
        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 180; i++) {
            float rad = i * 3.14159 / 180;
            glVertex2f(cos(rad) * 0.5, 0.35 + sin(rad) * 0.5);
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
                glVertex2f(cos(rad) * 0.5, 0.35 + sin(rad) * 0.5);
            }
            glEnd();
            glPopMatrix();
        }

        // Cap circles
        glColor3f(1.0f, 1.0f, 1.0f);
        drawCircle(-0.05, 0.7, 0.07);
        drawCircle(-0.2, 0.44, 0.05);
        drawCircle(0.35, 0.55, 0.05);
        drawCircle(0.15, 0.65, 0.05);
        drawCircle(-0.25, 0.65, 0.05);
        drawCircle(0.10, 0.45, 0.05);

        glPopMatrix();
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
