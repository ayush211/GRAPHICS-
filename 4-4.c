#include <graphics.h>
#include <stdio.h>
#include <conio.h>

// Function to draw a horizontal line
void drawLine(int x1, int x2, int y)
{
    while (x1 <= x2)
    {
        putpixel(x1, y, WHITE);
        x1++;
    }
}

void drawFilledCircle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int p = 1 - r;

    while (x <= y)
    {
        // Fill using horizontal lines between symmetric points
        drawLine(xc - x, xc + x, yc + y);
        drawLine(xc - x, xc + x, yc - y);
        drawLine(xc - y, xc + y, yc + x);
        drawLine(xc - y, xc + y, yc - x);

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
    int xc, yc, r;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter center (xc, yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter radius: ");
    scanf("%d", &r);

    drawFilledCircle(xc, yc, r);

    getch();
    closegraph();
    return 0;
}