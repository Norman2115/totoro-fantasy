#pragma once
#include <gl/glut.h>
#include "Constants.h"
#include "Colors.h"

class Character
{
protected:
    virtual void drawSideView() = 0;
    virtual void drawFrontView() = 0;
};

class LittleGirl : public Character {
private:
    float posX;
    float posY;
    float characterSize;
    int currentFrame;
    bool movingRight;

public:
    LittleGirl(float startX, float startY, float size)
        : posX(startX), posY(startY), characterSize(size), currentFrame(0), movingRight(true) {
    }

    void drawFrontView() override {
        glTranslatef(posX, posY, 0.0f);
        glScalef(characterSize, characterSize, 1.0f);
        glLineWidth(3);
        // Head
        glColor3f(1.0f, 1.0f, 1.0f);
        Circle::draw(0.0f, 0.525f, 0.075f);
        // Pink Dress
        glColor3f(1.0f, 0.75f, 0.8f);
        glBegin(GL_POLYGON);
        glVertex3f(-0.05f, 0.45f, -0.01f);
        glVertex3f(0.05f, 0.45f, -0.01f);
        glVertex3f(0.075f, 0.2f, -0.01f);
        glVertex3f(-0.075f, 0.2f, -0.01f);
        glEnd();
        // Left Hand
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2f(0.0575f, 0.4f);
        glVertex2f(0.1f, 0.275f);
        glEnd();
        // Right Hand
        glBegin(GL_LINE_STRIP);
        glVertex2f(-0.0575f, 0.4f);
        glVertex2f(-0.1f, 0.275f);
        glEnd();
        // Left Leg
        glBegin(GL_LINE_STRIP);
        glVertex2f(-0.025f, 0.2f);
        glVertex2f(-0.025f, 0.0f);
        glVertex2f(-0.075f, -0.025f);
        glEnd();
        // Right Leg
        glBegin(GL_LINE_STRIP);
        glVertex2f(0.025f, 0.2f);
        glVertex2f(0.025f, 0.0f);
        glVertex2f(0.075f, -0.025f);
        glEnd();
    }

    void drawSideView() override {
        glPushMatrix();
        glTranslatef(posX, posY, 0.0f);
        glScalef(characterSize, characterSize, 1.0f);
        glLineWidth(3);

        glColor3f(1.0f, 1.0f, 1.0f);
        Circle::draw(0.0f, 0.525f, 0.075f);

        glColor3f(1.0f, 0.75f, 0.8f);
        glBegin(GL_POLYGON);
        glVertex3f(-0.025f, 0.45f, -0.01f);
        glVertex3f(0.025f, 0.45f, -0.01f);
        glVertex3f(0.05f, 0.2f, -0.01f);
        glVertex3f(-0.05f, 0.2f, -0.01f);
        glEnd();

        glColor3f(1.0f, 1.0f, 1.0f);
        if (currentFrame == 0) {
            // Left leg
            glBegin(GL_LINE_STRIP);
            glVertex2f(0.0f, 0.2f);
            glVertex2f(-0.05f, 0.0f);
            glVertex2f(0.0f, 0.0f);
            glEnd();
            // Right leg
            glBegin(GL_LINE_STRIP);
            glVertex2f(0.0f, 0.2f);
            glVertex2f(0.05f, 0.0f);
            glVertex2f(0.1f, 0.0f);
            glEnd();
            // Left arm
            glBegin(GL_LINE_STRIP);
            glVertex2f(0.0f, 0.4f);
            glVertex2f(0.025f, 0.325f);
            glVertex2f(0.1f, 0.275f);
            glEnd();
        }
        else if (currentFrame == 1) {
            // Left Leg
            glBegin(GL_LINE_STRIP);
            glVertex2f(0.0f, 0.2f);
            glVertex2f(0.0f, 0.1f);
            glVertex2f(-0.05f, 0.025f);
            glVertex2f(0.0f, 0.0f);
            glEnd();
            // Right leg
            glBegin(GL_LINE_STRIP);
            glVertex2f(0.0f, 0.2f);
            glVertex2f(0.05f, 0.0f);
            glVertex2f(0.1f, 0.0f);
            glEnd();
            // Left arm
            glBegin(GL_LINE_STRIP);
            glVertex2f(0.0f, 0.4f);
            glVertex2f(0.0f, 0.325f);
            glVertex2f(0.025f, 0.25f);
            glEnd();
        }
        else if (currentFrame == 2) {
            // Left Leg
            glBegin(GL_LINE_STRIP);
            glVertex2f(0.0f, 0.2f);
            glVertex2f(0.05f, 0.1f);
            glVertex2f(-0.05f, 0.05f);
            glVertex2f(-0.025f, 0.0f);
            glEnd();
            // Right leg
            glBegin(GL_LINE_STRIP);
            glVertex2f(0.0f, 0.2f);
            glVertex2f(0.0f, 0.0f);
            glVertex2f(0.05f, 0.0f);
            glEnd();
            // Left arm
            glBegin(GL_LINE_STRIP);
            glVertex2f(0.0f, 0.4f);
            glVertex2f(-0.05f, 0.325f);
            glVertex2f(-0.025f, 0.25f);
            glEnd();
            // Right arm
            glBegin(GL_LINE_STRIP);
            glVertex2f(0.0375f, 0.325f);
            glVertex2f(0.0625f, 0.275f);
            glEnd();
        }
        else if (currentFrame == 3) {
            // Left Leg
            glBegin(GL_LINE_STRIP);
            glVertex2f(0.0f, 0.2f);
            glVertex2f(-0.0375f, 0.0f);
            glVertex2f(0.025f, 0.0f);
            glEnd();
            // Right leg
            glBegin(GL_LINE_STRIP);
            glVertex2f(0.0f, 0.2f);
            glVertex2f(0.025f, 0.1f);
            glVertex2f(0.0f, 0.025f);
            glVertex2f(0.05f, 0.0f);
            glEnd();
            // Left arm
            glBegin(GL_LINE_STRIP);
            glVertex2f(0.0f, 0.4f);
            glVertex2f(0.0f, 0.325f);
            glVertex2f(0.025f, 0.25f);
            glEnd();
        }
        glPopMatrix();
    }

    void move(float speed) {
        posX += speed;
        if (posX > 1.0f) {
            posX = -1.0f;
        }
    }

    void updateFrame() {
        currentFrame = (currentFrame + 1) % 4;
    }
};