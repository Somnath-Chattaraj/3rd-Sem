#include <iostream>

using namespace std;

class Queue {
private:
    int* data;
    int front, rear, size, count;

public:
    Queue(int size) : size(size), front(0), rear(0), count(0) {
        data = new int[size];
    }

    ~Queue() {
        delete[] data;
    }

    void add(int element) {
        if (count < size) {
            data[rear] = element;
            rear = (rear + 1) % size;
            ++count;
        } else {
             cout << "Queue overflow!" <<  endl;
        }
    }

    int remove() {
        if (count > 0) {
            int element = data[front];
            front = (front + 1) % size;
            --count;
            return element;
        } else {
             cout << "Queue underflow!" <<  endl;
            return -1;
        }
    }

    void disp() const {
        int i = front;
        int items = count;
        while (items > 0) {
             cout << data[i] << " ";
            i = (i + 1) % size;
            --items;
        }
         cout <<  endl;
    }
};

int main() {
    Queue q(10);

    q.add(2);
    q.add(3);
    q.add(4);
    q.add(5);

    q.disp();

    q.remove();
    q.remove();

    q.disp();

    return 0;
}
