#include <iostream>
#include <algorithm>

class IntArray {
private:
    int* arr;
    int size;

public:
    IntArray(int size) : size(size) {
        arr = new int[size];
    }

    IntArray(const IntArray& other) : size(other.size) {
        arr = new int[other.size];
        std::copy(other.arr, other.arr + other.size, arr);
    }

    ~IntArray() {
        delete[] arr;
    }

    void setElements(const int* elements) {
        std::copy(elements, elements + size, arr);
    }

    IntArray operator+(const IntArray& other) const {
        IntArray result(size);
        for (int i = 0; i < size; ++i) {
            result.arr[i] = arr[i] + other.arr[i];
        }
        return result;
    }

    void reverse() {
        std::reverse(arr, arr + size);
    }

    void sort() {
        std::sort(arr, arr + size);
    }

    void disp() const {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int elements1[] = {1, 2, 3};
    IntArray arr1(3);
    arr1.setElements(elements1);

    std::cout << "arr1: ";
    arr1.disp();

    IntArray arr2 = arr1;
    std::cout << "arr2 (copy of arr1): ";
    arr2.disp();

    arr2.reverse();
    std::cout << "arr2 after reversing: ";
    arr2.disp();

    std::cout << "arr1 (unchanged): ";
    arr1.disp();

    return 0;
}
