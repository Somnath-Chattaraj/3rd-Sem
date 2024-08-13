#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x, y, z;

public:
    Point(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    double distance(const Point& other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2));
    }
};

int main() {
    Point p1(1.0, 2.0, 3.0);
    Point p2(4.0, 5.0, 6.0);

     cout << "Distance between p1 and p2: " << p1.distance(p2) <<  endl;

    return 0;
}
