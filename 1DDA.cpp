/*
g++ -o 1DDA 1DDA.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
1DDA.exe
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

    int steps = abs(dy) > abs(dx) ? abs(dy) : abs(dx);

    float xstep = (float)dx / (float)steps;
    float ystep = (float)dy / (float)steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++)
    {
        int xtemp = round(x);
        int ytemp = round(y);

        putpixel(xtemp, ytemp, RED);
        delay(100);

        x += xstep;
        y += ystep;
    }
    
    closegraph();
    return 0;
}
