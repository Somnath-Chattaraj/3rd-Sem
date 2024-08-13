#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class Subject {
public:
     string name;
    int marks;

    Subject( string name, int marks) : name(name), marks(marks) {}
};

class GradeCard {
private:
     string department;
     string studentName;
     string rollNumber;
    int semester;
     vector<Subject> subjects;
    double cgpa;

    void calculateCGPA() {
        int totalMarks = 0;
        for (const auto& subject : subjects) {
            totalMarks += subject.marks;
        }
        cgpa = static_cast<double>(totalMarks) / subjects.size();
    }

public:
    GradeCard( string department,  string studentName,  string rollNumber, int semester, const  vector<Subject>& subjects)
        : department(department), studentName(studentName), rollNumber(rollNumber), semester(semester), subjects(subjects) {
        calculateCGPA();
    }

    double getCGPA() const {
        return cgpa;
    }

     string getStudentName() const {
        return studentName;
    }

     string getRollNumber() const {
        return rollNumber;
    }
};

int main() {
     vector<GradeCard> gradeCards;

    for (int i = 1; i <= 60; ++i) {
         vector<Subject> subjects = {
            {"Math", 85 + rand() % 15},
            {"Physics", 80 + rand() % 20},
            {"Chemistry", 75 + rand() % 25},
            {"Computer Science", 90 + rand() % 10},
            {"Biology", 70 + rand() % 30},
        };
        gradeCards.push_back(GradeCard("CSE", "Student" +  to_string(i), "Roll" +  to_string(i), 3, subjects));
    }

    auto maxCGPA =  max_element(gradeCards.begin(), gradeCards.end(), [](const GradeCard& a, const GradeCard& b) {
        return a.getCGPA() < b.getCGPA();
    });

     cout << "Highest CGPA: " << maxCGPA->getCGPA() <<  endl;
     cout << "Student Name: " << maxCGPA->getStudentName() <<  endl;
     cout << "Roll Number: " << maxCGPA->getRollNumber() <<  endl;

    return 0;
}
