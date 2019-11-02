#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"

class CutEllipsoid:public FiguraGeometrica
{
    int xcenter, ycenter,zcenter,rx, ry,rz;
public:
    /**
     * @brief CutEllipsoid - apaga um elipsóide cujas dimensões são definidas pelos parâmetros abaixo
     * @param xcenter - parâmetro de define a altura do centro da esfera em relação a origem
     * @param ycenter - parâmetro de define a largura do centro da esfera em relação a origem
     * @param zcenter - parâmetro de define a profundidade do centro da esfera em relação a ori
     * @param rx - raio do elipsóide em relação a altura
     * @param ry - raio do elipsóide em relação a largura
     * @param rz - raio do elipsóide em relação a profundidade
     */
    CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void draw(Sculptor &t);
};

#endif // CUTELLIPSOID_H
