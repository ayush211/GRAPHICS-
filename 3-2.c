#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void bresenhamLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        putpixel(x1, y1, WHITE);

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
    int x1, y1, x2, y2;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter top-left corner (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter bottom-right corner (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    // Draw rectangle using 4 lines
    bresenhamLine(x1, y1, x2, y1); // Top
    bresenhamLine(x2, y1, x2, y2); // Right
    bresenhamLine(x2, y2, x1, y2); // Bottom
    bresenhamLine(x1, y2, x1, y1); // Left

    getch();
    closegraph();
    return 0;
}