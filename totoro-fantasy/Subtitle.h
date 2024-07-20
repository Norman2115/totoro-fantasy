#pragma once
#include <GL/glut.h>
#include <string>
#include <cstring>

// Screen dimensions
const int screenWidth = 1920;
const int screenHeight = 1080;

class Subtitle
{
public:
    Subtitle(const std::string& text) : text(text) {}
    
    void setText(const std::string& newText) {
        text = newText;
    }

    void draw() {
        drawBackground();
        drawText();
    }

private:
    std::string text;

    void drawBackground() {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
        glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(screenWidth, 0.0f);
        glVertex2f(screenWidth, screenHeight * 0.1f);
        glVertex2f(0.0f, screenHeight * 0.1f);
        glEnd();
        glDisable(GL_BLEND);
    }

    void drawText() {
        glColor3f(1.0f, 1.0f, 1.0f);
        glRasterPos2f((screenWidth - getTextWidth()) / 2.0f, screenHeight * 0.05f);

        for (char c : text) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
    }

    float getTextWidth() {
        float width = 0.0f;
        for (char c : text) {
            width += glutBitmapWidth(GLUT_BITMAP_HELVETICA_18, c);
        }
        return width;
    }
};

