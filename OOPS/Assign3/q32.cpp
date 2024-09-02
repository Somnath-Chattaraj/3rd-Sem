#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int salary;

public:
    Employee(const string &n = "", int s = 0) : name(n), salary(s) {}

    void setDetails(const string &n, int s) {
        name = n;
        salary = s;
    }

    virtual void printDetails() const {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }

    virtual int getSalary() const {
        return salary;
    }

    virtual ~Employee() {}
};

class Manager : public Employee {
    int type;

public:
    Manager(const string &n = "", int s = 0, int t = 0) : Employee(n, s), type(t) {}

    void setDetails(const string &n, int s, int t) {
        Employee::setDetails(n, s);
        type = t;
    }

    void printDetails() const override {
        Employee::printDetails();
        cout << "Type: " << type << endl;
    }
};

class Clerk : public Employee {
    int allowance;

public:
    Clerk(const string &n = "", int s = 0, int a = 0) : Employee(n, s), allowance(a) {}

    void setDetails(const string &n, int s, int a) {
        Employee::setDetails(n, s);
        allowance = a;
    }

    void printDetails() const override {
        Employee::printDetails();
        cout << "Allowance: " << allowance << endl;
    }

    int getSalary() const override {
        return salary + allowance;
    }
};

int main() {
   
    Manager mgr("Alice", 50000, 1);
    Clerk clk("Bob", 30000, 5000);

    mgr.printDetails();
    cout << endl;
    clk.printDetails();
    cout << endl;


    Employee* employees[6];
    

    employees[0] = new Employee("John", 40000);
    employees[1] = new Employee("Jane", 45000);
    employees[2] = new Manager("Alice", 50000, 1);
    employees[3] = new Manager("Mark", 55000, 2);
    employees[4] = new Clerk("Bob", 30000, 5000);
    employees[5] = new Clerk("Charlie", 32000, 4500);


    int totalSalary = 0;
    for (int i = 0; i < 6; ++i) {
        employees[i]->printDetails();
        cout << endl;
        totalSalary += employees[i]->getSalary();
    }


    cout << "Total Salary: " << totalSalary << endl;


    for (int i = 0; i < 6; ++i) {
        delete employees[i];
    }

    return 0;
}
