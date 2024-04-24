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

    static void scale(Point& point, float sx, float sy, const Point& center) {
        point.x = center.x + (point.x - center.x) * sx;
        point.y = center.y + (point.y - center.y) * sy;
        std::cout << "Scaling Matrix:\n";
        std::cout << sx << " 0 0\n";
        std::cout << "0 " << sy << " 0\n";
        std::cout << "0 0 1\n";
    }
};

int main() {
    Point points[] = { {1, 1}, {3, 1}, {3, 3}, {1, 3} };
    const int numPoints = sizeof(points) / sizeof(points[0]);

    Point center = { 2, 2 };

    float sx = 0.5;
    float sy = 0.5;

    std::cout << "Original Square:\n";
    for (int i = 0; i < numPoints; ++i) {
        std::cout << "Point " << i + 1 << ": (" << points[i].x << ", " << points[i].y << ")\n";
    }
    std::cout << "\n";

    std::cout << "Center Point: (" << center.x << ", " << center.y << ")\n\n";

    for (int i = 0; i < numPoints; ++i) {
        std::cout << "Transformation for Point " << i + 1 << ":\n";
        Transformations2D::scale(points[i], sx, sy, center);
        std::cout << "\n";
    }

    std::cout << "Scaled Square (Half Size):\n";
    for (int i = 0; i < numPoints; ++i) {
        std::cout << "Point " << i + 1 << ": (" << points[i].x << ", " << points[i].y << ")\n";
    }

    return 0;
}
