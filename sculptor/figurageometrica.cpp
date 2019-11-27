#include "figurageometrica.h"

FiguraGeometrica::FiguraGeometrica()
{

}
/**
 * @brief FiguraGeometrica::setColor
 * Define a cor.
 * @param r: nível de vermelho.
 * @param g: nível de verde.
 * @param b: nível de azul.
 * @param a: transparência.
 */
void FiguraGeometrica:: setColor(float r, float g, float b, float a)
{
    this->r=r;
    this->g=g;
    this->b=b;
    this->a=a;
}
