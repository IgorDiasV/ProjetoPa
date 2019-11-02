#ifndef DEFINIRSCULPTOR_H
#define DEFINIRSCULPTOR_H

#include <QDialog>

namespace Ui {
class DefinirSculptor;
}

class DefinirSculptor : public QDialog
{

    Q_OBJECT

public:
    explicit DefinirSculptor(QWidget *parent = nullptr);

    ~DefinirSculptor();
public slots:
    void salvar();
private:
    Ui::DefinirSculptor *ui;
};

#endif // DEFINIRSCULPTOR_H
