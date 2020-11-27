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
    return;
}

QString Average::toPlainText()
{
    QString text = QString::number(m_avg) + " ";
    for(Grade* val:exams){
        text += "\n" + val->name + " " + QString::number(val->grade) + " " +  QString::number(val->weight) ;
    }
    return text;
}

void Average::readAll(QString& text)
{
    QTextStream in(&text);
    in >> m_avg;
    while(!in.atEnd())
    {
        QString x;
        double y,z;
        in >> x >> y >> z;
        this->addGrade(new Grade(x, y, z));
    }
    return;
}

