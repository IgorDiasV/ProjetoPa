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
#include <QDebug>

using namespace std;
FiguraGeometrica *fig;
Plotter::Plotter(QWidget *parent) : QWidget(parent)
{
    x=10;
    y=10;
    z=10;
    vz=0;
    raioEsfera=1;
    DimX=1;
    DimY=1;
    DimZ=1;
    Rx=1;
    Ry=1;
    Rz=1;
    r=1;
    g=0;
    b=0;
    matriz= new Sculptor(x,y,z);
    matriz->setColor(r,g,b,1);
    // setMouseTracking(true);
    putvoxel = true;
    cutvoxel = false;
    putbox = false;
    cutbox =  false;
    putsphere = false;
    cutsphere = false;
    putellipsoid = false;
    cutellipsoid = false;
    grade =false;

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
    //brush.setColor(QColor((int)r*255,(int)g*255,(int)b*255));
    brush.setStyle(Qt::SolidPattern);
    //painter.setPen(pen);
    //painter.setBrush(brush);

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
                brush.setColor(QColor(matriz->getR(i,j,vz)*255,matriz->getG(i,j,vz)*255,matriz->getB(i,j,vz)*255));
                painter.setBrush(brush);
                //painter.drawRect(px*(larg/x),py*(alt/y),larg/x,alt/y); // pinta o quadrado
                painter.drawRect(i*(larg/x),j*(alt/y),larg/x,alt/y); // pinta o quadrado
            }
        }
    }

    if(grade)
    {
        for(int i=0;i<larg;i+=larg/x) //desenhas as linhas verticais
        {
            painter.drawLine(i,0,i,alt-2);
        }
        for(int i=0;i<alt;i+=alt/y) //desenha as linhas horizontais
        {
            painter.drawLine(0,i,larg-2,i);
        }
    }

}

void Plotter::mousePressEvent(QMouseEvent *event)
{

    px=(event->x())/(width()/x);   //calcula em que quadrado na horizontal se encontra o mouse
    py=(event->y())/(height()/y); //calcula em que quadrado na vertica se encontra o mouse
    emit mouseX(px);
    emit mouseY(py);

    if(putvoxel){
        fig = new PutVoxel(px,py,vz,r,g,b,1);
        fig->draw(*matriz);
    }
    if(cutvoxel){
        fig = new CutVoxel(px,py,vz);
        fig->draw(*matriz);
    }
    if(putbox){
        fig = new PutBox(px,px+DimX,py,py+DimY,vz,vz+DimZ,r,g,b,1);
        fig->draw(*matriz);
    }
    if(cutbox){
        fig = new CutBox(px,px+DimX,py,py+DimY,vz,vz+DimZ);
        fig->draw(*matriz);
    }
    if(putsphere){
        fig = new PutSphere(px,py,vz,raioEsfera,r,g,b,1);
        fig->draw(*matriz);
    }
    if(cutsphere){
        fig =new CutSphere(px,py,vz,raioEsfera);
        fig->draw(*matriz);
    }
    if(putellipsoid){
        fig = new PutEllipsoid(px,py,vz,Rx,Ry,Rz,r,g,b,1);
        fig->draw(*matriz);
    }
    if(cutellipsoid){
        fig = new CutEllipsoid(px,py,vz,Rx,Ry,Rz);
        fig->draw(*matriz);
    }
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

    if(putvoxel){
        fig = new PutVoxel(px,py,vz,r,g,b,1);
        fig->draw(*matriz);
    }
    if(cutvoxel){
        fig = new CutVoxel(px,py,vz);
        fig->draw(*matriz);
    }
    if(putbox){
        fig = new PutBox(px,px+DimX,py,py+DimY,vz,vz+DimZ,r,g,b,1);
        fig->draw(*matriz);
    }
    if(cutbox){
        fig = new CutBox(px,px+DimX,py,py+DimY,vz,vz+DimZ);
        fig->draw(*matriz);
    }
    if(putsphere){
        fig = new PutSphere(px,py,vz,raioEsfera,r,g,b,1);
        fig->draw(*matriz);
    }
    if(cutsphere){
        fig =new CutSphere(px,py,vz,raioEsfera);
        fig->draw(*matriz);
    }
    if(putellipsoid){
        fig = new PutEllipsoid(px,py,vz,Rx,Ry,Rz,r,g,b,1);
        fig->draw(*matriz);
    }
    if(cutellipsoid){
        fig = new CutEllipsoid(px,py,vz,Rx,Ry,Rz);
        fig->draw(*matriz);
    }
    repaint();
}

