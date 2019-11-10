#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>

class Plotter : public QWidget
{
    Q_OBJECT
    int x,y,z,px,py;

public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
   void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mudarTamanho(int tx,int ty,int tz);

signals:
    void mouseX(int);
    void mouseY(int);
public slots:
};

#endif // PLOTTER_H
