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

    float sx, sy, sz;
    cout << "\nEnter sx, sy, and sz\n";
    cin >> sx >> sy >> sz;

    cout<<"\nTransformation Matrix is: \n";
    cout<<sx<<"\t0"<<"\t0"<<"\t0"<<endl;
    cout<<"0\t"<<sy<<"\t0"<<"\t0"<<endl;
    cout<<"0\t"<<"0\t"<<sz<<"\t0"<<endl;
    cout<<"0\t"<<"0"<<"\t0"<<"\t1"<<endl;

    for (int i = 0; i < numPoints; ++i)
    {
        points[i].x -=center.x;
        points[i].y -=center.y;
        points[i].z -=center.z;
    }
    cout << "\nTranslate to origin\n";
    for (int i = 0; i < numPoints; ++i)
    {
        cout << "Point " << i + 1 << ": (" << points[i].x << ", " << points[i].y << ", " << points[i].z << ")\n";
    }

    for (int i = 0; i < numPoints; ++i)
    {
        points[i].x *=sx;
        points[i].y *=sy;
        points[i].z *=sz;
    }
    cout << "\nScaling at origin:\n";
    for (int i = 0; i < numPoints; ++i)
    {
        cout << "Point " << i + 1 << ": (" << points[i].x << ", " << points[i].y << ", " << points[i].z << ")\n";
    }

    for (int i = 0; i < numPoints; ++i)
    {
        points[i].x +=center.x;
        points[i].y +=center.y;
        points[i].z +=center.z;
    }
    cout << "\nTranslation back to center:\n";
    for (int i = 0; i < numPoints; ++i)
    {
        cout << "Point " << i + 1 << ": (" << points[i].x << ", " << points[i].y << ", " << points[i].z << ")\n";
    }

    

    cout<<"\nFINAL Scaled Points are : \n";
    for (int i = 0; i < numPoints; ++i)
    {
        cout << "Point " << i + 1 << ": (" << points[i].x << ", " << points[i].y << ", " << points[i].z << ")\n";
    }
    return 0;
}