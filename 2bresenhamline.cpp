/*
g++ -o 2bresenhamline 2bresenhamline.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
2bresenhamline.exe

*/

#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1 = 100;
    int y1 = 100;
    int x2 = 500;
    int y2 = 500;

    int dx = x2 - x1;
    int dy = y2 - y1;

    int x = x1;
    int y = y1;
    int p = 2 * dy - dx;

    while (x < x2)
    {
        if (p >= 0)
        {
            putpixel(x, y, WHITE);
            y += 1;
            x += 1;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            putpixel(x, y, WHITE);
            x += 1;
            p = p + 2 * dy;
        }
        delay(100);
    }

    closegraph();
    return 0;
}
