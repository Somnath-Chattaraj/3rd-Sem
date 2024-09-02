#include <iostream>

using namespace std;

class BaseOne {
    public: 
    void printBaseOne() {
        cout << "BaseOne" << endl;
    }
};

class BaseTwo {
    public: 
    void printBaseTwo() {
        cout << "BaseTwo" << endl;
    }
};

class derived: public BaseOne, public BaseTwo {
    public:
    void printDerived() {
        cout << "Derived" << endl;
    }
};

int main() {
    derived d;
    d.printBaseOne();
    d.printBaseTwo();
    d.printDerived();
    return 0;
}