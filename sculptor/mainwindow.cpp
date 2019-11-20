#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <definirsculptor.h>
#include <QColorDialog>
#include <QColor>
#include <QDialog>
#include <QDebug>
#include <plotter.h>
#include "sculptor.h"
#include <QFileDialog>
#include <string>
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

//ui->lcdNumber->display(x);
    /* ******************* detecta o click do mouse *************** */
    connect(ui->widget,SIGNAL(mouseX(int)),ui->lcdX,SLOT(display(int))); //usado apenas para desenvolver, pode ser removido
    connect(ui->widget,SIGNAL(mouseY(int)),ui->lcdY,SLOT(display(int))); //usado apenas para desenvolver, pode ser removido
    /* *********************************************************** */


    /* ********************** planos ****************************** */
    connect(ui->sliderPlanoZ,SIGNAL(valueChanged(int)),ui->lcdPlanoZ,SLOT(display(int)));
    connect(ui->sliderPlanoZ,SIGNAL(valueChanged(int)),this,SLOT(mudarPlanoZ(int)));

    /* ********************** formas geométricas ********************************* */
    connect(ui->Button_putbox,&QPushButton::clicked, ui->widget, &Plotter::mudarParaPutbox);
    connect(ui->Button_cutsphere,&QPushButton::clicked, ui->widget, &Plotter::mudarParaCutSphere);
    connect(ui->Button_putsphere,&QPushButton::clicked, ui->widget, &Plotter::mudarParaPutsphere);
    /* ************************************************************************** */
    connect(ui->checkBox,&QCheckBox::stateChanged,this,&MainWindow::mudarVisibilidade);
   // connect(ui->checkBox,SIGNAL(stateChanged),this,SLOT(mudarVisibilidade));
   // qDebug()<<ui->checkBox->isTristate();
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

void MainWindow::mudarVisibilidade()
{
    ui->widget->visibilidadeDaGrade(ui->checkBox->isChecked());
  //qDebug()<<ui->checkBox->isChecked();
}


void MainWindow::on_actionAbrir_Projeto_triggered()
{
   QString nomeDoArquivo=QFileDialog::getOpenFileName();
   ui->widget->abrirProjeto(nomeDoArquivo.toStdString());

}
