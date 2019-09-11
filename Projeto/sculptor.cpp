#include "sculptor.h"
Voxel ***x;
Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    //np=nz,nl=nx,nc=ny
    x=new Voxel**[_nz*_nx*_ny];

    for(int i = 0; i < _nz; i++){
        x[i] = new Voxel*[_nx*_ny];
    }
    for(int i = 0; i < _nz; i++){
        for(int j = 0; j <_nx; j++){
            x[i][j] = new Voxel[_ny];
        }
    }

}

Sculptor::~Sculptor()
{

    delete [] *x;
    delete [] **x;
}

void Sculptor::setColor(float r, float g, float b, float alpha)
{
    this->r=r;
    this->g=g;
    this->b=b;
    a=alpha;
}
