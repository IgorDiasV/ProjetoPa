#include "plotter.h"
#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QMouseEvent>
#include <cmath>
#include "figurageometrica.h"
#include "classes.h"
#include <stdlib.h>

FiguraGeometrica *fig;
Plotter::Plotter(QWidget *parent) : QWidget(parent)
{
    x=10;
    y=10;
    z=10;
    vz=0;
    raioEsfera=1;
    matriz= new Sculptor(x,y,z);
    // setMouseTracking(true);
    putvoxel = false;
    cutvoxel = false;
    putbox = false;
    cutbox =  false;
    putsphere = true;
    cutsphere = false;
    putellipsoid = false;
    cutellipsoid = false;
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
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            if(matriz->getisOn(i,j,vz))
            {
                //painter.drawRect(px*(larg/x),py*(alt/y),larg/x,alt/y); // pinta o quadrado
                painter.drawRect(i*(larg/x),j*(alt/y),larg/x,alt/y); // pinta o quadrado

            }
        }
    }

  /*  for(int i=0;i<larg;i+=larg/x) //desenhas as linhas verticais
    {
        painter.drawLine(i,0,i,alt-2);
    }
    for(int i=0;i<alt;i+=alt/y) //desenha as linhas horizontais
    {
        painter.drawLine(0,i,larg-2,i);
    }*/

}

void Plotter::mousePressEvent(QMouseEvent *event)
{

    px=(event->x())/(width()/x);   //calcula em que quadrado na horizontal se encontra o mouse
    py=(event->y())/(height()/y); //calcula em que quadrado na vertica se encontra o mouse
    emit mouseX(px);
    emit mouseY(py);

    if(putsphere){
        fig = new PutSphere(px,py,vz,raioEsfera,1,1,1,1);
        fig->draw(*matriz);
        //matriz->putVoxel(px,py,1);
    }else if(cutsphere)
    {
       fig =new CutSphere(px,py,vz,raioEsfera);
       fig->draw(*matriz);
    }else if(putbox){
        fig = new PutBox(px,px+3,py,py+2,vz,vz+5,1,1,1,1);
        fig->draw(*matriz);
        //matriz->putVoxel(px,py,1);
    }

    //fig= new PutSphere(px,py,vz,raioEsfera,1,1,1,1);
    fig->draw(*matriz);
    //matriz->putVoxel(px,py,1);

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
    //matriz->putVoxel(px,py,1);
    if(putsphere){
        fig = new PutSphere(px,py,vz,raioEsfera,1,1,1,1);
        fig->draw(*matriz);
        //matriz->putVoxel(px,py,1);
    }else if(cutsphere)
    {
       fig =new CutSphere(px,py,vz,raioEsfera);
       fig->draw(*matriz);
    }else if(putbox){
        fig = new PutBox(px,px+3,py,py+2,vz,vz+5,1,1,1,1);
        fig->draw(*matriz);
        //matriz->putVoxel(px,py,1);
    }
    repaint();
}


void Plotter::mudarTamanho(int tx, int ty, int tz)
{
    delete matriz;
    x=tx;
    y=ty;
    z=tz;
    vz =0;
    matriz=new Sculptor(x,y,z);
    repaint();
}

void Plotter::mudarRaioEsfera(int r)
{
    raioEsfera=r;
}

void Plotter::planoAtualZ(int z)
{
    vz=z;
    repaint();
}

void Plotter::mudarParaPutbox()
{
    putvoxel = false;
    cutvoxel = false;
    putbox = true;
    cutbox =  false;
    putsphere = false;
    cutsphere = false;
    putellipsoid = false;
    cutellipsoid = false;

}
void Plotter::mudarParaCutSphere()
{
    putvoxel = false;
    cutvoxel = false;
    putbox = false;
    cutbox =  false;
    putsphere = false;
    cutsphere = true;
    putellipsoid = false;
    cutellipsoid = false;
}

