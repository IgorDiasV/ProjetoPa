#include "putvoxel.h"
#include "sculptor.h"
PutVoxel::PutVoxel()
{

}
void PutVoxel:: draw(int x,int y,int z,float r,float g,float b,float a,Sculptor &t)
{

    t.putVoxel(x,y,z);
    t.setColor(r,g,b,a);

}
