#ifndef AVERAGE_H
#define AVERAGE_H

#include "grade.h"
#include <vector>

class Average
{
public:
    Average(int);
    double avg;
    void addGrade(Grade);

private:
    int ects;
    std::vector<Grade> exams;
};

#endif // AVERAGE_H
