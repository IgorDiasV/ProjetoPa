#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"
#include "sculptor.h"

class CutVoxel:public FiguraGeometrica
{
public:
    CutVoxel();
    void draw(int x,int y, int z,Sculptor &t);
};

#endif // CUTVOXEL_H
