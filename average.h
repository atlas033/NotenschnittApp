#ifndef AVERAGE_H
#define AVERAGE_H

#include "grade.h"
#include <vector>

class Average
{
public:
    Average();
//    Average(int , )      constructor mit uebergabe von user daten
    void addGrade(Grade*);
    double getAvg() const  {return m_avg;} ;

private:
    double m_avg;
    std::vector<Grade*> exams;
    void calculateAvg();
};

#endif // AVERAGE_H
