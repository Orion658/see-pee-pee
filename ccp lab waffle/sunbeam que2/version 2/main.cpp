// main.cpp
#include <iostream>
#include "AdmissionSystem.h"
using namespace std;

// g++ -std=c++11 -o my_program main.cpp Course.cpp Student.cpp AdmissionSystem.cpp

int main()
{
    AdmissionSystem admissionSystem;

    // Adding some initial courses
    admissionSystem.addCourse("Math", 500);
    admissionSystem.addCourse("Science", 600);
    admissionSystem.addCourse("English", 450);

    int choice;
    do
    {
        cout << "Menu:\n";
        cout << "1. Register Student\n";
        cout << "2. Take Course\n";
        cout << "3. Display specific student's taken courses\n";
        cout << "4. Display all students and their courses registered\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name, mobile;
            int rollNo;
            cout << "Enter student name: ";
            cin >> name;
            cout << "Enter roll number: ";
            cin >> rollNo;
            cout << "Enter mobile number: ";
            cin >> mobile;
            admissionSystem.registerStudent(name, rollNo, mobile);
            break;
        }
        case 2:
        {
            string courseName;
            int rollNo;
            cout << "Enter roll number: ";
            cin >> rollNo;
            cout << "Enter course name: ";
            cin >> courseName;
            admissionSystem.takeCourse(rollNo, courseName);
            break;
        }
        case 3:
        {
            int rollNo;
            cout << "Enter roll number: ";
            cin >> rollNo;
            admissionSystem.displayStudentCourses(rollNo);
            break;
        }
        case 4:
            admissionSystem.displayAllStudents();
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
