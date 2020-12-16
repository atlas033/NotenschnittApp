#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "grade.h"
#include "average.h"

#include <memory>
#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void saveFile();

private slots:
    void on_pushAdd_clicked();

    void on_weightEdit_returnPressed();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionLoad_Profile_triggered();

    void on_actionQuit_triggered();

    void on_actionNew_triggered();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<Average> abc;
    QString currentFile;
};
#endif // MAINWINDOW_H
