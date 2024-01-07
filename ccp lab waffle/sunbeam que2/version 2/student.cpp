// Student.cpp
#include "Student.h"
#include <iostream>

Student::Student(const std::string &studentName, int roll, const std::string &mobileNum)
    : name(studentName), rollNo(roll), mobile(mobileNum) {}

void Student::takeCourse(const Course &course)
{
    courses.push_back(course);
}

void Student::displayTakenCourses() const
{
    std::cout << "Courses taken by " << name << " (Roll No: " << rollNo << "):\n";
    for (const auto &course : courses)
    {
        std::cout << "  - " << course.courseName << " (Fees: $" << course.fees << ")\n";
    }
    std::cout << std::endl;
}
