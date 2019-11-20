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

    /* *******************  para esfera  ************************ */
    connect(ui->sliderEsfera,SIGNAL(valueChanged(int)),ui->spinEsfera,SLOT(setValue(int)));
    connect(ui->spinEsfera,SIGNAL(valueChanged(int)),ui->sliderEsfera,SLOT(setValue(int)));
    connect(ui->sliderEsfera,SIGNAL(valueChanged(int)),this,SLOT(mudarRaioEsfera(int)));

    /* *******************  para a caixa  *********************** */
    connect(ui->SliderDimX, SIGNAL(valueChanged(int)), ui->lcdNumberDimX, SLOT(display(int)));
    connect(ui->SliderDimX, SIGNAL(valueChanged(int)), this, SLOT(mudarDimBoX(int)));
    connect(ui->SliderDimY, SIGNAL(valueChanged(int)), ui->lcdNumberDimY, SLOT(display(int)));
    connect(ui->SliderDimY, SIGNAL(valueChanged(int)), this, SLOT(mudarDimBoY(int)));
    connect(ui->SliderDimZ, SIGNAL(valueChanged(int)), ui->lcdNumberDimZ, SLOT(display(int)));
    connect(ui->SliderDimZ, SIGNAL(valueChanged(int)), this, SLOT(mudarDimBoZ(int)));

    /********************* para elipse ***************************/
    connect(ui->SliderRx, SIGNAL(valueChanged(int)), ui->lcdNumberRx, SLOT(display(int)));
    connect(ui->SliderRx, SIGNAL(valueChanged(int)), this, SLOT(mudarRaioX(int)));
    connect(ui->SliderRy, SIGNAL(valueChanged(int)), ui->lcdNumberRy, SLOT(display(int)));
    connect(ui->SliderRy, SIGNAL(valueChanged(int)), this, SLOT(mudarRaioY(int)));
    connect(ui->SliderRz, SIGNAL(valueChanged(int)), ui->lcdNumberRz, SLOT(display(int)));
    connect(ui->SliderRz, SIGNAL(valueChanged(int)), this, SLOT(mudarRaioZ(int)));

    /* ******************* detecta o click do mouse *************** */
    connect(ui->widget,SIGNAL(mouseX(int)),ui->lcdX,SLOT(display(int))); //usado apenas para desenvolver, pode ser removido
    connect(ui->widget,SIGNAL(mouseY(int)),ui->lcdY,SLOT(display(int))); //usado apenas para desenvolver, pode ser removido
    /* *********************************************************** */


    /* ********************** planos ****************************** */
    connect(ui->sliderPlanoZ,SIGNAL(valueChanged(int)),ui->lcdPlanoZ,SLOT(display(int)));
    connect(ui->sliderPlanoZ,SIGNAL(valueChanged(int)),this,SLOT(mudarPlanoZ(int)));

    /* ********************** formas geométricas ********************************* */
    connect(ui->Button_putvoxel, &QPushButton::clicked, ui->widget, &Plotter::mudarParaPutvoxel);
    connect(ui->Button_putbox,&QPushButton::clicked, ui->widget, &Plotter::mudarParaPutbox);
    connect(ui->Button_cutsphere,&QPushButton::clicked, ui->widget, &Plotter::mudarParaCutsphere);
    connect(ui->Button_putsphere,&QPushButton::clicked, ui->widget, &Plotter::mudarParaPutsphere);

}

void MainWindow:: mudarPlanoZ(int z)
{
    ui->widget->planoAtualZ(z);
}

void MainWindow::mudarRaioEsfera(int r)
{
    ui->widget->mudarRaioEsfera(r);

}

void MainWindow::mudarDimBoX(int dimx)
{
    ui->widget->mudarDimBoX(dimx);
}

void MainWindow::mudarDimBoY(int dimy)
{
    ui->widget->mudarDimBoY(dimy);
}

void MainWindow::mudarDimBoZ(int dimz)
{
    ui->widget->mudarDimBoZ(dimz);
}

void MainWindow::mudarRaioX(int rx)
{
    ui->widget->mudarRaioX(rx);
}

void MainWindow::mudarRaioY(int ry)
{
    ui->widget->mudarRaioY(ry);
}

void MainWindow::mudarRaioZ(int rz)
{
    ui->widget->mudarRaioZ(rz);
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

