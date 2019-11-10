#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <definirsculptor.h>
#include <QColorDialog>
#include <QColor>
#include <QDialog>
#include <QDebug>
#include <plotter.h>
#include "sculptor.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->showMaximized();
    connect(ui->botaoNew,&QPushButton::clicked,this,&MainWindow::novoProjeto);
    connect(ui->botaoCores,&QPushButton::clicked,this,&MainWindow::cores);
    //connect(ui->sliderEsfera,&QAbstractSlider ::valueChanged,ui->lcdEsfera,&QLCDNumber::display);
   // connect(ui->sliderEsfera,SIGNAL(valueChanged(int)),ui->lcdEsfera,SLOT(display(int)));
    //connect(ui->sliderEsfera,SIGNAL(valueChanged(int)),this,SLOT(raioEsfera(int)));
    connect(ui->sliderEsfera,SIGNAL(valueChanged(int)),ui->spinEsfera,SLOT(setValue(int)));
    connect(ui->spinEsfera,SIGNAL(valueChanged(int)),ui->sliderEsfera,SLOT(setValue(int)));
    //ui->lcdNumber->display(x);
    connect(ui->widget,SIGNAL(mouseX(int)),ui->lcdX,SLOT(display(int))); //usado apenas para desenvolver, pode ser removido
    connect(ui->widget,SIGNAL(mouseY(int)),ui->lcdY,SLOT(display(int))); //usado apenas para desenvolver, pode ser removido

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::novoProjeto()
{
    DefinirSculptor janela;
    if(janela.exec()== QDialog::Accepted)
    {
       tx=janela.getX();
       ty=janela.getY();
       tz=janela.getZ();

       ui->widget->mudarTamanho(tx,ty,tz); //redimensiona o widget
    }




}

void MainWindow::cores()
{
   QColor p=QColorDialog::getColor(Qt::white,this,"Escolha uma cor");
   // QColor p=QColorDialog::getColor();
}

