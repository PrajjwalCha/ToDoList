#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QDebug"


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


void MainWindow::on_Add_clicked()
{
    QString tasks = ui->lineEdit->text();
    if(!tasks.isEmpty()){
        ui->listWidget->addItem(tasks);
        ui->lineEdit->clear();
    }
}


void MainWindow::on_Remove_clicked()
{
    //alternatives 1***********
   /*QList<QListWidgetItem*> item =ui->listWidget->selectedItems();
   foreach (QListWidgetItem *item, item) {
       delete ui->listWidget->takeItem(ui->listWidget->row(item));
    }*/
    //alternative 2********
    qDeleteAll(ui->listWidget->selectedItems());
}

void MainWindow::on_pushButton_Up_clicked()
{
    int index ;
    QListWidgetItem* current = ui->listWidget->currentItem();
    index = ui->listWidget->row(current);
    QListWidgetItem* up = ui->listWidget->takeItem(index -1);
    ui->listWidget->insertItem(index -1, current);
    ui->listWidget->insertItem(index , up);

}


void MainWindow::on_pushButtonDown_clicked()
{
    int index ;
    QListWidgetItem* current = ui->listWidget->currentItem();
    index = ui->listWidget->row(current);
    QListWidgetItem* Down = ui->listWidget->takeItem(index +1);
    ui->listWidget->insertItem(index +1, current);
    ui->listWidget->insertItem(index , Down);

}
QString Path = "E:/QTProject/ToDo/list.txt";

void MainWindow::on_Save_clicked()
{
    QFile file(Path);
    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream stream(&file);
        for(int i = 0 ; i <ui->listWidget->count();++i ){
            QListWidgetItem* item = ui->listWidget->item(i);
            QString text = item->text();
            stream<<text<<Qt::endl;
        }
        qDebug()<<"File saveed sucessfully";
    }else{
        qDebug()<<"Failed to save the list";
    }

}


void MainWindow::on_OpenLoad_clicked()
{
    QFile file (Path);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QTextStream stream(&file);
        ui->listWidget->clear();
        while(!stream.atEnd()){
            QString item  = stream.readLine();
            ui->listWidget->addItem(item);
        }
        file.close();
    }else{
        qDebug()<<"failed to Loading file ";
    }
}

