#include "cutbox.h"

CutBox::CutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{

    this->x0 = x0;
    this->x1 = x1;
    this->y0 = y0;
    this->y1 = y1;
    this->z0 = z0;
    this->z1 = z1;
}

void CutBox::draw(Sculptor &t)
{
    for(int i=z0; i<z1; i++){
            for(int j=x0; j<x1; j++){
                for(int k=y0; k<y1; k++){

                        t.cutVoxel(i,j,k);

                }
            }
        }
}

