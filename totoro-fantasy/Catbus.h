#pragma once
#include <gl/glut.h>
#include "Ellipse.h"
#include "Circle.h"
#include "Constants.h"

class Catbus
{
private:
    float posX;
    float posY;
    float busSize;
    float opacity;
    int currentFrame;
    bool movingRight;
    bool isDay;
    bool isBoarded;
    float currentAngle;
    bool isLightOn;

    void drawBody() const {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        // Ear - Inner
        glColor4ub(244, 243, 224, opacity * 255);
        glBegin(GL_POLYGON);
        glVertex2f(-0.4f, 0.2f);
        glVertex2f(-0.4125f, 0.3f);
        glVertex2f(-0.45f, 0.21f);
        glEnd();
        // Ear - Outer
        glColor4ub(193, 129, 59, opacity * 255);
        glBegin(GL_POLYGON);
        glVertex2f(-0.45f, 0.21f);
        glVertex2f(-0.4125f, 0.3f);
        glVertex2f(-0.47, 0.21f);
        glEnd();

        // Tail
        glColor4ub(193, 129, 59, opacity * 255);
        Circle::draw(0.6625, 0.0625, 0.0625);
        glColor4ub(237, 182, 38, opacity * 255);
        glBegin(GL_POLYGON);
        glVertex2f(0.475f, -0.025f);
        glVertex2f(0.475f, 0.075f);
        glVertex2f(0.65f, 0.125f);
        glVertex2f(0.675f, 0.0f);
        glEnd();
        glColor4ub(193, 129, 59, opacity * 255);
        // Tail - Lower Stripe
        glBegin(GL_POLYGON);
        glVertex2f(0.5125f, 0.086f);
        glVertex2f(0.55f, 0.097f);
        glVertex2f(0.575f, -0.0125f);
        glVertex2f(0.532f, -0.02f);
        glEnd();

        // Body
        glColor4ub(237, 182, 38, opacity * 255);
        glBegin(GL_QUADS);
        glVertex2f(-0.375f, -0.05f);
        glVertex2f(0.475f, -0.05f);
        glVertex2f(0.475f, 0.375f);
        glVertex2f(-0.375f, 0.375f);
        glEnd();
        // Body Outline
        glColor4ub(193, 129, 59, opacity * 255);
        glBegin(GL_LINE_LOOP);
        glVertex2f(-0.375f, -0.05f);
        glVertex2f(0.475f, -0.05f);
        glVertex2f(0.475f, 0.375f);
        glVertex2f(-0.375f, 0.375f);
        glEnd();
        // Body - Top Stripe
        glColor4ub(193, 129, 59, opacity * 255);
        glBegin(GL_QUADS);
        glVertex2f(-0.375f, 0.35f);
        glVertex2f(0.475f, 0.35f);
        glVertex2f(0.475f, 0.375f);
        glVertex2f(-0.375f, 0.375f);
        glEnd();
        // Body - Middle Stripe
        glColor4ub(193, 129, 59, opacity * 255);
        glBegin(GL_QUADS);
        glVertex2f(-0.375f, 0.1f);
        glVertex2f(0.475f, 0.1f);
        glVertex2f(0.475f, 0.15f);
        glVertex2f(-0.375f, 0.15f);
        glEnd();

        // Head
        glColor4ub(237, 182, 38, opacity * 255);
        Circle::draw(-0.45f, 0.075f, 0.145f);

        // Eye
        glColor4ub(244, 234, 15, opacity * 255);
        Circle::draw(-0.515f, 0.125f, 0.0325);
        // Lens
        glColor4ub(0, 0, 0, opacity * 255);
        Ellipse::drawEllipse(-0.525f, 0.15f, 0.011f, 0.025f, 80);
        // Light
        if (isLightOn && !isDay) {
            glBegin(GL_POLYGON);
            glColor4ub(255, 253, 175, opacity * 50);
            glVertex2f(-0.515f, 0.155);
            glVertex2f(-0.515f, 0.096);
            glVertex2f(-0.7f, -0.1f);    // Further down right
            glVertex2f(-0.9f, -0.1f);    // Further down right
            glEnd();
        }

        // Mouth
        glColor4ub(255, 255, 255, opacity * 255);
        glBegin(GL_POLYGON);
        glVertex2f(-0.55f, -0.025f);
        glVertex2f(-0.45f, 0.075f);
        glVertex2f(-0.593f, 0.05f);
        glEnd();

        // Teeth
        glColor4ub(182, 167, 149, opacity * 255);
        glBegin(GL_LINES);
        glVertex2f(-0.5f, 0.065f);
        glVertex2f(-0.49f, 0.0365f);
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(-0.55f, 0.055f);
        glVertex2f(-0.525f, 0.001f);
        glEnd();

        // Whiskers
        glPushAttrib(GL_CURRENT_BIT | GL_LINE_BIT);
        glLineWidth(2);
        glColor4ub(0, 0, 0, opacity * 255);
        glBegin(GL_LINES);
        glVertex2f(-0.475, 0.1f);
        glVertex2f(-0.4125f, 0.125f);
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(-0.48, 0.105f);
        glVertex2f(-0.4125f, 0.1625f);
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(-0.485, 0.11f);
        glVertex2f(-0.45f, 0.175f);
        glEnd();
        glPopAttrib();

        // Face Stripe
        glColor4ub(193, 129, 59, opacity * 255);
        glPushMatrix();
        glTranslatef(-0.325f, 0.125f, 0.0f);
        glRotatef(270, 0.0f, 0.0f, 1.0f);
        glTranslatef(0.325f, -0.125f, 0.0f);
        Ellipse::drawEllipse(-0.325f, 0.125f, 0.0125f, 0.0375f, 100);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-0.325f, 0.075f, 0.0f);
        glRotatef(270, 0.0f, 0.0f, 1.0f);
        glTranslatef(0.325f, -0.075f, 0.0f);
        Ellipse::drawEllipse(-0.325f, 0.075f, 0.0125f, 0.0375f, 100);
        glPopMatrix();

