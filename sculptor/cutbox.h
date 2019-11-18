#ifndef CUTBOX_H
#define CUTBOX_H
#include "figurageometrica.h"

class CutBox:public FiguraGeometrica
{
    int x0, x1, y0, y1, z0, z1;
public:
    /**
     * @brief CutBox - apaga uma caixa cujas dimensões são definidas pelos parametros abaixo
     * @param x0 - parâmetro de altura onde começa a apagar a caixa
     * @param x1 - parâmetro de altura onde termina de apagar a apagar a caixa
     * @param y0 - parâmetro de largura onde começa a apagar a caixa
     * @param y1 - parâmetro de largura onde termina a apagar a caixa
     * @param z0 - parâmetro de profundidade onde começa a apagar a caixa
     * @param z1 - parâmetro de profundidade onde termina a apagar a caixa
     */
    CutBox(int x0,int x1,int y0,int y1,int z0,int z1);
    void draw(Sculptor &t);
};

#endif // CUTBOX_H
