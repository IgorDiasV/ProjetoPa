#include <iostream>
#include "sculptor.h"
using namespace std;

int main()
{
    // [altura][profundidade][largura]
    Sculptor p(2,2,2);
    p.putVoxel(1,0,0);//vermelho
    p.setColor(0,0,1,1);
    p.putVoxel(0,1,0);//azul
    p.setColor(0,1,0,1);
    p.putVoxel(0,0,1);//verde
    p.setColor(1,1,1,1);
    p.putVoxel(0,0,0);


    p.writeOFF("arquivo.off");
    system("geomview arquivo.off");

    return 0;
}
