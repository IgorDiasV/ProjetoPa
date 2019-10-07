#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"
#include "sculptor.h"

class CutVoxel:public FiguraGeometrica{
    int x, y, z;
public:
    CutVoxel(int x,int y,int z);
    void draw(Sculptor &t);
};
#endif // CUTVOXEL_H
