#include "definirsculptor.h"
#include "ui_definirsculptor.h"
#include "sculptor.h"
DefinirSculptor::DefinirSculptor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DefinirSculptor)
{
    ui->setupUi(this);
    connect(ui->botaoCancelar,&QPushButton::clicked,this,&DefinirSculptor::done);
    connect(ui->botaoSalvar,&QPushButton::clicked,this,&DefinirSculptor::salvar);
}

DefinirSculptor::~DefinirSculptor()
{
    delete ui;
}

void DefinirSculptor::salvar()
{
    int x=ui->spinX->value();
    int y=ui->spinY->value();
    int z=ui->spinZ->value();
    Sculptor(x,y,z);
    this->done(0);
}
