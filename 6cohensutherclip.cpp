/*
g++ -o 6cohensutherclip 6cohensutherclip.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
6cohensutherclip.exe

*/

#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

// Defining region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

void drawboundaries(int x1, int y1, int x2, int y2)
{
    int xmax = x1 > x2 ? x1 : x2;
    int xmin = x1 < x2 ? x1 : x2;

    int ymax = y1 > y2 ? y1 : y2;
    int ymin = y1 < y2 ? y1 : y2;

    line(xmin, ymin, xmax, ymin);
    line(xmin, ymin, xmin, ymax);
    line(xmax, ymin, xmax, ymax);
    line(xmin, ymax, xmax, ymax);
}

int FINDCODE(int xmax, int xmin, int ymax, int ymin, int x, int y)
{
    // inside = 0000
    int code = INSIDE;

    // left = 0001
    if (x < xmin)
        code = code | 1;

    // right = 0010
    else if (x > xmax)
        code = code | 2;

    // below = 0100
    if (y < ymin)
        code = code | 4;

    // top = 1000
    else if (y > ymax) // above the rectangle
        code = code | 8;

    return code;
}

void cohenSutherlandClip(int x1, int y1, int x2, int y2, int a1, int a2, int b1, int b2)
{

    int xmax = x1 > x2 ? x1 : x2;
    int xmin = x1 < x2 ? x1 : x2;

    int ymax = y1 > y2 ? y1 : y2;
    int ymin = y1 < y2 ? y1 : y2;

    // Compute region codes for A, B
    int code1 = FINDCODE(xmax, xmin, ymax, ymin, a1, a2);
    int code2 = FINDCODE(xmax, xmin, ymax, ymin, b1, b2);

    bool accept = false;

    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            //both inside
            accept = true;
            line(a1, a2, b1, b2);
            break;
        }

        else if (code1 & code2)
        {
            // both outside window
            break;
        }

        else
        {
            // partially inside
            int code_out = code1 != 0 ? code1 : code2;
            double x, y;

            
            if (code_out & 8)
            {

                /* Defining region codes
                const int INSIDE = 0; // 0000
                const int LEFT = 1;   // 0001
                const int RIGHT = 2;  // 0010
                const int BOTTOM = 4; // 0100
                const int TOP = 8;    // 1000

                */

                // x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                x = a1 + (b1 - a1) * (ymax - a2) / (b2 - a2);
                y = ymax;
            }

            else if (code_out & 4)
            {
                x = a1 + (b1 - a1) * (ymin - a2) / (b2 - a2);
                y = ymin;
            }

            else if (code_out & 2)
            {

                y = a2 + (b2 - a2) * (xmax - a1) / (b1 - a1);
                x = xmax;
            }

            else if (code_out & 1)
            {
                y = a2 + (b2 - a2) * (xmin - a1) / (b1 - a1);
                x = xmin;
            }

            // Now intersection point x, y is found
            // We replace point outside rectangle
            // by intersection point
            if (code_out == code1)
            {
                a1 = x;
                a2 = y;
                code1 = FINDCODE(xmax, xmin, ymax, ymin, a1, a2);
            }
            else
            {
                b1 = x;
                b2 = y;
                code2 = FINDCODE(xmax, xmin, ymax, ymin, b1, b2);
            }
        }
    }

    if (accept)
    {
        // cout << "Line accepted from " << x1 << ", "<< y1 << " to " << x2 << ", " << y2 << endl;
        //  Here the user can add code to display the rectangle
        //  along with the accepted (portion of) lines
        cleardevice();
        drawboundaries(x1, y1, x2, y2);
        line(a1, a2, b1, b2);
    }
    else
        cout << "Line rejected" << endl;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1, y1;
    int x2, y2;

    cout << "Enter 1st point of window" << endl;
    cin >> x1 >> y1;

    cout << "Enter 2nd point of window" << endl;
    cin >> x2 >> y2;

    int a1, a2;
    int b1, b2;

    cout << "ENTER LINE START POINT A(x, y)" << endl;
    cin >> a1 >> a2;

    cout << "ENTER LINE END POINT B(x, y)" << endl;
    cin >> b1 >> b2;

    drawboundaries(x1, y1, x2, y2);

    int ans;

    cout << "enter 1 to clip" << endl;
    cin >> ans;
    if (ans == 1)
        cohenSutherlandClip(x1, y1, x2, y2, a1, a2, b1, b2);
    getch();
    return 0;
}
