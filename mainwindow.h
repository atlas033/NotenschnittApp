#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "grade.h"
#include "average.h"

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushAdd_clicked();

    void on_weightEdit_returnPressed();

private:
    Ui::MainWindow *ui;
    Average* abc;
};
#endif // MAINWINDOW_H
