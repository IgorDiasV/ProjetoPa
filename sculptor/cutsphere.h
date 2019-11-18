#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"

class CutSphere:public FiguraGeometrica
{
     int xcenter,ycenter,zcenter,radius;
public:
     /**
     * @brief CutSphere - apaga uma esfera de dimensões definidas pelos parâmetros abaixo
      * @param xcenter - parâmetro de define a altura do centro da esfera em relação a origem
      * @param ycenter - parâmetro de define a largura do centro da esfera em relação a origem
      * @param zcenter - parâmetro de define a profundidade do centro da esfera em relação a origem
      * @param radius - raio da esfera
     */
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void draw(Sculptor &t);
};

#endif // CUTSPHERE_H
