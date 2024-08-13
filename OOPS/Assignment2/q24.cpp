#include <iostream>

class Stack {
private:
    int* buffer;
    int top;
    int size;

public:
    Stack(int size) : size(size), top(-1) {
        buffer = new int[size];
    }

    ~Stack() {
        delete[] buffer;
    }

    void push(int item) {
        if (top < size - 1) {
            buffer[++top] = item;
        } else {
            std::cout << "Stack overflow!" << std::endl;
        }
    }

    int pop() {
        if (top >= 0) {
            return buffer[top--];
        } else {
            std::cout << "Stack underflow!" << std::endl;
            return -1;
        }
    }

    void disp() const {
        for (int i = top; i >= 0; --i) {
            std::cout << buffer[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack s(10);

    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s.disp();

    s.pop();
    s.disp();

    return 0;
}
