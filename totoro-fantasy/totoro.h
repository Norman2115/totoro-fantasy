#ifndef TOTORO_H
#define TOTORO_H

#include <GL/glut.h>
#include <cmath>

class Totoro {
public:
    Totoro() {}

    void draw(float x, float y, float size) {
        glPushMatrix();
        glTranslatef(x, y, 0.0f);
        glScalef(size, size, 1.0f);  // Only use size for uniform scaling

        // Body
        glColor3f(0.5, 0.5, 0.5); // Gray color for Totoro
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.43 * cos(theta), 0.45 * sin(theta) - 0.2); // Adjusted vertical scale and offset
        }
        glEnd();

        // Bottom Body
        glColor3f(0.5, 0.5, 0.5); // Gray color for Totoro
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.45 * cos(theta), 0.3 * sin(theta) - 0.41); // Adjusted size and position for the belly
        }
        glEnd();

        // Left Ear
        glColor3f(0.5, 0.5, 0.5); // Gray color for Totoro's ears
        glPushMatrix();
        glTranslatef(-0.2, 0.25, 0.0); // Translate to the position of the left ear, lowered
        glRotatef(24, 0.0, 0.0, 1.0); // Rotate to slant the ear
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.10 * cos(theta), 0.25 * sin(theta)); // Adjusted size for the left ear
        }
        glEnd();
        glPopMatrix();

        // Right Ear
        glPushMatrix();
        glTranslatef(0.2, 0.25, 0.0); // Translate to the position of the right ear, lowered
        glRotatef(-24, 0.0, 0.0, 1.0); // Rotate to slant the ear
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.10 * cos(theta), 0.25 * sin(theta)); // Adjusted size for the right ear
        }
        glEnd();
        glPopMatrix();

        // Left Arm
        glColor3f(0.5, 0.5, 0.5); // Gray color for Totoro's arms
        glPushMatrix();
        glTranslatef(-0.42, -0.32, 0.0); // Translate to the position of the left arm
        glRotatef(-20, 0.0, 0.0, 1.0); // Rotate to slant the arm
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.10 * cos(theta), 0.18 * sin(theta)); // Adjusted size for the left arm
        }
        glEnd();
        glPopMatrix();

        // Right Arm
        glPushMatrix();
        glTranslatef(0.42, -0.32, 0.0); // Translate to the position of the right arm
        glRotatef(15, 0.0, 0.0, 1.0); // Rotate to slant the arm
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.10 * cos(theta), 0.18 * sin(theta)); // Adjusted size for the right arm
        }
        glEnd();
        glPopMatrix();

        // Left Foot
        glColor3f(0.5, 0.5, 0.5); // Gray color for Totoro's feet
        glPushMatrix();
        glTranslatef(-0.25, -0.70, 0); // Translate to the position of the left foot
        glRotatef(10, 0.0, 0.0, 0); // Rotate to slant the foot
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.15 * cos(theta), 0.06 * sin(theta)); // Adjusted size for the left foot
        }
        glEnd();
        glPopMatrix();

        // Right Foot
        glPushMatrix();
        glTranslatef(0.25, -0.70, 0.0); // Translate to the position of the right foot
        glRotatef(-10, 0.0, 0.0, 0); // Rotate to slant the foot
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.15 * cos(theta), 0.06 * sin(theta)); // Adjusted size for the right foot
        }
        glEnd();
        glPopMatrix();

        // Belly
        glColor3f(1.0, 1.0, 0.8); // Light yellow color for Totoro's belly
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.4 * cos(theta), 0.3 * sin(theta) - 0.4); // Adjusted size and position for the belly
        }
        glEnd();

        // Left Eye
        glColor3f(1.0, 1.0, 1.0); // White color for Totoro's eyes
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.08 * cos(theta) - 0.2, 0.08 * sin(theta) + 0.03); // Lowered position for the left eye
        }
        glEnd();

        // Right Eye
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.08 * cos(theta) + 0.2, 0.08 * sin(theta) + 0.03); // Lowered position for the right eye
        }
        glEnd();

        // Left Pupil
        glColor3f(0.0, 0.0, 0.0); // Black color for Totoro's pupils
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.03 * cos(theta) - 0.2, 0.03 * sin(theta) + 0.03); // Lowered position for the left pupil
        }
        glEnd();

        // Right Pupil
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.03 * cos(theta) + 0.2, 0.03 * sin(theta) + 0.03); // Lowered position for the right pupil
        }
        glEnd();

        // Nose
        glColor3f(0.0, 0.0, 0.0); // Black color for Totoro's nose
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.03 * cos(theta), 0.02 * sin(theta) + 0.02); // Adjusted size and position for the nose
        }
        glEnd();

        // Strip 1
        glColor3f(0.0, 0.0, 0.0); // Black color for Totoro's strips
        glBegin(GL_QUADS);
        glVertex2f(-0.05, -0.22);  // Bottom left
        glVertex2f(0.0, -0.16);    // Top middle
        glVertex2f(0.05, -0.22);  // Bottom right
        glVertex2f(0, -0.2);   // Center
        glEnd();

        // Strip 2
        glColor3f(0.0, 0.0, 0.0); // Black color for Totoro's strips
        glBegin(GL_QUADS);
        glVertex2f(-0.25, -0.32);  // Bottom left
        glVertex2f(-0.2, -0.26);   // Top middle
        glVertex2f(-0.15, -0.32);  // Bottom right
        glVertex2f(-0.2, -0.3);    // Center
        glEnd();

        // Strip 3
        glColor3f(0.0, 0.0, 0.0); // Black color for Totoro's strips
        glBegin(GL_QUADS);
        glVertex2f(0.15, -0.32);  // Bottom left
        glVertex2f(0.2, -0.26); // Top middle
        glVertex2f(0.25, -0.32);  // Bottom right
        glVertex2f(0.2, -0.3);  // Center
        glEnd();

        // Whiskers
        glColor3f(0.0, 0.0, 0.0); // Black color for Totoro's whiskers
        glBegin(GL_LINES);

        // Left whiskers 
        glVertex2f(-0.3, 0.0);    // Left whisker 1
        glVertex2f(-0.5, 0.1);
        glVertex2f(-0.3, -0.03);  // Left whisker 2
        glVertex2f(-0.5, 0.0);
        glVertex2f(-0.3, -0.06);  // Left whisker 3
        glVertex2f(-0.5, -0.1);

        // Right whiskers 
        glVertex2f(0.3, 0.0);     // Right whisker 1
        glVertex2f(0.5, 0.1);
        glVertex2f(0.3, -0.03);   // Right whisker 2
        glVertex2f(0.5, 0.0);
        glVertex2f(0.3, -0.06);   // Right whisker 3
        glVertex2f(0.5, -0.1);

        glEnd();

        glPopMatrix();
    }
};

#endif // TOTORO_H
