#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void drawEllipse(int xc, int yc, int rx, int ry)
{
    float dx, dy, d1, d2, x, y;
    int color = 1;   // start color

    x = 0;
    y = ry;

    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    // Region 1
    while (dx < dy)
    {
        // change color dynamically
        setcolor(color);
        color = (color + 1) % 15;
        if (color == 0) color = 1;

        putpixel(xc + x, yc + y, color);
        putpixel(xc - x, yc + y, color);
        putpixel(xc + x, yc - y, color);
        putpixel(xc - x, yc - y, color);

        if (d1 < 0)
        {
            x++;
            dx += 2 * ry * ry;
            d1 += dx + ry * ry;
        }
        else
        {
            x++;
            y--;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            d1 += dx - dy + ry * ry;
        }
    }

    d2 = (ry * ry * (x + 0.5) * (x + 0.5)) +
         (rx * rx * (y - 1) * (y - 1)) -
         (rx * rx * ry * ry);

    // Region 2
    while (y >= 0)
    {
        setcolor(color);
        color = (color + 1) % 15;
        if (color == 0) color = 1;

        putpixel(xc + x, yc + y, color);
        putpixel(xc - x, yc + y, color);
        putpixel(xc + x, yc - y, color);
        putpixel(xc - x, yc - y, color);

        if (d2 > 0)
        {
            y--;
            dy -= 2 * rx * rx;
            d2 += rx * rx - dy;
        }
        else
        {
            y--;
            x++;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            d2 += dx - dy + rx * rx;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    int xc, yc, rx, ry;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter center (xc, yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter radii (rx ry): ");
    scanf("%d %d", &rx, &ry);

    drawEllipse(xc, yc, rx, ry);

    getch();
    closegraph();
    return 0;
}