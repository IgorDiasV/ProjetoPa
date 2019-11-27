#include "cutellipsoid.h"
#include <cmath>

/**
 * @brief CutEllipsoid::CutEllipsoid
 * Apaga um elipsoide, tendo como parâmetro o centro e os raios em cada coordenada
 * @param xcenter: centro do elipsóide no eixo x
 * @param ycenter: centro do elipsóide no eixo y
 * @param zcenter: centro no do elipsóide eixo z
 * @param rx: raio no eixo x
 * @param ry: raio no eixo y
 * @param rz: raio no eixo z
 */
CutEllipsoid::CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->rx= rx;
    this->ry= ry;
    this->rz= rz;
}

void CutEllipsoid::draw(Sculptor &t)
{
    for(int i=zcenter-rz; i<=zcenter+rz; i++){
        for(int j=ycenter-ry; j<=ycenter+ry; j++){
            for(int k=xcenter-rx; k<=xcenter+rx; k++){
                if(pow(i-zcenter,2)/pow(rz,2) + pow(j-ycenter,2)/pow(ry,2) + pow(k-xcenter,2)/pow(rx,2) <= 1){
                    t.cutVoxel(k,j,i);
                }
            }
        }
    }
}
