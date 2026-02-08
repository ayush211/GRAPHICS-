#include <graphics.h>
#include <conio.h>

void main()
{
    int gd = DETECT, gm;
    int x, y;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    x = getmaxx() / 2;
    y = getmaxy() / 2;

    circle(x, y, 100);

    getch();
    closegraph();
}
