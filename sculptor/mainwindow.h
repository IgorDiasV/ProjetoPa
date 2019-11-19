#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sculptor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int tx,ty,tz;
   // Sculptor *matriz;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void putVoxel(int x,int y);
    ~MainWindow();
public slots:
    //esfera
    void mudarRaioEsfera(int r);
    //caixa
    void mudarDimBoX(int dimx);
    void mudarDimBoY(int dimy);
    void mudarDimBoZ(int dimz);
    //elipse

    //outros
    void novoProjeto();
    void mudarPlanoZ(int z);
    void cores();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
