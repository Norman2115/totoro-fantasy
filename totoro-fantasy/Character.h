#pragma once
#include <gl/glut.h>
#include "Constants.h"
#include "Colors.h"
#include "Constants.h"

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

    float getCurrentAngle() const {
        return currentAngle;
    }

    void setCurrentAngle(float angle) {
        currentAngle = angle;
    }

    float getOpacity() const {
        return opacity;
    }

    void setOpacity(float op) {
        opacity = op;
    }

    void move(float speed) {
        posX += speed;
    }

    void moveVertically(float speed) {
        posY += speed;
    }

    void moveDiagonally(float speedX, float speedY) {
        posX += speedX;
        posY += speedY;
    }

    void moveInArc(float speed, float angleIncrement) {
        float centerX = 1800.0f;
        float centerY = -1800.0f;
        float radius = 2000.0f;

        currentAngle -= angleIncrement * speed;
        posX = centerX + radius * cos(currentAngle);
        posY = centerY + radius * sin(currentAngle);
    }

    void updateFrame() {
        currentFrame = (currentFrame + 1) % 4;
    }

protected:
    float posX;
    float posY;
    float characterSize;
    float currentAngle;
    float opacity = 1.0f;
    int currentFrame;
    bool movingRight;

    Character(float startX, float startY, float size, float currentAngle)
        : posX(startX), posY(startY), characterSize(size), currentAngle(currentAngle), currentFrame(0), movingRight(true) {
    }

    void drawFrontView(Color dressColor) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glPushMatrix();
        glTranslatef(posX, posY, 0.0f);
        glScalef(characterSize, characterSize, 1.0f);
        glPushAttrib(GL_LINE_BIT);
        glLineWidth(3);
        // Head
        glColor4f(Colors::CHARACTER_SKIN.getR(), Colors::CHARACTER_SKIN.getG(), Colors::CHARACTER_SKIN.getB(), opacity);
        Circle::draw(0.0f, 0.525f, 0.075f);
        // Dress
        glColor4f(dressColor.getR(), dressColor.getG(), dressColor.getB(), opacity);
        glBegin(GL_POLYGON);
        glVertex3f(-0.05f, 0.45f, -0.01f);
        glVertex3f(0.05f, 0.45f, -0.01f);
        glVertex3f(0.075f, 0.2f, -0.01f);
        glVertex3f(-0.075f, 0.2f, -0.01f);
        glEnd();
        // Left Hand
        glColor4f(Colors::CHARACTER_SKIN.getR(), Colors::CHARACTER_SKIN.getG(), Colors::CHARACTER_SKIN.getB(), opacity);
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
        glPopAttrib();
        glPopMatrix();
        glDisable(GL_BLEND);
    }

    void drawSideView(Color dressColor) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glPushMatrix();
        glTranslatef(posX, posY, 0.0f);
        if (movingRight) {
            glScalef(characterSize, characterSize, 1.0f);
        }
        else {
            glScalef(-characterSize, characterSize, 1.0f);
        }

        glPushAttrib(GL_LINE_BIT);
        glLineWidth(3);

        glColor4f(Colors::CHARACTER_SKIN.getR(), Colors::CHARACTER_SKIN.getG(), Colors::CHARACTER_SKIN.getB(), opacity);
        Circle::draw(0.0f, 0.525f, 0.075f);

        glColor4f(dressColor.getR(), dressColor.getG(), dressColor.getB(), opacity);
        glBegin(GL_POLYGON);
        glVertex3f(-0.025f, 0.45f, -0.01f);
        glVertex3f(0.025f, 0.45f, -0.01f);
        glVertex3f(0.05f, 0.2f, -0.01f);
        glVertex3f(-0.05f, 0.2f, -0.01f);
        glEnd();

        glColor4f(Colors::CHARACTER_SKIN.getR(), Colors::CHARACTER_SKIN.getG(), Colors::CHARACTER_SKIN.getB(), opacity);
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
        glPopAttrib();
        glPopMatrix();
        glDisable(GL_BLEND);
    }

    void drawHugView(Color dressColor) {
        glColor4f(Colors::CHARACTER_SKIN.getR(), Colors::CHARACTER_SKIN.getG(), Colors::CHARACTER_SKIN.getB(), opacity);
        Circle::draw(0.0f, 0.525f, 0.075f);

        glColor4f(dressColor.getR(), dressColor.getG(), dressColor.getB(), opacity);
        glBegin(GL_POLYGON);
        glVertex3f(-0.025f, 0.45f, -0.01f);
        glVertex3f(0.025f, 0.45f, -0.01f);
        glVertex3f(0.05f, 0.2f, -0.01f);
        glVertex3f(-0.05f, 0.2f, -0.01f);
        glEnd();

        glColor4f(Colors::CHARACTER_SKIN.getR(), Colors::CHARACTER_SKIN.getG(), Colors::CHARACTER_SKIN.getB(), opacity);

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
    }
};

