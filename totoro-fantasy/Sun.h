#pragma once
#include <gl/glut.h>
#include "Circle.h"
#include "Colors.h"
#include "Color.h"
#include "Constants.h"

class Sun {
protected:
    float posX, posY, size;
    Color color;
    float currentAngle;

    Sun(float x, float y, float size, Color color)
        : posX(x), posY(y), size(size), color(color), currentAngle(Constants::PI / 2.27) {}


public:
    virtual void draw() = 0;

    // getter and setter for all member
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

    float getSize() const {
        return size;
    }

    void setSize(float s) {
        size = s;
    }

    Color getColor() const {
        return color;
    }

    void setColor(Color c) {
        color = c;
    }

    float getCurrentAngle() const {
        return currentAngle;
    }

    void setCurrentAngle(float angle) {
        currentAngle = angle;
    }

    void moveInArc(float speed, float angleIncrement) {
        float centerX = -490.0f;
        float centerY = -2617.0f;
        float radius = 3600.0f;

        currentAngle -= angleIncrement * speed;

        posX = centerX + radius * cos(currentAngle);
        posY = centerY + radius * sin(currentAngle);
    }
};

class DaySunOne : public Sun
{
public:

    DaySunOne(float x, float y, float size, Color color)
        : Sun(x, y, size, color) {}

    void draw() override
    {
        glColor3f(color.getR(), color.getG(), color.getB());

        // Draw the sun's body
        glPushMatrix();
        glTranslatef(posX, posY, 0.0f);
        glScalef(size, size, 1.0f);
        Circle::draw(0.0f, 0.0125f * 0.5f, 0.5f);
        glPopMatrix();

        // Draw sun rays
        float longRayLength = 0.5f;
        float shortRayLength = 0.3f;
        float rayWidth = 0.1f;
        float rayDistance = 0.1f;
        int numRays = 12;

        for (int i = 0; i < numRays; i++) {
            float angle = i * (2.0f * 3.1415926f / numRays);
            float rayLength = (i % 2 == 0) ? longRayLength : shortRayLength;

            float rayStartX = posX + (0.5f * size + rayDistance * size) * cos(angle);
            float rayStartY = posY + (0.5f * size + rayDistance * size) * sin(angle);
            float rayEndX = posX + (0.5f * size + rayLength * size) * cos(angle);
            float rayEndY = posY + (0.5f * size + rayLength * size) * sin(angle);

            float perpX = -sin(angle);
            float perpY = cos(angle);

            float rayTopLeftX = rayEndX - rayWidth * size / 2 * perpX;
            float rayTopLeftY = rayEndY - rayWidth * size / 2 * perpY;
            float rayTopRightX = rayEndX + rayWidth * size / 2 * perpX;
            float rayTopRightY = rayEndY + rayWidth * size / 2 * perpY;
            float rayBottomRightX = rayStartX + rayWidth * size / 2 * perpX;
            float rayBottomRightY = rayStartY + rayWidth * size / 2 * perpY;
            float rayBottomLeftX = rayStartX - rayWidth * size / 2 * perpX;
            float rayBottomLeftY = rayStartY - rayWidth * size / 2 * perpY;

            glBegin(GL_QUADS);
            glVertex2f(rayTopLeftX, rayTopLeftY);
            glVertex2f(rayTopRightX, rayTopRightY);
            glVertex2f(rayBottomRightX, rayBottomRightY);
            glVertex2f(rayBottomLeftX, rayBottomLeftY);
            glEnd();
        }
    }
};

