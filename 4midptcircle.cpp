/*
g++ -o 4midptcircle 4midptcircle.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
4midptcircle.exe

*/

#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;


void plot(int cx, int cy, int x, int y)
{
    putpixel(cx + x, cy + y, WHITE);
    putpixel(cx - x, cy + y, WHITE);
    putpixel(cx + x, cy - y, WHITE);
    putpixel(cx - x, cy - y, WHITE);
    putpixel(cx + y, cy + x, WHITE);
    putpixel(cx - y, cy + x, WHITE);
    putpixel(cx + y, cy - x, WHITE);
    putpixel(cx - y, cy - x, WHITE);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int cx, cy, r;
    cout << "Enter center (x, y) and the radius" << endl;
    cin >> cx >> cy >> r;

    int x = 0;
    int y = r;

    int p = 1 - r;
    plot(cx, cy, x, y);

    while (x < y)
    {
        x++;
        if (p < 0)
        {
            p = p + 2 * x + 1;
        }
        else
        {
            y--;
            p = p + 2 * (x - y) + 1;
        }
        plot(cx, cy, x, y);
    }

    getch();
    return 0;
}