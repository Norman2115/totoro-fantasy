#pragma once
#include <gl/glut.h>
#include <iostream>
#include "Colors.h"
#include "Color.h"
#include "Circle.h"

class Elements {
protected:
    float posX;
    float posY;
    float size;
    Color color;
    bool movingRight;

public:
    Elements(float posX, float posY, float size, Color color) 
        : posX(posX), posY(posY), size(size), color(color), movingRight(true) {}

    virtual void draw() = 0;

    float getPosX() const {
        return posX;
    }

    void setPosX(float posX) {
        this->posX = posX;
    }

    float getPosY() const {
        return posY;
    }

    void setPosY(float posY) {
        Elements::posY = posY;
    }

    float getSize() const {
        return size;
    }

    void setSize(float size) {
        this->size = size;
    }

    const Color getColor() const {
        return color;
    }

    void setColor(const Color& color) {
        this->color = color;
    }

    bool isMovingRight() const {
        return movingRight;
    }

    void setMovingRight(bool movingRight) {
        this->movingRight = movingRight;
    }

    void move(float speed) {
        if (movingRight) {
            posX += speed;
        }
        else {
            posX -= speed;
        }
    }

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
};

class SmallRockOne : public Elements {
public:
    SmallRockOne(float posX, float posY, float size, Color color)
        : Elements(posX, posY, size, color) {}

    void draw() override {
        glColor3f(color.getR(), color.getG(), color.getB());

        glBegin(GL_POLYGON);
        glVertex2f(posX - 0.49 * size, posY - 0.03 * size);
        glVertex2f(posX - 0.4 * size, posY + 0.2 * size);
        glVertex2f(posX - 0.29 * size, posY + 0.28 * size);
        glVertex2f(posX - 0.14 * size, posY + 0.25 * size);
        glVertex2f(posX + 0.28 * size, posY + 0.11 * size);
        glVertex2f(posX + 0.33 * size, posY + 0.03 * size);
        glVertex2f(posX + 0.2 * size, posY - 0.2 * size);
        glVertex2f(posX - 0.28 * size, posY - 0.18 * size);
        glEnd();

        glPushMatrix();
        glLineWidth(1.0f);
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_LINE_STRIP);
        glVertex2f(posX - 0.49 * size, posY - 0.03 * size);
        glVertex2f(posX - 0.4 * size, posY + 0.2 * size);
        glVertex2f(posX - 0.29 * size, posY + 0.28 * size);
        glVertex2f(posX - 0.14 * size, posY + 0.25 * size);
        glVertex2f(posX + 0.28 * size, posY + 0.11 * size);
        glVertex2f(posX + 0.33 * size, posY + 0.03 * size);
        glVertex2f(posX + 0.2 * size, posY - 0.2 * size);
        glVertex2f(posX - 0.28 * size, posY - 0.18 * size);
        glVertex2f(posX - 0.49 * size, posY - 0.03 * size);
        glEnd();
        glPopMatrix();
    }
};

class SmallRockTwo : public Elements {
public:
    SmallRockTwo(float posX, float posY, float size, Color color)
        : Elements(posX, posY, size, color) {}

    void draw() override {
        glColor3f(color.getR(), color.getG(), color.getB());

        glBegin(GL_POLYGON);
        glVertex2f(posX - 0.21 * size, posY - 0.03 * size);
        glVertex2f(posX - 0.19 * size, posY + 0.09 * size);
        glVertex2f(posX - 0.14 * size, posY + 0.14 * size);
        glVertex2f(posX - 0.06 * size, posY + 0.18 * size);
        glVertex2f(posX + 0.04 * size, posY + 0.17 * size);
        glVertex2f(posX + 0.16 * size, posY + 0.12 * size);
        glVertex2f(posX + 0.27 * size, posY + 0.06 * size);
        glVertex2f(posX + 0.28 * size, posY - 0.03 * size);
        glVertex2f(posX + 0.21 * size, posY - 0.09 * size);
        glVertex2f(posX + 0.14 * size, posY - 0.1 * size);
        glVertex2f(posX + 0.07 * size, posY - 0.11 * size);
        glVertex2f(posX - 0.13 * size, posY - 0.08 * size);
        glEnd();

        glPushMatrix();
        glLineWidth(1.0f);
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_LINE_STRIP);
        glVertex2f(posX - 0.21 * size, posY - 0.03 * size);
        glVertex2f(posX - 0.19 * size, posY + 0.09 * size);
        glVertex2f(posX - 0.14 * size, posY + 0.14 * size);
        glVertex2f(posX - 0.06 * size, posY + 0.18 * size);
        glVertex2f(posX + 0.04 * size, posY + 0.17 * size);
        glVertex2f(posX + 0.16 * size, posY + 0.12 * size);
        glVertex2f(posX + 0.27 * size, posY + 0.06 * size);
        glVertex2f(posX + 0.28 * size, posY - 0.03 * size);
        glVertex2f(posX + 0.21 * size, posY - 0.09 * size);
        glVertex2f(posX + 0.14 * size, posY - 0.1 * size);
        glVertex2f(posX + 0.07 * size, posY - 0.11 * size);
        glVertex2f(posX - 0.13 * size, posY - 0.08 * size);
        glVertex2f(posX - 0.21 * size, posY - 0.03 * size);
        glEnd();
        glPopMatrix();
    }
};

