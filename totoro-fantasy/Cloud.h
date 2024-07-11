#pragma once
#include <gl/glut.h>
#include <iostream>
#include "Circle.h"
#include "Colors.h"
#include "Color.h"

class Cloud
{
private:
    virtual void draw(float x, float y, float size, Color color) = 0;
};

class DayCloudOne : public Cloud {
public:
    void draw(float x, float y, float size, Color color) override {
        glColor3f(color.getR(), color.getG(), color.getB());
        float radius = 0.25 * size;
        Circle::draw(x, y + 0.7 * radius, radius);
        Circle::draw(x - 1.2 * radius, y - 0.01 * radius, radius);
        Circle::draw(x + 1.1 * radius, y + 0.4 * radius, radius);
        Circle::draw(x - 2.4 * radius, y - 0.6 * radius, radius);
        Circle::draw(x - 0.8 * radius, y - 0.6 * radius, radius);
        Circle::draw(x + 0.7 * radius, y - 0.6 * radius, radius);
        Circle::draw(x + 2.0 * radius, y - 0.6 * radius, radius);
    }
};

/*
    void draw(float x, float y) override {
        // Circle 1
        Circle::draw(x, y + 0.175, 0.25 * size);
        // Circle 2
        Circle::draw(x - 0.3, y - 0.0025, 0.25);
        // Circle 3
        Circle::draw(x + 0.275, y + 0.1, 0.25 * size);
        // Circle 4
        Circle::draw(x - 0.6 * size, y - 0.15 * size, 0.25 * size);
        // Circle 5
        Circle::draw(x - 0.2 * size, y - 0.15 * size, 0.25 * size);
        // Circle 6
        Circle::draw(x + 0.175 * size, y - 0.15 * size, 0.25 * size);
        // Circle 7
        Circle::draw(x + 0.5 * size, y - 0.15 * size, 0.25 * size);
    }
*/

class DayCloudTwo : public Cloud {
public:
    void draw(float x, float y, float size, Color color) override {
        glColor3f(color.getR(), color.getG(), color.getB());
        float radius1 = 0.25 * size;
        float radius2 = 0.275 * size;
        Circle::draw(x, y + 0.5 * radius1, radius1);
        Circle::draw(x + 1.1 * radius1, y + 0.3 * radius1, radius1);
        Circle::draw(x + 1.7 * radius1, y - 0.2 * radius1, radius1);
        Circle::draw(x + 0.4 * radius2, y - 0.5 * radius2, radius2);
        Circle::draw(x - 1.0 * radius1, y - 0.3 * radius1, radius1);
        Circle::draw(x - 2.0 * radius1, y, radius1);
        Circle::draw(x - 0.9 * radius1, y + 0.2 * radius1, radius1);
    }
};

/*
    void draw(float x, float y, float size) override {
        float radius1 = 0.25 * size;
        float radius2 = 0.275 * size;
        Circle::draw(x, y + 0.25 * radius1, radius1);
        Circle::draw(x + 0.275 * radius1, y + 0.15 * radius1, radius1);
        Circle::draw(x + 0.425 * radius1, y - 0.1 * radius1, radius1);
        Circle::draw(x + 0.1 * radius2, y - 0.25 * radius2, radius2);
        Circle::draw(x - 0.25 * radius1, y - 0.15 * radius1, radius1);
        Circle::draw(x - 0.5 * radius1, y, radius1);
        Circle::draw(x - 0.225 * radius1, y + 0.1 * radius1, radius1);
    }
*/

class DayCloudThree : public Cloud {
public:
    void draw(float x, float y, float size, Color color) override {
        glColor3f(color.getR(), color.getG(), color.getB());
        float radius1 = 0.25 * size;
        float radius2 = 0.275 * size;
        float radius3 = 0.3 * size;
        Circle::draw(x, y + 0.45 * radius2, radius2);
        Circle::draw(x + 1.3 * radius1, y + 0.5 * radius1, radius1);
        Circle::draw(x + 2.3 * radius1, y + 0.7 * radius1, radius1);
        Circle::draw(x + 3.3 * radius1, y, radius1);
        Circle::draw(x + 2.6 * radius1, y - 0.9 * radius1, radius1);
        Circle::draw(x + 1.6 * radius1, y - 1.2 * radius1, radius1);
        Circle::draw(x + 0.25 * radius3, y - 1 * radius3, radius3);
        Circle::draw(x - 1 * radius1, y - 1 * radius1, radius1);
        Circle::draw(x - 2.3 * radius1, y - 1 * radius1, radius1);
        Circle::draw(x - 3.2 * radius1, y - 0.3 * radius1, radius1);
        Circle::draw(x - 2.3 * radius1, y + 0.4 * radius1, radius1);
        Circle::draw(x - 1.2 * radius1, y + 0.8 * radius1, radius1);
    }
};
