#include "cutsphere.h"
#include "math.h"
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
                if(pow(i-zcenter,2)+pow(j-xcenter,2)+pow(k-ycenter,2) <= pow(radius,2)){
                    t.cutVoxel(i,j,k);
                }
            }
        }
    }
}
