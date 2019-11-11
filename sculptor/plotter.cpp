#include "plotter.h"
#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QMouseEvent>
#include <cmath>
Plotter::Plotter(QWidget *parent) : QWidget(parent)
{
    x=10;
    y=10;
    z=10;
    // setMouseTracking(true);
}
void Plotter::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    QBrush brush;

    int larg = width() - width()%x;
    int alt = height() - height()%y;

    pen.setColor(QColor(0,0,0));
    painter.setPen(pen);
    painter.drawRect(0,0,larg-2,alt-2);
    brush.setColor(QColor(255,255,0));
    brush.setStyle(Qt::SolidPattern);
    //painter.setPen(pen);
    painter.setBrush(brush);

//    painter.drawRect(px*(width()/x),py*(height()/y),width()/x,height()/y); // desenhar o contorno do widget
//    for(int i=0;i<width();i+=width()/x) //desenhas as linhas verticais
//    {
//        painter.drawLine(i,0,i,height());
//    }
//    for(int i=0;i<height();i+=height()/y) //desenha as linhas horizontais
//    {
//        painter.drawLine(0,i,width(),i);
//    }

    painter.drawRect(px*(larg/x),py*(alt/y),larg/x,alt/y); // desenhar o contorno do widget

    for(int i=0;i<larg;i+=larg/x) //desenhas as linhas verticais
    {
        painter.drawLine(i,0,i,alt-2);
    }
    for(int i=0;i<alt;i+=alt/y) //desenha as linhas horizontais
    {
        painter.drawLine(0,i,larg-2,i);
    }

}
void Plotter::mousePressEvent(QMouseEvent *event)
{
    px=(event->x())/(width()/x);   //calcula em que quadrado na horizontal se encontra o mouse
    py=(event->y())/(height()/y); //calcula em que quadrado na vertica se encontra o mouse
    emit mouseX(px);
    emit mouseY(py);
    repaint();



}

void Plotter::mudarTamanho(int tx, int ty, int tz)
{
    x=tx;
    y=ty;
    z=tz;
    repaint();
}
void Plotter::mouseMoveEvent(QMouseEvent *event)
{
    //int px=ceil((width()-1)/(width()-event->x()));
    px=(event->x())/(width()/x); //calcula em que quadrado na horizontal se encontra o mouse
    py=(event->y())/(height()/y); //calcula em que quadrado na vertica se encontra o mouse
    emit mouseX(px);


    //emit mouseX(event->x());

    emit mouseY(py);
    repaint();
}

