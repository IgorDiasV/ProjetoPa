#include "putsphere.h"
#include <cmath>

/**
 * @brief PutSphere::PutSphere
 * Desenha uma esfera, tendo como parâmetro o centro e o raio.
 * @param xcenter: centro da esfera no eixo x.
 * @param ycenter: centro da esfera no eixo y.
 * @param zcenter: centro da esfera no eixo z.
 * @param radius: raio da esfera.
 * @param rz: raio no eixo z
 * @param r: nível de vermelho.
 * @param g: nível de verde.
 * @param b: nível de azul.
 * @param a: transparência.
 */
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
