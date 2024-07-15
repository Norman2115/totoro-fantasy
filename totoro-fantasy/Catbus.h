#pragma once
#include <gl/glut.h>
#include "Ellipse.h"

class Catbus
{
private:
    float posX;
    float posY;
    float busSize;
    int currentFrame;
    bool movingRight;

public:
    void draw() const {
        float rotationAngles[6] = { 280, 330, 10, 40, 40, 30 };
        float rotationAngles2[6] = { 30, 5, 350, 305, 310, 50 };
        float rotationAngles3[6] = { 45, 40, 20, 355, 305, 350 };
        float rotationAngles4[6] = { 55, 45, 25, 0, 340, 320 };
        float rotationAngles5[6] = { 15, 25, 50, 35, 15, 350 };
        float rotationAngles6[6] = { 310, 340, 30, 30, 10, 0 };

        if (currentFrame == 0) {
            glPushMatrix();
            glColor3ub(255, 0, 0);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles[0], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.25f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(0, 255, 0);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles[1], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.125f, 0.0f, 0.0625f, 0.11f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(0, 0, 255);
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(rotationAngles[2], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.0f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.0f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(255, 255, 0);
            glTranslatef(0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles[3], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.125f, 0.0f, 0.0625f, 0.115f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(0, 255, 255);
            glTranslatef(0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles[4], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.25f, 0.0f, 0.0625f, 0.115f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(255, 0, 255);
            glTranslatef(0.325f, 0.0f, 0.0f);
            glRotatef(rotationAngles[5], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.325f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.325f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();
        }
        else if (currentFrame == 1) {
            glPushMatrix();
            glColor3ub(255, 0, 0);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles2[0], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.25f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(0, 255, 0);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles2[1], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.125f, 0.0f, 0.0625f, 0.11f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(0, 0, 255);
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(rotationAngles2[2], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.0f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.0f, 0.0f, 0.0625f, 0.12f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(255, 255, 0);
            glTranslatef(0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles2[3], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.125f, 0.0f, 0.0625f, 0.115f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(0, 255, 255);
            glTranslatef(0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles2[4], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.25f, 0.0f, 0.0625f, 0.1f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(255, 0, 255);
            glTranslatef(0.325f, 0.0f, 0.0f);
            glRotatef(rotationAngles2[5], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.325f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.325f, 0.0f, 0.0625f, 0.1f, 100);
            glPopMatrix();
        }
        else if (currentFrame == 2) {
            glPushMatrix();
            glColor3ub(255, 0, 0);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles3[0], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.25f, 0.0f, 0.0625f, 0.15f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(0, 255, 0);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles3[1], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.125f, 0.0f, 0.0625f, 0.14f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(0, 0, 255);
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(rotationAngles3[2], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.0f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.0f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(255, 255, 0);
            glTranslatef(0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles3[3], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.125f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(0, 255, 255);
            glTranslatef(0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles3[4], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.25f, 0.0f, 0.0625f, 0.115f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(255, 0, 255);
            glTranslatef(0.325f, 0.0f, 0.0f);
            glRotatef(rotationAngles3[5], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.325f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.325f, 0.0f, 0.0625f, 0.11f, 100);
            glPopMatrix();
        }
        else if (currentFrame == 3) {
            glPushMatrix();
            glColor3ub(255, 0, 0);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles4[0], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.25f, 0.0f, 0.0625f, 0.17f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(0, 255, 0);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles4[1], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.125f, 0.0f, 0.0625f, 0.15f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(0, 0, 255);
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(rotationAngles4[2], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.0f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.0f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(255, 255, 0);
            glTranslatef(0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles4[3], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.125f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(0, 255, 255);
            glTranslatef(0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles4[4], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.25f, 0.0f, 0.0625f, 0.13f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(255, 0, 255);
            glTranslatef(0.325f, 0.0f, 0.0f);
            glRotatef(rotationAngles4[5], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.325f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.325f, 0.0f, 0.0625f, 0.1f, 100);
            glPopMatrix();
        }
        else if (currentFrame == 4) {
            glPushMatrix();
            glColor3ub(255, 0, 0);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles5[0], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.25f, 0.0f, 0.0625f, 0.11f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(0, 255, 0);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles5[1], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.125f, 0.0f, 0.0625f, 0.12f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(0, 0, 255);
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(rotationAngles5[2], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.0f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.0f, 0.0f, 0.0625f, 0.14f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(255, 255, 0);
            glTranslatef(0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles5[3], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.125f, 0.0f, 0.0625f, 0.115f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(0, 255, 255);
            glTranslatef(0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles5[4], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.25f, 0.0f, 0.0625f, 0.12f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(255, 0, 255);
            glTranslatef(0.325f, 0.0f, 0.0f);
            glRotatef(rotationAngles5[5], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.325f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.325f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();
        }
        else if (currentFrame == 5) {
            glPushMatrix();
            glColor3ub(255, 0, 0);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles6[0], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.25f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(0, 255, 0);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles6[1], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.125f, 0.0f, 0.0625f, 0.12f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(0, 0, 255);
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(rotationAngles6[2], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.0f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.0f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(255, 255, 0);
            glTranslatef(0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles6[3], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.125f, 0.0f, 0.0625f, 0.12f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(0, 255, 255);
            glTranslatef(0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles6[4], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.25f, 0.0f, 0.0625f, 0.12f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor3ub(255, 0, 255);
            glTranslatef(0.325f, 0.0f, 0.0f);
            glRotatef(rotationAngles6[5], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.325f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.325f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();
        }
    }

    void move() {

    }

    void updateFrame() {
        currentFrame = (currentFrame + 1) % 6;
    }
};