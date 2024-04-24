/*
g++ -o 5midptellipse 5midptellipse.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
5midptellipse.exe

*/

#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

void midptellipse(int rx, int ry, int xc, int yc)
{
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;

    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    // REGION 1
    while (dx < dy)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }

    // REGION 2
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);

    while (y >= 0)
    {

        putpixel(xc + x, yc + y, BLUE);
        putpixel(xc - x, yc + y, BLUE);
        putpixel(xc + x, yc - y, BLUE);
        putpixel(xc - x, yc - y, BLUE);

        if (d2 > 0)
        {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int cx, cy, rx, ry;
    cout << "Enter center (x, y) " << endl;
    cin >> cx >> cy;

    cout << "Enter rx and ry" << endl;
    cin >> rx >> ry;

    midptellipse(rx, ry, cx, cy);

    getch();
    return 0;
}