void Plotter::mudarTamanho(int tx, int ty, int tz)
{
    delete matriz;
    x = tx;
    y = ty;
    z = tz;
    vz = 0;
    matriz = new Sculptor(x,y,z);
    repaint();
}

void Plotter::mudarRaioEsfera(int r)
{
    raioEsfera = r;
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
void Plotter::mudarRaioX(int rx)
{
    Rx = rx;
}

void Plotter::mudarRaioY(int ry)
{
    Ry = ry;
}

void Plotter::mudarRaioZ(int rz)
{
    Rz = rz;
}
void Plotter::planoAtualZ(int z)
{
    vz=z;
    repaint();
}

void Plotter::mudarParaPutvoxel()
{
    putvoxel = true;
    cutvoxel = false;
    putbox = false;
    cutbox =  false;
    putsphere = false;
    cutsphere = false;
    putellipsoid = false;
    cutellipsoid = false;
}

void Plotter::mudarParaCutvoxel()
{
    putvoxel = false;
    cutvoxel = true;
    putbox = false;
    cutbox =  false;
    putsphere = false;
    cutsphere = false;
    putellipsoid = false;
    cutellipsoid = false;
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

void Plotter::mudarParaCutbox()
{
    putvoxel = false;
    cutvoxel = false;
    putbox = false;
    cutbox =  true;
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

void Plotter::mudarParaCutsphere()
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

void Plotter::mudarParaPutellipsoid()
{
    putvoxel = false;
    cutvoxel = false;
    putbox = false;
    cutbox =  false;
    putsphere = false;
    cutsphere = false;
    putellipsoid = true;
    cutellipsoid = false;
}

void Plotter::mudarParaCutellipsoid()
{
    putvoxel = false;
    cutvoxel = false;
    putbox = false;
    cutbox =  false;
    putsphere = false;
    cutsphere = false;
    putellipsoid = false;
    cutellipsoid = true;
}

void Plotter::visibilidadeDaGrade(bool p)
{
    grade=p;
    repaint();
}

void Plotter::definirCor(int r, int g, int b)
{
    this->r = (float)r/255;
    this->g = (float)g/255;
    this->b = (float)b/255;
    matriz->setColor(this->r,this->g,this->b,1);
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
    mudarTamanho(dimx,dimy,dimz);
    for(unsigned int i=0;i<fig.size();i++)
    {
        fig[i]->draw(*matriz);
    }
    // p.writeOFF("novo.off");
    //system("geomview novo.off");
    repaint();

}

int Plotter::getDx()
{
    return x;
}
int Plotter::getDy()
{
    return y;
}
int Plotter::getDz()
{
    return z;
}
void Plotter::salvarProjeto(string arquivo)
{
    ofstream fout;
    fout.open(arquivo);
    if(!fout.is_open())
    {
        exit(0);
    }
    fout<<"dim "<<x<<" "<<y<<" "<<z<<endl;

    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            for(int k=0;k<z;k++)
            {
                if(matriz->getisOn(i,j,k))
                {
                    fout<<"putvoxel "<<i<<" "<<j<<" "<<k<<" "<<matriz->getR(i,j,k)
                       <<" "<<matriz->getG(i,j,k)<<" "<<matriz->getB(i,j,k)<<" "<<1<<endl;
                }
            }
        }
    }

}
