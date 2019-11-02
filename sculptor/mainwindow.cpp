#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <definirsculptor.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();
    connect(ui->botaoNew,&QPushButton::clicked,this,&MainWindow::novoProjeto);
    //ui->lcdNumber->display(x);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::novoProjeto()
{
    DefinirSculptor janela;
    janela.exec();

}
