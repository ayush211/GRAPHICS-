#include <graphics.h>
#include <conio.h>

void main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    line(100, 200, 400, 200);   // Horizontal
    line(250, 100, 250, 350);   // Vertical

    getch();
    closegraph();
}
