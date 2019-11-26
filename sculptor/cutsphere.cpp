#include "cutsphere.h"
#include <cmath>

//corta uma esfera, tendo como parâmetro o centro e o raio
CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    this->xcenter=xcenter;
    this->ycenter=ycenter;
    this->zcenter=zcenter;
    this->radius=radius;
}

void CutSphere::draw(Sculptor &t)
{
    for(int i=zcenter-radius; i<=zcenter+radius; i++){
        for(int j=ycenter-radius; j<=ycenter+radius; j++){
            for(int k=xcenter-radius; k<=xcenter+radius; k++){
                if(pow(i-zcenter,2)+pow(j-ycenter,2)+pow(k-xcenter,2) <= pow(radius,2)){
                    t.cutVoxel(k,j,i);
                }
            }
        }
    }
}