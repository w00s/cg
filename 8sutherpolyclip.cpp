#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

int xmin, xmax, ymin, ymax;
int n;
int p[100][2];

int l_p[100][2]; // after left clipping
int r_p[100][2]; // after right clipping

int t_p[100][2]; // after top clipping
int b_p[100][2]; // after bottom clipping

int nl = 0;
int nr = 0;

int nt = 0;
int nb = 0;

int i;

void left()
{
    for (i = 0; i < n; i++)
    {
        // case 1 : outside to outside      store nothing
        // case 2 : outside to inside       store intersection and inner point
        // case 3 : inside to inside        store destination
        // case 4 : inside to outside       store intersection

        float slope = (float)(p[i + 1][1] - p[i][1]) / (float)(p[i + 1][0] - p[i][0]);

        // out to in
        if (p[i][0] < xmin && p[i + 1][0] > xmin)
        {
            // store intersection

            l_p[nl][0] = xmin;
            l_p[nl][1] = p[i][1] + (float)(xmin - p[i][0]) * slope;

            // store inner point

            l_p[nl + 1][0] = p[i + 1][0];
            l_p[nl + 1][1] = p[i + 1][1];

            nl++;
            nl++;
        }

        // in to in
        else if (p[i][0] > xmin && p[i + 1][0] > xmin)
        {
            // store destination
            l_p[nl][0] = p[i + 1][0];
            l_p[nl][1] = p[i + 1][1];
            nl++;
        }

        // in to out
        else if (p[i][0] > xmin && p[i + 1][0] < xmin)
        {
            // store intersection
            l_p[nl][0] = xmin;
            l_p[nl][1] = p[i][1] + (float)(xmin - p[i][0]) * slope;
            nl++;
        }
        else
        {
            continue;
        }
    }
    l_p[nl][0] = l_p[0][0];
    l_p[nl][1] = l_p[0][1];
}

void right()
{
    for (i = 0; i < nl; i++)
    {
        // case 1 : outside to outside store nothing
        // case 2 : outside to inside    store intersection and inner point
        // case 3 : inside to inside        store destination
        // case 4 : inside to outside        store intersection

        float slope = (float)(l_p[i + 1][1] - l_p[i][1]) / (float)(l_p[i + 1][0] - l_p[i][0]);

        // out to in
        if (l_p[i][0] > xmax && l_p[i + 1][0] < xmax)
        {
            // store intersection

            r_p[nr][0] = xmax;
            r_p[nr][1] = l_p[i][1] + (float)(xmax - l_p[i][0]) * slope;

            // store inner point

            r_p[nr + 1][0] = l_p[i + 1][0];
            r_p[nr + 1][1] = l_p[i + 1][1];

            nr++;
            nr++;
        }

        // in to in
        else if (l_p[i][0] < xmax && l_p[i + 1][0] < xmax)
        {
            // store destination
            r_p[nr][0] = l_p[i + 1][0];
            r_p[nr][1] = l_p[i + 1][1];
            nr++;
        }

        // in to out
        else if (l_p[i][0] < xmax && l_p[i + 1][0] > xmax)
        {
            // store intersection
            r_p[nr][0] = xmax;
            r_p[nr][1] = l_p[i][1] + (float)(xmax - l_p[i][0]) * slope;
            nr++;
        }
        else
        {
            continue;
        }
    }
    r_p[nr][0] = r_p[0][0];
    r_p[nr][1] = r_p[0][1];
}

void top()
{
    for (i = 0; i < nr; i++)
    {
        // case 1 : outside to outside store nothing
        // case 2 : outside to inside    store intersection and inner point
        // case 3 : inside to inside        store destination
        // case 4 : inside to outside        store intersection

        float slope = (float)(r_p[i + 1][1] - r_p[i][1]) / (float)(r_p[i + 1][0] - r_p[i][0]);

        // out to in
        if (r_p[i][1] > ymax && r_p[i + 1][1] < ymax)
        {
            // store intersection

            t_p[nt][0] = r_p[i][0] + (float)(ymax - r_p[i][1]) / slope;
            t_p[nt][1] = ymax;

            // store inner point

            t_p[nt + 1][0] = r_p[i + 1][0];
            t_p[nt + 1][1] = r_p[i + 1][1];

            nt++;
            nt++;
        }

        // in to in
        else if (r_p[i][1] < ymax && r_p[i + 1][1] < ymax)
        {
            // store destination
            t_p[nt][0] = r_p[i + 1][0];
            t_p[nt][1] = r_p[i + 1][1];
            nt++;
        }

        // in to out
        else if (r_p[i][1] < ymax && r_p[i + 1][0] > ymax)
        {
            // store intersection
            t_p[nt][0] = r_p[i][0] + (float)(ymax - r_p[i][1]) / slope;
            t_p[nt][1] = ymax;
            nt++;
        }
        else
        {
            continue;
        }
    }
    t_p[nt][0] = t_p[0][0];
    t_p[nt][1] = t_p[0][1];
}

