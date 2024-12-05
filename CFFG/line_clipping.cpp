// 200 200 500 500
// 150 150 350 350
#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

static int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8, xl, yl, xh, yh;

// Function to get the outcode based on point (x, y)
int getcode(int x, int y) {
    int code = 0;
    // Perform bitwise OR to get outcode
    if (y > yh) code |= TOP;
    if (y < yl) code |= BOTTOM;
    if (x < xl) code |= LEFT;
    if (x > xh) code |= RIGHT;
    return code;
}

int main() {
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, NULL);
    setcolor(BLUE);

    // Get the bottom-left and top-right coordinates of the window
    cout << "Enter bottom left and top right coordinates of window: ";
    cin >> xl >> yl >> xh >> yh;

    // Draw the rectangle representing the clipping window
    rectangle(xl, yl, xh, yh);

    int x1, y1, x2, y2;
    // Get the endpoints of the line
    cout << "Enter the endpoints of the line: ";
    cin >> x1 >> y1 >> x2 >> y2;

    // Draw the original line (before clipping)
    setcolor(RED);  // Set the color to red for the original line
    line(x1, y1, x2, y2);

    int outcode1 = getcode(x1, y1), outcode2 = getcode(x2, y2);
    int accept = 0;  // Decides if line is to be drawn

    // If both points are inside the window, accept the line
    if (outcode1 == 0 && outcode2 == 0) {
        accept = 1;
    }
    // If the AND of both outcodes is non-zero, the line is completely outside the window
    else if ((outcode1 & outcode2) != 0) {
        accept = 0;
    } else {
        float m;  // Slope of the line
        int x, y;
        while (true) {
            // Calculate slope (handle vertical line case where x1 == x2)
            if (x2 != x1) {
                m = (float)(y2 - y1) / (x2 - x1);
            }

            // Choose the outcode that is not 0 (meaning outside the window)
            int temp;
            if (outcode1 == 0)
                temp = outcode2;
            else
                temp = outcode1;

            // Line clips top edge
            if (temp & TOP) {
                x = x1 + (yh - y1) / m;
                y = yh;
            }
            // Line clips bottom edge
            else if (temp & BOTTOM) {
                x = x1 + (yl - y1) / m;
                y = yl;
            }
            // Line clips left edge
            else if (temp & LEFT) {
                x = xl;
                y = y1 + m * (xl - x1);
            }
            // Line clips right edge
            else if (temp & RIGHT) {
                x = xh;
                y = y1 + m * (xh - x1);
            }

            // Update the point coordinates based on which outcode was selected
            if (temp == outcode1) {
                x1 = x;
                y1 = y;
                outcode1 = getcode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                outcode2 = getcode(x2, y2);
            }

            // Exit the loop if both points are inside the window
            if (outcode1 == 0 && outcode2 == 0) {
                accept = 1;
                break;
            }
            // Exit the loop if both outcodes are non-zero (line is outside)
            else if ((outcode1 & outcode2) != 0) {
                accept = 0;
                break;
            }
        }
    }

    // Set color for the final output
    setcolor(WHITE);
    cout << "After clipping: ";

    // If line is accepted, draw it
    if (accept) {
        line(x1, y1, x2, y2);
    } else {
        cout << "Line is outside the window and rejected.";
    }

    // Wait for user input before closing
    getch();
    closegraph();
    return 0;
}