class GrassOne : public Elements {
public:
    GrassOne(float posX, float posY, float size, Color color)
        : Elements(posX, posY, size, color) {}

    void draw() override {
        glColor3f(color.getR(), color.getG(), color.getB());

        glBegin(GL_POLYGON);
        glVertex2f(posX - 0.14 * size, posY - 0.08 * size);
        glVertex2f(posX - 0.172 * size, posY + 0.11 * size);
        glVertex2f(posX - 0.116 * size, posY + 0.083 * size);
        glVertex2f(posX - 0.09 * size, posY + 0.06 * size);
        glVertex2f(posX - 0.038 * size, posY + 0.201 * size);
        glVertex2f(posX - 0.019 * size, posY + 0.133 * size);
        glVertex2f(posX - 0.006 * size, posY + 0.095 * size);
        glVertex2f(posX + 0.007 * size, posY + 0.062 * size);
        glVertex2f(posX + 0.096 * size, posY + 0.135 * size);
        glVertex2f(posX + 0.12 * size, posY + 0.148 * size);
        glVertex2f(posX + 0.112 * size, posY + 0.111 * size);
        glVertex2f(posX + 0.098 * size, posY + 0.082 * size);
        glVertex2f(posX + 0.092 * size, posY + 0.05 * size);
        glVertex2f(posX + 0.089 * size, posY + 0.023 * size);
        glVertex2f(posX + 0.086 * size, posY - 0.006 * size);
        glVertex2f(posX + 0.085 * size, posY - 0.037 * size);
        glVertex2f(posX + 0.09 * size, posY - 0.058 * size);
        glVertex2f(posX + 0.112 * size, posY - 0.08 * size);
        glEnd();

        glPushMatrix();
        glLineWidth(1.0f);
        glColor3f(0.22, 0.3, 0.17);
        glBegin(GL_LINE_STRIP);
        glVertex2f(posX - 0.14 * size, posY - 0.08 * size);
        glVertex2f(posX - 0.172 * size, posY + 0.11 * size);
        glVertex2f(posX - 0.116 * size, posY + 0.083 * size);
        glVertex2f(posX - 0.09 * size, posY + 0.06 * size);
        glVertex2f(posX - 0.038 * size, posY + 0.201 * size);
        glVertex2f(posX - 0.019 * size, posY + 0.133 * size);
        glVertex2f(posX - 0.006 * size, posY + 0.095 * size);
        glVertex2f(posX + 0.007 * size, posY + 0.062 * size);
        glVertex2f(posX + 0.096 * size, posY + 0.135 * size);
        glVertex2f(posX + 0.12 * size, posY + 0.148 * size);
        glVertex2f(posX + 0.112 * size, posY + 0.111 * size);
        glVertex2f(posX + 0.098 * size, posY + 0.082 * size);
        glVertex2f(posX + 0.092 * size, posY + 0.05 * size);
        glVertex2f(posX + 0.089 * size, posY + 0.023 * size);
        glVertex2f(posX + 0.086 * size, posY - 0.006 * size);
        glVertex2f(posX + 0.085 * size, posY - 0.037 * size);
        glVertex2f(posX + 0.09 * size, posY - 0.058 * size);
        glVertex2f(posX + 0.112 * size, posY - 0.08 * size);
        glEnd();
        glPopMatrix();
    }

