#pragma once
#include <gl/glut.h>
#include <iostream>
#include "Circle.h"

class Cloud
{
private:
    virtual void draw(float x, float y) = 0;
};

class DayCloudOne : public Cloud {
public:
    void draw(float x, float y) override {
        // Circle 1
        Circle::draw(x, y + 0.175, 0.25);
        // Circle 2
        Circle::draw(x - 0.3 , y - 0.0025, 0.25);
        // Circle 3
        Circle::draw(x + 0.275, y + 0.1, 0.25);
        // Circle 4
        Circle::draw(x - 0.6, y - 0.15, 0.25);
        // Circle 5
        Circle::draw(x - 0.2, y - 0.15, 0.25);
        // Circle 6
        Circle::draw(x + 0.175, y - 0.15, 0.25);
        // Circle 7
        Circle::draw(x + 0.5, y - 0.15, 0.25);
    }
};

class DayCloudTwo : public Cloud {

};

class DayCloudThree : public Cloud {

};

class DarkCloudOne : public Cloud {

};

class DarkCloudTwo : public Cloud {

};

class DarkCloudThree : public Cloud {

};