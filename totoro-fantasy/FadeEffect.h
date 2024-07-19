#pragma once
#include <gl/glut.h>

class FadeEffect
{
private:
    float opacity = 0.0f;

public:
    void setOpacity(float opacity) {
        this->opacity = opacity;
    }

    float getOpacity() const {
        return opacity;
    }

    void drawFadeScreen() {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glColor4f(0.0f, 0.0f, 0.0f, opacity); // black with varying alpha
        glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(1920.0f, 0.0f);
        glVertex2f(1920.0f, 1080.0f);
        glVertex2f(0.0f, 1080.0f);
        glEnd();

        glDisable(GL_BLEND);
    }

    void updateFadeScreen() {
        opacity += 0.05f;
        if (opacity >= 1.0f) {
            opacity = 1.0f;
        }
    }
};