    void drawWithRotation(float angle) {
        glPushMatrix();
        glColor3f(color.getR(), color.getG(), color.getB());
        glTranslatef(posX, posY, 0.0f);
        glRotatef(angle, 0.0f, 0.0f, 1.0f);
        glTranslatef(-posX, -posY, 0.0f);

        glBegin(GL_POLYGON);
        glVertex2f(posX - 0.14 * size, posY - 0.08 * size);
        glVertex2f(posX - 0.172 * size, posY + 0.11 * size);
        glVertex2f(posX - 0.116 * size, posY + 0.083 * size);
        glVertex2f(posX - 0.09 * size, posY + 0.06 * size);
        glVertex2f(posX - 0.038 * size, posY + 0.201 * size);
        glVertex2f(posX - 0.019 * size, posY + 0.133 * size);
        glVertex2f(posX - 0.006 * size, posY + 0.095 * size);
        glVertex2f(posX + 0.007 * size, posY + 0.062 * size);
        glVertex2f(posX + 0.096 * size, posY + 0.135 * size);
        glVertex2f(posX + 0.12 * size, posY + 0.148 * size);
        glVertex2f(posX + 0.112 * size, posY + 0.111 * size);
        glVertex2f(posX + 0.098 * size, posY + 0.082 * size);
        glVertex2f(posX + 0.092 * size, posY + 0.05 * size);
        glVertex2f(posX + 0.089 * size, posY + 0.023 * size);
        glVertex2f(posX + 0.086 * size, posY - 0.006 * size);
        glVertex2f(posX + 0.085 * size, posY - 0.037 * size);
        glVertex2f(posX + 0.09 * size, posY - 0.058 * size);
        glVertex2f(posX + 0.112 * size, posY - 0.08 * size);
        glEnd();

        glPushMatrix();
        glLineWidth(1.0f);
        glColor3f(0.22, 0.3, 0.17);
        glBegin(GL_LINE_STRIP);
        glVertex2f(posX - 0.14 * size, posY - 0.08 * size);
        glVertex2f(posX - 0.172 * size, posY + 0.11 * size);
        glVertex2f(posX - 0.116 * size, posY + 0.083 * size);
        glVertex2f(posX - 0.09 * size, posY + 0.06 * size);
        glVertex2f(posX - 0.038 * size, posY + 0.201 * size);
        glVertex2f(posX - 0.019 * size, posY + 0.133 * size);
        glVertex2f(posX - 0.006 * size, posY + 0.095 * size);
        glVertex2f(posX + 0.007 * size, posY + 0.062 * size);
        glVertex2f(posX + 0.096 * size, posY + 0.135 * size);
        glVertex2f(posX + 0.12 * size, posY + 0.148 * size);
        glVertex2f(posX + 0.112 * size, posY + 0.111 * size);
        glVertex2f(posX + 0.098 * size, posY + 0.082 * size);
        glVertex2f(posX + 0.092 * size, posY + 0.05 * size);
        glVertex2f(posX + 0.089 * size, posY + 0.023 * size);
        glVertex2f(posX + 0.086 * size, posY - 0.006 * size);
        glVertex2f(posX + 0.085 * size, posY - 0.037 * size);
        glVertex2f(posX + 0.09 * size, posY - 0.058 * size);
        glVertex2f(posX + 0.112 * size, posY - 0.08 * size);
        glEnd();
        glPopMatrix();
        glPopMatrix();
    }
};

class GrassTwo : public Elements {
public:
    GrassTwo(float posX, float posY, float size, Color color)
        : Elements(posX, posY, size, color) {}


