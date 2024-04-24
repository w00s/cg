#include <iostream>
#include <cmath>

struct Point {
    float x, y;
};

class Transformations2D {
public:
    static void translate(Point& point, float tx, float ty) {
        point.x += tx;
        point.y += ty;
        std::cout << "Translation Matrix:\n";
        std::cout << "1 0 " << tx << "\n";
        std::cout << "0 1 " << ty << "\n";
        std::cout << "0 0 1\n";
    }

    static void rotate(Point& point, float angle) {
        float radians = angle * M_PI / 180.0;
        float x = point.x;
        point.x = x * cos(radians) - point.y * sin(radians);
        point.y = x * sin(radians) + point.y * cos(radians);
        std::cout << "Rotation Matrix:\n";
        std::cout << cos(radians) << " " << -sin(radians) << " 0\n";
        std::cout << sin(radians) << " " << cos(radians) << " 0\n";
        std::cout << "0 0 1\n";
    }
};

int main() {
    Point points[] = { {2, 3}, {5, 5}, {4, 3} };
    const int numPoints = sizeof(points) / sizeof(points[0]);

    Point center = { 1, 1 };
    float angle = 45;

    std::cout << "Original Triangle:\n";
    for (int i = 0; i < numPoints; ++i) {
        std::cout << "Point " << i + 1 << ": (" << points[i].x << ", " << points[i].y << ")\n";
    }
    std::cout << "\n";

    std::cout << "Center Point: (" << center.x << ", " << center.y << ")\n\n";

    for (int i = 0; i < numPoints; ++i) {
        Transformations2D::translate(points[i], -center.x, -center.y);
    }

    for (int i = 0; i < numPoints; ++i) {
        std::cout << "Transformation for Point " << i + 1 << ":\n";
        Transformations2D::rotate(points[i], angle);
        std::cout << "\n";
    }

    for (int i = 0; i < numPoints; ++i) {
        Transformations2D::translate(points[i], center.x, center.y);
    }

    std::cout << "Rotated Triangle:\n";
    for (int i = 0; i < numPoints; ++i) {
        std::cout << "Point " << i + 1 << ": (" << points[i].x << ", " << points[i].y << ")\n";
    }

    return 0;
}
