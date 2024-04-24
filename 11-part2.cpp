#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    float x, y, z;
};




int main()
{

    Point points[] = {{1, 1, 1}, {1, 1, 3}, {3, 1, 3}, {3, 1, 1}, {1, 3, 1}, {1, 3, 3}, {3, 3, 3}, {3, 3, 1}};
    const int numPoints = sizeof(points) / sizeof(points[0]);

    Point center = {2, 2, 2};

    cout << "Original Cube:\n";
    for (int i = 0; i < numPoints; ++i)
    {
        cout << "Point " << i + 1 << ": (" << points[i].x << ", " << points[i].y << ", " << points[i].z << ")\n";
    }

    float dx, dy, dz;
    cout << "\nEnter angle x, angle y, and angle z\n";
    cin >> dx >> dy >> dz;

    float cosx = cos (dx*3.14159/180);
    float sinx = sin (dx*3.14159/180);

    float cosy = cos (dy*3.14159/180);
    float siny = sin (dy*3.14159/180);

    float cosz = cos (dz*3.14159/180);
    float sinz = sin (dz*3.14159/180);



    for (int i = 0; i < numPoints; ++i)
    {
        points[i].y = (points[i].y*cosx) - (points[i].z*sinx);
        points[i].z = (points[i].y*sinx) + (points[i].z*cosx);
    }
    cout<<"\nAfter rotation about x axis : \n";
    for (int i = 0; i < numPoints; ++i)
    {
        cout << "Point " << i + 1 << ": (" << points[i].x << ", " << points[i].y << ", " << points[i].z << ")\n";
    }


    for (int i = 0; i < numPoints; ++i)
    {
        points[i].x = (points[i].x*cosy) + (points[i].z*siny);
        points[i].z = (points[i].z*cosy) - (points[i].x*siny);
    }
    cout<<"\nAfter rotation about y axis : \n";
    for (int i = 0; i < numPoints; ++i)
    {
        cout << "Point " << i + 1 << ": (" << points[i].x << ", " << points[i].y << ", " << points[i].z << ")\n";
    }


    for (int i = 0; i < numPoints; ++i)
    {
        points[i].x = (points[i].x*cosz) - (points[i].y*sinz);
        points[i].y = (points[i].x*sinz) + (points[i].y*cosz);
    }
    cout<<"\nAfter rotation about z axis : \n";
    for (int i = 0; i < numPoints; ++i)
    {
        cout << "Point " << i + 1 << ": (" << points[i].x << ", " << points[i].y << ", " << points[i].z << ")\n";
    }




    return 0;
}