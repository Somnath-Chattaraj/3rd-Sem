#include <iostream>

using namespace std;

class A {
    public:
    void printA() {
        cout << "A" << endl;
    }
};

class B {
    public:
    void printB() {
        cout << "B" << endl;
    }
};
class C {
    public:
    void printC() {
        cout << "C" << endl;
    }
};

class D : public A, public B {
    public:
    void printD() {
        cout << "D" << endl;
    }
};

class E : public B, public C {
    public:
    void printE() {
        cout << "E" << endl;
    }
};

class F : public D, public E {
    public:
    void printF() {
        cout << "F" << endl;
    }
};

int main() {
    F f;
    f.printA();
    f.D::printB();
    f.E::printB();
    f.printC();
    f.printD();
    f.printE();
    f.printF();
    return 0;
}