void bottom()
{
    for (i = 0; i < nt; i++)
    {
        // case 1 : outside to outside store nothing
        // case 2 : outside to inside    store intersection and inner point
        // case 3 : inside to inside        store destination
        // case 4 : inside to outside        store intersection

        float slope = (float)(t_p[i + 1][1] - t_p[i][1]) / (float)(t_p[i + 1][0] - t_p[i][0]);

        // out to in
        if (t_p[i][1] < ymin && t_p[i + 1][1] > ymin)
        {
            // store intersection

            b_p[nb][0] = t_p[i][0] + (float)(ymin - t_p[i][1]) / slope;
            b_p[nb][1] = ymin;

            // store inner point

            b_p[nb + 1][0] = t_p[i + 1][0];
            b_p[nb + 1][1] = t_p[i + 1][1];

            nb++;
            nb++;
        }

        // in to in
        else if (t_p[i][1] > ymin && t_p[i + 1][1] > ymin)
        {
            // store destination
            b_p[nb][0] = t_p[i + 1][0];
            b_p[nb][1] = t_p[i + 1][1];
            nb++;
        }

        // in to out
        else if (t_p[i][1] > ymin && t_p[i + 1][0] < ymin)
        {
            // store intersection
            b_p[nb][0] = t_p[i][0] + (float)(ymin - t_p[i][1]) / slope;
            b_p[nb][1] = ymin;
            nb++;
        }
        else
        {
            continue;
        }
    }
    b_p[nb][0] = b_p[0][0];
    b_p[nb][1] = b_p[0][1];
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    cout << "Enter xmin, xmax, ymin, ymax    :   ";
    cin >> xmin >> xmax >> ymin >> ymax;

    setcolor(WHITE);
    line(xmin, ymin, xmin, ymax);
    line(xmin, ymax, xmax, ymax);
    line(xmax, ymax, xmax, ymin);
    line(xmax, ymin, xmin, ymin);

    cout << "Enter n   :   ";
    cin >> n;

    // n 4 0 1 2 3 0 1 2 3 4 5 6 7 x y x y x y x y

    for (i = 0; i < n; i++)
    {
        cout << "Enter (x, y) for Point " << i << " :  ";
        cin >> p[i][0] >> p[i][1];
    }
    p[n][0] = p[0][0];
    p[n][1] = p[0][1];

    for (i = 0; i < n; i++)
    {
        line(p[i][0], p[i][1], p[i + 1][0], p[i + 1][1]);
    }

    int choice;

    cout << "Enter any key to clip";
    cin >> choice;

    left();
    right();
    top();
    bottom();

    // top clipping

    // bottom clipping

    //-------------

    cleardevice();

    setcolor(WHITE);
    line(xmin, ymin, xmin, ymax);
    line(xmin, ymax, xmax, ymax);
    line(xmax, ymax, xmax, ymin);
    line(xmax, ymin, xmin, ymin);

    setcolor(GREEN);

    for (i = 0; i < nb; i++)
    {
        line(b_p[i][0], b_p[i][1], b_p[i + 1][0], b_p[i + 1][1]);
    }

    cout << "Enter any key to exit";
    cin >> choice;

    getch();
    return 0;
}

// polygon cliiping
/*

g++ -o polyfinal polyfinal.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
polyfinal.exe
200 400 200 400
4
150 250
150 350
450 350
450 250


*/

/*

g++ -o polyfinal polyfinal.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
polyfinal.exe
200 400 200 400


3
150 300
450 350
450 250


*/
