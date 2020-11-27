#ifndef AVERAGE_H
#define AVERAGE_H

#include "grade.h"
#include <vector>
#include <QTextStream>
#include <QString>

class Average
{
public:
    Average();
    void addGrade(Grade*);
    double getAvg() const  {return m_avg;} ;
    QString toPlainText();
    void readAll(QString&);
    void calculateAvg();

private:
    double m_avg = 0.0;
    std::vector<Grade*> exams;
};

#endif // AVERAGE_H
