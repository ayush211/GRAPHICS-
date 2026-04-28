#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void drawCircle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int p = 1 - r;

    while (x <= y)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        x++;

        if (p < 0)
            p = p + 2 * x + 1;
        else
        {
            y--;
            p = p + 2 * (x - y) + 1;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    int xc, yc, r, i;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter center (xc, yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter initial radius: ");
    scanf("%d", &r);

    // Draw 5 concentric circles
    for (i = 0; i < 5; i++)
    {
        drawCircle(xc, yc, r + i * 20);  // increase radius
    }

    getch();
    closegraph();
    return 0;
}