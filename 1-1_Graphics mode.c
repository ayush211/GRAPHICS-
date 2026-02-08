#include <graphics.h>
#include <conio.h>

void main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    outtextxy(200, 200, "Graphics Mode Initialized");

    getch();
    closegraph();
}

