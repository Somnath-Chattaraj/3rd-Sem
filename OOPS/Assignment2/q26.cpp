#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Subject {
public:
    std::string name;
    int marks;

    Subject(std::string name, int marks) : name(name), marks(marks) {}
};

class GradeCard {
private:
    std::string department;
    std::string studentName;
    std::string rollNumber;
    int semester;
    std::vector<Subject> subjects;
    double cgpa;

    void calculateCGPA() {
        int totalMarks = 0;
        for (const auto& subject : subjects) {
            totalMarks += subject.marks;
        }
        cgpa = static_cast<double>(totalMarks) / subjects.size();
    }

public:
    GradeCard(std::string department, std::string studentName, std::string rollNumber, int semester, const std::vector<Subject>& subjects)
        : department(department), studentName(studentName), rollNumber(rollNumber), semester(semester), subjects(subjects) {
        calculateCGPA();
    }

    double getCGPA() const {
        return cgpa;
    }

    std::string getStudentName() const {
        return studentName;
    }

    std::string getRollNumber() const {
        return rollNumber;
    }
};

int main() {
    std::vector<GradeCard> gradeCards;

    for (int i = 1; i <= 60; ++i) {
        std::vector<Subject> subjects = {
            {"Math", 85 + rand() % 15},
            {"Physics", 80 + rand() % 20},
            {"Chemistry", 75 + rand() % 25},
            {"Computer Science", 90 + rand() % 10},
            {"Biology", 70 + rand() % 30},
        };
        gradeCards.push_back(GradeCard("CSE", "Student" + std::to_string(i), "Roll" + std::to_string(i), 3, subjects));
    }

    auto maxCGPA = std::max_element(gradeCards.begin(), gradeCards.end(), [](const GradeCard& a, const GradeCard& b) {
        return a.getCGPA() < b.getCGPA();
    });

    std::cout << "Highest CGPA: " << maxCGPA->getCGPA() << std::endl;
    std::cout << "Student Name: " << maxCGPA->getStudentName() << std::endl;
    std::cout << "Roll Number: " << maxCGPA->getRollNumber() << std::endl;

    return 0;
}
