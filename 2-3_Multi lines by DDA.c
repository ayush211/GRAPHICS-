#include <graphics.h>
#include <conio.h>
#include <math.h>

void main()
{
    int gd = DETECT, gm;
    float dx, dy, steps, x, y;
    int i;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Line 1
    dx = 300 - 100;
    dy = 100 - 100;
    steps = abs(dx);
    dx /= steps; dy /= steps;
    x = 100; y = 100;
    for (i = 0; i <= steps; i++) { putpixel(x, y, WHITE); x += dx; y += dy; }

    // Line 2
    dx = 300 - 300;
    dy = 300 - 100;
    steps = abs(dy);
    dx /= steps; dy /= steps;
    x = 300; y = 100;
    for (i = 0; i <= steps; i++) { putpixel(x, y, WHITE); x += dx; y += dy; }

    // Line 3
    dx = 100 - 300;
    dy = 300 - 300;
    steps = abs(dx);
    dx /= steps; dy /= steps;
    x = 300; y = 300;
    for (i = 0; i <= steps; i++) { putpixel(x, y, WHITE); x += dx; y += dy; }

    // Line 4
    dx = 100 - 100;
    dy = 100 - 300;
    steps = abs(dy);
    dx /= steps; dy /= steps;
    x = 100; y = 300;
    for (i = 0; i <= steps; i++) { putpixel(x, y, WHITE); x += dx; y += dy; }

    getch();
    closegraph();
}
