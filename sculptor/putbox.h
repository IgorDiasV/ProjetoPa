#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"

class PutBox:public FiguraGeometrica{
    int x0, x1, y0, y1, z0, z1;
public:
    /**
     * @brief PutBox - desenha uma caixa cujas dimensões são definidas pelos parâmetro abaixo
     * @param x0 - parâmetro de onde começa a altura da caixa
     * @param x1 - parâmetro de onde termina a altura da caixa
     * @param y0 - parâmetro de onde começa a largura da caixa
     * @param y1 - parâmetro de onde termina a largura da caixa
     * @param z0 - parâmetro de onde começa a profundidade da caixa
     * @param z1 - parâmetro de onde termina a produndidade da caixa
     */
    PutBox(int x0,int x1,int y0,int y1,int z0,int z1,float r,float g,float b,float a);
    void draw(Sculptor &t);
};

#endif // PUTBOX_H
