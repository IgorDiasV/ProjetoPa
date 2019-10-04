#include "cutvoxel.h"

CutVoxel::CutVoxel()
{

}
void CutVoxel::draw(int x, int y, int z,Sculptor &t)
{
    t.cutVoxel(x,y,z);
}
