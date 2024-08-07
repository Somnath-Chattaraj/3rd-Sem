// Write a menu driven C/C++ program using structure and pointer for storing 10-12 records of a student-
// database containing fields: name, address, five subjects’ and marks scored in each subject. Obtain the
// following:
// 1. Find the name of the students who have passed and failed in minimum three subjects (minimum
// pass mark of each subject is 40 out of 100).
// 2. Show the record of the student who has got maximum marks in Mathematics.
// 3. Show the record of the student who has got minimum marks in Physics.
// 4. Show the record of the student whose average marks is maximum.
// 5. Print the record of the student with name and total.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 12
#define SUBJECTS 5

typedef struct {
    char name[50];
    char address[100];
    int marks[SUBJECTS]; // Marks in 5 subjects
} Student;

void find_pass_fail(Student* students, int n) {
    for (int i = 0; i < n; ++i) {
        int fail_count = 0;
        for (int j = 0; j < SUBJECTS; ++j) {
            if (students[i].marks[j] < 40) {
                fail_count++;
            }
        }
        if (fail_count >= 3) {
            printf("Student failed in at least 3 subjects: %s\n", students[i].name);
        }
    }
}

void student_max_math(Student* students, int n) {
    int max_math_index = 0;
    for (int i = 1; i < n; ++i) {
        if (students[i].marks[0] > students[max_math_index].marks[0]) {
            max_math_index = i;
        }
    }
    printf("Student with maximum marks in Mathematics: %s\n", students[max_math_index].name);
}

void student_min_physics(Student* students, int n) {
    int min_physics_index = 0;
    for (int i = 1; i < n; ++i) {
        if (students[i].marks[1] < students[min_physics_index].marks[1]) {
            min_physics_index = i;
        }
    }
    printf("Student with minimum marks in Physics: %s\n", students[min_physics_index].name);
}

void student_max_avg(Student* students, int n) {
    int max_avg_index = 0;
    double max_avg = 0;
    for (int i = 0; i < n; ++i) {
        double total = 0;
        for (int j = 0; j < SUBJECTS; ++j) {
            total += students[i].marks[j];
        }
        double avg = total / SUBJECTS;
        if (avg > max_avg) {
            max_avg = avg;
            max_avg_index = i;
        }
    }
    printf("Student with maximum average marks: %s\n", students[max_avg_index].name);
}

void print_student_record(Student* students, int n) {
    for (int i = 0; i < n; ++i) {
        int total = 0;
        for (int j = 0; j < SUBJECTS; ++j) {
            total += students[i].marks[j];
        }
        printf("Student: %s, Total Marks: %d\n", students[i].name, total);
    }
}

int main() {
    Student students[MAX_STUDENTS] = {
        {"Alice", "123 Maple St", {85, 92, 78, 90, 88}},
        {"Bob", "456 Oak St", {65, 40, 55, 72, 61}},
        {"Charlie", "789 Pine St", {30, 50, 60, 40, 35}},
        {"David", "101 Elm St", {40, 55, 45, 62, 50}},
        {"Eva", "202 Birch St", {90, 95, 100, 85, 80}},
        {"Frank", "303 Cedar St", {55, 60, 58, 52, 48}},
        {"Grace", "404 Spruce St", {35, 25, 20, 40, 45}},
        {"Hannah", "505 Willow St", {70, 65, 60, 75, 80}},
        {"Ivy", "606 Cherry St", {45, 55, 65, 75, 85}},
        {"Jack", "707 Walnut St", {30, 35, 25, 40, 50}},
        {"Kara", "808 Aspen St", {95, 92, 88, 91, 89}},
        {"Leo", "909 Fir St", {60, 70, 80, 90, 100}}
    };

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Find students who passed/failed in at least 3 subjects\n");
        printf("2. Show the student with maximum marks in Mathematics\n");
        printf("3. Show the student with minimum marks in Physics\n");
        printf("4. Show the student with maximum average marks\n");
        printf("5. Print records of all students with total marks\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                find_pass_fail(students, MAX_STUDENTS);
                break;
            case 2:
                student_max_math(students, MAX_STUDENTS);
                break;
            case 3:
                student_min_physics(students, MAX_STUDENTS);
                break;
            case 4:
                student_max_avg(students, MAX_STUDENTS);
                break;
            case 5:
                print_student_record(students, MAX_STUDENTS);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
