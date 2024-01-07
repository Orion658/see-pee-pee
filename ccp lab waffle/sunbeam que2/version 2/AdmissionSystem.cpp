// AdmissionSystem.cpp
#include "AdmissionSystem.h"
#include <iostream>
#include <algorithm>

void AdmissionSystem::registerStudent(const std::string &name, int rollNo, const std::string &mobile)
{
    students.push_back(Student(name, rollNo, mobile));
}

void AdmissionSystem::addCourse(const std::string &courseName, double fees)
{
    availableCourses.push_back(Course(courseName, fees));
}

void AdmissionSystem::takeCourse(int rollNo, const std::string &courseName)
{
    auto studentIt = findStudent(rollNo);
    if (studentIt != students.end())
    {
        auto courseIt = findCourse(courseName);
        if (courseIt != availableCourses.end())
        {
            studentIt->takeCourse(*courseIt);
            std::cout << "Course added successfully.\n";
        }
        else
        {
            std::cout << "Course not found.\n";
        }
    }
    else
    {
        std::cout << "Student not found.\n";
    }
}

void AdmissionSystem::displayStudentCourses(int rollNo)
{
    auto studentIt = findStudent(rollNo);
    if (studentIt != students.end())
    {
        studentIt->displayTakenCourses();
    }
    else
    {
        std::cout << "Student not found.\n";
    }
}

void AdmissionSystem::displayAllStudents() const
{
    std::cout << "All registered students and their courses:\n";
    for (const auto &student : students)
    {
        std::cout << "----------------------------------------\n";
        std::cout << "Name: " << student.name << "\n";
        std::cout << "Roll No: " << student.rollNo << "\n";
        std::cout << "Mobile: " << student.mobile << "\n";
        student.displayTakenCourses();
    }
    std::cout << "----------------------------------------\n";
}

std::vector<Student>::iterator AdmissionSystem::findStudent(int rollNo)
{
    return std::find_if(students.begin(), students.end(),
                        [rollNo](const Student &student)
                        { return student.rollNo == rollNo; });
}

std::vector<Course>::iterator AdmissionSystem::findCourse(const std::string &courseName)
{
    return std::find_if(availableCourses.begin(), availableCourses.end(),
                        [courseName](const Course &course)
                        { return course.courseName == courseName; });
}
