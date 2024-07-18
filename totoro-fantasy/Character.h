#pragma once
#include <gl/glut.h>
#include "Constants.h"
#include "Colors.h"

class Character
{
public:
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

    float getCharacterSize() const {
        return characterSize;
    }

    void setCharacterSize(float size) {
        characterSize = size;
    }

    int getCurrentFrame() const {
        return currentFrame;
    }

    void setCurrentFrame(int frame) {
        currentFrame = frame;
    }

    bool getMovingRight() const {
        return movingRight;
    }

    void setMovingRight(bool moving) {
        movingRight = moving;
    }

    void move(float speed) {
        posX += speed;
    }

    void moveInArc(float speed, float angleIncrement) {
        float centerX = 1800.0f;
        float centerY = -1800.0f;
        float radius = 2000.0f;

        currentAngle += angleIncrement;
        posX = centerX + radius * cos(currentAngle);
        posY = centerY + radius * sin(currentAngle);
    }

    void updateFrame() {
        currentFrame = (currentFrame + 1) % 4;
    }

protected:
    float posX;
    float posY;
    float currentAngle;
    float characterSize;
    int currentFrame;
    bool movingRight;

    Character(float startX, float startY, float size, float currentAngle)
        : posX(startX), posY(startY), characterSize(size), currentFrame(0), movingRight(true), currentAngle(currentAngle) {
    }

    void drawFrontView() {
        glPushMatrix();
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
        glPopMatrix();
    }

    void drawSideView() {
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
};

class LittleGirl : public Character {
private:
    bool isCrying;

    void drawCryingEffect() {

    }

public:
    LittleGirl(float startX, float startY, float size, float currentAngle, bool crying)
        : Character(startX, startY, size, currentAngle), isCrying(crying) {
    }

    bool getCrying() const {
        return isCrying;
    }

    void setCrying(bool crying) {
        isCrying = crying;
    }

    void drawFrontView() {
        Character::drawFrontView();
        if (isCrying) {
            drawCryingEffect();
        }
    }

    void drawSideView() {
        Character::drawSideView();
    }
};