        // Windows
        if (isDay) {
            glColor4f(0.7, 0.87, 1, opacity);
        }
        else {
            glColor4ub(0, 0, 0, opacity * 255);
        }
        // Window 1
        glBegin(GL_POLYGON);
        glVertex2f(-0.3f, 0.2f);
        glVertex2f(-0.35f, 0.2f);
        glVertex2f(-0.35f, 0.3f);
        glVertex2f(-0.3f, 0.3f);
        glEnd();
        // Window 2
        glBegin(GL_POLYGON);
        glVertex2f(-0.275f, 0.2f);
        glVertex2f(-0.1875f, 0.2f);
        glVertex2f(-0.1875f, 0.3f);
        glVertex2f(-0.275f, 0.3f);
        glEnd();
        // Window 3
        glBegin(GL_POLYGON);
        glVertex2f(-0.1625, 0.2f);
        glVertex2f(-0.075f, 0.2f);
        glVertex2f(-0.075f, 0.3f);
        glVertex2f(-0.1625f, 0.3f);
        glEnd();
        // Window 4
        glBegin(GL_POLYGON);
        glVertex2f(-0.05f, 0.2f);
        glVertex2f(0.0375f, 0.2f);
        glVertex2f(0.0375f, 0.3f);
        glVertex2f(-0.05f, 0.3f);
        glEnd();
        // Window 5
        glBegin(GL_POLYGON);
        glVertex2f(0.0625f, 0.2f);
        glVertex2f(0.15f, 0.2f);
        glVertex2f(0.15f, 0.3f);
        glVertex2f(0.0625f, 0.3f);
        glEnd();
        // Window 6
        glBegin(GL_POLYGON);
        glVertex2f(0.175f, 0.2f);
        glVertex2f(0.2625f, 0.2f);
        glVertex2f(0.2625f, 0.3f);
        glVertex2f(0.175f, 0.3f);
        glEnd();
        // Window 7
        glBegin(GL_POLYGON);
        glVertex2f(0.2875f, 0.2f);
        glVertex2f(0.3625f, 0.2f);
        glVertex2f(0.3625f, 0.3f);
        glVertex2f(0.2875f, 0.3f);
        glEnd();
        // Window 8
        glBegin(GL_POLYGON);
        glVertex2f(0.3875f, 0.2f);
        glVertex2f(0.45f, 0.2f);
        glVertex2f(0.45f, 0.3f);
        glVertex2f(0.3875f, 0.3f);
        glEnd();