    void draw() override {
        glColor3f(color.getR(), color.getG(), color.getB());

        glBegin(GL_POLYGON);
        glVertex2f(posX - 0.4 * size, posY - 0.1 * size);
        glVertex2f(posX - 0.433 * size, posY + 0.1 * size);
        glVertex2f(posX - 0.336 * size, posY + 0.08 * size);
        glVertex2f(posX - 0.27 * size, posY + 0.0165 * size);
        glVertex2f(posX - 0.11 * size, posY + 0.19 * size);
        glVertex2f(posX + 0.04 * size, posY + 0.27 * size);
        glVertex2f(posX + 0.02 * size, posY + 0.22 * size);
        glVertex2f(posX + 0 * size, posY + 0.1 * size);
        glVertex2f(posX + 0.008 * size, posY + 0.034 * size);
        glVertex2f(posX + 0.05 * size, posY + 0.047 * size);
        glVertex2f(posX + 0.122 * size, posY + 0.08 * size);
        glVertex2f(posX + 0.109 * size, posY + 0.038 * size);
        glVertex2f(posX + 0.24 * size, posY + 0.07 * size);
        glVertex2f(posX + 0.345 * size, posY + 0.114 * size);
        glVertex2f(posX + 0.3 * size, posY + 0 * size);
        glVertex2f(posX + 0.28 * size, posY - 0.06 * size);
        glVertex2f(posX + 0.3 * size, posY - 0.1 * size);
        glEnd();

        glPushMatrix();
        glLineWidth(1.0f);
        glColor3f(0.22, 0.3, 0.17);
        glBegin(GL_LINE_STRIP);
        glVertex2f(posX - 0.4 * size, posY - 0.1 * size);
        glVertex2f(posX - 0.433 * size, posY + 0.1 * size);
        glVertex2f(posX - 0.336 * size, posY + 0.08 * size);
        glVertex2f(posX - 0.27 * size, posY + 0.0165 * size);
        glVertex2f(posX - 0.11 * size, posY + 0.19 * size);
        glVertex2f(posX + 0.04 * size, posY + 0.27 * size);
        glVertex2f(posX + 0.02 * size, posY + 0.22 * size);
        glVertex2f(posX + 0 * size, posY + 0.1 * size);
        glVertex2f(posX + 0.008 * size, posY + 0.034 * size);
        glVertex2f(posX + 0.05 * size, posY + 0.047 * size);
        glVertex2f(posX + 0.122 * size, posY + 0.08 * size);
        glVertex2f(posX + 0.109 * size, posY + 0.038 * size);
        glVertex2f(posX + 0.24 * size, posY + 0.07 * size);
        glVertex2f(posX + 0.345 * size, posY + 0.114 * size);
        glVertex2f(posX + 0.3 * size, posY + 0 * size);
        glVertex2f(posX + 0.28 * size, posY - 0.06 * size);
        glVertex2f(posX + 0.3 * size, posY - 0.1 * size);
        glEnd();
        glPopMatrix();
    }

    void drawWithRotation(float angle) {
        glPushMatrix();
        glColor3f(color.getR(), color.getG(), color.getB());
        glTranslatef(posX, posY, 0.0f);
        glRotatef(angle, 0.0f, 0.0f, 1.0f);
        glTranslatef(-posX, -posY, 0.0f);

        glBegin(GL_POLYGON);
        glVertex2f(posX - 0.4 * size, posY - 0.1 * size);
        glVertex2f(posX - 0.433 * size, posY + 0.1 * size);
        glVertex2f(posX - 0.336 * size, posY + 0.08 * size);
        glVertex2f(posX - 0.27 * size, posY + 0.0165 * size);
        glVertex2f(posX - 0.11 * size, posY + 0.19 * size);
        glVertex2f(posX + 0.04 * size, posY + 0.27 * size);
        glVertex2f(posX + 0.02 * size, posY + 0.22 * size);
        glVertex2f(posX + 0 * size, posY + 0.1 * size);
        glVertex2f(posX + 0.008 * size, posY + 0.034 * size);
        glVertex2f(posX + 0.05 * size, posY + 0.047 * size);
        glVertex2f(posX + 0.122 * size, posY + 0.08 * size);
        glVertex2f(posX + 0.109 * size, posY + 0.038 * size);
        glVertex2f(posX + 0.24 * size, posY + 0.07 * size);
        glVertex2f(posX + 0.345 * size, posY + 0.114 * size);
        glVertex2f(posX + 0.3 * size, posY + 0 * size);
        glVertex2f(posX + 0.28 * size, posY - 0.06 * size);
        glVertex2f(posX + 0.3 * size, posY - 0.1 * size);
        glEnd();

        glPushMatrix();
        glLineWidth(1.0f);
        glColor3f(0.22, 0.3, 0.17);
        glBegin(GL_LINE_STRIP);
        glVertex2f(posX - 0.4 * size, posY - 0.1 * size);
        glVertex2f(posX - 0.433 * size, posY + 0.1 * size);
        glVertex2f(posX - 0.336 * size, posY + 0.08 * size);
        glVertex2f(posX - 0.27 * size, posY + 0.0165 * size);
        glVertex2f(posX - 0.11 * size, posY + 0.19 * size);
        glVertex2f(posX + 0.04 * size, posY + 0.27 * size);
        glVertex2f(posX + 0.02 * size, posY + 0.22 * size);
        glVertex2f(posX + 0 * size, posY + 0.1 * size);
        glVertex2f(posX + 0.008 * size, posY + 0.034 * size);
        glVertex2f(posX + 0.05 * size, posY + 0.047 * size);
        glVertex2f(posX + 0.122 * size, posY + 0.08 * size);
        glVertex2f(posX + 0.109 * size, posY + 0.038 * size);
        glVertex2f(posX + 0.24 * size, posY + 0.07 * size);
        glVertex2f(posX + 0.345 * size, posY + 0.114 * size);
        glVertex2f(posX + 0.3 * size, posY + 0 * size);
        glVertex2f(posX + 0.28 * size, posY - 0.06 * size);
        glVertex2f(posX + 0.3 * size, posY - 0.1 * size);
        glEnd();
        glPopMatrix();
        glPopMatrix();
    }
};
class GrassLineOne : public Elements {
public:
    GrassLineOne(float posX, float posY, float size, Color color)
        : Elements(posX, posY, size, color) {}

