#pragma once
#include "gl/glut.h"
#include "Color.h"
#include "Circle.h"

class Flower
{
protected:
    float posX;
    float posY;
    float size;
    Color petalColor;

public:
    Flower(float startX, float startY, float size, Color petalColor) : posX(startX), posY(startY), size(size), petalColor(petalColor) {}

    void draw(float rotation) {
        glPushMatrix();
        glTranslatef(posX, posY, 0.0f);
        glScalef(size, size, 1.0f);
        // Rotate this flower
        glRotatef(rotation, 0.0f, 0.0f, 1.0f);
  
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

    // setter and getter for each attribute
    void setPosX(float posX) {
        this->posX = posX;
    }

    float getPosX() const {
        return posX;
    }

    void setPosY(float posY) {
        this->posY = posY;
    }

    float getPosY() const {
        return posY;
    }

    void setSize(float size) {
        this->size = size;
    }

    float getSize() const {
        return size;
    }

    void setColor(Color petalColor) {
        this->petalColor = petalColor;
    }

    Color getPetalColor() const {
        return petalColor;
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
