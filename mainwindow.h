#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QListWidget"

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
    void on_Add_clicked();

    void on_Remove_clicked();

    void on_pushButton_Up_clicked();

    void on_pushButtonDown_clicked();

    void on_Save_clicked();

    void on_OpenLoad_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