    void draw() override {
        glColor3f(color.getR(), color.getG(), color.getB());

        glPushMatrix();
        glLineWidth(1.0f);
        glColor3f(0.22, 0.3, 0.17);
        glBegin(GL_LINE_STRIP);
        glVertex2f(posX - 0.14 * size, posY - 0.08 * size);
        glVertex2f(posX - 0.172 * size, posY + 0.11 * size);
        glVertex2f(posX - 0.116 * size, posY + 0.083 * size);
        glVertex2f(posX - 0.09 * size, posY + 0.06 * size);
        glVertex2f(posX - 0.038 * size, posY + 0.201 * size);
        glVertex2f(posX - 0.019 * size, posY + 0.133 * size);
        glVertex2f(posX - 0.006 * size, posY + 0.095 * size);
        glVertex2f(posX + 0.007 * size, posY + 0.062 * size);
        glVertex2f(posX + 0.096 * size, posY + 0.135 * size);
        glVertex2f(posX + 0.12 * size, posY + 0.148 * size);
        glVertex2f(posX + 0.112 * size, posY + 0.111 * size);
        glVertex2f(posX + 0.098 * size, posY + 0.082 * size);
        glVertex2f(posX + 0.092 * size, posY + 0.05 * size);
        glVertex2f(posX + 0.089 * size, posY + 0.023 * size);
        glVertex2f(posX + 0.086 * size, posY - 0.006 * size);
        glVertex2f(posX + 0.085 * size, posY - 0.037 * size);
        glVertex2f(posX + 0.09 * size, posY - 0.058 * size);
        glVertex2f(posX + 0.112 * size, posY - 0.08 * size);
        glEnd();
        glPopMatrix();
    }
};

class GrassLineTwo : public Elements {
public:

    GrassLineTwo(float posX, float posY, float size, Color color)
        : Elements(posX, posY, size, color) {}

    void draw() override {
        glColor3f(color.getR(), color.getG(), color.getB());

        glPushMatrix();
        glLineWidth(1.0f);
        glColor3f(0.22, 0.3, 0.17);
        glBegin(GL_LINE_STRIP);
        glVertex2f(posX - 0.4 * size, posY - 0.1 * size);
        glVertex2f(posX - 0.433 * size, posY + 0.1 * size);
        glVertex2f(posX - 0.336 * size, posY + 0.08 * size);
        glVertex2f(posX - 0.27 * size, posY + 0.0165 * size);
        glVertex2f(posX - 0.11 * size, posY + 0.19 * size);
        glVertex2f(posX + 0.04 * size, posY + 0.27 * size);
        glVertex2f(posX + 0.02 * size, posY + 0.22 * size);
        glVertex2f(posX + 0 * size, posY + 0.1 * size);
        glVertex2f(posX + 0.008 * size, posY + 0.034 * size);
        glVertex2f(posX + 0.05 * size, posY + 0.047 * size);
        glVertex2f(posX + 0.122 * size, posY + 0.08 * size);
        glVertex2f(posX + 0.109 * size, posY + 0.038 * size);
        glVertex2f(posX + 0.24 * size, posY + 0.07 * size);
        glVertex2f(posX + 0.345 * size, posY + 0.114 * size);
        glVertex2f(posX + 0.3 * size, posY + 0 * size);
        glVertex2f(posX + 0.28 * size, posY - 0.06 * size);
        glVertex2f(posX + 0.3 * size, posY - 0.1 * size);
        glEnd();
        glPopMatrix();
    }
};