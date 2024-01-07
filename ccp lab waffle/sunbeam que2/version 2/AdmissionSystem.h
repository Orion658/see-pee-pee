// AdmissionSystem.h
#ifndef ADMISSIONSYSTEM_H
#define ADMISSIONSYSTEM_H

#include <vector>
#include "Student.h"

class AdmissionSystem
{
private:
    std::vector<Student> students;
    std::vector<Course> availableCourses;

public:
    void registerStudent(const std::string &name, int rollNo, const std::string &mobile);
    void addCourse(const std::string &courseName, double fees);
    void takeCourse(int rollNo, const std::string &courseName);
    void displayStudentCourses(int rollNo);
    void displayAllStudents() const;

private:
    std::vector<Student>::iterator findStudent(int rollNo);
    std::vector<Course>::iterator findCourse(const std::string &courseName);
};

#endif // ADMISSIONSYSTEM_H