        // Windows - Frame within Frame
        if (isDay) {
            glColor4ub(193, 129, 59, opacity * 255);
        }
        else {
            glColor4ub(255, 253, 141, opacity * 255);
        }
        // Window 1
        glBegin(GL_POLYGON);
        glVertex2f(-0.35f, 0.2f);
        glVertex2f(-0.35f, 0.3f);
        glVertex2f(-0.34f, 0.3f);
        glVertex2f(-0.34f, 0.2f);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(-0.3f, 0.3f);
        glVertex2f(-0.3f, 0.29f);
        glVertex2f(-0.35f, 0.29f);
        glVertex2f(-0.35f, 0.3f);
        glEnd();
        // Window 2
        glBegin(GL_POLYGON);
        glVertex2f(-0.275f, 0.2f);
        glVertex2f(-0.275f, 0.3f);
        glVertex2f(-0.26f, 0.3f);
        glVertex2f(-0.26f, 0.2f);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(-0.1875f, 0.3f);
        glVertex2f(-0.1875f, 0.29f);
        glVertex2f(-0.275f, 0.29f);
        glVertex2f(-0.275f, 0.3f);
        glEnd();
        // Window 3
        glBegin(GL_POLYGON);
        glVertex2f(-0.1625f, 0.2f);
        glVertex2f(-0.1625f, 0.3f);
        glVertex2f(-0.15f, 0.3f);
        glVertex2f(-0.15f, 0.2f);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(-0.075f, 0.3f);
        glVertex2f(-0.075f, 0.29f);
        glVertex2f(-0.15f, 0.29f);
        glVertex2f(-0.15f, 0.3f);
        glEnd();
        // Window 4
        glBegin(GL_POLYGON);
        glVertex2f(-0.05f, 0.2f);
        glVertex2f(-0.05f, 0.3f);
        glVertex2f(-0.0375f, 0.3f);
        glVertex2f(-0.0375f, 0.2f);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(0.0375f, 0.3f);
        glVertex2f(0.0375f, 0.29f);
        glVertex2f(-0.05f, 0.29f);
        glVertex2f(-0.05f, 0.3f);
        glEnd();
        // Window 5
        glBegin(GL_POLYGON);
        glVertex2f(0.0625f, 0.2f);
        glVertex2f(0.0625f, 0.3f);
        glVertex2f(0.075f, 0.3f);
        glVertex2f(0.075f, 0.2f);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(0.15f, 0.3f);
        glVertex2f(0.15f, 0.29f);
        glVertex2f(0.0625f, 0.29f);
        glVertex2f(0.0625f, 0.3f);
        glEnd();
        // Window 6
        glBegin(GL_POLYGON);
        glVertex2f(0.175f, 0.2f);
        glVertex2f(0.175f, 0.3f);
        glVertex2f(0.1875f, 0.3f);
        glVertex2f(0.1875f, 0.2f);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(0.2625f, 0.3f);
        glVertex2f(0.2625f, 0.29f);
        glVertex2f(0.175f, 0.29f);
        glVertex2f(0.175f, 0.3f);
        glEnd();
        // Window 7
        glBegin(GL_POLYGON);
        glVertex2f(0.2875f, 0.2f);
        glVertex2f(0.2875f, 0.3f);
        glVertex2f(0.3f, 0.3f);
        glVertex2f(0.3f, 0.2f);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(0.3625f, 0.3f);
        glVertex2f(0.3625f, 0.29f);
        glVertex2f(0.2875f, 0.29f);
        glVertex2f(0.2875f, 0.3f);
        glEnd();
        // Window 8
        glBegin(GL_POLYGON);
        glVertex2f(0.3875f, 0.2f);
        glVertex2f(0.3875f, 0.3f);
        glVertex2f(0.4f, 0.3f);
        glVertex2f(0.4f, 0.2f);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(0.45f, 0.3f);
        glVertex2f(0.45f, 0.29f);
        glVertex2f(0.3875f, 0.29f);
        glVertex2f(0.3875f, 0.3f);
        glEnd();

        if (isBoarded) {
            glColor4f(Colors::CHARACTER_SKIN.getR(), Colors::CHARACTER_SKIN.getG(), Colors::CHARACTER_SKIN.getB(), opacity);
            Circle::draw(0.1063f, 0.2385f, 0.038f);
        }
    }

