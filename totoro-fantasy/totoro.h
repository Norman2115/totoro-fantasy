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

class TotoroSide {
private:
    int frame;

public:
    TotoroSide() : frame(0) {}

    void draw(float x, float y, float size) {
        glPushMatrix();
        glTranslatef(x, y, 0.0f);
        glScalef(size, size, 1.0f);  // Only use size for uniform scaling

        // Body (ellipse shape)
        glColor3f(0.5, 0.5, 0.5); // Gray color for Totoro
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.35 * cos(theta), 0.45 * sin(theta) - 0.2); // Adjusted vertical scale and offset for side view
        }
        glEnd();

        // Bottom Body
        glColor3f(0.5, 0.5, 0.5); // Gray color for Totoro
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.35 * cos(theta), 0.3 * sin(theta) - 0.39); // Adjusted size and position for the belly
        }
        glEnd();

        // Head
        glColor3f(0.5, 0.5, 0.5); // Gray color for Totoro
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.24 * cos(theta), 0.25 * sin(theta) + 0.2); // Adjusted size and position for the head
        }
        glEnd();

        // Belly
        glColor3f(1.0, 1.0, 0.8); // Light yellow color for Totoro's belly
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.12 * cos(theta) - 0.24, 0.3 * sin(theta) - 0.28); // Adjusted size and position for the belly
        }
        glEnd();

        // Strip 1
        glColor3f(0.0, 0.0, 0.0); // Black color for Totoro's strips
        glBegin(GL_QUADS);
        glVertex2f(-0.29 + 0.015 - 0.03, -0.1);  // Bottom left (-0.05 - 0.3, -0.22 - 0.2)
        glVertex2f(-0.25 + 0.025 - 0.03, -0.06);   // Top middle (0.0 - 0.3, -0.16 - 0.2)
        glVertex2f(-0.2 - 0.03, -0.12);  // Bottom right (0.05 - 0.3, -0.22 - 0.2)
        glVertex2f(-0.25 + 0.015 - 0.03, -0.09);    // Center (0 - 0.3, -0.2 - 0.2)
        glEnd();

        // Whiskers
        glColor3f(0.0, 0.0, 0.0); // Black color for Totoro's whiskers
        glBegin(GL_LINES);

        // Right whiskers 
        glVertex2f(0.3 - 0.37, 0.0 + 0.22);     // Right whisker 1
        glVertex2f(0.5 - 0.37, 0.1 + 0.22);
        glVertex2f(0.3 - 0.37, -0.03 + 0.22);   // Right whisker 2
        glVertex2f(0.5 - 0.37, 0.0 + 0.22);
        glVertex2f(0.3 - 0.37, -0.06 + 0.22);   // Right whisker 3
        glVertex2f(0.5 - 0.37, -0.1 + 0.22);

        glEnd();



        // Tail
        glColor3f(0.5, 0.5, 0.5);
        glPushMatrix();
        glTranslatef(-0.15, -0.1, 0.0); // Translate to the position of the tail
        glRotatef(-30, 0.0, 0.0, 1.0); // Rotate to slant the tail
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.06 * cos(theta) + 0.6, 0.12 * sin(theta)); // Adjusted size for the tail
        }
        glEnd();
        glPopMatrix();

        // Left Ear
        glColor3f(0.5, 0.5, 0.5); // Gray color for Totoro's ears
        glPushMatrix();
        glTranslatef(-0.1, 0.25, 0.0); // Translate to the position of the left ear, lowered
        glRotatef(10, 0.0, 0.0, 1.0); // Rotate to slant the ear
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.07 * cos(theta) + 0.1, 0.2 * sin(theta) + 0.25); // Adjusted size for the left ear
        }
        glEnd();
        glPopMatrix();

        // Right Ear
        glColor3f(0.5, 0.5, 0.5); // Gray color for Totoro's ears
        glPushMatrix();
        glTranslatef(-0.1, 0.25, 0.0); // Translate to the position of the right ear, lowered
        glRotatef(-10, 0.0, 0.0, 1.0); // Rotate to slant the ear
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.07 * cos(theta) + 0.1, 0.2 * sin(theta) + 0.28); // Adjusted size for the right ear
        }
        glEnd();
        glPopMatrix();

        // Eye
        glColor3f(1.0, 1.0, 1.0); // White color for Totoro's eye
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.06 * cos(theta) - 0.14, 0.06 * sin(theta) + 0.25); // Adjusted size and position for the eye
        }
        glEnd();

        // Pupil
        glColor3f(0.0, 0.0, 0.0); // Black color for Totoro's pupil
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.023 * cos(theta) - 0.17, 0.023 * sin(theta) + 0.25); // Adjusted size and position for the pupil
        }
        glEnd();

        // Nose
        glColor3f(0.0, 0.0, 0.0); // Black color for Totoro's nose
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.028 * cos(theta) - 0.24, 0.017 * sin(theta) + 0.19); // Adjusted size and position for the nose
        }
        glEnd();

        // Right Arm (swinging)
        drawRightArm();

        // Animate feet
        drawAnimatedFeet();

        glPopMatrix();
    }

    void drawRightArm() {
        float rightArmAngles[6] = { -30, -15, 0, 15, 30, 15 }; // Swinging angles
        int positionIndex = frame % 6; // Loop through frames 0 to 5
        float rightArmAngle = rightArmAngles[positionIndex];

        glColor3f(0.45, 0.45, 0.45);
        glPushMatrix();
        glTranslatef(0.14, -0.22, 0.0); // Adjusted translation to the pivot point of the right arm (higher and slightly to the left)
        glRotatef(rightArmAngle, 0.0, 0.0, 1.0); // Rotate to swing the arm
        glTranslatef(0.0, -0.08, 0.0); // Translate down to the center of the arm
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.08 * cos(theta), 0.16 * sin(theta)); // Adjusted size for the right arm
        }
        glEnd();
        glPopMatrix();
    }

    void drawAnimatedFeet() {
        float leftFootPositionsX[6] = { 0.0f, -0.05f, -0.1f, -0.15f, -0.1f, -0.05f };
        float rightFootPositionsX[6] = { -0.15f, -0.1f, -0.05f, 0.0f, -0.05f, -0.1f };

        float leftFootPositionsY[6] = { 0.0f, 0.05f, 0.1f, 0.05f, 0.0f, -0.05f };
        float rightFootPositionsY[6] = { 0.05f, 0.0f, -0.05f, 0.0f, 0.05f, 0.1f };

        float leftFootAngles[6] = { 0, 20, 40, 20, 0, -20 };
        float rightFootAngles[6] = { -20, 0, 20, 40, 20, 0 };

        int positionIndex = frame % 6; // Loop through frames 0 to 5

        float leftFootPositionX = leftFootPositionsX[positionIndex];
        float rightFootPositionX = rightFootPositionsX[positionIndex];

        float leftFootPositionY = leftFootPositionsY[positionIndex];
        float rightFootPositionY = rightFootPositionsY[positionIndex];

        float leftFootAngle = leftFootAngles[positionIndex];
        float rightFootAngle = rightFootAngles[positionIndex];

        // Left Foot
        glColor3f(0.45, 0.45, 0.45);
        glPushMatrix();
        glTranslatef(-0.1f + leftFootPositionX, -0.65f + leftFootPositionY, 0.0f); // Translate left foot
        glRotatef(leftFootAngle, 0.0, 0.0, 1.0); // Rotate to animate the foot
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.12f * cos(theta), 0.06f * sin(theta)); // Adjusted size for the left foot
        }
        glEnd();
        glPopMatrix();

        // Right Foot
        glPushMatrix();
        glTranslatef(0.1f + rightFootPositionX, -0.65f + rightFootPositionY, 0.0f); // Translate right foot
        glRotatef(rightFootAngle, 0.0, 0.0, 1.0); // Rotate to animate the foot
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(0.12f * cos(theta), 0.06f * sin(theta)); // Adjusted size for the right foot
        }
        glEnd();
        glPopMatrix();
    }

    void updateFrame() {
        frame++;
    }
};

#endif // TOTORO_H
