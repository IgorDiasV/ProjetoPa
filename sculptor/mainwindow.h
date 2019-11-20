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
    void mudarRaioX(int rx);
    void mudarRaioY(int ry);
    void mudarRaioZ(int rz);
    //outros
    void novoProjeto();
    void mudarPlanoZ(int z);
    void cores();
    void mudarVisibilidade();
    void corSlider();
private slots:
    void on_actionAbrir_Projeto_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
