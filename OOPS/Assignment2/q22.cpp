#include <iostream>

class Demo {
private:
    int a;
    mutable int b;

public:
    Demo(int x, int y) : a(x), b(y) {}

    int getA() const {
        return a;
    }

    int getB() const {
        return b;
    }

    void modifyB(int newValue) const {
        b = newValue;
    }
};

int main() {
    Demo obj(10, 20);

    std::cout << "a: " << obj.getA() << std::endl;
    std::cout << "b: " << obj.getB() << std::endl;

    obj.modifyB(30);
    std::cout << "b after modification: " << obj.getB() << std::endl;

    return 0;
}
