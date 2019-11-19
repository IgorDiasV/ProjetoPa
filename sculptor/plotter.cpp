#include "plotter.h"
#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QMouseEvent>
#include <cmath>
#include "figurageometrica.h"
#include "classes.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
FiguraGeometrica *fig;
Plotter::Plotter(QWidget *parent) : QWidget(parent)
{
    x=100;
    y=100;
    z=100;
    vz=0;
    raioEsfera=1;
    DimX=1;
    DimY=1;
    DimZ=1;
    matriz= new Sculptor(x,y,z);
    // setMouseTracking(true);
    putvoxel = true;
    cutvoxel = false;
    putbox = false;
    cutbox =  false;
    putsphere = true;
    cutsphere = false;
    putellipsoid = false;
    cutellipsoid = false;
    abrirProjeto("robo");
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
    painter.drawRect(0,0,larg,alt);
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
    }else if(cutsphere){
       fig =new CutSphere(px,py,vz,raioEsfera);
       fig->draw(*matriz);
    }else if(putbox){
        fig = new PutBox(px,px+DimX,py,py+DimY,vz,vz+DimZ,1,1,1,1);
        fig->draw(*matriz);
        //matriz->putVoxel(px,py,1);
    }else if(putvoxel){
        fig = new PutVoxel(px,py,vz,1,1,1,1);
    }

    //fig= new PutSphere(px,py,vz,raioEsfera,1,1,1,1);
   // fig->draw(*matriz);
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
    }else if(cutsphere){
       fig =new CutSphere(px,py,vz,raioEsfera);
       fig->draw(*matriz);
    }else if(putbox){
        fig = new PutBox(px,px+DimX,py,py+DimY,vz,vz+DimZ,1,1,1,1);
        fig->draw(*matriz);
        //matriz->putVoxel(px,py,1);
    }else if(putvoxel){
        fig = new PutVoxel(px,py,vz,1,1,1,1);
    }

    repaint();
}


void Plotter::mudarTamanho(int tx, int ty, int tz)
{
    delete matriz;
    x=tx;
    y=ty;
    z=tz;
    vz=0;
    matriz=new Sculptor(x,y,z);
    repaint();
}

void Plotter::mudarRaioEsfera(int r)
{
    raioEsfera=r;
}

void Plotter::mudarDimBoX(int dimx)
{
    DimX = dimx;
}

void Plotter::mudarDimBoY(int dimy)
{
    DimY = dimy;
}

void Plotter::mudarDimBoZ(int dimz)
{
    DimZ = dimz;
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

void Plotter::mudarParaPutsphere()
{
    putvoxel = false;
    cutvoxel = false;
    putbox = false;
    cutbox =  false;
    putsphere = true;
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
void Plotter::abrirProjeto(string arquivo)
{
    int dimx=1,dimy=1,dimz=1;
    vector<FiguraGeometrica*> fig;
    string comando,str;
    ifstream fin;
    fin.open(arquivo);
    if(!fin.is_open())
    {
        cout<<"error ao abrir o arquivo"<<endl;
        exit(0);
    }
    while(1)
    {
        getline(fin,str);
        if(fin.good())
        {
            stringstream ss(str);
            ss>>comando;
            ///cout<<comando<<endl;
            if(comando.compare("dim")==0){
                ss>>dimx>>dimy>>dimz;
            }else if(comando.compare("putvoxel")==0){
                int x,y,z;
                float r,g,b,a;
                ss>>x>>y>>z>>r>>g>>b>>a;
                fig.push_back(new PutVoxel(x,y,z,r,g,b,a));
            }else if(comando.compare("cutvoxel")==0){
                int x,y,z;
                ss>>x>>y>>z;
                fig.push_back(new CutVoxel(x,y,z));
            }else if (comando.compare("putbox")==0){
                int x0,y0,z0,x1,y1,z1;
                float r,g,b,a;
                ss>>x0>>x1>>y0>>y1>>z0>>z1>>r>>g>>b>>a;
                fig.push_back(new PutBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
            }else if(comando.compare("cutbox")==0){
                int x0,y0,z0,x1,y1,z1;
                ss>>x0>>x1>>y0>>y1>>z0>>z1;
                fig.push_back(new CutBox(x0,x1,y0,y1,z0,z1));
            }else if(comando.compare("putsphere")==0){
                int x0, y0, z0, raio;
                float r, g, b, a;
                ss>>x0>>y0>>z0>>raio>>r>>g>>b>>a;
                fig.push_back(new PutSphere(x0,y0,z0,raio,r,g,b,a));
            }else if(comando.compare("cutsphere")==0){
                int x0, y0, z0, raio;
                ss>>x0>>y0>>z0>>raio;
                fig.push_back(new CutSphere(x0,y0,z0,raio));
            }else if(comando.compare("putellipsoid")==0){
                int x0, y0, z0, raiox, raioy, raioz;
                float r, g, b, a;
                ss>>x0>>y0>>z0>>raiox>>raioy>>raioz>>r>>g>>b>>a;
                fig.push_back(new PutEllipsoid(x0,y0,z0,raiox,raioy,raioz,r,g,b,a));
            }else if(comando.compare("cutellipsoid")==0){
                int x0, y0, z0, raiox, raioy, raioz;
                ss>>x0>>y0>>z0>>raiox>>raioy>>raioz;
                fig.push_back(new CutEllipsoid(x0,y0,z0,raiox,raioy,raioz));
            }
        }else {
            break;
        }
    }
    //Sculptor p(dimx,dimy,dimz);
    for(unsigned int i=0;i<fig.size();i++)
    {
        fig[i]->draw(*matriz);
    }
   // p.writeOFF("novo.off");
    //system("geomview novo.off");

}