public:
    Catbus(float startX, float startY, float size, bool isDay)
        : posX(startX), posY(startY), busSize(size), opacity(1.0f), currentFrame(0), movingRight(false), isDay(isDay), isBoarded(false), currentAngle(Constants::PI / 3), isLightOn(isDay ? false : true) {
    }

    void drawStandstillView() {
        glPushMatrix();
        glTranslatef(posX, posY, 0.0f);
        if (!movingRight) {
            glScalef(busSize, busSize, 1.0f);
        }
        else {
            glScalef(-busSize, busSize, 1.0f);
        }

        drawBody();

        glPushMatrix();
        glColor4ub(237, 182, 38, opacity * 255);
        Ellipse::drawEllipse(-0.25f, 0.0f, 0.0625f, 0.12f, 100);
        glColor4ub(193, 129, 59, opacity * 255);
        Ellipse::drawEllipseBorder(-0.25f, 0.0f, 0.0625f, 0.12f, 100);
        glPopMatrix();
        // Strip 1
        glPushMatrix();
        glColor4ub(193, 129, 59, opacity * 255);
        glTranslatef(-0.15f, -0.08f, 0.0f);
        glRotatef(90, 0.0f, 0.0f, 1.0f);
        glTranslatef(0.15f, 0.08f, 0.0f);
        Ellipse::drawEllipse(-0.15f, 0.08f, 0.02f, 0.0375f, 100);
        glPopMatrix();
        // Stripe 2
        glPushMatrix();
        glColor4ub(193, 129, 59, opacity * 255);
        glTranslatef(-0.31f, -0.15f, 0.0f);
        glRotatef(90, 0.0f, 0.0f, 1.0f);
        glTranslatef(0.31f, 0.15f, 0.0f);
        Ellipse::drawEllipse(-0.31f, -0.15f, 0.02f, 0.0375f, 100);
        glPopMatrix();

        glPushMatrix();
        glColor4ub(237, 182, 38, opacity * 255);
        Ellipse::drawEllipse(-0.125f, 0.0f, 0.0625f, 0.12f, 100);
        glColor4ub(193, 129, 59, opacity * 255);
        Ellipse::drawEllipseBorder(-0.125f, 0.0f, 0.0625f, 0.12f, 100);
        glPopMatrix();
        // Stripe
        glPushMatrix();
        glColor4ub(193, 129, 59, opacity * 255);
        glTranslatef(-0.187f, -0.115f, 0.0f);
        glRotatef(90, 0.0f, 0.0f, 1.0f);
        glTranslatef(0.187f, 0.115f, 0.0f);
        Ellipse::drawEllipse(-0.187f, -0.115f, 0.02f, 0.0375f, 100);
        glPopMatrix();

        glPushMatrix();
        glColor4ub(237, 182, 38, opacity * 255);
        Ellipse::drawEllipse(0.0f, 0.0f, 0.0625f, 0.12f, 100);
        glColor4ub(193, 129, 59, opacity * 255);
        Ellipse::drawEllipseBorder(0.0f, 0.0f, 0.0625f, 0.12f, 100);
        glPopMatrix();
        // Stripe
        glPushMatrix();
        glColor4ub(193, 129, 59, opacity * 255);
        glTranslatef(-0.062f, -0.115f, 0.0f);
        glRotatef(90, 0.0f, 0.0f, 1.0f);
        glTranslatef(0.062f, 0.115f, 0.0f);
        Ellipse::drawEllipse(-0.062f, -0.115f, 0.02f, 0.0375f, 100);
        glPopMatrix();

        glPushMatrix();
        glColor4ub(237, 182, 38, opacity * 255);
        Ellipse::drawEllipse(0.125f, 0.0f, 0.0625f, 0.12f, 100);
        glColor4ub(193, 129, 59, opacity * 255);
        Ellipse::drawEllipseBorder(0.125f, 0.0f, 0.0625f, 0.12f, 100);
        glPopMatrix();
        // Stripe
        glPushMatrix();
        glColor4ub(193, 129, 59, opacity * 255);
        glTranslatef(0.062f, -0.115f, 0.0f);
        glRotatef(90, 0.0f, 0.0f, 1.0f);
        glTranslatef(-0.062f, 0.115f, 0.0f);
        Ellipse::drawEllipse(0.062f, -0.115f, 0.02f, 0.0375f, 100);
        glPopMatrix();

        glPushMatrix();
        glColor4ub(237, 182, 38, opacity * 255);
        Ellipse::drawEllipse(0.25f, 0.0f, 0.0625f, 0.12f, 100);
        glColor4ub(193, 129, 59, opacity * 255);
        Ellipse::drawEllipseBorder(0.25f, 0.0f, 0.0625f, 0.12f, 100);
        glPopMatrix();
        // Stripe
        glPushMatrix();
        glColor4ub(193, 129, 59, opacity * 255);
        glTranslatef(0.188f, -0.115f, 0.0f);
        glRotatef(90, 0.0f, 0.0f, 1.0f);
        glTranslatef(-0.188f, 0.115f, 0.0f);
        Ellipse::drawEllipse(0.188f, -0.115f, 0.02f, 0.0375f, 100);
        glPopMatrix();

        glPushMatrix();
        glColor4ub(237, 182, 38, opacity * 255);
        Ellipse::drawEllipse(0.325f, 0.0f, 0.0625f, 0.12f, 100);
        glColor4ub(193, 129, 59, opacity * 255);
        Ellipse::drawEllipseBorder(0.325f, 0.0f, 0.0625f, 0.12f, 100);
        glPopMatrix();
        // Stripe
        glPushMatrix();
        glColor4ub(193, 129, 59, opacity * 255);
        glTranslatef(0.262f, -0.115f, 0.0f);
        glRotatef(90, 0.0f, 0.0f, 1.0f);
        glTranslatef(-0.262f, 0.115f, 0.0f);
        Ellipse::drawEllipse(0.262f, -0.115f, 0.02f, 0.0375f, 100);
        glPopMatrix();

        glPopMatrix();
        glDisable(GL_BLEND);
    }

    void drawRunningView() {
        glPushMatrix();
        glTranslatef(posX, posY, 0.0f);
        if (!movingRight) {
            glScalef(busSize, busSize, 1.0f);
        }
        else {
            glScalef(-busSize, busSize, 1.0f);
        }

        drawBody();

        float rotationAngles[6] = { 280, 330, 10, 40, 40, 30 };
        float rotationAngles2[6] = { 30, 5, 350, 305, 310, 50 };
        float rotationAngles3[6] = { 45, 40, 20, 355, 305, 350 };
        float rotationAngles4[6] = { 55, 45, 25, 0, 340, 320 };
        float rotationAngles5[6] = { 15, 25, 50, 35, 15, 350 };
        float rotationAngles6[6] = { 310, 340, 30, 30, 10, 0 };

        if (currentFrame == 0) {
            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles[0], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.25f, 0.0f, 0.0625f, 0.125f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(-0.25f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();
            // Stripe 1
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(-0.35f, 0.043f, 0.0f);
            glRotatef(10, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.35f, -0.043f, 0.0f);
            Ellipse::drawEllipse(-0.35f, 0.043f, 0.02f, 0.0375f, 100);
            glPopMatrix();
            // Stripe 2
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(-0.4125f, 0.034f, 0.0f);
            glRotatef(10, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.4125f, -0.034f, 0.0f);
            Ellipse::drawEllipse(-0.4125f, 0.034f, 0.02f, 0.0375f, 100);
            glPopMatrix();


            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles[1], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.125f, 0.0f, 0.0625f, 0.11f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(-0.125f, 0.0f, 0.0625f, 0.11f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(-0.225f, -0.052f, 0.0f);
            glRotatef(60, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.225f, 0.052f, 0.0f);
            Ellipse::drawEllipse(-0.225f, -0.052f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(rotationAngles[2], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.0f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.0f, 0.0f, 0.0625f, 0.125f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.0f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(-0.038f, -0.125f, 0.0f);
            glRotatef(100, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.038f, 0.13f, 0.0f);
            Ellipse::drawEllipse(-0.038f, -0.125f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles[3], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.125f, 0.0f, 0.0625f, 0.115f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.125f, 0.0f, 0.0625f, 0.115f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(0.15f, -0.125f, 0.0f);
            glRotatef(130, 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.15f, 0.125f, 0.0f);
            Ellipse::drawEllipse(0.15f, -0.125f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles[4], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.25f, 0.0f, 0.0625f, 0.115f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.25f, 0.0f, 0.0625f, 0.115f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(0.278f, -0.13f, 0.0f);
            glRotatef(130, 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.278f, 0.13f, 0.0f);
            Ellipse::drawEllipse(0.278f, -0.13f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.325f, 0.0f, 0.0f);
            glRotatef(rotationAngles[5], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.325f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.325f, 0.0f, 0.0625f, 0.125f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.325f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(0.3305f, -0.13f, 0.0f);
            glRotatef(120, 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.3305f, 0.13f, 0.0f);
            Ellipse::drawEllipse(0.3305f, -0.13f, 0.02f, 0.0375f, 100);
            glPopMatrix();
        }
        else if (currentFrame == 1) {
            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles2[0], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.25f, 0.0f, 0.0625f, 0.125f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(-0.25f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();
            // Stripe 1
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(-0.26f, -0.1f, 0.0f);
            glRotatef(120, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.26f, 0.1f, 0.0f);
            Ellipse::drawEllipse(-0.26f, -0.1f, 0.02f, 0.0375f, 100);
            glPopMatrix();
            // Stripe 2
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(-0.228f, -0.16f, 0.0f);
            glRotatef(120, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.228f, 0.16f, 0.0f);
            Ellipse::drawEllipse(-0.228f, -0.16f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles2[1], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.125f, 0.0f, 0.0625f, 0.11f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(-0.125f, 0.0f, 0.0625f, 0.11f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(-0.178f, -0.1f, 0.0f);
            glRotatef(90, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.178f, 0.1f, 0.0f);
            Ellipse::drawEllipse(-0.178f, -0.1f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(rotationAngles2[2], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.0f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.0f, 0.0f, 0.0625f, 0.12f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.0f, 0.0f, 0.0625f, 0.12f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(-0.08f, -0.1f, 0.0f);
            glRotatef(70, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.08f, 0.1f, 0.0f);
            Ellipse::drawEllipse(-0.08f, -0.1f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles2[3], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.125f, 0.0f, 0.0625f, 0.115f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.125f, 0.0f, 0.0625f, 0.115f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(-0.01f, -0.02f, 0.0f);
            glRotatef(30, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.01f, 0.02f, 0.0f);
            Ellipse::drawEllipse(-0.01f, -0.02f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles2[4], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.25f, 0.0f, 0.0625f, 0.1f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.25f, 0.0f, 0.0625f, 0.1f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(0.135f, -0.015f, 0.0f);
            glRotatef(30, 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.135f, 0.015f, 0.0f);
            Ellipse::drawEllipse(0.135f, -0.015f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.325f, 0.0f, 0.0f);
            glRotatef(rotationAngles2[5], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.325f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.325f, 0.0f, 0.0625f, 0.1f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.325f, 0.0f, 0.0625f, 0.1f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(0.35f, -0.1f, 0.0f);
            glRotatef(140, 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.35f, 0.1f, 0.0f);
            Ellipse::drawEllipse(0.35f, -0.1f, 0.02f, 0.0375f, 100);
            glPopMatrix();
        }
        else if (currentFrame == 2) {
            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles3[0], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.25f, 0.0f, 0.0625f, 0.15f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(-0.25f, 0.0f, 0.0625f, 0.15f, 100);
            glPopMatrix();
            // Stripe 1
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(-0.228f, -0.105f, 0.0f);
            glRotatef(130, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.228f, 0.105f, 0.0f);
            Ellipse::drawEllipse(-0.228f, -0.105f, 0.02f, 0.0375f, 100);
            glPopMatrix();
            // Stripe 2
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(-0.176f, -0.161f, 0.0f);
            glRotatef(130, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.176f, 0.161f, 0.0f);
            Ellipse::drawEllipse(-0.176f, -0.161f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles3[1], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.125f, 0.0f, 0.0625f, 0.14f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(-0.125f, 0.0f, 0.0625f, 0.14f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(-0.092f, -0.135f, 0.0f);
            glRotatef(130, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.092f, 0.135f, 0.0f);
            Ellipse::drawEllipse(-0.092f, -0.135f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(rotationAngles3[2], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.0f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.0f, 0.0f, 0.0625f, 0.125f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.0f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(-0.02f, -0.13f, 0.0f);
            glRotatef(110, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.02f, 0.13f, 0.0f);
            Ellipse::drawEllipse(-0.02f, -0.13f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles3[3], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.125f, 0.0f, 0.0625f, 0.125f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.125f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(0.052f, -0.11f, 0.0f);
            glRotatef(80, 0.00f, 0.0f, 1.0f);
            glTranslatef(-0.052f, 0.11f, 0.0f);
            Ellipse::drawEllipse(0.052f, -0.11f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles3[4], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.25f, 0.0f, 0.0625f, 0.115f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.25f, 0.0f, 0.0625f, 0.115f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(0.12f, -0.015f, 0.0f);
            glRotatef(30, 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.12f, 0.015f, 0.0f);
            Ellipse::drawEllipse(0.12f, -0.015f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.325f, 0.0f, 0.0f);
            glRotatef(rotationAngles3[5], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.325f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.325f, 0.0f, 0.0625f, 0.11f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.325f, 0.0f, 0.0625f, 0.11f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(0.245f, -0.09f, 0.0f);
            glRotatef(80, 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.245f, 0.09f, 0.0f);
            Ellipse::drawEllipse(0.245f, -0.09f, 0.02f, 0.0375f, 100);
            glPopMatrix();
        }
        else if (currentFrame == 3) {
            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles4[0], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.25f, 0.0f, 0.0625f, 0.17f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(-0.25f, 0.0f, 0.0625f, 0.17f, 100);
            glPopMatrix();
            // Stripe 1
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(-0.1895f, -0.115f, 0.0f);
            glRotatef(140, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.1895f, 0.115f, 0.0f);
            Ellipse::drawEllipse(-0.1895f, -0.115f, 0.02f, 0.0375f, 100);
            glPopMatrix();
            // Stripe 2
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(-0.132f, -0.16f, 0.0f);
            glRotatef(140, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.132f, 0.16f, 0.0f);
            Ellipse::drawEllipse(-0.132f, -0.16f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles4[1], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.125f, 0.0f, 0.0625f, 0.15f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(-0.125f, 0.0f, 0.0625f, 0.15f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(-0.068f, -0.145f, 0.0f);
            glRotatef(135, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.068f, 0.145f, 0.0f);
            Ellipse::drawEllipse(-0.068f, -0.145f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(rotationAngles4[2], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.0f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.0f, 0.0f, 0.0625f, 0.125f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.0f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(-0.008f, -0.13f, 0.0f);
            glRotatef(115, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.008f, 0.13f, 0.0f);
            Ellipse::drawEllipse(-0.008f, -0.13f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles4[3], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.125f, 0.0f, 0.0625f, 0.125f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.125f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(0.062f, -0.115f, 0.0f);
            glRotatef(90, 0.00f, 0.0f, 1.0f);
            glTranslatef(-0.062f, 0.115f, 0.0f);
            Ellipse::drawEllipse(0.062f, -0.115f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles4[4], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.25f, 0.0f, 0.0625f, 0.13f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.25f, 0.0f, 0.0625f, 0.13f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(0.147f, -0.1f, 0.0f);
            glRotatef(70, 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.147f, 0.1f, 0.0f);
            Ellipse::drawEllipse(0.147f, -0.1f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.325f, 0.0f, 0.0f);
            glRotatef(rotationAngles4[5], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.325f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.325f, 0.0f, 0.0625f, 0.1f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.325f, 0.0f, 0.0625f, 0.1f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(0.214f, -0.035f, 0.0f);
            glRotatef(50, 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.214f, 0.035f, 0.0f);
            Ellipse::drawEllipse(0.214f, -0.035f, 0.02f, 0.0375f, 100);
            glPopMatrix();
        }
        else if (currentFrame == 4) {
            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles5[0], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.25f, 0.0f, 0.0625f, 0.11f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(-0.25f, 0.0f, 0.0625f, 0.11f, 100);
            glPopMatrix();
            // Stripe 1
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(-0.288f, -0.08f, 0.0f);
            glRotatef(105, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.288f, 0.08f, 0.0f);
            Ellipse::drawEllipse(-0.288f, -0.08f, 0.02f, 0.0375f, 100);
            glPopMatrix();
            // Stripe 2
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(-0.274f, -0.145f, 0.0f);
            glRotatef(105, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.274f, 0.145f, 0.0f);
            Ellipse::drawEllipse(-0.274f, -0.145f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles5[1], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.125f, 0.0f, 0.0625f, 0.12f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(-0.125f, 0.0f, 0.0625f, 0.12f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(-0.139f, -0.12f, 0.0f);
            glRotatef(110, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.139f, 0.12f, 0.0f);
            Ellipse::drawEllipse(-0.139f, -0.12f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(rotationAngles5[2], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.0f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.0f, 0.0f, 0.0625f, 0.14f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.0f, 0.0f, 0.0625f, 0.14f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(0.057f, -0.13f, 0.0f);
            glRotatef(140, 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.057f, 0.13f, 0.0f);
            Ellipse::drawEllipse(0.057f, -0.13f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles5[3], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.125f, 0.0f, 0.0625f, 0.115f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.125f, 0.0f, 0.0625f, 0.115f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(0.132f, -0.12f, 0.0f);
            glRotatef(130, 0.00f, 0.0f, 1.0f);
            glTranslatef(-0.132f, 0.12f, 0.0f);
            Ellipse::drawEllipse(0.132f, -0.12f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles5[4], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.25f, 0.0f, 0.0625f, 0.12f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.25f, 0.0f, 0.0625f, 0.12f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(0.22f, -0.13f, 0.0f);
            glRotatef(103, 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.22f, 0.13f, 0.0f);
            Ellipse::drawEllipse(0.22f, -0.13f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.325f, 0.0f, 0.0f);
            glRotatef(rotationAngles5[5], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.325f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.325f, 0.0f, 0.0625f, 0.125f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.325f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(0.245f, -0.1f, 0.0f);
            glRotatef(80, 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.245f, 0.1f, 0.0f);
            Ellipse::drawEllipse(0.245f, -0.1f, 0.02f, 0.0375f, 100);
            glPopMatrix();
        }
        else if (currentFrame == 5) {
            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles6[0], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.25f, 0.0f, 0.0625f, 0.125f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(-0.25f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();
            // Stripe 1
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(-0.36f, -0.012f, 0.0f);
            glRotatef(35, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.36f, 0.012f, 0.0f);
            Ellipse::drawEllipse(-0.36f, -0.012f, 0.02f, 0.0375f, 100);
            glPopMatrix();
            // Stripe 2
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(-0.41f, -0.0555f, 0.0f);
            glRotatef(35, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.41f, 0.0555f, 0.0f);
            Ellipse::drawEllipse(-0.41f, -0.0555f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles6[1], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(-0.125f, 0.0f, 0.0625f, 0.12f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(-0.125f, 0.0f, 0.0625f, 0.12f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(-0.22f, -0.08f, 0.0f);
            glRotatef(70, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.22f, 0.08f, 0.0f);
            Ellipse::drawEllipse(-0.22f, -0.08f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(rotationAngles6[2], 0.0f, 0.0f, 1.0f);
            glTranslatef(0.0f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.0f, 0.0f, 0.0625f, 0.125f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.0f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(0.002f, -0.13f, 0.0f);
            glRotatef(120, 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.002f, 0.13f, 0.0f);
            Ellipse::drawEllipse(0.002f, -0.13f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.125f, 0.0f, 0.0f);
            glRotatef(rotationAngles6[3], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.125f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.125f, 0.0f, 0.0625f, 0.12f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.125f, 0.0f, 0.0625f, 0.12f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(0.128f, -0.13f, 0.0f);
            glRotatef(120, 0.00f, 0.0f, 1.0f);
            glTranslatef(-0.128f, 0.13f, 0.0f);
            Ellipse::drawEllipse(0.128f, -0.13f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.25f, 0.0f, 0.0f);
            glRotatef(rotationAngles6[4], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.25f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.25f, 0.0f, 0.0625f, 0.12f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.25f, 0.0f, 0.0625f, 0.12f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(0.208f, -0.12f, 0.0f);
            glRotatef(98, 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.208f, 0.12f, 0.0f);
            Ellipse::drawEllipse(0.208f, -0.12f, 0.02f, 0.0375f, 100);
            glPopMatrix();

            glPushMatrix();
            glColor4ub(237, 182, 38, opacity * 255);
            glTranslatef(0.325f, 0.0f, 0.0f);
            glRotatef(rotationAngles6[5], 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.325f, 0.0f, 0.0f);
            Ellipse::drawEllipse(0.325f, 0.0f, 0.0625f, 0.125f, 100);
            glColor4ub(193, 129, 59, opacity * 255);
            Ellipse::drawEllipseBorder(0.325f, 0.0f, 0.0625f, 0.125f, 100);
            glPopMatrix();
            // Stripe
            glPushMatrix();
            glColor4ub(193, 129, 59, opacity * 255);
            glTranslatef(0.262f, -0.11f, 0.0f);
            glRotatef(88, 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.262f, 0.11f, 0.0f);
            Ellipse::drawEllipse(0.262f, -0.11f, 0.02f, 0.0375f, 100);
            glPopMatrix();
        }

        glPopMatrix();
        glDisable(GL_BLEND);
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

    float getBusSize() const {
        return busSize;
    }

    void setBusSize(float size) {
        busSize = size;
    }

    float getOpacity() const {
        return opacity;
    }

    void setOpacity(float opacity) {
        this->opacity = opacity;
    }
    
    float getCurrentAngle() const {
        return currentAngle;
    }

    void setCurrentAngle(float currentAngle) {
        this->currentAngle = currentAngle;
    }

    bool getIsBoarded() const {
        return isBoarded;
    }

    void setIsBoarded(bool isBoarded) {
        this->isBoarded = isBoarded;
    }

    bool getMovingRight() const {
        return movingRight;
    }

    void setIsDay(bool isDay) {
        this->isDay = isDay;
    }

    bool getIsDay() const {
        return isDay;
    }

    void setMovingRight(bool movingRight) {
        this->movingRight = movingRight;
    }

    bool getIsLightOn() const {
        return isLightOn;
    }

    void setIsLightOn(bool isLightOn) {
        this->isLightOn = isLightOn;
    }

    void move(float speed) {
        if (!movingRight) {
            posX -= speed;
        }
        else {
            posX += speed;
        }
    }

    void moveDiagonal(float speedX, float speedY) {
        posX += speedX;
        posY += speedY;
    }

    void moveInArc(float speed, float angleIncrement) {
        float centerX = 1700.0f;
        float centerY = -2750.0f;
        float radius = 3100.0f;

        currentAngle += angleIncrement * speed;
        posX = centerX + radius * cos(currentAngle);
        posY = centerY + radius * sin(currentAngle);
    }

    void updateFrame() {
        currentFrame = (currentFrame + 1) % 6;
    }
};

