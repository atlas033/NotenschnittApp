#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "grade.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushAdd_clicked()
{
    // error handling
    abc->addGrade(new Grade(ui->subjectNameEdit->text(), ui->gradeEdit->text().toDouble(), ui->weightEdit->text().toDouble()) );
        // need function taht converts german float to english notation
    ui->subjectNameEdit->clear();
    ui->gradeEdit->clear();
    ui->weightEdit->clear();
    ui->avgDisplay->SetText( abc->getAvg()); // number method in qstring
}
