#include<bits/stdc++.h>
#include<graphics.h>
#include<conio.h>

using namespace std;

int main() {
    int gDriver = DETECT;
    int gMode;

    // Initialize graphics mode
    initgraph(&gDriver, &gMode, "");

    // Define the initial rectangle points and the translation vector
    int P[2][2] = { {50, 50}, {150, 150} };
    int T[] = {20, 50}; // Translation vector

    // Set color for the first rectangle
    setcolor(WHITE);

    // Draw the first rectangle
    rectangle(P[0][0], P[0][1], P[1][0], P[1][1]);

    // Apply translation to the points
    P[0][0] += T[0];  // Translate x1
    P[0][1] += T[1];  // Translate y1
    P[1][0] += T[0];  // Translate x2
    P[1][1] += T[1];  // Translate y2

    // Set color for the translated rectangle
    setcolor(GREEN);

    // Draw the translated rectangle
    rectangle(P[0][0], P[0][1], P[1][0], P[1][1]);

    // Wait for the user to press a key
    getch();

    // Close the graphics mode
    closegraph();

    return 0;
}

