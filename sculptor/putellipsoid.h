#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"

class PutEllipsoid:public FiguraGeometrica
{
    int xcenter, ycenter,zcenter,rx, ry,rz;
public:
    /**
     * @brief PutEllipsoid - desenha um elipsóide cujas dimensões são definidas pelos parâmetros abaixo
     * @param xcenter - parâmetro de define a altura do centro da esfera em relação a origem
     * @param ycenter - parâmetro de define a largura do centro da esfera em relação a origem
     * @param zcenter - parâmetro de define a profundidade do centro da esfera em relação a ori
     * @param rx - raio do elipsóide em relação a altura
     * @param ry - raio do elipsóide em relação a largura
     * @param rz - raio do elipsóide em relação a profundidade
     */
    PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz,float r, float g, float b, float a);
    void draw(Sculptor &t);
};

#endif // PUTELLIPSOID_H
