#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

void main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    float dx, dy, steps, x, y;
    int i;

    printf("Enter x1 y1: ");
    scanf("%d%d", &x1, &y1);
    printf("Enter x2 y2: ");
    scanf("%d%d", &x2, &y2);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    dx = x2 - x1;
    dy = y2 - y1;

    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    dx /= steps;
    dy /= steps;

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
