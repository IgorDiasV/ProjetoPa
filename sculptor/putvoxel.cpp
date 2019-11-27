#include "putvoxel.h"
#include "sculptor.h"

/**
 * @brief PutVoxel::PutVoxel
 * Desenha um voxel de uma posição.
 * @param x: posição x.
 * @param y: posição y.
 * @param z: posição z.
 * @param r: nível de vermelho.
 * @param g: nível de verde.
 * @param b: nível de azul.
 * @param a: transparência.
 */
PutVoxel::PutVoxel(int x,int y,int z,float r,float g,float b,float a)
{
    setColor(r,g,b,a);
    this->x = x;
    this->y = y;
    this->z = z;
}

void PutVoxel:: draw(Sculptor &t)
{
    t.setColor(r,g,b,a);
    t.putVoxel(x,y,z);
}
