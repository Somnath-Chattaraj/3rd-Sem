#include <iostream>
#include <algorithm>

using namespace std;

class IntArray {
private:
    int* arr;
    int size;

public:
    IntArray(int size) : size(size) {
        arr = new int[size];
    }

    IntArray(const IntArray& other) : size(other.size) {
        arr = new int[size];
        copy(other.arr, other.arr + size, arr);
    }

    ~IntArray() {
        delete[] arr;
    }

    IntArray& operator=(const IntArray& other) {
        if (this == &other) return *this; // Handle self-assignment

        delete[] arr;
        size = other.size;
        arr = new int[size];
        copy(other.arr, other.arr + size, arr);
        return *this;
    }

    void setElements(const int* elements) {
        copy(elements, elements + size, arr);
    }

    IntArray operator+(const IntArray& other) const {
        if (size != other.size) {
            throw invalid_argument("Arrays must be of the same size");
        }
        IntArray result(size);
        for (int i = 0; i < size; ++i) {
            result.arr[i] = arr[i] + other.arr[i];
        }
        return result;
    }

    void reverseArray() {
        reverse(arr, arr + size);
    }

    void sortArray() {
        sort(arr, arr + size);
    }

    void display() const {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int elements1[] = {1, 2, 3};
    IntArray arr1(3);
    arr1.setElements(elements1);

    cout << "arr1: ";
    arr1.display();

    IntArray arr2 = arr1;
    cout << "arr2 (copy of arr1): ";
    arr2.display();

    arr2.reverseArray();
    cout << "arr2 after reversing: ";
    arr2.display();

    cout << "arr1 (unchanged): ";
    arr1.display();

    return 0;
}
