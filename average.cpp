#include "average.h"

Average::Average(){}

void Average::calculateAvg()
{
    double avg = 0.0;
    double weights = 0.0;
    for(Grade* grades:exams){
        avg += grades->grade * grades->weight;
        weights += grades->weight;
    }
    avg /= weights;
    this->m_avg = avg;
    return;
}

void Average::addGrade(Grade* a)
{
    exams.push_back(a);
    calculateAvg();
    return;
}

