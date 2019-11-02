#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <definirsculptor.h>
#include <QColorDialog>
#include <QColor>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();
    connect(ui->botaoNew,&QPushButton::clicked,this,&MainWindow::novoProjeto);
    connect(ui->botaoCores,&QPushButton::clicked,this,&MainWindow::cores);
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

void MainWindow::cores()
{
   QColor p=QColorDialog::getColor(Qt::white,this,"Escolha uma cor");
   // QColor p=QColorDialog::getColor();
}
