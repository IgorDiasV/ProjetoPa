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
#include <string.h>
#include "abrirprojeto.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();
    //connect(ui->botaoNew,&QPushButton::clicked,this,&MainWindow::novoProjeto);
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
    connect(ui->Button_cutvoxel, &QPushButton::clicked, ui->widget, &Plotter::mudarParaCutvoxel);
    connect(ui->Button_putbox, &QPushButton::clicked, ui->widget, &Plotter::mudarParaPutbox);
    connect(ui->Button_cutbox, &QPushButton::clicked, ui->widget, &Plotter::mudarParaCutbox);
    connect(ui->Button_cutsphere, &QPushButton::clicked, ui->widget, &Plotter::mudarParaCutsphere);
    connect(ui->Button_putsphere, &QPushButton::clicked, ui->widget, &Plotter::mudarParaPutsphere);
    connect(ui->Button_putellipsoid, &QPushButton::clicked, ui->widget, &Plotter::mudarParaPutellipsoid);
    connect(ui->Button_cutellipsoid, &QPushButton::clicked, ui->widget, &Plotter::mudarParaCutellipsoid);

    /* ************************************************************************** */
    connect(ui->checkBox,&QCheckBox::stateChanged,this,&MainWindow::mudarVisibilidade);

    /*******************************************************************/
    connect(ui->Button_MeshLab, &QPushButton::clicked, ui->widget, &Plotter::abrirNoMeshlab);

    connect(ui->sliderR,SIGNAL(valueChanged(int)),this,SLOT(corSlider()));
    connect(ui->sliderG,SIGNAL(valueChanged(int)),this,SLOT(corSlider()));
    connect(ui->sliderB,SIGNAL(valueChanged(int)),this,SLOT(corSlider()));

    /*****************  hover ************************************* */
    ui->Button_cutbox->setStyleSheet("QPushButton:focus {border: 3px dashed black}");
    ui->Button_putbox->setStyleSheet("QPushButton:focus {border: 3px dashed black}");
    ui->Button_cutvoxel->setStyleSheet("QPushButton:focus {border: 3px dashed black}");
    ui->Button_putvoxel->setStyleSheet("QPushButton:focus {border: 3px dashed black}");
    ui->Button_cutsphere->setStyleSheet("QPushButton:focus {border: 3px dashed black}");
    ui->Button_cutellipsoid->setStyleSheet("QPushButton:focus {border: 3px dashed black}");
    ui->Button_putsphere->setStyleSheet("QPushButton:focus {border: 3px dashed black}");
    ui->Button_putellipsoid->setStyleSheet("QPushButton:focus {border: 3px dashed black}");
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
/*
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
*/
void MainWindow::cores()
{
    QColor p=QColorDialog::getColor(Qt::white,this,"Escolha uma cor");
    ui->widget->definirCor(p.red(), p.green(), p.blue());
    string css="QPushButton {background-color: rgb(";
    css+= std::to_string(p.red());
    css+=",";
    css+=std::to_string(p.green());
    css+=",";
    css+=std::to_string(p.blue());
    css+=")}";

    ui->botaoCores->setStyleSheet(QString::fromStdString(css));
    ui->sliderR->setValue(p.red());
    ui->sliderG->setValue(p.green());
    ui->sliderB->setValue(p.blue());

}

void MainWindow::mudarVisibilidade()
{
    ui->widget->visibilidadeDaGrade(ui->checkBox->isChecked());
}

void MainWindow::corSlider()
{
    string css="QPushButton {background-color: rgb(";
    css+= std::to_string(ui->sliderR->value());
    css+=",";
    css+=std::to_string(ui->sliderG->value());
    css+=",";
    css+=std::to_string(ui->sliderB->value());
    css+=")}";
    ui->botaoCores->setStyleSheet(QString::fromStdString(css));
    ui->widget->definirCor(ui->sliderR->value(),ui->sliderG->value(),ui->sliderB->value()) ;
}

void MainWindow::on_actionAbrir_Projeto_triggered()
{
    QString nomeDoArquivo=QFileDialog::getOpenFileName();
    if(nomeDoArquivo!=NULL){
        ui->widget->abrirProjeto(nomeDoArquivo.toStdString());
    }
    ui->sliderPlanoZ->setMaximum(ui->widget->getDz()-1);
    ui->sliderPlanoZ->setValue(0);
}

void MainWindow::on_actionSalvar_Projeto_triggered()
{
    QString nomeDoArquivo=QFileDialog::getSaveFileName();
    if(nomeDoArquivo!=NULL){
        ui->widget->salvarProjeto(nomeDoArquivo.toStdString());
    }
}

void MainWindow::on_actionExportar_Projeto_triggered()
{
    QString nomeDoArquivo=QFileDialog::getSaveFileName();
    if(nomeDoArquivo!=NULL){
        ui->widget->exportarProjeto(nomeDoArquivo.toStdString());
    }
}

void MainWindow::on_actionNovo_Projeto_triggered()
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
        ui->sliderEsfera->setMaximum(tx);
        ui->SliderRx->setMaximum(tx);
        ui->SliderRy->setMaximum(tx);
        ui->SliderRz->setMaximum(tx);
        ui->SliderDimX->setMaximum(tx);
        ui->SliderDimY->setMaximum(tx);
        ui->SliderDimZ->setMaximum(tx);
    }
}
