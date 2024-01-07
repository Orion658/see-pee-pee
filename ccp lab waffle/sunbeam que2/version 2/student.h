// Student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Course.h"

class Student
{
public:
    std::string name;
    int rollNo;
    std::string mobile;
    std::vector<Course> courses;

    Student(const std::string &studentName, int roll, const std::string &mobileNum);
    void takeCourse(const Course &course);
    void displayTakenCourses() const;
};

#endif // STUDENT_H
