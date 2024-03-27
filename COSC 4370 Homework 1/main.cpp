#include <iostream>
#include "BMP.h"
#include <cmath>
using namespace std;

//duplicates arc using symetry
void writeEllipse(int x, int y, int xc, int yc, struct BMP *bmpNew) {
    bmpNew->set_pixel(x + xc, y + yc, 255, 255, 255, 255); // White ellipse
    bmpNew->set_pixel(-x + xc, y + yc, 255, 255, 255, 255);
    bmpNew->set_pixel(x + xc, -y + yc, 255, 255, 255, 255);
    bmpNew->set_pixel(-x + xc, -y + yc, 255, 255, 255, 255);
}

// Function to rasterize ellipse using midpoint algorithm
void midpointEllipse(int a, int b, struct BMP *bmpNew) {
    int x = 0;
    int y = b;
    double d1 = pow(b, 2) - pow(a, 2) * b + 0.25 * pow(a, 2);
    int dx = 2 * pow(b, 2) * x;
    int dy = 2 * pow(a, 2) * y;

    // Region 1
    while (dx < dy) {
        writeEllipse(x, y, a, b, bmpNew);

        if (d1 < 0) {
            x++;
            dx += 2 * pow(b, 2);
            d1 += dx + pow(b, 2);
        } else {
            x++;
            y--;
            dx += 2 * pow(b, 2);
            dy -= 2 * pow(a, 2);
            d1 += dx - dy + pow(b, 2);
        }
    }

    // Region 2
    double d2 = pow(b, 2) * pow(x + 0.5, 2) + pow(a, 2) * pow(y - 1, 2) - pow(a, 2) * pow(b, 2);
    while (y >= 0) {
        writeEllipse(x, y, a, b, bmpNew);

        if (d2 > 0) {
            y--;
            dy -= 2 * pow(a, 2);
            d2 += pow(a, 2) - dy;
        } else {
            y--;
            x++;
            dx += 2 * pow(b, 2);
            dy -= 2 * pow(a, 2);
            d2 += dx - dy + pow(a, 2);
        }
    }
}

int main() {
    int a = 400;
    int b = 200;
    BMP bmpNew(a * 2 + 1, b * 2 + 1, false);
    bmpNew.fill_region(0, 0, 200, 200, 0, 0, 0, 0); // Black background

    midpointEllipse(a, b, &bmpNew);

    int radius = 200; 

    for (int angle = 0; angle <= 90; angle++) {
        int x = a + radius * cos(angle * M_PI / 180);
        int y = b + radius * sin(angle * M_PI / 180);

        bmpNew.set_pixel(x, y, 0, 0, 255, 255);
    }

    for (int angle = 0; angle >= -90; angle--) {
        int x = a + radius * cos(angle * M_PI / 180);
        int y = b + radius * sin(angle * M_PI / 180);

        bmpNew.set_pixel(x, y, 0, 0, 255, 255);
    }
  
    bmpNew.write("output.bmp");

    return 0;
}