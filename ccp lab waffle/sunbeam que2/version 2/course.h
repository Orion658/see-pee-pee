// Course.h
#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course
{
public:
    std::string courseName;
    double fees;

    Course(const std::string &name, double fees);
};

#endif // COURSE_H
