#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), abc(std::make_shared<Average>())
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    this->saveFile();
    delete ui;
}

void MainWindow::saveFile()
{
    QString fileName;
    // If we don't have a filename from before, get one.
    if (currentFile.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(this, "Save");
        currentFile = fileName;
    } else {
        fileName = currentFile;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = abc->toPlainText();
    out << text;
    file.close();
}

void MainWindow::on_pushAdd_clicked()
{
    // error handling

    abc->addGrade(std::make_shared<Grade>(ui->subjectNameEdit->text(), ui->gradeEdit->text().toDouble(), ui->weightEdit->text().toDouble()) );
        // need function that converts german float to english notation
    ui->subjectNameEdit->clear();
    ui->gradeEdit->clear();
    ui->weightEdit->clear();
    abc->calculateAvg();
    ui->avgDisplay->setText(QString::number(abc->getAvg(),'g', 2));
}


void MainWindow::on_weightEdit_returnPressed()
{
    abc->addGrade(std::make_shared<Grade>(ui->subjectNameEdit->text(), ui->gradeEdit->text().toDouble(), ui->weightEdit->text().toDouble()) );
        // need function that converts german float to english notation
    ui->subjectNameEdit->clear();
    ui->gradeEdit->clear();
    ui->weightEdit->clear();
    abc->calculateAvg();
    ui->avgDisplay->setText(QString::number(abc->getAvg(),'g', 2));
}


void MainWindow::on_actionSave_triggered()
{
    this->saveFile();
}

void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = abc->toPlainText();
    out << text;
    file.close();
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
    QString text = in.readAll();
    abc->readAll(text);
    file.close();
    ui->avgDisplay->setText(QString::number(abc->getAvg(),'g', 2));
}

void MainWindow::on_actionQuit_triggered()
{
    QCoreApplication::quit();
}

void MainWindow::on_actionNew_triggered()
{
    abc = std::make_shared<Average>();
    ui->subjectNameEdit->clear();
    ui->gradeEdit->clear();
    ui->weightEdit->clear();
    ui->avgDisplay->setText(QString::number(abc->getAvg(),'g', 2));
}
