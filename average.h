#ifndef AVERAGE_H
#define AVERAGE_H

#include "grade.h"
#include <vector>
#include <memory>
#include <QTextStream>
#include <QString>

class Average
{
public:
    Average();
    void addGrade(std::shared_ptr<Grade>);
    double getAvg() const  {return m_avg;} ;
    QString toPlainText();
    void readAll(QString&);
    void calculateAvg();

private:
    double m_avg = 0.0;
    std::vector<std::shared_ptr<Grade>> exams;
};

#endif // AVERAGE_H
