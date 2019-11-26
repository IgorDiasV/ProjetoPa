#include "putvoxel.h"
#include "sculptor.h"

//desenha um voxel de uma posição
PutVoxel::PutVoxel(int x,int y,int z,float r,float g,float b,float a)
{
    setColor(r,g,b,a);
    this->x = x;
    this->y = y;
    this->z = z;
}

void PutVoxel:: draw(Sculptor &t)
{
    t.setColor(r,g,b,a);
    t.putVoxel(x,y,z);
}
