#include "putellipsoid.h"
#include "math.h"
PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a)
{
    setColor(r,g,b,a);
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->rx= rx;
    this->ry= ry;
    this->rz= rz;
}

void PutEllipsoid::draw(Sculptor &t)
{
    for(int i=zcenter-rz; i<zcenter+rz; i++){
        for(int j=ycenter-ry; j<ycenter+ry; j++){
            for(int k=xcenter-rx; k<xcenter+rx; k++){
                if(pow(i-zcenter,2)/pow(rz,2) + pow(j-xcenter,2)/pow(rx,2) + pow(k-ycenter,2)/pow(ry,2) <= 1){
                  t.putVoxel(i,j,k);
                }
            }
        }
    }
}
