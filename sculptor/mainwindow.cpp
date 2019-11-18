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
    /* *******************  para esfera     ************************ */
    connect(ui->sliderEsfera,SIGNAL(valueChanged(int)),ui->spinEsfera,SLOT(setValue(int)));
    connect(ui->spinEsfera,SIGNAL(valueChanged(int)),ui->sliderEsfera,SLOT(setValue(int)));
    connect(ui->sliderEsfera,SIGNAL(valueChanged(int)),this,SLOT(mudarRaioEsfera(int)));
    /* ************************************************************* */

//ui->lcdNumber->display(x);
    /* ******************* detecta o click do mouse *************** */
    connect(ui->widget,SIGNAL(mouseX(int)),ui->lcdX,SLOT(display(int))); //usado apenas para desenvolver, pode ser removido
    connect(ui->widget,SIGNAL(mouseY(int)),ui->lcdY,SLOT(display(int))); //usado apenas para desenvolver, pode ser removido
    /* *********************************************************** */


    /* ********************** planos ****************************** */
    connect(ui->sliderPlanoZ,SIGNAL(valueChanged(int)),ui->lcdPlanoZ,SLOT(display(int)));
    connect(ui->sliderPlanoZ,SIGNAL(valueChanged(int)),this,SLOT(mudarPlanoZ(int)));
    /* ************************************************************ */

    connect(ui->Button_putbox,&QPushButton::clicked, ui->widget, &Plotter::mudarParaPutbox);
    connect(ui->Button_cutsphere,&QPushButton::clicked, ui->widget, &Plotter::mudarParaCutSphere);
}

void MainWindow:: mudarPlanoZ(int z)
{
    ui->widget->planoAtualZ(z);
}

void MainWindow::mudarRaioEsfera(int r)
{
    ui->widget->mudarRaioEsfera(r);

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
       //matriz=new Sculptor(tx,ty,tz);
       ui->widget->mudarTamanho(tx,ty,tz); //redimensiona o widget
       ui->sliderPlanoZ->setMaximum(tz-1);
    }




}

void MainWindow::cores()
{
   QColor p=QColorDialog::getColor(Qt::white,this,"Escolha uma cor");
   // QColor p=QColorDialog::getColor();
}

