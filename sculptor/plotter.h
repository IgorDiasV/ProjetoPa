#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include "sculptor.h"
class Plotter : public QWidget
{
    Q_OBJECT
    int x,y,z,px,py,raioEsfera,vz;
    Sculptor *matriz;

public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mudarTamanho(int tx,int ty,int tz);
    void mudarRaioEsfera(int r);
    void planoAtualZ(int z);
    //friend class Sculptor;

signals:
    void mouseX(int);
    void mouseY(int);
public slots:
};

#endif // PLOTTER_H
