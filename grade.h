#ifndef GRADE_H
#define GRADE_H

#include <string>


class Grade
{
public:
    Grade(std::string, double, int);
    std::string name;
    double grade;
    int weight;
};

#endif // GRADE_H
