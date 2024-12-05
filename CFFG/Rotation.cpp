// 2D Rotation about the origin
// Angle 70 degrees

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void rotation() {
    float theta;
    int rot[4][2] = { {0, 0}, {10, 50}, {70, 50}, {0, 0} };  // Coordinates of the shape
    int i, x_new, y_new;

    // Draw the original shape (a polygon)
    setcolor(BLUE);
    for (i = 0; i < 3; i++) {
        line(320 + rot[i][0], 240 - rot[i][1], 320 + rot[i+1][0], 240 - rot[i+1][1]);
    }

    // Input rotation angle in degrees
    printf("Enter rotation in degrees: ");
    scanf("%f", &theta);
    theta = theta * M_PI / 180;  // Convert degrees to radians

    // Rotate the shape's points
    for (i = 0; i < 4; i++) {
        x_new = (int)(rot[i][0] * cos(theta) - rot[i][1] * sin(theta));
        y_new = (int)(rot[i][0] * sin(theta) + rot[i][1] * cos(theta));
        rot[i][0] = x_new;
        rot[i][1] = y_new;
    }

    // Draw the rotated shape
    setcolor(RED);
    for (i = 0; i < 3; i++) {
        line(320 + rot[i][0], 240 - rot[i][1], 320 + rot[i+1][0], 240 - rot[i+1][1]);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");  // Initialize graphics mode
    cleardevice();  // Clear screen
    line(0, 240, 640, 240);  // Draw horizontal axis
    line(320, 0, 320, 480);  // Draw vertical axis

    rotation();  // Call the rotation function

    getch();  // Wait for user input
    closegraph();  // Close graphics mode
    return 0;
}
