#ifndef GRADE_H
#define GRADE_H

#include <QString>


class Grade
{
public:
    Grade(QString, double, double);
    QString name;
    double grade;
    double weight;
};

#endif // GRADE_H
