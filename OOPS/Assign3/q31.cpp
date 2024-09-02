#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
    float height;

public:

    Person(string n, int a, float h) : name(n), age(a), height(h) {}


    string getName() { return name; }
    int getAge() { return age; }
    float getHeight() { return height; }


    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setHeight(float h) { height = h; }


    virtual void printDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Height: " << height << " cm" << endl;
    }
};

class Student : public Person {
private:
    int roll;
    int yearOfAdmission;

public:

    Student(string n, int a, float h, int r, int y) : Person(n, a, h), roll(r), yearOfAdmission(y) {}


    int getRoll() { return roll; }
    int getYearOfAdmission() { return yearOfAdmission; }


    void setRoll(int r) { roll = r; }
    void setYearOfAdmission(int y) { yearOfAdmission = y; }


    void printDetails() override {
        Person::printDetails(); 
        cout << "Roll Number: " << roll << endl;
        cout << "Year of Admission: " << yearOfAdmission << endl;
    }
};

int main() {

    Person p1("John Doe", 45, 180.0);
    p1.printDetails();
    cout << endl;


    Student s1("Alice Smith", 20, 165.0, 101, 2022);
    s1.printDetails();
    cout << endl;


    Person* arr[4];
    arr[0] = new Person("Jane Doe", 50, 170.0);
    arr[1] = new Person("Mark Twain", 60, 175.0);
    arr[2] = new Student("Bob Marley", 19, 160.0, 102, 2023);
    arr[3] = new Student("Lucy Heart", 21, 162.0, 103, 2022);


    for (int i = 0; i < 4; ++i) {
        arr[i]->printDetails();
        cout << endl;
    }


    for (int i = 0; i < 4; ++i) {
        delete arr[i];
    }

    return 0;
}
