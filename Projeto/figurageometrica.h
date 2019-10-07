#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"

class FiguraGeometrica
{
protected:
    float r,g,b,a;
public:
    FiguraGeometrica();
    void setColor(float r,float g,float b,float a);
    virtual void draw(Sculptor &t)=0;
    virtual ~FiguraGeometrica(){}
};

#endif // FIGURAGEOMETRICA_H
