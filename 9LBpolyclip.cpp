#include <bits/stdc++.h>
#include <graphics.h>
#define ROUND(a) ((int)(a + 0.5))
#define TRUE 1
#define FALSE 0
using namespace std;

/*
g++ -o 9LBpolyclip 9LBpolyclip.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
9LBpolyclip.exe

*/

struct dcPt
{
    int x, y;
};

struct vertex
{
    float x, y;
};


int clipTest(float p, float q, float *t1, float *t2)
{
    float r;
    int retVal = TRUE;
    if (p < 0.0)
    {
        r = q / p;
        if (r > *t2)
            retVal = FALSE;
        else if (r > *t1)
            *t1 = r;
    }
    else if (p > 0.0)
    {
        r = q / p;
        if (r < *t1)
            retVal = FALSE;
        else if (r < *t2)
            *t2 = r;
    }
    else
    {
        if (q < 0.0)
            retVal = FALSE;
    }

    return retVal;
}

void clipLine(dcPt winMin, dcPt winMax, vertex p1, vertex p2)
{
    float t1 = 0.0, t2 = 1.0, dx = p2.x - p1.x, dy;
    if (clipTest(-dx, p1.x - winMin.x, &t1, &t2))
        if (clipTest(dx, winMax.x - p1.x, &t1, &t2))
        {
            dy = p2.y - p1.y;
            if (clipTest(-dy, p1.y - winMin.y, &t1, &t2))
                if (clipTest(dy, winMax.y - p1.y, &t1, &t2))
                {
                    if (t2 < 1.0)
                    {
                        p2.x = p1.x + t2 * dx;
                        p2.y = p1.y + t2 * dy;
                    }

                    if (t1 > 0.0)
                    {
                        p1.x += t1 * dx;
                        p1.y += t1 * dy;
                    }
                    setcolor(WHITE);
                    line(ROUND(p1.x), ROUND(p1.y), ROUND(p2.x), ROUND(p2.y));
                }
        }
}

int main()
{

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int xmin, xmax, ymin, ymax;
    cout << "Enter xmin, xmax, ymin,ymax    : ";
    cin >> xmin >> xmax >> ymin >> ymax;

    // dcPt winMin = {100, 100};
    // dcPt winMax = {500, 400};

    dcPt winMin = {xmin, ymin};
    dcPt winMax = {xmax, ymax};

    setcolor(RED);
    rectangle(winMin.x, winMin.y, winMax.x, winMax.y);

    float x1, y1, x2, y2, x3, y3;
    cout << "Enter x1, y1 : ";
    cin >> x1 >> y1;
    cout << "Enter x2, y2 : ";
    cin >> x2 >> y2;
    cout << "Enter x3, y3 : ";
    cin >> x3 >> y3;

    vertex p1 = {x1, y1}; // Start point
    vertex p2 = {x2, y2};
    vertex p3 = {x3, y3}; // End point

    line(ROUND(p1.x), ROUND(p1.y), ROUND(p2.x), ROUND(p2.y));
    line(ROUND(p2.x), ROUND(p2.y), ROUND(p3.x), ROUND(p3.y));
    line(ROUND(p3.x), ROUND(p3.y), ROUND(p1.x), ROUND(p1.y));

    int choice;
    cout << "enter any key to clip    : ";
    cin >> choice;

    clipLine(winMin, winMax, p1, p2);
    clipLine(winMin, winMax, p2, p3);
    clipLine(winMin, winMax, p3, p1);

    cout << "enter any key to exit    : ";
    cin >> choice;

    closegraph();
    return 0;
}