#include <iostream>

using namespace std;

class Base {
    public : 
    void printBase() {
        cout << "Base" << endl;
    }
};

class Derived: public Base {
    public:
    void printDereived() {
        cout << "Derived" << endl;
    }
};

int main(){
    Base b;
    b.printBase();
    Derived d;
    d.printBase();
    d.printDereived();
}