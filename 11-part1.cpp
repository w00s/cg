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

    float tx, ty, tz;
    cout << "\nEnter tx, ty, and tz\n";
    cin >> tx >> ty >> tz;

    for (int i = 0; i < numPoints; ++i)
    {
        points[i].x +=tx;
        points[i].y +=ty;
        points[i].z +=tz;
    }

    cout<<"\nTranslation Matrix is: \n";
    cout<<"1    0    0    "<<tx<<endl;
    cout<<"0    1    0    "<<ty<<endl;
    cout<<"0    0    1    "<<tz<<endl;
    cout<<"0    0    0    "<<"1"<<endl;

    cout<<"\nTransformed Points are : \n";
    for (int i = 0; i < numPoints; ++i)
    {
        cout << "Point " << i + 1 << ": (" << points[i].x << ", " << points[i].y << ", " << points[i].z << ")\n";
    }
    return 0;
}