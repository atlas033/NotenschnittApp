#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), abc(new Average())
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
        // need function that converts german float to english notation
    ui->subjectNameEdit->clear();
    ui->gradeEdit->clear();
    ui->weightEdit->clear();
    ui->avgDisplay->setText(QString::number(abc->getAvg(),'g', 2));
}

void MainWindow::on_weightEdit_returnPressed()
{
    abc->addGrade(new Grade(ui->subjectNameEdit->text(), ui->gradeEdit->text().toDouble(), ui->weightEdit->text().toDouble()) );
        // need function that converts german float to english notation
    ui->subjectNameEdit->clear();
    ui->gradeEdit->clear();
    ui->weightEdit->clear();
    ui->avgDisplay->setText(QString::number(abc->getAvg(),'g', 2));
}

void MainWindow::on_actionSave_triggered()
{

}

void MainWindow::on_actionSave_As_triggered()
{

}

void MainWindow::on_actionLoad_Profile_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    // do stuff
    file.close();
}

void MainWindow::on_actionQuit_triggered()
{

}

void MainWindow::on_actionNew_triggered()
{

}
