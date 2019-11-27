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
#include "abrirprojeto.h"

using namespace std;
FiguraGeometrica *fig;
Plotter::Plotter(QWidget *parent) : QWidget(parent)
{
    x=30;
    y=30;
    z=30;
    vz=0;
    raioEsfera=1;
    DimX=1;
    DimY=1;
    DimZ=1;
    Rx=1;
    Ry=1;
    Rz=1;
    r=1;
    g=1;
    b=1;
    matriz= new Sculptor(x,y,z);
    matriz->setColor(r,g,b,1);
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
/**
 * @brief Plotter::paintEvent
 * Desenha o contorno do plotter, e o gradeado de acordo com os parâmetros da classe.
 */
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
    brush.setStyle(Qt::SolidPattern);

    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(matriz->getisOn(i,j,vz)){
                brush.setColor(QColor(matriz->getR(i,j,vz)*255,matriz->getG(i,j,vz)*255,matriz->getB(i,j,vz)*255));
                painter.setBrush(brush);
                painter.drawRect(i*(larg/x),j*(alt/y),larg/x,alt/y); // pinta o quadrado
            }
        }
    }
    if(grade){
        for(int i=0;i<larg;i+=larg/x){
            painter.drawLine(i,0,i,alt-2);
        }
        for(int i=0;i<alt;i+=alt/y){
            painter.drawLine(0,i,larg-2,i);
        }
    }

}
/**
 * @brief Plotter::mousePressEvent
 * Desenha a figura atual quando o mouse é arrastado.
 */
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
/**
 * @brief Plotter::mouseMoveEvent
 * Desenha uma figura quando o mouse é movimentado.
 */
void Plotter::mouseMoveEvent(QMouseEvent *event)
{
    px=(event->x())/(width()/x); //calcula em que quadrado na horizontal se encontra o mouse
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
/**
 * @brief Plotter::mudarTamanho
 * Muda o tamanho da matriz alocada, apaga o projeto anterior.
 * @param tx: dimensão do eixo x.
 * @param ty: dimensão do eixo y.
 * @param tz: dimensão do eixo z.
 */
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
/**
 * @brief Plotter::mudarRaioEsfera
 * Muda o raio da esfera.
 * @param r: passa o raio definido nos slider para o construtor do widget
 */
void Plotter::mudarRaioEsfera(int r)
{
    raioEsfera = r;
}
/**
 * @brief Plotter::mudarDimBoX
 * Muda a dimensão x da caixa.
 * @param dimx: passa o dimensão x definido nos slider para o construtor do widget.
 */
void Plotter::mudarDimBoX(int dimx)
{
    DimX = dimx;
}
/**
 * @brief Plotter::mudarDimBoY
 * Muda a dimensão y da caixa.
 * @param dimy: passa o dimensão y definido nos slider para o construtor do widget.
 */
void Plotter::mudarDimBoY(int dimy)
{
    DimY = dimy;
}
/**
 * @brief Plotter::mudarDimBoZ
 * Muda a dimensão z da caixa.
 * @param dimz: passa o dimensão z definido nos slider para o construtor do widget.
 */
void Plotter::mudarDimBoZ(int dimz)
{
    DimZ = dimz;
}
/**
 * @brief Plotter::mudarRaioX
 * Muda o raio x do elipsóide.
 * @param rx: passa o raio no eixo x definido nos slider para o construtor do widget.
 */
void Plotter::mudarRaioX(int rx)
{
    Rx = rx;
}
/**
 * @brief Plotter::mudarRaioY
 * Muda o raio y do elipsóide.
 * @param ry: passa o raio no eixo y definido nos slider para o construtor do widget.
 */
void Plotter::mudarRaioY(int ry)
{
    Ry = ry;
}
/**
 * @brief Plotter::mudarRaioZ
 * Muda o raio z do elipsóide.
 * @param rz: passa o raio no eixo z definido nos slider para o construtor do widget.
 */
void Plotter::mudarRaioZ(int rz)
{
    Rz = rz;
}
/**
 * @brief Plotter::planoAtualZ
 * muda o plano atual que mostra na tela e redesenha o widget
 * @param z: passa o plano z definido nos slider para o construtor da classe.
 */
void Plotter::planoAtualZ(int z)
{
    vz=z;
    repaint();
}
/**
 * @brief Plotter::mudarParaPutvoxel
 * Muda o modo de desenho para putvoxel.
 */
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
/**
 * @brief Plotter::mudarParaCutvoxel
 * Muda o modo de desenho para cutvoxel.
 */
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
/**
 * @brief Plotter::mudarParaPutbox
 * Muda o modo de desenho para putbox.
 */
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
/**
 * @brief Plotter::mudarParaCutbox
 * Muda o modo de desenho para cutbox.
 */
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
/**
 * @brief Plotter::mudarParaPutsphere
 * Muda o modo de desenho para putsphere.
 */
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
/**
 * @brief Plotter::mudarParaCutsphere
 * Muda o modo de desenho para cutsphere.
 */
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
/**
 * @brief Plotter::mudarParaPutellipsoid
 * Muda o modo de desenho para putellipsoid.
 */
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
/**
 * @brief Plotter::mudarParaCutellipsoid
 * Muda o modo de desenho para cutellipsoid.
 */
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
/**
 * @brief Plotter::abrirNoMeshlab
 * Abre o projeto atual no software Meshlab.
 */
void Plotter::abrirNoMeshlab()
{
    matriz->writeOFF("arquivo.off");
    system("meshlab arquivo.off");
}
/**
 * @brief Plotter::visibilidadeDaGrade
 * Muda o mod0 de visualização (grade ou sem grade) e redesenha o widget.
 * @param p
 */
void Plotter::visibilidadeDaGrade(bool p)
{
    grade=p;
    repaint();
}
/**
 * @brief Plotter::definirCor
 * Define as cores do RGB.
 * @param r: nível de vermelho.
 * @param g: nível de verde.
 * @param b: nível de azul.
 */
void Plotter::definirCor(int r, int g, int b)
{
    this->r = (float)r/255;
    this->g = (float)g/255;
    this->b = (float)b/255;
    matriz->setColor(this->r,this->g,this->b,1);
}
/**
 * @brief Plotter::abrirProjeto
 * Abre um projeto de instruções já existente.
 * @param arquivo: nome do arquivo.
 */
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
    repaint();
}
/**
 * @brief Plotter::getDx
 * Retorna o tamanho da grade do widget no eixo x.
 */
int Plotter::getDx()
{
    return x;
}
/**
 * @brief Plotter::getDy
 * Retorna o tamanho da grade do widget no eixo y.
 */
int Plotter::getDy()
{
    return y;
}
/**
 * @brief Plotter::getDz
 * Retorna o tamanho da grade do widget no eixo z.
 */int Plotter::getDz()
{
    return z;
}
/**
 * @brief Plotter::salvarProjeto
 * Salva o projeto com um documento de texto com as instruções de desenho
 * @param arquivo: nome do arquivo.
 */void Plotter::salvarProjeto(string arquivo)
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
    fout.close();
}
/**
 * @brief Plotter::exportarProjeto
 * Exporta o projeto como arquivo .off.
 * @param arquivo: nome do arquivo
 */
void Plotter::exportarProjeto(string arquivo)
{
    matriz->writeOFF(arquivo);
}
