#include "putbox.h"

/**
 * @brief PutBox::PutBox
 * Desenha uma caixa tendo como parâmetros os pontos abaixo.
 * @param x0: ponto inicial no eixo x.
 * @param x1: ponto final no eixo x.
 * @param y0: ponto inicial no eixo y.
 * @param y1: ponto final no eixo y.
 * @param z0: ponto inicial no eixo z.
 * @param z1: ponto final no eixo z.
 * @param r: nível de vermelho.
 * @param g: nível de verde.
 * @param b: nível de azul.
 * @param a: transparência.
 */
PutBox::PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a)
{
    setColor(r,g,b,a);
    this->x0 = x0;
    this->x1 = x1;
    this->y0 = y0;
    this->y1 = y1;
    this->z0 = z0;
    this->z1 = z1;
}

void PutBox::draw(Sculptor &t)
{
    t.setColor(r,g,b,a);
    for(int i=z0; i<z1; i++){
        for(int j=x0; j<x1; j++){
            for(int k=y0; k<y1; k++){
                t.putVoxel(j,k,i);
            }
        }
    }
}