class LittleGirl : public Character {
private:
    bool isCrying;
    float bounceTime;
    bool initialDropComplete;

    void drawCryEffect() {
        glPushMatrix();
        glTranslatef(posX, posY, 0.0f);
        glScalef(characterSize, characterSize, 1.0f);
        glPushAttrib(GL_LINE_BIT);
        glLineWidth(3);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2f(-0.0125, 0.5375);
        glVertex2f(-0.04, 0.5375);
        glEnd();
        glBegin(GL_LINE_STRIP);
        glVertex2f(0.0125, 0.5375);
        glVertex2f(0.04, 0.5375);
        glEnd();
        glPopAttrib();

        glPushAttrib(GL_LINE_BIT);
        glLineWidth(2);
        glColor3f(0.0f, 0.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2f(-0.02625, 0.53);
        glVertex2f(-0.02625, 0.46);
        glEnd();
        glBegin(GL_LINE_STRIP);
        glVertex2f(0.02625, 0.53);
        glVertex2f(0.02625, 0.46);
        glEnd();
        glPopAttrib();
        glPopMatrix();
    }

public:
    LittleGirl(float startX, float startY, float size, float currentAngle, bool crying)
        : Character(startX, startY, size, currentAngle), isCrying(crying), bounceTime(0), initialDropComplete(false) {
    }

    bool getCrying() const {
        return isCrying;
    }

    void setCrying(bool crying) {
        isCrying = crying;
    }

    void drawFrontView() {
        Character::drawFrontView(Colors::GIRL_DRESS);
        if (isCrying) {
            drawCryEffect();
        }
    }

    void drawSideView() {
        Character::drawSideView(Colors::GIRL_DRESS);
    }

    bool bounceVertical(float bounceHeight, float targetPosY, float bounceDuration, float updateInterval) {
        if (!initialDropComplete) {
            posY -= 10.0f;
            if (posY <= targetPosY) {
                posY = targetPosY;
                initialDropComplete = true;
                bounceTime = 0.0f;
            }
            return true;
        }
        
        bounceTime += updateInterval / 1000.0f;
        float progress = bounceTime / bounceDuration;
        if (progress >= 1.0f) {
            setPosY(targetPosY);
            return false;
        }
        else {
            float heightAdjustment = sin(progress * 3.14159f) * bounceHeight;
            setPosY(targetPosY + heightAdjustment);
            return true;
        }
    }

    void resetBounceTime() { bounceTime = 0; }

    void hug() {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glPushMatrix();
        glTranslatef(posX, posY, 0.0f);
        if (movingRight) {
            glScalef(characterSize, characterSize, 1.0f);
        }
        else {
            glScalef(-characterSize, characterSize, 1.0f);
        }
        glPushAttrib(GL_LINE_BIT);
        glLineWidth(3);

        drawHugView(Colors::GIRL_DRESS);

        glBegin(GL_LINE_STRIP);
        glVertex2f(0.0f, 0.4f);
        glVertex2f(0.15f, 0.475f);
        glEnd();

        glPopAttrib();
        glPopMatrix();
        glDisable(GL_BLEND);
    }   
};

class Mother : public Character {
public:
    Mother(float startX, float startY, float size)
        : Character(startX, startY, size, 0) {
    }

    void drawFrontView() {
        Character::drawFrontView(Colors::MOM_DRESS);
    }

    void drawSideView() {
        Character::drawSideView(Colors::MOM_DRESS);
    }

    void hug() {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glPushMatrix();
        glTranslatef(posX, posY, 0.0f);
        glScalef(characterSize, characterSize, 1.0f);
        glPushAttrib(GL_LINE_BIT);
        glLineWidth(3);

        drawHugView(Colors::MOM_DRESS);

        glBegin(GL_LINE_STRIP);
        glVertex2f(0.0f, 0.4f);
        glVertex2f(0.15f, 0.3f);
        glEnd();

        glPopAttrib();
        glPopMatrix();
        glDisable(GL_BLEND);
    }
};