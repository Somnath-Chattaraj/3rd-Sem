#include <iostream>
#include <vector>
#include <algorithm>

class Vector {
private:
    std::vector<int> data;

public:
    Vector() = default;

    Vector(const std::vector<int>& vec) : data(vec) {}

    Vector operator+(const Vector& other) const {
        std::vector<int> result(data.size());
        std::transform(data.begin(), data.end(), other.data.begin(), result.begin(), std::plus<int>());
        return Vector(result);
    }

    Vector operator-(const Vector& other) const {
        std::vector<int> result(data.size());
        std::transform(data.begin(), data.end(), other.data.begin(), result.begin(), std::minus<int>());
        return Vector(result);
    }

    bool operator==(const Vector& other) const {
        return data == other.data;
    }

    bool operator<(const Vector& other) const {
        return data < other.data;
    }

    bool operator>(const Vector& other) const {
        return data > other.data;
    }

    void disp() const {
        for (const auto& element : data) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Vector v1({1, 2, 3});
    Vector v2({4, 5, 6});

    Vector v3 = v1 + v2;
    Vector v4 = v2 - v1;

    std::cout << "v1: ";
    v1.disp();

    std::cout << "v2: ";
    v2.disp();

    std::cout << "v3 (v1 + v2): ";
    v3.disp();

    std::cout << "v4 (v2 - v1): ";
    v4.disp();

    std::cout << "v1 == v2: " << (v1 == v2) << std::endl;
    std::cout << "v1 < v2: " << (v1 < v2) << std::endl;
    std::cout << "v1 > v2: " << (v1 > v2) << std::endl;

    return 0;
}
