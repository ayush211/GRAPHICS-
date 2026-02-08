#include <graphics.h>
#include <conio.h>
#include <math.h>

void main()
{
    int gd = DETECT, gm;
    int x1 = 100, y1 = 100, x2 = 300, y2 = 200;
    float dx, dy, steps, x, y;
    int i;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    dx = x2 - x1;
    dy = y2 - y1;

    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    dx = dx / steps;
    dy = dy / steps;

    x = x1;
    y = y1;

    for (i = 0; i <= steps; i++)
    {
        putpixel(x, y, WHITE);
        x += dx;
        y += dy;
    }

    getch();
    closegraph();
}
