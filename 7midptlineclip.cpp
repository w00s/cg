/*
g++ -o 7midptlineclip 7midptlineclip.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
7midptlineclip.exe

*/

#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

typedef struct coordinate
{
    int x, y;
    char code[4];
} PT;

int visibility(PT p1, PT p2)
{
    int i, flag = 0;
    for (i = 0; i < 4; i++)
    {
        if ((p1.code[i] != '0') || (p2.code[i] != '0'))
            flag = 1;
    }
    if (flag == 0)
        return (0);

    
    for (i = 0; i < 4; i++)
    {
        if ((p1.code[i] == p2.code[i]) && (p1.code[i] == '1'))
            flag = 0;
    }
    if (flag == 0)
        return 1;
    return 2;
}

PT setcode(PT p)
{
    PT ptemp;
    
    if (p.y <= 100)
        ptemp.code[0] = '1';
    else
        ptemp.code[0] = '0';
    if (p.y >= 400)
        ptemp.code[1] = '1';
    else
        ptemp.code[1] = '0';
    if (p.x >= 450)
        ptemp.code[2] = '1';
    else
        ptemp.code[2] = '0';
    if (p.x <= 150)
        ptemp.code[3] = '1';
    else
        ptemp.code[3] = '0';
    ptemp.x = p.x;
    ptemp.y = p.y;
    return ptemp;
}

void drawwindow()
{
    setcolor(RED);
    line(150, 100, 450, 100);
    line(450, 100, 450, 400);
    line(450, 400, 150, 400);
    line(150, 400, 150, 100);
}

void drawline(PT p1, PT p2)
{
    setcolor(WHITE);
    line(p1.x, p1.y, p2.x, p2.y);
}

void midsub(PT p1, PT p2)
{
    PT mid;
    int v;
    p1 = setcode(p1);
    p2 = setcode(p2);
    v = visibility(p1, p2);
    switch (v)
    {
    case 0:
        line(p1.x, p1.y, p2.x, p2.y);
        // drawline(p1, p2);
        break;
    case 1:
        break;
    case 2:
        mid.x = p1.x + (p2.x - p1.x) / 2;
        mid.y = p1.y + (p2.y - p1.y) / 2;
        
        midsub(p1, mid);

        mid.x++; 
        mid.y++; 
        
        midsub(mid, p2);
        
        break;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);


    PT p1, p2, ptemp;

    cleardevice();
    cout << "enter point 1:   ";
    cin >> p1.x >> p1.y;

    cout << "enter point 2:   ";
    cin >> p2.x >> p2.y;

    cleardevice();
    drawwindow();
    getch();
    drawline(p1, p2);
    getch();
    cleardevice();
    drawwindow();
    midsub(p1, p2);
    getch();
    closegraph();
    return 0;
}