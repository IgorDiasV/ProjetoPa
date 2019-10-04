#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"

class PutVoxel:public FiguraGeometrica
{
public:
    PutVoxel();
    void draw(int x,int y,int z,float r,float g,float b,float a,Sculptor &t);
};

#endif // PUTVOXEL_H
