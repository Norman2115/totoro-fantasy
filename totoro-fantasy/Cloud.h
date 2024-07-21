#pragma once
#include <gl/glut.h>
#include <iostream>
#include "Circle.h"
#include "Colors.h"
#include "Color.h"

class Cloud
{
protected:
    float posX;
    float posY;
    float size;
    Color originalColor;
    Color currentColor;

public:
    Cloud(float x, float y, float size, Color color)
        : posX(x), posY(y), size(size), originalColor(color), currentColor(color) {}

    virtual void draw() = 0;

    void setColor(Color color) {
        currentColor = color;
    }

    Color getOriginalColor() const {
        return originalColor;
    }

    void move(float speed, bool movingRight) {
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

class DayCloudOne : public Cloud {
public:
    DayCloudOne(float x, float y, float size, Color color)
        : Cloud(x, y, size, color) {}

    void draw() override {
        glPushMatrix();
        glTranslatef(posX, posY, 0.0f);
        glScalef(size, size, 1.0f);
        glColor3f(currentColor.getR(), currentColor.getG(), currentColor.getB());
        float radius = 0.25;
        Circle::draw(0.0f, 0.7f * radius, radius);
        Circle::draw(-1.2f * radius, -0.01f * radius, radius);
        Circle::draw(1.1f * radius, 0.4f * radius, radius);
        Circle::draw(-2.4f * radius, -0.6f * radius, radius);
        Circle::draw(-0.8f * radius, -0.6f * radius, radius);
        Circle::draw(0.7f * radius, -0.6f * radius, radius);
        Circle::draw(2.0f * radius, -0.6f * radius, radius);
        glPopMatrix();
    }
};

class DayCloudTwo : public Cloud {
public:
    DayCloudTwo(float x, float y, float size, Color color)
        : Cloud(x, y, size, color) {}

    void draw() override {
        glPushMatrix();
        glTranslatef(posX, posY, 0.0f);
        glScalef(size, size, 1.0f);
        glColor3f(currentColor.getR(), currentColor.getG(), currentColor.getB());
        float radius1 = 0.25;
        float radius2 = 0.275;
        Circle::draw(0.0f, 0.5f * radius1, radius1);
        Circle::draw(1.1f * radius1, 0.3f * radius1, radius1);
        Circle::draw(1.7f * radius1, -0.2f * radius1, radius1);
        Circle::draw(0.4f * radius2, -0.5f * radius2, radius2);
        Circle::draw(-1.0f * radius1, -0.3f * radius1, radius1);
        Circle::draw(-2.0f * radius1, 0.0f, radius1);
        Circle::draw(-0.9f * radius1, 0.2f * radius1, radius1);
        glPopMatrix();
    }
};

class DayCloudThree : public Cloud {
public:
    DayCloudThree(float x, float y, float size, Color color)
        : Cloud(x, y, size, color) {}

    void draw() override {
        glPushMatrix();
        glTranslatef(posX, posY, 0.0f);
        glScalef(size, size, 1.0f);
        glColor3f(currentColor.getR(), currentColor.getG(), currentColor.getB());
        float radius1 = 0.25;
        float radius2 = 0.275;
        float radius3 = 0.3;
        Circle::draw(0.0f, 0.45f * radius2, radius2);
        Circle::draw(1.3f * radius1, 0.5f * radius1, radius1);
        Circle::draw(2.3f * radius1, 0.7f * radius1, radius1);
        Circle::draw(3.3f * radius1, 0.0f, radius1);
        Circle::draw(2.6f * radius1, -0.9f * radius1, radius1);
        Circle::draw(1.6f * radius1, -1.2f * radius1, radius1);
        Circle::draw(0.25f * radius3, -1.0f * radius3, radius3);
        Circle::draw(-1.0f * radius1, -1.0f * radius1, radius1);
        Circle::draw(-2.3f * radius1, -1.0f * radius1, radius1);
        Circle::draw(-3.2f * radius1, -0.3f * radius1, radius1);
        Circle::draw(-2.3f * radius1, 0.4f * radius1, radius1);
        Circle::draw(-1.2f * radius1, 0.8f * radius1, radius1);
        glPopMatrix();
    }
};
