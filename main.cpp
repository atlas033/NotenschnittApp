#include "mainwindow.h"
#include "grade.h"
#include "average.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    Average(180);
    averageDisplay->setText("note");

}
