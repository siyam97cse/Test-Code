// Input 200 200 200 100 100 200
// angle 20
#include<bits/stdc++.h>
#include<graphics.h>
#include<math.h>

using namespace std;

int main()
{
    // Initialize the graphics driver and mode
    int gDriver = DETECT, gMode;      // DETECT is a macro that automatically detects the appropriate graphics driver
    initgraph(&gDriver, &gMode, "");  // Initializes the graphics mode with the detected driver and mode

    // Declare variables to store the coordinates of the triangle and for angle calculations
    int x1, y1, x2, y2, x3, y3;      // Coordinates of the triangle's vertices
    double c, s, angle;               // Variables for cosine (c), sine (s), and the angle of rotation

    // Input the coordinates of the 3 vertices of the triangle
    cout<<"Enter coordinate values : ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // Draw the triangle by connecting the 3 vertices with lines
    line(x1, y1, x2, y2);  // Draw line between (x1, y1) and (x2, y2)
    line(x2, y2, x3, y3);  // Draw line between (x2, y2) and (x3, y3)
    line(x3, y3, x1, y1);  // Draw line between (x3, y3) and (x1, y1)

    // Prompt the user to input the rotation angle in degrees
    cout << "Enter angle : ";
    cin >> angle;
    // Convert the angle from degrees to radians
    c = cos(angle * M_PI / 180);
    s = sin(angle * M_PI / 180);

    // Apply the 2D rotation transformation to each vertex of the triangle
    // The rotation matrix formula for a point (x, y) is:
    // [ x' ] = [ c  -s ] * [ x ]
    // [ y' ]   [ s   c ]   [ y ]
    x1 = floor(x1 * c + y1 * s);  // New x1 = x1*cos(angle) + y1*sin(angle)
    y1 = floor(-x1 * s + y1 * c); // New y1 = -x1*sin(angle) + y1*cos(angle)

    x2 = floor(x2 * c + y2 * s);  // New x2 = x2*cos(angle) + y2*sin(angle)
    y2 = floor(-x2 * s + y2 * c); // New y2 = -x2*sin(angle) + y2*cos(angle)

    x3 = floor(x3 * c + y3 * s);  // New x3 = x3*cos(angle) + y3*sin(angle)
    y3 = floor(-x3 * s + y3 * c); // New y3 = -x3*sin(angle) + y3*cos(angle)

    // Draw the rotated triangle with the new coordinates
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    getch();  // Wait for a key press (from the user) to continue

    closegraph();
}
