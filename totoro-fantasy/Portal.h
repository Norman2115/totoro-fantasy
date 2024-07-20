#ifndef PORTAL_H
#define PORTAL_H

#include <windows.h>
#include <cmath>
#include <gl/glut.h>

class Portal {
private:
    float angle;       // Angle for animation
    float glowAngle;   // Angle for glow effect
    int numParticles;  // Number of particles inside the portal (fixed value)
    float opacity;

    static Portal* instance; // Static instance pointer for the timer function

    void drawOval(float centerX, float centerY, float radiusX, float radiusY) {
        if (opacity <= 0.0f) return;
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(centerX, centerY);
        for (int i = 0; i <= 100; i++) {
            float currentAngle = 2.0f * 3.14159f * i / 100;
            float x = centerX + cosf(currentAngle) * radiusX;
            float y = centerY + sinf(currentAngle) * radiusY;

            // Calculate colors: various shades of blue and a bit of orange
            float blue = 0.5f + 0.5f * sin(currentAngle + angle);
            float orange = 0.5f + 0.5f * cos(currentAngle + angle);
            glColor4f(blue, 0.2f * orange, blue + 0.1f * orange, opacity);

            glVertex2f(x, y);
        }
        glEnd();
    }

    void drawGlow(float centerX, float centerY, float radiusX, float radiusY) {
        if (opacity <= 0.0f) return;
        glColor4f(0.0f, 0.0f, 1.0f, opacity <= 0.0f ? 0.0f : 1.0f); // Blue glow
        for (float i = 1.0f; i < 1.3f; i += 0.05f) {
            glBegin(GL_LINE_LOOP);
            for (int j = 0; j <= 100; j++) {
                float angle = 2.0f * 3.14159f * j / 100;
                float x = centerX + cosf(angle) * radiusX * i;
                float y = centerY + sinf(angle) * radiusY * i;
                glVertex2f(x, y);
            }
            glEnd();
        }
    }

    void drawParticles(float centerX, float centerY, float radiusX, float radiusY) const {
        if (opacity <= 0.0f) return;
        glBegin(GL_POINTS);
        for (int i = 0; i < numParticles; i++) {
            float angle = 2.0f * 3.14159f * (rand() % 1000) / 1000.0f;
            float distance = (rand() % 1000) / 1000.0f;
            float x = centerX + cosf(angle) * distance * radiusX;
            float y = centerY + sinf(angle) * distance * radiusY;
            glColor4f(0.0f, 0.0f, 1.0f, opacity);
            glVertex2f(x, y);
        }
        glEnd();
    }

    static void timerFunc(int value) {
        if (instance) {
            instance->update();
            glutTimerFunc(16, timerFunc, 0);  // Approximately 60 FPS
        }
    }

public:
    Portal()
        : angle(0.0f), glowAngle(0.0f), numParticles(500), opacity(1.0f) { // Fixed number of particles
        instance = this; // Initialize the static instance pointer
    }

    float getOpacity() const {
        return opacity;
    }

    void setOpacity(float opacity) {
        this->opacity = opacity;
    }

    void draw(float centerX, float centerY, float radiusX, float radiusY) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        // Draw animated oval portal
        drawOval(centerX, centerY, radiusX, radiusY);

        // Draw glow effect around the portal
        drawGlow(centerX, centerY, radiusX, radiusY);

        // Draw particles inside the portal
        drawParticles(centerX, centerY, radiusX, radiusY);

        glDisable(GL_BLEND);
    }

    void update() {
        angle += 0.1f;
        glowAngle += 0.05f;
        if (angle > 360.0f) {
            angle -= 360.0f;
        }
        if (glowAngle > 360.0f) {
            glowAngle -= 360.0f;
        }
        glutPostRedisplay();
    }

    void startTimer() {
        glutTimerFunc(0, timerFunc, 0);
    }
};

// Initialize the static instance pointer
Portal* Portal::instance = nullptr;

#endif // PORTAL_H
