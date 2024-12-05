#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void findNewCordinates(int s[2][2], int p[2][1])
{
    int temp[2][1] = {0};  // Temporary array to store the result of matrix multiplication

    // Perform matrix multiplication: temp = s * p (scaling transformation)
    for(int i = 0; i < 2; i++)      // Loop over the rows of the scaling matrix
        for(int j = 0; j < 1; j++)  // Loop over the columns of the point matrix (always 1 column)
            for(int k = 0; k < 2; k++)  // Loop for the inner product (columns of s * rows of p)
                temp[i][j] = temp[i][j] + (s[i][k] * p[k][j]);  // Matrix multiplication logic

    // Store the result of the multiplication back into the point array p
    p[0][0] = temp[0][0];
    p[1][0] = temp[1][0];
}

void scale(int x[], int y[], int sx, int sy)
{
    // Draw the original triangle using the input vertices
    line(x[0], y[0], x[1], y[1]);  // Draw line between (x0, y0) and (x1, y1)
    line(x[1], y[1], x[2], y[2]);  // Draw line between (x1, y1) and (x2, y2)
    line(x[2], y[2], x[0], y[0]);  // Draw line between (x2, y2) and (x0, y0)

    // Define the scaling matrix [2x2] for scaling transformation
    int s[2][2] = {sx, 0, 0, sy};  // Scaling matrix with sx and sy scaling factors for x and y respectively
    int p[2][1];                   // Array to store the coordinates of each vertex (2x1 column vector)

    // Apply scaling to each of the triangle's vertices
    for(int i = 0; i < 3; i++)  // Loop over each vertex of the triangle
    {
        p[0][0] = x[i];  // Set the x-coordinate of the vertex in the point array
        p[1][0] = y[i];  // Set the y-coordinate of the vertex in the point array

        // Call the findNewCordinates function to apply the scaling transformation to the vertex
        findNewCordinates(s, p);

        // Update the coordinates of the vertex with the new scaled coordinates
        x[i] = p[0][0];
        y[i] = p[1][0];
    }

    // Draw the scaled triangle using the new coordinates
    line(x[0], y[0], x[1], y[1]);  // Draw line between (x0', y0') and (x1', y1')
    line(x[1], y[1], x[2], y[2]);  // Draw line between (x1', y1') and (x2', y2')
    line(x[2], y[2], x[0], y[0]);  // Draw line between (x2', y2') and (x0', y0')
}

int main()
{
    int gDriver = DETECT;  // Automatically detect the graphics driver
    int gMode;             // Variable to store the graphics mode

    // Initialize the graphics mode
    initgraph(&gDriver, &gMode, "");  // Start the graphics system with the detected driver and mode

    // Define the coordinates of the triangle vertices
    int x[] = {100, 200, 300};  // x-coordinates of the triangle vertices
    int y[] = {200, 100, 200};  // y-coordinates of the triangle vertices

    // Define the scaling factors for the x and y axes (sx, sy)
    int sx = 2, sy = 2;  // Scaling factor: 2x for x-axis and 2x for y-axis

    // Call the scale function to apply scaling to the triangle
    scale(x, y, sx, sy);
        getch();
    closegraph();
}

