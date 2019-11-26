#include "putsphere.h"
#include <cmath>

//pinta uma esfera, tendo como parâmetro o centro e o raio
PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a)
{
    setColor(r,g,b,a);
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->radius= radius;

}

void PutSphere::draw(Sculptor &t)
{
    t.setColor(r,g,b,a);
    for(int i=zcenter-radius; i<=zcenter+radius; i++){
        for(int j=ycenter-radius; j<=ycenter+radius; j++){
            for(int k=xcenter-radius; k<=xcenter+radius; k++){
                if(pow(i-zcenter,2)+pow(j-ycenter,2)+pow(k-xcenter,2) <= pow(radius,2)){
                    t.putVoxel(k,j,i);
                }
            }
        }
    }
}
