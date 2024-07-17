#pragma once
#include "gl/glut.h"
#include "Color.h"
#include "Circle.h"

class Flower
{
public:
    void draw(float posX, float posY, float size, float rotation, Color petalColor) {
        glPushMatrix();
        glTranslatef(posX, posY, 0.0f);
        glScalef(size, size, 1.0f);
        // Rotate this flower
        glRotatef(rotation, 0.0f, 0.0f, 1.0f);
  
        // Draw the petals
        glColor3f(petalColor.getR(), petalColor.getG(), petalColor.getB());
        // Petal 1
        Circle::draw(0.1125f, -0.05f, 0.125f);
        // Petal 2
        Circle::draw(0.0f, -0.125f, 0.125f);
        // Petal 3
        Circle::draw(-0.1125f, -0.05f, 0.125f);
        // Petal 4
        Circle::draw(-0.075f, 0.1f, 0.125f);
        // Petal 5
        Circle::draw(0.075f, 0.1f, 0.125f);

        // Middle
        glColor3f(249, 249, 115);
        Circle::draw(0.0f, 0.0f, 0.1f);

        glPopMatrix();
    }
};
