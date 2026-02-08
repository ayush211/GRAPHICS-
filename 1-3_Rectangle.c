#include <graphics.h>
#include <conio.h>

void main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    rectangle(150, 100, 400, 300);

    getch();
    closegraph();
}
