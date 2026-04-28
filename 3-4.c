#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void bresenhamLine(int x1, int y1, int x2, int y2, int color)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        putpixel(x1, y1, color);  // use chosen color

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err = err - dy;
            x1 = x1 + sx;
        }

        if (e2 < dx)
        {
            err = err + dx;
            y1 = y1 + sy;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    int color;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter three vertices of triangle:\n");
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);

    printf("Enter color (0-15): ");
    scanf("%d", &color);

    // Draw triangle with chosen color
    bresenhamLine(x1, y1, x2, y2, color);
    bresenhamLine(x2, y2, x3, y3, color);
    bresenhamLine(x3, y3, x1, y1, color);

    getch();
    closegraph();
    return 0;
}