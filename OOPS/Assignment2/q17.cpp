#include <iostream>
using namespace std;
class Rectangle {
private:
    double length, width;

public:
    Rectangle(double l = 1.0, double w = 1.0) : length(l), width(w) {}

    double area() const {
        return length * width;
    }
};

int main() {
    Rectangle r1(2.0, 3.0);
    Rectangle r2(4.0, 5.0);
    Rectangle r3(6.0, 7.0);
    Rectangle r4(8.0, 9.0);

     cout << "Area of r1: " << r1.area() <<  endl;
     cout << "Area of r2: " << r2.area() <<  endl;
     cout << "Area of r3: " << r3.area() <<  endl;
     cout << "Area of r4: " << r4.area() <<  endl;

    return 0;
}
