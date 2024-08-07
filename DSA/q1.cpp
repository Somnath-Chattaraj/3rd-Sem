// Write a menu driven C/C++ program using structure and pointer for storing 10-12 records of a student-
// database containing fields: name, address, five subjects’ and marks scored in each subject. Obtain the
// following:
// 1. Find the name of the students who have passed and failed in minimum three subjects (minimum
// pass mark of each subject is 40 out of 100).
// 2. Show the record of the student who has got maximum marks in Mathematics.
// 3. Show the record of the student who has got minimum marks in Physics.
// 4. Show the record of the student whose average marks is maximum.
// 5. Print the record of the student with name and total.

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct Student {
    string name;
    string address;
    int marks[5]; // Marks in 5 subjects: Math, Physics, Chemistry, Biology, English
};

// Function to calculate total marks
int totalMarks(const Student& s) {
    int total = 0;
    for (int mark : s.marks) {
        total += mark;
    }
    return total;
}

// Function to calculate average marks
double averageMarks(const Student& s) {
    return totalMarks(s) / 5.0;
}

// Function to input student details
void inputStudent(Student* s) {
    cout << "Enter name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s->name);
    cout << "Enter address: ";
    getline(cin, s->address);
    cout << "Enter marks for 5 subjects (Math, Physics, Chemistry, Biology, English): ";
    for (int i = 0; i < 5; ++i) {
        cin >> s->marks[i];
    }
}

// Function to display student details
void displayStudent(const Student& s) {
    cout << "Name: " << s.name << "\nAddress: " << s.address << "\nMarks: ";
    for (int mark : s.marks) {
        cout << mark << " ";
    }
    cout << "\n";
}

int main() {
    const int NUM_STUDENTS = 12;
    Student students[NUM_STUDENTS];
    int numStudents = 0;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Student Record\n";
        cout << "2. Find Students Failed in Minimum Three Subjects\n";
        cout << "3. Student with Maximum Marks in Mathematics\n";
        cout << "4. Student with Minimum Marks in Physics\n";
        cout << "5. Student with Maximum Average Marks\n";
        cout << "6. Print Student Records with Total Marks\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                if (numStudents < NUM_STUDENTS) {
                    inputStudent(&students[numStudents++]);
                } else {
                    cout << "Student database is full.\n";
                }
                break;
            
            case 2:
                cout << "Students who failed in at least three subjects:\n";
                for (int i = 0; i < numStudents; ++i) {
                    int failCount = 0;
                    for (int mark : students[i].marks) {
                        if (mark < 40) {
                            ++failCount;
                        }
                    }
                    if (failCount >= 3) {
                        cout << students[i].name << "\n";
                    }
                }
                break;
            
            case 3: {
                int maxMathMarks = -1;
                int maxMathIndex = -1;
                for (int i = 0; i < numStudents; ++i) {
                    if (students[i].marks[0] > maxMathMarks) { // Math marks are at index 0
                        maxMathMarks = students[i].marks[0];
                        maxMathIndex = i;
                    }
                }
                if (maxMathIndex != -1) {
                    cout << "Student with maximum marks in Mathematics:\n";
                    displayStudent(students[maxMathIndex]);
                } else {
                    cout << "No records found.\n";
                }
                break;
            }

            case 4: {
                int minPhysicsMarks = 101;
                int minPhysicsIndex = -1;
                for (int i = 0; i < numStudents; ++i) {
                    if (students[i].marks[1] < minPhysicsMarks) { // Physics marks are at index 1
                        minPhysicsMarks = students[i].marks[1];
                        minPhysicsIndex = i;
                    }
                }
                if (minPhysicsIndex != -1) {
                    cout << "Student with minimum marks in Physics:\n";
                    displayStudent(students[minPhysicsIndex]);
                } else {
                    cout << "No records found.\n";
                }
                break;
            }

            case 5: {
                double maxAverage = -1;
                int maxAverageIndex = -1;
                for (int i = 0; i < numStudents; ++i) {
                    double avg = averageMarks(students[i]);
                    if (avg > maxAverage) {
                        maxAverage = avg;
                        maxAverageIndex = i;
                    }
                }
                if (maxAverageIndex != -1) {
                    cout << "Student with maximum average marks:\n";
                    displayStudent(students[maxAverageIndex]);
                } else {
                    cout << "No records found.\n";
                }
                break;
            }

            case 6:
                cout << "Student records with total marks:\n";
                for (int i = 0; i < numStudents; ++i) {
                    cout << students[i].name << ": " << totalMarks(students[i]) << "\n";
                }
                break;

            case 7:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
