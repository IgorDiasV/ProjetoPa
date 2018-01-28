#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include "sculptor.h"
class Plotter : public QWidget
{
    Q_OBJECT
    //dimensões da matriz
    int x,y,z;
    //posição do mouse
    int px,py,vz;
    //esfera
    int raioEsfera;
    //caixa
    int DimX, DimY, DimZ;
    //elipse
    int Rx, Ry, Rz;
    //cores
    float r, g, b;
    Sculptor *matriz;
    //vaiáveis de forma
    bool putvoxel, cutvoxel, putbox, cutbox, putsphere, cutsphere, putellipsoid, cutellipsoid,grade;
public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mudarTamanho(int tx,int ty,int tz);
    void mudarRaioEsfera(int r);
    void mudarDimBoX(int dimx);
    void mudarDimBoY(int dimy);
    void mudarDimBoZ(int dimz);
    void mudarRaioX(int rx);
    void mudarRaioY(int ry);
    void mudarRaioZ(int rz);
    void planoAtualZ(int z);
    void mudarParaCutSphere();
    void visibilidadeDaGrade(bool p);
    void definirCor(int r, int g, int b);
    int getDx();
    int getDy();
    int getDz();
    //friend class Sculptor;
    void abrirProjeto(string arquivo);
    void salvarProjeto(string arquivo);
    void exportarProjeto(string arquivo);
signals:
    void mouseX(int);
    void mouseY(int);
public slots:
    void mudarParaPutvoxel();
    void mudarParaCutvoxel();
    void mudarParaPutbox();
    void mudarParaCutbox();
    void mudarParaPutsphere();
    void mudarParaCutsphere();
    void mudarParaPutellipsoid();
    void mudarParaCutellipsoid();
    void abrirNoMeshlab();
};

#endif // PLOTTER_H
