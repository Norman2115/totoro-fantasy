#pragma once
#include <cmath>
#include <gl/glut.h>

class Ellipse
{
public:
    static void drawEllipse(float xTop, float yTop, float xRadius, float yRadius, int numSegments) {
        glBegin(GL_TRIANGLE_FAN);

        // Calculate the center of the ellipse based on the top point
        float xCenter = xTop;
        float yCenter = yTop - yRadius;

        glVertex2f(xCenter, yCenter); // Center of the ellipse

        // Start at the top end of the ellipse
        glVertex2f(xTop, yTop); // Topmost point

        for (int i = 1; i <= numSegments; i++) {
            float theta = 2.0f * 3.1415926f * float(i) / float(numSegments); // Angle in radians
            float x = xRadius * sinf(theta); // Calculate x coordinate
            float y = yRadius * cosf(theta); // Calculate y coordinate

            glVertex2f(x + xCenter, y + yCenter); // Output vertex
        }

        glEnd();
    }

    static void drawEllipseBorder(float xTop, float yTop, float xRadius, float yRadius, int numSegments) {
        glBegin(GL_LINE_LOOP);

        // Calculate the center of the ellipse based on the top point
        float xCenter = xTop;
        float yCenter = yTop - yRadius;

        for (int i = 0; i < numSegments; i++) {
            float theta = 2.0f * 3.1415926f * float(i) / float(numSegments); // Angle in radians
            float x = xRadius * sinf(theta); // Calculate x coordinate
            float y = yRadius * cosf(theta); // Calculate y coordinate

            glVertex2f(x + xCenter, y + yCenter); // Output vertex
        }

        glEnd();
    }
};
