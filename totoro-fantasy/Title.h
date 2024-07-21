#pragma once
#include <GL/glut.h>
#include <string>
#include <cstring>

// Screen dimensions
const int titleScreenWidth = 1920;
const int titleScreenHeight = 1080;

class Title
{
public:
    Title(const std::string& text) : text(text), scale(1.3f), opacity(1.0f) {}

    void setText(const std::string& newText) {
        text = newText;
    }

    void setOpacity(float newOpacity) {
        opacity = newOpacity;
    }

    float getOpacity() const {
        return opacity;
    }

    void draw() {
        drawText();
    }

private:
    std::string text;
    float scale;
    float opacity;

    void drawText() {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4f(1.0f, 1.0f, 1.0f, opacity);

        float textWidth = getTextWidth();
        float textHeight = getTextHeight();

        float xPos = (titleScreenWidth - textWidth) / 2.0f;
        float yPos = (titleScreenHeight + textHeight) / 2.2f;

        glPushMatrix();
        glTranslatef(xPos, yPos, 0.0f);
        glScalef(scale, scale, 1.0f);

        for (char c : text) {
            glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
        }

        glPopMatrix();
        glDisable(GL_BLEND);
    }

    float getTextWidth() {
        float width = 0.0f;
        for (char c : text) {
            width += glutStrokeWidth(GLUT_STROKE_ROMAN, c);
        }
        return width * scale;
    }

    float getTextHeight() {
        return 0.9f * 16.0f * scale;
    }
};