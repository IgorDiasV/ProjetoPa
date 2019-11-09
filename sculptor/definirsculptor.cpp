#include "definirsculptor.h"
#include "ui_definirsculptor.h"

DefinirSculptor::DefinirSculptor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DefinirSculptor)
{
    ui->setupUi(this);
}
int DefinirSculptor::getX()
{
    return ui->spinX->value();
}

int DefinirSculptor::getY()
{
    return ui->spinY->value();
}

int DefinirSculptor::getZ()
{
    return ui->spinZ->value();
}
DefinirSculptor::~DefinirSculptor()
{
    delete ui;
}
