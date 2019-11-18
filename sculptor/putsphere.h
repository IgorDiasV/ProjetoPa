#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"

class PutSphere: public FiguraGeometrica
{
    int xcenter,ycenter,zcenter,radius;
public:
    /**
     * @brief PutSphere - desenha uma esfera de dimensões definidas pelos parâmetros abaixo
     * @param xcenter - parâmetro de define a altura do centro da esfera em relação a origem
     * @param ycenter - parâmetro de define a largura do centro da esfera em relação a origem
     * @param zcenter - parâmetro de define a profundidade do centro da esfera em relação a origem
     * @param radius - raio da esfera
    */
    PutSphere(int xcenter, int ycenter, int zcenter, int radius,float r,float g,float b,float a);
    void draw(Sculptor &t);
};

#endif // PUTSPHERE_H
