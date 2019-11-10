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

    pen.setColor(QColor(0,0,0));
    painter.setPen(pen);
    painter.drawRect(0,0,width()-2,height()-2);
    brush.setColor(QColor(255,255,0));
    brush.setStyle(Qt::SolidPattern);
    //painter.setPen(pen);
    painter.setBrush(brush);

    painter.drawRect(px*(width()/x),py*(height()/y),width()/x,height()/y);
    for(int i=0;i<width();i+=width()/x)
    {
        painter.drawLine(i,0,i,height());
    }
    for(int i=0;i<height();i+=height()/y)
    {
        painter.drawLine(0,i,width(),i);
    }

}
void Plotter::mousePressEvent(QMouseEvent *event)
{
    px=ceil((event->x())/(width()/x));
    py=ceil((event->y())/(height()/y));
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
    px=ceil((event->x())/(width()/x));
    py=ceil((event->y())/(height()/y));

    emit mouseX(px);
    //emit mouseX(event->x());

    emit mouseY(py);
    repaint();
}

